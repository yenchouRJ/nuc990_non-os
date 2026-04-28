/**************************************************************************//**
 * @file     eth.c
 * @brief    Unified EMAC driver for NUC990 (supports EMAC0 and EMAC1)
 *           Uses EMAC_T register structure and named bit constants.
 *
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#include "NuMicro.h"

#include "netif/eth.h"
#include "lwip/opt.h"
#include "lwip/def.h"
#include "lwip/timeouts.h"

/* Per-interface state */
typedef struct {
    EMAC_T                     *emac;
    struct eth_descriptor       rx_desc[RX_DESCRIPTOR_NUM] __attribute__((aligned(32)));
    struct eth_descriptor       tx_desc[TX_DESCRIPTOR_NUM] __attribute__((aligned(32)));
    u8_t                        rx_buf[RX_DESCRIPTOR_NUM][PACKET_BUFFER_SIZE];
    u8_t                        tx_buf[TX_DESCRIPTOR_NUM][PACKET_BUFFER_SIZE];
    struct eth_descriptor volatile *cur_tx_desc_ptr;
    struct eth_descriptor volatile *cur_rx_desc_ptr;
    struct eth_descriptor volatile *fin_tx_desc_ptr;
    int                         plugged;
    void                      (*input_cb)(u16_t len, u8_t *buf);
} eth_intf_t;

static eth_intf_t eth_intf[2];

extern portBASE_TYPE xInsideISR;
extern void ethernetif_input0(u16_t len, u8_t *buf);
extern void ethernetif_input1(u16_t len, u8_t *buf);

/* ------------------------------------------------------------------ */
/*  MDIO (PHY register access)                                        */
/* ------------------------------------------------------------------ */

static void mdio_write(EMAC_T *emac, u8_t addr, u8_t reg, u16_t val)
{
    emac->MIID = val;
    emac->MIIDA = ((u32_t)addr << MIIDA_PHYAD_POS) | reg | MIIDA_MDCON | MIIDA_BUSY | MIIDA_WRITE;
    while (emac->MIIDA & MIIDA_BUSY);
}

static u16_t mdio_read(EMAC_T *emac, u8_t addr, u8_t reg)
{
    emac->MIIDA = ((u32_t)addr << MIIDA_PHYAD_POS) | reg | MIIDA_MDCON | MIIDA_BUSY;
    while (emac->MIIDA & MIIDA_BUSY);
    return (u16_t)(emac->MIID & MIID_DATA_MASK);
}

/* ------------------------------------------------------------------ */
/*  PHY reset & auto-negotiation                                       */
/* ------------------------------------------------------------------ */

static int reset_phy(eth_intf_t *intf)
{
    EMAC_T *emac = intf->emac;
    u16_t reg;
    u32_t delay;

    mdio_write(emac, CONFIG_PHY_ADDR, MII_BMCR, BMCR_RESET);

    delay = 2000;
    while (delay-- > 0) {
        if ((mdio_read(emac, CONFIG_PHY_ADDR, MII_BMCR) & BMCR_RESET) == 0)
            break;
    }
    if (delay == 0) {
        printf("Reset phy failed\n");
        return -1;
    }

    mdio_write(emac, CONFIG_PHY_ADDR, MII_ADVERTISE,
               ADVERTISE_CSMA | ADVERTISE_10HALF | ADVERTISE_10FULL |
               ADVERTISE_100HALF | ADVERTISE_100FULL);

    reg = mdio_read(emac, CONFIG_PHY_ADDR, MII_BMCR);
    mdio_write(emac, CONFIG_PHY_ADDR, MII_BMCR, reg | BMCR_ANRESTART);

    delay = 200000;
    while (delay-- > 0) {
        if ((mdio_read(emac, CONFIG_PHY_ADDR, MII_BMSR) &
             (BMSR_ANEGCOMPLETE | BMSR_LSTATUS)) ==
            (BMSR_ANEGCOMPLETE | BMSR_LSTATUS))
            break;
    }

    if (delay == 0) {
        printf("AN failed. Set to 100 FULL\n");
        emac->MCMDR |= (MCMDR_OPMOD | MCMDR_FDUP);
        intf->plugged = 0;
        return -1;
    } else {
        reg = mdio_read(emac, CONFIG_PHY_ADDR, MII_LPA);
        intf->plugged = 1;

        if (reg & ADVERTISE_100FULL) {
            emac->MCMDR |= (MCMDR_OPMOD | MCMDR_FDUP);
        } else if (reg & ADVERTISE_100HALF) {
            emac->MCMDR = (emac->MCMDR & ~MCMDR_FDUP) | MCMDR_OPMOD;
        } else if (reg & ADVERTISE_10FULL) {
            emac->MCMDR = (emac->MCMDR & ~MCMDR_OPMOD) | MCMDR_FDUP;
        } else {
            emac->MCMDR &= ~(MCMDR_OPMOD | MCMDR_FDUP);
        }
    }

    return 0;
}

/* ------------------------------------------------------------------ */
/*  Descriptor ring initialization                                     */
/* ------------------------------------------------------------------ */

static void init_tx_desc(eth_intf_t *intf)
{
    u32_t i;

    intf->cur_tx_desc_ptr = intf->fin_tx_desc_ptr =
        (struct eth_descriptor *)((UINT)(&intf->tx_desc[0]) | NON_CACHE_MASK);

    for (i = 0; i < TX_DESCRIPTOR_NUM; i++) {
        intf->tx_desc[i].status1 = TXFD_PADEN | TXFD_CRCAPP | TXFD_INTEN;
        intf->tx_desc[i].buf     = (unsigned char *)((UINT)(&intf->tx_buf[i][0]) | NON_CACHE_MASK);
        intf->tx_desc[i].status2 = 0;
        intf->tx_desc[i].next    = (struct eth_descriptor *)((UINT)(&intf->tx_desc[(i + 1) % TX_DESCRIPTOR_NUM]) | NON_CACHE_MASK);
    }
    intf->emac->TXDLSA = (unsigned int)&intf->tx_desc[0] | NON_CACHE_MASK;
}

static void init_rx_desc(eth_intf_t *intf)
{
    u32_t i;

    intf->cur_rx_desc_ptr =
        (struct eth_descriptor *)((UINT)(&intf->rx_desc[0]) | NON_CACHE_MASK);

    for (i = 0; i < RX_DESCRIPTOR_NUM; i++) {
        intf->rx_desc[i].status1 = OWNERSHIP_EMAC;
        intf->rx_desc[i].buf     = (unsigned char *)((UINT)(&intf->rx_buf[i][0]) | NON_CACHE_MASK);
        intf->rx_desc[i].status2 = 0;
        intf->rx_desc[i].next    = (struct eth_descriptor *)((UINT)(&intf->rx_desc[(i + 1) % RX_DESCRIPTOR_NUM]) | NON_CACHE_MASK);
    }
    intf->emac->RXDLSA = (unsigned int)&intf->rx_desc[0] | NON_CACHE_MASK;
}

/* ------------------------------------------------------------------ */
/*  MAC address / CAM setup                                            */
/* ------------------------------------------------------------------ */

static void set_mac_addr(EMAC_T *emac, u8_t *addr)
{
    emac->CAMxML[0][0] = ((u32_t)addr[0] << 24) | ((u32_t)addr[1] << 16) |
                          ((u32_t)addr[2] << 8)  | addr[3];
    emac->CAMxML[0][1] = ((u32_t)addr[4] << 24) | ((u32_t)addr[5] << 16);
    emac->CAMCMR = CAMCMR_ABP | CAMCMR_AMP | CAMCMR_ECMP;
    emac->CAMEN  = 1;    /* Enable CAM entry 0 */
}

/* ------------------------------------------------------------------ */
/*  Interrupt handlers                                                 */
/* ------------------------------------------------------------------ */

static void eth_rx_irq(eth_intf_t *intf)
{
    unsigned int status;
    EMAC_T *emac = intf->emac;

    xInsideISR = pdTRUE;
    status = emac->MISTA & MISTA_RX_MASK;
    emac->MISTA = status;   /* W1C */

    if (status & MISTA_RXBERR) {
        /* Shouldn't go here, unless descriptor corrupted */
    }

    do {
        status = intf->cur_rx_desc_ptr->status1;
        if (status & OWNERSHIP_EMAC)
            break;

        if (status & RXFD_RXGD) {
            intf->input_cb(status & 0xFFFF, intf->cur_rx_desc_ptr->buf);
        }

        intf->cur_rx_desc_ptr->status1 = OWNERSHIP_EMAC;
        intf->cur_rx_desc_ptr = intf->cur_rx_desc_ptr->next;
    } while (1);

    emac->RSDR = 0;   /* Trigger RX */
    xInsideISR = pdFALSE;
}

static void eth_tx_irq(eth_intf_t *intf)
{
    unsigned int status;
    u32_t cur_entry;
    EMAC_T *emac = intf->emac;

    xInsideISR = pdTRUE;
    status = emac->MISTA & MISTA_TX_MASK;
    emac->MISTA = status;   /* W1C */

    if (status & MISTA_TXBERR) {
        /* Shouldn't go here, unless descriptor corrupted */
        xInsideISR = pdFALSE;
        return;
    }

    cur_entry = emac->CTXDSA;
    while (cur_entry != (u32_t)intf->fin_tx_desc_ptr) {
        intf->fin_tx_desc_ptr = intf->fin_tx_desc_ptr->next;
    }
    xInsideISR = pdFALSE;
}

/* ISR trampolines for each interface */
static void ETH0_RX_IRQHandler(void) { eth_rx_irq(&eth_intf[0]); }
static void ETH0_TX_IRQHandler(void) { eth_tx_irq(&eth_intf[0]); }
static void ETH1_RX_IRQHandler(void) { eth_rx_irq(&eth_intf[1]); }
static void ETH1_TX_IRQHandler(void) { eth_tx_irq(&eth_intf[1]); }

/* ------------------------------------------------------------------ */
/*  Link status check                                                  */
/* ------------------------------------------------------------------ */

static void chk_link(void *arg)
{
    eth_intf_t *intf = (eth_intf_t *)arg;
    EMAC_T *emac = intf->emac;
    unsigned int reg;

    reg = mdio_read(emac, CONFIG_PHY_ADDR, MII_BMSR);

    if (reg & BMSR_LSTATUS) {
        if (!intf->plugged) {
            intf->plugged = 1;
            reset_phy(intf);
            emac->MCMDR |= (MCMDR_TXON | MCMDR_RXON);
        }
    } else {
        if (intf->plugged) {
            intf->plugged = 0;
            emac->MCMDR &= ~(MCMDR_TXON | MCMDR_RXON);
        }
    }
    sys_timeout(2000, chk_link, intf);
}

/* ------------------------------------------------------------------ */
/*  Public API                                                         */
/* ------------------------------------------------------------------ */

void ETH0_halt(void)
{
    EMAC0->MCMDR &= ~(MCMDR_TXON | MCMDR_RXON);
}

void ETH1_halt(void)
{
    EMAC1->MCMDR &= ~(MCMDR_TXON | MCMDR_RXON);
}

void ETH0_init(u8_t *mac_addr)
{
    eth_intf_t *intf = &eth_intf[0];
    intf->emac     = EMAC0;
    intf->input_cb = ethernetif_input0;
    intf->plugged  = 0;

    /* Enable EMAC0 clock */
    CLK->HCLKEN0 |= CLK_HCLKEN0_EMAC0EN_Msk;
    /* MDC clock divider */
    CLK->DIVCTL8 = (CLK->DIVCTL8 & ~CLK_DIVCTL8_MDCLKDIV_Msk) | 0xA0;

    /* Multi-function pin setting for EMAC0 (GPE) */
    SYS->GPE_MFPL = 0x11111111;
    SYS->GPE_MFPH = (SYS->GPE_MFPH & ~0xFF) | 0x11;

    /* Reset MAC */
    intf->emac->MCMDR = MCMDR_SWR;

    init_tx_desc(intf);
    init_rx_desc(intf);
    sysFlushCache(D_CACHE);
    set_mac_addr(intf->emac, mac_addr);
    reset_phy(intf);

    /* Strip CRC, enable TX and RX */
    intf->emac->MCMDR |= (MCMDR_SPCRC | MCMDR_TXON | MCMDR_RXON);

    /* Enable interrupts: RX good, RX bus error, RDU, TX completion, TX abort, TX bus error */
    intf->emac->MIEN |= (MIEN_RXIEN | MIEN_RXGDIEN | MIEN_RDUIEN | MIEN_RXBEIEN |
                          MIEN_TXCPIEN | MIEN_TXABTIEN | MIEN_TXBEIEN);

    sysInstallISR(IRQ_LEVEL_1, EMAC0_TX_IRQn, (PVOID)ETH0_TX_IRQHandler);
    sysInstallISR(IRQ_LEVEL_1, EMAC0_RX_IRQn, (PVOID)ETH0_RX_IRQHandler);
    sysEnableInterrupt(EMAC0_TX_IRQn);
    sysEnableInterrupt(EMAC0_RX_IRQn);

    intf->emac->RSDR = 0;   /* Trigger RX */

    /* Uncomment to enable periodic link status check */
    /* sys_timeout(2000, chk_link, intf); */
}

void ETH1_init(u8_t *mac_addr)
{
    eth_intf_t *intf = &eth_intf[1];
    intf->emac     = EMAC1;
    intf->input_cb = ethernetif_input1;
    intf->plugged  = 0;

    /* Enable EMAC1 clock */
    CLK->HCLKEN0 |= CLK_HCLKEN0_EMAC1EN_Msk;
    /* MDC clock divider */
    CLK->DIVCTL8 = (CLK->DIVCTL8 & ~CLK_DIVCTL8_MDCLKDIV_Msk) | 0xA0;

    /* Multi-function pin setting for EMAC1 (GPF) */
    SYS->GPF_MFPL = 0x11111111;
    SYS->GPF_MFPH = (SYS->GPF_MFPH & ~0xFF) | 0x11;

    /* Reset MAC */
    intf->emac->MCMDR = MCMDR_SWR;

    init_tx_desc(intf);
    init_rx_desc(intf);
    sysFlushCache(D_CACHE);
    set_mac_addr(intf->emac, mac_addr);
    reset_phy(intf);

    /* Strip CRC, enable TX and RX */
    intf->emac->MCMDR |= (MCMDR_SPCRC | MCMDR_TXON | MCMDR_RXON);

    /* Enable interrupts */
    intf->emac->MIEN |= (MIEN_RXIEN | MIEN_RXGDIEN | MIEN_RDUIEN | MIEN_RXBEIEN |
                          MIEN_TXCPIEN | MIEN_TXABTIEN | MIEN_TXBEIEN);

    sysInstallISR(IRQ_LEVEL_1, EMAC1_TX_IRQn, (PVOID)ETH1_TX_IRQHandler);
    sysInstallISR(IRQ_LEVEL_1, EMAC1_RX_IRQn, (PVOID)ETH1_RX_IRQHandler);
    sysEnableInterrupt(EMAC1_TX_IRQn);
    sysEnableInterrupt(EMAC1_RX_IRQn);

    intf->emac->RSDR = 0;   /* Trigger RX */

    /* Uncomment to enable periodic link status check */
    /* sys_timeout(2000, chk_link, intf); */
}

u8_t *ETH0_get_tx_buf(void)
{
    eth_intf_t *intf = &eth_intf[0];
    if (intf->cur_tx_desc_ptr->status1 & OWNERSHIP_EMAC)
        return NULL;
    return intf->cur_tx_desc_ptr->buf;
}

void ETH0_trigger_tx(u16_t length, struct pbuf *p)
{
    eth_intf_t *intf = &eth_intf[0];
    struct eth_descriptor volatile *desc;

    intf->cur_tx_desc_ptr->status2 = (unsigned int)length;
    desc = intf->cur_tx_desc_ptr->next;
    intf->cur_tx_desc_ptr->status1 |= OWNERSHIP_EMAC;
    intf->cur_tx_desc_ptr = desc;

    intf->emac->TSDR = 0;   /* Trigger TX */
}

u8_t *ETH1_get_tx_buf(void)
{
    eth_intf_t *intf = &eth_intf[1];
    if (intf->cur_tx_desc_ptr->status1 & OWNERSHIP_EMAC)
        return NULL;
    return intf->cur_tx_desc_ptr->buf;
}

void ETH1_trigger_tx(u16_t length, struct pbuf *p)
{
    eth_intf_t *intf = &eth_intf[1];
    struct eth_descriptor volatile *desc;

    intf->cur_tx_desc_ptr->status2 = (unsigned int)length;
    desc = intf->cur_tx_desc_ptr->next;
    intf->cur_tx_desc_ptr->status1 |= OWNERSHIP_EMAC;
    intf->cur_tx_desc_ptr = desc;

    intf->emac->TSDR = 0;   /* Trigger TX */
}

/**************************************************************************//**
 * @file     emac.c
 * @brief    EMAC driver source file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2024 Nuvoton Technology Corp. All rights reserved.
*****************************************************************************/
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "Numicro.h"
#include "sys.h"
#include "emac.h"

EMACdevice EMACdev[EMAC_CNT];
static EnhDesc rx_desc[EMAC_CNT][RX_DESC_SIZE] __attribute__ ((aligned(32)));
static EnhDesc tx_desc[EMAC_CNT][TX_DESC_SIZE] __attribute__ ((aligned(32)));

static struct sk_buff rx_buf[EMAC_CNT][RX_DESC_SIZE] __attribute__ ((aligned(8)));
static struct sk_buff tx_buf[EMAC_CNT][TX_DESC_SIZE] __attribute__ ((aligned(8)));

u8 mac_addr0[6] = DEFAULT_MAC0_ADDRESS;
u8 mac_addr1[6] = DEFAULT_MAC1_ADDRESS;

EMACconfig defconfig = {
    .reg.all = 0,
    .reg.bits.ecmp = 1,
    .reg.bits.bcst = 1,
    .reg.bits.mcst = 1,
    .reg.bits.ucst = 1,
    .reg.bits.coe = 1,
    .reg.bits.ts = 1,
    .reg.bits.wol = 1,
    .desc.all = 0,
    .desc.bits.cie = TTIOEN_HP,
    .desc.bits.crcapp = 1,
    .desc.bits.paden = 1,
    .rxcb = NULL,
};

static void init_tx_desc_ring(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    emacdev->TxDescCount = TX_DESC_SIZE;
    emacdev->TxDesc = &tx_desc[intf][0];
    emacdev->TxDescDma = (EnhDesc *)((u32)emacdev->TxDesc | NON_CACHE);

    for(int i = 0; i < TX_DESC_SIZE; i++)
    {
        tx_desc[intf][i].status = 0;
        tx_desc[intf][i].buffer = (u32)((&tx_buf[intf][i])->data) | NON_CACHE; // or fill at transmit
        tx_desc[intf][i].extstatus = 0;
        tx_desc[intf][i].next = (u32)&tx_desc[intf][(i + 1) % TX_DESC_SIZE] | NON_CACHE;
    }

    emacdev->TxNext = 0;
    emacdev->TxBusy = 0;
    emacdev->TxNextDesc = emacdev->TxDesc;
    emacdev->TxBusyDesc = emacdev->TxDesc;
    emacdev->BusyTxDesc = 0;

    emacdev->Base->TXDLSA = (u32)emacdev->TxDescDma;
#if defined(FOR_EMULATION)
    if(emacdev->configs.reg.bits.dtxdlsa)
        emacdev->Base->TXDLSA = RDM_INVALID_ADDR;
#endif
}

static void init_rx_desc_ring(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    emacdev->RxDescCount = RX_DESC_SIZE;
    emacdev->RxDesc = &rx_desc[intf][0];
    emacdev->RxDescDma = (EnhDesc *)((u32)emacdev->RxDesc | NON_CACHE);

    for(int i = 0; i < RX_DESC_SIZE; i++)
    {
        rx_desc[intf][i].status = (u32)DescRxOwner;
#if defined(FOR_EMULATION)
        if(emacdev->configs.reg.bits.drxdesc)
            rx_desc[intf][i].status = 0;
#endif
        rx_desc[intf][i].buffer = (u32)((&rx_buf[intf][i])->data) | NON_CACHE;
        rx_desc[intf][i].extstatus = 0;
        rx_desc[intf][i].next = (u32)&rx_desc[intf][(i + 1) % RX_DESC_SIZE] | NON_CACHE;
        if(emacdev->configs.reg.bits.ts)
        {
            rx_desc[intf][i].tsmsb = 0;
            rx_desc[intf][i].tslsb = 0;
        }
    }

    emacdev->RxNext = 0;
    emacdev->RxBusy = 0;
    emacdev->RxNextDesc = emacdev->RxDesc;
    emacdev->RxBusyDesc = emacdev->RxDesc;
    emacdev->BusyRxDesc = 0;

    emacdev->Base->RXDLSA = (u32)emacdev->RxDescDma;
#if defined(FOR_EMULATION)
    if(emacdev->configs.reg.bits.drxdlsa)
        emacdev->Base->RXDLSA = RDM_INVALID_ADDR;
#endif
}

void rx_desc_attribute_all(enum EMACINTF intf, u32 owner)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EnhDesc *desc;

    for(int i = 0; i < emacdev->RxDescCount; i++)
    {
        desc = (EnhDesc *)((u32)&rx_desc[intf][i] | NON_CACHE);
        if(owner)
            desc->status |= (u32)DescRxOwner;
        else
            desc->status &= ~(u32)DescRxOwner;
    }
}

struct sk_buff *tx_buf_get(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    if(emacdev->TxNextDesc->status & (u32)DescTxOwner)
        return NULL;

    return (struct sk_buff *)((u32)&tx_buf[intf][emacdev->TxNext] | NON_CACHE);
}

static void desc_cleanup(EnhDesc *desc)
{
    desc->status = 0;
    desc->extstatus = 0;
    desc->ptpstatus = 0;
}

static int tx_desc_prepare(enum EMACINTF intf, struct sk_buff *skb)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EnhDesc *desc = (EnhDesc *)((u32)emacdev->TxNextDesc | NON_CACHE);
    u32 next = emacdev->TxNext;
    u32 status;

    if(desc->status & (u32)DescTxOwner)
        return ERR_DESC_NOMEM; // no free descriptor

    emacdev->BusyTxDesc++;

    status = TXDESC_DEFAULT | (skb->len & DescTxTBC);
    if(emacdev->configs.desc.bits.cie)
        status |= emacdev->configs.desc.bits.cie << DescTxTTIOENpos;
    if(emacdev->configs.desc.bits.crcapp)
        status |= DescTxCRCAPP;
    if(emacdev->configs.desc.bits.paden)
        status |= DescTxPADEN;
    if(emacdev->configs.reg.bits.ts)
        status |= DescTxTTSEN;

    desc->status |= (u32)DescTxOwner | status;

    emacdev->TxNextDesc = (EnhDesc *)desc->next;
    emacdev->TxNext = (next + 1) % emacdev->TxDescCount;

    return next;
}

static int tx_desc_retrieve(enum EMACINTF intf, u16 *len, u32 *status, u32 *extstatus)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EnhDesc *desc = (EnhDesc *)((u32)emacdev->TxBusyDesc | NON_CACHE);
    u32 txdone = emacdev->TxBusy;
    struct sk_buff *skb = &tx_buf[intf][txdone];

    if(desc->status & (u32)DescTxOwner)
        return ERR_DESC_BUSY; // owned by DMA
    if(!(desc->status & DescTxTBC))
        return ERR_DESC_ACCES; // no data is transmitted

    emacdev->BusyTxDesc--;

    *status = desc->status;
    *extstatus = desc->extstatus;
    *len = *status & DescTxTBC;

    emacdev->TxBusyDesc = (EnhDesc *)desc->next;
    emacdev->TxBusy = (txdone + 1) % emacdev->TxDescCount;

    if(*status & DescTxTTSEN)
    {
        if(*extstatus & DescTxTTSAS)
        {
            // save ts of tx packet from desc
            skb->ts = (u64)desc->tsmsb * SEC_TO_NSEC + (u64)desc->tslsb;
            skb->ts_ready = 1;
            emacdev->tx_ts.tv_sec = desc->tsmsb;
            emacdev->tx_ts.tv_nsec = desc->tslsb;
        }
        // else
        //     return ERR_DESC_PERM; // desc[7:4] unavailable
    }
    desc_cleanup(desc);

    return 0;
}

static int rx_desc_read(enum EMACINTF intf, struct sk_buff *skb, u32 *status, u32 *ptptype)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EnhDesc *desc = (EnhDesc *)((u32)emacdev->RxBusyDesc | NON_CACHE);
    u32 next = emacdev->RxBusy;

    if(desc->status & (u32)DescRxOwner)
        return ERR_DESC_BUSY; // owned by DMA

    *status = desc->status;
    if(emacdev->configs.reg.bits.coe)
    {
        skb->ipver = (*status & DescRxIPVMASK) >> DescRxIPVpos;
        skb->protocol = (*status & DescRxPROTMASK) >> DescRxPROTpos;
    }

    skb->pData = (void *)desc->buffer;
    skb->len = *status & DescRxRBC;

    emacdev->RxBusyDesc = (EnhDesc *)desc->next;
    emacdev->RxBusy = (next + 1) % emacdev->RxDescCount;

    if(emacdev->configs.reg.bits.ts)
    {
        if(*status & DescRxRTSAS)
        {
            skb->ts = (u64)desc->tsmsb * SEC_TO_NSEC + (u64)desc->tslsb;
            *ptptype = desc->ptpstatus;
            skb->ptpver = *ptptype & DescRxPTPV;
            skb->ptptype = *ptptype & DescRxPTPFT;
            skb->ptpmesg = *ptptype & DescRxPTPMGT;
            emacdev->rx_ts.tv_sec = desc->tsmsb;
            emacdev->rx_ts.tv_nsec = desc->tslsb;
        }
        // else
        //     return ERR_DESC_PERM; // desc[7:4] unavailable
    }
    desc_cleanup(desc);

    // give ownership back to DMA
    desc->status |= (u32)DescRxOwner;

    return 0;
}

EnhDesc *rx_desc_current(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    return (EnhDesc *)((u32)emacdev->Base->CRXDSA | NON_CACHE);
}

int emac_transmit_frames(enum EMACINTF intf, void *data, u16 len)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    struct sk_buff *skb;

    skb = tx_buf_get(intf);

    if(skb == NULL)
        return ERR_EMAC_NOMEM;

    skb->len = len;
    memcpy(skb->data, data, skb->len);

    tx_desc_prepare(intf, skb);

    // ready to tx
    emac->MCMDR |= MCMDR_TXON;
    emac->TSDR = 0;

    return 0;
}

static inline void txdesc_handle(enum EMACINTF intf, EnhDesc *desc_cur)
{
    EMACdevice *emacdev = &EMACdev[intf];
    u16 len;
    u32 status, extstatus;
    int ret;

    if(!desc_cur)
        return;

    do {
        ret = tx_desc_retrieve(intf, &len, &status, &extstatus);
        if(ret < 0)
            break;

        if(extstatus & (u32)DescTxCCNT)
            emacdev->tx_stat.ccnt += (extstatus & (u32)DescTxCCNT) >> DescTxCCNTpos;
        if(extstatus & DescTxPAU)
            emacdev->tx_stat.pau++;
        if(extstatus & DescTxTXHA)
            emacdev->tx_stat.txha++;
        if(extstatus & DescTxLC)
            emacdev->tx_stat.lc_rd++;
        if(extstatus & DescTxTXABT)
            emacdev->tx_stat.txabt_rd++;
        if(extstatus & DescTxNCS)
            emacdev->tx_stat.ncs_rd++;
        if(extstatus & DescTxTXCP)
            emacdev->tx_stat.txcp_rd++;
        if(extstatus & DescTxTXINTR)
            emacdev->tx_stat.txintr_rd++;

        emacdev->tx_stat.txbytes += len;
        emacdev->tx_stat.txpkts++;
    } while(desc_cur != emacdev->TxBusyDesc);
    emacdev->tx_stat.txcomplete = 1;
}

void emac_tx_handler(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    EnhDesc *desc_cur;
    u32 isr;

    isr = emac->MISTA & MISTA_TX_MASK;
    emac->MISTA = isr;
    desc_cur = (EnhDesc *)emac->CTXDSA;

    if(emacdev->configs.reg.bits.ts && (isr & MISTA_TSALS))
        emacdev->ts_alarm_flag = 1;
    if(isr & MISTA_TXBERR)
    {
        // need sw reset
        emacdev->tx_stat.txberr++;
    }
    if(isr & MISTA_TDU)
        emacdev->tx_stat.tdu++;
    if(isr & MISTA_TXEMP)
        emacdev->tx_stat.txemp++;
    if(isr & MISTA_TXCP)
        txdesc_handle(intf, desc_cur);
}

static inline void rxdesc_handle(enum EMACINTF intf, EnhDesc *desc_cur)
{
    EMACdevice *emacdev = &EMACdev[intf];
    struct sk_buff *skb;
    u32 status, ptptype;
    int ret;

    if(!desc_cur)
        return;

    do {
        skb = &rx_buf[intf][emacdev->RxBusy];
        ret = rx_desc_read(intf, skb, &status, &ptptype);
        if(ret < 0)
            break;
        
        if(emacdev->configs.reg.bits.coe)
        {
            if(status & DescRxIPHE)
                emacdev->rx_stat.iphe++;
            if(status & DescRxIPPE)
                emacdev->rx_stat.ippe++;
        }
        if(status & DescRxRP)
            emacdev->rx_stat.rp_d++;
        if(status & DescRxALIE)
            emacdev->rx_stat.alie_rd++;
        if(status & DescRxRXGD)
            emacdev->rx_stat.rxgd_rd++;
        if(status & DescRxPTLE)
            emacdev->rx_stat.ptle_d++;
        if(status & DescRxCRCE)
            emacdev->rx_stat.crce_d++;
        if(status & DescRxRXINTR)
            emacdev->rx_stat.rxintr_rd++;
        // maybe enqueue skb pointer for higher layer
        if(emacdev->configs.rxcb)
            emacdev->configs.rxcb(intf, skb);
    } while(desc_cur != emacdev->RxBusyDesc);
}

void emac_rx_handler(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    EnhDesc *desc_cur;
    u32 isr;

    isr = emac->MISTA & MISTA_RX_MASK;
    emac->MISTA = isr;
    desc_cur = (EnhDesc *)emac->CRXDSA;

    if(emacdev->configs.reg.bits.wol && (isr & MISTA_MGPR))
        emacdev->wol_flag = 1;
    if(isr & MISTA_CFR)
        emacdev->rx_stat.cfr++;
    if(isr & MISTA_RXBERR)
    {
        // need sw reset
        emacdev->rx_stat.rxberr++;
    }
    if(isr & MISTA_RDU)
    {
        emacdev->rx_stat.rdu++;
        if(!emacdev->configs.reg.bits.drxdesc)
            emac_ready(intf);
    }
    if(isr & MISTA_DEN)
        emacdev->rx_stat.den++;
    if(isr & MISTA_DFO)
        emacdev->rx_stat.dfo++;
    if(isr & MISTA_MMP)
        emacdev->rx_stat.mmp++;
    if(isr & MISTA_RP)
        emacdev->rx_stat.rp_r++;
    if(isr & MISTA_PTLE)
        emacdev->rx_stat.ptle_r++;
    if(isr & MISTA_RXOV)
        emacdev->rx_stat.rxov++;
    if(isr & MISTA_CRCE)
        emacdev->rx_stat.crce_r++;
    if(isr & MISTA_RXGD)
        rxdesc_handle(intf, desc_cur);
}

void emac0_tx_handler(void)
{
    enum EMACINTF intf = EMAC_INTF0;

    emac_tx_handler(intf);
}

void emac0_rx_handler(void)
{
    enum EMACINTF intf = EMAC_INTF0;

    emac_rx_handler(intf);
}

void emac1_tx_handler(void)
{
    enum EMACINTF intf = EMAC_INTF1;

    emac_tx_handler(intf);
}

void emac1_rx_handler(void)
{
    enum EMACINTF intf = EMAC_INTF1;

    emac_rx_handler(intf);
}

u16 mdio_read(enum EMACINTF intf, u8 addr, u8 reg)
{
    EMACdevice *emacdev = &EMACdev[intf];
    emacdev->Base->MIIDA = MIIDA_MDCON | MIIDA_BUSY | ((u32)addr << MIIDA_PHYAD_POS) | (u32)reg;
    while(emacdev->Base->MIIDA & MIIDA_BUSY);

    return (u16)emacdev->Base->MIID;
}

void mdio_write(enum EMACINTF intf, u8 addr, u8 reg, u16 val)
{
    EMACdevice *emacdev = &EMACdev[intf];
    emacdev->Base->MIID = val;
    emacdev->Base->MIIDA = MIIDA_MDCON | MIIDA_BUSY | MIIDA_WRITE | ((u32)addr << MIIDA_PHYAD_POS) | (u32)reg;
    while(emacdev->Base->MIIDA & MIIDA_BUSY);
}

void emac_suspend(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    // suspend tx/rx
    emacdev->Base->MCMDR &= ~(MCMDR_TXON | MCMDR_RXON);
}

void emac_resume(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    // resume tx/rx
    emacdev->Base->MCMDR |= (MCMDR_TXON | MCMDR_RXON);
    emacdev->Base->TSDR = 0;
    emacdev->Base->RSDR = 0;
}

static int reset_phy(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    u32 spd, dpx;
    int delay;
    u16 reg;

    emacdev->PhyBase = DEFAULT_PHY_BASE;
    spd = emacdev->configs.reg.bits.spd;
    dpx = emacdev->configs.reg.bits.dpx;

    emac_suspend(intf);

#if defined(FOR_EMULATION)
    if((spd == SPD_NEGOTIATE) || (dpx == DUPLEX_NEGOTIATE))
        goto PHY_ERR;
#endif

    if(spd && dpx)
    {
        if(spd == SPD_100M)
            emacdev->Base->MCMDR |= MCMDR_OPMOD;
        else
            emacdev->Base->MCMDR &= ~MCMDR_OPMOD;

        if(dpx == DUPLEX_FULL)
            emacdev->Base->MCMDR |= MCMDR_FDUP;
        else
            emacdev->Base->MCMDR &= ~MCMDR_FDUP;
    }
    else // auto negotiation
    {
        // reset PHY
        mdio_write(intf, emacdev->PhyBase, MII_BMCR, BMCR_RESET);

        delay = 2000;
        while(delay-- > 0)
        {
            if((mdio_read(intf, emacdev->PhyBase, MII_BMCR) & BMCR_RESET) == 0)
                break;
        }

        if(delay == 0)
        {
            printf("Reset PHY failed\n");
            goto PHY_ERR;
        }

        mdio_write(intf, emacdev->PhyBase, MII_ADVERTISE, ADVERTISE_CSMA |
                   ADVERTISE_10HALF |
                   ADVERTISE_10FULL |
                   ADVERTISE_100HALF |
                   ADVERTISE_100FULL);

        reg = mdio_read(intf, emacdev->PhyBase, MII_BMCR);
        // restart auto negotiation
        mdio_write(intf, emacdev->PhyBase, MII_BMCR, reg | BMCR_ANRESTART);

        delay = 200000;
        while(delay-- > 0)
        {
            if((mdio_read(intf, emacdev->PhyBase, MII_BMSR) & (BMSR_ANEGCOMPLETE | BMSR_LSTATUS)) == 
               (BMSR_ANEGCOMPLETE | BMSR_LSTATUS))
                break;
        }

        if(delay == 0)
        {
            printf("Auto negotiation failed. Set to 100 FULL\n");
            emacdev->Base->MCMDR |= MCMDR_OPMOD | MCMDR_FDUP;
            // goto PHY_ERR;
        }
        else
        {
            reg = mdio_read(intf, emacdev->PhyBase, MII_LPA);

            if(reg & ADVERTISE_10HALF)
                emacdev->Base->MCMDR |= ~MCMDR_OPMOD | ~MCMDR_FDUP;
            else if(reg & ADVERTISE_10FULL)
                emacdev->Base->MCMDR |= ~MCMDR_OPMOD | MCMDR_FDUP;
            else if(reg & ADVERTISE_100HALF)
                emacdev->Base->MCMDR |= MCMDR_OPMOD | ~MCMDR_FDUP;
            else // ADVERTISE_100FULL
                emacdev->Base->MCMDR |= MCMDR_OPMOD | MCMDR_FDUP;
        }
    }
    emac_resume(intf);

    return 0;

PHY_ERR:
    emac_resume(intf);
    return ERR_EMAC_EIO;
}

static void set_mac_addr(enum EMACINTF intf, u8 *addr, u8 id)
{
    EMACdevice *emacdev = &EMACdev[intf];

    if(id > 14)
        return;

    emacdev->Base->CAMxML[id][0] = (addr[0] << 24) | (addr[1] << 16) |
                                   (addr[2] << 8)  | addr[3];
    emacdev->Base->CAMxML[id][1] = (addr[4] << 24) | (addr[5] << 16);
#if !defined(FOR_EMULATION)
    // enable cmp
    if((emacdev->Base->CAMCMR & CAMCMR_ECMP) == 0)
        emacdev->Base->CAMCMR |= CAMCMR_ECMP;
#endif
    emacdev->Base->CAMEN |= 0x1 << id;
}

void set_control_frame(enum EMACINTF intf, u8 *da, u8 *sa, u16 opcode, u8 time)
{
    EMACdevice *emacdev = &EMACdev[intf];

    set_mac_addr(intf, da, 13);
    set_mac_addr(intf, sa, 14);

    emacdev->Base->CAMxML[15][0] = ((u32)ETHERTYPE_CF << CAM15M_LENTYPE_POS) | ((u32)opcode & CAM15M_OPCODE_MASK);
    emacdev->Base->CAMxML[15][1] = ((u32)time << CAM15L_OPERAND_POS) & CAM15L_OPERAND_MASK;
    emacdev->Base->CAMEN |= 0x1 << 15;
}

void send_pause_frame(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    emacdev->Base->MCMDR |= MCMDR_SDPZ | MCMDR_TXON;
    emacdev->Base->TSDR = 0;

    while(emacdev->Base->MCMDR & MCMDR_SDPZ);
}

/* hash function */
static u32 bitrev32(u32 value) {
    u32 result = 0;
    for (int i = 0; i < 32; i++) {
        result <<= 1;
        result |= (value & 1);
        value >>= 1;
    }
    return result;
}

#define ETH_POLYNOMIAL_LE 0xEDB88320
static u32 crc32_le(u32 crc, const u8 *data, size_t len) {
    //crc = ~crc;  // Initialize with all bits set to 1
    while (len--) {
        crc ^= *data++;
        for (int i = 0; i < 8; i++) {
            if (crc & 1)
                crc = (crc >> 1) ^ ETH_POLYNOMIAL_LE;
            else
                crc >>= 1;
        }
    }
    //return ~crc;  // Finalize by inverting all bits
    return crc;
}

#define HASH_TABLE_BITS_LOG2 6
// HW hash group calculation
// mcbitslog2 is 6 for 64 bits
static u32 hash_group_calc(u8 *addr, u32 *mc_filter, int mcbitslog2)
{
    u32 bit_nr;

    bit_nr = bitrev32(~crc32_le(~0, addr, ETH_ALEN)) >> (32 - mcbitslog2);
	mc_filter[bit_nr >> 5] |= 1 << (bit_nr & 31);

    return bit_nr;
}

/**
 * @brief Set hash filter for multicast or unicast address
 *
 * @param intf
 * @param addr
 * @return u32 bit in hash table
 */
u32 hash_add_filter(enum EMACINTF intf, u8 *addr)
{
    EMACdevice *emacdev = &EMACdev[intf];
    u32 *mc_filter = emacdev->hash_table;

    emacdev->hash_id = hash_group_calc(addr, mc_filter, HASH_TABLE_BITS_LOG2);
    emacdev->Base->HTMR = mc_filter[1];
    emacdev->Base->HTLR = mc_filter[0];

    return emacdev->hash_id;
}

int hash_mask_filter(enum EMACINTF intf, u32 hashid)
{
    EMACdevice *emacdev = &EMACdev[intf];
    u32 *mc_filter = emacdev->hash_table;

    if(hashid > 63)
        return -1;

    mc_filter[hashid >> 5] &= ~(1 << (hashid & 31));
    emacdev->Base->HTMR = mc_filter[1];
    emacdev->Base->HTLR = mc_filter[0];

    return 0;
}

void hash_clear_filter(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    memset(emacdev->hash_table, 0, sizeof(emacdev->hash_table));
    emacdev->Base->HTMR = 0;
    emacdev->Base->HTLR = 0;
}

/* ptp function */
static int ts_init(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    u64 addend;

    emac->TSCTL |= TSCTL_DEFAULT;

    // design tsinc to 10ns aka 100MHz, and addend is 2^32/(HCLK/100M) i.e. 2^32*100M/180M
    addend = ((u64)1 << 32) * (u64)EMAC_TS_ACCURACY_MHZ / (u64)EMAC_HCLK_MHZ;
    emacdev->ts_addend = (u32)addend;

    emac->TSINC = 1000/EMAC_TS_ACCURACY_MHZ;
    emac->TSADDEND = emacdev->ts_addend;

    return 0;
}

int ts_set_timespec64(enum EMACINTF intf, struct timespec64 *ts)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    int limit;

    if(!emacdev->configs.reg.bits.ts)
        return ERR_EMAC_PERM;

    emac->TSUPDSEC = (u32)ts->tv_sec;
    emac->TSUPDSUBSEC = ts->tv_nsec;

    emac->TSCTL |= TSCTL_TSIEN;

    limit = 10;
	while (limit--) {
		if (!(emac->TSCTL & TSCTL_TSIEN))
			break;
		//mdelay(10);
	}

	// temp = emac->TSSUBSEC; // read subsec to update sec

    if (limit <= 0)
		return ERR_EMAC_EIO;

    return 0;
}

int ts_set_time(enum EMACINTF intf, u64 nsec)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    int limit;

    if(!emacdev->configs.reg.bits.ts)
        return ERR_EMAC_PERM;

    emac->TSUPDSEC = nsec / SEC_TO_NSEC;
    emac->TSUPDSUBSEC = nsec % SEC_TO_NSEC;

    emac->TSCTL |= TSCTL_TSIEN;

    limit = 10;
	while (limit--) {
		if (!(emac->TSCTL & TSCTL_TSIEN))
			break;
		//mdelay(10);
	}

	// temp = emac->TSSUBSEC; // read subsec to update sec

    if (limit <= 0)
		return ERR_EMAC_EIO;

    return 0;
}

void ts_adjust_time_addsub(enum EMACINTF intf, s64 delta)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    int limit;
    int sub = 0;

    if (delta < 0)
        sub = TSSSEC_ADDSUB_MASK;

    delta = llabs(delta);

    emac->TSUPDSEC = delta / SEC_TO_NSEC;
    emac->TSUPDSUBSEC = sub | (delta % SEC_TO_NSEC);
    emac->TSCTL |= TSCTL_TSUPDATE;

    limit = 10;
    while (limit--) {
		if (!(emac->TSCTL & TSCTL_TSIEN))
			break;
		//mdelay(10);
	}

	// temp = emac->TSSUBSEC; // read subsec to update sec
}

void ts_adjust_freq(enum EMACINTF intf, s32 ppb)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
	u32 diff, addend;
	int neg_adj = 0;
	u64 adj;

	if (ppb < 0) {
		neg_adj = 1;
		ppb = -ppb;
	}

	addend = emacdev->ts_addend;
	adj = addend;
	adj *= ppb;
	diff = adj / SEC_TO_NSEC;
	addend = neg_adj ? (addend - diff) : (addend + diff);
	
    emac->TSADDEND = addend;
}

void ts_get_timespec64(enum EMACINTF intf, struct timespec64 *ts)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;

    if(!ts || !emacdev->configs.reg.bits.ts)
        return;

    ts->tv_nsec = emac->TSSUBSEC & TSSUBSEC_MASK;
    ts->tv_sec = emac->TSSEC;
}

void ts_get_time(enum EMACINTF intf, u64 *nsec)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    u32 sec, subsec;

    if(!emacdev->configs.reg.bits.ts)
        return;

    subsec = emac->TSSUBSEC & TSSUBSEC_MASK;
    sec = emac->TSSEC;

    if(nsec)
        *nsec = (u64)sec * SEC_TO_NSEC + (u64)subsec;
}

void ts_set_alarm(enum EMACINTF intf, u64 nsec)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;

    emac->TSALMSEC = nsec / SEC_TO_NSEC;
    emac->TSALMSUBSEC = nsec % SEC_TO_NSEC;

    // enable alarm, it will alarm iff (TSALMSEC == TSSEC) && (TSALMSUBSEC == TSSUBSEC)
    emac->MIEN |= MIEN_TSALMIEN;
    emac->TSCTL |= TSCTL_TSALMEN;
}

void ts_delay_alarm(enum EMACINTF intf, u64 nsec)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    u64 curr;

    curr = (u64)emac->TSSUBSEC + (u64)emac->TSSEC * SEC_TO_NSEC;
    nsec += curr;
    emac->TSALMSEC = nsec / SEC_TO_NSEC;
    emac->TSALMSUBSEC = nsec % SEC_TO_NSEC;

    // enable alarm, it will alarm iff (TSALMSEC == TSSEC) && (TSALMSUBSEC == TSSUBSEC)
    emac->MIEN |= MIEN_TSALMIEN;
    emac->TSCTL |= TSCTL_TSALMEN;
}

int ts_check_alarm(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];

    if(emacdev->ts_alarm_flag)
    {
        emacdev->ts_alarm_flag = 0;
        return 0;
    }
    else
        return 1;
}

/*  Once emac and ts are ready, this can be used as timer delay */
void ts_delay_poll(enum EMACINTF intf, u64 nsdelay)
{
    ts_delay_alarm(intf, nsdelay);
    while(ts_check_alarm(intf));
}

/* This function aligns pulse to SEC */
int pps_cmd_set(enum EMACINTF intf, enum PPSCMD cmd)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;

    if(!emacdev->perout_enable && cmd > PPSCMD_NO_CMD)
        return -1;

    emac->PPSCTL = cmd & PPSCTL_MASK;

    return 0;
}

/**
 * @brief setting period output pulse
 * start/stop = 0 means immediatelly start/stop
 * period = 0 means disable period output
 *
 * @param intf interface
 * @param req structure contains start, stop, period, type
 * @return int 0 if success, else if fail
 */
int pps_perout_cmd_set(enum EMACINTF intf, struct perout_request *req)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    u32 ticks, hi, lo;
    u64 sec, nsec;
    u32 cmd;

    if (req->period == 0) {
        pps_cmd_set(intf, PPSCMD_NO_CMD);
        return 0;
    // } else if (req->period < 2 * SEC_TO_NSEC / HCLK_FREQ) {
    } else if (req->period > HCLK_FREQ / 2) {
        return -1;
    }

    switch (req->type) {
    case PEROUT_START_SINGLE_AT:
        // single pulse do not support immediate start
        if (req->start == 0)
            return -1;
    case PEROUT_START_SEQ_AT:
        // make it close to 50% duty cycle
        ticks = HCLK_FREQ / req->period;
        hi = ticks / 2;
        lo = ticks - hi;
        emac->PPSHW = hi - 1;
        emac->PPSLW = lo - 1;
        if (req->start == 0) {
            cmd = PPSCMD_START_SEQ;
        } else {
            sec = req->start / SEC_TO_NSEC;
            nsec = req->start % SEC_TO_NSEC;
            emac->PPSTSEC = sec;
            emac->PPSTSSEC = nsec;
            cmd = req->type == PEROUT_START_SINGLE_AT ?
                PPSCMD_START_SINGLE_AT_TIME : PPSCMD_START_SEQ_AT_TIME;
        }
        break;
    case PEROUT_STOP_AT:
        if (req->stop == 0) { // stop immediately
            cmd = PPSCMD_NO_CMD;
        } else {
            sec = req->stop / SEC_TO_NSEC;
            nsec = req->stop % SEC_TO_NSEC;
            emac->PPSTSEC = sec;
            emac->PPSTSSEC = nsec;
            cmd = PPSCMD_STOP_SEQ_AT_TIME;
        }
        break;
    default:
        break;
    }

    emacdev->perout_enable = 1;
    pps_cmd_set(intf, (enum PPSCMD)cmd);
    emacdev->perout_enable = 0;

    return 0;
}

/* mtu only refers to payload */
int change_mtu(enum EMACINTF intf, u16 mtu)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    
    if(mtu > MAX_MTU)
        return -1;

    emac_suspend(intf);

    if(mtu > MTU_UPPER)
    {
        emacdev->configs.reg.bits.alp = 1;
        emac->MCMDR |= MCMDR_ALP;
    }
    else if(mtu < MTU_LOWER)
    {
        emacdev->configs.reg.bits.arp = 1;
        emac->MCMDR |= MCMDR_ARP;
    }

    emac->DMARFC = (mtu + ETHERNET_HEADER + ETHERNET_CRC) & DMARFC_RXMS_MASK; // maximum packet length

    emac_resume(intf);

    return 0;
}

static int emac_init(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    EMAC_T *emac = emacdev->Base;
    int delay;
    int ret;

    // Reset EMAC
    emac->MCMDR |= MCMDR_SWR;
    while(emac->MCMDR & MCMDR_SWR);
    delay = 100;
    while(delay-- > 0)
    {
        if(!(emac->MCMDR & MCMDR_SWR))
            break;
    }
    if(delay == 0)
    {
        printf("Fatal: Reset EMAC%d failed\n", (u32)intf);
        return ERR_EMAC_EIO;
    }

    init_tx_desc_ring(intf);
    init_rx_desc_ring(intf);

    emac->CAMCMR = CAMCMR_ABP;
    emac->MCMDR = MCMDR_DEFAULT;
    //emac->FFTCR = BURSTLEN_8WORD;
    emac->MIEN = MIEN_DEFAULT;

    if(intf == EMAC_INTF0)
    {
        set_mac_addr(intf, mac_addr0, 0);
        sysInstallISR(IRQ_LEVEL_1, IRQ_EMAC0_TX, (PVOID)emac0_tx_handler);
        sysInstallISR(IRQ_LEVEL_1, IRQ_EMAC0_RX, (PVOID)emac0_rx_handler);
        if(!emacdev->configs.reg.bits.dint)
        {
            sysEnableInterrupt(IRQ_EMAC0_TX);
            sysEnableInterrupt(IRQ_EMAC0_RX);
        }
    }
    else
    {
        set_mac_addr(intf, mac_addr1, 0);
        sysInstallISR(IRQ_LEVEL_1, IRQ_EMAC1_TX, (PVOID)emac1_tx_handler);
        sysInstallISR(IRQ_LEVEL_1, IRQ_EMAC1_RX, (PVOID)emac1_rx_handler);
        if(!emacdev->configs.reg.bits.dint)
        {
            sysEnableInterrupt(IRQ_EMAC1_TX);
            sysEnableInterrupt(IRQ_EMAC1_RX);
        }
    }

    ts_init(intf);

    if(emacdev->configs.reg.bits.bcst)
        emac->CAMCMR |= CAMCMR_ABP;
    if(emacdev->configs.reg.bits.mcst)
        emac->CAMCMR |= CAMCMR_AMP;
    if(emacdev->configs.reg.bits.ucst) // higher priority than ecmp
        emac->CAMCMR |= CAMCMR_AUP;
    if(emacdev->configs.reg.bits.ahmp)
    {
        emac->CAMCMR &= ~CAMCMR_AMP;
        emac->CAMCMR |= CAMCMR_AHMP;
    }
    if(emacdev->configs.reg.bits.ahup)
    {
        emac->CAMCMR &= ~CAMCMR_AUP;
        emac->CAMCMR |= CAMCMR_AHUP;
    }
    if(emacdev->configs.reg.bits.ecmp)
        emac->CAMCMR |= CAMCMR_ECMP;
    if(emacdev->configs.reg.bits.ccam)
    {
        emac->CAMCMR &= ~(CAMCMR_AHMP | CAMCMR_AHUP);
        emac->CAMCMR |= CAMCMR_CCAM;
    }
    if(emacdev->configs.reg.bits.coe)
        emac->MCMDR |= MCMDR_RTIOEN;
    if(emacdev->configs.reg.bits.dspcrc)
        emac->MCMDR &= ~MCMDR_SPCRC;
    if(emacdev->configs.reg.bits.aep)
        emac->MCMDR |= MCMDR_AEP;
    if(emacdev->configs.reg.bits.arp)
    {
        emac->MCMDR |= MCMDR_ARP;
        emac->MIEN |= MIEN_RPIEN;
    }
    if(emacdev->configs.reg.bits.alp)
    {
        emac->MCMDR |= MCMDR_ALP;
        emac->MIEN |= MIEN_LPIEN;
    }
#if defined(FOR_EMULATION) || defined(FOR_SIMULATION) || defined(FOR_REAL_CHIP)
    if(emacdev->configs.reg.bits.lpb)
        emac->MCMDR |= MCMDR_LPB;
#endif
    if(emacdev->configs.reg.bits.ts)
    {
        emac->TSCTL |= TSCTL_TSEN | TSCTL_TSSNPEN;
        if(!emacdev->configs.reg.bits.coe)
        {
            emacdev->configs.reg.bits.coe = 1;
            emac->MCMDR |= MCMDR_RTIOEN;
        }
    }
    if(emacdev->configs.reg.bits.tsall)
        emac->TSCTL |= TSCTL_TSSNAEN;
    if(emacdev->configs.reg.bits.wol)
    {
        emac->MCMDR |= MCMDR_MGP_WAKE;
        emac->MIEN |= MIEN_WOLIEN;
        SYS->WKUPSER1 |= SYS_WKUPSER1_EMAC0WKEN_Msk << intf;
        emacdev->wol_flag = 0;
    }

    ret = reset_phy(intf);
    if(ret)
        return ret;

    // ready for rx
    emac_ready(intf);

    return 0;
}

int emac_open(enum EMACINTF intf, EMACconfig config)
{
    EMACdevice *emacdev = &EMACdev[intf];
    int ret;

    memset((void *)emacdev, 0, sizeof(EMACdevice));

    if(intf == EMAC_INTF0) {
        CLK->HCLKEN0 |= CLK_HCLKEN0_EMAC0_Msk;
        CLK->DIVCTL8 = (CLK->DIVCTL8 & ~0xFF) | 0xA0; // MDC 1.125MHz
        SYS->GPE_MFPL = (SYS->GPE_MFPL & ~0xFFFFFFFF) | 0x11111111;
        SYS->GPE_MFPH = (SYS->GPE_MFPH & ~0xFF) | 0x11;
        if (config.reg.bits.pps)
            SYS->GPF_MFPH = (SYS->GPF_MFPH & ~0xF00) | 0x100;
        emacdev->Base = EMAC0;
        emacdev->Intf = EMAC_INTF0;
    } else {
        CLK->HCLKEN0 |= CLK_HCLKEN0_EMAC1_Msk;
        CLK->DIVCTL8 = (CLK->DIVCTL8 & ~0xFF) | 0xA0; // MDC 1.125MHz
        SYS->GPF_MFPL = (SYS->GPF_MFPL & ~0xFFFFFFFF) | 0x11111111;
        SYS->GPF_MFPH = (SYS->GPF_MFPH & ~0xFF) | 0x11;
        if (config.reg.bits.pps)
            SYS->GPB_MFPL = (SYS->GPB_MFPL & ~0xF00000) | 0x100000;
        emacdev->Base = EMAC1;
        emacdev->Intf = EMAC_INTF1;
    }

    emacdev->configs = config;
    
    ret = emac_init(intf);
    if(ret)
    {
        printf("EMAC%d init failed\n", (u32)intf);
        return ret;
    }

    return 0;
}

/* This make emac fetch rxdesc */
void emac_ready(enum EMACINTF intf)
{
    EMACdevice *emacdev = &EMACdev[intf];
    // ready for rx
    emacdev->Base->RSDR = 0;
}

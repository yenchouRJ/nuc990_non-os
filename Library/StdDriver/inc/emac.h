/**************************************************************************//**
 * @file     emac.h
 * @brief    EMAC driver header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2026 Nuvoton Technology Corp. All rights reserved.
 ******************************************************************************/
#ifndef __EMAC_H__
#define __EMAC_H__

#ifdef __cplusplus
extern "C"
{
#endif

#include "NuMicro.h"

typedef signed char s8;
typedef unsigned char u8;

typedef signed short s16;
typedef unsigned short u16;

typedef signed int s32;
typedef unsigned int u32;

typedef signed long long s64;
typedef unsigned long long u64;

#define EMAC_CNT    2

#define CACHE_ON

#ifdef CACHE_ON
    #define NON_CACHE    NON_CACHE_MASK
#else
    #define NON_CACHE    0
#endif

#define DEFAULT_MAC0_ADDRESS {0x00, 0x11, 0x22, 0x33, 0x44, 0x55}
#define DEFAULT_MAC1_ADDRESS {0x00, 0x11, 0x22, 0x33, 0x44, 0x66}



/******************************************************************************
 * Descriptor
 ******************************************************************************/
typedef struct EnhDescStruct {
    uint32_t   status;         /* Status                                                                             */
    uint32_t   buffer;         /* Network buffer pointer(dma-able)                                                   */
    uint32_t   extstatus;      /* Extended status for Tx descriptor                                                  */
    uint32_t   next;           /* Next descriptor pointer in chain structure                                         */
    /* Enhanced, dma-able if TSCTL_TSEN */
    uint32_t   reserved1;      /* Reserved word                                                                      */
    uint32_t   ptpstatus;      /* Extended status for Rx descriptor PTP                                              */
    uint32_t   tslsb;          /* Lower 32 bits of the 64 bit timestamp value                                        */
    uint32_t   tsmsb;          /* Higher 32 bits of the 64 bit timestamp value                                       */
    /* Put something accessed by driver only here */
} EnhDesc;

enum EnhDescriptorStatus    /* status word of DMA descriptor */
{
    /********** TDES0 **********/
    DescTxOwner       = (int)0x80000000,
    DescTxTTIOEN      = 0x00300000,
    DescTxTTIOENpos   = 20,
    TTIOEN_NONE       = 0,
    TTIOEN_HO         = 1, /* Only IP header checksum insertion enabled */
    TTIOEN_HP         = 2, /* Both IP header checksum and payload checksum insertion enabled */
    DescTxTTSEN       = 0x00080000,
    DescTxINTEN       = 0x00040000,
    DescTxCRCAPP      = 0x00020000,
    DescTxPADEN       = 0x00010000,
    DescTxTBC         = 0x0000FFFF,
    /********** TDES1 **********/
    /* Tx buffer */

    /********** TDES2 **********/
    DescTxCCNT        = (int)0xF0000000,
    DescTxCCNTpos     = 28,
    DescTxTTSAS       = 0x08000000,
    DescTxSQE         = 0x04000000,
    DescTxPAU         = 0x02000000,
    DescTxTXHA        = 0x01000000,
    DescTxLC          = 0x00800000,
    DescTxTXABT       = 0x00400000,
    DescTxNCS         = 0x00200000,
    DescTxEXDEF       = 0x00100000,
    DescTxTXCP        = 0x00080000,
    DescTxDEF         = 0x00020000,
    DescTxTXINTR      = 0x00010000,

    /********** TDES3 **********/
    /* Next desc */

    /********** TDES6 **********/
    /* Timstamp low */

    /********** TDES7 **********/
    /* Timstamp high */

    /********** RDES0 **********/
    DescRxOwner       = (int)0x80000000, // 1: EMAC, 0: CPU
    DescRxIPV4D       = 0x20000000,
    DescRxIPV6D       = 0x10000000,
    DescRxIPVMASK     = 0x30000000,
    DescRxIPVpos      = 28,
    DescRxTCPD        = 0x08000000,
    DescRxUDPD        = 0x04000000,
    DescRxPROTMASK    = 0x0C000000,
    DescRxPROTpos     = 26,
    DescRxIPHE        = 0x02000000,
    DescRxIPPE        = 0x01000000,
    DescRxRTSAS       = 0x00800000,
    DescRxRP          = 0x00400000,
    DescRxALIE        = 0x00200000,
    DescRxRXGD        = 0x00100000,
    DescRxPTLE        = 0x00080000,
    DescRxCRCE        = 0x00020000,
    DescRxRXINTR      = 0x00010000,
    DescRxRBC         = 0x0000FFFF,
    
    /********** RDES1 **********/
    /* Tx buffer */

    /********** RDES3 **********/
    /* Next desc */

    /********** RDES5 **********/
    DescRxPTPV        = 0x000000C0,
    DescRxPTPVpos     = 6,
    PTPV_NONE         = (0 << DescRxPTPVpos),
    PTPV_V1           = (1 << DescRxPTPVpos),
    PTPV_V2           = (2 << DescRxPTPVpos),
    DescRxPTPFT       = 0x00000030,
    DescRxPTPFTpos    = 4,
    PTPFT_NONE        = (0 << DescRxPTPFTpos),
    PTPFT_IPV2        = (1 << DescRxPTPFTpos),
    PTPFT_IPV4        = (2 << DescRxPTPFTpos),
    PTPFT_IPV6        = (3 << DescRxPTPFTpos),
    DescRxPTPMGT      = 0x00000007,
    PTPMGT_NONE                = 0,
    PTPMGT_SYNC                = 1,
    PTPMGT_DelayReq            = 2,
    PTPMGT_PdelayReq           = 3,
    PTPMGT_PdelayResp          = 4,
    PTPMGT_FollowUp            = 5,
    PTPMGT_DelayResp           = 6,
    PTPMGT_PdelayRespFollowUp  = 7,

    /********** RDES6 **********/
    /* Timstamp low */

    /********** RDES7 **********/
    /* Timstamp high */
};

/******************************************************************************
 * PHY
 ******************************************************************************/
/* Generic MII registers. */
#define MII_BMCR            0x00        /* Basic mode control register */
#define MII_BMSR            0x01        /* Basic mode status register  */
#define MII_PHYSID1         0x02        /* PHYS ID 1                   */
#define MII_PHYSID2         0x03        /* PHYS ID 2                   */
#define MII_ADVERTISE       0x04        /* Advertisement control reg   */
#define MII_LPA             0x05        /* Link partner ability reg    */
#define MII_EXPANSION       0x06        /* Expansion register          */
#define MII_DCOUNTER        0x12        /* Disconnect counter          */
#define MII_FCSCOUNTER      0x13        /* False carrier counter       */
#define MII_NWAYTEST        0x14        /* N-way auto-neg test reg     */
#define MII_RERRCOUNTER     0x15        /* Receive error counter       */
#define MII_SREVISION       0x16        /* Silicon revision            */
#define MII_RESV1           0x17        /* Reserved...                 */
#define MII_LBRERROR        0x18        /* Lpback, rx, bypass error    */
#define MII_PHYADDR         0x19        /* PHY address                 */
#define MII_RESV2           0x1a        /* Reserved...                 */
#define MII_TPISTATUS       0x1b        /* TPI status for 10mbps       */
#define MII_NCONFIG         0x1c        /* Network interface config    */

/* Basic mode control register. */
#define BMCR_RESV               0x007f  /* Unused...                   */
#define BMCR_CTST               0x0080  /* Collision test              */
#define BMCR_FULLDPLX           0x0100  /* Full duplex                 */
#define BMCR_ANRESTART          0x0200  /* Auto negotiation restart    */
#define BMCR_ISOLATE            0x0400  /* Disconnect DP83840 from MII */
#define BMCR_PDOWN              0x0800  /* Powerdown the DP83840       */
#define BMCR_ANENABLE           0x1000  /* Enable auto negotiation     */
#define BMCR_SPEED100           0x2000  /* Select 100Mbps              */
#define BMCR_LOOPBACK           0x4000  /* TXD loopback bits           */
#define BMCR_RESET              0x8000  /* Reset the DP83840           */

/* Basic mode status register. */
#define BMSR_ERCAP              0x0001  /* Ext-reg capability          */
#define BMSR_JCD                0x0002  /* Jabber detected             */
#define BMSR_LSTATUS            0x0004  /* Link status                 */
#define BMSR_ANEGCAPABLE        0x0008  /* Able to do auto-negotiation */
#define BMSR_RFAULT             0x0010  /* Remote fault detected       */
#define BMSR_ANEGCOMPLETE       0x0020  /* Auto-negotiation complete   */
#define BMSR_RESV               0x07c0  /* Unused...                   */
#define BMSR_10HALF             0x0800  /* Can do 10mbps, half-duplex  */
#define BMSR_10FULL             0x1000  /* Can do 10mbps, full-duplex  */
#define BMSR_100HALF            0x2000  /* Can do 100mbps, half-duplex */
#define BMSR_100FULL            0x4000  /* Can do 100mbps, full-duplex */
#define BMSR_100BASE4           0x8000  /* Can do 100mbps, 4k packets  */

/* Advertisement control register. */
#define ADVERTISE_SLCT          0x001f  /* Selector bits               */
#define ADVERTISE_CSMA          0x0001  /* Only selector supported     */
#define ADVERTISE_10HALF        0x0020  /* Try for 10mbps half-duplex  */
#define ADVERTISE_10FULL        0x0040  /* Try for 10mbps full-duplex  */
#define ADVERTISE_100HALF       0x0080  /* Try for 100mbps half-duplex */
#define ADVERTISE_100FULL       0x0100  /* Try for 100mbps full-duplex */
#define ADVERTISE_100BASE4      0x0200  /* Try for 100mbps 4k packets  */
#define ADVERTISE_RESV          0x1c00  /* Unused...                   */
#define ADVERTISE_RFAULT        0x2000  /* Say we can detect faults    */
#define ADVERTISE_LPACK         0x4000  /* Ack link partners response  */
#define ADVERTISE_NPAGE         0x8000  /* Next page bit               */

/******************************************************************************
 * Driver
 ******************************************************************************/
enum EMACINTF {
    EMAC_INTF0 = 0,
    EMAC_INTF1 = 1,
};

enum LOOPBACK {
    LOOPBACK_EXT = 0,
    LOOPBACK_INT = 1,
};

enum MIISPEED {
    SPD_NEGOTIATE = 0,
    SPD_100M = 1,
    SPD_10M  = 2,
};

enum MIIDUPLEX {
    DUPLEX_NEGOTIATE = 0,
    DUPLEX_FULL = 1,
    DUPLEX_HALF = 2,
};

enum PHYBASE {
    PHY0  = 0,          //The device can support 32 phys, but we use first phy only
    PHY1  = 1,
    PHY31 = 31,
};

struct timespec64 {
	u64 tv_sec;    /* seconds */
	u32 tv_nsec;   /* nanoseconds */
};

enum PPSCMD {
    PPSCMD_PPS_1HZ = 0,
    PPSCMD_PPS_2HZ = 1,
    PPSCMD_PPS_4HZ = 2,
    PPSCMD_PPS_8HZ = 3,
    PPSCMD_PPS_16HZ = 4,
    PPSCMD_PPS_32HZ = 5,
    PPSCMD_PPS_64HZ = 6,
    PPSCMD_PPS_128HZ = 7,
    PPSCMD_PPS_256HZ = 8,
    PPSCMD_PPS_512HZ = 9,
    PPSCMD_PPS_1024HZ = 10,
    PPSCMD_PPS_2048HZ = 11,
    PPSCMD_PPS_4096HZ = 12,
    PPSCMD_PPS_8192HZ = 13,
    PPSCMD_PPS_16384HZ = 14,
    PPSCMD_PPS_32768HZ = 15,
    PPSCMD_NO_CMD = 16,
    PPSCMD_START_SEQ = 17,
    PPSCMD_START_SINGLE_AT_TIME = 18,
    PPSCMD_START_SEQ_AT_TIME = 19,
    PPSCMD_STOP_SEQ_AT_TIME = 20,
};

enum PEROUT_CMD {
    PEROUT_START_SINGLE_AT = 0,
    PEROUT_START_SEQ_AT = 1,
    PEROUT_STOP_AT = 2,
};

struct perout_request {
    u64 start;  /* start at abs time in ns */
    u64 stop;   /* stop at abs time in ns */
    u64 period; /* period in Hz */
    enum PEROUT_CMD type;
};

#define DEFAULT_PHY_BASE    PHY0

#define RX_DESC_SIZE 8    // Max Number of Rx Frame Descriptors
#define TX_DESC_SIZE 8    // Max number of Tx Frame Descriptors
#define EMAC_TXFIFO_LEN   2048 // 2k bytes for TxFIFO limit, payload is 2048-14-4=2030 bytes
#define EMAC_RXDESC_SIZE  4 // number of rxdesc in emac if there is no descriptor available
#define EMAC_RXFIFO_LEN   4096 // 4k bytes for RxFIFO limit

#define MAX_MTU      EMAC_TXFIFO_LEN - ETHERNET_HEADER - ETHERNET_CRC
#define MTU_UPPER    1500
#define MTU_LOWER    46
#define MTU_RESET    2030

#define EMAC_TS_ACCURACY_MHZ 100 // aka 10ns, the maximum resolution is 6ns for HCLK = 180MHz
#define EMAC_HCLK_MHZ(x)    ((x)/1000000UL)
#define SEC_TO_NSEC      1000000000ULL

#define MCMDR_DEFAULT    (MCMDR_SPCRC | MCMDR_ACP)
#define MIEN_DEFAULT     (MIEN_TXBEIEN | MIEN_TDUIEN | MIEN_LCIEN | MIEN_TXABTIEN |\
                          MIEN_TXCPIEN | MIEN_TXUDIEN | MIEN_TXIEN | MIEN_CFRIEN |\
                          MIEN_RXBEIEN | MIEN_RDUIEN | MIEN_DENIEN | MIEN_MFLEIEN | MIEN_ALIEIEN |\
                          MIEN_RXGDIEN | MIEN_RXOVIEN | MIEN_CRCEIEN | MIEN_RXIEN)
#define TSCTL_DEFAULT    (TSCTL_TSSNPEN | TSCTL_TSMODE)

#define TXDESC_DEFAULT   (DescTxINTEN)

#define ERR_EMAC_BASE     0
#define ERR_EMAC_PERM     (ERR_EMAC_BASE - 1)
#define ERR_EMAC_EIO      (ERR_EMAC_BASE - 5)
#define ERR_EMAC_NOMEM    (ERR_EMAC_BASE - 12)

#define ERR_DESC_BASE     -1000
#define ERR_DESC_PERM     (ERR_DESC_BASE - 1)
#define ERR_DESC_NOMEM    (ERR_DESC_BASE - 12)
#define ERR_DESC_ACCES    (ERR_DESC_BASE - 13)
#define ERR_DESC_BUSY     (ERR_DESC_BASE - 16)

#define RDM_INVALID_ADDR  0xA0000000

struct sk_buff {
    unsigned char data[EMAC_TXFIFO_LEN];
    void *pData;
    //unsigned int volatile rdy;
    u16 len;
    u8 ipver;
    u8 protocol;

    /* if ts enabled */
    u64 ts;
    u8 ptpver;
    u8 ptptype;
    u8 ptpmesg;
    u8 ts_ready;
} /*__attribute__((aligned(16)))*/; /* add this to guarantee alignment */

typedef void (* emac_rxcb)( enum EMACINTF, struct sk_buff * );

typedef struct EmacConfigStruct {
    union {
        uint32_t all;
        struct {
            // CAMCMR
            uint32_t ahmp: 1;
            uint32_t ahup: 1;
            uint32_t ecmp: 1;
            uint32_t ccam: 1;
            uint32_t bcst: 1;
            uint32_t mcst: 1;
            uint32_t ucst: 1;
            // MCMDR
            uint32_t coe: 1;
            uint32_t aep: 1;
            uint32_t arp: 1;
            uint32_t alp: 1;
            // others
            uint32_t lpb: 1;
            uint32_t ts: 1;
            uint32_t tsall: 1;
            uint32_t wol: 1;
            uint32_t spd: 2;
            uint32_t dpx: 2;
            uint32_t pps: 1;
            // any special test item bits
            uint32_t dint: 1;
            uint32_t dspcrc: 1;
            uint32_t drxdesc: 1;
            uint32_t dtxdlsa: 1;
            uint32_t drxdlsa: 1;
            uint32_t reserved: 7;
        } bits;
    } reg;
    union {
        uint32_t all;
        struct {
            uint32_t cie: 2;
            uint32_t crcapp: 1;
            uint32_t paden: 1;
            uint32_t reserved: 28; 
        } bits;
    } desc;
    emac_rxcb rxcb;
} EMACconfig;

// MAC Tx Error Structure
typedef struct _tx_statistic
{
	unsigned int  txbytes;
    unsigned int  txpkts;
    unsigned int  txcomplete;
    /* reg */
	unsigned int  txberr; 
	unsigned int  tdu;
	unsigned int  lc_rd;
	unsigned int  txabt_rd;
	unsigned int  ncs_rd;
	unsigned int  exdef_rd;
	unsigned int  txcp_rd;
	unsigned int  txemp;
    unsigned int  txintr_rd;
    /* desc */
    unsigned int  ccnt;
	unsigned int  sqe;
	unsigned int  pau;
	unsigned int  txha;
	unsigned int  def;
} tx_statistic;

// MAC Rx Error Structure
typedef struct _rx_statistic
{
	unsigned int  rxbytes;
    unsigned int  rxpkts;
    unsigned int  rxgood;
    /* reg */
	unsigned int  cfr;
	unsigned int  rxberr; 
	unsigned int  rdu;
    unsigned int  den;
    unsigned int  dfo;
	unsigned int  mmp;
	unsigned int  rp_r;
	unsigned int  alie_rd;
	unsigned int  rxgd_rd;
	unsigned int  ptle_r;
	unsigned int  rxov;
	unsigned int  crce_r;
    unsigned int  rxintr_rd;
    /* desc */
    unsigned int  iphe;
    unsigned int  ippe;
    unsigned int  rp_d;
    unsigned int  ptle_d;
    unsigned int  crce_d;
} rx_statistic;

struct net_device_stats {
    u32 tx_bytes;
    u32 tx_packets;
    u32 tx_errors;
    u32 tx_aborted_errors;
    u32 tx_carrier_errors;
    u32 tx_ip_header_errors;
    u32 tx_ip_payload_errors;
    u32 collisions;
    u32 rx_bytes;
    u32 rx_packets;
    u32 rx_errors;
    u32 rx_crc_errors;
    u32 rx_frame_errors;
    u32 rx_length_errors;
    u32 rx_dropped;
    u32 rx_over_errors;
    u32 rx_ip_header_errors;
    u32 rx_ip_payload_errors;
    volatile u32 ts_int;
};

struct log_packet_t {
    u8 *packet; // source packet, RO
	u32 size; // TODO: maybe change to 'payload' length
	u32 ver;
	u32 ft;
	u32 msg;
    u8 *cmp; // packet to compare, RW
};

typedef struct EMACDeviceStruct {
    /* General */
    EMAC_T *Base;                    /* base address of MAC registers           */
    u64     PhyBase;                 /* PHY device address on MII interface     */
    u64     Version;                 /* Emac Revision version                   */
    u32     Intf;
    u32     ClockDivMdc;
    u32     LinkState;
    u32     DuplexMode;
    u32     Speed;
    u32     LoopbackMode;
    EMACconfig configs;
    tx_statistic tx_stat;
    rx_statistic rx_stat;
    struct net_device_stats NetStats;
    struct log_packet_t *pkt_send; // hacking for answer

    /* Descriptor */
    EnhDesc *TxDescDma;              /* Dma-able address of first tx descriptor either in ring or chain mode, this is used by the EMAC device*/
    EnhDesc *RxDescDma;              /* Dma-albe address of first rx descriptor either in ring or chain mode, this is used by the EMAC device*/
    EnhDesc *TxDesc;                 /* start address of TX descriptors ring or chain, this is used by the driver  */
    EnhDesc *RxDesc;                 /* start address of RX descriptors ring or chain, this is used by the driver  */
    u32     RxDescCount;             /* number of rx descriptors in the tx descriptor queue/pool */
    u32     TxDescCount;             /* number of tx descriptors in the rx descriptor queue/pool */
    u32     BusyTxDesc;              /* Number of Tx Descriptors owned by DMA at any given time*/
    u32     BusyRxDesc;              /* Number of Rx Descriptors owned by DMA at any given time*/
    u32     TxBusy;                  /* index of the tx descriptor owned by DMA, is obtained by GMAC_get_tx_qptr()                */
    u32     TxNext;                  /* index of the tx descriptor next available with driver, given to DMA by GMAC_set_tx_qptr() */
    u32     RxBusy;                  /* index of the rx descriptor owned by DMA, obtained by GMAC_get_rx_qptr()                   */
    u32     RxNext;                  /* index of the rx descriptor next available with driver, given to DMA by GMAC_set_rx_qptr() */
    EnhDesc *TxBusyDesc;             /* Tx Descriptor address corresponding to the index TxBusy */
    EnhDesc *TxNextDesc;             /* Tx Descriptor address corresponding to the index TxNext */
    EnhDesc *RxBusyDesc;             /* Rx Descriptor address corresponding to the index TxBusy */
    EnhDesc *RxNextDesc;             /* Rx Descriptor address corresponding to the index RxNext */
    EnhDesc *TxPrevDesc;             /* Previous Tx Descriptor */
    
    /* hash */
    u32 hash_table[2];               /* 64-entry hash table, 0 is high 32 bits, 1 is low 32 bits. Multicast and unicast share one table */
    u32 hash_id;

    /* timestamp */
    struct timespec64 tx_ts;
    struct timespec64 rx_ts;
    u32     ts_addend;
    u32     ts_alarm_flag;
    u32     pps_counter;
    u32     perout_enable;
    /* wol */
    u32     wol_flag;
} EMACdevice;

#define RXPKT_IPV4         (DescRxIPV4D >> DescRxIPVpos)
#define RXPKT_IPV6         (DescRxIPV6D >> DescRxIPVpos)
#define RXPKT_TCP          (DescRxTCPD >> DescRxPROTpos)
#define RXPKT_UDP          (DescRxUDPD >> DescRxPROTpos)

#define IPV4_CHKSUM_OFFSET 10
#define IPV4_HEADER        20
#define IPV6_HEADER        40
// #define ARP_HEADER         28
#define TCP_CHKSUM_OFFSET  16
#define UDP_CHKSUM_OFFSET  6
// #define ICMP_CHKSUM_OFFSET 2
#define PROTOCOL_TCP       6
#define PROTOCOL_UDP       17
// #define PROTOCOL_ICMP      1

#define IPV4_CHKSUM_POS    (ETHERNET_HEADER + IPV4_CHKSUM_OFFSET)
#define TCPIPV4_CHKSUM_POS (ETHERNET_HEADER + IPV4_HEADER + TCP_CHKSUM_OFFSET)
#define UDPIPV4_CHKSUM_POS (ETHERNET_HEADER + IPV4_HEADER + UDP_CHKSUM_OFFSET)
#define TCPIPV6_CHKSUM_POS (ETHERNET_HEADER + IPV6_HEADER + TCP_CHKSUM_OFFSET)
#define UDPIPV6_CHKSUM_POS (ETHERNET_HEADER + IPV6_HEADER + UDP_CHKSUM_OFFSET)


#define ETHERTYPE_ARP      0x0806
#define ETHERTYPE_IP       0x0800
#define ETHERTYPE_IPV6     0x86DD
#define ETHERTYPE_VLAN     0x8100
#define ETHERTYPE_PTP      0x88F7
#define ETHERTYPE_CF       0x8808
#define CF_OPCODE_PAUSE    0x0001

struct pseudo_header {
    uint32_t source_ip;
    uint32_t dest_ip;
    uint8_t reserved;
    uint8_t protocol;
    uint16_t length;
};

/******************************************************************************
 * Ethernet
 ******************************************************************************/
#define ETH_ALEN                     6
#define ETHERTYPE_OFFSET            12  //Offset of the Ethernet type field in the Ethernet header
#define ETHERNET_HEADER             14  //6 byte Dest addr, 6 byte Src addr, 2 byte length/type
#define ETHERNET_CRC                 4  //Ethernet CRC
#define ETHERNET_EXTRA               2  //Only God knows about this?????
#define ETHERNET_PACKET_COPY       250  // Maximum length when received data is copied on to a new skb
#define ETHERNET_PACKET_EXTRA       18  // Preallocated length for the rx packets is MTU + ETHERNET_PACKET_EXTRA
#define VLAN_TAG                     4  //optional 802.1q VLAN Tag
#define MIN_ETHERNET_PAYLOAD        46  //Minimum Ethernet payload size
#define MAX_ETHERNET_PAYLOAD      1500  //Maximum Ethernet payload size
#define JUMBO_FRAME_PAYLOAD       9000  //Jumbo frame payload size

typedef struct __attribute__((__packed__)) _eth_header {
    unsigned char da[6];
    unsigned char sa[6];
    unsigned char type[2];
} eth_header;

typedef struct __attribute__((__packed__)) _ip_header {
    unsigned char ver_ihl;
    unsigned char tos;
    unsigned char len[2];
    unsigned char id[2];
    unsigned char frag[2];
    unsigned char ttl;
    unsigned char protocol;
    unsigned char checksum[2];
    unsigned char src[4];
    unsigned char dest[4];
} ip_header;

typedef struct __attribute__((__packed__)) _eth_packet
{
	eth_header header;
	unsigned char payload[EMAC_TXFIFO_LEN-ETHERNET_HEADER];
} eth_packet;

int emac_open(enum EMACINTF intf, EMACconfig config);
void emac_ready(enum EMACINTF intf);
void emac_suspend(enum EMACINTF intf);
void emac_resume(enum EMACINTF intf);
EnhDesc *rx_desc_current(enum EMACINTF intf);
int emac_transmit_frames(enum EMACINTF intf, void *data, u16 len);
int change_mtu(enum EMACINTF intf, u16 mtu);
void set_control_frame(enum EMACINTF intf, u8 *da, u8 *sa, u16 opcode, u8 time);
void send_pause_frame(enum EMACINTF intf);

u32 hash_add_filter(enum EMACINTF intf, u8 *addr);
int hash_mask_filter(enum EMACINTF intf, u32 hashid);
void hash_clear_filter(enum EMACINTF intf);

int ts_set_timespec64(enum EMACINTF intf, struct timespec64 *ts);
int ts_set_time(enum EMACINTF intf, u64 nsec);
void ts_adjust_time_addsub(enum EMACINTF intf, s64 delta);
void ts_adjust_freq(enum EMACINTF intf, s32 ppb);
void ts_get_timespec64(enum EMACINTF intf, struct timespec64 *ts);
void ts_get_time(enum EMACINTF intf, u64 *nsec);
void ts_set_alarm(enum EMACINTF intf, u64 nsec);
void ts_delay_alarm(enum EMACINTF intf, u64 nsec);
int ts_check_alarm(enum EMACINTF intf);
void ts_delay_poll(enum EMACINTF intf, u64 nsdelay);
int pps_cmd_set(enum EMACINTF intf, enum PPSCMD cmd);
int pps_perout_cmd_set(enum EMACINTF intf, struct perout_request *req);

#ifdef __cplusplus
}
#endif

#endif  /* __EMAC_H__ */

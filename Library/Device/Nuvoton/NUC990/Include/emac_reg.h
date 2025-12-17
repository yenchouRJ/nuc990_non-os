/**************************************************************************//**
 * @file     emac_reg.h
 * @version  V1.00
 * @brief    NUC990 EMAC driver header file
 *
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/

#ifndef __EMAC_REG_H__
#define __EMAC_REG_H__

#ifdef __cplusplus
extern "C"
{
#endif

/*---------------------- Ethernet MAC Controller -------------------------*/
/**
    @addtogroup EMAC Ethernet MAC Controller(EMAC)
    Memory Mapped Structure for EMAC Controller
@{ */

typedef struct {
/**
 * @var EMAC_T::CAMCMR
 * Offset: 0x00  EMAC0 CAM Command Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |AUP       |Accept Unicast Packet
 * |        |          |The AUP controls the unicast packet reception
 * |        |          |If AUP is enabled, EMAC receives all incoming packet its destination MAC address is a unicast address.
 * |        |          |0 = EMAC receives packet depends on the CAM comparison result.
 * |        |          |1 = EMAC receives all unicast packets.
 * |[1]     |AMP       |Accept Multicast Packet
 * |        |          |The AMP controls the multicast packet reception
 * |        |          |If AMP is enabled, EMAC receives all incoming packet its destination MAC address is a multicast address.
 * |        |          |0 = EMAC receives packet depends on the CAM comparison result.
 * |        |          |1 = EMAC receives all multicast packets.
 * |[2]     |ABP       |Accept Broadcast Packet
 * |        |          |The ABP controls the broadcast packet reception
 * |        |          |If ABP is enabled, EMAC receives all incoming packet its destination MAC address is a broadcast address.
 * |        |          |0 = EMAC receives packet depends on the CAM comparison result.
 * |        |          |1 = EMAC receives all broadcast packets.
 * |[3]     |CCAM      |Complement CAM Compare
 * |        |          |The CCAM controls the complement of the CAM comparison result
 * |        |          |If the ECMP and CCAM are both enabled, the incoming packet with specific destination MAC address configured in CAM entry will be dropped
 * |        |          |And the incoming packet with destination MAC address does not configured in any CAM entry will be received.
 * |        |          |0 = The CAM comparison result does not complement.
 * |        |          |1 = The CAM comparison result complemented.
 * |        |          |Note: When CCAM is set high, both AHMP and AHUP must be reset low.
 * |[4]     |ECMP      |CAM Compare Enable Bit
 * |        |          |The ECMP controls the enable of CAM comparison function for destination MAC address recognition
 * |        |          |If software wants to receive a packet with specific destination MAC address, configures the MAC address into CAM 12~0, then enables that CAM entry and set ECMP to 1.
 * |        |          |0 = CAM comparison function for destination MAC address recognition Disabled.
 * |        |          |1 = CAM comparison function for destination MAC address recognition Enabled.
 * |[8]     |AHUP      |Accept Hash Unicast Packet
 * |        |          |The AHUP controls the hash unicast packet reception
 * |        |          |If AHUP is enabled, EMAC receives all incoming packet its destination MAC address is a unicast address according to the hash table.
 * |        |          |0 = EMAC receives packet depends on the CAM comparison result.
 * |        |          |1 = EMAC receives all unicast packets that match the hash table.
 * |        |          |Note: AHUP is only valid when AUP is reset low.
 * |[9]     |AHMP      |Accept Hash Multicast Packet
 * |        |          |The AHMP controls the hash multicast packet reception
 * |        |          |If AHMP is enabled, EMAC receives all incoming packet its destination MAC address is a multicast address according to the hash table.
 * |        |          |0 = EMAC receives packet depends on the CAM comparison result.
 * |        |          |1 = EMAC receives all multicast packets that match the hash table.
 * |        |          |Note: AHMP is only valid when AMP is reset low.
 * @var EMAC_T::CAMEN
 * Offset: 0x04  EMAC0 CAM Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |CAMxEN    |CAM Entry X Enable Bit
 * |        |          |The CAMxEN controls the validation of CAM entry x. The x can be 0 to 15.
 * |        |          |The CAM entry 13, 14 and 15 are for PAUSE control frame transmission
 * |        |          |If software wants to transmit a PAUSE control frame out to network, the enable bits of these three CAM entries all must be enabled first.
 * |        |          |0 = CAM entry x Disabled.
 * |        |          |1 = CAM entry x Enabled.
 * @var EMAC_T::CAMxM
 * Offset: 0x08  EMAC0 CAM x Most Significant Word Register, x = 0 ~ 14
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CAMxM     |The CAMxM keeps the bit 47~16 of MAC address. The x can be the 0~14.
 * |        |          |The register pair {EMACn_CAMxM, EMACn_CAMxL} represents a CAM entry and keeps a MAC address.
 * |        |          |For example, if the MAC address 00-50-BA-33-BA-44 kept in CAM entry 1, the register EMACn_CAM1M is 32‟h0050_BA33 and EMACn_CAM1L is 32‟hBA44_0000.
 * @var EMAC_T::CAMxL
 * Offset: 0x0C  EMAC0 CAM x Least Significant Word Register, x = 0 ~ 14
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CAMxL     |The CAMxL keeps the bit 15~0 of MAC address. The x can be the 0~14.
 * |        |          |The register pair {EMACn_CAMxM, EMACn_CAMxL} represents a CAM entry and keeps a MAC address.
 * |        |          |For example, if the MAC address 00-50-BA-33-BA-44 kept in CAM entry 1, the register EMACn_CAM1M is 32‟h0050_BA33 and EMACn_CAM1L is 32‟hBA44_0000.
 * @var EMAC_T::CAM15M
 * Offset: 0x80  EMAC0 CAM 15 Most Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |OPCode    |OP Code Field of PAUSE Control Frame
 * |        |          |In the PAUSE control frame, an op code field defined and is 16&#8223;h0001.
 * |[31:16] |LenType   |Length/Type Field of PAUSE Control Frame
 * |        |          |In the PAUSE control frame, a length/type field defined and is 16&#8223;h8808.
 * @var EMAC_T::CAM15L
 * Offset: 0x84  EMAC0 CAM 15 Least Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:24] |Operand   |Pause Parameter
 * |        |          |In the PAUSE control frame, an operand field defined and controls how much time the destination Ethernet MAC Controller paused
 * |        |          |The unit of the operand is a slot time, the 512 bits time.
 * @var EMAC_T::TXDLSA
 * Offset: 0x88  EMAC0 Transmit Descriptor Link List Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |TXDLSA    |Transmit Descriptor Link-list Start Address
 * |        |          |The TXDLSA keeps the start address of transmit descriptor link-list
 * |        |          |If the software enables the bit TXON (EMAC0_MCMDR[8]), the content of TXDLSA will be loaded into the current transmit descriptor start address register (EMAC0_CTXDSA)
 * |        |          |The TXDLSA does not be updated by EMAC
 * |        |          |During the operation, EMAC will ignore the bits [1:0] of TXDLSA
 * |        |          |This means that each TX descriptor always must locate at word boundary memory address.
 * |        |          |Note: After TXON (EMAC0_MCMDR[8]) is enabled, if the user wants to modify TXDLSA, SWR needs to be executed first.
 * @var EMAC_T::RXDLSA
 * Offset: 0x8C  EMAC0 Receive Descriptor Link List Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |RXDLSA    |Receive Descriptor Link-list Start Address
 * |        |          |The RXDLSA keeps the start address of receive descriptor link-list
 * |        |          |If the SOFTWARE enables the bit RXON (EMAC0_MCMDR[0]), the content of RXDLSA will be loaded into the current receive descriptor start address register (EMAC0_CRXDSA)
 * |        |          |The RXDLSA does not be updated by EMAC
 * |        |          |During the operation, EMAC will ignore the bits [1:0] of RXDLSA
 * |        |          |This means that each RX descriptor always must locate at word boundary memory address.
 * |        |          |After RXON (EMAC0_MCMDR[0]) is enabled, if the user wants to modify RXDLSA, SWR needs to be executed first.
 * @var EMAC_T::MCMDR
 * Offset: 0x90  EMAC0 MAC Command Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |RXON      |Frame Reception ON
 * |        |          |The RXON controls the normal packet reception of EMAC
 * |        |          |If the RXON is set to high, the EMAC starts the packet reception process, including the RX descriptor fetching, packet reception and RX descriptor modification.
 * |        |          |It is necessary to finish EMAC initial sequence before enable RXON
 * |        |          |Otherwise, the EMAC operation is undefined.
 * |        |          |If the RXON is disabled during EMAC is receiving an incoming packet, the EMAC stops the packet reception process after the current packet reception finished.
 * |        |          |0 = Packet reception process stopped.
 * |        |          |1 = Packet reception process started.
 * |[1]     |ALP       |Accept Long Packet
 * |        |          |The ALP controls the long packet, which packet length is greater than 1518 bytes, reception
 * |        |          |If the ALP is set to high, the EMAC will accept the long packet.
 * |        |          |Otherwise, the long packet will be dropped.
 * |        |          |0 = Ethernet MAC controller dropped the long packet.
 * |        |          |1 = Ethernet MAC controller received the long packet.
 * |[2]     |ARP       |Accept Runt Packet
 * |        |          |The ARP controls the runt packet, which length is less than 64 bytes, reception
 * |        |          |If the ARP is set to high, the EMAC will accept the runt packet.
 * |        |          |Otherwise, the runt packet will be dropped.
 * |        |          |0 = Ethernet MAC controller dropped the runt packet.
 * |        |          |1 = Ethernet MAC controller received the runt packet.
 * |[3]     |ACP       |Accept Control Packet
 * |        |          |The ACP controls the control frame reception
 * |        |          |When the ACP is set to high, the EMAC will accept the control frame if it is correct, and drop the control frame if it is incorrect
 * |        |          |When the ACP is reset to low, the control frame will be received as a normal frame and not considered a control frame
 * |        |          |It is recommended that SOFTWARE only enable ACP while EMAC is operating on full duplex mode.
 * |        |          |0 = Ethernet MAC controller received the control frame but considered it a normal frame.
 * |        |          |1 = Ethernet MAC controller received the control frame.
 * |[4]     |AEP       |Accept CRC Error Packet
 * |        |          |The AEP controls the EMAC accepts or drops the CRC error packet
 * |        |          |If the AEP is set to high, the incoming packet with CRC error will be received by EMAC as a good packet.
 * |        |          |0 = Ethernet MAC controller dropped the CRC error packet.
 * |        |          |1 = Ethernet MAC controller received the CRC error packet.
 * |[5]     |SPCRC     |Strip CRC Checksum
 * |        |          |The SPCRC controls if the length of incoming packet is calculated with 4 bytes CRC checksum
 * |        |          |If the SPCRC is set to high, 4 bytes CRC checksum is excluded from length calculation of incoming packet.
 * |        |          |0 = The 4 bytes CRC checksum is included in packet length calculation.
 * |        |          |1 = The 4 bytes CRC checksum is excluded in packet length calculation.
 * |[6]     |MGPWKEN   |Magic Packet Wake-up Enable Bit
 * |        |          |The MGPWKEN high enables the functionality that Ethernet MAC controller checked if the incoming packet is Magic Packet and wakeup system from Power-down mode.
 * |        |          |If incoming packet was a Magic Packet and the system was in Power-down, the Ethernet MAC controller would generate a wakeup event to wake system up from Power-down mode.
 * |        |          |0 = Wake-up by Magic Packet function Disabled.
 * |        |          |1 = Wake-up by Magic Packet function Enabled.
 * |[7]     |PTPSRC    |PTP Counter Source Selection
 * |        |          |This bit control the PTP counter source is from EMC0 or from EMC1 internally.
 * |        |          |1u2019b0: The PTP counter source is from EMC1 internally
 * |        |          |1u2019b1: The PTP counter source is from EMC0.
 * |        |          |Note: This bit is only available in EMAC1. In EMAC0, this bit is reserved.
 * |[8]     |TXON      |Frame Transmission ON
 * |        |          |The TXON controls the normal packet transmission of EMAC
 * |        |          |If the TXON is set to high, the EMAC starts the packet transmission process, including the TX descriptor fetching, packet transmission and TX descriptor modification.
 * |        |          |It is must to finish EMAC initial sequence before enable TXON
 * |        |          |Otherwise, the EMAC operation is undefined.
 * |        |          |If the TXON is disabled during EMAC is transmitting a packet out, the EMAC stops the packet transmission process after the current packet transmission finished.
 * |        |          |0 = Packet transmission process stopped.
 * |        |          |1 = Packet transmission process started.
 * |[9]     |NDEF      |No Deferral
 * |        |          |The NDEF controls the enable of deferral exceed counter
 * |        |          |If NDEF is set to high, the deferral exceed counter is disabled
 * |        |          |The NDEF is only useful while EMAC is operating on half duplex mode.
 * |        |          |0 = The deferral exceed counter Enabled.
 * |        |          |1 = The deferral exceed counter Disabled.
 * |[11]    |RTIOEN    |RX TCP/IP Offload Engine Enable Bit
 * |        |          |The RTIOEN controls the RX TCP/IP checksum comparison and error detection.
 * |        |          |0 = RX TCP/IP Offload Engine Disabled.
 * |        |          |1 = IPv4 header checksum and payload checksum (TCP or UDP) comparison and IP header error detection Enabled.
 * |[16]    |SDPZ      |Send PAUSE Frame
 * |        |          |The SDPZ controls the PAUSE control frame transmission.
 * |        |          |If SOFTWARE wants to send a PAUSE control frame out, the CAM entry 13, 14 and 15 must be configured first and the corresponding CAM enable bit of CAMEN register also must be set
 * |        |          |Then, set SDPZ to 1 enables the PAUSE control frame transmission.
 * |        |          |The SDPZ is a self-clear bit
 * |        |          |This means after the PAUSE control frame transmission has completed, the SDPZ will be cleared automatically.
 * |        |          |It is recommended that only enabling SPDZ while EMAC is operating in Full Duplex mode.
 * |        |          |0 = PAUSE control frame transmission completed.
 * |        |          |1 = PAUSE control frame transmission Enabled.
 * |[17]    |SQECHKEN  |SQE Checking Enable Bit
 * |        |          |The SQECHKEN controls the enable of SQE checking
 * |        |          |The SQE checking is only available while EMAC is operating on 10M bps and half duplex mode
 * |        |          |In other words, the SQECHKEN cannot affect EMAC operation, if the EMAC is operating on 100M bps or full duplex mode.
 * |        |          |0 = SQE checking Disabled while EMAC is operating in 10Mbps and Half Duplex mode.
 * |        |          |1 = SQE checking Enabled while EMAC is operating in 10Mbps and Half Duplex mode.
 * |[18]    |FDUP      |Full Duplex Mode Selection
 * |        |          |The FDUP controls that if EMAC is operating on full or half duplex mode.
 * |        |          |0 = EMAC operates in half duplex mode.
 * |        |          |1 = EMAC operates in full duplex mode.
 * |[20]    |OPMOD     |Operation Mode Selection
 * |        |          |The OPMOD defines that if the EMAC is operating on 10M or 100M bps mode
 * |        |          |The SWR would not affect OPMOD value.
 * |        |          |0 = EMAC operates in 10Mbps mode.
 * |        |          |1 = EMAC operates in 100Mbps mode.
 * |[24]    |SWR       |Software Reset
 * |        |          |The SWR implements a reset function to make the EMAC return default state
 * |        |          |The SWR is a self-clear bit
 * |        |          |This means after the software reset finished, the SWR will be cleared automatically
 * |        |          |Enable SWR can also reset all control and status registers, exclusive of the control bit OPMOD (EMAC0_MCMDR[20]).
 * |        |          |The EMAC re-initial is necessary after the software reset completed.
 * |        |          |0 = Software reset completed.
 * |        |          |1 = Software reset Enabled.
 * @var EMAC_T::MIID
 * Offset: 0x94  EMAC0 MII Management Data Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |DATA      |MII Management Data
 * |        |          |The MIIData is the 16 bits data that will be written into the registers of external PHY for MII Management write command or the data from the registers of external PHY for MII Management read command.
 * @var EMAC_T::MIIDA
 * Offset: 0x98  EMAC0 MII Management Control and Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |PHYRAD    |PHY Register Address
 * |        |          |The PHYRAD keeps the address to indicate which register of external PHY is the target of the MII management command.
 * |[12:8]  |PHYAD     |PHY Address
 * |        |          |The PHYAD keeps the address to differentiate which external PHY is the target of the MII management command.
 * |[16]    |WRITE     |Write Command
 * |        |          |The WRITE defines the MII management command is a read or write.
 * |        |          |0 = MII management command is a read command.
 * |        |          |1 = MII management command is a write command.
 * |[17]    |BUSY      |Busy Bit
 * |        |          |The BUSY controls the enable of the MII management frame generation
 * |        |          |If SOFTWARE wants to access registers of external PHY, it set BUSY to high and EMAC generates the MII management frame to external PHY through MII Management I/F
 * |        |          |The BUSY is a self-clear bit
 * |        |          |This means the BUSY will be cleared automatically after the MII management command finished.
 * |        |          |0 = MII management command generation finished.
 * |        |          |1 = MII management command generation Enabled.
 * |[18]    |PREAMSP   |Preamble Suppress
 * |        |          |The PREAMSP controls the preamble field generation of MII management frame
 * |        |          |If the PREAMSP is set to high, the preamble field generation of MII management frame is skipped.
 * |        |          |0 = Preamble field generation of MII management frame not skipped.
 * |        |          |1 = Preamble field generation of MII management frame skipped.
 * |[19]    |MDCON     |MDC Clock ON Always
 * |        |          |The MDC controls the MDC clock generation
 * |        |          |If the MDCON is set to high, the MDC clock actives always
 * |        |          |Otherwise, the MDC will only active while SOFTWARE issues a MII management command.
 * |        |          |0 = MDC clock only actives while SOFTWARE issues a MII management command.
 * |        |          |1 = MDC clock actives always.
 * @var EMAC_T::FFTCR
 * Offset: 0x9C  EMAC0 FIFO Threshold Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |RXTHD     |RXFIFO Low Threshold
 * |        |          |The RXTHD controls when RXDMA requests internal arbiter for data transfer between RXFIFO and system memory
 * |        |          |The RXTHD defines not only the high threshold of RXFIFO, but also the low threshold
 * |        |          |The low threshold is the half of high threshold always
 * |        |          |During the packet reception, if the RXFIFO reaches the high threshold, the RXDMA starts to transfer frame data from RXFIFO to system memory
 * |        |          |If the frame data in RXFIFO is less than low threshold, RXDMA stops to transfer the frame data to system memory.
 * |        |          |00 = Depend on the burst length setting
 * |        |          |If the burst length is 8 words, high threshold is 8 words, too.
 * |        |          |01 = RXFIFO high threshold is 64B and low threshold is 32B.
 * |        |          |10 = RXFIFO high threshold is 128B and low threshold is 64B.
 * |        |          |11 = RXFIFO high threshold is 192B and low threshold is 96B.
 * |[9:8]   |TXTHD     |TXFIFO Low Threshold
 * |        |          |The TXTHD controls when TXDMA requests internal arbiter for data transfer between system memory and TXFIFO
 * |        |          |The TXTHD defines not only the low threshold of TXFIFO, but also the high threshold
 * |        |          |The high threshold is the twice of low threshold always
 * |        |          |During the packet transmission, if the TXFIFO reaches the high threshold, the TXDMA stops generate request to transfer frame data from system memory to TXFIFO
 * |        |          |If the frame data in TXFIFO is less than low threshold, TXDMA starts to transfer frame data from system memory to TXFIFO.
 * |        |          |The TXTHD also defines when the TXMAC starts to transmit frame out to network
 * |        |          |The TXMAC starts to transmit the frame out while the TXFIFO first time reaches the high threshold during the transmission of the frame
 * |        |          |If the frame data length is less than TXFIFO high threshold, the TXMAC starts to transmit the frame out after the frame data are all inside the TXFIFO.
 * |        |          |00 = Undefined.
 * |        |          |01 = TXFIFO low threshold is 64B and high threshold is 128B.
 * |        |          |10 = TXFIFO low threshold is 80B and high threshold is 160B.
 * |        |          |11 = TXFIFO low threshold is 96B and high threshold is 192B.
 * |[21:20] |BURSTLEN  |DMA Burst Length
 * |        |          |This defines the burst length of AHB bus cycle while EMAC accesses system memory.
 * |        |          |00 = 4 words.
 * |        |          |01 = 8 words.
 * |        |          |10 = 16 words.
 * |        |          |11 = 16 words.
 * @var EMAC_T::TSDR
 * Offset: 0xA0  EMAC0 Transmit Start Demand Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |TSD       |Transmit Start Demand
 * |        |          |If the TX descriptor is not available for use of TXDMA after the TXON (EMAC0_MCMDR[8]) is enabled, the FSM (Finite State Machine) of TXDMA enters the Halt state and the frame transmission is halted
 * |        |          |After the SOFTWARE has prepared the new TX descriptor for frame transmission, it must issue a write command to EMAC0_TSDR register to make TXDMA to leave Halt state and continue the frame transmission.
 * |        |          |The EMAC0_TSDR is a write only register and the value read from this register is undefined.
 * |        |          |The write to EMAC0_TSDR register takes effect only when TXDMA stayed at Halt state.
 * @var EMAC_T::RSDR
 * Offset: 0xA4  EMAC0 Receive Start Demand Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |RSD       |Receive Start Demand
 * |        |          |If the RX descriptor is not available for use of RXDMA after the RXON (EMAC0_MCMDR[0]) is enabled, the FSM (Finite State Machine) of RXDMA enters the Halt state and the frame reception is halted
 * |        |          |After the SOFTWARE has prepared the new RX descriptor for frame reception, it must issue a write command to EMAC0_RSDR register to make RXDMA to leave Halt state and continue the frame reception.
 * |        |          |The EMAC0_RSDR is a write only register and the value read from this register is undefined.
 * |        |          |The write to EMAC0_RSDR register takes effect only when RXDMA stayed at Halt state.
 * @var EMAC_T::DMARFC
 * Offset: 0xA8  EMAC0 Maximum Receive Frame Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |RXMS      |Maximum Receive Frame Length
 * |        |          |The RXMS defines the maximum frame length for received frame
 * |        |          |If the frame length of received frame is greater than RXMS, and bit MFLEIEN (EMAC0_MIEN[8]) is also enabled, the bit DFO (EMAC0_MISTA[8]) is set and the RX interrupt is triggered.
 * |        |          |It is recommended that only use RXMS to qualify the length of received frame while SOFTWARE wants to receive a frame which length is greater than 1518 bytes.
 * @var EMAC_T::MIEN
 * Offset: 0xAC  EMAC0 MAC Interrupt Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |RXIEN     |Receive Interrupt Enable Bit
 * |        |          |The RXIEN controls the RX interrupt generation.
 * |        |          |If RXIEN is enabled and RXINTR (EMAC0_MISTA[0]) is high, EMAC generates the RX interrupt to CPU
 * |        |          |If RXIEN is disabled, no RX interrupt is generated to CPU even any status bit EMAC0_MISTA[15:1] is set and the corresponding bit of EMAC0_MIEN is enabled
 * |        |          |In other words, if SOFTWARE wants to receive RX interrupt from EMAC, this bit must be enabled
 * |        |          |And, if SOFTWARE doesn&#8223;t want to receive any RX interrupt from EMAC, disables this bit.
 * |        |          |0 = RXINTR (EMAC0_MISTA[0]) is masked and RX interrupt generation Disabled.
 * |        |          |1 = RXINTR (EMAC0_MISTA[0]) is not masked and RX interrupt generation Enabled.
 * |[1]     |CRCEIEN   |CRC Error Interrupt Enable Bit
 * |        |          |The CRCEIEN controls the CRCE (EMAC0_MISTA[1]) interrupt generation
 * |        |          |If CRCE (EMAC0_MISTA[1]) is set, and both CRCEIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If CRCEIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the CRCE (EMAC0_MISTA[1]) is set.
 * |        |          |0 = CRCE (EMAC0_MISTA[1]) trigger RX interrupt Disabled.
 * |        |          |1 = CRCE (EMAC0_MISTA[1]) trigger RX interrupt Enabled.
 * |[2]     |RXOVIEN   |Receive FIFO Overflow Interrupt Enable Bit
 * |        |          |The RXOVIEN controls the RXOV (EMAC0_MISTA[2]) interrupt generation
 * |        |          |If RXOV (EMAC0_MISTA[2]) is set, and both RXOVIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If RXOVIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the RXOV (EMAC0_MISTA[2]) is set.
 * |        |          |0 = RXOV (EMAC0_MISTA[2]) trigger RX interrupt Disabled.
 * |        |          |1 = RXOV (EMAC0_MISTA[2]) trigger RX interrupt Enabled.
 * |[3]     |LPIEN     |Long Packet Interrupt Enable Bit
 * |        |          |The LPIEN controls the PTLE (EMAC0_MISTA[3]) interrupt generation
 * |        |          |If PTLE (EMAC0_MISTA[3]) is set, and both LPIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If LPIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the PTLE (EMAC0_MISTA[3]) is set.
 * |        |          |0 = PTLE (EMAC0_MISTA[3]) trigger RX interrupt Disabled.
 * |        |          |1 = PTLE (EMAC0_MISTA[3]) trigger RX interrupt Enabled.
 * |[4]     |RXGDIEN   |Receive Good Interrupt Enable Bit
 * |        |          |The RXGDIEN controls the RXGD (EMAC0_MISTA[4]) interrupt generation
 * |        |          |If RXGD (EMAC0_MISTA[4]) is set, and both RXGDIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If RXGDIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the RXGD (EMAC0_MISTA[4]) is set.
 * |        |          |0 = RXGD (EMAC0_MISTA[4]) trigger RX interrupt Disabled.
 * |        |          |1 = RXGD (EMAC0_MISTA[4]) trigger RX interrupt Enabled.
 * |[5]     |ALIEIEN   |Alignment Error Interrupt Enable Bit
 * |        |          |The ALIEIEN controls the ALIE (EMAC0_MISTA[5]) interrupt generation
 * |        |          |If ALIE (EMAC0_MISTA[5]) is set, and both ALIEIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If ALIEIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the ALIE (EMAC0_MISTA[5]) is set.
 * |        |          |0 = ALIE (EMAC0_MISTA[5]) trigger RX interrupt Disabled.
 * |        |          |1 = ALIE (EMAC0_MISTA[5]) trigger RX interrupt Enabled.
 * |[6]     |RPIEN     |Runt Packet Interrupt Enable Bit
 * |        |          |The RPIEN controls the RP (EMAC0_MISTA[6]) interrupt generation
 * |        |          |If RP (EMAC0_MISTA[6]) is set, and both RPIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If RPIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the RP (EMAC0_MISTA[6]) is set.
 * |        |          |0 = RP (EMAC0_MISTA[6]) trigger RX interrupt Disabled.
 * |        |          |1 = RP (EMAC0_MISTA[6]) trigger RX interrupt Enabled.
 * |[7]     |MMPIEN    |Miss Packet Counter Overrun Interrupt Enable Bit
 * |        |          |The MMPIEN controls the MMP (EMAC0_MISTA[7]) interrupt generation
 * |        |          |If MMP (EMAC0_MISTA[7]) is set, and both MMPIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If MMPIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the MMP (EMAC0_MISTA[7]) is set.
 * |        |          |0 = MMP (EMAC0_MISTA[7]) trigger RX interrupt Disabled.
 * |        |          |1 = MMP (EMAC0_MISTA[7]) trigger RX interrupt Enabled.
 * |[8]     |MFLEIEN   |Maximum Frame Length Exceed Interrupt Enable Bit
 * |        |          |The MFLEIEN controls the DFO (EMAC0_MISTA[8]) interrupt generation
 * |        |          |If DFO (EMAC0_MISTA[8]) is set, and both MFLEIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If MFLEIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the DFO (EMAC0_MISTA[8]) is set.
 * |        |          |0 = DFO (EMAC0_MISTA[8]) trigger RX interrupt Disabled.
 * |        |          |1 = DFO (EMAC0_MISTA[8]) trigger RX interrupt Enabled.
 * |[9]     |DENIEN    |DMA Early Notification Interrupt Enable Bit
 * |        |          |The DENIEN controls the DEN (EMAC0_MISTA[9]) interrupt generation
 * |        |          |If DEN (EMAC0_MISTA[9]) is set, and both DENIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If DENIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the DEN (EMAC0_MISTA[9]) is set.
 * |        |          |0 = DEN (EMAC0_MISTA[9]) trigger RX interrupt Disabled.
 * |        |          |1 = DEN (EMAC0_MISTA[9]) trigger RX interrupt Enabled.
 * |[10]    |RDUIEN    |Receive Descriptor Unavailable Interrupt Enable Bit
 * |        |          |The RDUIEN controls the RDU (EMAC0_MISTA[10]) interrupt generation
 * |        |          |If RDU (EMAC0_MISTA[10]) is set, and both RDUIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If RDUIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the RDU (EMAC0_MISTA[10]) is set.
 * |        |          |0 = RDU (EMAC0_MISTA[10]) trigger RX interrupt Disabled.
 * |        |          |1 = RDU (EMAC0_MISTA[10]) trigger RX interrupt Enabled.
 * |[11]    |RXBEIEN   |Receive Bus Error Interrupt Enable Bit
 * |        |          |The RXBEIEN controls the RXBERR (EMAC0_MISTA[11]) interrupt generation
 * |        |          |If RXBERR (EMAC0_MISTA[11]) is set, and both RXBEIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If RXBEIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the RXBERR (EMAC0_MISTA[11]) is set.
 * |        |          |0 = RXBERR (EMAC0_MISTA[11]) trigger RX interrupt Disabled.
 * |        |          |1 = RXBERR (EMAC0_MISTA[11]) trigger RX interrupt Enabled.
 * |[14]    |CFRIEN    |Control Frame Receive Interrupt Enable Bit
 * |        |          |The CFRIEN controls the CFR (EMAC0_MISTA[14]) interrupt generation
 * |        |          |If CFR (EMAC0_MISTA[14]) is set, and both CFRIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If CFRIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the CFR (EMAC0_MISTA[14]) is set.
 * |        |          |0 = CFR (EMAC0_MISTA[14]) trigger RX interrupt Disabled.
 * |        |          |1 = CFR (EMAC0_MISTA[14]) trigger RX interrupt Enabled.
 * |[15]    |WOLIEN    |Magic Packet Receive Interrupt Enable Bit
 * |        |          |The WOLIEN controls the MPR (EMAC0_MISTA[15]) interrupt generation
 * |        |          |If MPR (EMAC0_MISTA[15]) is set, and both WOLIEN and RXIEN (EMAC0_MIEN[0]) are enabled, the EMAC generates the RX interrupt to CPU
 * |        |          |If WOLIEN or RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated to CPU even the MPR (EMAC0_MISTA[15]) is set.
 * |        |          |0 = MPR (EMAC0_MISTA[15]) trigger RX interrupt Disabled.
 * |        |          |1 = MPR (EMAC0_MISTA[15]) trigger RX interrupt Enabled.
 * |[16]    |TXIEN     |Transmit Interrupt Enable Bit
 * |        |          |The TXIEN controls the TX interrupt generation.
 * |        |          |If TXIEN is enabled and TXINTR (EMAC0_MISTA[16]) is high, EMAC generates the TX interrupt to CPU
 * |        |          |If TXIEN is disabled, no TX interrupt is generated to CPU even any status bit of EMAC0_MISTA[24:17] is set and the corresponding bit of EMAC0_MIEN is enabled
 * |        |          |In other words, if SOFTWARE wants to receive TX interrupt from EMAC, this bit must be enabled
 * |        |          |And, if SOFTWARE doesn&#8223;t want to receive any TX interrupt from EMAC, disables this bit.
 * |        |          |0 = TXINTR (EMAC0_MISTA[16]) is masked and TX interrupt generation Dsiabled.
 * |        |          |1 = TXINTR (EMAC0_MISTA[16]) is not masked and TX interrupt generation Enabled.
 * |[17]    |TXUDIEN   |Transmit FIFO Underflow Interrupt Enable Bit
 * |        |          |The TXUDIEN controls the TXEMP (EMAC0_MISTA[17]) interrupt generation
 * |        |          |If TXEMP (EMAC0_MISTA[17]) is set, and both TXUDIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TXUDIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the TXEMP (EMAC0_MISTA[17]) is set.
 * |        |          |0 = TXEMP (EMAC0_MISTA[17]) trigger TX interrupt Disabled.
 * |        |          |1 = TXEMP (EMAC0_MISTA[17]) trigger TX interrupt Enabled.
 * |[18]    |TXCPIEN   |Transmit Completion Interrupt Enable Bit
 * |        |          |The TXCPIEN controls the TXCP (EMAC0_MISTA[18]) interrupt generation
 * |        |          |If TXCP (EMAC0_MISTA[18]) is set, and both TXCPIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TXCPIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the TXCP (EMAC0_MISTA[18]) is set.
 * |        |          |0 = TXCP (EMAC0_MISTA[18]) trigger TX interrupt Disabled.
 * |        |          |1 = TXCP (EMAC0_MISTA[18]) trigger TX interrupt Enabled.
 * |[19]    |EXDEFIEN  |Defer Exceed Interrupt Enable Bit
 * |        |          |The EXDEFIEN controls the EXDEF (EMAC0_MISTA[19]) interrupt generation
 * |        |          |If EXDEF (EMAC0_MISTA[19]) is set, and both EXDEFIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If EXDEFIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the EXDEF (EMAC0_MISTA[19]) is set.
 * |        |          |0 = EXDEF (EMAC0_MISTA[19]) trigger TX interrupt Disabled.
 * |        |          |1 = EXDEF (EMAC0_MISTA[19]) trigger TX interrupt Enabled.
 * |[20]    |NCSIEN    |No Carrier Sense Interrupt Enable Bit
 * |        |          |The NCSIEN controls the NCS (EMAC0_MISTA[20]) interrupt generation
 * |        |          |If NCS (EMAC0_MISTA[20]) is set, and both NCSIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If NCSIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the NCS (EMAC0_MISTA[20]) is set.
 * |        |          |0 = NCS (EMAC0_MISTA[20]) trigger TX interrupt Disabled.
 * |        |          |1 = NCS (EMAC0_MISTA[20]) trigger TX interrupt Enabled.
 * |[21]    |TXABTIEN  |Transmit Abort Interrupt Enable Bit
 * |        |          |The TXABTIEN controls the TXABT (EMAC0_MISTA[21]) interrupt generation
 * |        |          |If TXABT (EMAC0_MISTA[21]) is set, and both TXABTIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TXABTIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the TXABT (EMAC0_MISTA[21]) is set.
 * |        |          |0 = TXABT (EMAC0_MISTA[21]) trigger TX interrupt Disabled.
 * |        |          |1 = TXABT (EMAC0_MISTA[21]) trigger TX interrupt Enabled.
 * |[22]    |LCIEN     |Late Collision Interrupt Enable Bit
 * |        |          |The LCIEN controls the LC (EMAC0_MISTA[22]) interrupt generation
 * |        |          |If LC (EMAC0_MISTA[22]) is set, and both LCIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If LCIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the LC (EMAC0_MISTA[22]) is set.
 * |        |          |0 = LC (EMAC0_MISTA[22]) trigger TX interrupt Disabled.
 * |        |          |1 = LC (EMAC0_MISTA[22]) trigger TX interrupt Enabled.
 * |[23]    |TDUIEN    |Transmit Descriptor Unavailable Interrupt Enable Bit
 * |        |          |The TDUIEN controls the TDU (EMAC0_MISTA[23]) interrupt generation
 * |        |          |If TDU (EMAC0_MISTA[23]) is set, and both TDUIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TDUIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the TDU (EMAC0_MISTA[23]) is set.
 * |        |          |0 = TDU (EMAC0_MISTA[23]) trigger TX interrupt Disabled.
 * |        |          |1 = TDU (EMAC0_MISTA[23]) trigger TX interrupt Enabled.
 * |[24]    |TXBEIEN   |Transmit Bus Error Interrupt Enable Bit
 * |        |          |The TXBEIEN controls the TXBERR (EMAC0_MISTA[24]) interrupt generation
 * |        |          |If TXBERR (EMAC0_MISTA[24]) is set, and both TXBEIEN and TXIEN (EMAC0_MIEN[16]) are enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TXBEIEN or TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated to CPU even the TXBERR (EMAC0_MISTA[24]) is set.
 * |        |          |0 = TXBERR (EMAC0_MISTA[24]) trigger TX interrupt Disabled.
 * |        |          |1 = TXBERR (EMAC0_MISTA[24]) trigger TX interrupt Enabled.
 * |[28]    |TSALMIEN  |Time Stamp Alarm Interrupt Enable Bit
 * |        |          |The TSALMIEN controls the TSALS (EMAC0_MISTA[28]) interrupt generation
 * |        |          |If TSALS (EMAC0_MISTA[28]) is set, and both TSALMIEN and TXIEN (EMAC0_MIEN[16]) enabled, the EMAC generates the TX interrupt to CPU
 * |        |          |If TSALMIEN or TXIEN (EMAC0_MIEN[16]) disabled, no TX interrupt generated to CPU even the TSALS (EMAC0_MISTA[28]) is set.
 * |        |          |0 = TSALS (EMAC0_MISTA[28]) trigger TX interrupt Disabled.
 * |        |          |1 = TSALS (EMAC0_MISTA[28]) trigger TX interrupt Enabled.
 * @var EMAC_T::MISTA
 * Offset: 0xB0  EMAC0 MAC Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |RXINTR    |Receive Interrupt
 * |        |          |The RXINTR indicates the RX interrupt status.
 * |        |          |If RXINTR high and its corresponding enable bit, RXIEN (EMAC0_MIEN[0]), is also high indicates the EMAC generates RX interrupt to CPU
 * |        |          |If RXINTR is high but RXIEN (EMAC0_MIEN[0]) is disabled, no RX interrupt is generated.
 * |        |          |The RXINTR is logic OR result of bit logic AND result of EMAC0_MISTA[15:1] and EMAC0_MIEN[15:1]
 * |        |          |In other words, if any bit of EMAC0_MISTA[15:1] is high and its corresponding enable bit in EMAC0_MIEN[15:1] is also enabled, the RXINTR will be high.
 * |        |          |Because the RXINTR is a logic OR result, clears EMAC0_MISTA[15:1] makes RXINTR be cleared, too.
 * |        |          |0 = No status bit in EMAC0_MISTA[15:1] is set or no enable bit in EMAC0_MIEN[15:1] is enabled.
 * |        |          |1 = At least one status in EMAC0_MISTA[15:1] is set and its corresponding enable bit in EMAC0_MIEN[15:1] is enabled, too.
 * |[1]     |CRCE      |CRC Error Interrupt
 * |        |          |The CRCE high indicates the incoming packet incurred the CRC error and the packet is dropped
 * |        |          |However, if the AEP (EMAC0_MCMDR[4]) is set, the CRC error packet will be regarded as a good packet and will not be dropped.
 * |        |          |If the CRCE is high and CRCEIEN (EMAC0_MIEN[1]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the CRCE status.
 * |        |          |0 = The frame does not incur CRC error.
 * |        |          |1 = The frame incurred CRC error.
 * |[2]     |RXOV      |Receive FIFO Overflow Interrupt
 * |        |          |The RXOV high indicates the RXFIFO overflow occurred during packet reception
 * |        |          |While the RXFIFO overflow occurred, the EMAC drops the current receiving packet
 * |        |          |If the RXFIFO overflow occurred often, it is recommended that modify RXFIFO threshold control, the RXTHD of FFTCR register, to higher level.
 * |        |          |If the RXOV is high and RXOVIEN (EMAC0_MIEN[2]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the RXOV status.
 * |        |          |0 = No RXFIFO overflow occurred during packet reception.
 * |        |          |1 = RXFIFO overflow occurred during packet reception.
 * |[3]     |PTLE      |Packet Too Long Interrupt
 * |        |          |The PTLE high indicates the length of the incoming packet is greater than 1518 bytes and the incoming packet is dropped.
 * |        |          |If the PTLE is high and LPIEN(EMAC0_MIEN[3]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the PTLE status.
 * |        |          |0 = The incoming frame is not a long frame.
 * |        |          |1 = The incoming frame is a long frame.
 * |[4]     |RXGD      |Receive Good Interrupt
 * |        |          |The RXGD high indicates the frame reception has completed.
 * |        |          |If the RXGD is high and RXGDIEN (EMAC0_MIEN[4]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the RXGD status.
 * |        |          |0 = The frame reception has not complete yet.
 * |        |          |1 = The frame reception has completed.
 * |[5]     |ALIE      |Alignment Error Interrupt
 * |        |          |The ALIE high indicates the length of the incoming frame is not a multiple of byte
 * |        |          |If the ALIE is high and ALIEIEN (EMAC0_MIEN[5]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the ALIE status.
 * |        |          |0 = The frame length is a multiple of byte.
 * |        |          |1 = The frame length is not a multiple of byte.
 * |        |          |Note: ALIE detects the half-byte level alignment error, not the nibble level alignment error
 * |        |          |For the nibble level alignment error, PHY will provide RX_ER as an output and cause CRCE.
 * |[6]     |RP        |Runt Packet Interrupt
 * |        |          |The RP high indicates the length of the incoming packet is less than 64 bytes and the packet is dropped
 * |        |          |However, if the ARP (EMAC0_MCMDR[2]) is set, short packets will be treated as a good packets and will not be dropped.
 * |        |          |If the RP is high and RPIEN (EMAC0_MIEN[6]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the RP status.
 * |        |          |0 = The incoming frame is not a short frame or SOFTWARE wants to receive a short frame.
 * |        |          |1 = The incoming frame is a short frame.
 * |[7]     |MMP       |More Missed Packet Interrupt
 * |        |          |The MMP high indicates the MPCNT, Missed Packet Count, has overflow
 * |        |          |If the MMP is high and MMPIEN (EMAC0_MIEN[7]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the MMP status.
 * |        |          |0 = The MPCNT has not rolled over yet.
 * |        |          |1 = The MPCNT has rolled over yet.
 * |[8]     |DFO       |Maximum Frame Length Interrupt
 * |        |          |The DFO high indicates the length of the incoming packet has exceeded the length limitation configured in DMARFC register and the incoming packet is dropped
 * |        |          |If the DFO is high and MFLEIEN (EMAC0_MIEN[8]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the DFO status.
 * |        |          |0 = The length of the incoming packet doesn&#8223;t exceed the length limitation configured in DMARFC.
 * |        |          |1 = The length of the incoming packet has exceeded the length limitation configured in DMARFC.
 * |[9]     |DEN       |DMA Early Notification Interrupt
 * |        |          |The DEN high indicates the EMAC has received the Length/Type field of the incoming packet.
 * |        |          |If the DEN is high and DENIEN (EMAC0_MIEN[9]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the DEN status.
 * |        |          |0 = The Length/Type field of incoming packet has not received yet.
 * |        |          |1 = The Length/Type field of incoming packet has received.
 * |[10]    |RDU       |Receive Descriptor Unavailable Interrupt
 * |        |          |The RDU high indicates that there is no available RX descriptor for packet reception and RXDMA will stay at Halt state
 * |        |          |Once, the RXDMA enters the Halt state, SOFTWARE must issues a write command to RSDR register to make RXDMA leave Halt state while new RX descriptor is available.
 * |        |          |If the RDU is high and RDUIEN (EMAC0_MIEN[10]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the RDU status.
 * |        |          |0 = RX descriptor is available.
 * |        |          |1 = RX descriptor is unavailable.
 * |[11]    |RXBERR    |Receive Bus Error Interrupt
 * |        |          |The RXBERR high indicates the memory controller replies ERROR response while EMAC access system memory through RXDMA during packet reception process
 * |        |          |Reset EMAC is recommended while RXBERR status is high.
 * |        |          |If the RXBERR is high and RXBEIEN (EMAC0_MIEN[11]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the RXBERR status.
 * |        |          |0 = No ERROR response is received.
 * |        |          |1 = ERROR response is received.
 * |[14]    |CFR       |Control Frame Receive Interrupt
 * |        |          |The CFR high indicates EMAC receives a flow control frame
 * |        |          |The CFR only available while EMAC is operating on full duplex mode.
 * |        |          |If the CFR is high and CFRIEN (EMAC0_MIEN[14]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the CFR status.
 * |        |          |0 = The EMAC does not receive the flow control frame.
 * |        |          |1 = The EMAC receives a flow control frame.
 * |[15]    |MGPR      |Magic Packet Received Interrupt
 * |        |          |The MPR high indicates EMAC receives a Magic Packet
 * |        |          |The CFR only available while system is in Power-down mode and MGPWKEN is set high.
 * |        |          |If the MPR is high and WOLIEN (EMAC0_MIEN[15]) is enabled, the RXINTR will be high
 * |        |          |Write 1 to this bit clears the MPR status.
 * |        |          |0 = The EMAC does not receive the Magic Packet.
 * |        |          |1 = The EMAC receives a Magic Packet.
 * |[16]    |TXINTR    |Transmit Interrupt
 * |        |          |The TXINTR indicates the TX interrupt status.
 * |        |          |If TXINTR high and its corresponding enable bit, TXIEN (EMAC0_MIEN[16]), is also high indicates the EMAC generates TX interrupt to CPU
 * |        |          |If TXINTR is high but TXIEN (EMAC0_MIEN[16]) is disabled, no TX interrupt is generated.
 * |        |          |The TXINTR is logic OR result of bit logic AND result of EMAC0_MISTA[28:17] and EMAC0_MIEN[28:17]
 * |        |          |In other words, if any bit of EMAC0_MISTA[28:17] is high and its corresponding enable bit in EMAC0_MIEN[28:17] is also enabled, the TXINTR will be high
 * |        |          |Because the TXINTR is a logic OR result, clears EMC_MISTA[28:17] makes TXINTR be cleared, too.
 * |        |          |0 = No status bit in EMAC0_MISTA[28:17] is set or no enable bit in EMAC0_MIEN[28:17] is enabled.
 * |        |          |1 = At least one status in EMAC0_MISTA[28:17] is set and its corresponding enable bit in EMAC0_MIEN[28:17] is enabled, too.
 * |[17]    |TXEMP     |Transmit FIFO Underflow Interrupt
 * |        |          |The TXEMP high indicates the TXFIFO underflow occurred during packet transmission
 * |        |          |While the TXFIFO underflow occurred, the EMAC will retransmit the packet automatically without SOFTWARE intervention
 * |        |          |If the TXFIFO underflow occurred often, it is recommended that modify TXFIFO threshold control, the TXTHD of FFTCR register, to higher level.
 * |        |          |If the TXEMP is high and TXUDIEN (EMAC0_MIEN[17]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TXEMP status.
 * |        |          |0 = No TXFIFO underflow occurred during packet transmission.
 * |        |          |1 = TXFIFO underflow occurred during packet transmission.
 * |[18]    |TXCP      |Transmit Completion Interrupt
 * |        |          |The TXCP indicates the packet transmission has completed correctly.
 * |        |          |If the TXCP is high and TXCPIEN (EMAC0_MIEN[18]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TXCP status.
 * |        |          |0 = The packet transmission not completed.
 * |        |          |1 = The packet transmission has completed.
 * |[19]    |EXDEF     |Defer Exceed Interrupt
 * |        |          |The EXDEF high indicates the frame waiting for transmission has deferred over 0.32768ms on 100Mbps mode, or 3.2768ms on 10Mbps mode
 * |        |          |The deferral exceed check will only be done while bit NDEF of MCMDR is disabled, and EMAC is operating on half-duplex mode.
 * |        |          |If the EXDEF is high and EXDEFIEN (EMAC0_MIEN[19]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the EXDEF status.
 * |        |          |0 = Frame waiting for transmission has not deferred over 0.32768ms (100Mbps) or 3.2768ms (10Mbps).
 * |        |          |1 = Frame waiting for transmission has deferred over 0.32768ms (100Mbps) or 3.2768ms (10Mbps).
 * |[20]    |NCS       |No Carrier Sense Interrupt
 * |        |          |The NCS high indicates the MII I/F signal CRS does not active at the start of or during the packet transmission
 * |        |          |The NCS is only available while EMAC is operating on half-duplex mode
 * |        |          |If the NCS is high and NCSIEN (EMAC0_MIEN[20]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the NCS status.
 * |        |          |0 = CRS signal actives correctly.
 * |        |          |1 = CRS signal does not active at the start of or during the packet transmission.
 * |[21]    |TXABT     |Transmit Abort Interrupt
 * |        |          |The TXABT high indicates the packet incurred 16 consecutive collisions during transmission, and then the transmission process for this packet is aborted
 * |        |          |The transmission abort is only available while EMAC is operating on half-duplex mode.
 * |        |          |If the TXABT is high and TXABTIEN (EMAC0_MIEN[21]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TXABT status.
 * |        |          |0 = Packet does not incur 16 consecutive collisions during transmission.
 * |        |          |1 = Packet incurred 16 consecutive collisions during transmission.
 * |[22]    |LC        |Late Collision Interrupt
 * |        |          |The LC high indicates the collision occurred in the outside of 64 bytes collision window
 * |        |          |This means after the 64 bytes of a frame has been transmitted out to the network, the collision still occurred
 * |        |          |The late collision check will only be done while EMAC is operating on half-duplex mode
 * |        |          |If the LC is high and LCIEN (EMAC0_MIEN[22]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the LC status.
 * |        |          |0 = No collision occurred in the outside of 64 bytes collision window.
 * |        |          |1 = Collision occurred in the outside of 64 bytes collision window.
 * |[23]    |TDU       |Transmit Descriptor Unavailable Interrupt
 * |        |          |The TDU high indicates that there is no available TX descriptor for packet transmission and TXDMA will stay at Halt state
 * |        |          |Once, the TXDMA enters the Halt state, SOFTWARE must issues a write command to TSDR register to make TXDMA leave Halt state while new TX descriptor is available.
 * |        |          |If the TDU is high and TDUIEN (EMAC0_MIEN[23]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TDU status.
 * |        |          |0 = TX descriptor is available.
 * |        |          |1 = TX descriptor is unavailable.
 * |[24]    |TXBERR    |Transmit Bus Error Interrupt
 * |        |          |The TXBERR high indicates the memory controller replies ERROR response while EMAC access system memory through TXDMA during packet transmission process
 * |        |          |Reset EMAC is recommended while TXBERR status is high.
 * |        |          |If the TXBERR is high and TXBEIEN (EMAC0_MIEN[24]) is enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TXBERR status.
 * |        |          |0 = No ERROR response is received.
 * |        |          |1 = ERROR response is received.
 * |[28]    |TSALS     |Time Stamp Alarm Interrupt
 * |        |          |The TSALS high indicates the SEC (EMAC0_TSSEC[31:0]) register value equals to SECA (EMAC0_ALMSEC[31:0]) register and SUBSEC (EMAC0_TSSUBSEC[30:0]) register value equals to register SUBSECA (EMAC0_ALMSSEC[30:0]).
 * |        |          |If TSALS is high and TXALMIEN (EMAC0_MIEN[28]) enabled, the TXINTR (EMAC0_MISTA[16]) will be high
 * |        |          |Write 1 to this bit clears the TSALS status.
 * |        |          |0 = SEC (EMAC0_TSSEC[31:0]) did not equal SECA (EMAC0_ALMSEC[31:0]) or SUBSEC (EMAC0_TSSUBSEC[30:0]) did not equal SUBSECA (EMAC0_ALMSSEC[30:0]).
 * |        |          |1 = SEC (EMAC0_TSSEC[31:0]) equals SECA (EMAC0_ALMSEC[31:0]) and SUBSEC (EMAC0_TSSUBSEC[30:0]) equals SUBSECA (EMAC0_ALMSSEC[30:0]).
 * @var EMAC_T::MGSTA
 * Offset: 0xB4  EMAC0 MAC General Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |CFR       |Control Frame Received
 * |        |          |The CFR high indicates EMAC receives a flow control frame
 * |        |          |The CFR only available while EMAC is operating on full duplex mode.
 * |        |          |0 = The EMAC does not receive the flow control frame.
 * |        |          |1 = The EMAC receives a flow control frame.
 * |[1]     |RXHA      |Receive Halted
 * |        |          |The RXHA high indicates the next normal packet reception process will be halted because the bit RXON of MCMDR is disabled be SOFTWARE.
 * |        |          |0 = Next normal packet reception process will go on.
 * |        |          |1 = Next normal packet reception process will be halted.
 * |[2]     |RXFFULL   |RXFIFO Full
 * |        |          |The RXFFULL indicates the RXFIFO is full due to four packets are kept in RXFIFO and the following incoming packet will be dropped.
 * |        |          |0 = The RXFIFO is not full.
 * |        |          |1 = The RXFIFO is full and the following incoming packet will be dropped.
 * |[7:4]   |CCNT      |Collision Count
 * |        |          |The CCNT indicates that how many collisions occurred consecutively during a packet transmission
 * |        |          |If the packet incurred 16 consecutive collisions during transmission, the CCNT will be 4&#8223;h0 and bit TXABT will be set to 1.
 * |[8]     |DEF       |Deferred Transmission
 * |        |          |The DEF high indicates the packet transmission has deferred once
 * |        |          |The DEF is only available while EMAC is operating on half-duplex mode.
 * |        |          |0 = Packet transmission does not defer.
 * |        |          |1 = Packet transmission has deferred once.
 * |[9]     |PAU       |Transmission Paused
 * |        |          |The PAU high indicates the next normal packet transmission process will be paused temporally because EMAC received a PAUSE control frame.
 * |        |          |0 = Next normal packet transmission process will go on.
 * |        |          |1 = Next normal packet transmission process will be paused.
 * |[10]    |SQE       |Signal Quality Error
 * |        |          |The SQE high indicates the SQE error found at end of packet transmission on 10Mbps half-duplex mode
 * |        |          |The SQE error check will only be done while both bit EnSQE (EMAC0_MCMDR[17]) is enabled and EMAC is operating on 10Mbps half-duplex mode.
 * |        |          |0 = No SQE error found at end of packet transmission.
 * |        |          |1 = SQE error found at end of packet transmission.
 * |[11]    |TXHA      |Transmission Halted
 * |        |          |The TXHA high indicates the next normal packet transmission process will be halted because the bit TXON (EMAC0_MCMDR[8]) is disabled be SOFTWARE.
 * |        |          |0 = Next normal packet transmission process will go on.
 * |        |          |1 = Next normal packet transmission process will be halted.
 * |[12]    |RPAU      |Remote Pause Status
 * |        |          |The RPAU indicates that remote pause counter down counting actives.
 * |        |          |After Ethernet MAC controller sent PAUSE frame out successfully, it starts the remote pause counter down counting
 * |        |          |When this bit high, itu2019s predictable that remote Ethernet MAC controller wouldnu2019t start the packet transmission until the down counting done.
 * |        |          |0 = Remote pause counter down counting done.
 * |        |          |1 = Remote pause counter down counting actives.
 * @var EMAC_T::MPCNT
 * Offset: 0xB8  EMAC0 Missed Packet Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MPC       |Miss Packet Count
 * |        |          |The MPC indicates the number of packets that were dropped due to various types of receive errors
 * |        |          |The following type of receiving error makes missed packet counter increase:
 * |        |          |1. Incoming packet is incurred RXFIFO overflow.
 * |        |          |2. Incoming packet is incurred CRC error.
 * |        |          |3. Receiving packets during RXON is disabled.
 * |        |          |Note 1: Read MPC will reset the MPC counter.
 * |        |          |Note 2: when RXON is disabled, RXFIFO will retain up to 4 packets
 * |        |          |Users need to ensure that there are enough descriptors before RXON is enabled.
 * @var EMAC_T::MRPC
 * Offset: 0xBC  EMAC0 MAC Receive Pause Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |MRPC      |MAC Receive Pause Count
 * |        |          |The MRPC keeps the operand field of the PAUSE control frame
 * |        |          |It indicates how many slot time (512 bit time) the TX of EMAC will be paused.
 * @var EMAC_T::DMARFS
 * Offset: 0xC8  EMAC0 DMA Receive Frame Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[15:0]  |RXFLT     |Receive Frame Length/Type
 * |        |          |The RXFLT keeps the Length/Type field of each incoming Ethernet packet
 * |        |          |If the bit DENIEN (EMAC0_MIEN[9]) is enabled and the Length/Type field of incoming packet has received, the bit DEN (EMAC0_MISTA[9]) will be set and trigger interrupt
 * |        |          |And, the content of Length/Type field will be stored in RXFLT.
 * @var EMAC_T::CTXDSA
 * Offset: 0xCC  EMAC0 Current Transmit Descriptor Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CTXDSA    |Current Transmit Descriptor Start Address
 * |        |          |The CTXDSA keeps the start address of TX descriptor that is used by TXDMA currently
 * |        |          |The EMAC0_CTXDSA is read only and write to this register has no effect.
 * @var EMAC_T::CTXBSA
 * Offset: 0xD0  EMAC0 Current Transmit Buffer Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CTXBSA    |Current Transmit Buffer Start Address
 * |        |          |The CTXDSA keeps the start address of TX frame buffer that is used by TXDMA currently
 * |        |          |The EMAC0_CTXBSA is read only and write to this register has no effect.
 * @var EMAC_T::CRXDSA
 * Offset: 0xD4  EMAC0 Current Receive Descriptor Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CRXDSA    |Current Receive Descriptor Start Address
 * |        |          |The CRXDSA keeps the start address of RX descriptor that is used by RXDMA currently
 * |        |          |The EMAC0_CRXDSA is read only and write to this register has no effect.
 * @var EMAC_T::CRXBSA
 * Offset: 0xD8  EMAC0 Current Receive Buffer Start Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |CRXBSA    |Current Receive Buffer Start Address
 * |        |          |The CRXBSA keeps the start address of RX frame buffer that is used by RXDMA currently
 * |        |          |The EMAC0_CRXBSA is read only and write to this register has no effect.
 * @var EMAC_T::HTMR
 * Offset: 0xDC  EMAC0 Hash Table Most Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |HTM       |Hash Table Most Significant Word
 * |        |          |The HTM keeps the bit 63~32 of Hash table
 * |        |          |The register pair {EMAC0_HTMR, EMAC0_HTLR} represents the Hash table for Hash filter recognition.
 * @var EMAC_T::HTLR
 * Offset: 0xE0  EMAC0 Hash Table Least Significant Word Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |HTL       |Hash Table Least Significant Word
 * |        |          |The HTL keeps the bit 31~0 of Hash table
 * |        |          |The register pair {EMAC0_HTMR, EMAC0_HTLR} represents the Hash table for Hash filter recognition.
 * @var EMAC_T::TSCTL
 * Offset: 0x100  EMAC0 Time Stamp Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |TSEN      |Time Stamp Function Enable Bit
 * |        |          |This bit controls if the IEEE 1588 PTP time stamp function is enabled or not.
 * |        |          |Set this bit high to enable IEEE 1588 PTP time stamp function while set this bit low to disable IEEE 1588 PTP time stamp function.
 * |        |          |0 = IEEE 1588 PTP time stamp function Disabled.
 * |        |          |1 = IEEE 1588 PTP time stamp function Enabled.
 * |[1]     |TSIEN     |Time Stamp Counter Initialization Enable Bit
 * |        |          |Set this bit high enables Ethernet MAC controller to load value of register EMAC0_UPDSEC and EMAC0_UPDSSEC to PTP time stamp counter.
 * |        |          |After the load operation finished, Ethernet MAC controller clear this bit to low automatically.
 * |        |          |0 = Time stamp counter initialization done.
 * |        |          |1 = Time stamp counter initialization Enabled.
 * |[2]     |TSMODE    |Time Stamp Fine Update Enable Bit
 * |        |          |This bit chooses the time stamp counter update mode.
 * |        |          |0 = Time stamp counter is in coarse update mode.
 * |        |          |1 = Time stamp counter is in fine update mode.
 * |[3]     |TSUPDATE  |Time Stamp Counter Time Update Enable Bit
 * |        |          |Set this bit high enables Ethernet MAC controller to add value of register EMAC0_UPDSEC and EMAC0_UPDSSEC to PTP time stamp counter.
 * |        |          |After the add operation finished, Ethernet MAC controller clear this bit to low automatically.
 * |        |          |0 = No action.
 * |        |          |1 = EMAC0_UPDSEC updated to EMAC0_TSSEC and EMAC0_UPDSSEC updated to EMAC0_TSSUBSEC.
 * |[5]     |TSALMEN   |Time Stamp Alarm Enable Bit
 * |        |          |Set this bit high enable Ethernet MAC controller to set TSALS (EMAC0_MISTA[28]) high when EMAC0_TSSEC equals to EMAC0_ALMSEC and EMAC0_TSSUBSEC equals to EMAC0_ALMSSEC.
 * |        |          |0 = Alarm Disabled when EMAC0_TSSEC equals to EMAC0_ALMSEC and EMAC0_TSSUBSEC equals to EMAC0_ALMSSEC.
 * |        |          |1 = Alarm Enabled when EMAC0_TSSEC equals to EMAC0_ALMSEC and EMAC0_TSSUBSEC equals to EMAC0_ALMSSEC.
 * |[6]     |TSSNPEN   |Time Stamp Snapshot For PTP Packets Enable Bit
 * |        |          |Set this bit high would store the 63-bit reference timing value to enhanced descriptor for TX/RX PTP packets.
 * |        |          |0 = EMAC does not store the 63-bit reference timing value to enhanced descriptor for TX/RX PTP packets.
 * |        |          |1 = EMAC stores the 63-bit reference timing value to enhanced descriptor for TX/RX PTP packets.
 * |[7]     |TSSNAEN   |Time Stamp Snapshot For All Packets Enable Bit
 * |        |          |Set this bit high would store the 63-bit reference timing value to enhanced descriptor for all TX/RX packets.
 * |        |          |0 = EMAC does not store the 63-bit reference timing value to enhanced descriptor for all TX/RX packets.
 * |        |          |1 = EMAC stores the 63-bit reference timing value to enhanced descriptor for all TX/RX packets.
 * @var EMAC_T::TSSEC
 * Offset: 0x110  EMAC0 Time Stamp Counter Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SEC       |Time Stamp Counter Second
 * |        |          |This register reflects the second part of the 63-bit reference timing counter when TSEN (EMAC0_TSCTL[0]) is high.
 * @var EMAC_T::TSSUBSEC
 * Offset: 0x114  EMAC0 Time Stamp Counter Sub Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[30:0]  |SUBSEC    |Time Stamp Counter Sub-second
 * |        |          |This register reflects the nanosecond part of the 63-bit reference timing counter when TSEN (EMAC0_TSCTL[0]) is high.
 * |        |          |This register should not exceed 0x3B9A_C9FF.
 * @var EMAC_T::TSINC
 * Offset: 0x118  EMAC0 Time Stamp Increment Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |CNTINC    |Time Stamp Counter Increment
 * |        |          |Time stamp counter increment value.
 * |        |          |If TSEN (EMAC0_TSCTL[0]) is high, EMAC adds EMAC0_TSSUBSEC with this 8-bit value every time when it wants to increase the EMAC0_TSSUBSEC value.
 * @var EMAC_T::TSADDEND
 * Offset: 0x11C  EMAC0 Time Stamp Addend Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |ADDEND    |Time Stamp Counter Addend
 * |        |          |This register keeps a 32-bit value for accumulator to enable increment of EMAC0_TSSUBSEC.
 * |        |          |If TSEN (EMAC0_TSCTL[0]) and TSMODE (EMAC0_TSCTL[2]) are both high, EMAC increases accumulator with this 32-bit value in each HCLK
 * |        |          |Once the accumulator is overflow, it generates an enable to increase EMAC0_TSSUBSEC with an 8-bit value kept in register EMAC0_TSINC.
 * @var EMAC_T::UPDSEC
 * Offset: 0x120  EMAC0 Time Stamp Update Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SECU      |Time Stamp Counter Second Update
 * |        |          |When TSIEN (EMAC0_TSCTL[1]) is high
 * |        |          |EMAC loads this 32-bit value to EMAC0_TSSEC directly
 * |        |          |When TSUPDATE (EMAC0_TSCTL[3]) is high, EMAC increases EMAC0_TSSEC with this 32-bit value.
 * @var EMAC_T::UPDSSEC
 * Offset: 0x124  EMAC0 Time Stamp Update Sub Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[30:0]  |SUBSECU   |Time Stamp Counter Sub-second Update
 * |        |          |When TSIEN (EMAC0_TSCTL[1]) is high
 * |        |          |EMAC loads this 31-bit value to EMAC0_TSSUBSEC directly
 * |        |          |When TSUPDATE (EMAC0_TSCTL[3]) is high, EMAC increases EMAC0_TSSUBSEC with this 31-bit value.
 * |        |          |This register should not exceed 0x3B9A_C9FF.
 * |[31]    |ADDSUB    |Time Stamp Update Addition or Subtraction
 * |        |          |This control bit determines whether the time value is added or subtracted with the contents of the update register defined by SECU (EMAC0_UPDSEC[31:0]) and SUBSECU (EMAC0_UPDSSEC[30:0])
 * |        |          |When ADDSUB is set, the 63-bit reference timing counter is subtracted by the value in the update register
 * |        |          |Conversely, when this bit is reset, the 63-bit reference timing counter is added with the contents of the update register.
 * @var EMAC_T::ALMSEC
 * Offset: 0x128  EMAC0 Time Stamp Alarm Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |SECA      |Time Stamp Counter Second Alarm
 * |        |          |Time stamp counter second part alarm value.
 * |        |          |This value is only useful when TSALMEN (EMAC0_TSCTL[5]) high
 * |        |          |If TSALMEN (EMAC0_TSCTL[5]) is high, SEC (EMAC0_TSSEC[31:0]) equals to SECA (EMAC0_ALMSEC[31:0]) and SUBSEC (EMAC0_TSSUBSEC[30:0]) equals to SUBSECA (EMAC0_ALMSSEC[30:0]), Ethernet MAC controller set TSALS (EMAC0_MISTA[28]) high.
 * @var EMAC_T::ALMSSEC
 * Offset: 0x12C  EMAC0 Time Stamp Alarm Sub Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[30:0]  |SUBSECA   |Time Stamp Counter Sub-second Alarm
 * |        |          |Time stamp counter sub-second part alarm value.
 * |        |          |This value is only useful when TSALMEN (EMAC0_TSCTL[5]) high
 * |        |          |If TSALMEN (EMAC0_TSCTL[5]) is high, SEC (EMAC0_TSSEC[31:0]) equals to SECA (EMAC0_ALMSEC[31:0]) and SUBSEC (EMAC0_TSSUBSEC[30:0]) equals to SUBSECA (EMAC0_ALMSSEC[30:0]), Ethernet MAC controller set TSALS (EMAC0_MISTA[28]) high.
 * |        |          |This register should not exceed 0x3B9A_C9FF.
 * @var EMAC_T::PPSCTL
 * Offset: 0x130  EMAC0 PPS Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[4:0]   |PPSCTL    |Multi-mode PPS Output Control
 * |        |          |The PPSCTL controls the PPS output mode selection
 * |        |          |The following list describes the various modes and commands available:
 * |        |          |00000 = The PPS output is 1 pulse per second with a 50% duty cycle.
 * |        |          |00001 = The PPS output is 2 pulse per second with a 50% duty cycle.
 * |        |          |00010 = The PPS output is 4 pulse per second with a 50% duty cycle.
 * |        |          |00011 = The PPS output is 8 pulse per second with a 50% duty cycle.
 * |        |          |00100 = The PPS output is 16 pulse per second with a 50% duty cycle.
 * |        |          |u2026
 * |        |          |01111 = The PPS output is 32768 pulse per second with a 50% duty cycle.
 * |        |          |10000 = No Command.
 * |        |          |10001 = START Pulse Sequence.
 * |        |          |This command initiates the generation of a pulse sequence immediately, with the duration defined by EMAC0_PPSHW and EMAC0_PPSLW.
 * |        |          |10010 = START Single Pulse at Time.
 * |        |          |This command initiates the generation of a single pulse at the start time defined by EMAC0_PPSTSEC and EMAC0_PPSTSSEC, with the duration defined by EMAC0_PPSHW and EMAC0_PPSLW
 * |        |          |After generating the one single pulse, PPSCTL will revert to the 10000 u201CNo Commandu201D command.
 * |        |          |10011 = START Pulse Sequence at Time.
 * |        |          |This command initiates the generation of a pulse sequence at the start time defined by EMAC0_PPSTSEC and EMAC0_PPSTSSEC, with the duration defined by EMAC0_PPSHW and EMAC0_PPSLW
 * |        |          |After the start time, PPSCTL will stop at 10001 u201CSTART Pulse Sequenceu201D command.
 * |        |          |10100 = STOP Pulse Sequence at Time.
 * |        |          |This command stops the pulse sequence at the time defined by EMAC0_PPSTSEC and EMAC0_PPSTSSEC
 * |        |          |After the pulse sequence is stopped, PPSCTL will revert to the 10000 u201CNo Commandu201D command.
 * |        |          |10101 - 11111 = Reserved.
 * @var EMAC_T::PPSHW
 * Offset: 0x134  EMAC0 PPS High Width Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PPSHW     |PPS Output High-Level Width
 * |        |          |This register represents the duration of the high-level state of the PPS output signal
 * |        |          |It is measured in terms of the HCLK cycle counts -1 between the rising edge and the corresponding falling edge of the PPS output
 * |        |          |For example, if the HCLK frequency is 50 MHz (period of 20 ns), and desired high-level pulse width is 200 ns, then the PPSHW value should be set to 9 (10 - 1).
 * @var EMAC_T::PPSLW
 * Offset: 0x138  EMAC0 PPS Low Width Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PPSLW     |PPS Output Low-Level Width
 * |        |          |This register represents the duration of the low-level state of the PPS output signal
 * |        |          |It is measured in terms of the HCLK cycle counts -1 between the falling edge and the corresponding rising edge of the PPS output
 * |        |          |For example, if the HCLK frequency is 50 MHz (period of 20 ns), and desired low-level pulse width is 200 ns, then the PPSLW value should be set to 9 (10 - 1).
 * @var EMAC_T::PPSTSEC
 * Offset: 0x13C  EMAC0 PPS Target Time Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |PPSTSEC   |PPS Target Time Second
 * |        |          |This register stores the target time in seconds
 * |        |          |When the current timestamp value matches or exceeds the target timestamp defined by EMAC0_PPSTSEC and EMAC0_PPSTSSEC, the EMAC will initiate or stop the PPS output based on PPSCTL (EMAC0_PPSCTL[4:0]).
 * @var EMAC_T::PPSTSSEC
 * Offset: 0x140  EMAC0 PPS Target Time Sub Second Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[30:0]  |PPSTSSEC  |PPS Target Time Sub-second
 * |        |          |This register stores the target time in nanoseconds
 * |        |          |When the current timestamp value matches or exceeds the target timestamp defined by EMAC0_PPSTSEC and EMAC0_PPSTSSEC, the EMAC will initiate or stop the PPS output based on PPSCTL (EMAC0_PPSCTL[4:0]).
 * |        |          |This register should not exceed 0x3B9A_C9FF
 * |        |          |The actual start or stop time of the PPS output may have an error margin up to one unit of CNTINC (EMAC0_TSINC).
 */
    __IO uint32_t CAMCMR;
    __IO uint32_t CAMEN;
    __IO uint32_t CAMxML[16][2];
    __IO uint32_t TXDLSA;
    __IO uint32_t RXDLSA;
    __IO uint32_t MCMDR;
    __IO uint32_t MIID;
    __IO uint32_t MIIDA;
    __IO uint32_t FFTCR;
    __IO uint32_t TSDR;
    __IO uint32_t RSDR;
    __IO uint32_t DMARFC;
    __IO uint32_t MIEN;
    __IO uint32_t MISTA;
    __IO uint32_t MGSTA;
    __IO uint32_t MPCNT;
    __IO uint32_t MRPC;
    __I  uint32_t RESERVE0[2];
    __IO uint32_t DMARFS;
    __IO uint32_t CTXDSA;
    __IO uint32_t CTXBSA;
    __IO uint32_t CRXDSA;
    __IO uint32_t CRXBSA;
    __IO uint32_t HTMR;
    __IO uint32_t HTLR;
    __I  uint32_t RESERVE1[7];
    __IO uint32_t TSCTL;
    __I  uint32_t RESERVE2[3];
    __IO uint32_t TSSEC;
    __IO uint32_t TSSUBSEC;
    __IO uint32_t TSINC;
    __IO uint32_t TSADDEND;
    __IO uint32_t TSUPDSEC;
    __IO uint32_t TSUPDSUBSEC;
    __IO uint32_t TSALMSEC;
    __IO uint32_t TSALMSUBSEC;
    __IO uint32_t PPSCTL;
    __IO uint32_t PPSHW;
    __IO uint32_t PPSLW;
    __IO uint32_t PPSTSEC;
    __IO uint32_t PPSTSSEC;
} EMAC_T;

/**
    @addtogroup EMAC_CONST EMAC Bit Field Definition
    Constant Definitions for EMAC Controller
@{ */

#define CAMCMR_AHMP         0x00000200
#define CAMCMR_AHUP         0x00000100
#define CAMCMR_ECMP         0x00000010
#define CAMCMR_CCAM         0x00000008 // 1: Complement compare, 0: Direct compare
#define CAMCMR_ABP          0x00000004
#define CAMCMR_AMP          0x00000002
#define CAMCMR_AUP          0x00000001

#define CAMEN_EN_MASK       0x0000FFFF

#define CAMxM_MASK          0xFFFFFFFF

#define CAMxL_MASK          0xFFFF0000

#define CAM15M_LENTYPE_POS          16
#define CAM15M_LENTYPE_MASK 0xFFFF0000
#define CAM15M_OPCODE_POS            0
#define CAM15M_OPCODE_MASK  0x0000FFFF

#define CAM15L_OPERAND_POS          24
#define CAM15L_OPERAND_MASK 0xFF000000

#define MCMDR_SWR           0x01000000
#define MCMDR_LPB           0x00200000
#define MCMDR_OPMOD         0x00100000 // 1: 100Mbps, 0: 10Mbps
#define MCMDR_FDUP          0x00040000 // 1: Full duplex, 0: Half duplex
#define MCMDR_SQECHKEN      0x00020000
#define MCMDR_SDPZ          0x00010000
#define MCMDR_RTIOEN        0x00000800
#define MCMDR_NDEF          0x00000200
#define MCMDR_TXON          0x00000100
#define MCMDR_PTP_SRC       0x00000080
#define MCMDR_MGP_WAKE      0x00000040
#define MCMDR_SPCRC         0x00000020
#define MCMDR_AEP           0x00000010
#define MCMDR_ACP           0x00000008
#define MCMDR_ARP           0x00000004
#define MCMDR_ALP           0x00000002
#define MCMDR_RXON          0x00000001

#define MIID_DATA_MASK      0x0000FFFF

#define MIIDA_MDCON         0x00080000
#define MIIDA_PREAMSP       0x00040000
#define MIIDA_BUSY          0x00020000
#define MIIDA_WRITE         0x00010000
#define MIIDA_PHYAD_MASK    0x00001F00
#define MIIDA_PHYAD_POS              8
#define MIIDA_PHYRAD_MASK   0x0000001F
#define MIIDA_PHYRAD_POS             0

#define FFTCR_BURSTLEN_MASK 0x00300000
#define FFTCR_BURSTLEN_POS          20
#define BURSTLEN_4WORD      (0 << FFTCR_BURSTLEN_POS)
#define BURSTLEN_8WORD      (1 << FFTCR_BURSTLEN_POS)
#define BURSTLEN_16WORD     (2 << FFTCR_BURSTLEN_POS)
/* 3 is also 16 words */
#define FFTCR_TXTHD_MASK    0x00000300
#define FFTCR_TXTHD_POS              8
#define TXTHD_NONE          (0 << FFTCR_TXTHD_POS) /* low 32, high 64 bytes */
#define TXTHD_64BYTE        (1 << FFTCR_TXTHD_POS) /* low 64, high 128 bytes */
#define TXTHD_80BYTE        (2 << FFTCR_TXTHD_POS) /* low 80, high 160 bytes */
#define TXTHD_96BYTE        (3 << FFTCR_TXTHD_POS) /* low 96, high 192 bytes */
#define FFTCR_RXTHD_MASK    0x00000003
#define FFTCR_RXTHD_POS              0
#define RXTHD_NONE                   0
#define RXTHD_32BYTE                 1 /* high 64 bytes, low 32 */
#define RXTHD_64BYTE                 2 /* high 128 bytes, low 64 */
#define RXTHD_96BYTE                 3 /* high 192 bytes, low 96 */

#define DMARFC_RXMS_MASK    0x0000FFFF

#define MIEN_TSALMIEN       0x10000000
#define MIEN_TXBEIEN        0x01000000
#define MIEN_TDUIEN         0x00800000
#define MIEN_LCIEN          0x00400000
#define MIEN_TXABTIEN       0x00200000
#define MIEN_NCSIEN         0x00100000
#define MIEN_EXDEFIEN       0x00080000
#define MIEN_TXCPIEN        0x00040000
#define MIEN_TXUDIEN        0x00020000
#define MIEN_TXIEN          0x00010000
#define MIEN_WOLIEN         0x00008000
#define MIEN_CFRIEN         0x00004000
#define MIEN_RXBEIEN        0x00000800
#define MIEN_RDUIEN         0x00000400
#define MIEN_DENIEN         0x00000200
#define MIEN_MFLEIEN        0x00000100
#define MIEN_MMPIEN         0x00000080
#define MIEN_RPIEN          0x00000040
#define MIEN_ALIEIEN        0x00000020
#define MIEN_RXGDIEN        0x00000010
#define MIEN_LPIEN          0x00000008
#define MIEN_RXOVIEN        0x00000004
#define MIEN_CRCEIEN        0x00000002
#define MIEN_RXIEN          0x00000001

#define MISTA_TSALS         0x10000000
#define MISTA_TXBERR        0x01000000
#define MISTA_TDU           0x00800000
#define MISTA_LC            0x00400000
#define MISTA_TXABT         0x00200000
#define MISTA_NCS           0x00100000
#define MISTA_EXDEF         0x00080000
#define MISTA_TXCP          0x00040000
#define MISTA_TXEMP         0x00020000
#define MISTA_TXINTR        0x00010000
#define MISTA_TX_MASK       0xFFFF0000
#define MISTA_MGPR          0x00008000
#define MISTA_CFR           0x00004000
#define MISTA_RXBERR        0x00000800
#define MISTA_RDU           0x00000400
#define MISTA_DEN           0x00000200
#define MISTA_DFO           0x00000100
#define MISTA_MMP           0x00000080
#define MISTA_RP            0x00000040
#define MISTA_ALIE          0x00000020
#define MISTA_RXGD          0x00000010
#define MISTA_PTLE          0x00000008
#define MISTA_RXOV          0x00000004
#define MISTA_CRCE          0x00000002
#define MISTA_RXINTR        0x00000001
#define MISTA_RX_MASK       0x0000FFFF

#define MGSTA_RPAU          0x00001000
#define MGSTA_TXHA          0x00000800
#define MGSTA_SQE           0x00000400
#define MGSTA_PAU           0x00000200
#define MGSTA_DEF           0x00000100
#define MGSTA_CCNT_MASK     0x000000F0
#define MGSTA_CCNT_POS               4
#define MGSTA_RXFFULL       0x00000004
#define MGSTA_RXHA          0x00000002
#define MGSTA_CFR           0x00000001
#define MGSTA_MASK          0x00000FFF

#define MPCNT_MPC_MASK      0x0000FFFF

#define MRPC_MASK           0x0000FFFF

#define DMARFS_RXFLT_MASK   0x0000FFFF

#define TSCTL_TSSNAEN       0x00000080
#define TSCTL_TSSNPEN       0x00000040
#define TSCTL_TSALMEN       0x00000020
#define TSCTL_TSUPDATE      0x00000008
#define TSCTL_TSMODE        0x00000004
#define TSCTL_TSIEN         0x00000002
#define TSCTL_TSEN          0x00000001

#define TSSSEC_ADDSUB_MASK  0x80000000
#define TSSUBSEC_MASK       0x7FFFFFFF

#define TSINC_CNTINC_MASK    0x000000FF

#define PPSCTL_MASK         0x0000001F

/* -------------------------------- */

/**@}*/ /* EMAC_CONST */
/**@}*/ /* end of EMAC register group */


/**@}*/ /* end of REGISTER group */

#ifdef __cplusplus
}
#endif

#endif


/*** (C) COPYRIGHT 2025 Nuvoton Technology Corp. ***/

/**************************************************************************//**
 * @file     NFI_reg.h
 * @brief    NFI register definition header file
 *
 * SPDX-License-Identifier: Apache-2.0
 * @copyright (C) 2025 Nuvoton Technology Corp. All rights reserved.
 *****************************************************************************/
#ifndef __NFI_REG_H__
#define __NFI_REG_H__

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif

/******************************************************************************/
/*                Device Specific Peripheral registers structures             */
/******************************************************************************/

/** @addtogroup REGISTER Control Register

  @{

*/


/*---------------------- NAND Flash Interface -------------------------*/
/**
    @addtogroup NFI NAND Flash Interface(NFI)
    Memory Mapped Structure for NFI Controller
@{ */

typedef struct
{


/**
 * @var NFI_T::BUFFER
 * Offset: 0x00  NFI Embedded Buffer Word n
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |Data      |NFI Embedded Buffer Word n
 * |        |          |This field indicates a 32-bit data of NAND Flash controller embedded buffer.
 * @var NFI_T::DMACTL
 * Offset: 0x400  NFI DMA Control and Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |DMACEN    |DMA Controller Engine Enable Bit
 * |        |          |0 = DMA Controller Disabled.
 * |        |          |1 = DMA Controller Enabled.
 * |        |          |Note 1: If this bit is cleared, DMA will ignore all requests from NAND Flash and force bus master into IDLE state.
 * |        |          |Note 2: If target abort occurred, DMACEN will be cleared.
 * |[1]     |DMARST    |Software Engine Reset
 * |        |          |0 = No effect.
 * |        |          |1 = Reset internal state machine and pointers
 * |        |          |The contents of control register will not be cleared
 * |        |          |This bit will be auto cleared after a few clock cycles.
 * |        |          |Note: The software reset DMA related registers.
 * |[3]     |SGEN      |Scatter-gather Function for NFI Enable Bit
 * |        |          |0 = Scatter-gather function Disabled (DMA will treat the starting address in DMASA as starting pointer of a single block memory).
 * |        |          |1 = Scatter-gather function Enabled (DMA will treat the starting address in DMASA as a starting address of Physical Address Descriptor (PAD) table
 * |        |          |The format of these Padsu2019 will be described later).
 * |[9]     |DMABUSY   |NFI DMA Transfer in Progress
 * |        |          |This bit indicates if NFI is granted and doing DMA transfer or not.
 * |        |          |0 = NFI DMA transfer is not in progress.
 * |        |          |1 = NFI DMA transfer is in progress.
 * @var NFI_T::DMASA
 * Offset: 0x408  NFI DMA Transfer Starting Address Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |ORDER     |Determined to the PAD Table Fetching Is in Order or Out of Order
 * |        |          |0 = PAD table is fetched in order.
 * |        |          |1 = PAD table is fetched out of order.
 * |        |          |Note: The bit 0 is valid in scatter-gather mode when SGEN (NFI_DMACTL[3]) = 1.
 * |[31:1]  |DMASA     |DMA Transfer Starting Address
 * |        |          |This field pads 0 as least significant bit indicates a 32-bit starting address of system memory (SRAM) for DMA to retrieve or fill in data.
 * |        |          |If DMA is not in normal mode, this field will be interpreted as a starting address of Physical Address Descriptor (PAD) table.
 * |        |          |Note: Starting address of the SRAM must be word aligned, for example, 0x0000_0000, 0x0000_0004.
 * @var NFI_T::DMABCNT
 * Offset: 0x40C  NFI DMA Transfer Byte Count Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[19:0]  |BCNT      |DMA Transfer Byte Count (Read Only)
 * |        |          |This field indicates the remained byte count of DMA transfer
 * |        |          |The value of this field is valid only when NFI is busy; otherwise, it is zero.
 * @var NFI_T::DMAINTEN
 * Offset: 0x410  NFI DMA Interrupt Enable Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |ABORTIEN  |DMA Read/Write Target Abort Interrupt Enable Bit
 * |        |          |0 = Target abort interrupt generation Disabled during DMA transfer.
 * |        |          |1 = Target abort interrupt generation Enabled during DMA transfer.
 * |[1]     |WEOTIEN   |Wrong EOT Encountered Interrupt Enable Bit
 * |        |          |0 = Interrupt generation Disabled when wrong EOT (end of transfer) is encountered.
 * |        |          |1 = Interrupt generation Enabled when wrong EOT (end of transfer) is encountered.
 * @var NFI_T::DMAINTSTS
 * Offset: 0x414  NFI DMA Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |ABORTIF   |DMA Read/Write Target Abort Interrupt Flag (Read Only)
 * |        |          |0 = No bus ERROR response received.
 * |        |          |1 = Bus ERROR response received.
 * |        |          |Note 1: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * |        |          |Note 2: When DMAu2019s bus master received ERROR response, it means that target abort happened
 * |        |          |DMA will stop transfer and respond this event by set ABORTIF high
 * |        |          |Then, NFI go to IDLE state
 * |        |          |When target abort occurred or WEOTIF is set, it is necessary to reset NFIu2019s DMA and then transfer those data again.
 * |[1]     |WEOTIF    |Wrong EOT Encountered Interrupt Flag (Read Only)
 * |        |          |When DMA Scatter-Gather function is enabled, and EOT of the descriptor is encountered before DMA transfer finished (that means the total sector count of all PAD is less than the sector count of NFI), this bit will be set.
 * |        |          |0 = No EOT encountered before DMA transfer finished.
 * |        |          |1 = EOT encountered before DMA transfer finished.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * @var NFI_T::GCTL
 * Offset: 0x800  NFI Global Control and Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |GCTLRST   |Software Engine Reset
 * |        |          |0 = No effect.
 * |        |          |1 = Reset all NFI engines.
 * |        |          |Note: The contents of control register will not be cleared
 * |        |          |This bit will auto cleared after a few clock cycles.
 * |[3]     |NANDEN    |NAND Flash Functionality Enable Bit
 * |        |          |0 = NAND Flash functionality of NFI Disabled.
 * |        |          |1 = NAND Flash functionality of NFI Enabled.
 * @var NFI_T::GINTEN
 * Offset: 0x804  NFI Global Interrupt Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |DTAIEN    |DMA READ/WRITE Target Abort Interrupt Enable Bit
 * |        |          |0 = DMA READ/WRITE target abort interrupt generation Disabled.
 * |        |          |1 = DMA READ/WRITE target abort interrupt generation Enabled.
 * @var NFI_T::GINTSTS
 * Offset: 0x808  NFI Global Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |DTAIF     |DMA READ/WRITE Target Abort Interrupt Flag (Read Only)
 * |        |          |This bit indicates DMA received an ERROR response from internal AHB bus during DMA read/write operation
 * |        |          |When Target Abort occurred, please reset all engines.
 * |        |          |0 = No bus ERROR response received.
 * |        |          |1 = Bus ERROR response received.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * @var NFI_T::NANDCTL
 * Offset: 0x8A0  NAND Flash Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |SWRST     |Software Engine Reset
 * |        |          |0 = No effect.
 * |        |          |1 = Reset the internal state machine and counters (include DWREN (NFI_NANDCTL[2]) and DRDEN (NFI_NANDCTL[1])).
 * |        |          |Note: The contents of control register will not be cleared
 * |        |          |This bit will be auto cleared after a few clock cycles.
 * |[1]     |DRDEN     |DMA Read Data Enable Bit
 * |        |          |This bit enables NAND controller to transfer data (1 page) from NAND Flash or NAND type Flash into DMACu2019s embedded frame buffer.
 * |        |          |0 = No effect.
 * |        |          |1 = DMA read data transfer Enabled.
 * |        |          |Note: When DMA transfer completed, this bit will be cleared automatically.
 * |[2]     |DWREN     |DMA Write Data Enable Bit
 * |        |          |This bit enables NAND controller to transfer data (1 page) from DMACu2019s embedded frame buffer into NAND Flash or NAND type Flash.
 * |        |          |0 = No effect.
 * |        |          |1 = DMA write data transfer Enabled.
 * |        |          |Note: When DMA transfer completed, this bit will be cleared automatically.
 * |[3]     |REDUNREN  |Redundant Area Read Enable Bit
 * |        |          |This bit enables NAND controller to transfer redundant data from NAND Flash into NFI_NANDRA, the data size is dependent on NFI_NANDRACTL register.
 * |        |          |0 = No effect.
 * |        |          |1 = Read redundant data transfer Enabled.
 * |        |          |Note: When transfer completed, this bit will be cleared automatically.
 * |[4]     |REDUNAUTOWEN|Redundant Area Auto Write Enable Bit
 * |        |          |This field is used to auto write redundant data out to NAND Flash
 * |        |          |The redundant data area is dependent on NFI_NANDRACTL register.
 * |        |          |0 = Auto write redundant data out to NAND Flash Disabled.
 * |        |          |1 = Auto write redundant data out to NAND Flash Enabled.
 * |[7]     |ECCCHK    |None Used Field ECC Check After Read Page Data
 * |        |          |0 = ECC check Disabled
 * |        |          |The NAND controller will always check ECC result for each field, no matter it is used or not.
 * |        |          |1 = ECC check Enabled
 * |        |          |The NAND controller will check 1u2019s count for byte 2, 3 of redundant data of the ECC in each field
 * |        |          |If the count value is greater than 8, the NAND controller will treat this field as none used field; otherwise, it is used
 * |        |          |If that field is none used field, the NAND controller will ignore its ECC check result.
 * |[8]     |PROT3BEN  |Protect_3Byte Software Data Enable Bit
 * |        |          |The ECC algorithm only protects data area and hardware ECC parity code
 * |        |          |User can choose to protect software redundant data first 3 bytes by setting this bit high.
 * |        |          |0 = Software redundant data is not protected by ECC algorithm.
 * |        |          |1 = Software redundant data first 3 bytes protected by ECC algorithm.
 * |[9]     |SRAMINT   |SRAM Initial
 * |        |          |0 = No effect.
 * |        |          |1 = Reset the internal NFI_NANDRA0~NFI_NANDRA1 to 0xFFFF_FFFF.
 * |        |          |Note: The contents of control register will not be cleared
 * |        |          |This bit will be auto cleared after a few clock cycles.
 * |[17:16] |PSIZE     |Page Size of NAND
 * |        |          |This bit indicates the page size of NAND
 * |        |          |There are four page sizes for choose, 512 bytes/page, 2048 bytes/page, 4096 bytes/page and 8192 bytes/page
 * |        |          |Before setting PSIZE register, user must set BCHTSEL register at first.
 * |        |          |00 = Page size is 512 bytes/page.
 * |        |          |01 = Page size is 2048 bytes/page.
 * |        |          |10 = Page size is 4096 bytes/page.
 * |        |          |11 = Page size is 8192 bytes/page.
 * |[22:18] |BCHTSEL   |BCH Correct Bit Selection
 * |        |          |This field is used to select BCH correct bits for data protecting
 * |        |          |For BCH algorithm, T can be 4 or 8 or 12 or 15 or 24 for choosing (correct 4 or 8 or 12 or 15 or 24 bits).
 * |        |          |00001 = Using BCH T24 to encode/decode (T24).(.1024 Bytes per block)
 * |        |          |00010 = Using BCH T4 to encode/decode (T4).
 * |        |          |00100 = Using BCH T8 to encode/decode (T8).
 * |        |          |01000 = Using BCH T12 to encode/decode (T12).
 * |        |          |10000 = Using BCH T15 to encode/decode (T15).
 * |[23]    |ECCEN     |ECC Algorithm Enable Bit
 * |        |          |This field is used to select the ECC algorithm for data protecting
 * |        |          |The BCH algorithm can correct 4 or 8 or 12 or 15 or 24 bits.
 * |        |          |0 = BCH code encode/decode Disabled.
 * |        |          |1 = BCH code encode/decode Enabled.
 * |        |          |Note 1: If disabling ECCEN and when reading data from NAND, the NAND controller will ignore its ECC check result
 * |        |          |When writing data to NAND, the NAND controller will write out 0xFF to every parity field.
 * |        |          |Note 2: The ECC algorithm only protects data area and hardware ECC parity code by default
 * |        |          |By setting PROT3BEN (NFI_NANDCTL[8]) high, the first 3 bytes of redundant data are also protected by ECC algorithm.
 * |[25]    |CS0       |NAND Flash Chip Select 0 Enable Bit
 * |        |          |0 = Chip select 0 Enabled.
 * |        |          |1 = Chip select 0 Disabled.
 * @var NFI_T::NANDTMCTL
 * Offset: 0x8A4  NAND Flash Timing Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |LOWID     |Read/Write Enable Signal Low Pulse Width
 * |        |          |This field controls the low pulse width of signals u2013RE and u2013WE while HARDWARE mode page access is enabled
 * |        |          |The pulse width is a multiple of period of AHB bus clock
 * |        |          |( The actual width time will be [clock period*(LOWID+1)] )
 * |[15:8]  |HIWID     |Read/Write Enable Signal High Pulse Width
 * |        |          |This field controls the high pulse width of signals u2013RE and u2013WE while HARDWARE mode page access is enabled
 * |        |          |The pulse width is a multiple of period of AHB bus clock
 * |        |          |( The actual width time will be [clock period*(HIWID+1)] )
 * |[22:16] |CALESH    |CLE/ALE Setup/Hold Time
 * |        |          |This field controls the CLE/ALE setup/hold time to u2013WE.
 * |        |          |The setup/hold time can be calculated using following equation:
 * |        |          |tCLS = (CALESH+1)*TAHB.
 * |        |          |tCLH = ((CALESH*2)+2)*TAHB.
 * |        |          |tALS = (CALESH+1)*TAHB.
 * |        |          |tALH = ((CALESH*2)+2)*TAHB.
 * |[27:24] |EDOD      |EDO Mode Delay Time
 * |        |          |Control this field to delay sampling point when NAND Flash enters EDO mode only.
 * |        |          |The EDO mode delay time can be calculated using following equation:
 * |        |          |Delay time = (EDOD+1)*(TAHB/2).
 * |[31]    |EDOEN     |EDO Mode Enable Bit
 * |        |          |This bit specifies NAND Flash to EDO mode
 * |        |          |Before trigger this bit, software should fill EDOD(NFI_NANDTMCTL[27:24]), CALESH(NFI_NANDTMCTL[22:16]), HIWID(NFI_NANDTMCTL[15:8]) and LOWID(NFI_NANDTMCTL[7:0]).
 * |        |          |0 = EDO Mode related function Disabled.
 * |        |          |1 = EDO Mode related function Enabled.
 * |        |          |Note: Only NAND Flash entering EDO mode should set this bit.
 * @var NFI_T::NANDINTEN
 * Offset: 0x8A8  NAND Flash Interrupt Enable Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |DMAIE     |DMA Read/Write Data Complete Interrupt Enable Bit
 * |        |          |0 = DMA read/write data complete interrupt generation Disabled.
 * |        |          |1 = DMA read/write data complete interrupt generation Enabled.
 * |[2]     |ECCFLDIE  |ECC Field Check Error Interrupt Enable Bit
 * |        |          |This bit can check the ECC error on each field (512bytes) of data transfer
 * |        |          |Enable this bit to detect error and do error correction.
 * |        |          |0 = ECC field check error Disabled.
 * |        |          |1 = ECC field check error Enabled.
 * |[10]    |RB0IE     |Ready/-Busy 0 Rising Edge Detect Interrupt Enable Bit
 * |        |          |0 = R/-B rising edge detect interrupt generation Disabled.
 * |        |          |1 = R/-B rising edge detect interrupt generation Enabled.
 * @var NFI_T::NANDINTSTS
 * Offset: 0x8AC  NAND Flash Interrupt Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |DMAIF     |DMA Read/Write Data Complete Interrupt Flag (Read Only)
 * |        |          |0 = DMA read/write transfer is not finished yet.
 * |        |          |1 = DMA read/write transfer is done.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * |[2]     |ECCFLDIF  |ECC Field Check Error Interrupt Flag (Read Only)
 * |        |          |This bit can check the ECC error on each field (512bytes) of data transfer
 * |        |          |Read this bit to check if the error occurred.
 * |        |          |0 = No occurrence of ECC error.
 * |        |          |1 = Occurrence of ECC error.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * |[4]     |EDOF      |EDO Mode Entrance Flag (Read Only)
 * |        |          |0 = NAND Flash did not enter EDO mode.
 * |        |          |1 = NAND Flash entered EDO mode.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * |[10]    |RB0IF     |Ready/-Busy 0 Rising Edge Detect Interrupt Flag (Read Only)
 * |        |          |0 = R/-B rising edge is not detected.
 * |        |          |1 = R/-B rising edge is detected.
 * |        |          |Note: This bit is read only, but can be cleared by writing u20181u2019 to it.
 * |[18]    |RB0Status |Ready/-Busy 0 Pin Status (Read Only)
 * |        |          |This bit reflects the Ready/-Busy pin status of NAND Flash.
 * @var NFI_T::NANDCMD
 * Offset: 0x8B0  NAND Flash Command Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |COMMAND   |NAND Flash Command Port
 * |        |          |When CPU writes to this port, NFI will send a command to NAND Flash.
 * @var NFI_T::NANDADDR
 * Offset: 0x8B4  NAND Flash Address Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |ADDRESS   |NAND Flash Address Port
 * |        |          |By writing this port, NAND Flash control will send an address to NAND Flash.
 * |[31]    |EOA       |End of Address
 * |        |          |Write this bit to indicate if this address is the last one or not
 * |        |          |By writing address port with this bit low, the NAND Flash controller will set ALE pin to active (HIGH)
 * |        |          |After the last address is written (with this bit set high), the NAND Flash controller will set ALE pin to inactive (LOW).
 * |        |          |0 = Not the last address cycle.
 * |        |          |1 = The last one address cycle.
 * @var NFI_T::NANDDATA
 * Offset: 0x8B8  NAND Flash Data Port Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |DATA      |NAND Flash Data Port
 * |        |          |CPU can access NANDu2019s memory array through this data port
 * |        |          |When CPU WRITE, the lower 8-bit data from CPU will appear on the data bus of NAND controller
 * |        |          |When CPU READ, NAND controller will get 8-bit data from data bus.
 * @var NFI_T::NANDRACTL
 * Offset: 0x8BC  NAND Flash Redundant Area Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[8:0]   |RA128EN   |Redundant Area 128 Byte Enable Bit
 * |        |          |These bits indicate NAND Flash extended redundant area.
 * |        |          |If PSIZE (NFI_NANDCTL[17:16]) = 2u2019b00, this field will be set 0x10 (16 bytes) automatically.
 * |        |          |If PSIZE (NFI_NANDCTL[17:16]) = 2u2019b01, this field will be set 0x40 (64 bytes) automatically.
 * |        |          |If PSIZE (NFI_NANDCTL[17:16]) = 2u2019b10, this field will be set 0x80 (128 bytes) automatically.
 * |        |          |If PSIZE (NFI_NANDCTL[17:16]) = 2u2019b11, this field will be set 0x100 (256 bytes) automatically.
 * |        |          |Note: The REA128EN must be 4 byte aligned, so bit1 and bit0 canu2019t be filled 1 to it.
 * |        |          |The maximum redundant area of the controller is 472 bytes.
 * |[31:16] |MECC      |Mask ECC During Write Page Data
 * |        |          |These 16 bits registers indicate NAND controller to write out ECC parity or just 0xFF for each field (every 512 bytes) the real parity data will be write out to NFI_NANDRAx.
 * |        |          |0x00 = Do not mask the ECC parity for each field.
 * |        |          |0x01 = Mask ECC parity and write out FF to NAND ECC parity for 512 Bytes page size or 2K/4K/8K page size first 512 field.
 * |        |          |0x02 = Mask ECC parity and write out FF to NAND ECC parity for 512 Bytes page size or 2K/4K/8K page size second 512 field.
 * |        |          |Others = Mask ECC parity and write out FF to NAND ECC parity for 512 Bytes page size or 2K/4K/8K page size each 512 field.
 * @var NFI_T::NANDECTL
 * Offset: 0x8C0  NAND Flash Extend Control Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[0]     |WP        |NAND Flash Write Protect Control
 * |        |          |Set this bit low (low active) to make NAND_nWP functional pin low to prevent the write to NAND Flash device.
 * |        |          |0 = NAND Flash is write-protected and is not writeable.
 * |        |          |1 = NAND Flash is not write-protected and is writeable.
 * @var NFI_T::NANDECCES
 * Offset: 0x8D0  NAND Flash ECC Error Status Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[1:0]   |F1STAT    |ECC Status of Field 1
 * |        |          |This field contains the ECC correction status (BCH algorithm) of ECC-field 1.
 * |        |          |00 = No error.
 * |        |          |01 = Correctable error.
 * |        |          |10 = Uncorrectable error.
 * |        |          |11 = Reserved.
 * |[6:2]   |F1ECNT    |Error Count of ECC Field 1
 * |        |          |This field contains the error counts after ECC correct calculation of Field 1
 * |        |          |For this ECC core (BCH algorithm), only when F1STAT equals to 0x01, the value in this field is meaningful
 * |        |          |F1ECNT means how many errors depending on which ECC is used.
 * |[9:8]   |F2STAT    |ECC Status of Field 2
 * |        |          |This field contains the ECC correction status (BCH algorithm) of ECC-field 2.
 * |        |          |00 = No error.
 * |        |          |01 = Correctable error.
 * |        |          |10 = Uncorrectable error.
 * |        |          |11 = Reserved.
 * |[14:10] |F2ECNT    |Error Count of ECC Field 2
 * |        |          |This field contains the error counts after ECC correct calculation of Field 2
 * |        |          |For this ECC core (BCH algorithm), only when F2STAT equals to 0x01, the value in this field is meaningful
 * |        |          |F2ECNT means how many errors depending on which ECC is used.
 * |[17:16] |F3STAT    |ECC Status of Field 3
 * |        |          |This field contains the ECC correction status (BCH algorithm) of ECC-field 3.
 * |        |          |00 = No error.
 * |        |          |01 = Correctable error.
 * |        |          |10 = Uncorrectable error.
 * |        |          |11 = Reserved.
 * |[22:18] |F3ECNT    |Error Count of ECC Field 3
 * |        |          |This field contains the error counts after ECC correct calculation of Field 3
 * |        |          |For this ECC core (BCH algorithm), only when F3STAT equals to 0x01, the value in this field is meaningful
 * |        |          |F3ECNT means how many errors depending on which ECC is used.
 * |[25:24] |F4STAT    |ECC Status of Field 4
 * |        |          |This field contains the ECC correction status (BCH algorithm) of ECC-field 4.
 * |        |          |00 = No error.
 * |        |          |01 = Correctable error.
 * |        |          |10 = Uncorrectable error.
 * |        |          |11 = Reserved.
 * |[30:26] |F4ECNT    |Error Count of ECC Field 4
 * |        |          |This field contains the error counts after ECC correct calculation of Field 4
 * |        |          |For this ECC core (BCH algorithm), only when F4STAT equals to 0x01, the value in this field is meaningful
 * |        |          |F4ECNT means how many errors depending on which ECC is used.
 * @var NFI_T::NANDECCEA
 * Offset: 0x900  NAND Flash ECC Error Byte Address 0 Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[10:0]  |ERRADDR0  |ECC Error Address First Field of Error 0
 * |        |          |This field contains an 11-bit ECC error address 0 of first field
 * |        |          |If it is a correctable error, please read the error data, ERRDATA0 (NFI_NANDECCED0[7:0]), to correct this error.
 * |[26:16] |ERRADDR1  |ECC Error Address First Field of Error 1
 * |        |          |This field contains an 11-bit ECC error address 1 of first field
 * |        |          |If it is a correctable error, please read the error data, ERRDATA1 (NFI_NANDECCED0[15:8]), to correct this error.
 * @var NFI_T::NANDECCED
 * Offset: 0x960  NAND Flash ECC Error Data Register
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[7:0]   |ERRDATA0  |ECC Error Data of First Field 0
 * |        |          |This field contains an 8-bit BCH ECC error data 0 of first field
 * |        |          |If it is a correctable error, please read out the error data in this field and doing bitwise XOR with received data locating at address ERRADDR0 (NFI_ANNDECCEA0[10:0]), and then the result will be the correct data.
 * |[15:8]  |ERRDATA1  |ECC Error Data of First Field 1
 * |        |          |This field contains an 8-bit BCH ECC error data 1 of first field
 * |        |          |If it is a correctable error, please read out the error data in this field and doing bitwise XOR with received data locating at address ERRADDR1 (NFI_NANDECCEA0[26:16]), and then the result will be the correct data.
 * |[23:16] |ERRDATA2  |ECC Error Data of First Field 2
 * |        |          |This field contains an 8-bit BCH ECC error data 2 of first field
 * |        |          |If it is a correctable error, please read out the error data in this field and doing bitwise XOR with received data locating at address ERRADDR2 (NFI_NANDECCEA1[10:0]), and then the result will be the correct data.
 * |[31:24] |ERRDATA3  |ECC Error Data of First Field 3
 * |        |          |This field contains an 8-bit BCH ECC error data 3 of first field
 * |        |          |If it is a correctable error, please read out the error data in this field and doing bitwise XOR with received data locating at address ERRADDR3 (NFI_NANDECCEA1[26:16]), and then the result will be the correct data.
 * @var NFI_T::NANDRA
 * Offset: 0xA00  NAND Flash Redundant Area Word n
 * ---------------------------------------------------------------------------------------------------
 * |Bits    |Field     |Descriptions
 * | :----: | :----:   | :---- |
 * |[31:0]  |Data      |NAND Flash Redundant Area Word n
 * |        |          |This field indicates a 32-bit data of redundant area.
 */
    __IO uint32_t BUFFER[32];            /*!< [0x0000] NFI Embedded Buffer Word n                                       */
    __I  uint32_t RESERVE0[224];
    __IO uint32_t DMACTL;                /*!< [0x0400] NFI DMA Control and Status Register                              */
    __I  uint32_t RESERVE1[1];
    __IO uint32_t DMASA;                 /*!< [0x0408] NFI DMA Transfer Starting Address Register                       */
    __I  uint32_t DMABCNT;               /*!< [0x040c] NFI DMA Transfer Byte Count Register                             */
    __IO uint32_t DMAINTEN;              /*!< [0x0410] NFI DMA Interrupt Enable Control Register                        */
    __I  uint32_t DMAINTSTS;             /*!< [0x0414] NFI DMA Interrupt Status Register                                */
    __I  uint32_t RESERVE2[250];
    __IO uint32_t GCTL;                  /*!< [0x0800] NFI Global Control and Status Register                           */
    __IO uint32_t GINTEN;                /*!< [0x0804] NFI Global Interrupt Control Register                            */
    __I  uint32_t GINTSTS;               /*!< [0x0808] NFI Global Interrupt Status Register                             */
    __I  uint32_t RESERVE3[37];
    __IO uint32_t NANDCTL;               /*!< [0x08a0] NAND Flash Control Register                                      */
    __IO uint32_t NANDTMCTL;             /*!< [0x08a4] NAND Flash Timing Control Register                               */
    __IO uint32_t NANDINTEN;             /*!< [0x08a8] NAND Flash Interrupt Enable Register                             */
    __IO uint32_t NANDINTSTS;            /*!< [0x08ac] NAND Flash Interrupt Status Register                             */
    __O  uint32_t NANDCMD;               /*!< [0x08b0] NAND Flash Command Port Register                                 */
    __O  uint32_t NANDADDR;              /*!< [0x08b4] NAND Flash Address Port Register                                 */
    __IO uint32_t NANDDATA;              /*!< [0x08b8] NAND Flash Data Port Register                                    */
    __IO uint32_t NANDRACTL;             /*!< [0x08bc] NAND Flash Redundant Area Control Register                       */
    __IO uint32_t NANDECTL;              /*!< [0x08c0] NAND Flash Extend Control Register                               */
    __I  uint32_t RESERVE4[3];
    __I  uint32_t NANDECCES[4];          /*!< [0x08d0] NAND Flash ECC Error Status 0 Register                           */
    __I  uint32_t RESERVE5[8];
    __I  uint32_t NANDECCEA[12];         /*!< [0x0900] NAND Flash ECC Error Byte Address 0 Register                     */
    __I  uint32_t RESERVE6[12];
    __I  uint32_t NANDECCED[6];          /*!< [0x0960] NAND Flash ECC Error Data Register 0                             */
    __I  uint32_t RESERVE7[34];
    __IO uint32_t NANDRA[118];           /*!< [0x0a00] NAND Flash Redundant Area Word n                                 */

} NFI_T;

/**
    @addtogroup NFI_CONST NFI Bit Field Definition
    Constant Definitions for NFI Controller
@{ */

#define NFI_BUFFER_Data_Pos              (0)                                               /*!< NFI_T::BUFFER: Data Position           */
#define NFI_BUFFER_Data_Msk              (0xfffffffful << NFI_BUFFER0_Data_Pos)            /*!< NFI_T::BUFFER: Data Mask               */

#define NFI_DMACTL_DMACEN_Pos            (0)                                               /*!< NFI_T::DMACTL: DMACEN Position         */
#define NFI_DMACTL_DMACEN_Msk            (0x1ul << NFI_DMACTL_DMACEN_Pos)                  /*!< NFI_T::DMACTL: DMACEN Mask             */

#define NFI_DMACTL_DMARST_Pos            (1)                                               /*!< NFI_T::DMACTL: DMARST Position         */
#define NFI_DMACTL_DMARST_Msk            (0x1ul << NFI_DMACTL_DMARST_Pos)                  /*!< NFI_T::DMACTL: DMARST Mask             */

#define NFI_DMACTL_SGEN_Pos              (3)                                               /*!< NFI_T::DMACTL: SGEN Position           */
#define NFI_DMACTL_SGEN_Msk              (0x1ul << NFI_DMACTL_SGEN_Pos)                    /*!< NFI_T::DMACTL: SGEN Mask               */

#define NFI_DMACTL_DMABUSY_Pos           (9)                                               /*!< NFI_T::DMACTL: DMABUSY Position        */
#define NFI_DMACTL_DMABUSY_Msk           (0x1ul << NFI_DMACTL_DMABUSY_Pos)                 /*!< NFI_T::DMACTL: DMABUSY Mask            */

#define NFI_DMASA_ORDER_Pos              (0)                                               /*!< NFI_T::DMASA: ORDER Position           */
#define NFI_DMASA_ORDER_Msk              (0x1ul << NFI_DMASA_ORDER_Pos)                    /*!< NFI_T::DMASA: ORDER Mask               */

#define NFI_DMASA_DMASA_Pos              (1)                                               /*!< NFI_T::DMASA: DMASA Position           */
#define NFI_DMASA_DMASA_Msk              (0x7ffffffful << NFI_DMASA_DMASA_Pos)             /*!< NFI_T::DMASA: DMASA Mask               */

#define NFI_DMABCNT_BCNT_Pos             (0)                                               /*!< NFI_T::DMABCNT: BCNT Position          */
#define NFI_DMABCNT_BCNT_Msk             (0xffffful << NFI_DMABCNT_BCNT_Pos)               /*!< NFI_T::DMABCNT: BCNT Mask              */

#define NFI_DMAINTEN_ABORTIEN_Pos        (0)                                               /*!< NFI_T::DMAINTEN: ABORTIEN Position     */
#define NFI_DMAINTEN_ABORTIEN_Msk        (0x1ul << NFI_DMAINTEN_ABORTIEN_Pos)              /*!< NFI_T::DMAINTEN: ABORTIEN Mask         */

#define NFI_DMAINTEN_WEOTIEN_Pos         (1)                                               /*!< NFI_T::DMAINTEN: WEOTIEN Position      */
#define NFI_DMAINTEN_WEOTIEN_Msk         (0x1ul << NFI_DMAINTEN_WEOTIEN_Pos)               /*!< NFI_T::DMAINTEN: WEOTIEN Mask          */

#define NFI_DMAINTSTS_ABORTIF_Pos        (0)                                               /*!< NFI_T::DMAINTSTS: ABORTIF Position     */
#define NFI_DMAINTSTS_ABORTIF_Msk        (0x1ul << NFI_DMAINTSTS_ABORTIF_Pos)              /*!< NFI_T::DMAINTSTS: ABORTIF Mask         */

#define NFI_DMAINTSTS_WEOTIF_Pos         (1)                                               /*!< NFI_T::DMAINTSTS: WEOTIF Position      */
#define NFI_DMAINTSTS_WEOTIF_Msk         (0x1ul << NFI_DMAINTSTS_WEOTIF_Pos)               /*!< NFI_T::DMAINTSTS: WEOTIF Mask          */

#define NFI_GCTL_GCTLRST_Pos             (0)                                               /*!< NFI_T::GCTL: GCTLRST Position          */
#define NFI_GCTL_GCTLRST_Msk             (0x1ul << NFI_GCTL_GCTLRST_Pos)                   /*!< NFI_T::GCTL: GCTLRST Mask              */

#define NFI_GCTL_NANDEN_Pos              (3)                                               /*!< NFI_T::GCTL: NANDEN Position           */
#define NFI_GCTL_NANDEN_Msk              (0x1ul << NFI_GCTL_NANDEN_Pos)                    /*!< NFI_T::GCTL: NANDEN Mask               */

#define NFI_GINTEN_DTAIEN_Pos            (0)                                               /*!< NFI_T::GINTEN: DTAIEN Position         */
#define NFI_GINTEN_DTAIEN_Msk            (0x1ul << NFI_GINTEN_DTAIEN_Pos)                  /*!< NFI_T::GINTEN: DTAIEN Mask             */

#define NFI_GINTSTS_DTAIF_Pos            (0)                                               /*!< NFI_T::GINTSTS: DTAIF Position         */
#define NFI_GINTSTS_DTAIF_Msk            (0x1ul << NFI_GINTSTS_DTAIF_Pos)                  /*!< NFI_T::GINTSTS: DTAIF Mask             */

#define NFI_NANDCTL_SWRST_Pos            (0)                                               /*!< NFI_T::NANDCTL: SWRST Position         */
#define NFI_NANDCTL_SWRST_Msk            (0x1ul << NFI_NANDCTL_SWRST_Pos)                  /*!< NFI_T::NANDCTL: SWRST Mask             */

#define NFI_NANDCTL_DRDEN_Pos            (1)                                               /*!< NFI_T::NANDCTL: DRDEN Position         */
#define NFI_NANDCTL_DRDEN_Msk            (0x1ul << NFI_NANDCTL_DRDEN_Pos)                  /*!< NFI_T::NANDCTL: DRDEN Mask             */

#define NFI_NANDCTL_DWREN_Pos            (2)                                               /*!< NFI_T::NANDCTL: DWREN Position         */
#define NFI_NANDCTL_DWREN_Msk            (0x1ul << NFI_NANDCTL_DWREN_Pos)                  /*!< NFI_T::NANDCTL: DWREN Mask             */

#define NFI_NANDCTL_REDUNREN_Pos         (3)                                               /*!< NFI_T::NANDCTL: REDUNREN Position      */
#define NFI_NANDCTL_REDUNREN_Msk         (0x1ul << NFI_NANDCTL_REDUNREN_Pos)               /*!< NFI_T::NANDCTL: REDUNREN Mask          */

#define NFI_NANDCTL_REDUNAUTOWEN_Pos     (4)                                               /*!< NFI_T::NANDCTL: REDUNAUTOWEN Position  */
#define NFI_NANDCTL_REDUNAUTOWEN_Msk     (0x1ul << NFI_NANDCTL_REDUNAUTOWEN_Pos)           /*!< NFI_T::NANDCTL: REDUNAUTOWEN Mask      */

#define NFI_NANDCTL_ECCCHK_Pos           (7)                                               /*!< NFI_T::NANDCTL: ECCCHK Position        */
#define NFI_NANDCTL_ECCCHK_Msk           (0x1ul << NFI_NANDCTL_ECCCHK_Pos)                 /*!< NFI_T::NANDCTL: ECCCHK Mask            */

#define NFI_NANDCTL_PROT3BEN_Pos         (8)                                               /*!< NFI_T::NANDCTL: PROT3BEN Position      */
#define NFI_NANDCTL_PROT3BEN_Msk         (0x1ul << NFI_NANDCTL_PROT3BEN_Pos)               /*!< NFI_T::NANDCTL: PROT3BEN Mask          */

#define NFI_NANDCTL_SRAMINT_Pos          (9)                                               /*!< NFI_T::NANDCTL: SRAMINT Position       */
#define NFI_NANDCTL_SRAMINT_Msk          (0x1ul << NFI_NANDCTL_SRAMINT_Pos)                /*!< NFI_T::NANDCTL: SRAMINT Mask           */

#define NFI_NANDCTL_PSIZE_Pos            (16)                                              /*!< NFI_T::NANDCTL: PSIZE Position         */
#define NFI_NANDCTL_PSIZE_Msk            (0x3ul << NFI_NANDCTL_PSIZE_Pos)                  /*!< NFI_T::NANDCTL: PSIZE Mask             */

#define NFI_NANDCTL_BCHTSEL_Pos          (18)                                              /*!< NFI_T::NANDCTL: BCHTSEL Position       */
#define NFI_NANDCTL_BCHTSEL_Msk          (0x1ful << NFI_NANDCTL_BCHTSEL_Pos)               /*!< NFI_T::NANDCTL: BCHTSEL Mask           */

#define NFI_NANDCTL_ECCEN_Pos            (23)                                              /*!< NFI_T::NANDCTL: ECCEN Position         */
#define NFI_NANDCTL_ECCEN_Msk            (0x1ul << NFI_NANDCTL_ECCEN_Pos)                  /*!< NFI_T::NANDCTL: ECCEN Mask             */

#define NFI_NANDCTL_CS0_Pos              (25)                                              /*!< NFI_T::NANDCTL: CS0 Position           */
#define NFI_NANDCTL_CS0_Msk              (0x1ul << NFI_NANDCTL_CS0_Pos)                    /*!< NFI_T::NANDCTL: CS0 Mask               */

#define NFI_NANDTMCTL_LOWID_Pos          (0)                                               /*!< NFI_T::NANDTMCTL: LOWID Position       */
#define NFI_NANDTMCTL_LOWID_Msk          (0xfful << NFI_NANDTMCTL_LOWID_Pos)               /*!< NFI_T::NANDTMCTL: LOWID Mask           */

#define NFI_NANDTMCTL_HIWID_Pos          (8)                                               /*!< NFI_T::NANDTMCTL: HIWID Position       */
#define NFI_NANDTMCTL_HIWID_Msk          (0xfful << NFI_NANDTMCTL_HIWID_Pos)               /*!< NFI_T::NANDTMCTL: HIWID Mask           */

#define NFI_NANDTMCTL_CALESH_Pos         (16)                                              /*!< NFI_T::NANDTMCTL: CALESH Position      */
#define NFI_NANDTMCTL_CALESH_Msk         (0x7ful << NFI_NANDTMCTL_CALESH_Pos)              /*!< NFI_T::NANDTMCTL: CALESH Mask          */

#define NFI_NANDTMCTL_EDOD_Pos           (24)                                              /*!< NFI_T::NANDTMCTL: EDOD Position        */
#define NFI_NANDTMCTL_EDOD_Msk           (0xful << NFI_NANDTMCTL_EDOD_Pos)                 /*!< NFI_T::NANDTMCTL: EDOD Mask            */

#define NFI_NANDTMCTL_EDOEN_Pos          (31)                                              /*!< NFI_T::NANDTMCTL: EDOEN Position       */
#define NFI_NANDTMCTL_EDOEN_Msk          (0x1ul << NFI_NANDTMCTL_EDOEN_Pos)                /*!< NFI_T::NANDTMCTL: EDOEN Mask           */

#define NFI_NANDINTEN_DMAIE_Pos          (0)                                               /*!< NFI_T::NANDINTEN: DMAIE Position       */
#define NFI_NANDINTEN_DMAIE_Msk          (0x1ul << NFI_NANDINTEN_DMAIE_Pos)                /*!< NFI_T::NANDINTEN: DMAIE Mask           */

#define NFI_NANDINTEN_ECCFLDIE_Pos       (2)                                               /*!< NFI_T::NANDINTEN: ECCFLDIE Position    */
#define NFI_NANDINTEN_ECCFLDIE_Msk       (0x1ul << NFI_NANDINTEN_ECCFLDIE_Pos)             /*!< NFI_T::NANDINTEN: ECCFLDIE Mask        */

#define NFI_NANDINTEN_RB0IE_Pos          (10)                                              /*!< NFI_T::NANDINTEN: RB0IE Position       */
#define NFI_NANDINTEN_RB0IE_Msk          (0x1ul << NFI_NANDINTEN_RB0IE_Pos)                /*!< NFI_T::NANDINTEN: RB0IE Mask           */

#define NFI_NANDINTSTS_DMAIF_Pos         (0)                                               /*!< NFI_T::NANDINTSTS: DMAIF Position      */
#define NFI_NANDINTSTS_DMAIF_Msk         (0x1ul << NFI_NANDINTSTS_DMAIF_Pos)               /*!< NFI_T::NANDINTSTS: DMAIF Mask          */

#define NFI_NANDINTSTS_ECCFLDIF_Pos      (2)                                               /*!< NFI_T::NANDINTSTS: ECCFLDIF Position   */
#define NFI_NANDINTSTS_ECCFLDIF_Msk      (0x1ul << NFI_NANDINTSTS_ECCFLDIF_Pos)            /*!< NFI_T::NANDINTSTS: ECCFLDIF Mask       */

#define NFI_NANDINTSTS_EDOF_Pos          (4)                                               /*!< NFI_T::NANDINTSTS: EDOF Position       */
#define NFI_NANDINTSTS_EDOF_Msk          (0x1ul << NFI_NANDINTSTS_EDOF_Pos)                /*!< NFI_T::NANDINTSTS: EDOF Mask           */

#define NFI_NANDINTSTS_RB0IF_Pos         (10)                                              /*!< NFI_T::NANDINTSTS: RB0IF Position      */
#define NFI_NANDINTSTS_RB0IF_Msk         (0x1ul << NFI_NANDINTSTS_RB0IF_Pos)               /*!< NFI_T::NANDINTSTS: RB0IF Mask          */

#define NFI_NANDINTSTS_RB0Status_Pos     (18)                                              /*!< NFI_T::NANDINTSTS: RB0Status Position  */
#define NFI_NANDINTSTS_RB0Status_Msk     (0x1ul << NFI_NANDINTSTS_RB0Status_Pos)           /*!< NFI_T::NANDINTSTS: RB0Status Mask      */

#define NFI_NANDCMD_COMMAND_Pos          (0)                                               /*!< NFI_T::NANDCMD: COMMAND Position       */
#define NFI_NANDCMD_COMMAND_Msk          (0xfful << NFI_NANDCMD_COMMAND_Pos)               /*!< NFI_T::NANDCMD: COMMAND Mask           */

#define NFI_NANDADDR_ADDRESS_Pos         (0)                                               /*!< NFI_T::NANDADDR: ADDRESS Position      */
#define NFI_NANDADDR_ADDRESS_Msk         (0xfful << NFI_NANDADDR_ADDRESS_Pos)              /*!< NFI_T::NANDADDR: ADDRESS Mask          */

#define NFI_NANDADDR_EOA_Pos             (31)                                              /*!< NFI_T::NANDADDR: EOA Position          */
#define NFI_NANDADDR_EOA_Msk             (0x1ul << NFI_NANDADDR_EOA_Pos)                   /*!< NFI_T::NANDADDR: EOA Mask              */

#define NFI_NANDDATA_DATA_Pos            (0)                                               /*!< NFI_T::NANDDATA: DATA Position         */
#define NFI_NANDDATA_DATA_Msk            (0xfful << NFI_NANDDATA_DATA_Pos)                 /*!< NFI_T::NANDDATA: DATA Mask             */

#define NFI_NANDRACTL_RA128EN_Pos        (0)                                               /*!< NFI_T::NANDRACTL: RA128EN Position     */
#define NFI_NANDRACTL_RA128EN_Msk        (0x1fful << NFI_NANDRACTL_RA128EN_Pos)            /*!< NFI_T::NANDRACTL: RA128EN Mask         */

#define NFI_NANDRACTL_MECC_Pos           (16)                                              /*!< NFI_T::NANDRACTL: MECC Position        */
#define NFI_NANDRACTL_MECC_Msk           (0xfffful << NFI_NANDRACTL_MECC_Pos)              /*!< NFI_T::NANDRACTL: MECC Mask            */

#define NFI_NANDECTL_WP_Pos              (0)                                               /*!< NFI_T::NANDECTL: WP Position           */
#define NFI_NANDECTL_WP_Msk              (0x1ul << NFI_NANDECTL_WP_Pos)                    /*!< NFI_T::NANDECTL: WP Mask               */

#define NFI_NANDECCES_F1STAT_Pos         (0)                                               /*!< NFI_T::NANDECCES: F1STAT Position      */
#define NFI_NANDECCES_F1STAT_Msk         (0x3ul << NFI_NANDECCES0_F1STAT_Pos)              /*!< NFI_T::NANDECCES: F1STAT Mask          */

#define NFI_NANDECCES_F1ECNT_Pos         (2)                                               /*!< NFI_T::NANDECCES: F1ECNT Position      */
#define NFI_NANDECCES_F1ECNT_Msk         (0x1ful << NFI_NANDECCES0_F1ECNT_Pos)             /*!< NFI_T::NANDECCES: F1ECNT Mask          */

#define NFI_NANDECCES_F2STAT_Pos         (8)                                               /*!< NFI_T::NANDECCES: F2STAT Position      */
#define NFI_NANDECCES_F2STAT_Msk         (0x3ul << NFI_NANDECCES0_F2STAT_Pos)              /*!< NFI_T::NANDECCES: F2STAT Mask          */

#define NFI_NANDECCES_F2ECNT_Pos         (10)                                              /*!< NFI_T::NANDECCES: F2ECNT Position      */
#define NFI_NANDECCES_F2ECNT_Msk         (0x1ful << NFI_NANDECCES0_F2ECNT_Pos)             /*!< NFI_T::NANDECCES: F2ECNT Mask          */

#define NFI_NANDECCES_F3STAT_Pos         (16)                                              /*!< NFI_T::NANDECCES: F3STAT Position      */
#define NFI_NANDECCES_F3STAT_Msk         (0x3ul << NFI_NANDECCES0_F3STAT_Pos)              /*!< NFI_T::NANDECCES: F3STAT Mask          */

#define NFI_NANDECCES_F3ECNT_Pos         (18)                                              /*!< NFI_T::NANDECCES: F3ECNT Position      */
#define NFI_NANDECCES_F3ECNT_Msk         (0x1ful << NFI_NANDECCES0_F3ECNT_Pos)             /*!< NFI_T::NANDECCES: F3ECNT Mask          */

#define NFI_NANDECCES_F4STAT_Pos         (24)                                              /*!< NFI_T::NANDECCES: F4STAT Position      */
#define NFI_NANDECCES_F4STAT_Msk         (0x3ul << NFI_NANDECCES0_F4STAT_Pos)              /*!< NFI_T::NANDECCES: F4STAT Mask          */

#define NFI_NANDECCES_F4ECNT_Pos         (26)                                              /*!< NFI_T::NANDECCES: F4ECNT Position      */
#define NFI_NANDECCES_F4ECNT_Msk         (0x1ful << NFI_NANDECCES0_F4ECNT_Pos)             /*!< NFI_T::NANDECCES: F4ECNT Mask          */

#define NFI_NANDRA_Data_Pos              (0)                                               /*!< NFI_T::NANDRA: Data Position           */
#define NFI_NANDRA_Data_Msk              (0xfffffffful << NFI_NANDRA0_Data_Pos)            /*!< NFI_T::NANDRA: Data Mask               */

/**@}*/ /* NFI_CONST */
/**@}*/ /* end of NFI register group */
/**@}*/ /* end of REGISTER group */

#if defined ( __CC_ARM   )
#pragma no_anon_unions
#endif

#endif /* __NFI_REG_H__ */

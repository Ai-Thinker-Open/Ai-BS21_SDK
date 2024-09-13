/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V151 ssi register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-08, Create file. \n
 */
#ifndef HAL_SPI_V151_REGS_DEF_H
#define HAL_SPI_V151_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_spi_v151_regs_def SPI V151 Regs Definition
 * @ingroup  drivers_hal_spi
 * @{
 */

#define HAL_SPI_DRNM_REG_SIZE 36

/**
 * @brief  This union represents the bit fields in the Control Register 0. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_ctra_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t soe            :   1;  /*!< <b>Slave Output Enable.</b> \n
                                             Relevant only when the spi is
                                             configured as a spi_slenrial-slave device. When configured as a
                                             spi_slenrial master, this bit field has no functionality. This bit
                                             enables or disables the setting of the ssi_oe_n output from
                                             the spi spi_slenrial slave. When SLV_OE = 1, the
                                             ssi_oe_n output can never be active. When the ssi_oe_n
                                             output controls the tri-state buffer on the txd output from the
                                             slave, a high impedance state is always present on the slave
                                             txd output when SLV_OE = 1. \n
                                             This is useful when the master transmits in broadcast mode
                                             (master transmits data to all slave devices). Only one slave
                                             may respond with data on the master rxd line. This bit is
                                             enabled after reset and must be disabled by software (when
                                             broadcast mode is used), if you do not want this device to
                                             respond with data. \n
                                             <b>Values:</b>
                                                - 0x1 (DISABLED): Slave Output is disabled
                                                - 0x0 (ENABLED): Slave Output is enabled \n */
        uint32_t srlt           :   1;  /*!< <b>Shift Register Loop.</b> \n
                                             Used for testing purposes only. When internally active,
                                             connects the transmit shift register output to the receive shift
                                             register input. \n
                                             Can be used in both spi_slenrial-slave and spi_slenrial-master modes.
                                             When the spi is configured as a slave in loopback
                                             mode, the ss_in_n and ssi_clk signals must be provided by
                                             an external source. In this mode, the slave cannot generate
                                             these signals because there is nothing to which to loop back \n
                                             <b>Values:</b>
                                                - 0x1 (TESTING_MODE): Test mode: Tx & Rx shift reg connected
                                                - 0x0 (NORMAL_MODE): Normal mode operation */
        uint32_t ssn_te         :   1;  /*!< <b>Slave Select Toggle Enable.</b> \n
                                             When operating in SPI mode with clock phase (SCPH) set to
                                             0, this register controls the behavior of the slave select line
                                             (ss_*_n) between data frames. If this register field is set to 1
                                             the ss_*_n line will toggle between consecutive data frames,
                                             with the spi_slenrial clock (sclk) being held to its default value while
                                             ss_*_n is high; if this register field is set to 0 the ss_*_n will
                                             stay low and sclk will run continuously for the duration of the
                                             transfer. \n
                                             @note
                                             This register is only valid when SPI_SCPH0_SSTOGGLE is set to 1.
                                             @par
                                             */
        uint32_t scph           :   1;  /*!< <b>Serial Clock Phase.</b>
                                             Valid when the frame format (FRF) is set to Motorola SPI.
                                             The spi_slenrial clock phase selects the relationship of the spi_slenrial
                                             clock with the slave select signal. \n
                                             When SCPH = 0, data are captured on the first edge of the
                                             spi_slenrial clock. When SCPH = 1, the spi_slenrial clock starts toggling
                                             one cycle after the slave select line is activated, and data are
                                             captured on the second edge of the spi_slenrial clock. \n
                                             <b>Values:</b>
                                                - 0x0 (SCPH_MIDDLE): Serial clock toggles in middle of first data bit.
                                                - 0x1 (SCPH_START): Serial clock toggles at start of first data bit. */
        uint32_t scpol          :   1;  /*!< <b>Serial Clock Polarity.</b> \n
                                             Valid when the frame format (FRF) is set to Motorola SPI.
                                             Used to select the polarity of the inactive spi_slenrial clock, which
                                             is held inactive when the spi master is not actively
                                             transferring data on the spi_slenrial bus. \n
                                             <b>Values:</b>
                                                - 0x0 (SCLK_LOW): Inactive state of spi_slenrial clock is low
                                                - 0x1 (SCLK_HIGH): Inactive state of spi_slenrial clock is high */
        uint32_t cfs16          :   4;  /*!< <b>Control Frame Size.</b>  \n
                                             Selects the length of the control word for the Microwire frame format. \n
                                             <b>Values:</b>
                                                - 0x0 (SIZE_01_BIT): 1-bit Control Word
                                                - 0x1 (SIZE_02_BIT): 2-bit Control Word
                                                - 0x2 (SIZE_03_BIT): 3-bit Control Word
                                                - 0x3 (SIZE_04_BIT): 4-bit Control Word
                                                - 0x4 (SIZE_05_BIT): 5-bit Control Word
                                                - 0x5 (SIZE_06_BIT): 6-bit Control Word
                                                - 0x6 (SIZE_07_BIT): 7-bit Control Word
                                                - 0x7 (SIZE_08_BIT): 8-bit Control Word
                                                - 0x8 (SIZE_09_BIT): 9-bit Control Word
                                                - 0x9 (SIZE_10_BIT): 10-bit Control Word
                                                - 0xa (SIZE_11_BIT): 11-bit Control Word
                                                - 0xb (SIZE_12_BIT): 12-bit Control Word
                                                - 0xc (SIZE_13_BIT): 13-bit Control Word
                                                - 0xd (SIZE_14_BIT): 14-bit Control Word
                                                - 0xe (SIZE_15_BIT): 15-bit Control Word
                                                - 0xf (SIZE_16_BIT): 16-bit Control Word */
        uint32_t dfs16          :   4;  /*!< <b>Data Frame Size.</b> \n
                                             This register field is only valid when SPI_MAX_XFER_SIZE
                                             is configured to 16. If SPI_MAX_XFER_SIZE is configured to
                                             32, then writing to this field will not have any effect. \n
                                             Selects the data frame length. When the data frame size is
                                             programmed to be less than 16 bits, the receive data are
                                             automatically right-justified by the receive logic, with the
                                             upper bits of the receive FIFO zero-padded. \n
                                             You must right-justify transmit data before writing into the
                                             transmit FIFO. The transmit logic ignores the upper unused
                                             bits when transmitting the data. \n
                                             @note
                                             When SPI_SPI_MODE is either set to "Dual" or
                                             "Quad" or "Octal" mode and SPI_FRF is not set to 2'b00.
                                                - DFS value should be multiple of 2 if SPI_FRF = 01.
                                                - DFS value should be multiple of 4 if SPI_FRF = 10.
                                                - DFS value should be multiple of 8 if SPI_FRF = 11.
                                             @par
                                             <b>Values:</b>
                                                - 0x3 (FRAME_04BITS): 4-bit spi_slenrial data transfer.
                                                - 0x4 (FRAME_05BITS): 5-bit spi_slenrial data transfer.
                                                - 0x5 (FRAME_06BITS): 6-bit spi_slenrial data transfer.
                                                - 0x6 (FRAME_07BITS): 7-bit spi_slenrial data transfer.
                                                - 0x7 (FRAME_08BITS): 8-bit spi_slenrial data transfer.
                                                - 0x8 (FRAME_09BITS): 9-bit spi_slenrial data transfer.
                                                - 0x9 (FRAME_10BITS): 10-bit spi_slenrial data transfer.
                                                - 0xa (FRAME_11BITS): 11-bit spi_slenrial data transfer.
                                                - 0xb (FRAME_12BITS): 12-bit spi_slenrial data transfer.
                                                - 0xc (FRAME_13BITS): 13-bit spi_slenrial data transfer.
                                                - 0xd (FRAME_14BITS): 14-bit spi_slenrial data transfer.
                                                - 0xe (FRAME_15BITS): 15-bit spi_slenrial data transfer.
                                                - 0xf (FRAME_16BITS): 16-bit spi_slenrial data transfer. */
        uint32_t dfs32          :   5;  /*!< <b>Data Frame Size.</b> \n
                                             in 32-bit transfer size mode. Used to select
                                             the data frame size in 32-bit transfer mode. These bits are
                                             only valid when SPI_MAX_XFER_SIZE is configured to 32.
                                             When the data frame size is programmed to be less than 32
                                             bits, the receive data are automatically right-justified by the
                                             receive logic, with the upper bits of the receive FIFO zeropadded.
                                             You are responsible for making sure that transmit
                                             data is right-justified before writing into the transmit FIFO.
                                             The transmit logic ignores the upper unused bits when
                                             transmitting the data. \n
                                             @note
                                             When SPI_SPI_MODE is either set to "Dual" or
                                             "Quad" or "Octal" mode and SPI_FRF is not set to 2'b00.
                                                - DFS value should be multiple of 2 if SPI_FRF = 0x01,
                                                - DFS value should be multiple of 4 if SPI_FRF = 0x10,
                                                - DFS value should be multiple of 8 if SPI_FRF = 0x11.
                                             @par
                                            <b>Values:</b>
                                                - 0x3 (FRAME_04BITS): 4-bit spi_slenrial data transfer
                                                - 0x4 (FRAME_05BITS): 5-bit spi_slenrial data transfer
                                                - 0x5 (FRAME_06BITS): 6-bit spi_slenrial data transfer
                                                - 0x6 (FRAME_07BITS): 7-bit spi_slenrial data transfer
                                                - 0x7 (FRAME_08BITS): 8-bit spi_slenrial data transfer
                                                - 0x8 (FRAME_09BITS): 9-bit spi_slenrial data transfer
                                                - 0x9 (FRAME_10BITS): 10-bit spi_slenrial data transfer
                                                - 0xa (FRAME_11BITS): 11-bit spi_slenrial data transfer
                                                - 0xb (FRAME_12BITS): 12-bit spi_slenrial data transfer
                                                - 0xc (FRAME_13BITS): 13-bit spi_slenrial data transfer
                                                - 0xd (FRAME_14BITS): 14-bit spi_slenrial data transfer
                                                - 0xe (FRAME_15BITS): 15-bit spi_slenrial data transfer
                                                - 0xf (FRAME_16BITS): 16-bit spi_slenrial data transfer
                                                - 0x10 (FRAME_17BITS): 17-bit spi_slenrial data transfer
                                                - 0x11 (FRAME_18BITS): 18-bit spi_slenrial data transfer
                                                - 0x12 (FRAME_19BITS): 19-bit spi_slenrial data transfer
                                                - 0x13 (FRAME_20BITS): 20-bit spi_slenrial data transfer
                                                - 0x14 (FRAME_21BITS): 21-bit spi_slenrial data transfer
                                                - 0x15 (FRAME_22BITS): 22-bit spi_slenrial data transfer
                                                - 0x16 (FRAME_23BITS): 23-bit spi_slenrial data transfer
                                                - 0x17 (FRAME_24BITS): 24-bit spi_slenrial data transfer
                                                - 0x18 (FRAME_25BITS): 25-bit spi_slenrial data transfer
                                                - 0x19 (FRAME_26BITS): 26-bit spi_slenrial data transfer
                                                - 0x1a (FRAME_27BITS): 27-bit spi_slenrial data transfer
                                                - 0x1b (FRAME_28BITS): 28-bit spi_slenrial data transfer
                                                - 0x1c (FRAME_29BITS): 29-bit spi_slenrial data transfer
                                                - 0x1d (FRAME_30BITS): 30-bit spi_slenrial data transfer
                                                - 0x1e (FRAME_31BITS): 31-bit spi_slenrial data transfer
                                                - 0x1f (FRAME_32BITS): 32-bit spi_slenrial data transfer */

        uint32_t trsm           :   2;  /*!< <b>Transfer Mode.</b> \n
                                             Selects the mode of transfer for spi_slenrial communication. This
                                             field does not affect the transfer duplicity. Only indicates
                                             whether the receive or transmit data are valid. \n
                                             In transmit-only mode, data received from the external
                                             device is not valid and is not stored in the receive FIFO
                                             memory; it is overwritten on the next transfer. \n
                                             In receive-only mode, transmitted data are not valid. After
                                             the first write to the transmit FIFO, the same word is
                                             retransmitted for the duration of the transfer. \n
                                             In transmit-and-receive mode, both transmit and receive
                                             data are valid. The transfer continues until the transmit FIFO
                                             is empty. Data received from the external device are stored
                                             into the receive FIFO memory, where it can be accessed by
                                             the host processor. \n
                                             In eeprom-read mode, receive data is not valid while control
                                             data is being transmitted. When all control data is sent to the
                                             EEPROM, receive data becomes valid and transmit data
                                             becomes invalid. All data in the transmit FIFO is considered
                                             control data in this mode. This transfer mode is only valid
                                             when the spi is configured as master device.
                                                - 00 - Transmit & Receive
                                                - 01 - Transmit Only
                                                - 10 - Receive Only
                                                - 11 - EEPROM Read
                                             When SPI_SPI_MODE is either set to "Dual" or "Quad" or
                                             "Octal" mode and SPI_FRF is not set to 2'b00. There are
                                             only two valid combinations:
                                                - 10 - Read
                                                - 01 - Write \n
                                             <b>Values:</b>
                                                - 0x0 (TX_AND_RX): Transmit & receive
                                                - 0x1 (TX_ONLY): Transmit only mode or Write (SPI_FRF != 2'b00)
                                                - 0x2 (RX_ONLY): Receive only mode or Read (SPI_FRF != 2'b00)
                                                - 0x3 (EEPROM_READ): EEPROM Read mode */
        uint32_t enhff          :   2;  /*!< <b>SPI Frame Format.</b> \n
                                             Selects data frame format for Transmitting/Receiving the data
                                             Bits only valid when SPI_SPI_MODE is either set to "Dual"
                                             or "Quad" or "Octal" mode. \n
                                             When SPI_SPI_MODE is configured for "Dual Mode", 10/11
                                             combination is reserved. \n
                                             When SPI_SPI_MODE is configured for "Quad Mode", 11
                                             combination is reserved. \n
                                             <b>Values:</b>
                                                - 0x0 (STD_SPI_FRF): Standard SPI Frame Format
                                                - 0x1 (DUAL_SPI_FRF): Dual SPI Frame Format
                                                - 0x2 (QUAD_SPI_FRF): Quad SPI Frame Format
                                                - 0x3 (OCTAL_SPI_FRF): Octal SPI Frame Format
                                              */
        uint32_t prs            :   2;  /*!< <b>Frame Format.</b> \n
                                             Selects which spi_slenrial protocol transfers the data. \n
                                             <b>Values:</b>
                                                - 0x0 (MOTOROLA_SPI): Motorolla SPI Frame Format.
                                                - 0x1 (TEXAS_SSP): Texas Instruments SSP FrameFormat.
                                                - 0x2 (NS_MICROWIRE): National Microwire FrameFormat.
                                                - 0x3 (RESERVED): reserved value. */
        uint32_t reserved24_31  :   6;
    } b;                                /*!< Register bits. */
} spi_ctra_data_t;

/**
 * @brief  This union represents the bit fields in the Control Register 1. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_ctrb_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t nrdf           :   16; /*!< <b>Number of Data Frames.</b> \n
                                             When TMOD = 10 or TMOD = 11 , this register field sets the
                                             number of data frames to be continuously received by the
                                             spi. The spi continues to receive spi_slenrial
                                             data until the number of data frames received is equal to this
                                             register value plus 1, which enables you to receive up to 64
                                             KB of data in a continuous transfer. \n
                                             When the spi is configured as a spi_slenrial slave, the
                                             transfer continues for as long as the slave is selected.
                                             Therefore, this register spi_slenrves no purpose and is not present
                                             when the spi is configured as a spi_slenrial slave. */
    } b;                                /*!< Register bits. */
} spi_ctrb_data_t;

/**
 * @brief  This union represents the bit fields in the SPI Enable Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_er_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t start_en       :   1;  /*!< <b>SPI Enable.</b> \n
                                             Enables and disables all spi operations. When
                                             disabled, all spi_slenrial transfers are halted immediately. Transmit
                                             and receive FIFO buffers are cleared when the device is
                                             disabled. It is impossible to program some of the
                                             spi control registers when enabled. When disabled,
                                             the ssi_sleep output is set (after delay) to inform the system
                                             that it is safe to remove the ssi_clk, thus saving power
                                             consumption in the system. \n
                                             <b>Values:</b>
                                                - 0x0 (DISABLE): Disables Serial Transfer
                                                - 0x1 (ENABLED): Enables Serial Transfer */
    } b;                                /*!< Register bits. */
} spi_er_data_t;

/**
 * @brief  This union represents the bit fields in the Microwire Control Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_mcr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t mh             :   1;  /*!< <b>Microwire Handshaking.</b> \n
                                             Relevant only when the spi is configured as a
                                             spi_slenrial-master device. When configured as a spi_slenrial slave, this
                                             bit field has no functionality. Used to enable and disable the
                                             busy/ready handshaking interface for the Microwire protocol.
                                             When enabled, the spi checks for a ready status
                                             from the target slave, after the transfer of the last data/control
                                             bit, before clearing the BUSY status in the SR register. \n
                                             <b>Values:</b>
                                                - 0x0 (DISABLE): Handshaking interface is disabled
                                                - 0x1 (ENABLED): Handshaking interface is enabled
                                             */
        uint32_t mss            :   1;  /*!< <b>Microwire Transfer Mode.</b> \n
                                             Defines whether the Microwire transfer is sequential or nonsequential.
                                             When sequential mode is used, only one control
                                             word is needed to transmit or receive a block of data words.
                                             When non-sequential mode is used, there must be a control
                                             word for each data word that is transmitted or received. \n
                                             <b>Values:</b>
                                                - 0x0 (NON_SEQUENTIAL): Non-Sequential Microwire Transfer
                                                - 0x1 (SEQUENTIAL): Sequential Microwire Transfer */
        uint32_t mtrc           :   1;  /*!< <b>Microwire Control.</b> \n
                                             Defines the direction of the data word when the Microwire
                                             spi_slenrial protocol is used. When this bit is set to 0, the data
                                             word is received by the spi MacroCell from the
                                             external spi_slenrial device. When this bit is set to 1, the data word
                                             is transmitted from the spi MacroCell to the
                                             external spi_slenrial device. \n
                                             <b>Values:</b>
                                                - 0x0 (RECEIVE): SPI receives data
                                                - 0x1 (TRANSMIT): SPI transmits data */
    } b;                                /*!< Register bits. */
} spi_mcr_data_t;

/**
 * @brief  This union represents the bit fields in the Slave Enable Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_slenr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ssef           :   16; /*!< <b>Slave Select Enable Flag.</b> \n
                                             Each bit in this register corresponds to a slave select line
                                             (ss_x_n) from the spi master. When a bit in this
                                             register is set (1), the corresponding slave select line from
                                             the master is activated when a spi_slenrial transfer begins. It
                                             should be noted that setting or clearing bits in this register
                                             have no effect on the corresponding slave select outputs until
                                             a transfer is started. Before beginning a transfer, you should
                                             enable the bit in this register that corresponds to the slave
                                             device with which the master wants to communicate. When
                                             not operating in broadcast mode, only one bit in this field
                                             should be set. \n
                                             <b>Values:</b>
                                                - 0x0 (NOT_SELECTED): No slave selected
                                                - 0x1 (SELECTED): Slave is selected */
    } b;                                /*!< Register bits. */
} spi_slenr_data_t;

/**
 * @brief  This union represents the bit fields in the Slave Enable Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_brs_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t frdv           :   16; /*!< <b>SPI Clock Divider.</b> \n
                                             The LSB for this field is always set to 0 and is unaffected by a
                                             write operation, which ensures an even value is held in this
                                             register. If the value is 0, the spi_slenrial output clock (sclk_out) is
                                             disabled. The frequency of the sclk_out is derived from the
                                             following equation:. \n
                                             Fsclk_out = Fssi_clk/SCKDV \n
                                             where SCKDV is any even value between 2 and 65534. For example: \n
                                             for Fssi_clk = 3.6864MHz and SCKDV =2, Fsclk_out = 3.6864/2 = 1.8432MHz. */
    } b;                                /*!< Register bits. */
} spi_brs_data_t;

/**
 * @brief  This union represents the bit fields in the Transmit FIFO Threshold Level. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_twlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t twl;                   /*!< <b>Transmit FIFO Threshold.</b> \n
                                             Controls the level of entries (or below) at which the transmit
                                             FIFO controller triggers an interrupt. The FIFO depth is
                                             configurable in the range 2-256; this register is sized to the
                                             number of address bits needed to access the FIFO. If you
                                             attempt to set this value greater than or equal to the depth of
                                             the FIFO, this field is not written and retains its current value.
                                             When the number of transmit FIFO entries is less than or
                                             equal to this value, the transmit FIFO empty interrupt is
                                             triggered. For information on the Transmit FIFO Threshold
                                             values, see the "Master SPI and SSP Serial Transfers" in the
                                             spi Databook. \n
                                             ssi_txe_intr is asspi_slenrted when TFT or less data entries are
                                             present in transmit FIFO. */
    } b;                                /*!< Register bits. */
} spi_twlr_data_t;

/**
 * @brief  This union represents the bit fields in the Receive FIFO Threshold Level. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_rwlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rwl;                   /*!< <b>Receive FIFO Threshold.</b> \n
                                             Controls the level of entries (or above) at which the receive
                                             FIFO controller triggers an interrupt. The FIFO depth is
                                             configurable in the range 2-256. This register is sized to the
                                             number of address bits needed to access the FIFO. If you
                                             attempt to set this value greater than the depth of the FIFO,
                                             this field is not written and retains its current value. When the
                                             number of receive FIFO entries is greater than or equal to
                                             this value + 1, the receive FIFO full interrupt is triggered. For
                                             information on the Receive FIFO Threshold values, see the
                                             "Master SPI and SSP Serial Transfers" in the spi
                                             Databook. \n
                                             ssi_rxf_intr is asspi_slenrted when RFT or more data entries are
                                             present in receive FIFO. */
    } b;                                /*!< Register bits. */
} spi_rwlr_data_t;

/**
 * @brief  This union represents the bit fields in the Transmit FIFO Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_tlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t tfl;                   /*!< <b>Transmit FIFO Level.</b> \n
                                             Contains the number of valid data entries in the transmit FIFO. */
    } b;                                /*!< Register bits. */
} spi_tlr_data_t;

/**
 * @brief  This union represents the bit fields in the Receive FIFO Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_rlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rfl;                 /*!< <b>Receive FIFO Level.</b> \n
                                             Contains the number of valid data entries in the receive FIFO. */
    } b;                                /*!< Register bits. */
} spi_rlr_data_t;

/**
 * @brief  This union represents the bit fields in the Receive FIFO Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_wsr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t dcfe_tfee      :   1;  /*!< <b>Data Collision Error.</b> \n
                                             Relevant only when the spi is configured as a
                                             master device. This bit will be set if ss_in_n input is asspi_slenrted
                                             by other master, when the spi master is in the
                                             middle of the transfer. This informs the processor that the
                                             last data transfer was halted before completion. This bit is
                                             cleared when read. \n
                                             <b>Values:</b>
                                                - 0x0 (NO_ERROR_CONDITION): No Error
                                                - 0x1 (TX_COLLISION_ERROR): Transmit Data Collision Error */
        uint32_t reserved1_3    :   3;
        uint32_t rfne           :   1;  /*!< <b>Receive FIFO Not Empty.</b> \n
                                             Set when the receive FIFO contains one or more entries and
                                             is cleared when the receive FIFO is empty. This bit can be
                                             polled by software to completely empty the receive FIFO. \n
                                             <b>Values:</b>
                                                 - 0x0 (EMPTY): Receive FIFO is empty
                                                 - 0x1 (NOT_EMPTY): Receive FIFO is not empty */
        uint32_t rffe           :   1;  /*!< <b>Receive FIFO Full.</b> \n
                                             When the receive FIFO is completely full, this bit is set.
                                             When the receive FIFO contains one or more empty location,
                                             this bit is cleared. \n
                                             <b>Values:</b>
                                                - 0x0 (NOT_FULL): Receive FIFO is not full
                                                - 0x1 (FULL): Receive FIFO is full */
        uint32_t reserved6_10   :   5;
        uint32_t tfnf           :   1;  /*!< <b>Transmit FIFO Not Full.</b> \n
                                             Set when the transmit FIFO contains one or more empty
                                             locations, and is cleared when the FIFO is full. \n
                                             <b>Values:</b>
                                                - 0x0 (FULL): Transmit FIFO is full
                                                - 0x1 (NOT_FULL): Transmit FIFO is not Full */
        uint32_t tfe            :   1;  /*!< <b>Transmit FIFO Empty.</b> \n
                                             When the transmit FIFO is completely empty, this bit is set. \n
                                             When the transmit FIFO contains one or more valid entries,
                                             this bit is cleared. This bit field does not request an interrupt. \n
                                             <b>Values:</b>
                                                - 0x0 (NOT_EMPTY): Transmit FIFO is not empty
                                                - 0x1 (EMPTY): Transmit FIFO is empty */
        uint32_t reserved13_14  :   2;
        uint32_t sbf            :   1;  /*!< <b>SPI Busy Flag.</b> \n
                                             When set, indicates that a spi_slenrial transfer is in progress; when
                                             cleared indicates that the spi is idle or disabled. \n
                                             <b>Values:</b>
                                                - 0x0 (INACTIVE): spi is idle or disabled
                                                - 0x1 (ACTIVE): spi is actively transferring data */
        uint32_t reserved16_31;
    } b;                                /*!< Register bits. */
} spi_wsr_data_t;

/**
 * @brief  This union represents the bit fields in the Interrupt Registers. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
union spi_v151_interrupt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rffis          :   1;  /*!< Receive FIFO Full Interrupt Mask. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_rxf_intr interrupt is set
                                                - 0x1 (UNSET): ssi_rxf_intr interrupt is not set */
        uint32_t rfofis         :   1;  /*!< Receive FIFO Overflow Interrupt Mask. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_rxo_intr interrupt is set
                                                - 0x1 (UNSET): ssi_rxo_intr interrupt is not set */
        uint32_t rfufis         :   1;  /*!< Receive FIFO Underflow Interrupt Mask. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_rxu_intr interrupt is set
                                                - 0x1 (UNSET): ssi_rxu_intr interrupt is not set */
        uint32_t reserved3_6    :   4;
        uint32_t tfeis          :   1;  /*!< Transmit FIFO Empty Interrupt Mask. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_txe_intr interrupt is set
                                                - 0x1 (UNSET): ssi_txe_intr interrupt is not set */
        uint32_t tfofis         :   1;  /*!< Transmit FIFO Overflow Interrupt Mask. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_txo_intr interrupt is set
                                                - 0x1 (UNSET): ssi_txo_intr interrupt is not set */
        uint32_t reserved9_14   :   6;
        uint32_t mmcris         :   1;  /*!< Multi-Master Contention Interrupt Mask. This bit field is not
                                             present if the spi is configured as a spi_slenrial-slave
                                             device. \n
                                             <b>Values:</b>
                                                - 0x0 (SET): ssi_mst_intr interrupt is set
                                                - 0x1 (UNSET): ssi_mst_intr interrupt is not set */
    } b;                                /*!< Register bits. */
};

/**
 * @brief  This union represents the bit fields in the Interrupt Mask Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_v151_interrupt_data spi_inmar_data_t;

/**
 * @brief  This union represents the bit fields in the Interrupt Status Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_v151_interrupt_data spi_insr_data_t;

/**
 * @brief  This union represents the bit fields in the Raw Interrupt Status Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_v151_interrupt_data spi_rainsr_data_t;

/**
 * @brief  This union represents the bit fields in the Interrupt Clear Register Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_icr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t cis            :   1;  /*!< <b>Clear Interrupt.</b> \n
                                             This register reflects the status of the interrupt. <b>A read from
                                             this register clears the ssi_txo_intr, ssi_rxu_intr, ssi_rxo_intr, and
                                             the ssi_mst_intr interrupt;</b> writing has no
                                             effect. */
        uint32_t reserved1_31   :   31;
    } b;                                /*!< Register bits. */
} spi_icr_data_t;

/**
 * @brief  This union represents the bit fields in the Transmit FIFO Overflow Interrupt Clear Register Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_icr_data spi_tfoficr_data_t;

/**
 * @brief  This union represents the bit fields in the Receive FIFO Overflow Interrupt Clear Register Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_icr_data spi_rxoicr_data_t;

/**
 * @brief  This union represents the bit fields in the Receive FIFO Underflow Interrupt Clear Register Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_icr_data spi_rfficr_data_t;

/**
 * @brief  This union represents the bit fields in the Multi-Master Interrupt Clear Register Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_icr_data spi_msticr_data_t;

/**
 * @brief  This union represents the bit fields in the DMA Control Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_dcr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t tden           :   1;  /*!< <b>Transmit DMA Enable.</b> \n
                                             This bit enables/disables the transmit FIFO DMA channel. \n
                                             <b>Values:</b>
                                                - 0x0 (DISABLE): Transmit DMA disabled
                                                - 0x1 (ENABLED): Transmit DMA enabled */
        uint32_t rden           :   1;  /*!< <b>Receive DMA Enable.</b> \n
                                             This bit enables/disables the receive FIFO DMA channel. \n
                                             <b>Values:</b>
                                                - 0x0 (DISABLE): Transmit DMA disabled
                                                - 0x1 (ENABLED): Transmit DMA enabled */
        uint32_t reserved2_31   :   30;
    } b;                                /*!< Register bits. */
} spi_dcr_data_t;

/**
 * @brief  This union represents the bit fields in the DMA Data Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
union spi_v151_dmadlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t dl;                    /*!< <b>Data Level.</b> \n
                                             These bits field controls the level at which a DMA request is
                                             made by the transmit/receive logic. It is equal to the watermark level */
    } b;                                /*!< Register bits. */
};

/**
 * @brief  This union represents the bit fields in the DMA Transmit Data Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_v151_dmadlr_data spi_dtdl_data_t;

/**
 * @brief  This union represents the bit fields in the DMA Receive Data Level Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_v151_dmadlr_data spi_drdl_data_t;

/**
 * @brief  This union represents the bit fields in the  coreKit version ID Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_id_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t id;                    /*!< Contains the hex representation of the Synopsys component
                                             version. Consists of ASCII value for each number in the
                                             version, followed by *. For example 32_30_31_2A represents
                                             the version 2.01*. */
    } b;                                /*!< Register bits. */
} spi_id_data_t;

/**
 * @brief  This union represents the bit fields in the Data Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_drnm_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t datar;                 /*!< Data Register. When writing to this register, you must rightjustify
                                             the data. Read data are automatically right-justified. If
                                             SPI_MAX_XFER_SIZE configuration parameter is set to 32,
                                             all 32 bits are valid. Otherwise, only 16 bits ([15:0]) of the
                                             register are valid. Read = Receive FIFO buffer Write =
                                             Transmit FIFO buffer. */
    } b;                                /*!< Register bits. */
} spi_drnm_data_t;

/**
 * @brief  This union represents the bit fields in the RX Sample Delay Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_rsdr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rxdsd          :   8;  /*!< <b>Rxd Sample Delay.</b> \n
                                             This register is used to delay the sample of the rxd input port.
                                             Each value represents a single ssi_clk delay on the sample of rxd. */
        uint32_t reserved8_31   :   24;
    } b;                                /*!< Register bits. */
} spi_rsdr_data_t;

/**
 * @brief  This union represents the bit fields in the SPI Control 0 Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_enhctl_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t waitnum        :   5;  /*!< <b>Wait cycles.</b> \n
                                             Number of wait cycles in Dual/Quad/Octal mode between
                                             control frames transmit and data reception. This value is
                                             specified as number of SPI clock cycles. For information on
                                             the WAIT_CYCLES decode value, see "Read Operation in
                                             Enhanced SPI Modes" section in the spi Databook. */
        uint32_t aaitf          :   2;  /*!< <b>Address and instruction transfer format.</b> \n
                                             Selects whether spi will transmit
                                             instruction/address either in Standard SPI mode or the SPI
                                             mode selected in CTRLR0.SPI_FRF field. 00 - Instruction
                                             and Address will be sent in Standard SPI Mode.
                                             01 - Instruction will be sent in Standard SPI Mode and
                                             Address will be sent in the mode specified by
                                             CTRLR0.SPI_FRF. \n
                                             10 - Both Instruction and Address will be sent in the mode
                                             specified by SPI_FRF. 11 - reserved. */
        uint32_t rdsen          :   1;  /*!< <b>Read data strobe enable bit.</b> \n
                                             Once this bit is set to 1 spi will use Read data
                                             strobe (rxds) to capture read data in DDR mode. */
        uint32_t addrlen        :   4;  /*!< <b>Address Length.</b> \n
                                             This bit defines Length of Address to be transmitted. Only
                                             after this much bits are programmed in to the FIFO the
                                             transfer can begin. For information on the ADDR_Ldecode
                                             value, see "Read Operation in Enhanced SPI Modes"
                                             section in the spi Databook. \n
                                             <b>Values:</b>
                                                - 0x0 (ADDR_L_0): 0-bit Address Width
                                                - 0x1 (ADDR_L_1): 4-bit Address Width
                                                - 0x2 (ADDR_L_2): 8-bit Address Width
                                                - 0x3 (ADDR_L_3): 12-bit Address Width
                                                - 0x4 (ADDR_L_4): 16-bit Address Width
                                                - 0x5 (ADDR_L_5): 20-bit Address Width
                                                - 0x6 (ADDR_L_6): 24-bit Address Width
                                                - 0x7 (ADDR_L_7): 28-bit Address Width
                                                - 0x8 (ADDR_L_8): 32-bit Address Width
                                                - 0x9 (ADDR_L_9): 36-bit Address Width
                                                - 0xa (ADDR_L_10): 40-bit Address Width
                                                - 0xb (ADDR_L_11): 44-bit Address Width
                                                - 0xc (ADDR_L_12): 48-bit Address Width
                                                - 0xd (ADDR_L_13): 52-bit Address Width
                                                - 0xe (ADDR_L_14): 56-bit Address Width
                                                - 0xf (ADDR_L_15): 60-bit Address Width */
        uint32_t ilen           :   2;  /*!< <b>Instruction Length.</b> \n
                                             Dual/Quad/Octal mode instruction length in bits. \n
                                             <b>Values:</b>
                                                - 0x0 (INST_L_0): 0-bit (No Instruction)
                                                - 0x1 (INST_L_1): 4-bit Instruction
                                                - 0x2 (INST_L_2): 8-bit Instruction
                                                - 0x3 (INST_L_3): 16-bit Instruction */
        uint32_t iddren         :   1;  /*!< <b>Instruction DDR Enable bit.</b> \n
                                             This will enable Dual-data rate transfer for Instruction phase. */
        uint32_t ddren          :   1;  /*!< <b>SPI DDR Enable bit.</b> \n
                                             This will enable Dual-data rate transfers in Dual/Quad/Octal
                                             frame formats of SPI. */

        uint32_t reserved16_31  :   18;
    } b;                                /*!< Register bits. */
} spi_enhctl_data_t;

/**
 * @brief  This union represents the bit fields in the Transmit Drive Edge Register. \n
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union spi_tder_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t txdde          :   8;  /*!< TXD Drive edge - value of which decides the driving edge of
                                             tramit data. The maximum value of this regster is = (BAUDR/2) -1. */
        uint32_t reserved8_31   :   24;
    } b;                                /*!< Register bits. */
} spi_tder_data_t;

/**
 * @brief  Registers associated with spi.
 */
typedef struct spi_v151_regs {
    volatile uint32_t spi_er;           /*!< This register enables and disables the spi. Reset
                                             Value: 0x0 <i>Offset: 00h</i>. */
    volatile uint32_t spi_ctra;         /*!< This register controls the spi_slenrial data transfer. It is impossible
                                             to write to this register when... <i>Offset: 04h</i>. */
    volatile uint32_t spi_ctrb;         /*!< This register exists only when the spi is configured
                                             as a master device. When the spi... <i>Offset: 08h</i>. */
    volatile uint32_t spi_enhctl;       /*!< This register is valid only when SPI_MODE is either set
                                             to "Dual" or "Quad" or "Octal" mode. This... <i>Offset: 0Ch</i>. */
    volatile uint32_t spi_mcr;          /*!< This register controls the direction of the data word for the
                                             half-duplex Microwire spi_slenrial protocol... <i>Offset: 10h</i>. */
    volatile uint32_t spi_brs;          /*!< This register is valid only when the spi is
                                             configured as a master device. When the spi...
                                             <i>Offset: 14h</i>. */
    volatile uint32_t spi_dcr;          /*!< This register is only valid when spi is configured
                                             with a set of DMA Controller interface... <i>Offset: 18h</i>. */
    volatile uint32_t spi_drdl;         /*!< This register is only valid when spi is configured
                                             with a set of DMA interface signals... <i>Offset: 1Ch</i>. */
    volatile uint32_t spi_dtdl;         /*!< This register is only valid when the spi is
                                             configured with a set of DMA interface signals... <i>Offset: 20h</i>. */
    volatile uint32_t spi_rsdr;         /*!< This register is only valid when the spi is
                                             configured with rxd sample delay logic.... <i>Offset: 24h</i>. */
    volatile uint32_t spi_tder;         /*!< This Register is valid only when SPI_TDER is equal to 1.
                                             This register is used to control the... <i>Offset: 28h</i>. */
    volatile uint32_t spi_drnm[HAL_SPI_DRNM_REG_SIZE]; /*!< The spi data register is a 16/32-bit (depending on
                                                    MAX_XFER_SIZE) read/write buffer for the...
                                                    <i>Offset: 2Ch</i>. */
    volatile uint32_t spi_rainsr;       /*!< This read-only register reports the status of the spi
                                             interrupts prior to masking. Reset... <i>Offset: BCh</i>. */
    volatile uint32_t spi_insr;         /*!< This register reports the status of the spi interrupts
                                             after they have been masked. Reset... <i>Offset: C0h</i>. */
    volatile uint32_t spi_inmar;        /*!< This read/write reigster masks or enables all interrupts
                                             generated by the spi. When the spi... <i>Offset: C4h</i>. */
    volatile uint32_t spi_slenr;        /*!< This register is valid only when the spi is
                                             configured as a master device. When the spi...
                                             <i>Offset: C8h</i>. */
    volatile uint32_t spi_twlr;         /*!< This register controls the threshold value for the transmit
                                             FIFO memory. The spi is enabled... <i>Offset: CCh</i>. */
    volatile uint32_t spi_tlr;          /*!< This register contains the number of valid data entries in the
                                             transmit FIFO memory. Reset Value:.. <i>Offset: D0h</i>. */
    volatile uint32_t spi_tfoficr;      /*!< Transmit FIFO Overflow Interrupt Clear Register. Reset
                                             Value: 0x0 <i>Offset: D4h</i>. */
    volatile uint32_t spi_rwlr;         /*!< This register controls the threshold value for the receive
                                             FIFO memory. The spi is enabled... <i>Offset: D8h</i>. */
    volatile uint32_t spi_rlr;          /*!< This register contains the number of valid data entries in the
                                             receive FIFO memory. This register... <i>Offset: DCh</i>. */
    volatile uint32_t spi_rfficr;       /*!< Receive FIFO Underflow Interrupt Clear Register. Reset
                                             Value: 0x0 <i>Offset: E0h</i>. */
    volatile uint32_t spi_wsr;          /*!< This is a read-only register used to indicate the current
                                             transfer status, FIFO status, and any... <i>Offset: E4h</i>. */
    volatile uint32_t spi_msticr;       /*!< Multi-Master Interrupt Clear Register. Reset Value: 0x0
                                             <i>Offset: E8h</i>. */
    volatile uint32_t spi_id;           /*!< This read-only register stores the specific spi
                                             component version. Reset Value:... <i>Offset: ECh</i>. */
    volatile uint32_t spi_rsvd;         /*!< Reserved. <i>Offset: F0h</i>. */
    volatile uint32_t spi_rxoicr;       /*!< Receive FIFO Overflow Interrupt Clear Register. Reset
                                             Value: 0x0 <i>Offset: F4h</i>. */
    volatile uint32_t spi_icr;          /*!< Interrupt Clear Register. Reset Value: 0x0 <i>Offset: F8h</i>. */
} spi_v151_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
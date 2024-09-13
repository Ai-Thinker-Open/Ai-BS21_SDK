/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides i2c v151 register \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-08-15, Create file. \n
 */

#ifndef HAL_I2C_V151_REGS_DEF_H
#define HAL_I2C_V151_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */


/**
 * @defgroup drivers_hal_i2c_v151_regs_def I2C v151 Regs Definition
 * @ingroup  drivers_hal_i2c
 * @{
 */

#define I2C_COMPONENT_PARAMETER_ADDRESS_START 0xF4
#define I2C_CONFIG_PARAMETER_ADDRESS_END 0x9C

#define I2C_CONFIG_PARAMETER_RES_NUM \
        ((((I2C_COMPONENT_PARAMETER_ADDRESS_START) - (I2C_CONFIG_PARAMETER_ADDRESS_END)) >> 2) - 1)

/**
 * @brief  This union represents the bit fields in the i2c control
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_con_data {
    uint32_t d32;
    struct {
        uint32_t master_mode                  : 1;  /*!< R_W, This bit controls whether the i2c_v151 master is
                                                         enabled. */
        uint32_t speed                        : 2;  /*!< R_W, These bits control at which speed the i2c_v151 operates;
                                                         its setting is relevant only if one is operating the i2c_v151
                                                         in master mode. */
        uint32_t ic_10bitaddr_slave           : 1;  /*!< R_W, When acting as a slave, this bit controls whether the
                                                         i2c_v151 responds to 7- or 10-bit addresses. */
        uint32_t ic_10bitaddr_master          : 1;  /*!< R_W, If the I2C_DYNAMIC_TAR_UPDATE configuration parameter
                                                         is set to 'No' (0), this bit is named IC_10BITADDR_MASTER
                                                         and controls whether the i2c_v151 starts its transfers in
                                                         7- or 10-bit addressing mode when acting as a master. */
        uint32_t ic_restart_en                : 1;  /*!< R_W, Determines whether RESTART conditions may be sent when
                                                         acting as a master. */
        uint32_t ic_slave_disable             : 1;  /*!< R_W, This bit controls whether I2C has its slave disabled,
                                                         which means once the presetn signal is applied, then this bit
                                                         takes on the value of the configuration parameter
                                                         IC_SLAVE_DISABLE. */
        uint32_t stop_det_ifaddressed         : 1;  /*!< R_W, In slave mode:
                                                         1'b1: STOP_DET interrrupt only when it is addressed. */
        uint32_t tx_empty_ctrl                : 1;  /*!< R_W, This bit controls the generation of the TX_EMPTY
                                                         interrupt, as described in the IC_RAW_INTR_STAT register. */
        uint32_t rx_fifo_full_hld_ctrl        : 1;  /*!< Varies, This bit controls whether i2c_v151 should hold the
                                                         bus when the Rx FIFO is physically full to its RX_BUFFER_DEPTH,
                                                         as described in the IC_RX_FULL_HLD_BUS_EN parameter. */
        uint32_t stop_det_if_master_active    : 1;  /*!< R_W,, In Master mode:
                                                         1'b1: issues the STOP_DET interrupt only when master is active.
                                                         1'b0: issues the STOP_DET irrespective of whether
                                                         master is active or not. */
        uint32_t bus_clear_feature_ctrl       : 1;  /*!< R_W, In Master mode:
                                                         1'b1: Bus Clear Feature is enabled. */
        uint32_t reserved12_15                : 4;
        uint32_t optional_sar_ctrl            : 1;  /*!< R_W, Enables the usage of IC_OPTIONAL_SAR register. */
        uint32_t smbus_slave_quick_en         : 1;  /*!< R_W, If this bit is set to 1, i2c_v151 slave only receives
                                                         Quick commands in SMBus Mode. */
        uint32_t smbus_arp_en                 : 1;  /*!< R_W, This bit controls whether i2c_v151 should enable
                                                         Address Resolution Logic in SMBus Mode. */
        uint32_t smbus_persistent_slv_addr_en : 1;  /*!< R_W, The bit controls to enable i2c_v151 slave as persistent
                                                         or non persistent. If the slave is non-PSA then i2c_v151
                                                         slave device clears the Address valid flag for both General and
                                                         Directed Reset ARP command else the address valid flag will
                                                         always set to 1. This bit is applicable only in Slave mode.
                                                         1: SMBus Persistent Slave address control is enabled.
                                                         0: SMBus Persistent Slave address control is disabled. */
        uint32_t reserved20_31                : 12;
    } b;                                           /*!< Register bits. */
} ic_v151_con_data_t;

/**
 * @brief  This union represents the bit fields in the i2c target address
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_tar_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_tar           : 10; /*!< This is the target address for any master transaction. When
                                             transmitting a General Call, these bits are ignored. To generate a
                                             START BYTE, the CPU needs to write only once into these bits. */
        uint32_t gc_or_start      : 1;  /*!< If bit 11 (SPECIAL) is set to 1, then this bit indicates whether a
                                             General Call or START byte command is to be performed by the
                                             i2c_v151.
                                             0: General Call Address – after issuing a General Call, only writes
                                             may be performed. Attempting to issue a read command results in
                                             setting bit 6 (TX_ABRT) of the IC_RAW_INTR_STAT register. The
                                             i2c_v151 remains in General Call mode until the SPECIAL bit
                                             value (bit 11) is cleared.
                                             1: START BYTE. */
        uint32_t special          : 1;  /*!< This bit indicates whether software performs a General Call or
                                             START BYTE command.
                                             0: ignore bit 10 GC_OR_START and use IC_TAR normally
                                             1: perform special I2C command as specified in GC_OR_START bit. */
        uint32_t master_10bitaddr : 1;  /*!< This bit controls whether the i2c_v151 starts its transfers in 7-or
                                             10-bit addressing mode when acting as a master.
                                             0: 7-bit addressing
                                             1: 10-bit addressing
                                             Dependencies: This bit exists in this register only if the
                                             I2C_DYNAMIC_TAR_UPDATE configuration parameter is set to “Yes” (1). */
        uint32_t device_id        : 1;  /*!< R_W, If bit 11 (SPECIAL) is set to 1, then this bit indicates whether
                                             a Device-ID of a particular slave mentioned in IC_TAR[9:0] is
                                             to be performed by the i2c_v151 Master. */
        uint32_t reserved14_15    : 2;
        uint32_t smbus_quick_cmd  : 1;  /*!< R_W, If bit 11 (SPECIAL) is set to 1, then this bit indicates whether
                                             a Quick command is to be performed by the i2c_v151. */
        uint32_t reserved17_31    : 15;
    } b;                                /*!< Register bits. */
} ic_v151_tar_data_t;

/**
 * @brief  This union represents the bit fields in the i2c slave address
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_sar_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_sar           : 10; /*!< The IC_SAR holds the slave address when the I2C is operating as a slave.
                                             For 7-bit addressing, only IC_SAR[6:0] is used.
                                             This register can be written only when the I2C interface is disabled,
                                             which corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect. The default values cannot be
                                             any of the reserved address locations:
                                             that is, 0x00 to 0x07, or 0x78 to 0x7f. The correct operation of the
                                             device is not guaranteed if you program the IC_SAR or IC_TAR to a
                                             reserved value. */
        uint32_t reserved10_31    : 22;
    } b;                                /*!< Register bits. */
} ic_v151_sar_data_t;

/**
 * @brief  This union represents the bit fields in the i2c high speed master code addr
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_hs_maddr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_hs_mar        : 3;  /*!< This bit field holds the value of the I2C HS mode master code.
                                             HS-mode master codes are reserved 8-bit codes (00001xxx)
                                             that are not used for slave addressing or other purposes.
                                             Each master has its unique master code;
                                             up to eight highspeed mode masters can be
                                             present on the same I2C bus system.
                                             Valid values are from 0 to 7.
                                             This register goes away and becomes read-only returning 0’s if
                                             the IC_MAX_SPEED_MODE configuration parameter is set to either Standard
                                             (1) or Fast (2).
                                             This register can be written only when the I2C interface is disabled,
                                             which corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect. */
        uint32_t reserved3_31     : 29;
    } b;                                /*!< Register bits. */
} ic_v151_hs_maddr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c rx/tx data buffer and command
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_data_cmd_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t dat              : 8;  /*!< This register contains the data to be transmitted or received
                                             on the I2C bus. If you are writing to this register and want
                                             to perform a read, bits 7:0 (DAT) are ignored by the i2c_v151.
                                             However, when you read this register,
                                             these bits return the value of data
                                             received on the i2c_v151 interface. */
        uint32_t cmd              : 1;  /*!< This bit controls whether a read or a write is performed.
                                             This bit does not control the direction when the i2c_v151
                                             acts as a slave. It controls only the direction when it acts as a master.
                                             • 1 = Read
                                             • 0 = Write
                                             When a command is entered in the TX FIFO,
                                             this bit distinguishes the write and read commands.
                                             In slave-receiver mode, this bit is a “don’t care” because writes to this
                                             register are not required. In slave-transmitter mode,
                                             a “0” indicates that the data in IC_DATA_CMD is to be transmitted.
                                             When programming this bit, you should remember the following:
                                             attempting to perform a read operation after a General Call command
                                             has been sent results in a TX_ABRT interrupt
                                             (bit 6 of the IC_RAW_INTR_STAT register),
                                             unless bit 11 (SPECIAL) in the IC_TAR register has been cleared.
                                             If a “1” is written to this bit after receiving a RD_REQ interrupt,
                                             then a TX_ABRT interrupt occurs. */
        uint32_t stop             : 1;  /*!< This bit controls whether a STOP is issued after the byte is
                                             sent or received. This bit is available only if
                                             IC_EMPTYFIFO_HOLD_MASTER_EN is configured to 1.
                                             • 1 – STOP is issued after this byte, regardless of whether or not
                                             the Tx FIFO is empty. If the Tx FIFO is not empty,
                                             the master immediately tries to start a new
                                             transfer by issuing a START and arbitrating for the bus.
                                             • 0 – STOP is not issued after this byte, regardless of whether or not
                                             the Tx FIFO is empty. If the Tx FIFO is not empty, the master continues
                                             the current transfer by
                                             sending/receiving data bytes according to the value of the CMD bit.
                                             If the Tx FIFO is empty, the master holds the SCL line low and stalls
                                             the bus until a new command is available in the Tx FIFO. */
        uint32_t restart          : 1;  /*!< This bit controls whether a RESTART is issued before
                                             the byte is sent or received. This bit is available only
                                             if IC_EMPTYFIFO_HOLD_MASTER_EN is configured to 1.
                                             • 1 – If IC_RESTART_EN is 1, a RESTART is issued before the data is
                                             sent/received (according to the value of CMD),
                                             regardless of whether or not the transfer direction
                                             is changing from the previous command; if IC_RESTART_EN
                                             is 0, a STOP followed by a START is issued instead.
                                             • 0 – If IC_RESTART_EN is 1, a RESTART is issued only
                                             if the transfer direction is changing from the previous command;
                                             if IC_RESTART_EN is 0, a STOP followed by a START is issued instead. */
        uint32_t first_data_byte  : 1;  /*!< R, Indicates the first data byte  received after the address phase
                                             for receive transfer in Master receiver or Slave receiver mode. */
        uint32_t reserved12_31    : 20;
    } b;                                /*!< Register bits. */
} ic_v151_data_cmd_data_t;

/**
 * @brief  This union represents the bit fields in the i2c standard speed clock scl high count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_ss_scl_hcnt_ic_ufm_scl_hcnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_ss_scl_hcnt   : 16;  /*!< This register must be set before any I2C bus transaction can
                                              take place to ensure proper I/O timing. This register sets the
                                              SCL clock high-period count for standard speed. For more information,
                                              refer to "IC_CLK Frequency Configuration".This register can be written
                                              only when the I2C interface is disabled which corresponds to the
                                              IC_ENABLE[0] register being set to 0. Writes at other times have no
                                              effect. The minimum valid value is 6; hardware prevents values less
                                              than this being written, and if attempted results in 6 being
                                              set. For designs with APB_DATA_WIDTH = 8, the order of
                                              programming is important to ensure the correct operation of
                                              the i2c_v151. The lower byte must be programmed first.
                                              Then the upper byte is programmed. When the configuration parameter
                                              IC_HC_COUNT_VALUES is set to 1, this register is read only. */
        uint32_t reserved16_31    : 16;
    } ss_b;                                /*!< Register bits. */

    struct {
        uint32_t ic_ufm_scl_hcnt   : 16;  /*!< This register must be set before any I2C bus transaction can
                                               take place to ensure proper I/O timing. This register sets the
                                               SCL clock high-period count for Ultra-Fast speed. For more
                                               information, refer to "IC_CLK Frequency Configuration".
                                               This register can be written only when the I2C interface is
                                               disabled which corresponds to the IC_ENABLE[0] register
                                               being set to 0. Writes at other times have no effect.
                                               The minimum valid value is 3; hardware prevents values less
                                               than this being written, and if attempted results in 3 being
                                               set. For designs with APB_DATA_WIDTH = 8, the order of
                                               programming is important to ensure the correct operation of
                                               the i2c_v151. The lower byte must be programmed first.
                                               Then the upper byte is programmed. When the configuration
                                               parameter IC_HC_COUNT_VALUES is set to 1, this register
                                               is read only. */
        uint32_t reserved16_31    : 16;
    } ufm_b;
} ic_v151_ss_scl_hcnt_ic_ufm_scl_hcnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c standard speed clock scl low count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_ss_scl_lcnt_ic_ufm_scl_lcnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_ss_scl_lcnt   : 16;  /*!< This register must be set before any I2C bus transaction
                                             can take place to ensure proper I/O timing.
                                             This register sets the SCL clock low period count for standard speed.
                                             This register can be written only when the I2C interface is disabled which
                                             corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect.
                                             The minimum valid value is 8;
                                             hardware prevents values less than this being written,
                                             and if attempted, results in 8 being set. For designs with
                                             APB_DATA_WIDTH = 8, the order of programming is important to ensure the
                                             correct operation of i2c_v151. The lower byte must be programmed first,
                                             and then the upper byte is programmed.
                                             When the configuration parameter IC_HC_COUNT_VALUES is set to 1, this
                                             register is read only. */
        uint32_t reserved16_31    : 16;
    } ss_b;                                /*!< Register bits. */

    struct {
        uint32_t ic_ufm_scl_lcnt  : 16;  /*!< * Varies, This register must be set before any I2C bus transaction can
                                                take place to ensure proper I/O timing.  This register sets the
                                                SCL clock low period count for Ultra-Fast speed.
                                                This register can be written only when the I2C interface is
                                                disabled which corresponds to the IC_ENABLE[0] register
                                                being set to 0. Writes at other times have no effect.
                                                The minimum valid value is 5; hardware prevents values less
                                                than this being written, and if attempted, results in 5 being
                                                set. For designs with APB_DATA_WIDTH = 8, the order of
                                                programming is important to ensure the correct operation of
                                                i2c_v151. The lower byte must be programmed first, and
                                                then the upper byte is programmed. When the configuration
                                                parameter IC_HC_COUNT_VALUES is set to 1, this register
                                                is read only. */
        uint32_t reserved16_31    : 16;
    } ufm_b;                             /*!< Register bits. */
} ic_v151_ss_scl_lcnt_ic_ufm_scl_lcnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c fast speed clock scl high count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_fs_scl_hcnt_ic_ufm_tbuf_cnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_fs_scl_hcnt   : 16;  /*!< This register must be set before any I2C bus transaction
                                             can take place to ensure proper I/O timing.
                                             This register sets the SCL clock high-period count for fast speed.
                                             It is used in high-speed mode to send the Master Code and
                                             START BYTE or General CALL. This register goes away and becomes
                                             read-only returning 0s if IC_MAX_SPEED_MODE = standard.
                                             This register can be written only when the I2C interface is disabled,
                                             which corresponds to the IC_ENABLE register
                                             being set to 0. Writes at other times have no effect.
                                             The minimum valid value is 6; hardware prevents values less than this
                                             being written, and if attempted results in 6 being set. For designs with
                                             APB_DATA_WIDTH == 8 the order of programming is important to ensure the
                                             correct operation of the i2c_v151. The lower byte must be programmed
                                             first. Then the upper byte is programmed.
                                             When the configuration parameter IC_HC_COUNT_VALUES is set to 1, this
                                             register is read only. */
        uint32_t reserved16_311    : 16;
    } fs_b;                               /*!< Register bits. */

    struct {
        uint32_t ic_ufm_tbuf_cnt  : 16;  /*!< R_W, This register must be set before any I2C bus transaction can
                                           take place to ensure proper I/O timing. This register must be set before any
                                           I2C bus transaction can take place to ensure proper I/O timing.
                                           This register sets the Bus-Free time between a STOP and STOP condition count
                                           for Ultra-Fast speed.
                                           This register can be written only when the I2C interface is
                                           disabled which corresponds to the IC_ENABLE[0] register
                                           being set to 0. Writes at other times have no effect.
                                           For designs with APB_DATA_WIDTH = 8, the order of
                                           programming is important to ensure the correct operation of
                                           the i2c_v151. The lower byte must be programmed first
                                           and then the upper byte is programmed. When the configuration parameter. */
        uint32_t reserved16_31    : 16;
    } ufm_b;                               /*!< Register bits. */
} ic_v151_fs_scl_hcnt_ic_ufm_tbuf_cnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c fast speed clock scl low count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_fs_scl_lcnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_fs_scl_lcnt   : 16;  /*!< This register must be set before any I2C bus transaction
                                             can take place to ensure proper I/O timing.
                                             This register sets the SCL clock low period count for fast speed.
                                             It is used in high-speed mode to send the Master Code and
                                             START BYTE or General CALL. This register goes away and
                                             becomes read-only returning 0s if IC_MAX_SPEED_MODE = standard.
                                             This register can be written only when the I2C interface is disabled,
                                             which corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect.
                                             The minimum valid value is 8; hardware prevents values less than this
                                             being written, and if attempted results in 8 being set. For designs with
                                             APB_DATA_WIDTH = 8 the order of programming is important to ensure the
                                             correct operation of the i2c_v151. The lower byte must be programmed
                                             first. Then the upper byte is programmed. If the value is less than 8
                                             then the count value gets changed to 8.
                                             When the configuration parameter IC_HC_COUNT_VALUES is set to 1, this
                                             register is read only. */
    } b;                                /*!< Register bits. */
} ic_v151_fs_scl_lcnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c high speed clock scl high count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_hs_scl_hcnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_hs_scl_hcnt   : 16;  /*!< This register must be set before any I2C bus transaction can
                                             take place to ensure proper I/O timing.
                                             This register sets the SCL clock high period count for high speed.
                                             The SCL High time depends on the loading of the bus. For 100pF loading,
                                             the SCL High time is 60ns; for 400pF loading, the SCL High time is 120ns.
                                             This register goes away and becomes read-only returning 0s if
                                             IC_MAX_SPEED_MODE != high.
                                             This register can be written only when the I2C interface is disabled,
                                             which corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect. The minimum valid value is 6;
                                             hardware prevents values less than this being written,
                                             and if attempted results in 6 being set. For designs with
                                             APB_DATA_WIDTH = 8 the order of programming is important to ensure the
                                             correct operation of the i2c_v151. The lower byte must be programmed
                                             first. Then the upper byte is programmed.
                                             When the configuration parameter IC_HC_COUNT_VALUES is set to 1, this
                                             register is read only. */
    } b;                                /*!< Register bits. */
} ic_v151_hs_scl_hcnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c high speed clock scl low count
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_hs_scl_lcnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_hs_scl_lcnt   : 16; /*!< This register must be set before any I2C bus transaction can
                                             take place to ensure proper I/O timing.
                                             This register sets the SCL clock low period count for high speed.
                                             The SCL low time depends on the loading of the bus. For 100pF loading,
                                             the SCL low time is 160ns; for 400pF loading, the SCL low time is 320ns.
                                             This register goes away and becomes read-only returning 0s if
                                             IC_MAX_SPEED_MODE != high. This register can be written only when
                                             the I2C interface is disabled, which
                                             corresponds to the IC_ENABLE register being set to 0.
                                             Writes at other times have no effect.
                                             The minimum valid value is 8; hardware prevents values less than
                                             this being written, and if attempted results in 8 being set.
                                             For designs with APB_DATA_WIDTH == 8 the order of programming
                                             is important to ensure the correct operation of the i2c_v151.
                                             The lower byte must be programmed first.
                                             Then the upper byte is programmed. If the value is less
                                             than 8 then the count value gets changed to 8. When the configuration
                                             parameter IC_HC_COUNT_VALUES is set to 1, this register is read only. */
    } b;                                /*!< Register bits. */
} ic_v151_hs_scl_lcnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c interrupt status
 *         Register. Each bit in this register has a corresponding mask bit in the IC_INTR_MASK register.
 *         These bits are cleared by reading the matching interrupt clear register.
 *         The unmasked raw versions of these bits are available in the IC_RAW_INTR_STAT register.
 *         See “IC_RAW_INTR_STAT” for a detailed description of these bits
 */
typedef union ic_v151_intr_stat_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t r_rx_under         : 1;  /*!< r_rx_under status */
        uint32_t r_rx_over          : 1;  /*!< r_rx_over status */
        uint32_t r_rx_full          : 1;  /*!< r_rx_full status */
        uint32_t r_tx_over          : 1;  /*!< r_tx_over status */
        uint32_t r_tx_empty         : 1;  /*!< r_tx_empty status */
        uint32_t r_rd_req           : 1;  /*!< r_rd_req status */
        uint32_t r_tx_abrt          : 1;  /*!< r_tx_abrt status */
        uint32_t r_rx_done          : 1;  /*!< r_rx_done status */
        uint32_t r_activity         : 1;  /*!< r_activity status */
        uint32_t r_stop_det         : 1;  /*!< r_stop_det status */
        uint32_t r_start_det        : 1;  /*!< r_start_det status */
        uint32_t r_gen_call         : 1;  /*!< r_den_call status */
        uint32_t r_restart_det      : 1;  /*!< r_restart_det status */
        uint32_t r_master_on_hold   : 1;  /*!< r_master_on_hold status */
        uint32_t r_scl_stuck_at_low : 1;  /*!< m_scl_stuck_at_low status */
        uint32_t reserved15_31      : 17;
    } b;                                /*!< Register bits. */
} ic_v151_intr_stat_data_t;

/**
 * @brief  This union represents the bit fields in the i2c interrupt mask
 *         Register. These bits mask their corresponding interrupt status bits.
 *         This register is active low; a value of 0 masks the interrupt,
 *         whereas a value of 1 unmasks the interrupt.
 *         These bits mask their corresponding interrupt status bits in the
 *         IC_INTR_STAT register.
 */
typedef union ic_v151_intr_mask_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t m_rx_under         : 1;  /*!< m_rx_under mask */
        uint32_t m_rx_over          : 1;  /*!< m_rx_over mask */
        uint32_t m_rx_full          : 1;  /*!< m_rx_full mask */
        uint32_t m_tx_over          : 1;  /*!< m_tx_over mask */
        uint32_t m_tx_empty         : 1;  /*!< m_tx_empty mask */
        uint32_t m_rd_req           : 1;  /*!< m_rd_req mask */
        uint32_t m_tx_abrt          : 1;  /*!< m_tx_abrt mask */
        uint32_t m_rx_done          : 1;  /*!< m_rx_done mask */
        uint32_t m_activity         : 1;  /*!< m_activity mask */
        uint32_t m_stop_det         : 1;  /*!< m_stop_det mask */
        uint32_t m_start_det        : 1;  /*!< m_start_det mask */
        uint32_t m_gen_call         : 1;  /*!< m_den_call mask */
        uint32_t m_restart_det      : 1;  /*!< m_restart_det status */
        uint32_t m_master_on_hold   : 1;  /*!< m_master_on_hold status */
        uint32_t m_scl_stuck_at_low : 1;  /*!< m_scl_stuck_at_low status */
        uint32_t reserved15_31      : 17;
    } b;                                /*!< Register bits. */
} ic_v151_intr_mask_data_t;

/**
 * @brief  This union represents the bit fields in the i2c raw interrupt status
 *         Register. Unlike the IC_INTR_STAT register, these bits are not masked so
 *         they always show the true status of the i2c_v151
 */
typedef union ic_v151_raw_intr_stat_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rx_under         : 1;  /*!< Set if the processor attempts to read the receive buffer
                                             when it is empty by reading from the IC_DATA_CMD register.
                                             If the module is disabled (IC_ENABLE[0]=0),
                                             this bit keeps its level until the master or slave state
                                             machines go into idle, and when ic_en goes to 0,
                                             this interrupt is cleared.  */
        uint32_t rx_over          : 1;  /*!< Set if the receive buffer is completely filled to IC_RX_BUFFER_DEPTH
                                             and an additional byte is received from an external I2C device.
                                             The i2c_v151 acknowledges this,
                                             but any data bytes received after the FIFO is full are lost.
                                             If the module is disabled (IC_ENABLE[0]=0),
                                             this bit keeps its level until the master or slave state machines
                                             go into idle, and when ic_en goes to 0, this interrupt is cleared. */
        uint32_t rx_full          : 1;  /*!< Set when the receive buffer reaches or
                                             goes above the RX_TL threshold in the IC_RX_TL register.
                                             It is automatically cleared by hardware when buffer level goes
                                             below the threshold. If the module is disabled (IC_ENABLE[0]=0),
                                             the RX FIFO is flushed and held in reset;
                                             therefore the RX FIFO is not full. So this bit is cleared
                                             once the IC_ENABLE bit 0 is programmed with a 0,
                                             regardless of the activity that continues */
        uint32_t tx_over          : 1;  /*!< Set during transmit if the transmit buffer is filled to IC_TX_BUFFER_DEPTH
                                             and the processor attempts to issue another I2C command by writing to the
                                             IC_DATA_CMD register. When the module is disabled,
                                             this bit keeps its level until the master or
                                             slave state machines go into idle, and when ic_en goes to 0,
                                             this interrupt is cleared. */
        uint32_t tx_empty         : 1;  /*!< This bit is set to 1 when the transmit buffer is at or
                                             below the threshold value set in the IC_TX_TL register.
                                             It is automatically cleared by hardware when the buffer
                                             level goes above the threshold. When the IC_ENABLE bit 0 is 0,
                                             the TX FIFO is flushed and held in reset.
                                             There the TX FIFO looks like it has no data within it,
                                             so this bit is set to 1,
                                             provided there is activity in the master or slave state machines.
                                             When there is no longer activity, then with ic_en=0,
                                             this bit is set to 0. */
        uint32_t rd_req           : 1;  /*!< This bit is set to 1 when i2c_v151 is acting as a slave and
                                             another I2C master is attempting to read data from i2c_v151.
                                             The i2c_v151 holds the I2C bus in a wait state (SCL=0)
                                             until this interrupt is serviced, which means that the slave
                                             has been addressed by a remote master
                                             that is asking for data to be transferred.
                                             The processor must respond to this interrupt and then
                                             write the requested data to the IC_DATA_CMD register.
                                             This bit is set to 0 just after the processor reads the
                                             IC_CLR_RD_REQ register. */
        uint32_t tx_abrt          : 1;  /*!< This bit indicates if i2c_v151, as an I2C transmitter,
                                             is unable to complete the intended actions on the contents of
                                             the transmit FIFO. This situation can occur both as an I2C master
                                             or an I2C slave, and is referred to as a “transmit abort”.
                                             When this bit is set to 1, the IC_TX_ABRT_SOURCE register indicates the
                                             reason why the transmit abort takes places. */
        uint32_t rx_done          : 1;  /*!< When the i2c_v151 is acting as a slave-transmitter,
                                             this bit is set to 1 if the master does not acknowledge a
                                             transmitted byte. This occurs on the last byte of the transmission,
                                             indicating that the transmission is done. */
        uint32_t activity         : 1;  /*!< This bit captures i2c_v151 activity and stays set until it is cleared.
                                             There are four ways to clear it:
                                             • Disabling the i2c_v151
                                             • Reading the IC_CLR_ACTIVITY register
                                             • Reading the IC_CLR_INTR register
                                             • System reset
                                             Once this bit is set, it stays set unless one of the four methods
                                             is used to clear it. Even if the i2c_v151 module is idle,
                                             this bit remains set until cleared,
                                             indicating that there was activity on the bus */
        uint32_t stop_det         : 1;  /*!< Indicates whether a STOP condition has occurred on the I2C interface
                                             regardless of whether i2c_v151 is operating in slave or master mode */
        uint32_t start_det        : 1;  /*!< Indicates whether a START or RESTART condition has occurred on the I2C
                                             interface regardless of
                                             whether i2c_v151 is operating in slave or master mode. */
        uint32_t gen_call         : 1;  /*!< Set only when a General Call address is received and it is acknowledged.
                                             It stays set until it is cleared either by
                                             disabling i2c_v151 or when the CPU reads bit 0 of the
                                             IC_CLR_GEN_CALL register. i2c_v151 stores the received data in the
                                             Rx buffer. */
        uint32_t restart_det      : 1;  /*!< Indicates whether a RESTART condition has occurred on the
                                             I2C interface  when i2c_v151 is operating in Slave mode
                                             and the slave is being addressed. */
        uint32_t master_on_hold   : 1;  /*!< Indicates whether master is holding the bus and TX FIFO is
                                             empty. */
        uint32_t scl_stuck_at_low : 1;  /*!< Indicates whether the SCL Line is stuck at low for the
                                             IC_SCL_STUCK_LOW_TIMEOUT number of ic_clk periods. */
        uint32_t reserved15_31    : 17;
    } b;                                /*!< Register bits. */
} ic_v151_raw_intr_stat_data_t;

/**
 * @brief  This union represents the bit fields in the i2c receive fifo threshold
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_rx_tl_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rx_tl            : 8;  /*!< Receive FIFO Threshold Level Controls the level of entries (or above)
                                             that triggers the RX_FULL interrupt (bit 2 in IC_RAW_INTR_STAT register).
                                             The valid range is 0-255, with the additional restriction that
                                             hardware does not allow this value to be set to a value larger than
                                             the depth of the buffer. If an attempt is made to do that,
                                             the actual value set will be the maximum depth of the buffer.
                                             A value of 0 sets the threshold for 1 entry,
                                             and a value of 255 sets the threshold for 256 entries. */
        uint32_t reserved8_31     : 24;
    } b;                                /*!< Register bits. */
} ic_v151_rx_tl_data_t;

/**
 * @brief  This union represents the bit fields in the i2c transmit fifo threshold
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_tx_tl_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t tx_tl            : 8;  /*!< Transmit FIFO Threshold Level
                                             Controls the level of entries (or below) that
                                             trigger the TX_EMPTY interrupt (bit 4 in IC_RAW_INTR_STAT register).
                                             The valid range is 0-255, with the additional restriction that
                                             it may not be set to value larger than the depth of the buffer.
                                             If an attempt is made to do that,
                                             the actual value set will be the maximum depth of the buffer.
                                             A value of 0 sets the threshold for 0 entries,
                                             and a value of 255 sets the threshold for 255 entries. */
        uint32_t reserved8_31     : 24;
    } b;                                /*!< Register bits. */
} ic_v151_tx_tl_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear combined and individual interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_intr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_rx_under     : 1;  /*!< Read this register to clear the combined interrupt,
                                         all individual interrupts, and the IC_TX_ABRT_SOURCE register.
                                         This bit does not clear hardware clearable interrupts
                                         but software clearable interrupts. Refer to Bit 9 of the
                                         IC_TX_ABRT_SOURCE register for an exception to clearing
                                         IC_TX_ABRT_SOURCE. */
        uint32_t clr_rx_over      : 1;  /*!< Read this register to clear the RX_OVER interrupt
                                         (bit 1) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved8_31     : 24;
        uint32_t clr_tx_over      : 1;  /*!< Read this register to clear the TX_OVER interrupt
                                             (bit 3) of the IC_RAW_INTR_STAT register. */
        uint32_t clr_rd_req       : 1;  /*!< Read this register to clear the RD_REQ interrupt
                                             (bit 5) of the IC_RAW_INTR_STAT register. */
        uint32_t clr_tx_abrt      : 1;  /*!< Read this register to clear the TX_ABRT interrupt
                                             (bit 6) of the IC_RAW_INTR_STAT register,
                                             and the IC_TX_ABRT_SOURCE register.
                                             This also releases the TX FIFO from the flushed/reset state,
                                             allowing more writes to the TX FIFO. */
        uint32_t clr_rx_done      : 1;  /*!< Read this register to clear the RX_DONE interrupt
                                             (bit 7) of the IC_RAW_INTR_STAT register. */
        uint32_t clr_activity    : 1;  /*!< Reading this register clears the ACTIVITY interrupt
                                             if the I2C is not active anymore.
                                             If the I2C module is still active on the bus,
                                             the ACTIVITY interrupt bit continues to be set.
                                             It is automatically cleared by hardware if the module
                                             is disabled and if there is no further activity on the bus.
                                             The value read from this register to get status of
                                             the ACTIVITY interrupt (bit 8) of the IC_RAW_INTR_STAT register. */
        uint32_t clr_stop_det     : 1;  /*!< Read this register to clear the STOP_DET interrupt
                                             (bit 9) of the IC_RAW_INTR_STAT register */
        uint32_t clr_start_det    : 1;  /*!< Read this register to clear the START_DET interrupt
                                             (bit 10) of the IC_RAW_INTR_STAT register */
        uint32_t clr_gen_call     : 1;  /*!< Read this register to clear the GEN_CALL interrupt
                                             (bit 11) of the IC_RAW_INTR_STAT register */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_intr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear combined and individual interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_int_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_int         : 1;  /*!< Read this register to clear the combined interrupt,
                                             all individual interrupts, and the
                                             IC_TX_ABRT_SOURCE register. This bit does not clear hardware clearable
                                             interrupts but software clearable interrupts. Refer to Bit 9 of the
                                             IC_TX_ABRT_SOURCE register for an exception to clearing
                                             IC_TX_ABRT_SOURCE. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_int_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear rx_under interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_rx_under_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_rx_under     : 1;  /*!< Read this register to clear the combined interrupt,
                                         all individual interrupts, and the IC_TX_ABRT_SOURCE register.
                                         This bit does not clear hardware clearable interrupts
                                         but software clearable interrupts. Refer to Bit 9 of the
                                         IC_TX_ABRT_SOURCE register for an exception to clearing
                                         IC_TX_ABRT_SOURCE. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_rx_under_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear rx_over interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_rx_over_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_rx_over      : 1;  /*!< Read this register to clear the RX_OVER interrupt
                                         (bit 1) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_rx_over_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear tx_over interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_tx_over_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_tx_over      : 1;  /*!< Read this register to clear the TX_OVER interrupt
                                             (bit 3) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_tx_over_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear rd_req interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_rd_req_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_rd_req       : 1;  /*!< Read this register to clear the RD_REQ interrupt
                                             (bit 5) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_rd_req_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear tx_abrt interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_tx_abrt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_tx_abrt      : 1;  /*!< Read this register to clear the TX_ABRT interrupt
                                             (bit 6) of the IC_RAW_INTR_STAT register,
                                             and the IC_TX_ABRT_SOURCE register.
                                             This also releases the TX FIFO from the flushed/reset state,
                                             allowing more writes to the TX FIFO. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_tx_abrt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear rx_done interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_rx_done_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_rx_done      : 1;  /*!< Read this register to clear the RX_DONE interrupt
                                             (bit 7) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_rx_done_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear activity interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_activity_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_activity    : 1;  /*!< Reading this register clears the ACTIVITY interrupt
                                             if the I2C is not active anymore.
                                             If the I2C module is still active on the bus,
                                             the ACTIVITY interrupt bit continues to be set.
                                             It is automatically cleared by hardware if the module
                                             is disabled and if there is no further activity on the bus.
                                             The value read from this register to get status of
                                             the ACTIVITY interrupt (bit 8) of the IC_RAW_INTR_STAT register. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_activity_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear stop_det interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_stop_det_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_stop_det     : 1;  /*!< Read this register to clear the STOP_DET interrupt
                                             (bit 9) of the IC_RAW_INTR_STAT register */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_stop_det_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear start_det interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_start_det_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_start_det    : 1;  /*!< Read this register to clear the START_DET interrupt
                                             (bit 10) of the IC_RAW_INTR_STAT register */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_start_det_data_t;

/**
 * @brief  This union represents the bit fields in the i2c clear gen_call interrupt
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_clr_gen_call_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t clr_gen_call     : 1;  /*!< Read this register to clear the GEN_CALL interrupt
                                             (bit 11) of the IC_RAW_INTR_STAT register */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_clr_gen_call_data_t;

/**
 * @brief  This union represents the bit fields in the i2c enable
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_enable_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t enable                    : 1;  /*!< Controls whether the i2c_v151 is enabled.
                                                      0: Disables i2c_v151
                                                      1: Enables i2c_v151
                                                      Software can disable i2c_v151 while it is active.
                                                      However, it is important that care be
                                                      taken to ensure that i2c_v151 is disabled properly.
                                                      When i2c_v151 is disabled, the following occurs:
                                                      •The TX FIFO and RX FIFO get flushed.
                                                      •Status bits in the IC_INTR_STAT register are still active until
                                                      i2c_v151 goes into IDLE state.
                                                      If the module is transmitting,
                                                      it stops as well as deletes the contents of the transmit
                                                      buffer after the current transfer is complete.
                                                      If the module is receiving, the i2c_v151
                                                      stops the current transfer at the end of the current byte and
                                                      does not acknowledge the transfer.
                                                      In systems with asynchronous pclk and ic_clk when
                                                      IC_CLK_TYPE parameter set to asynchronous (1), there is a
                                                      two ic_clk delay when enabling or disabling the i2c_v151. */
        uint32_t abort                     : 1;  /*!< When set, the controller initiates the transfer abort. */
        uint32_t tx_cmd_block              : 1;  /*!< In Master mode:
                                                      1'b1: Blocks the transmission of data on I2C bus even if
                                                      Tx FIFO has data to transmit. */
        uint32_t sda_stuck_recovery_enable : 1;  /*!< if SDA is stuck at low indicated through the TX_ABORT
                                                      interrupt (IC_TX_ABRT_SOURCE[17]), then this bit is used
                                                      as a control knob to initiate the SDA Recovery Mechanism
                                                      (that is, send at most 9 SCL clocks and STOP to release the
                                                      SDA line) and then this bit gets auto clear */
        uint32_t reserved4_15 : 12;
        uint32_t smbus_clk_reset           : 1;  /*!< This bit is used in SMBus Host mode to initiate the SMBus
                                                     Master Clock Reset. */
        uint32_t smbus_suspend_en          : 1;  /*!< The SMBUS_SUSPEND_EN register bit is used to control
                                                      assertion and de-assertion of SMBSUS signal. */
        uint32_t smbus_alert_en            : 1;  /*!< The SMBUS_ALERT_CTRL register bit is used to control
                                                      assertion of SMBALERT signal. */
        uint32_t reserved19_31             : 13;
    } b;                                /*!< Register bits. */
} ic_v151_enable_data_t;

/**
 * @brief  This union represents the bit fields in the i2c status
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_status_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t activity                  : 1;  /*!< I2C Activity Status. */
        uint32_t tfnf                      : 1;  /*!< Transmit FIFO Not Full. Set when the transmit FIFO contains
                                                      one or more empty locations,
                                                      and is cleared when the FIFO is full.
                                                      0: Transmit FIFO is full
                                                      1: Transmit FIFO is not full */
        uint32_t tfe                       : 1;  /*!< Transmit FIFO Completely Empty.
                                                      When the transmit FIFO is completely empty, this bit is set.
                                                      When it contains one or more valid entries, this bit is cleared.
                                                      This bit field does not request an interrupt.
                                                      0: Transmit FIFO is not empty
                                                      1: Transmit FIFO is empty */
        uint32_t rfne                      : 1;  /*!< Receive FIFO Not Empty.
                                                      This bit is set when the receive FIFO contains one or more entries
                                                      it is cleared when the receive FIFO is empty.
                                                      0: Receive FIFO is empty
                                                      1: Receive FIFO is not empty */
        uint32_t rff                       : 1;  /*!< Receive FIFO Completely Full. When the receive FIFO is completely
                                                      full, this bit is set.
                                                      When the receive FIFO contains one or more empty location,
                                                      this bit is cleared.
                                                      0: Receive FIFO is not full
                                                      1: Receive FIFO is full */
        uint32_t mst_activity              : 1;  /*!< Master FSM Activity Status.
                                                      When the Master Finite State Machine (FSM) is not in the IDLE
                                                      state, this bit is set.
                                                      0: Master FSM is in IDLE state so the Master part of
                                                      i2c_v151 is not Active
                                                      1: Master FSM is not in IDLE state so the Master part of
                                                      i2c_v151 is Active */
        uint32_t slv_activity              : 1;  /*!< Slave FSM Activity Status. When the Slave Finite State Machine
                                                      (FSM) is not in the IDLE state, this bit is set.
                                                      0: Slave FSM is in IDLE state so the Slave part of
                                                      i2c_v151 is not Active
                                                      1: Slave FSM is not in IDLE state so the Slave part of
                                                      i2c_v151 is Active */
        uint32_t mst_hold_tx_fifo_empty    : 1;  /*!< If the IC_EMPTYFIFO_HOLD_MASTER_EN parameter is
                                                      set to 1, the i2c_v151 master stalls the write transfer
                                                      when Tx FIFO is empty, and the the last byte does not have
                                                      the Stop bit set. */
        uint32_t mst_hold_rx_fifo_full     : 1;  /*!< This bit indicates the BUS Hold in Master mode due to Rx
                                                      FIFO is Full and additional byte has been received (This
                                                      kind of Bus hold is applicable if
                                                      IC_RX_FULL_HLD_BUS_EN is set to 1). */
        uint32_t slv_hold_tx_fifo_empty    : 1;  /*!< This bit indicates the BUS Hold in Slave mode for the Read
                                                      request when the Tx FIFO is empty. */
        uint32_t slv_hold_rx_fifo_full     : 1;  /*!< This bit indicates the BUS Hold in Slave mode due to Rx
                                                      FIFO is Full and  an additional byte has been received (This
                                                      kind of Bus hold is applicable if
                                                      IC_RX_FULL_HLD_BUS_EN is set to 1). */
        uint32_t sda_stuck_not_recovered   : 1;  /*!< This bit indicates the BUS Hold in Slave mode due to Rx
                                                      FIFO is Full and an additional byte has been received (This
                                                      kind of Bus hold is applicable if
                                                      IC_RX_FULL_HLD_BUS_EN is set to 1) */
        uint32_t reserved12_15             : 4;
        uint32_t smbus_quick_cmd_bit       : 1;  /*!< This bit indicates the R/W bit of the Quick command
                                                      received. */
        uint32_t smbus_slave_addr_valid    : 1;  /*!< This bit indicates whether the slave address (ic_sar) is valid
                                                      or not. */
        uint32_t smbus_slave_addr_resolved : 1;  /*!< GEN_ERROR, GEN_ERROR */
        uint32_t smbus_suspend_status      : 1;  /*!< This bit indicates the status of the SMBus Suspend signal
                                                      (ic_smbsus_in_n). */
        uint32_t smbus_alert_status        : 1;  /*!< R, This bit indicates the status of the SMBus Alert signal
                                                    (ic_smbalert_in_n). */
        uint32_t reserved21_31             : 11;
    } b;                                /*!< Register bits. */
} ic_v151_status_data_t;

/**
 * @brief  This union represents the bit fields in the i2c transmit fifo level
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_txflr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t txflr;                 /*!< Transmit FIFO Level. Contains the number of valid data entries in the
                                             transmit FIFO. */
    } b;                                /*!< Register bits. */
} ic_v151_txflr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c receive fifo level
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_rxflr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rxflr;                 /*!< Receive FIFO Level. Contains the number of valid data entries in the
                                             receive FIFO. */
    } b;                                /*!< Register bits. */
} ic_v151_rxflr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c sda hold time length
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_sda_rx_hold_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t sda_rx_hold    : 8;    /*!< Sets the required SDA hold time  in units of ic_clk period,
                                             when i2c_v151 acts as a receiver. */
        uint32_t reserved8_31   : 24;
    } b;                                /*!< Register bits. */
} ic_v151_sda_rx_hold_data_t;

/**
 * @brief  This union represents the bit fields in the i2c sda hold time length
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_sda_tx_hold_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t sda_tx_hold    : 16;   /*!< Sets the required SDA hold time  in units of ic_clk period,
                                                when i2c_v151 acts as a transmitter. */
        uint32_t reserved16_31  : 16;
    } b;                                /*!< Register bits. */
} ic_v151_sda_tx_hold_data_t;

/**
 * @brief  This union represents the bit fields in the i2c transmit abort source
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_tx_flush_cnt_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t tx_flush_cnt         : 9;  /*!< This field indicates the  number of Tx FIFO Data Commands
                                                 which are flushed due to TX_ABRT interrupt. */
        uint32_t reserved9_31         : 23;
    } b;                                    /*!< Register bits. */
} ic_v151_tx_flush_cnt_data_t;

/**
 * @brief  This union represents the bit fields in the i2c transmit abort source
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_tx_abrt_source_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t user_abrt            : 1;  /*!< This is a master-mode-only bit. Master has detected the
                                                 transfer abort (IC_ENABLE[1]) */
        uint32_t sda_stuck_at_low     : 1;  /*!< This is a master-mode-only bit. Master detects the SDA
                                                 Stuck at low for the IC_SDA_STUCK_AT_LOW_TIMEOUT value of ic_clks. */
        uint32_t device_noack         : 1;  /*!< This is a master-mode-only bit.  Master is initiating the DEVICE_ID
                                                 transfer and the device id sent was not acknowledged by any slave */
        uint32_t device_slvaddr_noack : 1;  /*!< This is a master-mode-only bit. Master is initiating the
                                                 DEVICE_ID transfer and the slave address sent was not
                                                 acknowledged by any slave. */
        uint32_t abrt_device_write    : 1;  /*!< This is a master-mode-only bit. */
        uint32_t reserved5_31         : 27;
    } b;                                    /*!< Register bits. */
} ic_v151_tx_abrt_source_data_t;

/**
 * @brief  This union represents the bit fields in the i2c transmit abort source
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_abrt_slv_intx_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t addr_7b_noack        : 1;  /*!< 1: Master is in 7-bit addressing mode and the
                                                 address sent was not acknowledged by any slave. */
        uint32_t addr1_10b_noack      : 1;  /*!< 1: Master is in 10-bit addressing mode and the
                                                 address sent was not acknowledged by any slave. */
        uint32_t addr2_10b_noack      : 1;  /*!< 1: Master is in 10-bit address mode and the
                                                 second address byte of the 10-bit address
                                                 was not acknowledged by any slave. */
        uint32_t txdata_noack         : 1;  /*!< 1: This is a master-mode only bit. Master has
                                                 received an acknowledgement for the
                                                 address, but when it sent data byte(s)
                                                 following the address, it did not receive an
                                                 acknowledge from the remote slave(s). */
        uint32_t gcall_noack          : 1;  /*!< 1: i2c_v151 in master mode sent a
                                                 General Call and no slave on the bus
                                                 acknowledged the General Call. */
        uint32_t gcalll_read          : 1;  /*!< 1: i2c_v151 in master mode sent a
                                                 General Call but the user programmed the
                                                 byte following the General Call to be a read
                                                 from the bus (IC_DATA_CMD[9] is set to 1). */
        uint32_t hs_ackdet            : 1;  /*!< 1: Master is in High Speed mode and the High
                                                 Speed Master code was acknowledged (wrong behavior). */
        uint32_t sbyte_ackdet         : 1;  /*!< 1: Master has sent a START Byte and the
                                                 START Byte was acknowledged (wrong behavior). */
        uint32_t hs_norstrt           : 1;  /*!< 1: The restart is disabled (IC_RESTART_EN
                                                 bit (IC_CON[5]) = 0) and the user is trying to
                                                 use the master to transfer data in High Speed
                                                 mode. */
        uint32_t sbyte_norstrt        : 1;  /*!< To clear Bit 9, the source of the
                                                 ABRT_SBYTE_NORSTRT must be fixed first;
                                                 restart must be enabled (IC_CON[5]=1), the
                                                 SPECIAL bit must be cleared (IC_TAR[11]), or
                                                 the GC_OR_START bit must be cleared
                                                 (IC_TAR[10]). Once the source of the
                                                 ABRT_SBYTE_NORSTRT is fixed, then this
                                                 bit can be cleared in the same manner as
                                                 other bits in this register. If the source of the
                                                 ABRT_SBYTE_NORSTRT is not fixed before
                                                 attempting to clear this bit, bit 9 clears for one
                                                 cycle and then gets re-asserted.
                                                 1: The restart is disabled (IC_RESTART_EN
                                                 bit (IC_CON[5]) = 0) and the user is trying to
                                                 send a START Byte. */
        uint32_t rd_10b_norstrt       : 1;  /*!< 1: The restart is disabled (IC_RESTART_EN
                                                 bit (IC_CON[5]) = 0) and the master sends a
                                                 read command in 10-bit addressing mode. */
        uint32_t master_dis           : 1;  /*!< 1: User tries to initiate a Master operation with
                                                 the Master mode disabled. */
        uint32_t lost                 : 1;  /*!< 1: Master has lost arbitration, or if
                                                 IC_TX_ABRT_SOURCE[14] is also set, then
                                                 the slave transmitter has lost arbitration.
                                                 Note: I2C can be both master and slave at the
                                                 same time. */
        uint32_t slvflush_txfifo      : 1;  /*!< 1: Slave has received a read command and
                                                 some data exists in the TX FIFO so the slave
                                                 issues a TX_ABRT interrupt to flush old data
                                                 in TX FIFO. */
        uint32_t slv_arblost          : 1;  /*!< 1: Slave lost the bus while transmitting data to
                                                 a remote master. IC_TX_ABRT_SOURCE[12]
                                                 is set at the same time.
                                                 Note: Even though the slave never “owns” the
                                                 bus, something could go wrong on the bus.
                                                 This is a fail safe check. For instance, during a
                                                 data transmission at the low-to-high transition
                                                 of SCL, if what is on the data bus is not what is
                                                 supposed to be transmitted, then i2c_v151
                                                 no longer own the bus. */
        uint32_t slvrd_intx           : 1;  /*!< 1: When the processor side responds to a
                                                 slave mode request for data to be transmitted
                                                 to a remote master and user writes a 1 in
                                                 CMD (bit 8) of IC_DATA_CMD register. */
        uint32_t reserved16_31        : 16;
    } b;                                    /*!< Register bits. */
} ic_v151_abrt_slv_intx_data_t;

/**
 * @brief  This union represents the bit fields in the i2c generate slave data nack
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_slv_data_nack_only_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t nack             : 1;  /*!< Generate NACK. This NACK generation only occurs when i2c_v151
                                             is a slavereceiver. If this register is set to a value of 1,
                                             it can only generate a NACK after a data byte is received; hence,
                                             the data transfer is aborted and the data received is
                                             not pushed to the receive buffer.
                                             When the register is set to a value of 0, it generates NACK/ACK,
                                             depending on normal criteria.
                                             1 = generate NACK after data byte received
                                             0 = generate NACK/ACK normally */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_slv_data_nack_only_data_t;

/**
 * @brief  This union represents the bit fields in the i2c dma control
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_dma_cr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t rdmae            : 1;  /*!< Receive DMA Enable.
                                             This bit enables/disables the receive FIFO DMA channel.
                                             0 = Receive DMA disabled
                                             1 = Receive DMA enabled */
        uint32_t tdmae            : 1;  /*!< Transmit DMA Enable.
                                             This bit enables/disables the transmit FIFO DMA channel.
                                             0 = Transmit DMA disabled
                                             1 = Transmit DMA enabled */
        uint32_t reserved2_31     : 30;
    } b;                                /*!< Register bits. */
} ic_v151_dma_cr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c dma transmit data level
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_dma_tdlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t dmatdl;                /*!< Transmit Data Level.
                                             This bit field controls the level at which a DMA
                                             request is made by the transmit logic. It is equal to the watermark
                                             level; that is, the dma_tx_req signal is generated when the number of
                                             valid data entries in the transmit FIFO is equal to or below this field
                                             value, and TDMAE = 1. */
    } b;                                /*!< Register bits. */
} ic_v151_dma_tdlr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c dma revice data level
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_dma_rdlr_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t dmardl;                /*!< Receive Data Level.
                                             This bit field controls the level at which a DMA
                                             request is made by the receive logic. The watermark level = DMARDL+1;
                                             that is, dma_rx_req is generated when the number of valid data entries in
                                             the receive FIFO is equal to or more than this field value + 1, and RDMAE
                                             =1. For instance, when DMARDL is 0, then dma_rx_req is asserted when
                                             1 or more data entries are present in the receive FIFO. */
    } b;                                /*!< Register bits. */
} ic_v151_dma_rdlr_data_t;

/**
 * @brief  This union represents the bit fields in the i2c sda setup
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_sda_setup_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t sda_setup        : 8;  /*!< SDA Setup. It is recommended that if the required delay is 1000ns, then for
                                             an ic_clk frequency of 10 MHz, IC_SDA_SETUP should be programmed to a
                                             value of 11. IC_SDA_SETUP must be programmed with a minimum value of 2.
                                             Default Reset value: 0x64, but can be hardcoded by setting the
                                             IC_DEFAULT_SDA_SETUP configuration parameter. */
        uint32_t reserved8_31     : 24;
    } b;                                /*!< Register bits. */
} ic_v151_sda_setup_data_t;

/**
 * @brief  This union represents the bit fields in the i2c ack general call
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_ack_general_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ack_gen_call     : 1;  /*!< ACK General Call. When set to 1, i2c_v151 responds with a ACK (by
                                             asserting ic_data_oe) when it receives a General Call. When set to 0, the
                                             i2c_v151 does not generate General Call interrupts.
                                             Default Reset value: 0x1, but can be hardcoded by setting the
                                             IC_DEFAULT_ACK_GENERAL_CALL configuration parameter. */
        uint32_t reserved1_31     : 31;
    } b;                                /*!< Register bits. */
} ic_v151_ack_general_data_t;

/**
 * @brief  This union represents the bit fields in the i2c enable status
 *         Register.  Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union ic_v151_enable_status_data {
    uint32_t d32;                       /*!< Raw register data. */
    struct {
        uint32_t ic_en            : 1;  /*!< ic_en Status. This bit always reflects the value driven on the
                                             output port ic_en.
                                             When read as 1, i2c_v151 is deemed to be in an enabled state.
                                             When read as 0, i2c_v151 is deemed completely inactive. */
        uint32_t slv_disable_whlle_busy : 1;
                                        /*!< Slave Disabled While Busy (Transmit, Receive).
                                            This bit indicates if a potential or active Slave operation
                                            has been aborted due to the setting of the IC_ENABLE register
                                            from 1 to 0. This bit is set when the CPU writes a
                                            0 to the IC_ENABLE register while: (a) i2c_v151 is receiving the
                                            address byte of the Slave-Transmitter operation from a remote master;
                                            OR, (b) address and data bytes of the Slave-Receiver operation from a
                                            remote master.
                                            When read as 1, i2c_v151 is deemed to have forced a NACK during
                                            any part of an I2C transfer, irrespective of whether the I2C address
                                            matches the slave address set in i2c_v151 (IC_SAR register) OR if the
                                            transfer is completed before IC_ENABLE is set to 0 but has not taken
                                            effect. */
        uint32_t slv_rx_data_lost : 1;  /*!< Slave Disabled While Busy (Transmit, Receive).
                                             This bit indicates if a potential or active Slave operation
                                             has been aborted due to the setting of the IC_ENABLE register
                                             from 1 to 0. This bit is set when the CPU writes a
                                             0 to the IC_ENABLE register while: (a) i2c_v151 is receiving the
                                             address byte of the Slave-Transmitter operation from a remote master;
                                             OR, (b) address and data bytes of the Slave-Receiver operation from a
                                             remote master.
                                             When read as 1, i2c_v151 is deemed to have forced a NACK during
                                             any part of an I2C transfer, irrespective of whether the I2C address
                                             matches the slave address set in i2c_v151 (IC_SAR register) OR if the
                                             transfer is completed before IC_ENABLE is set to 0 but has not taken
                                             effect. */
        uint32_t reserved3_31     : 29;
    } b;                                /*!< Register bits. */
} ic_v151_enable_status_data_t;


/**
 * @brief  Registers associated with I2c.
 */
typedef struct i2c_v151_regs {
#if defined(CONFIG_I2C_IP_VERSION_V151_PRO)
    volatile uint32_t rsvd_00;    /*!< Reserved 2: 08h ~ 0Ch. */
    volatile uint32_t con;              /*!< I2c control register. <i>Offset: 00h</i>. */
    volatile uint32_t enable;           /*!< I2c enable register.
                                             <i>Offset: 04h</i>. */
    volatile uint32_t rsvd_0c;    /*!< Reserved 2: 08h ~ 0Ch. */
#else
    volatile uint32_t con;              /*!< I2c control register. <i>Offset: 00h</i>. */
    volatile uint32_t enable;           /*!< I2c enable register.
                                             <i>Offset: 04h</i>. */
    volatile uint32_t rsvd_08_0c[2];    /*!< Reserved 2: 08h ~ 0Ch. */
#endif
    volatile uint32_t tar;              /*!< I2c target address register. <i>Offset: 10h</i>. */
    volatile uint32_t sar;              /*!< I2c slave address register. <i>Offset: 14h</i>. */
    volatile uint32_t hs_maddr;         /*!< I2c high speed master mode code address register.
                                             <i>Offset: 18h</i>. */
    volatile uint32_t data_cmd;         /*!< I2c rx/tx data buffer and command register.
                                             <i>Offset: 1Ch</i>. */
    volatile uint32_t rsvd_20_2c[4];    /*!< Reserved 2: 20h ~ 2Ch. */
    volatile uint32_t ss_scl_hcnt;      /*!< I2c standard speed clock scl high count register.
                                             <i>Offset: 30h</i>. */
    volatile uint32_t ss_scl_lcnt;      /*!< I2c standard speed clock scl low count register.
                                             <i>Offset: 34h</i>. */
    volatile uint32_t rsvd_38;          /*!< Reserved 1: 38h. */
    volatile uint32_t fs_scl_hcnt;      /*!< I2c fast speed clock scl high count register.
                                             <i>Offset: 3Ch</i>. */
    volatile uint32_t fs_scl_lcnt;      /*!< I2c fast speed clock scl low count register.
                                             <i>Offset: 40h</i>. */
    volatile uint32_t hs_scl_hcnt;      /*!< I2c high speed clock scl high count register.
                                             <i>Offset: 44h</i>. */
    volatile uint32_t hs_scl_lcnt;      /*!< I2c high speed clock scl low count register.
                                             <i>Offset: 48h</i>. */
    volatile uint32_t rsvd_4c;          /*!< Reserved 1: 4Ch. */
    volatile uint32_t rx_tl;            /*!< I2c receive fifo threshold register.
                                             <i>Offset: 50h</i>. */
    volatile uint32_t tx_tl;            /*!< I2c Transmit fifo threshold register.
                                             <i>Offset: 54h</i>. */
    volatile uint32_t slave_data_nack_only;
                                        /*!< I2c generate slave data nack register.
                                             <i>Offset: 58h</i>. */
    volatile uint32_t rsvd_5c;          /*!< Reserved 1: 5Ch. */
    volatile uint32_t status;           /*!< I2c status register.
                                             <i>Offset: 60h</i>. */
    volatile uint32_t txflr;            /*!< I2c transmit fifo level register.
                                             <i>Offset: 64h</i>. */
    volatile uint32_t rxflr;            /*!< I2c receive fifo level register.
                                             <i>Offset: 68h</i>. */
    volatile uint32_t sda_rx_hold;      /*!< I2c sda hold time length register.
                                             <i>Offset: 6Ch</i>. */
    volatile uint32_t sda_tx_hold;      /*!< I2c sda hold time length register.
                                             <i>Offset: 70h</i>. */
    volatile uint32_t tx_flush_cnt;     /*!< I2c transmit abort source register.
                                             <i>Offset: 74h</i>. */
    volatile uint32_t tx_abrt_source;   /*!< I2c transmit abort source register.
                                             <i>Offset: 78h</i>. */
    volatile uint32_t tx_abrt_slv_intx; /*!< I2c transmit abort source register.
                                             <i>Offset: 7Ch</i>. */
    volatile uint32_t ack_general_call; /*!< I2c ack general call register.
                                             <i>Offset: 80h</i>. */
    volatile uint32_t enable_status;    /*!< I2c enable status register.
                                             <i>Offset: 84h</i>. */
    volatile uint32_t rsvd_88_9c[6];    /*!< Reserved 2: 88h ~ 9Ch. */
    volatile uint32_t dma_cr;           /*!< I2c dma control register.
                                             <i>Offset: A0h</i>. */
    volatile uint32_t dma_tdlr;         /*!< I2c dma transmit data level register.
                                             <i>Offset: A4h</i>. */
    volatile uint32_t dma_rdlr;         /*!< I2c dma receive data level register.
                                             <i>Offset: A8h</i>. */
    volatile uint32_t sda_setup;        /*!< I2c sda setup register.
                                             <i>Offset: ACh</i>. */
    volatile uint32_t intr_mask;        /*!< I2c interrupt mask register. <i>Offset: B0h</i>. */
    volatile uint32_t intr_stat;        /*!< I2c interrupt status register. <i>Offset: B4h</i>. */
    volatile uint32_t raw_intr_stat;    /*!< I2c raw interrupt status register.
                                             <i>Offset: B8h</i>. */
    volatile uint32_t intr_stat_all;    /*!< I2c intr stat all register.
                                             <i>Offset: BCh</i>. */
    volatile uint32_t clr_intr;         /*!< I2c clear combined and individual interrupt register.
                                             <i>Offset: C0h</i>. */
    volatile uint32_t clr_int;         /*!< I2c clear combined and individual interrupt register.
                                             <i>Offset: C4h</i>. */
} i2c_v151_regs_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
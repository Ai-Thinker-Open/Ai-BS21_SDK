/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides trng v2 register definition\n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-06-05, Create file. \n
 */
#ifndef HAL_TRNG_V2_REGS_DEF_H
#define HAL_TRNG_V2_REGS_DEF_H

#include <stdint.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/**
 * @defgroup drivers_hal_trng_v2_regs_def Regs Definition
 * @ingroup  drivers_hal_trng_v2
 * @{
 */

/**
 * @brief  This union represents the bit fields in the trng status register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_status {
    struct {
        uint32_t    ready                 : 1;       /*!< data is available in the trng_data_0…3 registers.
                                                          Acknowledging this state by writing a ‘1’ to bit [0] of the
                                                          TRNG_INTACK register clears this bit to ‘0’. */
        uint32_t    shutdown_oflo         : 1;       /*!< the number of FROs shut down after a second ‘error event’
                                                          has exceeded the threshold set by ‘shutdown_threshold’
                                                          in the TRNG_ALARMCNT register. */
        uint32_t    stuck_out             : 1;       /*!< logic around the output data registers4 detected that the
                                                          EIP-76 generates the same value twice in a row. */
        uint32_t    noise_fail            : 1;       /*!< the [AIS-31] ‘run test’ logic monitoring data shifted into
                                                          the main shift register detected a sequence of 48 identical
                                                          bits, which is considered a ‘Noise Source failure’ as
                                                          proposed in section E.5 of the [AIS-31] standard.  */
        uint32_t    run_fail              : 1;       /*!< the [AIS-31] ‘run test’ logic monitoring data shifted into
                                                          the main shift register detected an out-of-bounds value for
                                                          at least one of the ‘run_X_count_...’ counters after
                                                          checking 20,000 bits. */
        uint32_t    long_run_fail         : 1;       /*!< the [AIS-31] ‘run test’ logic monitoring data shifted into
                                                          the main shift register detected a sequence of 34
                                                          identical bits. */
        uint32_t    poker_fail            : 1;       /*!< the [AIS-31] ‘poker test’ logic monitoring data shifted
                                                          into the main shift register detected an out-of-bounds
                                                          value in at least one of the 16 ‘poker_count_X’ counters or
                                                          an out of bounds ‘sum of squares’ value after checking
                                                          20,000 bits. */
        uint32_t    monobit_fail          : 1;       /*!< the [AIS-31] ‘monobit test’ logic monitoring data shifted
                                                          into the main shift register detected an out-of-bounds number
                                                          of ‘1’s after checking 20,000 bits. */
        uint32_t    test_ready            : 1;       /*!< Data for known-answer tests on the ‘Repetition Count’,
                                                          ‘Adaptive Proportion’, ‘monobit’, ‘run’ and ‘poker’ tests and
                                                          Conditioning Function can be written to the TRNG_RAW_...
                                                          registers; data for DRBG functionality tests can be written
                                                          to the TRNG_INPUT_… registers. */
        uint32_t    stuck_nrbg            : 1;       /*!< NRBG stuck error; this happens when two identical values were
                                                          extracted from the main shift register (configuration without
                                                          Conditioning Function) or the Conditioning Function
                                                          output (when configured). */
        uint32_t    reserved_0            : 3;       /*!< Bits should be ignored on a read. */
        uint32_t    repcnt_fail           : 1;       /*!< the [SP 800-90B draft] ‘Repetition Count’ test logic
                                                          monitoring the data shifted into the main shift register
                                                          detected a number of consecutive identical 8-bit Noise Source
                                                          output samples that matched the programmed cutoff value. */
        uint32_t    aprop_fail            : 1;       /*!< the [SP 800-90B draft] ‘Adaptive Proportion’ test logic
                                                          monitoring the data shifted into the main shift register
                                                          detected too many 8-bit Noise Source output samples matching
                                                          the first sample taken in the test window. */
        uint32_t    test_stuck_out_1      : 1;       /*!< indication that ‘stuck_out’ functionality testing is enabled
                                                          (via TRNG_INTACK register bit [15]). This bit will
                                                          automatically fall back to ‘0’ when a stuck output is actually
                                                          detected. */
        uint32_t    blocks_available      : 8;       /*!< This field indicates the number of 128 bits blocks of
                                                          random data that are available in the random data RAM buffer
                                                          (if configured).
                                                          If this value is non-zero, the output registers will be
                                                          re-filled from the random data RAM buffer immediately after
                                                          acknowledging the ‘ready’ interrupt. */
        uint32_t    reserved_1            : 7;      /*!<  Bits should be ignored on a read. */
        uint32_t    need_clock            : 1;      /*!<  ‘1’ indicates that the TRNG is busy generating entropy
                                                          or is in one of its test modes – the module clock may not
                                                          be turned off.
                                                          This bit is a direct mirror of the ‘need_clock’ output
                                                          signal of the module. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_status_t;

/**
 * @brief  This union represents the bit fields in the trng control register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_control {
    struct {
        uint32_t    ready_mask            : 1;      /*!< ‘1’ = allow the ‘ready’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    shutdown_oflo_mask    : 1;       /*!< allow the ‘shutdown_oflo’ bit in the TRNG_STATUS register
                                                          to activate the (active ‘high’) ‘irq’ output. */
        uint32_t    stuck_out_mask        : 1;       /*!< allow the ‘stuck_out’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    noise_fail_mask       : 1;       /*!< allow the ‘noise_fail’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    run_fail_mask         : 1;       /*!< allow the ‘run_fail’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    long_run_fail_mask    : 1;       /*!< allow the ‘long_run_fail’ bit in the TRNG_STATUS register
                                                          to activate the (active ‘high’) ‘irq’ output. */
        uint32_t    poker_fail_mask       : 1;       /*!< allow the ‘poker_fail’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    monobit_fail_mask     : 1;       /*!< allow the ‘monobit_fail’ bit in the TRNG_STATUS register
                                                          to activate the (active ‘high’) ‘irq’ output. */
        uint32_t    test_mode             : 1;       /*!< Enables access to (amongst others) the TRNG_COUNT and
                                                          TRNG_RAW_L/H registers and keep
                                                          ‘need_clock’ output active ‘high’ for testing purposes. */
        uint32_t    stuck_nrbg_mask       : 1;       /*!< allow the 'stuck_nrbg' bit in the TRNG_STATUS register to
                                                          activate the (active 'high') 'irq' output. */
        uint32_t    enable_trng           : 1;       /*!< Setting this bit to ‘1’ starts the EIP-76, gathering
                                                          entropy from the FROs. Resetting this bit to ‘0’ forces all
                                                          NRBG logic back into the idle state immediately. */
        uint32_t    reserved_0            : 1;       /*!< Bit should be written with ‘0’ and should be ignored on
                                                          a read. */
        uint32_t    drbg_en               : 1;       /*!< Enable the [SP 800-90A] AES-256 DRBG. If this bit is reset
                                                          to ‘0’, the DRBG is forced back into the idle state
                                                          immediately. */
        uint32_t    repcnt_fail_mask      : 1;       /*!< allow the ‘repcnt_fail’ bit in the TRNG_STATUS register
                                                          to activate the (active ‘high’) ‘irq’ output. */
        uint32_t    aprop_fail_mask       : 1;       /*!< allow the ‘aprop_fail’ bit in the TRNG_STATUS register to
                                                          activate the (active ‘high’) ‘irq’ output. */
        uint32_t    re_seed               : 1;       /*!< Set-only, writing a ‘1’ starts a re-seed cycle as described
                                                          in section 0 below, writing a ‘0’ has no effect. */
        uint32_t    request_data          : 1;       /*!< Write-only, writing a ‘1’ indicates that the ‘data_blocks’
                                                          field contains the number of 128 bit data blocks that the
                                                          [SP 800-90A] AES-256 DRBG should generate in a single
                                                          ‘Generate_function’. Writing a ‘0’ has no effect. */
        uint32_t    reserved_1            : 3;       /*!< Bits should be written with ‘0’ and should be ignored on
                                                          a read. */
        uint32_t    data_blocks           : 12;      /*!< This field indicates the number of 128 bit data blocks that
                                                          must be generated by the [SP 800-90A] AES-256 DRBG in a
                                                          single ‘Generate_function’. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_control_t;

/**
 * @brief  This union represents the bit fields in the trng config register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_config {
    struct {
        uint32_t    noise_blocks          : 8;       /*!< This field sets the number of 512-bit blocks of raw Noise
                                                          Source output data that must be processed by either the
                                                          Conditioning Function or the SP 800-90 DRBG ‘BC_DF’
                                                          functionality to yield a ‘full entropy’ output value. */
        uint32_t    sample_div            : 4;       /*!< This field directly controls the number of ‘clk’ input
                                                          cycles between samples taken from the FROs. The default
                                                          value 0 indicates that samples are taken every ‘clk’ cycle,
                                                          maximum value 15 (decimal) takes one sample every 16
                                                          ‘clk’ cycles. */
        uint32_t    read_timeout          : 4;       /*!< This field controls the secure reading mode
                                                          (see section 5.2.6.2). Value 0 disables secure reading,
                                                          values in the range 1…15 enable secure reading and
                                                          set a read gate closure timeout of approximately
                                                          (read_timeout) x  16 ‘clk’ input cycles. */
        uint32_t    sample_cycles         : 16;      /*!< This field sets the number of FRO samples that are
                                                          XOR-ed together into one bit to be shifted into the main
                                                          shift register. This value must be such that there is at
                                                          least one bit of entropy (in total) in each 8 bits that are
                                                          shifted. This field can only be modified while ‘enable_trng’
                                                          in TRNG_CONTROL is ‘0’ or when either of the
                                                          ‘test_known_noise’ or ‘test_cond_func’ bits in TRNG_TEST
                                                          is ‘1’. Value 0 in this field selects 65536 FRO samples to be
                                                          XOR-ed together. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_config_t;

/**
 * @brief  This union represents the bit fields in the trng alarm count register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarmcnt {
    struct {
        uint32_t    alarm_threshold       : 8;       /*!< Alarm detection threshold for the repeating pattern detectors
                                                          on each FRO. A FRO ‘alarm event’ is declared when a repeating
                                                          pattern (of up to four samples length) is detected
                                                          continuously for the number of samples defined by this
                                                          field’s value. Reset value 255 (decimal) should keep the
                                                          number of ‘alarm events’ to a manageable level. */
        uint32_t    reserved_0            : 7;       /*!< Bits should be written with a ‘0’ and should be ignored on
                                                          a read. */
        uint32_t    stall_run_poker       : 1;       /*!< Stall the ‘monobit test’, ‘run test’ and ‘poker test’
                                                          circuits when either the ‘monobit_fail’, ‘run_fail’ or
                                                          ‘poker_fail’ bits in the TRNG_STATUS register are set to ‘1’
                                                          – this allows inspecting the state of the result counters
                                                          (which would otherwise bereset immediately for the next
                                                          20,000 bits block to test). */
        uint32_t    shutdown_threshold    : 5;       /*!< Threshold setting for generating the ‘shutdown_oflo’
                                                          interrupt,which is activated when the ‘shutdown_count’ value
                                                          in this register exceeds the threshold value set here. */
        uint32_t    reserved_1            : 2;       /*!< Bits should be written with a ‘0’ and should be ignored on
                                                          a read. */
        uint32_t    shutdown_fatal        : 1;       /*!< ‘1’ = Consider the ‘shutdown_oflo’ interrupt as a fatal error
                                                          requiring taking the complete TRNG engine off-line */
        uint32_t    shutdown_count        : 6;       /*!< Read-only, indicates the number of ‘1’ bits in the
                                                          TRNG_ALARMSTOP egister. This field is 6 bits wide to allow up
                                                          to 32 ‘ones’ to be indicated. The actual maximum value equals
                                                          the number of FROs. */
        uint32_t    reserved_2            : 2;       /*!< Bits should be written with a ‘0’ and should be ignored on
                                                          a read. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_alarmcnt_t;

/**
 * @brief  This union represents the bit fields in the trng fro enable register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_froenable {
    struct {
        uint32_t    fro_enables           : 24;      /*!< Enable bits for the individual FROs. A ‘1’ in bit [n] enables
                                                          FRO ‘n’. The default state is all ones to enable all FROs
                                                          after power-up. Note that they are not actually started up
                                                          before the ‘enable_trng’ bit in the TRNG_CONTROL register is
                                                          set to ‘1’. A bit is automatically forced to ‘0’ here
                                                          (and cannot be written to ‘1’) when the corresponding
                                                          bit in the TRNG_ALARMSTOP register has value ‘1’. */
        uint32_t    reserved              : 8;       /*!< Bits should be written with a ‘0’ and should be ignored on
                                                          a read. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_froenable_t;

/**
 * @brief  This union represents the bit fields in the trng fro detune register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_frodetune {
    struct {
        uint32_t    fro_detunes           : 24;      /*!< De-tune bits for the individual FROs. A ‘1’ in bit [n] lets
                                                          FRO ‘n’ run approximately 5% faster. The value of one of
                                                          these bits may only be changed while the corresponding FRO is
                                                          turned off (by temporarily writing a ‘0’ in the corresponding
                                                          bit of the TRNG_FROENABLE register). */
        uint32_t    reserved              : 8;       /*!< Logging bits for the ‘alarm events’ of individual FROs.
                                                          A ‘1’ in bit [n] indicates FRO ‘n’ experienced an ‘alarm
                                                          event’. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_frodetune_t;

/**
 * @brief  This union represents the bit fields in the trng alarm mask register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarmmask {
    struct {
        uint32_t    fro_alarmmasks        : 24;      /*!< Logging bits for the ‘alarm events’ of individual FROs.
                                                          A ‘1’ in bit [n] indicates FRO ‘n’ experienced an
                                                          ‘alarm event’. */
        uint32_t    reserved              : 8;       /*!< Bits should be written with a ‘0’ and should be ignored on
                                                          a read. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_alarmmask_t;

/**
 * @brief  This union represents the bit fields in the trng alarm stop register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef union trng_alarmstop {
    struct {
        uint32_t    fro_alarmstops        : 24;      /*!< Logging bits for the ‘alarm events’ of individual FROs.
                                                          A ‘1’ in bit [n] indicates FRO ‘n’ experienced more than one
                                                          ‘alarm event’ in quick succession and has been turned off.
                                                          A ‘1’ in this field forces the corresponding bit in the
                                                          TRNG_FROENABLE register to ‘0’. */
        uint32_t    reserved              : 8;       /*!< Receive (read)/Transmit (write) data character. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_alarmstop_t;

/**
 * @brief  This union represents the bit fields in the trng oscl en register.
 *         Read the register into the <i>d32</i> member then
 *         set/clear the bits using the <i>b</i> elements.
 */
typedef struct trng_oscl {
    struct {
        uint32_t    reserved_0            : 2;       /*!< reserved. */
        uint32_t    oscl_en               : 1;       /*!< trng oscl enable. */
        uint32_t    reserved              : 8;       /*!< reserved. */
    } b;
    uint32_t    d32;                                 /*!< Raw register data. */
} trng_oscl_t;

/**
 * @brief  Registers associated with trng.
 */
typedef struct trng_regs_v2 {
    volatile uint32_t               trng_data_0;      /*!< Random number output register 0. */
    volatile uint32_t               trng_data_1;      /*!< Random number output register 1 */
    volatile uint32_t               trng_data_2;      /*!< Random number output register 2 */
    volatile uint32_t               trng_data_3;      /*!< Random number output register 3 */
    volatile trng_status_t          trng_status;      /*!< trng status register */
    volatile trng_control_t         trng_control;     /*!< trng control register */
    volatile trng_config_t          trng_config;      /*!< trng config register */
    volatile trng_alarmcnt_t        trng_alarmcnt;    /*!< trng alarm count register */
    volatile trng_froenable_t       trng_froenable;   /*!< trng fro enable register */
    volatile trng_frodetune_t       trng_frodetune;   /*!< trng fro detune register */
    volatile trng_alarmmask_t       trng_alarmmask;   /*!< trng alarm mask register */
    volatile trng_alarmstop_t       trng_alarmstop;   /*!< trng alarm stop register */
    volatile uint32_t               reserved[40];     /*!< reserved. */
    volatile trng_oscl_t            trng_oscl;        /*!< trng oscl register. */
} trng_regs_v2_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
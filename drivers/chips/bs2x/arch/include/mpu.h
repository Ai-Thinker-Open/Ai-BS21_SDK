/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description:  LIN131 MPU DRIVER HEADER FILE.
 * Author: @CompanyNameTag
 * Create:  2021-10-10
 */

#ifndef PAL_MPU_H
#define PAL_MPU_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define DEVICE_NONBUFFERABLE            0
#define NORMAL_NONCACHEABEL_BUFFERABLE  3
#define WRITEBACK_RALLOCATE     7
#define WRITEBACK_WALLOCATE     11
#define WRITEBACK_RWALLOCATE    15

#define PMPXCFG_NUM_PER_REG     4

#define PMPCFG_ADDR_MATCH_OFF   0x0 /*!< Null region (disabled). */
#define PMPCFG_ADDR_MATCH_TOR   0x1 /*!< Top of range. */
#define PMPCFG_ADDR_MATCH_NA4   0x2 /*!< Naturally aligned four-byte region. */
#define PMPCFG_ADDR_MATCH_NAPOT 0x3 /*!< Naturally aligned power-of-two region. */

/**
 * @brief  pmp cfg readable, writable and executable attribute.
 */
typedef struct {
    uint8_t r : 1; /*!< Read permission. */
    uint8_t w : 1; /*!< Write permission. */
    uint8_t x : 1; /*!< Execute permission. */
    uint8_t a : 2; /*!< Address Matching mode. */
    uint8_t resv_0 : 2;
    uint8_t l : 1; /*!< Locking. */
} pmpxcfg_t;

/**
 * @brief  pmp region attribute.
 */
typedef struct {
    uint8_t idx;
    uint32_t end_addr;
    uint8_t memattr;
    pmpxcfg_t cfg;
} mpu_config_t;

/**
 * @brief  pmp cfg value union.
 */
union rv_csr_pmpcfg {
    uint32_t value;
    pmpxcfg_t cfg[PMPXCFG_NUM_PER_REG];
};

void mpu_config(mpu_config_t *mpu_cfg, uint16_t mpu_cfg_lenth);

#ifdef __cplusplus
#if __cplusplus
    }
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
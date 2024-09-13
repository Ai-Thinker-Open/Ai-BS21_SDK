/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides flash port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-10-26， Create file. \n
 */
#ifndef FLASH_CONFIG_PORTING_H
#define FLASH_CONFIG_PORTING_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @ingroup  drivers_port_flash_config
 * @{
 */

#if defined(CONFIG_FLASH_USE_CUSTOMIZED_DEVICE_INFO)

#define FLASH_MANUFACTURER_GIGADEVICE_GD25Q80C   0x1440C8

/* Mxic enter qspi mode cmd config. */
/* MX25R64/MX25R32 mxic flash config. */
static flash_cmd_exe_t g_mxic_mx25rxx_enter_qspi_mode_cmd[] = {
    /* Write enable. */
    { FLASH_CMD_TYPE_CMD,        HAL_SPI_FRAME_FORMAT_STANDARD, 1, { FLASH_WREN_CMD } },
    /* Write configuration register, enable QPI & enable High performance mode. */
    { FLASH_CMD_TYPE_CMD,        HAL_SPI_FRAME_FORMAT_STANDARD, 4, { 0x01, 0x40, 0x00, 0x02 } },
    /* Wait until the configuration is complete. qspi mode 6 dummy cycle, max 80MHZ. */
    { FLASH_CMD_TYPE_PROCESSING, HAL_SPI_FRAME_FORMAT_STANDARD, 3, { FLASH_RDSR1_CMD, 0, 0 } },
    /* The END command, will not be executed and need return. */
    { FLASH_CMD_TYPE_END,        HAL_SPI_FRAME_FORMAT_MAX_NUM,   0, { 0 } }
};

/* PUYA config. */
/* P25Q32LX PUYA flash config. */
static flash_cmd_exe_t g_puya_p25q32lc_enter_qspi_mode_cmd[] = {
    /* Write enable for volatile status register. */
    { FLASH_CMD_TYPE_CMD,        HAL_SPI_FRAME_FORMAT_STANDARD, 1, { 0x50 } },
    /* Write status register-2 to 0x2, enable QPI write bit. */
    { FLASH_CMD_TYPE_CMD,        HAL_SPI_FRAME_FORMAT_STANDARD, 2, { 0x31, 0x02 } },
    /* Wait until the configuration is complete. */
    { FLASH_CMD_TYPE_PROCESSING, HAL_SPI_FRAME_FORMAT_STANDARD, 3, { FLASH_RDSR1_CMD, 0, 0 } },
    /* Enable QPI mode. */
    { FLASH_CMD_TYPE_CMD,        HAL_SPI_FRAME_FORMAT_STANDARD, 1, { 0x38 } },
    /* Set the dummy cycle to 6, with the maximum read frequency being 104MHZ 70MHZ. */
    { FLASH_CMD_TYPE_CMD, HAL_SPI_FRAME_FORMAT_QUAD, 2, { 0xC0,  0x20} },
    /* The END command, will not be executed and need return. */
    { FLASH_CMD_TYPE_END,        HAL_SPI_FRAME_FORMAT_MAX_NUM,   0, { 0 } }
};

/* Gigadevice enter qspi mode cmd config. */
/* GD25WQ64/GD25LE64EX gigadevice flash config. */
static flash_cmd_exe_t g_gigadevice_gd25q80_enter_qspi_mode_cmd[] = {
    /* Write enable for volatile status register. */
    { FLASH_CMD_TYPE_CMD, HAL_SPI_FRAME_FORMAT_STANDARD, 1, { 0x50 } },
    /* Write volatile configuration register, config XIP disable. */
    { FLASH_CMD_TYPE_CMD, HAL_SPI_FRAME_FORMAT_STANDARD, 3, { 0x01, 0x00, 0x02 } },
    /* Wait until the configuration is complete. qspi mode, max 104MHZ. */
    { FLASH_CMD_TYPE_PROCESSING, HAL_SPI_FRAME_FORMAT_STANDARD, 3, { FLASH_RDSR1_CMD, 0, 0 } },
    /* The END command, will not be executed and need return. */
    { FLASH_CMD_TYPE_END, HAL_SPI_FRAME_FORMAT_MAX_NUM,   0, { 0 } }
};

/* Mxic enter xip mode config. */
/* MX25R64/MX25R32 mxic flash config. */
static flash_qspi_xip_config_t g_mxic_mx25rxx_config = {
    /* Enter XIP mode before config. */
    WAIT_CYCLES_4, HAL_SPI_INST_LEN_8, HAL_SPI_ADDR_LEN_32, HAL_SPI_TRANS_TYPE_INST_S_ADDR_Q,
    /* Enter XIP mode after config. */
    WAIT_CYCLES_4, HAL_SPI_INST_LEN_0, HAL_SPI_ADDR_LEN_32, HAL_SPI_TRANS_TYPE_INST_S_ADDR_Q,
    /* XIP 32bit addr & wrap config. */
    false,
    false,
};

/* PUYA config. */
/* P25Q32LX PUYA flash config. */
static flash_qspi_xip_config_t g_puya_p25q32lc_config = {
    /* The config that before enter XIP mode. */
    WAIT_CYCLES_6,
    HAL_SPI_INST_LEN_8,
    HAL_SPI_ADDR_LEN_24,
    HAL_SPI_TRANS_TYPE_INST_Q_ADDR_Q,
    /* The config that after enter XIP mode. */
    WAIT_CYCLES_6,
    HAL_SPI_INST_LEN_8,
    HAL_SPI_ADDR_LEN_24,
    HAL_SPI_TRANS_TYPE_INST_Q_ADDR_Q,
    /* XIP 32bit addr & wrap config. */
    false,
    false,
};

/* GD25LQ256 gigadevice flash config. */
static flash_qspi_xip_config_t g_gigadevice_gd25q80_config = {
    /* The config that before enter XIP mode. */
    WAIT_CYCLES_4,
    HAL_SPI_INST_LEN_0,
    HAL_SPI_ADDR_LEN_32,
    HAL_SPI_TRANS_TYPE_INST_Q_ADDR_Q,
    /* The config that after enter XIP mode. */
    WAIT_CYCLES_4,
    HAL_SPI_INST_LEN_8,
    HAL_SPI_ADDR_LEN_32,
    HAL_SPI_TRANS_TYPE_INST_Q_ADDR_Q,
    /* XIP 32bit addr & wrap config. */
    true,
    false,
};

static const flash_device_parameter_t g_flash_device_parameter[FLASH_MANUFACTURER_MAX] = {
    { FLASH_MANUFACTURER_MXIC_MX25R80,          FLASH_SIZE_8MB,  0xA5, 0xAA, WAIT_CYCLES_4, 0x2B, 0xB0, 0x30,
      g_mxic_mx25rxx_enter_qspi_mode_cmd,         NULL,                               &g_mxic_mx25rxx_config },
    { FLASH_MANUFACTURER_PUYA_P25Q80SU,         FLASH_SIZE_1MB, 0x20, 0xFF, WAIT_CYCLES_4, 0x05, 0x75, 0x7A,
      g_puya_p25q32lc_enter_qspi_mode_cmd,        NULL,                               &g_puya_p25q32lc_config },
    { FLASH_MANUFACTURER_GIGADEVICE_GD25Q80C,   FLASH_SIZE_8MB, 0x20, 0x0, WAIT_CYCLES_4, 0x05, 0x75, 0x7A,
      g_gigadevice_gd25q80_enter_qspi_mode_cmd,  NULL,                               &g_gigadevice_gd25q80_config},
};
#endif

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

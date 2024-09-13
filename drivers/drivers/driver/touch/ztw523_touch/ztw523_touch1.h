/*
 * Copyright (c) @CompanyNameMagicTag 2021-2022. All rights reserved.
 * Description: ztw523 touch driver.
 * Author: @CompanyNameTag
 * Create: 2021-05-29
 */

#ifndef ZTW523_TOUCH1_H
#define ZTW523_TOUCH1_H

#include "stdio.h"
#include "soc_errno.h"
#include "soc_osal.h"
#include "touch_screen_def.h"
#include "platform_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/* ztw523 definitions */
/* max wait time */
#define ZTW523_OPERATER_MUTEX_WAIT_TIME 3000 /* operater tp mutex timeout ms */
#define ZTW523_CMCP_WAIT_TIMEOUT        1000
/* define some properties value */
#define ZTW523_ENABLE                   0x0001
#define ZTW523_DISABLE                  0x0000
#define ZTW523_DATA_LEN                 2
#define ZTW523_POWERON_DELAY            100
#define ZTW523_POWEROFF_DELAY           100
#define ZTW523_RESETHIGH_DELAY          10
#define ZTW523_CLEARINT_DELAY           10
#define ZTW523_FIRMWAREON_DELAY         200
#define ZTW523_INIT_RETRY_TIMERS        3
#define ZTW523_SETMODE_RETRY_TIMERS     3
#define ZTW523_SOFTRESET_RETRY_TIMES    10
#define ZTW523_RETRY_TIMES              10
#define ZTW523_DEVICE_INFO              "zinitix,ztw523"
#define ZTW523_DEVICE_INFO_SIZE         sizeof(ZTW523_DEVICE_INFO)
#define ZTW523_MAX_SUPPORTED_FINGER_NUM 1
#define ZTW523_POINT_MODE               1
#define ZTW523_CALIB_TOUCH_MODE         0x07
#define ZTW523_REGDATA_SHIFT            8
#define ZTW523_GENERAL_DELAY_1          1
#define ZTW523_GENERAL_DELAY_5          5
#define ZTW523_GENERAL_DELAY_10         10
#define ZTW523_GENERAL_DELAY_20         20
#define ZTW523_GENERAL_DELAY_25         25
#define ZTW523_GENERAL_DELAY_30         30
#define ZTW523_GENERAL_DELAY_50         50
#define ZTW523_GENERAL_DELAY_100        100
#define ZTW523_GENERAL_DELAY_200        200
#define ZTW523_GENERAL_DELAY_500        500
#define ZTW523_GENERAL_RETRY_1          1
#define ZTW523_GENERAL_RETRY_2          2
#define ZTW523_GENERAL_RETRY_3          3
#define ZTW523_GENERAL_RETRY_4          4
#define ZTW523_GENERAL_RETRY_10         10
#define ZTW523_RAWDATA_DELAY_FOR_HOST   100
#define ZTW523_FW_JUMP_CODE             0x0048
#define ZTW523_REPORT_RATE              60
#define ZTW523_PIXEL_THRESHOLD          5

#ifndef ZTW523_RES_MAX_X
#define ZTW523_RES_MAX_X 453
#endif

#ifndef ZTW523_RES_MAX_Y
#define ZTW523_RES_MAX_Y 453
#endif

#ifndef ZTW523_POINT_TRESHHOLD
#define ZTW523_POINT_TRESHHOLD 0x19
#endif

#define ZTW523_TOUCHINFO_HEAD_LEN 4
#define ZTW523_POINTINFO_LEN      6
#define ZTW523_TOUCHINFO_LEN      (ZTW523_TOUCHINFO_HEAD_LEN + ZTW523_POINTINFO_LEN * ZTW523_MAX_SUPPORTED_FINGER_NUM)

#define ZTW523_INT_NONE            0x0000
#define ZTW523_INT_MASK            0x081F
#define ZTW523_PALM_MASK           0x0010
#define ZTW523_GESTURE_WAKEUP_INIT 0
#define ZTW523_FIRMWARE_SIZE       48
#define ZTW_PAGE_SIZE_128          128
#define ZTW_PAGE_SIZE_64           64
#define ZTW_SECTOR_SIZE            8
#define ZTW_CHIPID_F400            0xF400
#define ZTW_CHIPID_E240            0xE240
#define ZTW_CHIPID_E700            0xE700
#define ZTW_CHIPID_E548            0xE548
#define ZTW_CHIPID_E538            0xE538
#define ZTW_CHIPID_E532            0xE532
#define ZTW_VENDOR_ID              0x5A49
#define ZTW523_CHIP_ID             0xE628
/* define touch info offset */
#define ZTW523_STATUSL_OFFSET   0
#define ZTW523_STATUSH_OFFSET   1
#define ZTW523_EVENTL_OFFSET    2
#define ZTW523_EVENTH_OFFSET    3
#define ZTW523_XL_OFFSET        4
#define ZTW523_XH_OFFSET        5
#define ZTW523_YL_OFFSET        6
#define ZTW523_YH_OFFSET        7
#define ZTW523_WIDTH_OFFSET     8
#define ZTW523_SUBSTATUS_OFFSET 9
/* define data shift and mask */
#define ZTW523_SHIFT_8_BIT  8
#define ZTW523_SHIFT_16_BIT 16
#define ZTW523_SHIFT_24_BIT 24
#define ZTW523_MASK_BYTE    0xFF
/* define ZTW523_HIGH_SPEED_DMA rely on iic dma support */
#ifdef ZTW523_HIGH_SPEED_DMA
#define ZTW523_TOUCH_POINT_MODE 0
#else
#define ZTW523_TOUCH_POINT_MODE 1
#endif

#define ZTW523_SEC_MODE        48
#define ZTW523_NORMAL_MODE     5
#define ZTW523_DND_MODE        11 /* mutual cap */
#define ZTW523_SELF_DND_MODE   17 /* self cap */
#define ZTW523_DNDSKIP_CNT     1
#define ZTW523_SELFDNDSKIP_CNT 1
/* Config Reg Info */
#define ZTW523_REG_CMD_ENABLE    0xC000
#define ZTW523_REG_CHIP_ID       0xCC00
#define ZTW523_REG_INTN_CLEAR    0xC004
#define ZTW523_REG_NVM           0xC002
#define ZTW523_REG_NVM_VPP       0xC003
#define ZTW523_REG_NVM_WP        0xC104
#define ZTW523_REG_PROGRAM_START 0xC001
#define ZTW523_POWER_CTL_BEGIN   0x000A
#define ZTW523_POWER_CTL_END     0x000B
#define ZTW523_CALIB_CTL1        0xC003
#define ZTW523_CALIB_CTL2        0xC104
#define ZTW523_SDRAM_RESET       0x0FF8
#define ZTW523_REPORT_REG        0x0186  /* 设置中断上报频率 */
#define ZTW523_PIXEL_THRESHOLD_REG 0x00C3
/* Register Map */
#define ZTW523_SWRESET_CMD                   0x0000
#define ZTW523_WAKEUP_CMD                    0x0001
#define ZTW523_IDLE_CMD                      0x0004
#define ZTW523_SLEEP_CMD                     0x0005
#define ZTW523_CLEAR_INT_STATUS_CMD          0x0003
#define ZTW523_CALIBRATE_CMD                 0x0006
#define ZTW523_SAVE_STATUS_CMD               0x0007
#define ZTW523_SAVE_CALIBRATION_CMD          0x0008
#define ZTW523_RECALL_FACTORY_CMD            0x000f
#define ZTW523_SENSITIVITY                   0x0020
#define ZTW523_I2C_CHECKSUM_WCNT             0x016a
#define ZTW523_I2C_CHECKSUM_RESULT           0x016c
#define ZTW523_DEBUG_REG                     0x0115 /* 0~7 */
#define ZTW523_TOUCH_MODE                    0x0010
#define ZTW523_CHIP_REVISION                 0x0011
#define ZTW523_FIRMWARE_VERSION              0x0012
#define ZTW523_MINOR_FW_VERSION              0x0121
#define ZTW523_DATA_VERSION_REG              0x0013
#define ZTW523_HW_ID                         0x0014
#define ZTW523_SUPPORTED_FINGER_NUM          0x0015
#define ZTW523_EEPROM_INFO                   0x0018
#define ZTW523_INITIAL_TOUCH_MODE            0x0019
#define ZTW523_CHIP_HW_REVISION              0x001A
#define ZTW523_IC_VENDOR_ID                  0x001C
#define ZTW523_TSM_MODULE_ID                 0x001E
#define ZTW523_TOTAL_NUMBER_OF_X             0x0060
#define ZTW523_TOTAL_NUMBER_OF_Y             0x0061
#define ZTW523_DELAY_RAW_FOR_HOST            0x007f
#define ZTW523_BUTTON_SUPPORTED_NUM          0x00B0
#define ZTW523_BUTTON_SENSITIVITY            0x00B2
#define ZTW523_X_RESOLUTION                  0x00C0
#define ZTW523_Y_RESOLUTION                  0x00C1
#define ZTW523_HOLD_POINT_TRESHHOLD          0x00C3
#define ZTW523_POINT_STATUS_REG              0x0080
#define ZTW523_ICON_STATUS_REG               0x00AA
#define ZTW523_AFE_FREQUENCY                 0x0100
#define ZTW523_DND_N_COUNT                   0x0122
#define ZTW523_DND_U_COUNT                   0x0135
#define ZTW523_RAWDATA_REG                   0x0200
#define ZTW523_EEPROM_INFO_REG               0x0018
#define ZTW523_INT_ENABLE_FLAG               0x00f0
#define ZTW523_PERIODICAL_INTERRUPT_INTERVAL 0x00f1
#define ZTW523_CHECKSUM_RESULT               0x012c
#define ZTW523_GESTURE_WAKEUP_REG            0x0126

#define ZTW523_TOUCHINFO_MASK 0x0F
#define ZTW523_TOUCH_EXIST    0x01
#define ZTW523_TOUCH_DOWN     0x03
#define ZTW523_TOUCH_MOVE     0x05
#define ZTW523_TOUCH_UP       0x08
#define ZTW523_TOUCH_NONE     0x07

#define ZTW523_SUB_BIT_EXIST  0
#define ZTW523_SUB_BIT_DOWN   1
#define ZTW523_SUB_BIT_MOVE   2
#define ZTW523_SUB_BIT_UP     3
#define ZTW523_SUB_BIT_UPDATE 4
#define ZTW523_SUB_BIT_WAIT   5

#ifndef ZTW523_TSP_X_CHANNEL_NUM
#define ZTW523_TSP_X_CHANNEL_NUM 6
#endif

#ifndef ZTW523_TSP_Y_CHANNEL_NUM
#define ZTW523_TSP_Y_CHANNEL_NUM 6
#endif

#define ZTW523_TSP_DND_NUM     (ZTW523_TSP_X_CHANNEL_NUM * ZTW523_TSP_Y_CHANNEL_NUM)
#define ZTW523_TSP_SELFDND_NUM (ZTW523_TSP_X_CHANNEL_NUM + ZTW523_TSP_Y_CHANNEL_NUM)

/* firmware info */
#define ZTW523_FIRMWARE_VERSION_L            0
#define ZTW523_FIRMWARE_VERSION_H            1
#define ZTW523_FIRMWARE_VERSION_OFFSET       52
#define ZTW523_FIRMWARE_MINOR_VERSION_OFFSET 56
#define ZTW523_FIRMWARE_DATA_VERSION_OFFSET  60
#define ZTW523_FIRMWARE_OFFSET_ZERO          0
#define ZTW523_FIRMWARE_CONVERT_DATA_STEP    2
#define ZTW523_FIRMWARE_CONVERT_DATA_OFFSET  1
/* file op code */
#define ZTW523_FILE_ERROR (-1)
#define ZTW523_FILE_OK    0
/* upgrade info */
#define ZTW523_FWGRADE_CMD_NUM 3
/* rawdata info */
#define ZTW523_RAWDATA_CMD_NUM 2
/* define gesture macro */
#define ZTW523_GESTURE_WAKEUP 1

/* self_dnd dnd parameter */
#define ZTW523_SEC_SELF_DND_N_COUNT      15
#define ZTW523_SEC_SELF_DND_U_COUNT      2
#define ZTW523_SEC_SELF_DND_FREQUENCY    80

#define ZTW523_SEC_DND_N_COUNT           27
#define ZTW523_SEC_DND_U_COUNT           3
#define ZTW523_SEC_DND_FREQUENCY         240

/* host peripheral typedef */
typedef ext_errno (*tp_irq_callback)(void);

/* ZTW523 driver typedef */
typedef enum {
    ZTW523_POWERDOWN = 0,
    ZTW523_POWERUP,
} ztw523_sw_power_status;

typedef enum {
    ZTW523_WORK_NORMAL = 0,
    ZTW523_WORK_STANDBY,
    ZTW523_WORK_GETCMCP,
    ZTW523_WORK_SLEEP,
    ZTW523_WORK_SUSPEND,
    ZTW523_WORK_RESUME,
    ZTW523_WORK_INVALID,
} ztw523_work_status;

typedef enum {
    ZTW523_NOT_READY = 0,
    ZTW523_READY,
} ztw523_device_status;

typedef enum {
    MC_BUTTON_RELEASE = 0, /* button release */
    MC_BUTTON_PRESSED = 1, /* button pressed */
} button_event_type;

typedef enum {
    MC_TOUCHKEY_EVENT_PRESS = 0,
    MC_TOUCHKEY_EVENT_RELASSE,
    MC_TOUCHKEY_EVENT_LONG_PRESS,
    MC_TOUCHKEY_EVENT_INVALID,
} touch_key_event_type;

typedef enum {
    ZTW523_GESTURE_NONE = 0,
    ZTW523_GESTURE_SIGNAL_CLICK = 1,
    ZTW523_GESTURE_DOUBLE_CLICK = 2,
    ZTW523_GESTURE_SLIDE_UP = 4,
    ZTW523_GESTURE_SLIDE_DOWN = 5,
} ztw523_gesture_event;

typedef enum {
    ZTW523_IRQ_DISABLE = 0,
    ZTW523_IRQ_ENABLE,
} ztw523_irq_status;

typedef enum {
    MC_TP_NORMAL_WORK_MODE = 0, /* tp normal mode */
    MC_TP_STANDBY_WORK_MODE,    /* tp idle mode */
    MC_TP_BOOTLOADER_WORK_MODE,
    MC_TP_SLEEP_WORK_MODE,
    MC_TP_SUSPEND_SCAN,
    MC_TP_RESUME_SCAN,
    MC_TP_MAX_MODE,
} tp_work_mode;

typedef enum {
    MC_TP_UPGRADE_NEED_FLAG,
    MC_TP_UPGRADE_START_ASYN,
    MC_TP_UPGRADE_STATUS,
    MC_TP_UPGRADE_SYNC,
} mc_tp_upgrade;

typedef struct {
    uint32_t reset_gpio;
    uint32_t int_gpio;
    i2c_bus_t i2c_id;
    uint32_t i2c_baudrate;
} tp_peripheral_attr;

typedef struct {
    uint16_t button_code;
} button_dev_info;

typedef struct {
    uint16_t xchannel_num;
    uint16_t ychannel_num;
    uint16_t total_dnd_num;
    uint16_t total_self_dnd_num;
} ztw523_panel_data;

typedef struct {
    uint32_t skip_cnt;
    int16_t dnd_data[ZTW523_TSP_DND_NUM];
    int16_t self_dnd_data[ZTW523_TSP_SELFDND_NUM];
} ztw523_tsp_rawdata;

typedef enum {
    MC_TP_RAW_DATA,
    MC_TP_BASE_DATA,
    MC_TP_NOS_DATA,
    MC_TP_SIG_DATA,
    MC_TP_FT_DATA,
    MC_TP_NT_DATA,
    MC_TP_MAX_DATA,
    MC_TP_CM_CP_DATA,     /* 7, CM CP data */
    MC_TP_INT_COUNT_DATA, /* 8, TP Int count */
    MC_TP_NOISE_METRICS_DATA,
    MC_TP_DATA_STRUCTURE_DATA,
    MC_TP_PANEL_SCAN_CM_DATA,
    MC_TP_PANEL_SCAN_CP_DATA,
    MC_TP_START_RAW_TRANS,
    MC_TP_STOP_RAW_TRANS,
    MC_TP_START_GET_WATER_TEMPR, /* 15, start get and print water level and temprature */
    MC_TP_STOP_GET_WATER_TEMPR,  /* 16, stop get and print water level and temprature */
    MC_TP_RAW_MAX,
} mc_tp_rawdata;

typedef struct {
    mc_tp_rawdata cmd;
    uint8_t *data_buf;
    uint8_t data_in_len;
    uint32_t data_out_len;
    uint32_t data_addr;
} touch_rawdata_info;

/* define for drv process talbe */
typedef ext_errno (*touch_drv_upgrade_handle)(uint8_t *data_buff, uint8_t buf_len);
typedef struct {
    mc_tp_upgrade cmd_id;
    touch_drv_upgrade_handle process_cb;
} touch_drv_upgrade_proc;

typedef ext_errno (*touch_hal_rawdata_handle)(uint8_t *data_buf, uint8_t buf_len);
typedef struct {
    mc_tp_rawdata cmd_id;
    touch_hal_rawdata_handle process_cb;
} touch_drv_rawdata_proc;

typedef struct {
    uint16_t chip_id;
    uint16_t vendor_id;
    uint16_t chip_hw_id;
    uint8_t chip_info[ZTW523_DEVICE_INFO_SIZE];
    uint16_t firmware_version;
    uint16_t minor_firmware_version;
    uint16_t reg_version;
    uint32_t flash_fw_version;
    uint16_t int_mask;
    uint16_t touch_mode;
    uint32_t irq_count;
    uint32_t touch_count;
    uint32_t page_size;
    uint16_t header_size;
    uint16_t image_size;
    osal_mutex ops_mux;
    bool fw_upgrade_flag;
    bool gesture_wakeup;
    bool host_dev_init_flag;
    ztw523_sw_power_status power_status;
    ztw523_work_status work_status;
    ztw523_sw_power_status chip_sw_power_status;
    ztw523_device_status chip_status;
    input_event_info touch_msg;
    ztw523_panel_data panel_info;
    tp_peripheral_attr dev_attr;
    ztw523_tsp_rawdata tsp_raw_data;
    void *p_void;
    uint32_t tp_event;
    touch_drv_upgrade_proc upgrade_table[ZTW523_FWGRADE_CMD_NUM];
    touch_drv_rawdata_proc raw_data_table[ZTW523_RAWDATA_CMD_NUM];
} ztw523_drv_data;

ext_errno ztw523_init(void);
ext_errno ztw523_deinit(void);
ext_errno ztw523_set_power_mode(tp_work_mode power_mode);
ext_errno ztw523_get_power_mode(uint32_t *power_mode);
ext_errno ztw523_resume(void);
ext_errno ztw523_irq_callback(uint8_t *data_buf, uint8_t data_len);
ext_errno ztw523_host_init_sample(void);
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif

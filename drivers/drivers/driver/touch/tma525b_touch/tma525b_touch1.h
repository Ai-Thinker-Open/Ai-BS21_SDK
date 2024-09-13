/*
 * Copyright (c) @CompanyNameMagicTag 2021-2022. All rights reserved.
 * Description: tma525b touch driver.
 * Author: @CompanyNameTag
 * Create: 2021-05-29
 */

#ifndef TMA525B_TOUCH1_H
#define TMA525B_TOUCH1_H

#include "stdio.h"
#include "soc_errno.h"
#include "soc_osal.h"
#include "touch_screen_def.h"
#include "cmsis_os2.h"
#include "platform_core.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define high_byte(x)            (uint8_t)(((x) >> 8) & 0xFF)
#define low_byte(x)             (uint8_t)((x) & 0xFF)
#define set_cmd_low(byte, bits) \
    ((byte) = (((byte) & 0xF0) | ((bits) & 0x0F)))
#define set_cmd_high(byte, bits) \
    ((byte) = (((byte) & 0x0F) | ((bits) & 0xF0)))

#define set_cmd_opcode(data, opcode)          set_cmd_low(data, opcode)
#define set_cmd_report_type(data, reporttype) set_cmd_high(data, ((reporttype) << 4))
#define set_cmd_report_id(data, reportid)     set_cmd_low(data, reportid)

#define hid_output_app_command(command) \
    .cmdtype = HID_OUTPUT_CMD_APP,      \
    .cmdcode = (command)

#define hid_output_bl_command(command) \
    .cmdtype = HID_OUTPUT_CMD_BL,      \
    .cmdcode = (command)

/* tma525b definitions */
/* max wait time */
#define TMA525B_OPERATER_MUTEX_WAIT_TIME 3000 /* operater tp mutex timeout ms */
#define TMA525B_CMCP_WAIT_TIMEOUT        1000
/* define some properties value */
#define TMA525B_ENABLE                   0x0001
#define TMA525B_DISABLE                  0x0000
#define TMA525B_DATA_LEN                 2


#define TMA525B_RESETHIGH_DELAY          10
#define TMA525B_CLEARINT_DELAY           10
#define TMA525B_FIRMWAREON_DELAY         200
#define TMA525B_INIT_RETRY_TIMERS        3
#define TMA525B_SETMODE_RETRY_TIMERS     3
#define TMA525B_SOFTRESET_RETRY_TIMES    10
#define TMA525B_RETRY_TIMES              10
#define TMA525B_DEVICE_INFO              "zinitix,tma525b"
#define TMA525B_DEVICE_INFO_SIZE         sizeof(TMA525B_DEVICE_INFO)
#define TMA525B_MAX_SUPPORTED_FINGER_NUM 1
#define TMA525B_POINT_MODE               1
#define TMA525B_CALIB_TOUCH_MODE         0x07
#define TMA525B_REGDATA_SHIFT            8
#define TMA525B_GENERAL_DELAY_1          1
#define TMA525B_GENERAL_DELAY_5          5
#define TMA525B_GENERAL_DELAY_10         10
#define TMA525B_GENERAL_DELAY_20         20
#define TMA525B_GENERAL_DELAY_25         25
#define TMA525B_GENERAL_DELAY_30         30
#define TMA525B_GENERAL_DELAY_50         50
#define TMA525B_GENERAL_DELAY_100        100
#define TMA525B_GENERAL_DELAY_200        200
#define TMA525B_GENERAL_DELAY_500        500
#define TMA525B_GENERAL_RETRY_1          1
#define TMA525B_GENERAL_RETRY_2          2
#define TMA525B_GENERAL_RETRY_3          3
#define TMA525B_GENERAL_RETRY_4          4
#define TMA525B_GENERAL_RETRY_10         10
#define TMA525B_RAWDATA_DELAY_FOR_HOST   100
#define TMA525B_FW_JUMP_CODE             0x0048
#define TMA525B_REPORT_RATE              60
#define TMA525B_PIXEL_THRESHOLD          5

#ifndef TMA525B_RES_MAX_X
#define TMA525B_RES_MAX_X 453
#endif

#ifndef TMA525B_RES_MAX_Y
#define TMA525B_RES_MAX_Y 453
#endif

#define TMA525B_TOUCHINFO_HEAD_LEN 4
#define TMA525B_POINTINFO_LEN      6
#define TMA525B_TOUCHINFO_LEN (TMA525B_TOUCHINFO_HEAD_LEN + TMA525B_POINTINFO_LEN * TMA525B_MAX_SUPPORTED_FINGER_NUM)

#define TMA525B_INT_NONE            0x0000
#define TMA525B_INT_MASK            0x001F
#define TMA525B_PALM_MASK           0x0010
#define TMA525B_GESTURE_WAKEUP_INIT 0
#define TMA525B_FIRMWARE_SIZE       48
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
#define TMA525B_CHIP_ID             0xE628
/* define touch info offset */
#define TMA525B_STATUSL_OFFSET   0
#define TMA525B_STATUSH_OFFSET   1
#define TMA525B_EVENTL_OFFSET    2
#define TMA525B_EVENTH_OFFSET    3
#define TMA525B_WIDTH_OFFSET     8
#define TMA525B_SUBSTATUS_OFFSET 9
/* define data shift and mask */
#define TMA525B_SHIFT_8_BIT  8
#define TMA525B_SHIFT_16_BIT 16
#define TMA525B_SHIFT_24_BIT 24
#define TMA525B_MASK_BYTE    0xFF
/* define TMA525B_HIGH_SPEED_DMA rely on iic dma support */
#ifdef TMA525B_HIGH_SPEED_DMA
#define TMA525B_TOUCH_POINT_MODE 0
#else
#define TMA525B_TOUCH_POINT_MODE 1
#endif

#define TMA525B_SEC_MODE        48
#define TMA525B_NORMAL_MODE     5
#define TMA525B_DND_MODE        11 /* mutual cap */
#define TMA525B_SELF_DND_MODE   17 /* self cap */
#define TMA525B_DNDSKIP_CNT     1
#define TMA525B_SELFDNDSKIP_CNT 1
/* Config Reg Info */
#define TMA525B_REG_CMD_ENABLE    0xC000
#define TMA525B_REG_CHIP_ID       0xCC00
#define TMA525B_REG_INTN_CLEAR    0xC004
#define TMA525B_REG_NVM           0xC002
#define TMA525B_REG_NVM_VPP       0xC003
#define TMA525B_REG_NVM_WP        0xC104
#define TMA525B_REG_PROGRAM_START 0xC001
#define TMA525B_POWER_CTL_BEGIN   0x000A
#define TMA525B_POWER_CTL_END     0x000B
#define TMA525B_CALIB_CTL1        0xC003
#define TMA525B_CALIB_CTL2        0xC104
#define TMA525B_SDRAM_RESET       0x0FF8
#define TMA525B_REPORT_REG        0x0186  /* 设置中断上报频率 */
#define TMA525B_PIXEL_THRESHOLD_REG 0x00C3
/* Register Map */
#define TMA525B_SWRESET_CMD                   0x0000
#define TMA525B_WAKEUP_CMD                    0x0001
#define TMA525B_IDLE_CMD                      0x0004
#define TMA525B_SLEEP_CMD                     0x0005
#define TMA525B_CLEAR_INT_STATUS_CMD          0x0003
#define TMA525B_CALIBRATE_CMD                 0x0006
#define TMA525B_SAVE_STATUS_CMD               0x0007
#define TMA525B_SAVE_CALIBRATION_CMD          0x0008
#define TMA525B_RECALL_FACTORY_CMD            0x000f
#define TMA525B_SENSITIVITY                   0x0020
#define TMA525B_I2C_CHECKSUM_WCNT             0x016a
#define TMA525B_I2C_CHECKSUM_RESULT           0x016c
#define TMA525B_DEBUG_REG                     0x0115 /* 0~7 */
#define TMA525B_TOUCH_MODE                    0x0010
#define TMA525B_CHIP_REVISION                 0x0011
#define TMA525B_FIRMWARE_VERSION              0x0012
#define TMA525B_MINOR_FW_VERSION              0x0121
#define TMA525B_DATA_VERSION_REG              0x0013
#define TMA525B_HW_ID                         0x0014
#define TMA525B_SUPPORTED_FINGER_NUM          0x0015
#define TMA525B_EEPROM_INFO                   0x0018
#define TMA525B_INITIAL_TOUCH_MODE            0x0019
#define TMA525B_CHIP_HW_REVISION              0x001A
#define TMA525B_IC_VENDOR_ID                  0x001C
#define TMA525B_TSM_MODULE_ID                 0x001E
#define TMA525B_TOTAL_NUMBER_OF_X             0x0060
#define TMA525B_TOTAL_NUMBER_OF_Y             0x0061
#define TMA525B_DELAY_RAW_FOR_HOST            0x007f
#define TMA525B_BUTTON_SUPPORTED_NUM          0x00B0
#define TMA525B_BUTTON_SENSITIVITY            0x00B2
#define TMA525B_X_RESOLUTION                  0x00C0
#define TMA525B_Y_RESOLUTION                  0x00C1
#define TMA525B_POINT_STATUS_REG              0x0080
#define TMA525B_ICON_STATUS_REG               0x00AA
#define TMA525B_AFE_FREQUENCY                 0x0100
#define TMA525B_DND_N_COUNT                   0x0122
#define TMA525B_DND_U_COUNT                   0x0135
#define TMA525B_RAWDATA_REG                   0x0200
#define TMA525B_EEPROM_INFO_REG               0x0018
#define TMA525B_INT_ENABLE_FLAG               0x00f0
#define TMA525B_PERIODICAL_INTERRUPT_INTERVAL 0x00f1
#define TMA525B_CHECKSUM_RESULT               0x012c
#define TMA525B_GESTURE_WAKEUP_REG            0x0126

#define TMA525B_TOUCHINFO_MASK 0x0F
#define TMA525B_TOUCH_EXIST    0x01
#define TMA525B_TOUCH_DOWN     0x03
#define TMA525B_TOUCH_MOVE     0x05
#define TMA525B_TOUCH_UP       0x08
#define TMA525B_TOUCH_NONE     0x07

#define TMA525B_SUB_BIT_EXIST  0
#define TMA525B_SUB_BIT_DOWN   1
#define TMA525B_SUB_BIT_MOVE   2
#define TMA525B_SUB_BIT_UP     3
#define TMA525B_SUB_BIT_UPDATE 4
#define TMA525B_SUB_BIT_WAIT   5

#ifndef TMA525B_TSP_X_CHANNEL_NUM
#define TMA525B_TSP_X_CHANNEL_NUM 6
#endif

#ifndef TMA525B_TSP_Y_CHANNEL_NUM
#define TMA525B_TSP_Y_CHANNEL_NUM 6
#endif

#define TMA525B_TSP_DND_NUM     (TMA525B_TSP_X_CHANNEL_NUM * TMA525B_TSP_Y_CHANNEL_NUM)
#define TMA525B_TSP_SELFDND_NUM (TMA525B_TSP_X_CHANNEL_NUM + TMA525B_TSP_Y_CHANNEL_NUM)

#define tma525b_bit_test(val, n) ((val) & (1 << (n)))

/* firmware info */
#define TMA525B_FIRMWARE_VERSION_L            0
#define TMA525B_FIRMWARE_VERSION_H            1
#define TMA525B_FIRMWARE_VERSION_OFFSET       52
#define TMA525B_FIRMWARE_MINOR_VERSION_OFFSET 56
#define TMA525B_FIRMWARE_DATA_VERSION_OFFSET  60
#define TMA525B_FIRMWARE_OFFSET_ZERO          0
#define TMA525B_FIRMWARE_CONVERT_DATA_STEP    2
#define TMA525B_FIRMWARE_CONVERT_DATA_OFFSET  1
/* file op code */
#define TMA525B_FILE_ERROR (-1)
#define TMA525B_FILE_OK    0
/* upgrade info */
#define TMA525B_FWGRADE_CMD_NUM 3
/* rawdata info */
#define TMA525B_RAWDATA_CMD_NUM 2
/* define gesture macro */
#define TMA525B_GESTURE_WAKEUP 1

/* self_dnd dnd parameter */
#define TMA525B_SEC_SELF_DND_N_COUNT      15
#define TMA525B_SEC_SELF_DND_U_COUNT      2
#define TMA525B_SEC_SELF_DND_FREQUENCY    80

#define TMA525B_SEC_DND_N_COUNT           27
#define TMA525B_SEC_DND_U_COUNT           3
#define TMA525B_SEC_DND_FREQUENCY         240

#ifndef array_size
#define array_size(x)   (sizeof(x) / sizeof((x)[0]))
#endif

#define TMA525B_DETECT_DATA_LEN  1
#define TMA525B_INPUT_SIZE_LEN   2
#define TMA525B_POWERON_DELAY    10
#define TMA525B_RESETHIGH_DELAY  10
#define TMA525B_POWEROFF_DELAY   10
#define TMA525B_RESET_HIGH_DELAY 20
#define TMA525B_RESET_LOW_DELAY  40
#define TMA525B_RESETOFF_DELAY   2
#define TMA525B_RESET_DELAY      20
#define TMA525B_CMD_RESP_DELAY   20
#define TMA525B_DETECT_DELAY     120 /* reset delay for detect,may need to leave some margin for first int 120ms */
#define TMA525B_FORCE_UPGRADE    0x100

#define TMA525B_RESERVERD_4BYTE 4
/* max wait time */
#define TMA525B_OPERATER_MUTEX_WAIT_TIME      3000 /* operater tp mutex timeout ms */
#define TMA525B_SYSTEM_MUTEX_WAIT_TIME        1000 /* tp internal mutex timeout ms */
#define TMA525B_SEMAPHORE_WAIT_MAX_TIME_RESET 1000 /* tp reset INT semaphore timeout ms */
#define ELEMENT_SIZE       2
#define CALIB_SIZE         2
#define TMA525B_RX_NUM 8
#define TMA525B_TX_NUM 6
#define CM_VALUE_SIZE      (TMA525B_TX_NUM * TMA525B_RX_NUM)             /* 36 or 49 */
#define CP_VALUE_SIZE      (TMA525B_TX_NUM + TMA525B_RX_NUM)             /* 12 or 14 */
#define CM_VALUE_LEN       (CM_VALUE_SIZE * ELEMENT_SIZE)                /* 72 or 98 */
#define CP_VALUE_LEN       (CP_VALUE_SIZE * ELEMENT_SIZE)                /* 24 or 28 */
#define CP_TX_LEN          (TMA525B_TX_NUM * ELEMENT_SIZE)               /* 12 or 14 */
#define CP_RX_LEN          (TMA525B_RX_NUM * ELEMENT_SIZE)               /* 12 or 14 */
#define CP_TX_CALIB_LEN    (TMA525B_TX_NUM * ELEMENT_SIZE)               /* 12 or 14 */
#define CP_RX_CALIB_LEN    (TMA525B_RX_NUM * ELEMENT_SIZE)               /* 12 or 14 */
#define CP_VALUE_CALIB_LEN (CP_VALUE_SIZE * (ELEMENT_SIZE + CALIB_SIZE)) /* 48 or 56 */
/* CRC */
#define CRC_BIT_LEN         8
#define CRC_SHIFT_4         4
#define CRC_MASK            0x0F
#define CRC_TABLE_16        16
#define CRC_LOWBYTE_OFFSET  3
#define CRC_HIGHBYTE_OFFSET 2
#define CRC_CALC_OFFSET     7
/* register address and len define */
#define TMA525B_HID_DESC_REGISTER_ADDR 0x0001
#define TMA525B_OUTPUT_REGISTER_ADDR   0x0004
#define TMA525B_COMMAND_REGISTER_ADDR  0x0005
#define TMA525B_OUTPUT_REG_ADDR_LEN    2
#define TMA525B_OUTPUT_SIZE 156
#define TMA525B_INPUT_SIZE  156
#define get_input_size(pbuf)     (((uint16_t)((pbuf)[1]) << 8) | ((uint16_t)((pbuf)[0])))
#define get_unaligned_le16(pbuf) (((*((uint8_t *)(pbuf) + 1)) << 8) | (*((uint8_t *)(pbuf))))
/* output and response offset */
#define RESP_OFFSET_SOP_4     4
#define RESP_OFFSET_STATUS_5  5
#define RESP_OFFSET_SUMMARY_6 6
#define RESP_OFFSET_RST_7     7
#define RESP_OFFSET_TESTID_6  6
#define RESP_OFFSET_LENLOW_7  7
#define RESP_OFFSET_FORMAT_9  9
#define RESP_OFFSET_VALUE_10  10
#define OUT_REG_ADDR_LEN      2
#define OUT_OFFSET_SOP_6      6
/* reset int num */
#define TMA525B_RESET_INIT_NUM            0
#define TMA525B_RESET_BOOTLOADER_INT_NUM  1
#define TMA525B_RESET_APPLICATION_INT_NUM 2
/* data len and data shift and mask define */
#define TMA525B_SHIFT_8_BIT  8
#define TMA525B_SHIFT_16_BIT 16
#define TMA525B_SHIFT_24_BIT 24
#define TMA525B_DATALEN_1    1
#define TMA525B_DATALEN_2    2
#define TMA525B_DATALEN_3    3
#define TMA525B_DATALEN_4    4
#define TMA525B_DATALEN_5    5
#define TMA525B_DATALEN_6    6
#define TMA525B_DATALEN_7    7
#define TMA525B_OFFSET_0     0
#define TMA525B_OFFSET_1     1
#define TMA525B_OFFSET_2     2
#define TMA525B_OFFSET_3     3
#define TMA525B_OFFSET_4     4
#define TMA525B_OFFSET_5     5
#define TMA525B_OFFSET_6     6
#define TMA525B_OFFSET_7     7

#define TMA525B_APPLICATION_CMD_LEN 5
#define TMA525B_BOOTLOADER_CMD_LEN  11

#define TMA525B_REPORTID_SHIFT 2
#define TMA525B_ESD_SHIFT      5

#define TMA525B_ESD_MASK 0x80
/* Timeout in ms */
#define TMA525B_REQUEST_EXCLUSIVE_TIMEOUT                8000
#define TMA525B_WATCHDOG_TIMEOUT                         3000
#define TMA525B_HID_RESET_TIMEOUT                        1000
#define TMA525B_HID_GET_HID_DESCRIPTOR_TIMEOUT           500
#define TMA525B_HID_GET_REPORT_DESCRIPTOR_TIMEOUT        500
#define TMA525B_HID_SET_POWER_TIMEOUT                    500
#define TMA525B_HID_OUTPUT_TIMEOUT                       1000 /* 300 */
#define TMA525B_HID_OUTPUT_START_BOOTLOADER_TIMEOUT      2000
#define TMA525B_HID_OUTPUT_USER_TIMEOUT                  8000
#define TMA525B_HID_OUTPUT_GET_SYSINFO_TIMEOUT           3000
#define TMA525B_HID_OUTPUT_BL_READ_IMAGE_TIMEOUT         1000
#define TMA525B_HID_OUTPUT_CALIBRATE_IDAC_TIMEOUT        5000
#define TMA525B_HID_OUTPUT_WRITE_CONF_BLOCK_TIMEOUT      400
#define TMA525B_HID_OUTPUT_RUN_SELF_TEST_TIMEOUT         2000
/* initiate bootloader:erase 64K flash time is about 14s */
#define TMA525B_HID_OUTPUT_BL_INITIATE_BL_TIMEOUT        20000
#define TMA525B_HID_OUTPUT_BL_PROGRAM_AND_VERIFY_TIMEOUT 400   /* i2c write 144 bytes data */

/* Touch Info */
#define TMA525B_TYPE_TOUCH_DOWN  0x20
#define TMA525B_TYPE_TOUCH_UP    0x60
#define TMA525B_TYPE_TOUCH_MOVE 0x40

#define TMA525B_REPORT_DATA_LEN             107
#define TMA525B_RECORD_LEN_L_OFFSET         0
#define TMA525B_RECORD_LEN_H_OFFSET         1
#define TMA525B_RECORD_LEN_BYTE             2
#define TMA525B_EVENT_OFFSET                8
#define TMA525B_XL_OFFSET                   9
#define TMA525B_XH_OFFSET                   10
#define TMA525B_YL_OFFSET                   11
#define TMA525B_YH_OFFSET                   12
#define TMA525B_REPORT_ID_OFFSET            2
#define TMA525B_REPORT_TOUCH_INT            0X01
#define TMA525B_REPORT_GESTURE_WAKEUP       0X04
#define TMA525B_MASK_EVENT_BIT              0x60
#define TMA525B_RECORD_LO_OFFSET            5
#define TMA525B_RECORD_LO_BIT_MASK          0x20
#define TMA525B_RECORD_FINGER_BIT_MASK      0x1F
#define TMA525B_RECORD_LO_BIT_OFFSET        5
#define TMA525B_RECORD_COUNTER_NOISE_OFFSET 6 /* report counter and noise effects byte */
#define TMA525B_RECORD_NOISE_BIT_MASK       0x07

/* HID */
#define HID_CYVENDOR       0xff010000
#define CHID_VENDOR_ID     0x04B4
#define HID_BL_PRODUCT_ID  0xC100
#define HID_APP_PRODUCT_ID 0xC101
#define HID_VERSION        0x0100
#define HID_APP_REPORT_ID  0xF7 /* APPLICATION REPORT ID */
#define HID_BL_REPORT_ID   0xFF /* BOOTLOADER REPORT ID */

#define HID_INVALID_REPORT_ID         0x0
#define HID_TOUCH_REPORT_ID           0x1
#define HID_BTN_REPORT_ID             0x3 /* BOTTON REPORT ID */
#define HID_WAKEUP_REPORT_ID          0x4 /* GESTURE REPORT ID */
#define HID_NOISE_METRIC_REPORT_ID    0x5
#define HID_TRACKING_HEATMAP_REPOR_ID 0xE
#define HID_SENSOR_DATA_REPORT_ID     0xF
#define HID_APP_RESPONSE_REPORT_ID    0x1F /* SYSINFO REPORT ID */
#define HID_APP_OUTPUT_REPORT_ID      0x2F
#define HID_BL_RESPONSE_REPORT_ID     0x30
#define HID_BL_OUTPUT_REPORT_ID       0x40
#define HID_RESPONSE_REPORT_ID        0xF0

#define HID_OUTPUT_RESPONSE_REPORT_OFFSET 2
#define HID_OUTPUT_RESPONSE_CMD_OFFSET    4
#define HID_OUTPUT_RESPONSE_CMD_MASK      0x7F
#define HID_OUTPUT_CMD_OFFSET             6
#define HID_OUTPUT_CMD_MASK               0x7F

#define HID_SYSINFO_CYDATA_OFFSET  5
#define HID_SYSINFO_SENSING_OFFSET 33
#define HID_SYSINFO_BTN_OFFSET     48
#define HID_SYSINFO_BTN_MASK       0xF
#define HID_SYSINFO_MAX_BTN        4

#define HID_POWER_ON                   0x0
#define HID_POWER_SLEEP                0x1
#define HID_LENGTH_BYTES               2
#define HID_LENGTH_AND_REPORT_ID_BYTES 3

#define HID_OUTPUT_BL_SOP           0x1
#define HID_OUTPUT_BL_EOP           0x17
#define HID_OUTPUT_BL_RESP_SIZE_MIN 11
#define HID_OUTPUT_CMD_DIFF         1
/*
 * Before PIP 1.7, empty buffer is 0x0002;
 * From PIP 1.7, empty buffer is 0xFFXX
 */
#define TMA525B_EMPTY_PIP1P7_BEFORE      0x0002
#define TMA525B_EMPTY_PIP1P7_LATER       0xFF00
#define TMA525B_MAX_SUPPORTED_FINGER_NUM 1
#define TMA525B_RECORD_SIZE              17
#define TMA525B_REPORT_HEAD_SIZE         7
#define TMA525B_REPORT_SIZE              TMA525B_RECORD_SIZE * TMA525B_MAX_SUPPORTED_FINGER_NUM
#define TMA525B_REPORT_SIZE_TWO_FINGER   27

/* sysinfo struct define */
#define TMA525B_PIP_MAJOR_VER_OFFSET 5
#define TMA525B_PIP_MINOR_VER_OFFSET 6
#define TMA525B_FW_MAJOR_VER_OFFSET  9
#define TMA525B_FW_MINOR_VER_OFFSET  10
#define T525_REVCTRL_L0_OFFSET       11
#define T525_REVCTRL_L1_OFFSET       12
#define T525_REVCTRL_H0_OFFSET       13
#define T525_REVCTRL_H1_OFFSET       14
#define TMA525B_CFG_VER_L_OFFSET     15
#define TMA525B_CFG_VER_H_OFFSET     16
#define TMA525B_BL_MAJOR_VER_OFFSET  17
#define TMA525B_BL_MINOR_VER_OFFSET  18
#define TMA525B_REVISION_ID_OFFSET   20
#define TMA525B_SILICON_L_OFFSET     21
#define TMA525B_SILICON_H_OFFSET     22
#define TMA525B_PANEL_ID_OFFSET      47
#define TMA525B_BL_PANEL_ID_OFFSET   12

/* file op code */
#define TMA525B_FILE_ERROR (-1)
#define TMA525B_FILE_OK    0

/* err code */
#define COMMAND_SEND_FAIL      (-10)
#define WAIT_EVENT_TIMEOUT     (-20)
#define RESPONSE_VALIDATE_FAIL (-30)
#define RELEASE_EVENT_FAIL     (-40)

/* raw data info */
#define TMA525B_RAWDATA_CMD_NUM    2
#define TMA525B_NOISE_OFFSET_L     7
#define TMA525B_NOISE_OFFSET_H     8
#define TMA525B_TOUCH_TYPE_OFFSET  11
#define TMA525B_WATER_LEVEL_OFFSET 12
#define TMA525B_MONITOR_OFFSET_L   23
#define TMA525B_MONITOR_OFFSET_H   24
/* define idac info */
#define TMA525B_IDAC_NUM               6
#define TMA525B_DATASTRUCT_NUM         8
#define TMA525B_IDAC_LEN               10
#define TMA525B_GAIN_CORRECTION        4
#define TMA525B_GAIN_LEN               TMA525B_RX_NUM *TMA525B_GAIN_CORRECTION
#define TMA525B_TRIM_LEN               TMA525B_RX_NUM
#define TMA525B_IDAC_SIZE              TMA525B_IDAC_LEN *TMA525B_IDAC_NUM
#define TMA525B_PININDEX_LEN           1
#define TMA525B_IDAC_OFFSET_OFFSET_L   0
#define TMA525B_IDAC_OFFSET_OFFSET_H   1
#define TMA525B_IDAC_LENGTH_OFFSET_L   2
#define TMA525B_IDAC_LENGTH_OFFSET_H   3
#define TMA525B_IDAC_DATAID_OFFSET     4
#define TMA525B_IDAC_CENTORFREQ_DATAID 0x00
#define TMA525B_IDAC_FREQ1_DATAID      0x04
#define TMA525B_IDAC_FREQ2_DATAID      0x05
#define TMA525B_IDAC_FREQ3_DATAID      0x07
#define TMA525B_IDAC_FREQ5_DATAID      0x09
#define TMA525B_MUTUALGAIN_DATAID      0x10
#define TMA525B_SELFGAIN_DATAID        0x11
#define TMA525B_ATTENTRIM_DATAID       0x12
#define TMA525B_PININDEX_DATAID        0x13
/* retrieve panel scan data */
#define TMA525B_PANELINFO_0               0
#define TMA525B_PANELINFO_1               1
#define TMA525B_PANELINFO_2               2
#define TMA525B_PANELINFO_NUM             3
#define MUTUAL_CAP_RAW_DATA_ID            0x00
#define MUTUAL_CAP_BASELINE_DATA_ID       0x01
#define MUTUAL_CAP_DIFF_DATA_ID           0x02
#define SELF_CAP_RAW_DATA_ID              0x03
#define SELF_CAP_BASELINE_DATA_ID         0x04
#define SELF_CAP_DIFF_DATA_ID             0x05
#define TMA525B_PANELINFO_OFFSET_OFFSET_L 0
#define TMA525B_PANELINFO_OFFSET_OFFSET_H 1
#define TMA525B_PANELINFO_LENGTH_OFFSET_L 2
#define TMA525B_PANELINFO_LENGTH_OFFSET_H 3
#define TMA525B_PANELINFO_DATAID_OFFSET   4
#define TMA525B_ELEMENT_SIZE_MASK         0x07
/* config version info */
#define TMA525B_CONFIG_VERSION_LEN 2
/* define power mode info */
#define TMA525B_PM_LENGTH1_OFFSET         0
#define TMA525B_PM_LENGTH2_OFFSET         1
#define TMA525B_PM_REPORTID_OFFSET        2
#define TMA525B_PM_POWERSTATE_OFFSET      3
#define TMA525B_PM_OPCODE_OFFSET          4
#define TMA525B_POWERMODE_POWERSTATE_MASK 0x3
#define TMA525B_POWERMODE_OPCODE_MASK     0xF
#define TMA525B_POWERMODE_NORMAL          0
#define TMA525B_POWERMODE_SLEEP           1
#define TMA525B_POWERMODE_EASYWAKE_STATUS 1
/* define cmd out info */
#define TMA525B_CMD_REG_LEN   2
#define TMA525B_CMD_LEN       2
#define TMA525B_HID_CMD_OUT_F 0xF
#define TMA525B_REPORTID_LEN  1
#define TMA525B_DATA_REG_LEN  2
/* define gesture info */
#define TMA525B_WAKEUP_RECORD_LEN    8
#define TMA525B_EVENT_CODE_OFFSET    3
#define TMA525B_GESTURE_DOUBLE_CLICK 0x01
#define TMA525B_GESTURE_SINGLE_CLICK 0x03
#define TMA525B_GESTURE_SLIDE_UP     0x07
#define TMA525B_GESTURE_SLIDE_DOWN   0x08

#define INPUT_DEV_NAME_LEN      15

typedef enum {
    MC_TOUCHKEY_EVENT_PRESS = 0,
    MC_TOUCHKEY_EVENT_RELASSE,
    MC_TOUCHKEY_EVENT_LONG_PRESS,
    MC_TOUCHKEY_EVENT_INVALID,
} touchkeyeventtype;

typedef struct {
    uint16_t buttoncode;
} buttondevinfo;

typedef struct {
    uint16_t reserved;
} touchkeydevinfo;

typedef enum buttoneventtype {
    /** 按键被释放 */
    BUTTON_RELEASE = 0,
    /** 按键被按下 */
    BUTTON_PRESS,
    /** 按键短按 */
    BUTTON_SHORT_PRESS,
    /** 按键1s长按 */
    BUTTON_ONESEC_PRESS,
    /** 按键普通长按，时长为1.5s */
    BUTTON_LONG_PRESS,
    /** 按键关机事件长按 */
    BUTTON_POWER_OFF_PRESS,
    /** 按键双击 */
    BUTTON_DOUBLE_PRESS,
    /** 按键3s长按 */
    BUTTON_THREESEC_PRESS,
    /** 按键6s强制关机 */
    BUTTON_SHUTDOWN_PRESS,
    /** 异常按键事件 */
    BUTTON_UNKNOWN,
} buttoneventtype;

typedef enum {
    /** 手指触摸 */
    TP_PRESS = 0,
    /** 手指抬起 */
    TP_RELEASE = 1,
    /** 手指触摸后滑动 */
    TP_MOVE = 2,
    /** 主表盘盖屏 */
    TP_COVER = 3,
    /** 手指单击 */
    TP_SHORT_CLICK = 4,
    /** 手指双击 */
    TP_DOUBLE_CLICK = 5,
    /** 上滑 */
    TP_SLIDE_UP = 6,
    /** 下滑 */
    TP_SLIDE_DOWN = 7,
    /** 异常TP事件 */
    TP_INVALID,
} toucheventtype;

typedef struct {
    uint16_t xaxis[TP_FIGURE_NUM_SUPPORT];
    uint16_t yaxis[TP_FIGURE_NUM_SUPPORT];
    uint16_t zaxis[TP_FIGURE_NUM_SUPPORT];
} touchdevinfo;

typedef struct {
    InputDevType inputtype;
    union {
        buttoneventtype buttonevent;
        toucheventtype tpevent;
        touchkeyeventtype touchkeyevent;
    };
    union {
        buttondevinfo buttoneventinfo;
        touchdevinfo tpeventinfo;
        touchkeydevinfo touchkeyeventinfo;
    };
    uint32_t timestamp;
} inputeventinfo;

typedef struct {
    osSemaphoreAttr_t attr;
    uint32_t maxcount;
    uint32_t initialcount;
} semaphoreex;

typedef enum {
    ERROR_INIT_START = -100,
    ERROR_INIT_1,
    ERROR_INIT_2,
    ERROR_INIT_3,
    ERROR_INIT_RESET,
    ERROR_INIT_GET_HID_DESC,
    ERROR_INIT_GET_MODE,
    ERROR_INIT_GET_SYSINFO,

    ERROR_CALIBRATE_START = -200,
    ERROR_CALIBRATE_SUSPEND,
    ERROR_CALIBRATE_MUTCAP,
    ERROR_CALIBRATE_MUTCAP_FAIL,
    ERROR_CALIBRATE_SELFCAP,
    ERROR_CALIBRATE_SELFCAP_FAIL,
    ERROR_CALIBRATE_RESUME,
    ERROR_GET_DATA_SUSPEND,
    ERROR_GET_DATA_ATTENUATOR,
    ERROR_GET_DATA_ATTENUATOR_FAIL,
    ERROR_GET_DATA_MUTUAL,
    ERROR_GET_DATA_MUTUAL_FAIL,
    ERROR_GET_DATA_SELF,
    ERROR_GET_DATA_SELF_FAIL,
    ERROR_GET_TRIM,
    ERROR_GET_TRIM_FAIL,
    ERROR_GET_PININDEX,
    ERROR_GET_PININDEX_FAIL,
    ERROR_GET_DATA_RESUME,
    ERROR_PANELSCAN_MUTUAL,
    ERROR_PANELSCAN_SELF,

    ERROR_OUTPUT_START = -300,
    ERROR_WAIT_EVENT_TIMEOUT,
    ERROR_COMMAND_SEND_FAIL,
    ERROR_RESPONSE_VALIDATE_FAIL,
    ERROR_RELEASE_EVENT_FAIL,
    ERROR_MEM_ALLOC_FAIL,

    ERROR_GETCMCP_START = -400,
    ERROR_GETCMCP_SUSPEND,
    ERROR_GETCMCP_SHORTS,
    ERROR_GETCMCP_CM_SELFTEST,
    ERROR_GETCMCP_CM_GETRES,
    ERROR_GETCMCP_CP_SELFTEST,
    ERROR_GETCMCP_CP_GETRES,
    ERROR_GETCMCP_RESUME,
} tma525b_errorcode;

typedef struct {
    uint16_t hiddesclen;
    uint8_t reportid;
    uint8_t reservedbyte;
    uint16_t bcdversion;
    uint16_t reportdesclen;
    uint16_t reportdescregaddr;
    uint16_t inputregaddr;
    uint16_t maxinputlen;
    uint16_t outputregaddr;
    uint16_t maxoutputlen;
    uint16_t commandregaddr;
    uint16_t dataregaddr;
    uint16_t vendorid;
    uint16_t productid;
    uint8_t majorversion;
    uint8_t minorversion;
    uint8_t reserved[TMA525B_RESERVERD_4BYTE];
} tma525b_hiddesc;

typedef enum {
    TMA525B_SYNC_CMD = 0,
    TMA525B_ASYN_CMD = 1
} tma525b_cmd_type;

typedef enum {
    RESET_TO_BOOTLOADER = 0x1,
    RESET_TO_APPLICATION = 0x2,
    RESET_TO_DETECT = 0x3,
} tma525b_reset_type;

typedef enum {
    HID_CMD_RESERVED,
    HID_CMD_RESET,
    HID_CMD_GET_REPORT,
    HID_CMD_SET_REPORT,
    HID_CMD_GET_IDLE,
    HID_CMD_SET_IDLE,
    HID_CMD_GET_PROTOCOL,
    HID_CMD_SET_PROTOCOL,
    HID_CMD_SET_POWER,
    HID_CMD_VENDOR = 0xE,
} tma525b_hidcommand;

typedef enum {
    TMA525B_POWER_NORMAL = 0,
    TMA525B_POWER_EASYWAKE,
    TMA525B_POWER_SLEEP,
} tma525b_power_mode;

typedef enum {
    HID_OUTPUT_CMD_APP = 0,
    HID_OUTPUT_CMD_BL,
} tma525b_output_type;

typedef enum {
    TMA525B_MODE_UNKNOWN,
    TMA525B_MODE_BOOTLOADER,
    TMA525B_MODE_APPLICATION,
} tma525b_mode_type;

typedef enum {
    CMD_STATUS_SUCCESS = 0,
    CMD_STATUS_FAILURE,
} tma525b_outputcmdstatus;

typedef enum {
    TMA525B_CM_DATA = 0,
    TMA525B_CP_DATA,
} tma525b_capdatatype;

typedef union {
    uint16_t rawdataflag;
    uint32_t reserved;
} tma525b_reserved_value;

typedef enum {
    HID_OUTPUT_NULL,
    HID_OUTPUT_START_BOOTLOADER,
    HID_OUTPUT_GET_SYSINFO,
    HID_OUTPUT_SUSPEND_SCANNING,
    HID_OUTPUT_RESUME_SCANNING,
    HID_OUTPUT_GET_PARAM,
    HID_OUTPUT_SET_PARAM,
    HID_OUTPUT_GET_NOISE_METRICS,
    HID_OUTPUT_RESERVED,
    HID_OUTPUT_ENTER_EASYWAKE_STATE,
    HID_OUTPUT_EXIT_EASYWAKE_STATE = 0x10,
    HID_OUTPUT_VERIFY_CONFIG_BLOCK_CRC = 0x20,
    HID_OUTPUT_GET_CONFIG_ROW_SIZE,
    HID_OUTPUT_READ_CONF_BLOCK,
    HID_OUTPUT_WRITE_CONF_BLOCK,
    HID_OUTPUT_GET_DATA_STRUCTURE,
    HID_OUTPUT_LOAD_SELF_TEST_PARAM,
    HID_OUTPUT_RUN_SELF_TEST,
    HID_OUTPUT_GET_SELF_TEST_RESULT,
    HID_OUTPUT_CALIBRATE_IDACS,
    HID_OUTPUT_INITIALIZE_BASELINES,
    HID_OUTPUT_EXEC_PANEL_SCAN,
    HID_OUTPUT_RETRIEVE_PANEL_SCAN,
    HID_OUTPUT_START_SENSOR_DATA_MODE,
    HID_OUTPUT_STOP_SENSOR_DATA_MODE,
    HID_OUTPUT_START_TRACKING_HEATMAP_MODE,
    HID_OUTPUT_INT_PIN_OVERRIDE = 0x40,
    HID_OUTPUT_STORE_PANEL_SCAN = 0x60,
    HID_OUTPUT_PROCESS_PANEL_SCAN,
    HID_OUTPUT_DISCARD_INPUT_REPORT,
    HID_OUTPUT_LAST,
    HID_OUTPUT_USER_CMD,
} tma525b_hid_output_application_cmd;

typedef enum {
    HID_OUTPUT_BL_VERIFY_APP_INTEGRITY = 0x31,
    HID_OUTPUT_BL_APPEND_DATA_BUFF = 0x37,
    HID_OUTPUT_BL_GET_INFO,
    HID_OUTPUT_BL_PROGRAM_AND_VERIFY,
    HID_OUTPUT_BL_LAUNCH_APP = 0x3B,
    HID_OUTPUT_BL_READ_IMAGE = 0x3D,
    HID_OUTPUT_BL_GET_PANEL_ID = 0x3E,
    HID_OUTPUT_BL_INITIATE_BL = 0x48,
    HID_OUTPUT_BL_LAST,
} tma525b_hid_output_boot_loader_cmd;

typedef struct {
    uint8_t opcode;
    uint8_t reporttype;
    union {
        uint8_t reportid;
        uint8_t powerstate;
    };
    uint8_t hasdatareg;
    uint32_t writelen;
    uint8_t *writebuf;
    uint8_t *readbuf;
    uint8_t waitinterrupt;
    uint8_t resetcmd;
    uint16_t timeoutms;
} tma525b_hidcmd;

typedef struct {
    uint8_t cmdtype;
    uint16_t cmdlen;
    uint8_t cmdcode;
    uint32_t datalen;
    uint8_t *databuf;
    uint8_t novalid;
    uint8_t resetexpect;
    uint16_t timeoutms;
} tma525b_hidoutput;

typedef struct {
    uint8_t pipmajorversion;
    uint8_t pipminorversion;
    uint8_t fwmajorversion;
    uint8_t fwminorversion;
    uint32_t revctrlnumber;
    uint16_t configversion;
    uint16_t siliconid;
    uint8_t revisionid;
    uint8_t blmajorversion;
    uint8_t blminorversion;
    uint8_t panelid;
} tma525b_sysinfo;

typedef struct {
    uint8_t testid;
    uint8_t status;
    uint8_t summaryresult;
    uint16_t readoffset;
    uint16_t readlen;
    uint16_t actualreadlen;
    tma525b_capdatatype datatype;
    uint8_t cmdata[CM_VALUE_LEN];
    uint8_t cpdata[CP_VALUE_CALIB_LEN];
} tma525b_cmcpdata;

typedef struct {
    uint32_t inputsize;
    uint32_t responsesize;
    uint8_t inputbuf[TMA525B_INPUT_SIZE];
    uint8_t responsebuf[TMA525B_INPUT_SIZE];
    uint8_t cmdbuf[TMA525B_OUTPUT_SIZE];
} tma525b_coredata;

typedef enum {
    TMA525B_CMD_NULL,
    TMA525B_CMD_DETECT,
    TMA525B_CMD_RESET,
    TMA525B_CMD_GET_HID_DESCRIPTOR,
    TMA525B_CMD_GET_SYSINFO,
    TMA525B_CMD_WATCHDOG,
    TMA525B_CMD_SET_WORK_MODE,
    TMA525B_CMD_FW_UPGRADE,
    TMA525B_CMD_RAWDATA,
    TMA525B_CMD_MAX,
} tma525b_cmd_status;

typedef struct {
    uint32_t chipid;
    uint32_t debug;
    uint32_t timeoutms;
    tma525b_reserved_value reservedvalue;
    uint8_t hidcmdstate;
    uint8_t hidresetcmdstate; /* record reset int count */
    tma525b_mode_type modetype;
    tma525b_power_mode powermode;
    unsigned int osready;
    unsigned int selfcheckstatus;
    unsigned int tpmsgstatus;
    volatile unsigned int intflag;
    tma525b_cmd_status cmdstatus;
    const uint16_t crctable[CRC_TABLE_16];
    osMutexId_t systemlock;
    osMutexId_t operlock;
    osSemaphoreId_t intsem;
    tma525b_coredata coredata;
    tma525b_hiddesc hiddesc;
    tma525b_sysinfo sysinfo;
    void *pvoid;
} tma525b_touch_drv_data;

/* host peripheral typedef */
typedef ext_errno (*tp_irq_callback)(void);

/* TMA525B driver typedef */
typedef enum {
    TMA525B_POWERDOWN = 0,
    TMA525B_POWERUP,
} tma525b_sw_power_status;

typedef enum {
    TMA525B_WORK_NORMAL = 0,
    TMA525B_WORK_STANDBY,
    TMA525B_WORK_GETCMCP,
    TMA525B_WORK_SLEEP,
    TMA525B_WORK_SUSPEND,
    TMA525B_WORK_RESUME,
    TMA525B_WORK_INVALID,
} tma525b_work_status;

typedef enum {
    TMA525B_NOT_READY = 0,
    TMA525B_READY,
} tma525b_device_status;

typedef enum {
    MC_BUTTON_RELEASE = 0, /* button release */
    MC_BUTTON_PRESSED = 1, /* button pressed */
} button_event_type;

#define TMA525B_GESTURE_SIGNAL_CLICK 1
typedef enum {
    TMA525B_IRQ_DISABLE = 0,
    TMA525B_IRQ_ENABLE,
} tma525b_irq_status;

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
} tma525b_panel_data;

typedef struct {
    uint32_t skip_cnt;
    int16_t dnd_data[TMA525B_TSP_DND_NUM];
    int16_t self_dnd_data[TMA525B_TSP_SELFDND_NUM];
} tma525b_tsp_rawdata;

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
    uint8_t chip_info[TMA525B_DEVICE_INFO_SIZE];
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
    tma525b_sw_power_status power_status;
    tma525b_work_status work_status;
    tma525b_sw_power_status chip_sw_power_status;
    tma525b_device_status chip_status;
    input_event_info touch_msg;
    tma525b_panel_data panel_info;
    tp_peripheral_attr dev_attr;
    tma525b_tsp_rawdata tsp_raw_data;
    void *p_void;
    uint32_t tp_event;
    touch_drv_upgrade_proc upgrade_table[TMA525B_FWGRADE_CMD_NUM];
    touch_drv_rawdata_proc raw_data_table[TMA525B_RAWDATA_CMD_NUM];
} tma525b_drv_data;

typedef struct {
    uint32_t revctrlnumber;
    uint32_t chipinfo;
    uint32_t chipid;
} touchsysinfo;

ext_errno tma525b_init(void);
ext_errno tma525b_deinit(void);
ext_errno tma525b_set_power_mode(tp_work_mode power_mode);
ext_errno tma525b_get_power_mode(uint32_t *power_mode);
ext_errno tma525b_resume(void);
ext_errno tma525b_irq_callback(uint8_t *data_buf, uint8_t data_len);
ext_errno tma525b_host_init_sample(void);
#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif

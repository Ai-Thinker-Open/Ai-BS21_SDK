/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: product none standard config
 * Author: @CompanyNameTag
 * Create:  2021-06-16
 */
#ifndef PRODUCT_NONE_CONFIG_H
#define PRODUCT_NONE_CONFIG_H

/**
 * @addtogroup connectivity_config_product
 * @{
 */
/* Platform board config, need check if it support or not carefully. */
#define BTH_WITH_SMART_WEAR                 NO
#define WAIT_APPS_DUMP_FOREVER              NO
#define ENABLE_LOW_POWER                    NO
#define PM_SLEEP_DEBUG_ENABLE               NO
#define PM_ULP_GPIO_WKUP_ENABLE             NO
#define PM_MCPU_MIPS_STATISTICS_ENABLE      NO

/* If the image page changes，the partition table and packaging script also need to be modified */
#define PARTITION_IMAGE_PAGES               1
#ifdef SUPPORT_EXTERN_FLASH
    #define FLASHBOOT_A_IMAGE_PAGES             11
    #define FLASHBOOT_B_IMAGE_PAGES             11
#else
    #define FLASHBOOT_A_IMAGE_PAGES             10
    #ifdef NO_BOOT_BACKUP
        #define FLASHBOOT_B_IMAGE_PAGES         0
    #else
        #define FLASHBOOT_B_IMAGE_PAGES         10
    #endif
#endif

#if defined(FLASH_1M)
#ifdef SUPPORT_BT_UPG
#define FOTA_DATA_PAGES         94
#else
#define FOTA_DATA_PAGES         0
#endif
#else
#define FOTA_DATA_PAGES         0
#endif

#if defined(CONFIG_SAMPLE_SUPPORT_IR_STUDY)
#define IR_STUDY_PAGES          5
#else
#define IR_STUDY_PAGES          0
#endif

#define CUSTOMER_USED_PAGES                 0
#define NV_IMAGE_PAGES                      2
#define SSB_IMAGE_PAGES                     0
#define DTB_IMAGE_PAGES                     0
#define RECOVERY_IMAGE_PAGES                0
#define RESERVE_IMAGE_PAGES                 0
#define BT_IMAGE_PAGES                      0
#define HIFI0_IMAGE_PAGES                   0
#define HIFI1_IMAGE_PAGES                   0
#define APP_IMAGE_PAGES                     0
#define APP_BTN_TASK_MONITOR_ENABLE         NO

#ifdef BUILD_APPLICATION_STANDARD
#define BT_MIPS_DEBUG                       YES
#else
#define BT_MIPS_DEBUG                       NO
#endif
/* Platform board config, need check if it support or not carefully. */
#define USE_COMPRESS_LOG_INSTEAD_OF_SDT_LOG NO
#define LOG_LEVEL_APP_DEFAULT_CONFIG        3   // Info level
#ifdef DEVICE_ONLY
#define SYS_DEBUG_MODE_ENABLE               YES
#else
#define SYS_DEBUG_MODE_ENABLE               NO
#endif
#define APP_LOGGING_LENGTH                  0xC00

/********************Other module board config********************/
#define BTC_SWITCH_COEX                     NO
#define BTC_SMART_WEAR_WLCOEX               NO
#define BTC_WITH_SMART_WEAR                 NO
#define BTC_TWS_MONITOR                     YES
#define BTC_ICO_SUPPORT                     YES
#define BTC_DUAL_ANT_SWITCH_SUPPORT         NO
#define BTC_GET_EMC_FROM_PLATFORM           NO // 耳机产品通过HCI传递NV数据实现后，该选项需要置为NO
#define BTSNOOP_ENABLE                      YES
#define WEAR_USER_CONFIG                    NO
#define BTH_WEAR_ENABLE_AUDIO_SINK          NO
#define BTH_WEAR_ENABLE_AUDIO_GATEWAY       NO
#define BTH_WEAR_BREDR_DOUBLE_CONNECT       NO
#define BTC_DFX_LOG_HELP_SUPPORT            NO
#define BTH_WEAR_ENABLE_HFP_FEATURES        NO
#define BTH_WEAR_ENABLE_CONNECT_MANAGER     NO
#define BTH_WEAR_ENABLE_BLE_FEATURES        NO
#define BTH_HIGH_POWER                      YES
#define BTH_CONFIG_HDAP                     NO
#define DEVICE_MANAGE_FEATURE               YES
#define BTH_CALL_LC3_32K                    NO
#define ENABLE_CHANGE_DEVICE_NAME           YES
#define BTH_DIP_PRODUCT_ID                  0x4108


/********************Other module board config********************/
#define FACTORY_CALI                        NO
#define TWS_USER_CHR_RECORD                 NO
#define BTH_ENABLE_L2HC_CODEC               YES
#define BTH_ENABLE_LC3_CODEC                YES
#define MULTI_CONNECT                       YES
#define BTH_WEAR_ENABLE_AVRCP_CONTROLLER    NO
/**
 * @} end of group PRODUCT
 */
#endif

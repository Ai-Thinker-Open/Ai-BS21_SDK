/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: diag usr config
 * This file should be changed only infrequently and with great care.
 */

#ifndef DIAG_CONFIG_H
#define DIAG_CONFIG_H

#include <stdint.h>
#include "dfx_resource_id.h"
#include "memory_config_common.h"

#define DFX_MSG_MAX_SIZE        0x20               /* msg element size of msg queue */
#define DFX_MSG_ID_LEN          sizeof(uint32_t)
#define DFX_QUEUE_MAX_SIZE      64

#define CONFIG_DIAG_CMD_TBL_NUM     4      /* diag:Maximum number of cmd tbl cnt */
#define CONFIG_DIAG_IND_TBL_NUM     3      /* diag:Maximum number of ind tbl cnt */
#define CONFIG_STAT_CMD_LIST_NUM    10     /* diag:Maximum number of stat tbl cnt */
#define CONFIG_DIAG_RX_BUF_SIZE     0x400  /* diag:rx buf size */

#define CONFIG_DIAG_TRANSMIT_ITEM_CNT 1    /* diag:Maximum transfer item cnt */
#define CONFIG_DIAG_FILTER_GROUP_NUM  10   /* diag: Maximum number of diag file group */

#define DFX_OFFLINE_LOG_MUTI_FILE_NUM   1                       /* 离线日志最大文件个数 */
#define DFX_OFFLINE_LOG_PATH            ""                      /* 离线日志存放路径 */
#define DFX_OFFLINE_LOG_NAME            ""                      /* 离线日志文件名 */
#define DFX_OFFLINE_LOG_FILE_SIZE       0x32000                 /* 离线日志每个文件最大字节数 */
#define DFX_OFFLINE_LOG_CACHE_SIZE      2048                    /* 离线日志缓存大小 */
#define DFX_OFFLINE_LOG_CACHE_ENABLE    1                       /* 离线日志缓存开关 */

#if defined(SUPPORT_EXTERN_FLASH)
#define LOG_FILE_FLASH_START_ADDRESS    0x0                     /* 离线日志起始地址 */
#else
#define LOG_FILE_FLASH_START_ADDRESS    0x779000                /* 离线日志起始地址 */
#endif

#endif /* DIAG_CONFIG_H */

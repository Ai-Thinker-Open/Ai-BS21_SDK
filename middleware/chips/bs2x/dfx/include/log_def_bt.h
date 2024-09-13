/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description:  common logging producer interface - need to change name of log.h in all the protocol core files
 * Author: @CompanyNameTag
 * Create:
 */

#ifndef _LOG_DEF_BT_H_
#define _LOG_DEF_BT_H_

typedef enum {
// only for btc extern part
    _BTC_FILE_ID_EXT_START = 801,
    PATCH_LM_TASK_C,
    PATCH_LLD_ISO_PDU_C,
    PATCH_LLD_CIS_C,
    PATCH_LLC_CIS_C,
    HAL_ACCUMULATION_C,
    _BTC_FILE_ID_EXT_END = 1023,
} log_file_list_enum_bt_t;
#endif

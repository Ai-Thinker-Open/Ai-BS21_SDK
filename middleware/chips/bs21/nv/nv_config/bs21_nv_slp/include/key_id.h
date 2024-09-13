/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: NV - key_id.
 */

#ifndef KEY_ID_H
#define KEY_ID_H

#define REGION_KEY_NUMS 0x1000 /* 每个区域容纳key_id的个数 */

/* Please use the format of NV_ID_XXX */

/* system factory key_id [0x0001,0x1000) */
#define BTC_CONFIG_NV_INFO_ID 0xB
#define BTH_BLE_NV_RESERVED_ID 0xE
/* user factory key_id [0x1000,0x2000) */

/* system normal key_id [0x2000,0x3000) */
#define NV_ID_OFFLINELOG_ENBALE_FLAG    0x2002 /* Offline log enable flag */

/* user normal key_id [0x3000,0x4000) */

/* reserved key_id [0x4000,0xFFFF) */
#define NV_ID_RESTORE_ENABLE              0xA000 /* NV restore factory region flag */

#endif /* __KEY_ID_H__ */
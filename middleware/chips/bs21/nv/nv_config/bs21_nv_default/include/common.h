/*
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved.
 * Description: NV common header file.
 */

#ifndef COMMON_H
#define COMMON_H

#include "stdint.h"
/* 修改此文件后需要先编译A核任意版本生成中间文件application.etypes后才能在编译nv.bin时生效 */
#define BT_CUSTOMIZE_NV_RESERVED 86
#define BT_CUSTOMIZE_CHNL_MAP_LEN 10
/* 基础类型无需在此文件中定义，直接引用即可，对应app.json中的sample0 */

/* 蓝牙地址长度 */
#define BD_ADDR_LEN 6
/* 蓝牙名称长度 */
#define BD_NAME_MAX_LEN       32
/* 蓝牙秘钥索引长度 */
#define BTH_SYS_MASK_LEN  4
/* 蓝牙本端配对地址长度 */
#define BTH_BLE_OWN_ADDR_LEN  24
/* 蓝牙产品信息预留长度 */
#define BTH_PRODUCT_INFORMATION_RESERVE_LEN   32
/* 蓝牙秘钥长度 */
#define BTH_BLE_SMP_DATA_LEN  632
/* 蓝牙预留长度 */
#define BTH_BLE_RESERVE_LEN   128

/* HOST NV配置数据长度 */
#define SLE_CONFIG_SYNC_DATA_SIZE 108
#define SLE_SM_OWN_ADDR_LEN 24
#define SLE_NV_RESERV_LEN   128

/* HOST NV配置结构 */
typedef struct {
    uint8_t bd_addr[BD_ADDR_LEN];
    uint8_t bd_name[BD_NAME_MAX_LEN];
    uint8_t product_type;
    uint8_t sys_mask[BTH_SYS_MASK_LEN];
    uint8_t reserve[BTH_PRODUCT_INFORMATION_RESERVE_LEN];
} bth_product_information_config_t;
/* HOST NV配置结构 */
typedef struct {            /* Keys that indexes by addr */
    uint8_t smp_index;
    uint8_t keys[BTH_BLE_SMP_DATA_LEN];     /* own address, dule-mode? */
} bth_smp_keys_store_nv_stru_t;

typedef struct {            /* Keys that indexes by addr */
    uint8_t reserve[BTH_BLE_RESERVE_LEN];
} bth_ble_nv_reserved_struct_t;

/* SLE HOST NV配置结构 */
typedef struct {
    uint8_t sle_addr[BD_ADDR_LEN];
    uint8_t sle_name[BD_NAME_MAX_LEN];
    uint8_t sys_mask[BTH_SYS_MASK_LEN];
    uint8_t reserve[BTH_PRODUCT_INFORMATION_RESERVE_LEN];
} sle_product_data_config_stru_t;

typedef struct {
    uint16_t config_nv_1;
    uint16_t config_nv_2;
    uint16_t config_nv_3;
    uint16_t config_nv_4;
    uint16_t config_nv_5[5];
    uint16_t config_nv_6;
    uint16_t config_nv_7;
    uint16_t config_nv_8;
    uint16_t config_nv_9;
    uint8_t config_nv_10;
    int8_t config_nv_11;
    int8_t config_nv_12;
    uint8_t flag;
} bt_nv_cali_info_type_t;
#endif /* COMMON_H */
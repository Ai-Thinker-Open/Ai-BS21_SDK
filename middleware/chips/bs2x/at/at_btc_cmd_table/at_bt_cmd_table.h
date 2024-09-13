/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: at cmd table \n
 * Author: @CompanyNameTag \n
 */

#if !defined(AT_BT_CMD_AT_CMD_TALBE_H)
#define AT_BT_CMD_AT_CMD_TALBE_H

#include "at.h"
#include "at_porting.h"

#define AT_XO_CTRIM_PARAM_NUM 2
#define AT_BLE_RF_TX_PARAM_NUM 4
#define AT_BLE_RF_RX_PARAM_NUM 3
#define AT_SLE_RF_TX_PARAM_NUM 10
#define AT_SLE_RF_RX_PARAM_NUM 5
#define AT_SLE_CFO_PARAM_NUM 1
#define AT_RF_SINGLE_TONE_PARAM_NUM 2
#define AT_WRITE_CUSTOMIZE_NV_PARAM_NUM 32
#define AT_WRITE_FEM_FLAG_PARAM_NUM 2

typedef struct {
    uint32_t para_map;
    int32_t increase;
    int32_t step_num;
} xo_ctrim_cali_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t tx_freq;
    int32_t test_data_len;
    int32_t pk_payload_type;
    int32_t tx_phy;
} ble_rf_tx_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t rx_freq;
    int32_t rx_phy;
    int32_t modulation_index;
} ble_rf_rx_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t tx_freq;
    int32_t tx_power;
    int32_t test_data_len;
    int32_t pk_payload_type;
    int32_t tx_phy;
    int32_t tx_format;
    int32_t tx_rate;
    int32_t tx_pilot_ratio;
    int32_t tx_polar_r;
    int32_t tx_interval;
} sle_rf_tx_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t rx_freq;
    int32_t rx_phy;
    int32_t rx_format;
    int32_t rx_pilot_ratio;
    int32_t rx_interval;
} sle_rf_rx_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t rf_freq;
    int32_t rf_mode;
} rf_single_tone_param_args_t;

typedef struct {
    uint32_t para_map;
    int32_t rssi_limit;
} rf_sle_cfo_rpt_rssi_limit_t;

typedef struct {
    uint32_t para_map;
    int32_t customize_offset1; // 定制化字段在NV结构中的偏移
    int32_t customize_value1;  // 该偏移字段的定制化值
    int32_t customize_offset2;
    int32_t customize_value2;
    int32_t customize_offset3;
    int32_t customize_value3;
    int32_t customize_offset4;
    int32_t customize_value4;
    int32_t customize_offset5;
    int32_t customize_value5;
    int32_t customize_offset6;
    int32_t customize_value6;
    int32_t customize_offset7;
    int32_t customize_value7;
    int32_t customize_offset8;
    int32_t customize_value8;
    int32_t customize_offset9;
    int32_t customize_value9;
    int32_t customize_offset10;
    int32_t customize_value10;
    int32_t customize_offset11;
    int32_t customize_value11;
    int32_t customize_offset12;
    int32_t customize_value12;
    int32_t customize_offset13;
    int32_t customize_value13;
    int32_t customize_offset14;
    int32_t customize_value14;
    int32_t customize_offset15;
    int32_t customize_value15; // 定制化AT支持一次最多写入15个定制化字节
} bt_write_customize_nv_param_args_t;

typedef struct {
    uint32_t para_map;
    int8_t fem_switch; // 控制fem开关
} fem_switch_param_args_t;

extern const at_para_parse_syntax_t xo_ctrim_cali_param_syntax[AT_XO_CTRIM_PARAM_NUM];
extern const at_para_parse_syntax_t ble_rf_tx_write_param_syntax[AT_BLE_RF_TX_PARAM_NUM];
extern const at_para_parse_syntax_t ble_rf_rx_write_param_syntax[AT_BLE_RF_RX_PARAM_NUM];
extern const at_para_parse_syntax_t sle_rf_tx_write_param_syntax[AT_SLE_RF_TX_PARAM_NUM];
extern const at_para_parse_syntax_t sle_rf_rx_write_param_syntax[AT_SLE_RF_RX_PARAM_NUM];
extern const at_para_parse_syntax_t sle_cfo_rpt_rssi_limit_param_syntax[AT_SLE_CFO_PARAM_NUM];
extern const at_para_parse_syntax_t rf_single_tone_param_syntax[AT_RF_SINGLE_TONE_PARAM_NUM];
extern const at_para_parse_syntax_t bt_write_customize_nv_param_syntax[AT_WRITE_CUSTOMIZE_NV_PARAM_NUM];
extern const at_para_parse_syntax_t write_fem_flag_param_syntax[AT_WRITE_FEM_FLAG_PARAM_NUM];

#endif /* AT_BT_CMD_TALBE_H */

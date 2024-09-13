/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: KEYSCAN Sample Source. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-26, Create file. \n
 */
#include "common_def.h"
#include "pinctrl.h"
#include "keyscan_porting.h"
#include "keyscan.h"
#include "soc_osal.h"
#include "osal_debug.h"
#include "cmsis_os2.h"
#include "app_init.h"

#define KEYSCAN_PULSE_TIME              3
#define KEYSCAN_MODE_SET                0
#define KEYSCAN_INTERRUPT_TYPE          3
#define KEYSCAN_REPORT_MAX_NUMS         6
#define KEYSCAN_PARAM_INDEX_2           2
#define KEYSCAN_PARAM_INDEX_3           3
#define KEYSCAN_PARAM_INDEX_4           4
#define LENGTH_OF_KEY_VALUE_STR         5
#define CONVERT_DEC_TO_HEX              16
#define MAX_NUM_OF_DEC                  10

#define KEYSCAN_TASK_STACK_SIZE         0x1000
#define KEYSCAN_TASK_PRIO               (osPriority_t)(17)

#if defined(CONFIG_KEYSCAN_USE_FULL_KEYS_TYPE)
uint8_t g_app_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    { 0x29, 0x2B, 0x14, 0x35, 0x04, 0x1E, 0x1D, 0x00 },
    { 0x3D, 0x3C, 0x08, 0x3B, 0x07, 0x20, 0x06, 0x00 },
    { 0x00, 0x39, 0x1A, 0x3A, 0x16, 0x1F, 0x1B, 0x00 },
    { 0x00, 0x00, 0x00, 0xE0, 0x00, 0x00, 0xE4, 0x00 },
    { 0x0A, 0x17, 0x15, 0x22, 0x09, 0x21, 0x19, 0x05 },
    { 0x0B, 0x1C, 0x18, 0x23, 0x0D, 0x24, 0x10, 0x11 },
    { 0x3F, 0x30, 0x0C, 0x2E, 0x0E, 0x25, 0x36, 0x00 },
    { 0x00, 0x00, 0x12, 0x40, 0x0F, 0x26, 0x37, 0x00 },
    { 0x34, 0x2F, 0x13, 0x2D, 0x33, 0x27, 0x00, 0x38 },
    { 0x3E, 0x2A, 0x00, 0x41, 0x31, 0x42, 0x28, 0x2C },
    { 0x00, 0x00, 0xE3, 0x00, 0x00, 0x43, 0x00, 0x51 },
    { 0xE2, 0x00, 0x00, 0x00, 0x00, 0x45, 0xE5, 0xE6 },
    { 0x00, 0x53, 0x00, 0x00, 0xE1, 0x44, 0x00, 0x4F },
    { 0x52, 0x00, 0x00, 0x00, 0x00, 0x00, 0x4C, 0x50 },
    { 0x5F, 0x5C, 0x61, 0x5E, 0x59, 0x62, 0x55, 0x5B },
    { 0x54, 0x60, 0x56, 0x57, 0x5D, 0x5A, 0x58, 0x63 }
};

static uint8_t g_gpio_map[CONFIG_KEYSCAN_ENABLE_ROW + CONFIG_KEYSCAN_ENABLE_COL] = {
    31, 24, 14, 23, 27, 28, 10, 11, 30, 13, 15, 16, 25, 26, 12, 22,     //行GPIO
    2, 3, 4, 5, 6, 21, 9, 29 };                                         //列GPIO

#else
uint8_t g_app_key_map[CONFIG_KEYSCAN_ENABLE_ROW][CONFIG_KEYSCAN_ENABLE_COL] = {
    { 0x05, 0x16 },  /* BS */
    { 0x1F, 0x25 },  /* 28 */
    { 0x5A, 0x1B },  /* 2x */
};
#endif

static int app_keyscan_report_callback(int key_nums, uint8_t key_values[])
{
    char *key_value_str[KEYSCAN_REPORT_MAX_NUMS];
    for (uint8_t i = 0; i < key_nums; i++) {
        key_value_str[i] = (char *)osal_vmalloc(LENGTH_OF_KEY_VALUE_STR);
        key_value_str[i][0] = '0';
        key_value_str[i][1] = 'x';
        uint32_t tran = key_values[i] / CONVERT_DEC_TO_HEX;
        if (tran < MAX_NUM_OF_DEC) {
            key_value_str[i][KEYSCAN_PARAM_INDEX_2] = '0' + tran;
        } else {
            key_value_str[i][KEYSCAN_PARAM_INDEX_2] = ('A' + tran - MAX_NUM_OF_DEC);
        }
        tran = key_values[i] % CONVERT_DEC_TO_HEX;
        if (tran < MAX_NUM_OF_DEC) {
            key_value_str[i][KEYSCAN_PARAM_INDEX_3] = '0' + tran;
        } else {
            key_value_str[i][KEYSCAN_PARAM_INDEX_3] = ('A' + tran - MAX_NUM_OF_DEC);
        }
        key_value_str[i][KEYSCAN_PARAM_INDEX_4] = '\0';
    }

    for (int i = 0; i < key_nums; i++) {
        osal_printk("KEY val: %s\r\n", key_value_str[i]);
    }
    for (int i = 0; i < key_nums; i++) {
        osal_vfree(key_value_str[i]);
    }
    return 0;
}

static void keyscan_entry(void)
{
#if defined(CONFIG_KEYSCAN_USE_FULL_KEYS_TYPE)
    keyscan_porting_config_pins();
#endif
    if (keyscan_porting_set_gpio(g_gpio_map)) {
        return;
    }
    /* Set the key value matrix of Keyscan. */
    if (uapi_set_keyscan_value_map((uint8_t **)g_app_key_map,
        CONFIG_KEYSCAN_ENABLE_ROW, CONFIG_KEYSCAN_ENABLE_COL) == ERRCODE_SUCC) {
        osal_printk("the key value matrix of Keyscan has been successfully configured!\r\n");
    }
    /* KEYSCAN Init Config. */
    uapi_keyscan_init(KEYSCAN_PULSE_TIME, KEYSCAN_MODE_SET, KEYSCAN_INTERRUPT_TYPE);

    osal_printk("keyscan register callback start!\r\n");
    if (uapi_keyscan_register_callback(app_keyscan_report_callback) == ERRCODE_SUCC) {
        osal_printk("keyscan register callback succ!\r\n");
    }
    osal_printk("keyscan enable start!\r\n");
    if (uapi_keyscan_enable() == ERRCODE_KEYSCAN_POWER_ON) {
        osal_printk("keyscan enable start succ!\r\n");
    }
}

/* Run the keyscan_entry. */
app_run(keyscan_entry);
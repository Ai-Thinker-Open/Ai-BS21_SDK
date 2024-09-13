/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Test PDM source \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-02-08, Create file. \n
 */
#include "osal_debug.h"
#include "test_suite.h"
#include "test_suite_errors.h"

#include "common_def.h"
#include "securec.h"
#include "interrupt/osal_interrupt.h"
#include "pinctrl.h"
#include "watchdog.h"
#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
#include "hal_pdm_v150_regs_op.h"
#include "chip_core_irq.h"
#endif
#include "pdm.h"
#include "hal_pdm.h"
#include "test_pdm.h"

#define PDM_CONFIG_PARAM_NUM 1
#define PDM_CONVERT_32_TO_16 16


#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
#define PDM_MEM_SIZE         (32768)
#define PDM_FIFO_ADDR        (0x5208E080)
#endif

static uint32_t g_dtcm_cfg = 0;

static int test_pdm_config(int argc, char* argv[])
{
#if defined(CONFIG_PDM_USING_V151) && (CONFIG_PDM_USING_V151 == 1)
    uapi_reg_read16(0x52000f90, g_dtcm_cfg);
    uapi_reg_write16(0x52000f90, 0x0f2); // 配置0x20018000 + 0x48000 给A核使用
#endif
    pdm_config_t config = { 0 };

    if (argc != PDM_CONFIG_PARAM_NUM) {
        return ERRCODE_TEST_SUITE_ERROR_BAD_PARAMS;
    }

    uint8_t mic = (uint8_t)strtol(argv[0], NULL, 0);

#if defined(CONFIG_PDM_USING_V151) && (CONFIG_PDM_USING_V151 == 1)
    config.fs_ctrl_freq = PDM_MIC_FRE_16K;
    config.linear_select = 0;
    config.zero_num = 0x14;
    config.threshold_id = 0;
    config.noise_enable = 0;
    config.pga_bypass_enable = 0;
    config.fade_out_time = 0;
    config.fade_in_time = 0;
    config.little_signal = 0;
    config.anti_clip = 0;
    config.fade_in_out = 0;
    config.pga_gain = 0x28;
    config.srcdn_src_mode = DOUBLE_EXTRACT;
#endif
#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
    config.srcdn_src_mode = SIXFOLD_EXTRACT;
#endif

    errcode_t ret = uapi_pdm_set_attr(mic, &config);
    if (ret != ERRCODE_SUCC) {
        return ERRCODE_TEST_SUITE_CONFIG_FAILED;
    }

    return TEST_SUITE_OK;
}

#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
uint32_t g_count;
uint16_t g_pdm_mem[PDM_MEM_SIZE / sizeof(uint16_t)] = {1};

static void test_pdm_read_fifo(void)
{
    for (uint32_t i = 0; i < CONFIG_PDM_AFIFO_AFULL_TH; i++) {
        if (g_count < (sizeof(g_pdm_mem) / sizeof(uint16_t))) {
            g_pdm_mem[g_count++] = uapi_reg_read_val32(PDM_FIFO_ADDR) >> PDM_CONVERT_32_TO_16;
        } else {
            osal_printk("pdm sample done\n");
        }
    }
}

static int pdm_irq_handler(int a, void *tmp)
{
    unused(a);
    unused(tmp);

    if (hal_pdm_v150_up_fifo_st_get_up_fifo_full_int() == 1) {
        test_pdm_read_fifo();
        hal_pdm_v150_up_fifo_st_clr_set_up_fifo_clr(1);
        hal_pdm_v150_up_fifo_st_clr_set_up_fifo_clr(0);
        hal_pdm_v150_up_fifo_st_clr_set_up_fifo_full_int_clr(1);
        osal_irq_clear(PDM_IRQN);
        return 0;
    }

    if (hal_pdm_v150_up_fifo_st_get_up_fifo_afull_int() == 1) {
        test_pdm_read_fifo();
        hal_pdm_v150_up_fifo_st_clr_set_up_fifo_afull_int_clr(1);
    }
    osal_irq_clear(PDM_IRQN);
    return 1;
}
#endif

static int test_pdm_start(int argc, char* argv[])
{
    unused(argc);
    unused(argv);
#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
    osal_irq_request(PDM_IRQN, pdm_irq_handler, NULL, NULL, NULL);
    osal_irq_enable(PDM_IRQN);
#endif
    errcode_t ret = uapi_pdm_start();
    if (ret != ERRCODE_SUCC) {
        return ERRCODE_TEST_SUITE_TEST_FAILED;
    }

    return TEST_SUITE_OK;
}

static int test_pdm_stop(int argc, char* argv[])
{
    unused(argc);
    unused(argv);

    errcode_t ret = uapi_pdm_stop();
    if (ret != ERRCODE_SUCC) {
        return ERRCODE_TEST_SUITE_TEST_FAILED;
    }
    uapi_reg_write16(0x52000f90, g_dtcm_cfg);
    return TEST_SUITE_OK;
}

#if defined(CONFIG_PDM_USING_V151) && (CONFIG_PDM_USING_V151 == 1)
static int test_pdm_read(int argc, char* argv[])
{
    unused(argc);
    unused(argv);

    int i = 0;
    int count = 1;
    int times = uapi_reg_getbits(0x5208E000 + 0xb8, 10, 5);
    uapi_pdm_start();
    while ((i * sizeof(uint32_t)) < 0x47ffc) {
        if ((uapi_reg_getbits(0x5208E320, 0, 1) || uapi_reg_getbits(0x5208E320, 1, 1)) == 0) {
            uapi_watchdog_kick();
            continue;
        }

        for (; i < times * count; i++) {
            uapi_reg_write16(0x20018000  + (i * sizeof(uint16_t)),
                             (uapi_reg_read_val32(0x5208E628) >> PDM_CONVERT_32_TO_16));
        }

        uapi_reg_write16(0x5208E310, 0x3);
        count++;

        if ((uapi_reg_getbits(0x5208E320, ((uint32_t)HAL_PDM_DMIC_4 + sizeof(uint32_t)), 1) ||
             uapi_reg_getbits(0x5208E320, ((uint32_t)HAL_PDM_DMIC_5 + sizeof(uint32_t)), 1))) {
            uapi_reg_write16(0x5208E310, 0x30);
        }
    }
    uapi_pdm_stop();
    return TEST_SUITE_OK;
}
#endif

static int test_pdm_init(int argc, char* argv[])
{
    unused(argc);
    unused(argv);
#if defined(CONFIG_PDM_USING_V150) && (CONFIG_PDM_USING_V150 == 1)
    osal_printk("g_pdm_mem:0x%x", (uint32_t)g_pdm_mem);
#if defined(CONFIG_PINCTRL_SUPPORT_IE)
    uapi_pin_set_ie(S_MGPIO22, PIN_IE_1);
#endif /* CONFIG_PINCTRL_SUPPORT_IE */
    uapi_pin_set_mode(S_MGPIO22, (pin_mode_t)HAL_PIO_DMIC_DIN);
    uapi_pin_set_mode(S_MGPIO23, (pin_mode_t)HAL_PIO_DMIC_CLK);
    memset_s(g_pdm_mem, sizeof(g_pdm_mem), 0, sizeof(g_pdm_mem));
#endif

#if defined(CONFIG_PDM_USING_V151) && (CONFIG_PDM_USING_V151 == 1)
#if defined(CONFIG_PINCTRL_SUPPORT_IE)
    uapi_pin_set_ie(S_MGPIO30, PIN_IE_1);
    uapi_pin_set_ie(S_MGPIO31, PIN_IE_1);
#endif /* CONFIG_PINCTRL_SUPPORT_IE */
    uapi_pin_set_mode(S_MGPIO30, PIN_MODE_1);
    uapi_pin_set_mode(S_MGPIO31, PIN_MODE_1);
#endif
    uapi_pdm_init();
    return TEST_SUITE_OK;
}

void add_pdm_test_case(void)
{
    uapi_test_suite_add_function("test_pdm_init", "Params: no param", test_pdm_init);
    uapi_test_suite_add_function("test_pdm_config", "Params: <pdm_channel>", test_pdm_config);
    uapi_test_suite_add_function("test_pdm_start", "params: no param", test_pdm_start);
    uapi_test_suite_add_function("test_pdm_stop", "params: no param", test_pdm_stop);
#if defined(CONFIG_PDM_USING_V151) && (CONFIG_PDM_USING_V151 == 1)
    uapi_test_suite_add_function("test_pdm_read", "params: no param", test_pdm_read);
#endif
}
/**
 * Copyright (c) @CompanyNameMagicTag 2022-2022. All rights reserved. \n
 *
 * Description: Provides V150 rtc register operation API \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-12-07， Create file. \n
 */
#ifndef HAL_RTC_V150_REGS_OP_H
#define HAL_RTC_V150_REGS_OP_H

#include <stdint.h>
#include "errcode.h"
#include "rtc_porting.h"
#include "hal_rtc_v150_regs_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_rtc_v150_regs_op RTC V150 Regs Operation
 * @ingroup  drivers_hal_rtc
 * @{
 */

extern uintptr_t g_rtc_comm_regs;
extern uintptr_t g_rtc_regs[CONFIG_RTC_MAX_NUM];

/**
 * @brief  Reg addr associated with rtc.
 */
#define rtc_regs(index) ((rtc_v150_regs_t *)(g_rtc_regs[index]))

/**
 * @brief  Set the value of @ref rtc_v150_control_reg_data.enable.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  val Enable or not.
 */
static inline void hal_rtc_v150_control_reg_set_enable(rtc_index_t index, uint32_t val)
{
    rtc_v150_control_reg_data_t rtc_control_reg;
    rtc_control_reg.d32 = rtc_regs(index)->control;
    rtc_control_reg.b.enable = val;
    rtc_regs(index)->control = rtc_control_reg.d32;
}

/**
 * @brief  Get the value of @ref rtc_v150_control_reg_data_t.enable.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @return The value of @ref rtc_v150_control_reg_data_t.enable.
 */
static inline uint32_t hal_rtc_v150_control_reg_get_enable(rtc_index_t index)
{
    rtc_v150_control_reg_data_t rtc_control_reg;
    rtc_control_reg.d32 = rtc_regs(index)->control;
    return rtc_control_reg.b.enable;
}

/**
 * @brief  Set the value of @ref rtc_v150_control_reg_data.mode.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  val The work mode of rtc.
 */
static inline void hal_rtc_v150_control_reg_set_mode(rtc_index_t index, uint32_t val)
{
    rtc_v150_control_reg_data_t rtc_control_reg;
    rtc_control_reg.d32 = rtc_regs(index)->control;
    rtc_control_reg.b.mode = val;
    rtc_regs(index)->control = rtc_control_reg.d32;
}

/**
 * @brief  Get the value of @ref rtc_v150_regs.current_value0.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @return The value of @ref rtc_v150_regs.current_value0.
 */
static inline uint32_t hal_rtc_v150_get_current_value0(rtc_index_t index)
{
    return rtc_regs(index)->current_value0;
}

/**
 * @brief  Get the value of @ref rtc_v150_regs.current_value1.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @return The value of @ref rtc_v150_regs.current_value1.
 */
static inline uint32_t hal_rtc_v150_get_current_value1(rtc_index_t index)
{
    return rtc_regs(index)->current_value1;
}

/**
 * @brief  Set the value of @ref rtc_v150_regs.load_count0.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  val The load count value.
 */
static inline void hal_rtc_v150_set_load_count0(rtc_index_t index, uint32_t val)
{
    rtc_regs(index)->load_count0 = val;
}

/**
 * @brief  Set the value of @ref rtc_v150_regs.load_count1.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  val The load count value.
 */
static inline void hal_rtc_v150_set_load_count1(rtc_index_t index, uint32_t val)
{
    rtc_regs(index)->load_count1 = val;
}

/**
 * @brief  Clear rtc interrupt.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 */
static inline void hal_rtc_v150_int_clr(rtc_index_t index)
{
    rtc_regs(index)->eoi_ren = 0x1;
}

#if defined(CONFIG_RTC_SUPPORT_LPM)
/**
 * @brief  Get rtc interrupt status.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @return The value of @ref rtc_v150_regs.intr.
 */
static inline uint32_t hal_rtc_v150_get_int_sts(rtc_index_t index)
{
    return rtc_regs(index)->intr;
}
#endif /* CONFIG_RTC_SUPPORT_LPM */

/**
 * @brief  Set the value of @ref rtc_v150_control_reg_data_t.cnt_req.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 */
static inline void hal_rtc_v150_ctrl_set_cnt_req(rtc_index_t index)
{
    rtc_v150_control_reg_data_t rtc_control_reg;
    rtc_control_reg.d32 = rtc_regs(index)->control;
    rtc_control_reg.b.cnt_req = 1;
    rtc_regs(index)->control = rtc_control_reg.d32;
}

/**
 * @brief  Set the value of @ref rtcs_v150_regs.lock.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @param  [in]  val The lock password.
 */
static inline void hal_rtc_v150_set_load_lock(rtc_index_t index, uint32_t val)
{
    unused(index);
    ((rtcs_v150_regs_t *)g_rtc_comm_regs)->lock = val;
}

/**
 * @brief  Get the value of @ref rtc_v150_control_reg_data_t.cnt_lock.
 * @param  [in]  index Index of the hardware rtc. For detail, see @ref rtc_index_t.
 * @return The value of @ref rtc_v150_control_reg_data_t.cnt_lock.
 */
static inline uint32_t hal_rtc_v150_ctrl_get_cnt_lock(rtc_index_t index)
{
    rtc_v150_control_reg_data_t rtc_control_reg;
    rtc_control_reg.d32 = rtc_regs(index)->control;
    return rtc_control_reg.b.cnt_lock;
}


/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
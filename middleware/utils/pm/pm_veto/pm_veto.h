/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides sleep veto header \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-09， Create file. \n
 */

#ifndef PM_VETO_H
#define PM_VETO_H

#include <stdbool.h>
#include "common_def.h"
#include "errcode.h"
#include "pm_porting.h"
#include "pm_veto_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup middleware_utils_pm_veto PM veto
 * @ingroup  middleware_utils_pm
 * @{
 */

/**
 * @if Eng
 * @brief  Number of votes record.
 * @else
 * @brief  投票数量记录。
 * @endif
 */
typedef struct {
    uint8_t total_counts;
    uint8_t sub_counts[PM_VETO_ID_MAX];
} pm_veto_counts_t;

/**
 * @if Eng
 * @brief  Number of votes recorded.
 * @else
 * @brief  投票数量记录。
 * @endif
 */
typedef struct {
    pm_veto_counts_t veto_counts;
    uint16_t last_veto_id;
    uint32_t last_veto_lr;
    uint64_t veto_timeout_timestamp;
} pm_veto_t;

/**
 * @if Eng
 * @brief  Sleep veto initialization.
 * @else
 * @brief  睡眠否决初始化。
 * @endif
 */
void uapi_pm_veto_init(void);

#if defined(CONFIG_PM_VETO_TRACK_ENABLE) && (CONFIG_PM_VETO_TRACK_ENABLE == 1)
/**
 * @if Eng
 * @brief  Interface for starting voting track recording.
 * @param  [in]  veto_mask Voting ID mask.
 * @param  [in]  num Number of voting track records.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  启动投票轨迹记录接口。
 * @param  [in]  veto_mask 投票ID掩码。
 * @param  [in]  num 投票轨迹记录数量。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_veto_start_track(uint8_t veto_mask, uint8_t num);

/**
 * @if Eng
 * @brief  Interface for stoping voting track recording.
 * @else
 * @brief  停止投票轨迹记录接口。
 * @endif
 */
void uapi_pm_veto_stop_track(void);
#endif

/**
 * @if Eng
 * @brief  Add deep-sleep veto.
 * @param  [in]  veto_id The module ID of the veto.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  添加深度睡眠否决票。
 * @param  [in]  veto_id 模块ID。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_add_sleep_veto(pm_veto_id_t veto_id);

/**
 * @if Eng
 * @brief  Add deep-sleep veto with timeout.
 * @note   This interface is used independently, the system is not allowed to sleep within the timeout period.
 * @param  [in]  veto_id The module ID of the veto.
 * @param  [in]  timeout_ms Timeout interval for deep-sleep veto.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  添加带超时的深度睡眠否决票。
 * @note   该接口单独使用，在超时时间内系统不允许睡眠。
 * @param    veto_id 模块ID
 * @param    timeout_ms 超时时间内不允许睡眠。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_add_sleep_veto_with_timeout(pm_veto_id_t veto_id, uint32_t timeout_ms);

/**
 * @if Eng
 * @brief  Remove deep-sleep veto.
 * @param  [in]  veto_id The module ID of the veto.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  移除深睡否决票。
 * @param  [in]  veto_id 模块ID。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t uapi_pm_remove_sleep_veto(pm_veto_id_t veto_id);


/**
 * @if Eng
 * @brief  Get deep-sleep veto.
 * @retval true  Veto deep-sleep.
 * @retval false Allow deep-sleep.
 * @else
 * @brief  获取深睡否决票。
 * @retval true  不允许深睡。
 * @retval false 允许深睡。
 * @endif
 */
bool uapi_pm_get_sleep_veto(void);

/**
 * @if Eng
 * @brief  Get sleep veto information.
 * @return Sleep veto information.
 * @else
 * @brief  获取睡眠否决信息。
 * @return 睡眠否决信息。
 * @endif
 */
pm_veto_t *uapi_pm_veto_get_info(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
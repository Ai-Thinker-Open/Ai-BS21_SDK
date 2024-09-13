/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides PDM driver api \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-29， Create file. \n
 */
#ifndef PDM_H
#define PDM_H

#include <stdio.h>
#include "errcode.h"
#include "hal_pdm.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_driver_pdm PDM
 * @ingroup  drivers_driver
 * @{
 */

/**
 * @if Eng
 * @brief  Definition of PDM configuration.
 * @else
 * @brief  PDM配置参数。
 * @endif
 */
typedef struct pdm_config {
#if defined(CONFIG_PDM_USING_V151)
    uint8_t fs_ctrl_freq;
    uint8_t linear_select;
    uint8_t zero_num;
    uint8_t threshold_id;
    uint8_t noise_enable;
    uint8_t pga_bypass_enable;
    uint8_t fade_out_time;
    uint8_t fade_in_time;
    uint8_t little_signal;
    uint8_t anti_clip;
    uint8_t fade_in_out;
    uint8_t pga_gain;
#endif  /* CONFIG_PDM_USING_V151 */
    uint8_t srcdn_src_mode;
} pdm_config_t;

/**
 * @if Eng
 * @brief  Initialize the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  初始化PDM。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pdm_init(void);

/**
 * @if Eng
 * @brief  Deinitialize the PDM.
 * @else
 * @brief  去初始化PDM。
 * @endif
 */
void uapi_pdm_deinit(void);

/**
 * @if Eng
 * @brief  Set the MIC attribute of PDM.
 * @param  [in]  mic The MIC need to set. For details, see @ref hal_pdm_mic_t.
 * @param  [in]  attr The MIC attribute of PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  设置PDM通道的属性。
 * @param  [in]  mic 需要配置的通道，参考 @ref hal_pdm_mic_t 。
 * @param  [in]  attr 配置参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pdm_set_attr(uint8_t mic, const pdm_config_t *attr);

/**
 * @if Eng
 * @brief  Get the MIC attribute of PDM.
 * @param  [in]  mic The MIC need to set. For details, see @ref hal_pdm_mic_t.
 * @param  [out] attr The MIC attribute of PDM to store.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  获取PDM通道的属性。
 * @param  [in]  mic 需要获取的通道，参考 @ref hal_pdm_mic_t 。
 * @param  [out] attr 用于存储获取的属性参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
void uapi_pdm_get_attr(uint8_t mic, pdm_config_t *attr);

/**
 * @if Eng
 * @brief  Start the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  启动PDM采样。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pdm_start(void);

/**
 * @if Eng
 * @brief  Stop the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t.
 * @else
 * @brief  停止PDM采样。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
errcode_t uapi_pdm_stop(void);

/**
 * @if Eng
 * @brief  Get the FIFO address of PDM, used to set the src address of DMA.
 * @return The FIFO address of PDM.
 * @else
 * @brief  获取PDM的FIFO基地址，用于在DMA传输时指定传输的源地址。
 * @return PDM的FIFO基地址。
 * @endif
 */
uintptr_t uapi_pdm_get_fifo_addr(void);

/**
 * @if Eng
 * @brief  Get the FIFO deepth of PDM, used to set the src deepth of DMA.
 * @return The FIFO deepth of PDM.
 * @else
 * @brief  获取PDM的FIFO深度，用于在DMA传输时指定传输的源地址。
 * @return PDM的FIFO深度。
 * @endif
 */
uint32_t uapi_pdm_get_fifo_deepth(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif

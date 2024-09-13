/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides HAL PDM \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-01-29, Create file. \n
 */
#ifndef HAL_PDM_H
#define HAL_PDM_H

#include <stdint.h>
#include "errcode.h"
#include "pdm_porting.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_hal_pdm_api PDM
 * @ingroup  drivers_hal_pdm
 * @{
 */

/**
 * @if Eng
 * @brief  MIC definition.
 * @else
 * @brief  MIC通道定义。
 * @endif
 */
typedef enum hal_pdm_mic {
#if defined(CONFIG_PDM_USING_V150)
    HAL_PDM_AMIC,
    HAL_PDM_DMIC_0,
    HAL_PDM_DMIC_1,
#endif  /* CONFIG_PDM_USING_V150 */

#if defined(CONFIG_PDM_USING_V151)
    HAL_PDM_DMIC_4,
    HAL_PDM_DMIC_5,
    HAL_PDM_DMIC_DUAL,
#endif  /* CONFIG_PDM_USING_V151 */

    HAL_PDM_MIC_MAX_NUM
} hal_pdm_mic_t;

#if defined(CONFIG_PDM_USING_V151)
/**
 * @if Eng
 * @brief  MIC sampling rate control.
 * @else
 * @brief  MIC采样率控制。
 * @endif
 */
typedef enum hal_pdm_fre {
    PDM_MIC_FRE_16K,
    PDM_MIC_FRE_32K,
    PDM_MIC_FRE_48K,
    PDM_MIC_FRE_96K,
    PDM_MIC_FRE_8K,
} hal_pdm_fre_t;

/**
 * @if Eng
 * @brief  PGA linear control.
 * @else
 * @brief  PGA线性控制选项。
 * @endif
 */
typedef enum hal_pdm_mic_pag_linear_sel {
    LOGARITHM_FADE_IN_OUT,
    LINEAR_FADE_IN_OUT,
} hal_pdm_mic_pag_linear_sel_t;

/**
 * @if Eng
 * @brief  DMIC clocks configuration.
 * @else
 * @brief  DMIC时钟配置。
 * @endif
 */
typedef enum hal_pdm_fs_dmic {
    CLK_OFF,
    HALF_CLK,
    ONE_THIRD_CLK,
    QUARTER_CLK,
    EIGHTH_CLK = 7,
    TWELFTH_CLK = 11
} hal_pdm_fs_dmic_t;
#endif  /* CONFIG_PDM_USING_V151 */

/**
 * @if Eng
 * @brief  SRC downsampling decimation multiple configuration.
 * @else
 * @brief  SRC下行采样率配置。
 * @endif
 */
typedef enum hal_pdm_srcdn_src_mode {
    TRIPLE_EXTRACT,
    SIXFOLD_EXTRACT,
    DOUBLE_EXTRACT,
    ONE_POINT_FIVE_EXTRACT
} hal_pdm_srcdn_src_mode_t;

/**
 * @if Eng
 * @brief  The configuration of PDM.
 * @else
 * @brief  PDM配置参数。
 * @endif
 */
typedef struct hal_pdm_config {
#if defined(CONFIG_PDM_USING_V151)
    hal_pdm_fre_t fs_ctrl_freq;
    hal_pdm_mic_pag_linear_sel_t linear_select;
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
    hal_pdm_srcdn_src_mode_t srcdn_src_mode;
} hal_pdm_config_t;

/**
 * @if Eng
 * @brief  Initialize the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  初始化PDM。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
typedef errcode_t (*hal_pdm_init_t)(void);

/**
 * @if Eng
 * @brief  Deinitialize the PDM.
 * @else
 * @brief  去初始化PDM。
 * @endif
 */
typedef void (*hal_pdm_deinit_t)(void);

/**
 * @if Eng
 * @brief  Set the MIC attribute of PDM.
 * @param  [in]  mic The MIC need to set.
 * @param  [in]  attr The MIC attribute of PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置PDM通道的属性。
 * @param  [in]  mic 需要配置的通道。
 * @param  [in]  attr 配置参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
typedef errcode_t (*hal_pdm_set_attr_t)(uint8_t mic, hal_pdm_config_t *attr);

/**
 * @if Eng
 * @brief  Get the MIC attribute of PDM.
 * @param  [in]  mic The MIC need to set.
 * @param  [out] attr The MIC attribute of PDM to store.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  设置PDM通道的属性。
 * @param  [in]  mic 需要配置的通道。
 * @param  [out] attr 用于存储获取的配置参数。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
typedef void (*hal_pdm_get_attr_t)(uint8_t mic, hal_pdm_config_t *attr);

/**
 * @if Eng
 * @brief  Start the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  启动PDM采样。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
typedef errcode_t (*hal_pdm_start_t)(void);

/**
 * @if Eng
 * @brief  Stop the PDM.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  停止PDM采样。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败，参考 @ref errcode_t 。
 * @endif
 */
typedef errcode_t (*hal_pdm_stop_t)(void);

/**
 * @if Eng
 * @brief  Get the FIFO address of PDM, used to set the src address of DMA.
 * @return The FIFO address of PDM.
 * @else
 * @brief  获取PDM的FIFO基地址，用于在DMA传输时指定传输的源地址。
 * @return PDM的FIFO基地址。
 * @endif
 */
typedef uintptr_t (*hal_pdm_get_fifo_addr_t)(void);

/**
 * @if Eng
 * @brief  Get the FIFO deepth of PDM, used to set the src deepth of DMA.
 * @return The FIFO deepth of PDM.
 * @else
 * @brief  获取PDM的FIFO深度，用于在DMA传输时指定传输的源地址。
 * @return PDM的FIFO深度。
 * @endif
 */
typedef uint32_t (*hal_pdm_get_fifo_deepth_t)(void);

/**
 * @if Eng
 * @brief  Interface between PDM driver and PDM hal.
 * @else
 * @brief  Driver层PDM和HAL层PDM的接口。
 * @endif
 */
typedef struct hal_pdm_funcs {
    hal_pdm_init_t              init;               /*!< @if Eng Init device interface.
                                                         @else   HAL层PDM的初始化接口。 @endif */
    hal_pdm_deinit_t            deinit;             /*!< @if Eng Deinit device interface.
                                                         @else   HAL层PDM去初始化接口。 @endif */
    hal_pdm_set_attr_t          set_attr;           /*!< @if Eng Set the attribute of PDM.
                                                         @else   HAL层设置PDM参数接口。 @endif */
    hal_pdm_get_attr_t          get_attr;           /*!< @if Eng Get the attribute of PDM.
                                                         @else   HAL层获取PDM参数接口。 @endif */
    hal_pdm_start_t             start;              /*!< @if Eng Start the PDM.
                                                         @else   HAL层启动PDM采样接口。 @endif */
    hal_pdm_stop_t              stop;               /*!< @if Eng Stop the PDM.
                                                         @else   HAL层停止PDM采样接口。 @endif */
    hal_pdm_get_fifo_addr_t     get_fifo_addr;      /*!< @if Eng Get the FIFO address of PDM.
                                                         @else   HAL层获取PDM的FIFO基地址接口。 @endif */
    hal_pdm_get_fifo_deepth_t   get_fifo_deepth;    /*!< @if Eng Get the FIFO deepth of PDM.
                                                         @else   HAL层获取PDM的FIFO深度接口。 @endif */
} hal_pdm_funcs_t;

/**
 * @if Eng
 * @brief  Init the registers of PDM IPs.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  初始化寄存器基地址列表。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_pdm_regs_init(void);

/**
 * @if Eng
 * @brief  Deinit the registers of PDM IPs.
 * @else
 * @brief  去初始化寄存器基地址列表。
 * @endif
 */
void hal_pdm_regs_deinit(void);

/**
 * @if Eng
 * @brief  Register @ref hal_pdm_funcs_t into the g_hal_pdms_funcs.
 * @param  [in]  funcs Interface between PDM driver and PDM hal.
 * @retval ERRCODE_SUCC Success.
 * @retval Other        Failure. For details, see @ref errcode_t
 * @else
 * @brief  注册 @ref hal_pdm_funcs_t 到 g_hal_pdms_funcs。
 * @param  [in]  funcs Driver层PDM和HAL层PDM的接口实例。
 * @retval ERRCODE_SUCC 成功。
 * @retval Other        失败。参考 @ref errcode_t
 * @endif
 */
errcode_t hal_pdm_register_funcs(hal_pdm_funcs_t *funcs);

/**
 * @if Eng
 * @brief  Unregister @ref hal_pdm_funcs_t from g_hal_pdms_funcs.
 * @else
 * @brief  从g_hal_pdms_funcs注销 @ref hal_pdm_funcs_t 。
 * @endif
 */
void hal_pdm_unregister_funcs(void);

/**
 * @if Eng
 * @brief  Get interface between PDM driver and PDM hal, For details, see @ref hal_pdm_funcs_t
 * @return Interface between PDM driver and PDM hal, For details, see @ref hal_pdm_funcs_t
 * @else
 * @brief  获取Driver层PDM和HAL层PDM的接口实例。参考 @ref hal_pdm_funcs_t
 * @return Driver层PDM和HAL层PDM的接口实例。参考 @ref hal_pdm_funcs_t
 * @endif
 */
hal_pdm_funcs_t *hal_pdm_get_funcs(void);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
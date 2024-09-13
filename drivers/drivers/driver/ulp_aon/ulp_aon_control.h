/*
 * Copyright (c) @CompanyNameMagicTag 2019-2020. All rights reserved.
 * Description:   ulp aon control head file
 * Author: @CompanyNameTag
 * Create: 2019-12-19
 */
#ifndef NON_OS_ULP_AON_CONTROL_H
#define NON_OS_ULP_AON_CONTROL_H

#include "non_os.h"
#include "chip_io.h"

/** @defgroup connectivity_drivers_non_os_ulp_aon ULP Aon
  * @ingroup  connectivity_drivers_non_os
  * @{
  */
typedef enum {
    PMU_CODEC_ISO_N,
    PMU_CMU_IS_N,
    PMU2_ISO_N,
    PMU1_ISO_N,
} pmu_iso_man_sel_t;

/** @defgroup connectivity_drivers_non_os_ulp_aon ULP Aon
  * @ingroup  connectivity_drivers_non_os
  * @{
  */
typedef enum {
    ULP_CLK_32_FROM_PMU_RC_32K = 0x0, // in fact only 26k
    ULP_CLK_32_FROM_XO_32K     = 0x1,
    ULP_CLK_32_FROM_AON_SUB    = 0x3,
} ulp_32k_sel_t;
/**
 * @brief  Init ulp aon, turn on ulp aon slep/wakeup.
 * @return None
 */
void ulp_aon_init(void);

/**
 * @brief  Ulp aon ship mode config.
 * @param  en_ship_mode Enable/Disable ship mode.
 * @return None
 */
void ulp_aon_ship_mode_cfg(bool en_ship_mode);

/**
 * @brief  Enter WFI befor clear ulp aon wakeup/sleep status.
 * @return None
 */
void ulp_aon_before_enter_wfi_handle(void);

/**
 * @brief  Manual control ULP GPIO pull down/up.
 * @param  sleep_n_pull           pull up/down
 * @return None
 */
void ulp_aon_sleep_n_pad_manual_control(switch_type_t sleep_n_pull);

/**
 * @brief  en_ref_bg1 manual or auto config
 * @param  ref_bg1_manual   manual or auto
 * @return None
 */
void ulp_en_ref_bg1_manual_config(switch_type_t ref_bg1_manual);

/**
 * @brief  Config en_ref_bg1 manual value
 * @param  ref_bg1_manual   manual value
 * @return None
 */
void ulp_en_ref_bg1_select_config(switch_type_t ref_bg1_manual);

/**
 * @brief  PMU IOS manual or auto config
 * @param  pmu_iso_man Which IOS module
 * @param  manual_switch   manual or auto
 * @return None
 */
void pmu_iso_manual_config(pmu_iso_man_sel_t pmu_iso_man, switch_type_t manual_switch);

/**
 * @brief  Config PMU IOS manual value
 * @param  pmu_iso_sel  Which IOS module
 * @param  select_switch   manual value
 * @return None
 */
void pmu_iso_select_config(pmu_iso_man_sel_t pmu_iso_sel, switch_type_t select_switch);

/**
 * @brief  VDD1P9 sw off manual or auto config.
 * @param  man_switch     Manual or auto mode config
 * @return None
 */
void ulp_vdd1p9_sw_off_manual_config(switch_type_t man_switch);

/**
 * @brief  VDD1P9 sw off manual value config.
 * @param  sel_switch     Manual value config
 * @return None
 */
void ulp_vdd1p9_sw_off_select_config(switch_type_t sel_switch);

/**
 * @brief  VDD0P7 to sys iso en manual or auto config.
 * @param  man_switch     Manual or auto mode config
 * @return None
 */
void ulp_vdd0p7_to_sys_iso_en_manual_config(switch_type_t man_switch);

/**
 * @brief  VDD0P7 to sys iso en manual value config.
 * @param  sel_switch     Manual value config
 * @return None
 */
void ulp_vdd0p7_to_sys_iso_en_select_config(switch_type_t sel_switch);

/**
 * @brief  Clamp digital circuit reset.
 * @return None
 */
void ulp_aon_rst_boot_select(void);

/**
 * @brief  Glb mem power force control.
 * @param  mem_pwr_on     Force enable power or not.
 * @return None
 */
void ulp_glb_mem_pwr_force_on_control(switch_type_t mem_pwr_on);

/**
 * @brief  Glb mem power force control.
 * @param  sel     select 32k clock for ulp aon.
 * @return None
 */
void ulp_aon_clk_32k_sel(ulp_32k_sel_t sel);
/**
  * @}
  */
#endif

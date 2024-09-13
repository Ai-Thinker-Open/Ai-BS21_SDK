/*
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved.
 * Description:  PMU DRIVER HEADER FILE
 * Author: @CompanyNameTag
 * Create:  2022-06-18
 */

#ifndef NON_OS_APPLICATION_CORE_PMU_LDO_H
#define NON_OS_APPLICATION_CORE_PMU_LDO_H

#include "chip_io.h"

/** @defgroup connectivity_drivers_non_os_pmu_ldo PMU Ldo
  * @ingroup  connectivity_drivers_non_os_pmu
  * @{
  */

typedef enum pmu_ldo_pwr_ctl {
    PMU_LDO_POWER_OFF,
    PMU_LDO_POWER_ON,
    PMU_LDO_POWER_AUTO,
} pmu_ldo_pwr_ctl_t;

/**
 * @brief  PMU manual config init.
 */
void pmu_wakeup_manual_config(void);

/**
 * @brief  Config buck ldo vset.
 * @param  vset Buck ldo vset value to be configured.
 */
void pmu_buck_ldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get buck ldo vset value.
 * @return Buck ldo vset value.
 */
uint8_t pmu_buck_ldo_get_vset(void);

/**
 * @brief  Config sysldo vset.
 * @param  vset Sysldo vset value to be configured.
 */
void pmu_sysldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get sysldo vset value.
 * @return Sysldo vset value.
 */
uint8_t pmu_sysldo_get_vset(void);

/**
 * @brief  Config cldo vset.
 * @param  vset Cldo vset value to be configured.
 */
void pmu_cldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get cldo vset value.
 * @return Cldo vset value.
 */
uint8_t pmu_cldo_get_vset(void);

/**
 * @brief  Config micldo vset.
 * @param  vset Micldo vset value to be configured.
 */
void pmu_micldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get micldo vset value.
 * @return Micldo vset value.
 */
uint8_t pmu_micldo_get_vset(void);

/**
 * @brief  Config nfcldo vset.
 * @param  vset Nfcldo vset value to be configured.
 */
void pmu_nfcldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get nfcldo vset value.
 * @return Nfcldo vset value.
 */
uint8_t pmu_nfcldo_get_vset(void);

/**
 * @brief  Power on or power off nfcldo.
 * @param  pwr_ctl Power control. For details, see @ref pmu_ldo_pwr_ctl_t.
 */
void pmu_nfcldo_power_cfg(uint8_t pwr_ctl);

/**
 * @brief  Config flashldo vset.
 * @param  vset flashldo vset value to be configured.
 */
void pmu_flashldo_vset_cfg(uint8_t vset);

/**
 * @brief  Get flashldo vset value.
 * @return Flashldo vset value.
 */
uint8_t pmu_flashldo_get_vset(void);

/**
 * @brief  Power on or power off flashldo.
 * @param  pwr_ctl Power control. For details, see @ref pmu_ldo_pwr_ctl_t.
 */
void pmu_flashldo_power_cfg(uint8_t pwr_ctl);

/**
 * @brief  Power on or power off micldo.
 * @param  pwr_ctl Power control. For details, see @ref pmu_ldo_pwr_ctl_t.
 */
void pmu_micldo_power_cfg(uint8_t pwr_ctl);

/**
  * @}
  */
#endif

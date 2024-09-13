/*
 * Copyright (c) @CompanyNameMagicTag 2018-2020. All rights reserved.
 * Description: PMU INTERRUPT HEADER
 * Author: @CompanyNameTag
 * Create:  2018-10-15
 */

#ifndef NON_OS_APPLICATION_CORE_PMU_INTERRUPT_H
#define NON_OS_APPLICATION_CORE_PMU_INTERRUPT_H

#include <stdint.h>
#include "chip_definitions.h"
#include "platform_core.h"

/** @defgroup connectivity_drivers_non_os_pmu_interrupt PMU Interrupt
  * @ingroup  connectivity_drivers_non_os_pmu
  * @{
  */

/**
 * @brief  Wakeup interrupt handler, deal with that restore clk,vol,register,glb value.
 */
void pmu_wakeup_handler(void);

/**
 * @brief  Sleep interrupt handler, deal with tha clk gating,vol buck,register/glb value preserve.
 */
void pmu_sleep_handler(void);

/**
 * @brief  Pmu interrupts init, register interrupt,set priority, enable interrupt,and so on.
 */
void pmu_init_interrupts(void);

/**
  * @}
  */
#endif

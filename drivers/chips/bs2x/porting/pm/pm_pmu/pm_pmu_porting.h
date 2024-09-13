/**
 * Copyright (c) @CompanyNameMagicTag 2023-2023. All rights reserved. \n
 *
 * Description: Provides pm pmu port \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2023-07-29， Create file. \n
 */
#ifndef PM_PMU_PORTING_H
#define PM_PMU_PORTING_H

#include <stdbool.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/**
 * @defgroup drivers_port_pm_pmu PM pmu
 * @ingroup  drivers_port_pm
 * @{
 */

typedef enum pmu_control_type {
    /* LDO. */
    PMU_CONTROL_FLASHLDO_POWER,           /* For power configuration, see @ref pmu_control_power_t */
    PMU_CONTROL_MICLDO_POWER,             /* For power configuration, see @ref pmu_control_power_t */
#ifdef NFC_TASK_EXIST
    PMU_CONTROL_NFCLDO_POWER,             /* For power configuration, see @ref pmu_control_power_t */
#endif
#ifdef PIN_RESET_ENABLE
    PMU_CONTROL_PIN_RESET_ENABLE,         /* For power configuration, see @ref pin_t */
    PMU_CONTROL_PIN_RESET_DISABLE,        /* For power configuration, see @ref pin_t */
#endif
    PMU_CONTROL_TYPE_MAX,
} pmu_control_type_t;

typedef enum pmu_control_power {
    PMU_CONTROL_POWER_OFF,
    PMU_CONTROL_POWER_ON,
    PMU_CONTROL_POWER_AUTO
} pmu_control_power_t;

typedef enum pmu_ldo_id {
    PMU_LDO_ID_BUCK_1P1,        /* For voltage configuration, see @ref pmu_buck_1p1_vset_t */
    PMU_LDO_ID_SYSLDO,          /* For voltage configuration, see @ref pmu_sysldo_vset_t */
    PMU_LDO_ID_FLASHLDO,        /* For voltage configuration, see @ref pmu_flash_ldo_vset_t */
    PMU_LDO_ID_CLDO,            /* For voltage configuration, see @ref pmu_cldo_vset_t */
    PMU_LDO_ID_MICLDO,          /* For voltage configuration, see @ref pmu_micldo_vset_t */
#ifdef NFC_TASK_EXIST
    PMU_LDO_ID_NFCLDO,          /* For voltage configuration, see @ref pmu_nfcldo_vset_t */
#endif
} pmu_ldo_id_t;

typedef enum pmu_buck_1p1_vset {
    PMU_BUCK_1P1_VSET_0V7   = 0x0,
    PMU_BUCK_1P1_VSET_0V725 = 0x1,
    PMU_BUCK_1P1_VSET_0V75  = 0x2,
    PMU_BUCK_1P1_VSET_0V775 = 0x3,
    PMU_BUCK_1P1_VSET_0V8   = 0x4,
    PMU_BUCK_1P1_VSET_0V825 = 0x5,
    PMU_BUCK_1P1_VSET_0V85  = 0x6,
    PMU_BUCK_1P1_VSET_0V875 = 0x7,
    PMU_BUCK_1P1_VSET_0V9   = 0x8,
    PMU_BUCK_1P1_VSET_0V925 = 0x9,
    PMU_BUCK_1P1_VSET_0V95  = 0xa,
    PMU_BUCK_1P1_VSET_0V975 = 0xb,
    PMU_BUCK_1P1_VSET_1V0   = 0xc,
    PMU_BUCK_1P1_VSET_1V025 = 0xd,
    PMU_BUCK_1P1_VSET_1V05  = 0xe,
    PMU_BUCK_1P1_VSET_1V075 = 0xf,
    PMU_BUCK_1P1_VSET_1V1   = 0x10,
    PMU_BUCK_1P1_VSET_1V125 = 0x11,
    PMU_BUCK_1P1_VSET_1V15  = 0x12,
    PMU_BUCK_1P1_VSET_1V175 = 0x13,
    PMU_BUCK_1P1_VSET_1V2   = 0x14,
    PMU_BUCK_1P1_VSET_1V225 = 0x15,
    PMU_BUCK_1P1_VSET_1V25  = 0x16,
    PMU_BUCK_1P1_VSET_1V275 = 0x17,
    PMU_BUCK_1P1_VSET_1V3   = 0x18,
    PMU_BUCK_1P1_VSET_1V325 = 0x19,
    PMU_BUCK_1P1_VSET_1V35  = 0x1a,
    PMU_BUCK_1P1_VSET_1V375 = 0x1b,
    PMU_BUCK_1P1_VSET_1V4   = 0x1c,
    PMU_BUCK_1P1_VSET_1V425 = 0x1d,
    PMU_BUCK_1P1_VSET_1V45  = 0x1e,
    PMU_BUCK_1P1_VSET_1V475 = 0x1f,
} pmu_buck_1p1_vset_t;

typedef enum pmu_sysldo_vset {
    PMU_SYSLDO_VSET_0V7   = 0x0,
    PMU_SYSLDO_VSET_0V75  = 0x1,
    PMU_SYSLDO_VSET_0V8   = 0x2,
    PMU_SYSLDO_VSET_0V85  = 0x3,
    PMU_SYSLDO_VSET_0V875 = 0x4,
    PMU_SYSLDO_VSET_0V9   = 0x5,
    PMU_SYSLDO_VSET_0V925 = 0x6,
    PMU_SYSLDO_VSET_0V95  = 0x7,
    PMU_SYSLDO_VSET_0V975 = 0x8,
    PMU_SYSLDO_VSET_1V0   = 0x9,
    PMU_SYSLDO_VSET_1V025 = 0xa,
    PMU_SYSLDO_VSET_1V05  = 0xb,
    PMU_SYSLDO_VSET_1V075 = 0xc,
    PMU_SYSLDO_VSET_1V1   = 0xd,
    PMU_SYSLDO_VSET_1V15  = 0xe,
    PMU_SYSLDO_VSET_1V2   = 0xf,
} pmu_sysldo_vset_t;

typedef enum pmu_flash_ldo_vset {
    PMU_FLASHLDO_VSET_1V5 = 0x0,
    PMU_FLASHLDO_VSET_1V8 = 0x1,
    PMU_FLASHLDO_VSET_2V1 = 0x2,
    PMU_FLASHLDO_VSET_2V4 = 0x3,
} pmu_flash_ldo_vset_t;

typedef enum pmu_cldo_vset {
    PMU_CLDO_VSET_0V9   = 0x0,
    PMU_CLDO_VSET_0V925 = 0x1,
    PMU_CLDO_VSET_0V95  = 0x2,
    PMU_CLDO_VSET_1V0   = 0x3,
    PMU_CLDO_VSET_1V05  = 0x4,
    PMU_CLDO_VSET_1V1   = 0x5,
    PMU_CLDO_VSET_1V15  = 0x6,
    PMU_CLDO_VSET_1V2   = 0x7,
} pmu_cldo_vset_t;

typedef enum pmu_micldo_vset {
    PMU_MICLDO_VSET_1V1 = 0x0,
    PMU_MICLDO_VSET_1V3 = 0x1,
    PMU_MICLDO_VSET_1V5 = 0x2,
    PMU_MICLDO_VSET_1V8 = 0x3,
    PMU_MICLDO_VSET_2V0 = 0x4,
    PMU_MICLDO_VSET_2V2 = 0x5,
    PMU_MICLDO_VSET_2V5 = 0x6,
    PMU_MICLDO_VSET_2V8 = 0x7,
} pmu_micldo_vset_t;

typedef enum pmu_nfcldo_vset {
    PMU_NFCLDO_VSET_1V1 = 0x1,
    PMU_NFCLDO_VSET_1V2 = 0x2,
    PMU_NFCLDO_VSET_1V3 = 0x3,
    PMU_NFCLDO_VSET_1V4 = 0x4,
    PMU_NFCLDO_VSET_1V5 = 0x5,
    PMU_NFCLDO_VSET_1V6 = 0x6,
    PMU_NFCLDO_VSET_1V7 = 0x7,
    PMU_NFCLDO_VSET_1V8 = 0x8,
    PMU_NFCLDO_VSET_1V9 = 0x9,
    PMU_NFCLDO_VSET_2V0 = 0xA,
    PMU_NFCLDO_VSET_2V1 = 0xB,
    PMU_NFCLDO_VSET_2V2 = 0xC,
    PMU_NFCLDO_VSET_2V3 = 0xD,
    PMU_NFCLDO_VSET_2V4 = 0xE,
    PMU_NFCLDO_VSET_2V5 = 0xF,
} pmu_nfcldo_vset_t;

typedef enum pmu_power_supply {
    PMU_POWER_SUPPLY_BY_BUCK,
    PMU_POWER_SUPPLY_BY_LDO,
} pmu_power_supply_t;

void pm_pmu_power_supply_mode_init(void);
pmu_power_supply_t pm_get_pmu_power_supply_mode(void);
void pm_efuse_ldo_power(bool on);

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif
/*
 * Copyright (c) CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description:   CPU load
 * Author:
 * Create: 2021-04-06
 */
#ifndef CPU_LOAD_H
#define CPU_LOAD_H
#include "std_def.h"
#include "platform_types.h"

/**
 * @defgroup connectivity_libs_cpu_load CPU Load
 * @ingroup  connectivity_libs
 * @{
 */
#define SECTION_MAX 20

/**
 * @brief  Section types for image
 */
typedef enum {
    SECTION_TYPE_INIT = 1,  //!< The section that needs to be initialized.
    SECTION_TYPE_CLEAR,     //!< The section that needs to be cleared.
    SECTION_TYPE_RELOAD,    //!< The section that needs to be reloaded.
    SECTION_TYPE_MAX,
} section_type_e;

/**
 * @brief  Section infomation for image.
 */
typedef struct {
    const uint32_t section_type;
    const uint32_t *section_run_begin;
    const uint32_t *section_run_end;
    const uint32_t *section_load_addr;
    const uint32_t section_reserved_value;
} section_info_t;

/**
 * @brief  Section head infomation.
 */
typedef struct {
    const uint32_t section_num;
    const uint32_t reserved;
    const section_info_t section_info[SECTION_MAX];
} section_head_t;

/**
 * @brief  Get section information from image.
 * @param  image The image has seciton information.
 * @return Section infomation of image.
 */
const section_head_t *cpu_load_get_section_info(core_images_e image);

/**
 * @brief  Load image.
 * @param  load_info The information of image.
 * @param  image The image has seciton information.
 */
void cpu_load_image(const section_head_t *load_info, core_images_e image);

/**
 * @}
 */
#endif

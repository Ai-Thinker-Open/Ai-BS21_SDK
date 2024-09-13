/**
 * Copyright (c) @CompanyNameMagicTag 2022-2023. All rights reserved. \n
 *
 * Description: Provides configuration definitions related to partitions. \n
 * Author: @CompanyNameTag \n
 * History: \n
 * 2022-09-01, Create file. \n
 */
#ifndef PARTITION_RESOURCE_ID_H
#define PARTITION_RESOURCE_ID_H

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

/* partition image id, must be same as flash partition bin */
#define PARTITION_IMAGE_ID  0x4B87A52D

/**
 * @defgroup middleware_chips_brandy_partition Partition
 * @ingroup  middleware_chips_brandy
 * @{
 */

/**
 * @if Eng
 * @brief  Partition ids.
 * @else
 * @brief  分区ID
 * @endif
 */
typedef enum {
    PARTITION_FLASHBOOT_IMAGE = 0x0,
    PARTITION_FLASHBOOT_BACKUP = 0x1,
    PARTITION_ACPU_IMAGE = 0x23,
    PARTITION_NV_DATA = 0x25,
    PARTITION_FOTA_DATA = 0x26,
    PARTITION_RESERVED_0 = 0x27,
    PARTITION_RESERVED_1 = 0x28,
    PARTITION_FLASHBOOT_DFU_VID_PID = 0x29,
    PARTITION_RESERVED_3 = 0x30,
    PARTITION_RESERVED_4 = 0x31,
    PARTITION_RESERVED_5 = 0x32,
    PARTITION_RESERVED_6 = 0x33,
    PARTITION_MAX_CNT = 12 /* !< @if Eng Maximum number of partitions.
        The value is recorded only as the number of partitions and is not used to determine the ID validity.
                                @else   分区的数量，这个枚举只用来记录分区的数量，不作为分区ID有效性的判断 @endif */
} partition_ids_t;

/**
 * @}
 */

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* PARTITION_RESOURCE_ID_H */

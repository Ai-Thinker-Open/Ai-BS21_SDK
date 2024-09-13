/*
 * Copyright (c) @CompanyNameMagicTag 2021-2021. All rights reserved.
 * Description: touch screen msg queue.
 * Author: @CompanyNameTag
 * Create: 2022-04-18
 */

#ifndef TOUCH_SCREEN_QUEUE1_H
#define TOUCH_SCREEN_QUEUE1_H

#include "soc_osal.h"
#include "touch_screen_def.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#define ts_mem_free(sz)                 \
    do {                                     \
        if ((sz) != NULL) {               \
            osal_kfree((sz));    \
        }                                    \
        (sz) = NULL;                      \
    } while (0)

struct ts_list {
    input_event_info *msg;
    struct ts_list *next;
};

typedef struct {
    struct ts_list *head;
    struct ts_list *tail;
    uint32_t cnt;
    uint32_t cap;
} ts_queue_t;

ts_queue_t *ts_init_queue(uint32_t capacity);
int32_t ts_queue_get_length(ts_queue_t *q);
int32_t ts_queue_is_empty(const ts_queue_t *q);
int32_t ts_queue_is_full(const ts_queue_t *q);
int32_t ts_de_queue(ts_queue_t *q, input_event_info *msg);
int32_t ts_en_queue(ts_queue_t *q, input_event_info *msg);
void ts_clear_queue(ts_queue_t *q);
void ts_delete_queue(ts_queue_t *q);

#ifdef __cplusplus
#if __cplusplus
    }
#endif
#endif

#endif
/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2023-2023. All rights reserved.
 * Description: Cmsis(safe) KAL Interface
 * Author: Huawei LiteOS Team
 * Create: 2023-05-23
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --------------------------------------------------------------------------- */

#ifndef KAL_CMSIS_SAFE_H
#define KAL_CMSIS_SAFE_H

#include "cmsis_os.h"
#include "los_task_pri.h"
#include "los_memory.h"
#include "los_membox.h"
#include "los_hwi_pri.h"
#ifdef LOSCFG_BASE_IPC_SEM
#include "los_sem_pri.h"
#endif
#ifdef LOSCFG_BASE_CORE_SWTMR
#include "los_swtmr_pri.h"
#endif
#ifdef LOSCFG_BASE_IPC_MUX
#include "los_mux_pri.h"
#endif
#ifdef LOSCFG_BASE_IPC_EVENT
#include "los_event_pri.h"
#endif
#ifdef LOSCFG_BASE_IPC_QUEUE
#include "los_queue.h"
#include "los_queue_pri.h"
#endif
#include "arch/pmp.h"

#define CMSIS_INT_ACTIVE                    (g_intCount[ArchCurrCpuid()] > 0)
#define ERROR_IS_INVALID_SID(ret)           ((ret) == LOS_ERRNO_SEC_INVALID_SID)

#define GET_QUEUEINFO_INFO(queueInfo)       (queueInfo.info)
#define GET_QUEUEINFO_LEN(queueInfo)        (queueInfo.info.queueLen)
#define GET_QUEUEINFO_MSGSIZE(queueInfo)    (queueInfo.info.queueSize)
#define GET_QUEUEINFO_COUNT(queueInfo)      (queueInfo.info.readWriteableCnt[OS_QUEUE_READ])
#define GET_QUEUEINFO_SPACE(queueInfo)      (queueInfo.info.readWriteableCnt[OS_QUEUE_WRITE])

#define THREAD_CMSIS2LITEOS(threadId)   ((UINT32)(UINTPTR)threadId)
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
#define THREAD_LITEOS2CMSIS(threadId)   ((osThreadId_t)(UINTPTR)threadId)
#else
#define THREAD_LITEOS2CMSIS(threadId)   ((osThreadId)(UINTPTR)threadId)
#endif

#define SEM_CMSIS2LITEOS(semId)         ((UINT32)(UINTPTR)semId)
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
#define SEM_LITEOS2CMSIS(semId)         ((osSemaphoreId_t)(UINTPTR)semId)
#else
#define SEM_LITEOS2CMSIS(semId)         ((osSemaphoreId)(UINTPTR)semId)
#endif

#define MUX_CMSIS2LITEOS(muxId)         ((UINT32)(UINTPTR)muxId)
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
#define MUX_LITEOS2CMSIS(muxId)         ((osMutexId_t)(UINTPTR)muxId)
#else
#define MUX_LITEOS2CMSIS(muxId)         ((osMutexId)(UINTPTR)muxId)
#endif

#define QUEUE_CMSIS2LITEOS(queueId)     ((UINT32)(UINTPTR)queueId)
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
#define QUEUE_LITEOS2CMSIS(queueId)     ((osMessageQueueId_t)(UINTPTR)queueId)
#else
#define QUEUE_LITEOS2CMSIS(queueId)     ((osMessageQId)(UINTPTR)queueId)
#endif

#define SWTMR_CMSIS2LITEOS(swtmrId)     ((UINT16)(((UINT16)(UINTPTR)swtmrId) - (UINT16)1))
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
#define SWTMR_LITEOS2CMSIS(swtmrId)     ((osTimerId_t)(UINTPTR)(swtmrId + (UINT16)1))
#else
#define SWTMR_LITEOS2CMSIS(swtmrId)     ((osTimerId)(UINTPTR)(swtmrId + (UINT16)1))
#endif

#define EVENT_CMSIS2LITEOS(eventId)     ((UINT32)(UINTPTR)eventId)
#define EVENT_LITEOS2CMSIS(eventId)     ((osEventFlagsId_t)(UINTPTR)eventId)
typedef struct {
    void *(*startRoutine)(void *);
    UINTPTR         args[4];
} CmsisData;


LITE_OS_SEC_ALW_INLINE STATIC INLINE BOOL KAL_GetPreemptableStatus(VOID)
{
    OsKernelInfo info = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_KERNEL, 0, &info, (UINT32)sizeof(info)) != LOS_OK) {
        return FALSE;
    }
    return info.preemptible;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE const CHAR *KAL_GetTaskName(UINT32 taskId)
{
    TSK_INFO_S taskInfo = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_TASK, taskId, &taskInfo, (UINT32)sizeof(taskInfo)) != LOS_OK) {
        return NULL;
    }
    return taskInfo.taskName;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_GetCurTaskId(VOID)
{
    UINT32 taskId = LOS_CurTaskIDGet();
    if (taskId == LOS_ERRNO_TSK_ID_INVALID) {
        return 0;
    }
    return taskId;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_GetTaskState(UINT32 taskId, UINT16 *taskStatus)
{
    TSK_INFO_S taskInfo = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_TASK, taskId, &taskInfo, (UINT32)sizeof(taskInfo)) != LOS_OK) {
        return LOS_NOK;
    }
    *taskStatus = taskInfo.status;
    return LOS_OK;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_GetTaskStackSize(UINT32 taskId)
{
    TSK_INFO_S taskInfo = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_TASK, taskId, &taskInfo, (UINT32)sizeof(taskInfo)) != LOS_OK) {
        return 0;
    }
    return taskInfo.stackSize;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_GetTaskStackSpace(UINT32 taskId)
{
    TSK_INFO_S taskInfo = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_TASK, taskId, &taskInfo, (UINT32)sizeof(taskInfo)) != LOS_OK) {
        return 0;
    }
    if (taskInfo.ovf == LOS_NOK) {
        return 0;
    }

    return taskInfo.stackSize - taskInfo.peakUsed;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_GetTaskCount(VOID)
{
    OsKernelInfo info = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_KERNEL, 0, &info, (UINT32)sizeof(info)) != LOS_OK) {
        return 0;
    }
    return info.taskCount;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_ThreadGetPid(UINT32 thread_id)
{
    if (LOS_TaskPriGet(thread_id) == (UINT16)OS_INVALID) {
        return (UINT32)-1;
    }

    return thread_id;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_TaskDelete(UINT32 taskId, const VOID *value)
{
    return OsTaskDeleteDynamic(taskId, value);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_TaskSelfDelete(VOID)
{
    return OsTaskDeleteDynamic(LOS_CurTaskIDGet(), NULL);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_ThreadCreate(UINT32 *tId,
                                                             TSK_INIT_PARAM_S *taskInitParam,
                                                             VOID *stackMem)
{
    if (stackMem != NULL) {
        return LOS_TaskCreateStatic(tId, taskInitParam, stackMem);
    } else {
        return OsTaskCreateDynamic(tId, taskInitParam, FALSE);
    }
}

#ifdef LOSCFG_BASE_IPC_QUEUE
LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueCreate(UINT32 *queueId,
                                                            VOID *pool,
                                                            UINT32 queueSize,
                                                            UINT32 msgSize)
{
    UINT16 poolSize = (UINT16)OS_QUEUEMEM_SIZE(msgSize, queueSize);
    if (pool != NULL) {
        return LOS_QueueCreateStatic(NULL, (UINT16)queueSize, queueId,
                                     0, (UINT16)msgSize, pool, poolSize);
    } else {
        pool = LOS_MemAlloc((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], poolSize);
        if (pool == NULL) {
            return LOS_NOK;
        }

        UINT32 ret = LOS_QueueCreateStatic(NULL, (UINT16)queueSize, queueId,
                                           0, (UINT16)msgSize, pool, poolSize);
        if (ret != LOS_OK) {
            (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], pool);
        }

        return ret;
    }
}

LITE_OS_SEC_ALW_INLINE  STATIC INLINE UINT32 KAL_QueueDelete(UINT32 queueId, BOOL userFlag)
{
    if (!userFlag) {
        return LOS_QueueDelete(queueId);
    } else {
        UINT32 ret;
        OsQueueInfo info = {0};
        if (OsResourceInfoGet(RESORURCE_TYPE_QUEUE, queueId, &info, (UINT32)sizeof(info)) != LOS_OK) {
            return LOS_NOK;
        }
        ret = LOS_QueueDelete(queueId);
        if (ret == LOS_OK) {
            (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], info.queueHandle);
        }
        return ret;
    }
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueWriteCopy(UINT32 queueId, VOID *msg_ptr, UINT32 timeout)
{
    return LOS_QueueWriteCopy(queueId, msg_ptr, OS_NULL_INT, timeout);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueReadCopy(UINT32 queueId, VOID *msg_ptr, UINT32 timeout)
{
    UINT32 bufferSize = OS_NULL_INT;
    return LOS_QueueReadCopy(queueId, msg_ptr, &bufferSize, timeout);
}
#endif

#ifdef LOSCFG_BASE_IPC_EVENT
#ifdef LOSCFG_COMPAT_CMSIS_VER_2
LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 MappingEventRet(UINT32 ret)
{
    switch (ret) {
        case LOS_ERRNO_EVENT_PTR_NULL:
        case LOS_ERRNO_EVENT_SETBIT_INVALID:
        case LOS_ERRNO_EVENT_EVENTMASK_INVALID:
        case LOS_ERRNO_EVENT_FLAGS_INVALID:
        case LOS_ERRNO_SEC_INVALID_SID:
            return (UINT32)osFlagsErrorParameter;
        case LOS_ERRNO_EVENT_READ_TIMEOUT:
            return (UINT32)osFlagsErrorTimeout;
        default:
            return (UINT32)osFlagsErrorResource;
    }
}
#endif

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_TaskEventRead(UINT32 eventMask, UINT32 mode, UINT32 timeout)
{
        return OsEventReadWithId(0, OS_EVENT_ID_TYPE_CURTASK, eventMask, mode, timeout);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_EventRead(UINT32 id, UINT32 eventMask, UINT32 mode, UINT32 timeout)
{
    return OsEventReadWithId(id, OS_EVENT_ID_TYPE_EVENT, eventMask, mode, timeout);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_TaskEventSetAndGetEvent(UINT32 id, UINT32 events, UINT32 retMode)
{
    return OsEventWriteAndGet(id, events, FALSE, OS_EVENT_ID_TYPE_TASK, retMode);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_EventSetAndGetEvent(UINT32 id, UINT32 events, UINT32 retMode)
{
    return OsEventWriteAndGet(id, events, FALSE, OS_EVENT_ID_TYPE_EVENT, retMode);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_TaskEventClearAndGetEvent(UINT32 id, UINT32 events)
{
    return OsEventClearAndGet(id, OS_EVENT_ID_TYPE_TASK, events, OS_EVENT_MODE_RETURN_BEFORE);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_CurTaskEventClearAndGetEvent(UINT32 events)
{
    return OsEventClearAndGet(0, OS_EVENT_ID_TYPE_CURTASK, events, OS_EVENT_MODE_RETURN_BEFORE);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_EventClearAndGetEvent(UINT32 id, UINT32 events)
{
    return OsEventClearAndGet(id, OS_EVENT_ID_TYPE_EVENT, events, OS_EVENT_MODE_RETURN_BEFORE);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_EventCreate(UINTPTR * eventId)
{
    return LOS_EventCreate((UINT32 *)eventId);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_EventDelete(UINT32 eventId)
{
    return LOS_EventDelete(eventId);
}
#endif

#ifdef LOSCFG_BASE_CORE_SWTMR
LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_SwtmrStart(UINT16 swtId, UINT32 interval, UINT32 expiry)
{
    return OsSwtmrStartTimer(swtId, interval, expiry);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE BOOL KAL_SwtmrIsRunning(UINT16 swtId)
{
    UINT32 tick;
    UINT32 interval;
    return (LOS_SwtmrTimeGet(swtId, &tick, &interval) == LOS_OK);
}
#endif

#ifdef LOSCFG_BASE_IPC_SEM
LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_SemPendAndGetCount(UINT32 sid, UINT32 timeout)
{
    return OsSemPendAndGetCount(sid, timeout);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_SemGetCount(UINT32 semId)
{
    OsSemInfo info = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_SEM, semId, &info, (UINT32)sizeof(info)) != LOS_OK) {
        return 0;
    }
    return info.semCount;
}
#endif

#ifdef LOSCFG_BASE_IPC_MUX
LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_MutexGetOwner(UINT32 mutexId)
{
    OsMuxInfo info = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_MUX, mutexId, &info, (UINT32)sizeof(info)) != LOS_OK) {
        return 0;
    }
    return info.ownerId;
}
#endif

#ifdef LOSCFG_COMPAT_CMSIS_VER_1
#ifndef LOSCFG_COMPAT_CMSIS_STATIC_ALLOCATION
/* internal function for osPool */
LITE_OS_SEC_ALW_INLINE STATIC INLINE VOID *KAL_PoolCreate(UINT32 blkNum, UINT32 blkSize)
{
    VOID *memBox = NULL;
    UINT64 poolSize;
    UINT32 boxCBSize;
    UINT32 ret;

    if ((blkNum == 0) || (blkSize == 0)) {
        return NULL;
    }

#ifdef LOSCFG_MEMBOX_STATIC
    poolSize = LOS_MEMBOX_SIZE(blkSize, (UINT64)blkNum);
    boxCBSize = (UINT32)poolSize;
#else
    blkSize = LOS_MEMBOX_ALLIGNED(blkSize);
    poolSize = blkSize * (UINT64)blkNum;
    boxCBSize = (UINT32)sizeof(LOS_MEMBOX_INFO);
#endif
    if ((UINT32)(poolSize >> 32) != 0) { /* get the high 32 bits */
        PRINT_DEBUG("pool size too large! \n");
        return NULL;
    }
    memBox = LOS_MemAlloc((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], boxCBSize);
    if (memBox == NULL) {
        return NULL;
    }

    ret = LOS_MemboxInit(memBox, (UINT32)poolSize, blkSize);
    if (ret != LOS_OK) {
        (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], memBox);
        return NULL;
    }
    return memBox;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_PoolDelete(VOID *pool)
{
    if (LOS_MemboxDeinit((const VOID *)pool) != LOS_OK) {
        PRINT_ERR("pool delete mux failed\n");
    }
    return LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], pool);
}
#endif

#ifdef LOSCFG_BASE_IPC_QUEUE
LITE_OS_SEC_ALW_INLINE STATIC_INLINE osStatus MappingQueueWriteRet(UINT32 ret)
{
    switch (ret) {
        case LOS_OK:
            return osOK;
        case LOS_ERRNO_QUEUE_TIMEOUT:
        case LOS_ERRNO_QUEUE_ISFULL:
            return osErrorTimeoutResource;
        case LOS_ERRNO_QUEUE_INVALID:
        case LOS_ERRNO_QUEUE_NOT_CREATE:
        case LOS_ERRNO_QUEUE_WRITE_PTR_NULL:
        case LOS_ERRNO_QUEUE_WRITESIZE_ISZERO:
        case LOS_ERRNO_QUEUE_WRITE_SIZE_TOO_BIG:
        case LOS_ERRNO_SEC_INVALID_SID:
            return osErrorParameter;
        default:
            return osErrorResource;
    }
}

LITE_OS_SEC_ALW_INLINE STATIC_INLINE osStatus MappingQueueReadRet(UINT32 ret)
{
    switch (ret) {
        case LOS_OK:
            return osEventMessage;
        case LOS_ERRNO_QUEUE_TIMEOUT:
        case LOS_ERRNO_QUEUE_ISEMPTY:
            return osEventTimeout;
        case LOS_ERRNO_QUEUE_INVALID:
        case LOS_ERRNO_QUEUE_NOT_CREATE:
        case LOS_ERRNO_QUEUE_READ_PTR_NULL:
        case LOS_ERRNO_QUEUE_READ_SIZE_TOO_SMALL:
        case LOS_ERRNO_SEC_INVALID_SID:
            return osErrorParameter;
        default:
            return osErrorResource;
    }
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE VOID *KAL_MailPoolCreate(UINT32 queueId,
                                                              VOID *pool,
                                                              UINT32 blkNum,
                                                              UINT32 blkSize)
{
    UINT64 poolSize;
    VOID *mailPool = NULL;
    VOID *mail = NULL;

    (VOID)pool;

    blkSize = (UINT32)LOS_Align((UINTPTR)blkSize, (UINT32)PMP_ADDR_ALIGN_SIZE);
    poolSize = blkSize * (UINT64)blkNum;
    if ((UINT32)(poolSize >> 32) != 0) { /* get the high 32 bits */
        PRINT_ERR("pool size too large! \n");
        return NULL;
    }

    mailPool = LOS_MemAllocAlign((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX],
                                 (UINT32)poolSize, (UINT32)PMP_ADDR_ALIGN_SIZE);
    if (mailPool == NULL) {
        PRINT_ERR("mail pool alloc failed!\n");
        return NULL;
    }
    mail = OsQueueMailCreate(queueId, blkNum, blkSize, mailPool);
    if (mail == NULL) {
        (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], mailPool);
    }
    return mail;
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE VOID *KAL_QueueMailAlloc(UINT32 queueId, VOID *mailPool, UINT32 tick)
{
    (VOID)mailPool;
    return OsQueueMailAlloc(queueId, tick, FALSE);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE VOID *KAL_QueueMailCAlloc(UINT32 queueId, VOID *mailPool, UINT32 tick)
{
    (VOID)mailPool;
    return OsQueueMailAlloc(queueId, tick, TRUE);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueMailFree(UINT32 queueId, VOID *mailPool, VOID *mailMem)
{
    (VOID)mailPool;
    return OsQueueMailFree(queueId, (const VOID *)mailMem);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueMailPut(UINT32 queueId, VOID *mailPool, VOID *mailMem, UINT32 opt)
{
    (VOID)mailPool;
    return OsQueueMailPut(queueId, mailMem, opt);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueMailGet(UINT32 queueId, VOID *mailPool, VOID *buff, UINT32 timeout)
{
    (VOID)mailPool;
    return OsQueueMailGet(queueId, buff, timeout);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE osStatus KAL_QueueMailDelete(UINT32 queueId, VOID *mailPool)
{
    (VOID)mailPool;
    UINT32 ret;
    LOS_ASSERT(g_curBoxId == OS_BOX_GET_BID(queueId))

#ifdef LOSCFG_COMPAT_CMSIS_STATIC_ALLOCATION
    ret = OsQueueMailDelete(queueId);
#else
    OsQueueInfo info = {0};
    if (OsResourceInfoGet(RESORURCE_TYPE_QUEUE, queueId, &info, (UINT32)sizeof(info)) != LOS_OK) {
        return osErrorOS;
    }

    ret = OsQueueMailDelete(queueId);
    if (ret == LOS_OK) {
        (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], info.queueHandle);
        (VOID)LOS_MemFree((VOID *)g_boxLocalPool[OS_MEM_POOL_INDEX], info.mailHandle);
    }
#endif
    return ((ret == LOS_OK) ? osOK : osErrorOS);
}

LITE_OS_SEC_ALW_INLINE STATIC INLINE UINT32 KAL_QueueMailClear(UINT32 queueId, VOID *mailPool)
{
    (VOID)mailPool;
    return OsQueueMailClear(queueId);
}
#endif /* LOSCFG_BASE_IPC_QUEUE */
#endif /* LOSCFG_COMPAT_CMSIS_VER_1 */
#endif /* KAL_CMSIS_SAFE_H */

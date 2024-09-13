STRING( REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CMAKE_CURRENT_SOURCE_DIR} )
set(MODULE_NAME ${CURRENT_FOLDER})

# add global include, compile macro and options to public target #
set(MODULE_INCLUDE_PUB)
set(MODULE_CXXINCLUDE_PUB)
set(MODULE_COPTS_PUB)
set(MODULE_ASOPTS_PUB)
set(MODULE_CXXOPTS_PUB)
set(MODULE_CMACRO_PUB)
set(MODULE_ASMACRO_PUB)
set(MODULE_CXXMACRO_PUB)


# add local include, compile macro and options to private target #
set(MODULE_INCLUDE_PRI
    ${LITEOSTOPDIR}/kernel/extended/include
    ${LITEOSTOPDIR}/kernel/extended/include/lowpower
    ${LITEOSTOPDIR}/kernel/base/mem
)
set(MODULE_COPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_ASOPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_CXXOPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_CMACRO_PRI)
set(MODULE_ASMACRO_PRI)
set(MODULE_CXXMACRO_PRI)


# add srcs to private target #
set(LOCAL_SRCS_y)
set(LOCAL_DIRS_y)
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_MIN}" los_bitmap.c los_err.c los_misc.c los_mp.c
                                              los_percpu.c los_sortlink.c los_stackinfo.c
                                              los_task.c los_tick.c los_exc.c)

list(APPEND "LOCAL_SRCS_${LOSCFG_ARCH_INTERRUPT_TAKEOVER}" los_hwi.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_IPC_QUEUE}" los_queue.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_IPC_EVENT}" los_event.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_IPC_MUX}" los_mux.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_IPC_SEM}" los_sem.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_IPC_RWSEM}" los_rwsem.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_BASE_CORE_SWTMR}" los_swtmr.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_SPINDEP}" los_spinlock.c)

# printf
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_PRINTF}" los_printf.c)

#ringbuf
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_RINGBUF}" los_ringbuf.c)

# debug
if (LOSCFG_DEBUG_TASK OR LOSCFG_SHELL OR NOT LOSCFG_EXC_SIMPLE_INFO)
list(APPEND "LOCAL_SRCS_y" debug/los_task_debug.c)
endif()
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_HWI}" debug/los_hwi_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_SWTMR}" debug/los_swtmr_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_QUEUE}" debug/los_queue_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_MUTEX}" debug/los_mux_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_SEMAPHORE}" debug/los_sem_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_DEBUG_SCHED_STATISTICS}" debug/los_sched_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_LOCKDEP}" debug/los_lockdep_debug.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_PTHREAD_MUXDEP}" debug/pthread_mux_deadlock_debug.c)

# Schedulers
list(APPEND "LOCAL_DIRS_${LOSCFG_SCHED_SQ}" sched/sched_sq)
list(APPEND "LOCAL_DIRS_${LOSCFG_SCHED_MQ}" sched/sched_mq)

# Memory Algorithms
list(APPEND "LOCAL_DIRS_${LOSCFG_KERNEL_MEM_BESTFIT}" mem/bestfit)
list(APPEND "LOCAL_DIRS_${LOSCFG_KERNEL_MEM_BESTFIT_LITTLE}" mem/bestfit_little)

# Memory Extension
list(APPEND "LOCAL_DIRS_${LOSCFG_KERNEL_MEM_SLAB_EXTENTION}" mem/slab)
list(APPEND "LOCAL_DIRS_${LOSCFG_MEM_TASK_STAT}" mem/common/memstat)

# Membox
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_MEMBOX_STATIC}" mem/membox/los_membox.c)
list(APPEND "LOCAL_SRCS_${LOSCFG_KERNEL_MEMBOX_DYNAMIC}" mem/membox/los_membox_dyn.c)

# Memory Debug
list(APPEND "LOCAL_DIRS_${LOSCFG_MEM_RECORDINFO}" mem/common/memrecord)
list(APPEND "LOCAL_DIRS_${LOSCFG_MEM_MUL_POOL}" mem/common/multipool)

# Shellcmd
if(LOSCFG_SHELL)
list(APPEND LOCAL_SRCS_y shellcmd/mempt_shellcmd.c)
list(APPEND LOCAL_SRCS_y shellcmd/sysinfo_shellcmd.c)
list(APPEND LOCAL_SRCS_y shellcmd/stack_shellcmd.c)
list(APPEND LOCAL_SRCS_y shellcmd/task_shellcmd.c)
list(APPEND LOCAL_SRCS_${LOSCFG_DEBUG_HWI} shellcmd/hwi_shellcmd.c)
list(APPEND LOCAL_SRCS_${LOSCFG_DEBUG_SWTMR} shellcmd/swtmr_shellcmd.c)
list(APPEND LOCAL_SRCS_${LOSCFG_LOWPOWER_SLEEP_DEBUG} shellcmd/lpm_shellcmd.c)
endif()

FOREACH(CUR_DIR ${LOCAL_DIRS_y})
    aux_source_directory(${CUR_DIR} LOCAL_SRCS_y)
ENDFOREACH(CUR_DIR)


# set(LOCAL_SRCS ${LOCAL_SRCS_y})  # module.cmake will sort LOCAL_SRCS files
include(${MODULE})

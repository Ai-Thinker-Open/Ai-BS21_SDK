/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Usb Thread Ref File
 * Author: Huawei LiteOS Team
 * Create: 2013-01-01
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

#ifndef _THREAD_REF_H
#define	_THREAD_REF_H

#include <unistd.h>
#ifdef CONFIG_DRIVERS_USB_HOST_DRIVER
#include <los_task.h>
#endif
#include "kal_spinlock.h"
#include "kal_base.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Ref. usb_process.c */
struct thread {
	void *v;
};

struct module {
};

#define	thread_lock(td)		LOS_TaskLock()
#define	thread_unlock(td)	LOS_TaskUnlock()
#define	curthread			LOS_CurTaskIDGet()

#define	USB_THREAD_SUSPEND_CHECK()	/* kthread_suspend_check(curproc) */
#define	USB_THREAD_SUSPEND(p)	/* LOS_TaskSuspend(p,0) */
#define	USB_THREAD_EXIT(err)	/* pthread_exit(PTHREAD_CANCELED) */
#define	sched_prio(td, prio)

#define	FAR
#define	CODE

#ifndef container_of
#define	container_of	KAL_CONTAINER_OF
#endif

#ifndef min
#define	min(x, y)	((x) < (y) ? (x) : (y))
#endif

#ifndef min_t
#define	min_t(t, x, y)	((t)(x) < (t)(y) ? (t)(x) : (t)(y))
#endif

/* spinlock api */
#define	spinlock_t		SPIN_LOCK_S

#if (CONFIG_KERNEL_SMP == YES)
#define	spin_lock_init(lock)	LOS_SpinInit(lock)
#define	spin_lock(lock)		LOS_SpinLock(lock)
#define	spin_unlock(lock)	LOS_SpinUnlock(lock)

#define	spin_lock_irqsave(lock, flags)		LOS_SpinLockSave(lock, (UINT32 *)&flags)
#define	spin_unlock_irqrestore(lock, flags)	LOS_SpinUnlockRestore(lock, (UINT32)flags)
#else /* (CONFIG_KERNEL_SMP != YES) */

#define	spin_lock_init(lock)	do {} while (0)

#define	spin_lock(lock)		LOS_TaskLock()
#define	spin_unlock(lock)	LOS_TaskUnlock()

#define	spin_lock_irqsave(lock, flags)	do {	\
		flags = LOS_IntLock();		\
		spin_lock(lock);		\
	} while (0)

#define	spin_unlock_irqrestore(lock, flags)	do {	\
		spin_unlock(lock);			\
		LOS_IntRestore(flags);			\
	} while (0)
#endif /* CONFIG_KERNEL_SMP */

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _THREAD_REF_H */

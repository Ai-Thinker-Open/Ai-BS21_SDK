include $(LITEOSTOPDIR)/config.mk

MODULE_NAME := cmsis_user

LOCAL_SRCS :=  $(wildcard *.c)

LOCAL_INCLUDE :=

LOCAL_FLAGS := $(LOCAL_INCLUDE) $(LITEOS_GCOV_OPTS) $(LITEOS_NON_SECURE_LOCAL_OPTS)

ifeq ($(LOSCFG_BOX), y)
	include $(UMODULE)
else
	include $(MODULE)
endif

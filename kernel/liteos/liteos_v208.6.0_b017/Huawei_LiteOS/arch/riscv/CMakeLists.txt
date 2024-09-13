set(LOSCFG_ARCH_CPU riscv)

# extra definition for other module
set(LITEOS_CPU_TYPE ${LOSCFG_ARCH_CPU} CACHE STRING "CPU_TYPE" FORCE)

set(MODULE_NAME ${LOSCFG_ARCH_CPU})
set(LITEOS_INT_AHEAD_LIBS ${LOSCFG_ARCH_CPU} targets init CACHE STRING "LiteOS libs place ahead")

# add global include, compile macro and options to public target #
set(MODULE_INCLUDE_PUB)
set(MODULE_CXXINCLUDE_PUB)
set(MODULE_CXXOPTS_PUB)
set(MODULE_CXXMACRO_PUB)

if (LOSCFG_COMPILER_CLANG)
    set(LITEOS_CPU_OPTS --target=riscv32)
    set(ARCH_COPTS)
    set(ARCH_CXXOPTS)
endif()

if (LOSCFG_COMPILER_RISCV_CLANG_UNKNOWN)
    set(ARCH_COPTS -mllvm -disable-loop-ivopt=true)
endif()

set(LCMP_MARCH_EXTENSIONS_y)
set(LITEOS_MARCH_OPTS)
set(RISCV_MARCH_y "-march=")
set(RISCV_ABI_y)

if (LOSCFG_COMPILER_GCC)
    set(LITEOS_CPU_OPTS -msmall-data-limit=0)
    set(ARCH_COPTS   -falign-functions=2 -fno-optimize-strlen -freorder-blocks-algorithm=simple -fno-schedule-insns)
    set(ARCH_CXXOPTS -falign-functions=2 -fno-optimize-strlen -freorder-blocks-algorithm=simple -fno-schedule-insns)
endif()

# march string setting
string(APPEND RISCV_MARCH_${LOSCFG_ARCH_RISCV_RV32IMC} "rv32im")
string(APPEND RISCV_MARCH_${LOSCFG_ARCH_FPU_ENABLE} "f")
string(APPEND RISCV_MARCH_${LOSCFG_ARCH_FPU_DOUBLE} "d")
string(APPEND RISCV_MARCH_${LOSCFG_ARCH_RISCV_RV32IMC} "c")

if (LOSCFG_COMPILER_CLANG AND ${VERSION_NUM} VERSION_GREATER_EQUAL "15.0.0")
    string(APPEND RISCV_MARCH_${LOSCFG_ARCH_RISCV_ISA_B} "b0p92")
else()
    string(APPEND RISCV_MARCH_${LOSCFG_ARCH_RISCV_ISA_B} "b")
endif()

string(APPEND RISCV_MARCH_${LOSCFG_ARCH_VECTOR_ENABLE} "v")

list(APPEND LCMP_MARCH_EXTENSIONS_${LOSCFG_LCMP_CUSTOM_INST16_EXTENSIONS} xlinxma)
list(APPEND LCMP_MARCH_EXTENSIONS_${LOSCFG_LCMP_CUSTOM_INST16_SUB_EXTENSIONS} xlinxmb)
list(APPEND LCMP_MARCH_EXTENSIONS_${LOSCFG_LCMP_CUSTOM_INST32_EXTENSIONS} xlinxmc)
list(APPEND LCMP_MARCH_EXTENSIONS_${LOSCFG_ARCH_RISCV_TES} xlinxme)
list(JOIN LCMP_MARCH_EXTENSIONS_y "_" LCMP_MARCH_EXTENSIONS_y)

if (LOSCFG_COMPILER_RISCV_CLANG_MUSL AND LOSCFG_ARCH_LINXCORE_131)
    string(CONCAT LITEOS_MARCH_OPTS ${RISCV_MARCH_y} "_xhimideer")
else()
    string(CONCAT LITEOS_MARCH_OPTS ${RISCV_MARCH_y} ${LCMP_MARCH_EXTENSIONS_y})
endif()

list(APPEND LITEOS_CPU_OPTS ${LITEOS_MARCH_OPTS})

# ISA string setting
string(APPEND RISCV_ABI_${LOSCFG_ARCH_RISCV_RV32IMC} "-mabi=ilp32")

string(APPEND RISCV_ABI_${LOSCFG_ARCH_FPU_ENABLE} "f")

if (LOSCFG_ARCH_FPU_DOUBLE)
string(REPLACE "f" "d" RISCV_ABI_${LOSCFG_ARCH_FPU_DOUBLE} ${RISCV_ABI_${LOSCFG_ARCH_FPU_DOUBLE}})
endif()

list(APPEND ARCH_COPTS ${RISCV_ABI_y})
list(APPEND ARCH_CXXOPTS ${RISCV_ABI_y})

if (LOSCFG_RISCV_COMPILER_OPTIONS_EMIT_LLI)
    list(APPEND LITEOS_CPU_OPTS -femit-lli)
endif()

set(ARCH_ASOPTS -x assembler-with-cpp)

if (LOSCFG_RISCV_COMPILER_OPTIONS_LDM_STM)
    list(APPEND ARCH_COPTS -fldm-stm-optimize)
    list(APPEND ARCH_CXXOPTS -fldm-stm-optimize)
endif()

if (LOSCFG_COMPILER_RISCV_GCC_UNKNOWN)
    #remove "" maybe in LOSCFG_RISCV_COMPILER_OPTIONS_USER_DEFINED
    string(REGEX REPLACE \" "" LOSCFG_RISCV_COMPILER_OPTIONS_USER_DEFINED "${LOSCFG_RISCV_COMPILER_OPTIONS_USER_DEFINED}")
    list(APPEND ARCH_COPTS ${LOSCFG_RISCV_COMPILER_OPTIONS_USER_DEFINED})
    list(APPEND ARCH_COPTS -mtune=size -fno-short-enums)
    if (LOSCFG_RISCV_COMPILER_OPTIONS_PUSH_POP)
        list(APPEND ARCH_COPTS -mpush-pop)      # failed to work when backtrace enabled
    endif()
    if (LOSCFG_RISCV_COMPILER_OPTIONS_SAVE_RESTORE)
        list(APPEND ARCH_COPTS -msave-restore)  # failed to work when backtrace enabled
    endif()
    if (LOSCFG_RISCV_COMPILER_OPTIONS_NO_INLINE)
        # these options are used to easily patch for ROM codes
        list(APPEND ARCH_COPTS -fno-inline-small-functions -fno-inline-functions-called-once)
    endif()
    if (LOSCFG_RISCV_COMPILER_OPTIONS_LBU_SB)
        list(APPEND ARCH_COPTS -Wa,-enable-c-lbu-sb)
    endif()
    if (LOSCFG_RISCV_COMPILER_OPTIONS_LDM_STM)
        set(ARCH_CMACRO LOS_COMPILE_LDM)
        set(ARCH_ASMACRO LOS_COMPILE_LDM)
    endif()
endif()

set(MODULE_COPTS_PUB   ${LITEOS_CPU_OPTS} ${ARCH_COPTS})
set(MODULE_ASOPTS_PUB  ${LITEOS_CPU_OPTS} ${ARCH_ASOPTS})
set(MODULE_CXXOPTS_PUB ${ARCH_CXXOPTS})
set(MODULE_CMACRO_PUB  ${ARCH_CMACRO})
set(MODULE_ASMACRO_PUB ${ARCH_ASMACRO})
set(MODULE_CXXMACRO_PUB)

set(GSYM_CFLAG ${GSYM_CFLAG}${MODULE_COPTS_PUB} CACHE INTERNAL "CSYM Add Arch Option" FORCE)

# add local include, compile macro and options to private target #
set(MODULE_INCLUDE_PRI
    ${LITEOSTOPDIR}/kernel/extended/include
    ${LITEOSTOPDIR}/kernel/extended/dynload/include
    ${LITEOSTOPDIR}/kernel/extended/perf
)

set(MODULE_CXXINCLUDE_PRI ${MODULE_INCLUDE_PRI})

set(MODULE_COPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_ASOPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_CXXOPTS_PRI ${LITEOS_NON_SECURE_LOCAL_OPTS})
set(MODULE_CMACRO_PRI)
set(MODULE_ASMACRO_PRI)
set(MODULE_CXXMACRO_PRI)

# add srcs to private target #
# set(LOCAL_SRCS_y src/cache.c src/canary.c src/fault.c src/task.c src/stack.S)
list(APPEND LOCAL_SRCS_${LOSCFG_APC_ENABLE} src/pmp.c)
list(APPEND LOCAL_SRCS_${LOSCFG_PERF_HW_PMU} src/pmu.c)
list(APPEND LOCAL_SRCS_${LOSCFG_KERNEL_DYNLOAD} src/dynload.c)
list(APPEND LOCAL_SRCS_${LOSCFG_LASLR} src/aslr/aslr.c src/aslr/symbol.S src/aslr/aslr_vector.S)
list(APPEND LOCAL_SRCS_${LOSCFG_FPB_ENABLE} src/fpb.c)

if (LOSCFG_RISCV_COMPILER_OPTIONS_LCMP_GEN)
    list(APPEND LOCAL_SRCS_y src/intrinsics/reset.c src/intrinsics/dispatch.c src/intrinsics/trap.c)
else()
    list(APPEND LOCAL_SRCS_y src/reset_vector.S src/dispatch.S src/exception.S src/trap.S)
endif()

if (NOT LOSCFG_ARCH_INTERRUPT_TAKEOVER)
    list(REMOVE_ITEM LOCAL_SRCS_y src/exception.S src/fault.c)
endif()

if (LOSCFG_USING_BOARD_RESET_VECTOR)
list(REMOVE_ITEM LOCAL_SRCS_y src/reset_vector.S src/stack.S)
endif()

# aslr should avoid generating jump tables for switch statements even it would be more efficient.
if (LOSCFG_LASLR)
list(APPEND MODULE_COPTS_PRI -fno-jump-tables)
endif()

if (LOSCFG_KERNEL_DEEPSLEEP)
    list(APPEND LOCAL_SRCS_y src/runstop.S)
endif()

# add customized architecture directory here.
if (LOSCFG_ARCH_LINXCORE_131)
    set(LITEOS_ARCH_RISCV linx131)
endif()

if (LITEOS_ARCH_RISCV)
    include(src/${LITEOS_ARCH_RISCV}/custom.cmake)
endif()

# set(LOCAL_SRCS ${LOCAL_SRCS_y})  # module.cmake will sort LOCAL_SRCS files
include(${MODULE})

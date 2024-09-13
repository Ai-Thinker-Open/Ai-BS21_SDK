include(libc_src.cmake)

set(MODULE_NAME c)


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
    ${LITEOS_LIBC_PATH}/src/include
    ${LITEOS_LIBC_PATH}/src/internal
    ${LITEOS_LIBC_PATH}/src/crypt
    ${LITEOS_LIBC_PATH}/src/ctype
    ${LITEOS_LIBC_PATH}/src/dirent
    ${LITEOS_LIBC_PATH}/src/errno
    ${LITEOS_LIBC_PATH}/src/ipc
    ${LITEOS_LIBC_PATH}/src/locale
    ${LITEOS_LIBC_PATH}/src/math
    ${LITEOS_LIBC_PATH}/src/multibyte
    ${LITEOS_LIBC_PATH}/src/networknetwork
    ${LITEOS_LIBC_PATH}/src/passwd
    ${LITEOS_LIBC_PATH}/src/prng
    ${LITEOS_LIBC_PATH}/src/process
    ${LITEOS_LIBC_PATH}/src/regex
    ${LITEOS_LIBC_PATH}/src/search
    ${LITEOS_LIBC_PATH}/src/time
    ${LITEOSTOPDIR}/lib/liteos_libc/pthread
    ${LITEOSTOPDIR}/lib/liteos_libc/tzdst
    ${LITEOSTOPDIR}/lib/liteos_libc/lock
    ${LITEOSTOPDIR}/lib/liteos_libc/locale
    ${LITEOSTOPDIR}/lib/liteos_libc/init
)
if(LOSCFG_LLTSER)
    list(APPEND MODULE_INCLUDE_PRI ${LITEOSTOPDIR}/internal/tools/gcov_ser)
endif()

if(LOSCFG_HW_RANDOM_ENABLE)
    list(APPEND MODULE_INCLUDE_PRI ${LITEOSTOPDIR}/drivers/random/include)
endif()

set(MODULE_COPTS_PRI)
set(MODULE_ASOPTS_PRI)
set(MODULE_CXXOPTS_PRI)
set(MODULE_CMACRO_PRI)
set(MODULE_ASMACRO_PRI)
set(MODULE_CXXMACRO_PRI)


# add srcs to private target #
set(LOCAL_SRCS_y)
set(LOCAL_DIRS_y)

# libc module
set(LOCAL_SRCS_LIBC ${LIBC_STRING_SRC} ${LIBC_TIME_SRC})
if (NOT LOSCFG_SAFETY_KERNEL)
list(APPEND LOCAL_SRCS_LIBC
    ${LIBC_ERRNO_SRC} ${LIBC_STDLIB_SRC}
    ${LIBC_INTERNAL_SRC} ${LIBC_MISC_SRC}
    ${LIBC_LOCALE_SRC} ${LIBC_CTYPE_SRC} ${LIBC_TEMP_SRC}
    ${LIBC_FCNTL_SRC} ${LIBC_SIGNAL_SRC} ${LIBC_NETWORK_SRC}
    ${LIBC_UNISTD_SRC} ${LIBC_COMPLEX_SRC} ${LIBC_MULTIBYTE_SRC}
    ${LIBC_EXIT_SRC} ${LIBC_LEGACY_SRC}
)
endif()
if(NOT LOSCFG_ARCH_FPU_ENABLE AND LOSCFG_ARCH_ARM_AARCH64)
    list(REMOVE_ITEM LOCAL_SRCS_LIBC
        ${LIBC_DIR_PATH}/src/complex/cabs.c
        ${LIBC_DIR_PATH}/src/internal/floatscan.c
        ${LIBC_DIR_PATH}/src/stdlib/atof.c
        ${LIBC_DIR_PATH}/src/stdlib/strtod.c
        ${LIBC_DIR_PATH}/src/time/difftime.c
        ${LIBC_DIR_PATH}/src/locale/strtod_l.c
    )
endif()

# liteos_libc module
set(LOCAL_DIRS_LITEOS_LIBC string exit)
if (LOSCFG_SAFETY_KERNEL)
list(APPEND LOCAL_DIRS_LITEOS_LIBC errno)
else()
list(APPEND LOCAL_DIRS_LITEOS_LIBC errno stdlib signal tzdst lock locale init)
endif()
list(TRANSFORM LOCAL_DIRS_LITEOS_LIBC PREPEND ../liteos_libc/)

list(APPEND LOCAL_DIRS_y ${LOCAL_DIRS_LITEOS_LIBC})
list(APPEND LOCAL_SRCS_y ${LOCAL_SRCS_LIBC})

# standard io base
list(APPEND LOCAL_SRCS_y ${LIBC_STDIO_BASE})
# standard io file api
list(APPEND LOCAL_SRCS_${LOSCFG_LIB_STDIO} ${LIBC_STDIO_SRC})
# standard format api
list(APPEND LOCAL_SRCS_${LOSCFG_LIB_FORMAT} ${LIBC_FORMAT_SRC})

FOREACH(CUR_DIR ${LOCAL_DIRS_y})
    aux_source_directory(${CUR_DIR} LOCAL_SRCS_y)
ENDFOREACH(CUR_DIR)

list(APPEND LOCAL_SRCS_y
    ../liteos_libc/time/time.c
    ../liteos_libc/time/time64.c
    ../liteos_libc/misc/getentropy.c
    ../liteos_libc/time/localtime_r.c
    ../liteos_libc/time/mktime.c
    ../liteos_libc/time/clock_gettime.c
)

if(NOT LOSCFG_COMPAT_POSIX)
    list(APPEND LOCAL_SRCS_y ${LIBC_DIR_PATH}/src/prng/rand.c)
endif()

if((NOT LOSCFG_ARCH_ARM_CORTEX_M) AND (NOT LOSCFG_ARCH_ARM_AARCH64))
    file(GLOB LOCAL_ASMSRCS_LIST_TEMP RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        "${LIBC_DIR_PATH}/src/string/${ARCH_LOCAL}/*.S"
    )
    if(LOCAL_ASMSRCS_LIST_TEMP)
        list(APPEND LOCAL_SRCS_y ${LOCAL_ASMSRCS_LIST_TEMP})
    endif()
endif()

set(LOCAL_SRCS_REMOVED)
if(LOSCFG_ARCH_ARM_V7A OR LOSCFG_ARCH_ARM_V7R OR LOSCFG_ARCH_CORTEX_R52)
    list(APPEND LOCAL_SRCS_REMOVED
        ${LIBC_DIR_PATH}/src/string/memcpy.c
        ${LIBC_DIR_PATH}/src/string/strcmp.c
        ${LIBC_DIR_PATH}/src/string/memcmp.c
    )
    if(LOSCFG_ARCH_FPU_VFP_NEON)
        list(APPEND LOCAL_SRCS_REMOVED ${LIBC_DIR_PATH}/src/string/memset.c)
    endif()
elseif(LOSCFG_ARCH_RISCV32)
    list(APPEND LOCAL_SRCS_REMOVED
        ${LIBC_DIR_PATH}/src/string/memcpy.c
        ${LIBC_DIR_PATH}/src/string/memset.c
        ${LIBC_DIR_PATH}/src/string/strcmp.c
    )
elseif(LOSCFG_ARCH_ARM_AARCH64)
    list(APPEND LOCAL_SRCS_REMOVED
        ${LIBC_DIR_PATH}/src/string/strcmp.c
    )
    if(LOSCFG_ARCH_FPU_ENABLE)
        list(APPEND LOCAL_SRCS_REMOVED
            ${LIBC_DIR_PATH}/src/string/memset.c  # floating pointer unit is not supported
            ${LIBC_DIR_PATH}/src/string/memcpy.c  # Alignment fault
            ${LIBC_DIR_PATH}/src/string/memcmp.c  # Alignment fault
        )
    endif()
endif()

if(LOSCFG_LIB_STDIO)
    list(APPEND LOCAL_SRCS_REMOVED ../liteos_libc/exit/assert.c)
endif()

if(LOCAL_SRCS_REMOVED)
    list(REMOVE_ITEM LOCAL_SRCS_y ${LOCAL_SRCS_REMOVED})
endif()

list(GET LOCAL_SRCS_y 0 SOURCES0)
get_filename_component(SOURCES0  "${SOURCES0}" ABSOLUTE)
if(EXISTS ${SOURCES0})
    set(LOCAL_SRCS ${LOCAL_SRCS_y})
else()
set(LOCAL_SRCS "")
endif()

list(APPEND MODULE_COPTS_PRI
     -Wunused
     -Wno-unused-value
     -Wno-parentheses
     -Wno-strict-prototypes
     -Wdate-time
)
if(LOSCFG_COMPILER_CLANG)
    list(APPEND MODULE_COPTS_PRI -Wno-uninitialized)
    if (${VERSION_NUM} VERSION_GREATER_EQUAL 13.0.0)
        list(APPEND MODULE_COPTS_PRI -Wno-unused-but-set-variable)
    endif()
else()
    list(APPEND MODULE_COPTS_PRI -Wno-maybe-uninitialized -Wno-unused-but-set-variable)
endif()

if(NOT LOSCFG_COMPILER_XTENSA_32)
    list(APPEND MODULE_COPTS_PRI -Wvla)
endif()

if(LOSCFG_LMS_LIBC_FULL_CHECK)
    list(APPEND MODULE_COPTS_PRI -fsanitize=kernel-address)
endif()

include(${MODULE_LIBC})

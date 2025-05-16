
PROJ_NAME  :=  test
PROJ_TC    :=  gae

CONFIG_LINK_PRINTF_FLOAT:=y
CONFIG_LINK_SCANF_FLOAT:=n
CONFIG_COMPILE_OPTIMIZE:=O1

TARGET_POSTBUILD := ${TARGET_DEST_FILENAME_BIN}

# board configuration
MOD_ARCH=m4
include ${PUSER_ROOTDIR}/boards/nucleo_wl55jc/make.mk

# os and library configuration
CONFIG_MK_CHIP_ARCH=${MOD_ARCH}
CONFIG_MK_COMPILER=gcc
CONFIG_MK_USE_FREERTOS=n
CONFIG_MK_USE_FRMEM_METHOD=4
CONFIG_MK_USE_FR_POSIX=n
CONFIG_MK_USE_FS_FATFS=n
CONFIG_MK_USE_LIB_CPP=n
CONFIG_MK_USE_UORB=n
CONFIG_MK_USE_HRT=n
CONFIG_MK_USE_CRUSB=n
CONFIG_MK_USE_CRUSB_CDC=n
CONFIG_MK_CRUSB_IP=none

include ${SDK_ROOTDIR}/sched/make.mk
include ${SDK_ROOTDIR}/mm/make.mk
include ${SDK_ROOTDIR}/libs/make.mk
include ${SDK_ROOTDIR}/include/make.mk
include ${SDK_ROOTDIR}/usb/make.mk
CSOURCES      += ${FR_CSOURCES}
CPPSOURCES    += ${FR_CPPSOURCES}
PROJ_CINCDIRS += ${FR_CINCDIRS}

#####################################
# app configuration
#####################################
PROJ_CDEFS += CONFIG_BOARD_COM_STDINOUT

PUSER_CPPSOURCES += app/app_main.cpp

BUILD_DIR_ROOT ?= ../../.build
TOOLS_DIR ?= ../../tools
ECHO ?= echo 
Q ?= @
TARGET_NAME:=stc8h8k64u
TARGET_PATH:=${BUILD_DIR_ROOT}/${TARGET_NAME}
PYTHON_EXE ?= python3

STC8H8K64U_RULES_MK ?= ../../lib/sdcc_rules.mk
COMMON_LIB_PATH ?= ../../lib/common

include .config
# include ../../lib/cc2530_hal/cc2530_hal.mk
include ../../lib/common/common.mk

# addprefix of the cc2530_hal library
# CSRCS:=$(addprefix ${CC2530_LIB_PATH}/,$(CSRCS))
CSRCS+=$(addprefix ${COMMON_LIB_PATH}/,$(COMMON_SRCS))

# HEADERS:=$(addprefix ${CC2530_LIB_PATH}/include/,$(HEADERS))
HEADERS+=$(addprefix ${COMMON_LIB_PATH}/include/,$(COMMON_HEADERS))

INCLUDE_PATH := -I${CC2530_LIB_PATH}/include \
				-I${TARGET_PATH} \
				-I${COMMON_LIB_PATH}/include \
				-Iinclude

# add local source file
CSRCS+=$(wildcard src/*.c)
HEADERS+=$(wildcard include/*.h)
HEADERS+=${TARGET_PATH}/config.h

.PHONY: all ${TARGET_NAME} clean upload list

# explicity set the default build target
all: ${TARGET_NAME}

# create the target directory
${TARGET_PATH}:
	${Q}${ECHO} "Creating target build directory ${TARGET_PATH}"
	${Q}mkdir -p ${TARGET_PATH}

# create the .config file using default the setting
.config:./Kconfig 
	${Q}echo "Creating .config file"
	${Q}${PYTHON_EXE} ${TOOLS_DIR}/kconfig.py -i $^ -o $@

# create the config.h file from the .config file
${TARGET_PATH}/config.h:.config ${TARGET_PATH}
	${Q}echo "Generate the ${TARGET_PATH}/config.h from .config"
	${Q}${PYTHON_EXE} ${TOOLS_DIR}/kconfig.py -i ./Kconfig -o .config -O ${TARGET_PATH}/config.h

${TARGET_NAME}: ${TARGET_PATH}/config.h
	${Q}echo "Building target ${TARGET_NAME}"
	${Q}${MAKE} -f ${STC8H8K64U_RULES_MK} \
		TARGET_NAME=$@ TARGET_DIR=${TARGET_PATH} \
		INCLUDE_PATH="${INCLUDE_PATH}" \
		C_SOURCES="${CSRCS}" \
		HEADER_FILES="${HEADERS}" \
		ASM_SOURCES= \
		CPU=STC8H8K64U

clean:
	${Q}echo "Cleaning target ${TARGET_NAME}"
	${Q}echo "delete ${TARGET_PATH}"&&rm -rf ${TARGET_PATH}

upload: ${TARGET_NAME}
	${Q}echo "Uploading target ${TARGET_NAME}"
	${Q}stcgal -P stc8d -o reset_pin_enabled=True -r false -t 48000 -p ${PORT}  ${BUILD_DIR_ROOT}/${TARGET_NAME}/${TARGET_NAME}.hex 

list: 
	${Q}echo "Available targets:"
	${Q}echo "\t ${TARGET_NAME}\n\t clean \n\t upload \n\t list"


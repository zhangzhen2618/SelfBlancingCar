
BUILD_DIR_ROOT ?= ../../.build
TOOLS_DIR ?= ../../tools
ECHO ?= echo 
Q ?= @
TARGET_NAME:=cc2530_remote
TARGET_PATH:=${BUILD_DIR_ROOT}/${TARGET_NAME}
PYTHON_EXE ?= python3

CC2530_LIB_PATH ?= ../../lib/cc2530_hal
CC2530_RULES_MK ?= ../../lib/sdcc_rules.mk

include .config
include ../../lib/cc2530_hal/cc2530_hal.mk

# addprefix of the cc2530_hal library
CSRCS:=$(addprefix ${CC2530_LIB_PATH}/,$(CSRCS))
HEADERS:=$(addprefix ${CC2530_LIB_PATH}/include/,$(HEADERS))
INCLUDE_PATH := -I${CC2530_LIB_PATH}/include \
				-I${TARGET_PATH} \
				-I.include

# add local source file
CSRCS+=$(wildcard src/*.c)
HEADERS+=$(wildcard include/*.h)
HEADERS+=${TARGET_PATH}/config.h

.PHONY: all ${TARGET_NAME} clean upload list config

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
	${Q}${MAKE} -f ${CC2530_RULES_MK} \
		TARGET_NAME=$@ TARGET_DIR=${TARGET_PATH} \
		INCLUDE_PATH="${INCLUDE_PATH}" \
		C_SOURCES="${CSRCS}" \
		HEADER_FILES="${HEADERS}" \
		ASM_SOURCES= \
		CPU=CC2530F256

clean:
	${Q}echo "Cleaning target ${TARGET_NAME}"
	${Q}echo "delete ${TARGET_PATH}"&&rm -rf ${TARGET_PATH}

upload: ${TARGET_NAME}
	${Q}echo "Uploading target ${TARGET_NAME}"

list: 
	${Q}echo "Available targets:"
	${Q}echo "\t ${TARGET_NAME}\n\t clean \n\t upload \n\t list \n\tconfig"
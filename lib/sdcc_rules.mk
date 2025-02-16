# ifeq ($(CPU),STC8H8K64U)
# 	hello="hello sldjl"
# endif
MCU := --out-fmt-ihx --code-loc 0x0000 \
	--xram-size 0x2000 --iram-size 0x200  --model-large \
		--code-size 65536  --stack-auto\
		--opt-code-speed -DFLASH_SIZE=65536 -DFLASH_PAGESIZE=0x200
CC := sdcc
ASM := sdas8051

ECHO ?= echo
Q ?= @

# list of header file
# HEADER_FILES := $(foreach ipath, ${INCLUDE_PATH}, $(shell ls $(patsubst -I%, %, ${ipath})/*.h))
INCLUDE_PATH_ := ${INCLUDE_PATH} -I/usr/share/sdcc/include/

FLAGS := ${MCU} ${INCLUDE_PATH_}
ROM_SIZE ?= 65536

# TARGET_DIR := ${BUILD_DIR_ROOT}/${TARGET_NAME}

IHX := ${TARGET_DIR}/${TARGET_NAME}.ihx
HEX := ${TARGET_DIR}/${TARGET_NAME}.hex
BINARY := ${TARGET_DIR}/${TARGET_NAME}.bin

# list of objects
OBJECTS = ${addprefix ${TARGET_DIR}/, $(notdir $(C_SOURCES:.c=.rel))}
vpath %.c $(sort $(dir ${C_SOURCES}))
# list of ASM objects
OBJECTS += ${addprefix ${TARGET_DIR}/, $(notdir $(ASM_SOURCES:.s=.rel))}
vpath %.s $(sort $(dir ${ASM_SOURCES}))

.PHONY :check_files show_message
all: show_message ${IHX} ${HEX} ${BINARY} 
	${Q}${ECHO} "\n\n***********************  Memory cost **************************"
	${Q}${ECHO} "\nMemory: " & tail -n 5 ${TARGET_DIR}/*.mem
	${Q}${ECHO} "\n\n***********************  Memory cost *************************\n\n"

show_message: check_files
	${Q}${ECHO} "*****************build Target : ${TARGET_NAME} ***********************\n"
	${Q}date
	${Q}${ECHO} "Build dir : 	${TARGET_DIR}"
	${Q}${ECHO} "Target : 		${TARGET_NAME}"
	${Q}${ECHO} "MCU : 			${MCU}"
	${Q}${ECHO} "CPU: 			${CPU}"
	${Q}${ECHO} "source files : \n $(addprefix "\\n\\t",${C_SOURCES})"
	${Q}${ECHO} "header files : \n $(addprefix "\\n\\t",${HEADER_FILES})"
	${Q}${ECHO} "asm files : \n $(addprefix "\\n\\t",${ASM_SOURCES})"
	${Q}${ECHO} "\n*****************build Target : ${TARGET_NAME} ***********************\n"

check_files:
	${Q}error_num=0; \
	for file in ${C_SOURCES} ${ASM_SOURCES} ${HEADER_FILES}; do \
		if [ ! -f $$file ]; then \
            error_num=$$((error_num+1)); \
			echo "Warning: File $$file does not exist."; \
		fi \
	done; \
	exit $$error_num

${TARGET_DIR}/%.rel: %.c ${HEADER_FILES}
	${Q}${ECHO} Generating object : $@
	${Q}${CC} -c ${FLAGS} -o $@ $<

${TARGET_DIR}:
	${Q}mkdir -p ${TARGET_DIR}

# generate the ihx file
${IHX}: ${MAKEFILE_LIST} ${OBJECTS}
	${Q}${ECHO} "${VPATH}"
	${Q}${CC} -o $@ ${OBJECTS} ${FLAGS}

# convent ihx to hex
${HEX}: ${IHX}
	${Q}packihx $< > $@

# use hex generate bin file
${BINARY}: ${HEX}
	${Q}makebin -s ${ROM_SIZE} $< $@

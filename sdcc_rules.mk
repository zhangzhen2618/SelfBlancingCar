# ifeq ($(CPU),STC8H8K64U)
# 	hello="hello sldjl"
# endif
MCU := --out-fmt-ihx --code-loc 0x0000 \
	--xram-size 0x2000 --iram-size 0x200  --model-large \
		--code-size 65536  --stack-auto\
		--opt-code-speed -DFLASH_SIZE=65536 -DFLASH_PAGESIZE=0x200
CC := sdcc
ASM := sdas8051

# list of header file
HEADER_FILES := $(foreach ipath, ${INCLUDE_PATH}, $(shell ls $(patsubst -I%, %, ${ipath})/*.h))
INCLUDE_PATH_ := ${INCLUDE_PATH} -I/usr/share/sdcc/include/

FLAGS := ${MCU} ${INCLUDE_PATH_}
ROM_SIZE ?= 65536

TARGET_DIR := ${BUILD_DIR_ROOT}/${TARGET_NAME}

IHX := ${TARGET_DIR}/${TARGET_NAME}.ihx
HEX := ${TARGET_DIR}/${TARGET_NAME}.hex
BINARY := ${TARGET_DIR}/${TARGET_NAME}.bin

# list of objects
OBJECTS = ${addprefix ${TARGET_DIR}/, $(notdir $(C_SOURCES:.c=.rel))}
vpath %.c $(sort $(dir ${C_SOURCES}))
# list of ASM objects
OBJECTS += ${addprefix ${TARGET_DIR}/, $(notdir $(ASM_SOURCES:.s=.rel))}
vpath %.s $(sort $(dir ${ASM_SOURCES}))

.PHONY :
all: show_message ${TARGET_DIR} ${IHX} ${HEX} ${BINARY}
	@echo "\n\n***********************  Memory cost **************************"
	@echo "\nMemory: " & tail -n 5 ${TARGET_DIR}/*.mem
	@echo "\n\n***********************  Memory cost *************************\n\n"

.PHONY : show_message

show_message:
	@echo "*****************build Target : ${TARGET_NAME} ***********************\n"
	@date
	@echo "Target : ${TARGET_NAME}"
	@echo "CPU: ${CPU}"
	@echo "sources file : \n $(addprefix "\\n\\t",${C_SOURCES})"
	@echo "\n*****************build Target : ${TARGET_NAME} ***********************\n"

${TARGET_DIR}/%.rel: %.c ${HEADER_FILES}
	@echo Generating object : $@ 
	@${CC} -c ${FLAGS} -o $@ $<

${TARGET_DIR}:
	@mkdir -p ${TARGET_DIR}

# generate the ihx file
${IHX}: ${MAKEFILE_LIST} ${OBJECTS}
	@${CC} -o $@ ${OBJECTS} ${FLAGS}

# convent ihx to hex
${HEX}: ${IHX}
	@packihx $< > $@

# use hex generate bin file
${BINARY}: ${HEX}
	@makebin -s ${ROM_SIZE} $< $@

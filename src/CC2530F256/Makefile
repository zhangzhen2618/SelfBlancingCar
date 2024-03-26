
CC2530F256_SRC=buzzer.c \
				cc2530_LCD.c \
				rf.c \
				sys_config.c \
				dma.c \
				main.c

CC2530F256_PC_SRC=rf.c \
				sys_config.c \
				uart.c \
				dma.c \
				main_pc.c

CC2530F256: 
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH=-I./src/CC2530F256/include \
		C_SOURCES="$(addprefix ./src/CC2530F256/src/,${CC2530F256_SRC})"\
		ASM_SOURCES= \
		CPU=CC2530F256

clean_CC2530F256: 
	@${ECHO} "clean target CC2530F256"
	@rm -rf ${BUILD_DIR_ROOT}/CC2530F256

upload_CC2530F256: CC2530F256
	@${ECHO} "Uploading target : ${BUILD_DIR_ROOT}/CC2530F256/CC2530F256.hex"
	@sudo cc-tool -f -e -v -w ${BUILD_DIR_ROOT}/CC2530F256/CC2530F256.hex


CC2530F256_PC: 
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH=-I./src/CC2530F256/include \
		C_SOURCES="$(addprefix ./src/CC2530F256/src/,${CC2530F256_PC_SRC})"\
		ASM_SOURCES= \
		CPU=CC2530F256

clean_CC2530F256_PC: 
	@${ECHO} "clean target CC2530F256_PC"
	@rm -rf ${BUILD_DIR_ROOT}/CC2530F256_PC

upload_CC2530F256_PC: CC2530F256_PC
	@${ECHO} "Uploading target : ${BUILD_DIR_ROOT}/CC2530F256_PC/CC2530F256_PC.hex"
	@sudo cc-tool -f -e -v -w ${BUILD_DIR_ROOT}/CC2530F256_PC/CC2530F256_PC.hex
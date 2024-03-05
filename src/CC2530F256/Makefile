CC2530F256: 
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH=-I./src/CC2530F256/include \
		C_SOURCES="$(shell ls ./src/CC2530F256/src/*.c)"\
		ASM_SOURCES= \
		CPU=CC2530F256

clean_CC2530F256: 
	@${ECHO} "clean target CC2530F256"
	@rm -rf ${BUILD_DIR_ROOT}/CC2530F256

upload_CC2530F256: CC2530F256
	@${ECHO} "Uploading target : ${BUILD_DIR_ROOT}/CC2530F256/CC2530F256.hex"
	@sudo cc-tool -f -e -v -w ${BUILD_DIR_ROOT}/CC2530F256/CC2530F256.hex
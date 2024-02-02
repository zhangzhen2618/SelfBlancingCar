CC2530F256_comunication: 
	@echo "build target : $@"
	
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH=-I./src/CC2530F256/include \
		C_SOURCES="$(shell ls ./src/CC2530F256/src/*.c)"\
		ASM_SOURCES= \
		CPU=CC2530F256

	@echo "\n\n***********************  Memory cost **************************"
	@echo "\nMemory: " & tail -n 5 ${BUILD_DIR_ROOT}/$@/*.mem
	@echo "\n\n***********************  Memory cost *************************\n\n"

clean_CC2530F256_comunication: 
	@echo "clean target CC2530F256_comunication"
	@rm -rf ${BUILD_DIR_ROOT}/CC2530F256_comunication

upload_CC2530F256_comunication: CC2530F256_comunication
	@echo "Uploading target : ${BUILD_DIR_ROOT}/CC2530F256_comunication/CC2530F256_comunication.hex"
	@sudo cc-tool -f -e -v -w ${BUILD_DIR_ROOT}/CC2530F256_comunication/CC2530F256_comunication.hex
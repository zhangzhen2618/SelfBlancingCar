PROJECT_NAME=STC8H8K64U_controller

# # C sources file to complie
# sC_SRCS?=
# # asm sources file to complie
# sASM_SRCS=

STC8H8K64U_controller: 
	@echo "build target : $@"
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH=-I./src/STC8H8K64U/include \
		C_SOURCES=$(shell ls ./src/STC8H8K64U/src/*.c)\
		ASM_SOURCES= \
		CPU=STC8H8K64U

	@echo "\n\n***********************  Memory cost **************************"
	@echo "\nMemory: " & tail -n 5 ${BUILD_DIR_ROOT}/$@/*.mem
	@echo "\n\n***********************  Memory cost *************************\n\n"

clean_STC8H8K64U_controller:
	@echo "clean target STC8H8K64U_controller"
	@rm -rf ${BUILD_DIR_ROOT}/STC8H8K64U_controller

upload_STC8H8K64U_controller: STC8H8K64U_controller
	@echo "Uploading target : ${BUILD_DIR_ROOT}/STC8H8K64U_controller/STC8H8K64U_controller.hex"
	@stcgal -P stc8d -t 48000 -p ${PORT}  ${BUILD_DIR_ROOT}/STC8H8K64U_controller/STC8H8K64U_controller.hex
PROJECT_NAME=STC8H8K64U

# # C sources file to complie
# sC_SRCS?=
# # asm sources file to complie
# sASM_SRCS=

STC8H8K64U_COMM_SRC=crc.c

STC8H8K64U: 
	@${MAKE} -f sdcc_rules.mk TARGET_NAME=$@ \
		INCLUDE_PATH="-I./src/STC8H8K64U/include -I./src/COMMON/include" \
		C_SOURCES="$(shell ls ./src/STC8H8K64U/src/*.c)\
					 $(addprefix ./src/COMMON/src/,${STC8H8K64U_COMM_SRC})"\
		ASM_SOURCES= \
		CPU=STC8H8K64U

clean_STC8H8K64U:
	@${ECHO} "clean target STC8H8K64U"
	@rm -rf ${BUILD_DIR_ROOT}/STC8H8K64U

upload_STC8H8K64U: STC8H8K64U
	@${ECHO} "Uploading target : ${BUILD_DIR_ROOT}/STC8H8K64U/STC8H8K64U.hex"
	@stcgal -P stc8d -o reset_pin_enabled=True -r false -t 48000 -p ${PORT}  ${BUILD_DIR_ROOT}/STC8H8K64U/STC8H8K64U.hex 
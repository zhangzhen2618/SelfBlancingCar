export BUILD_DIR_ROOT ?= .build
export ECHO ?= echo 
# upload the serial port
export PORT ?= /dev/ttyUSB0

include src/CC2530F256/Makefile
include src/STC8H8K64U/Makefile

clean_all:
	@rm -rf ${BUILD_DIR_ROOT}
export BUILD_DIR_ROOT ?= .build
# upload the serial port
export PORT ?= /dev/ttyUSB0

sub_makefile := $(addsuffix Makefile, $(shell ls -d src/*/))

include ${sub_makefile}

clean_all:
	@rm -rf ${BUILD_DIR_ROOT}
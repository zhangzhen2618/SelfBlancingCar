export BUILD_DIR_ROOT ?= ${PWD}/.build
export TOOLS_DIR ?= ${PWD}/tools
export ECHO ?= echo 
# upload the serial port
export PORT ?= /dev/ttyUSB0

export Q ?= @

# explicity set default build target
all: list

# define a space character to be able to explicitly find it in strings
space := $(subst ,, )

define make_list
     $(shell ls ./targets/*/Makefile | xargs -n 1 dirname | xargs -n 1 basename)
endef

# Parsing
# --------------------------------------------------------------------
# assume 1st argument passed is the main target, the
# rest are arguments to pass to the makefile generated
# by Makefile in the subdirectory

SUB_TARGET := $(word 2,$(MAKECMDGOALS))
ARGS := $(wordlist 3,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))

# 防止参数被解释为目标
# .SECONDEXPANSION:
# .SECONDARY:
define parse_args
$(eval $(1):;@:)
endef

$(eval $(call parse_args,${SUB_TARGET}))
$(foreach param,$(ARGS),$(eval $(call parse_args,$(param))))

TARGETS := $(call make_list)

.PHONY: all list_targets $(TARGETS)

# list all targets
list_targets: 
	${Q}echo "Eevey target will be accessed by the following command:"
	${Q}echo "make <target> <sub_target> <args>"
	${Q}echo "For example: make cc2530_local clean, This will clean the cc2530_local target"
	${Q}echo "When the sub_target is not specified or is all, the default target is to complie and  generate the target"
	${Q}echo "Default every target has the following sub_target: all, clean, upload and list"
	${Q}echo "Different targets may have different sub_targets"
	${Q}echo "You can use make <target> list to see the available sub_targets"
	${Q}echo "Available targets:"
	@echo "$(addprefix \n\t,$(TARGETS))"

$(TARGETS): 
	${Q}cd ./targets/$@ && $(MAKE) $(SUB_TARGET) $(ARGS)

	
ifeq ($(CONFIG_COMMON_CRC_ENABLE),y)
COMMON_HEADERS += crc.h
COMMON_SRCS += src/crc.c
endif
ifeq ($(CONFIG_COMMON_PROTO_ENABLE),y)
COMMON_HEADERS += protocol.h
# COMMON_SRCS += src/crc.c
endif
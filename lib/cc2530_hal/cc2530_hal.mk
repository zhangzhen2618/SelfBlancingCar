ifeq ($(CONFIG_USE_CC2530_HAL),y)
HEADERS += hal_defs.h \
		hal_clock.h \
		hal_mcu.h \
		hal_bitdef.h \

CSRCS += src/hal_clock.c\
		src/hal_mcu.c
endif

ifeq ($(CONFIG_UART_ENABLE),y)
HEADERS += hal_uart.h
CSRCS += src/hal_uart.c
endif

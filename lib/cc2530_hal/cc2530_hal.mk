# cc2530 hal library makefile config
ifeq ($(CONFIG_USE_CC2530_HAL),y)
HEADERS += hal_defs.h \
		hal_clock.h \
		hal_mcu.h \
		hal_bitdef.h \
		hal_int.h

CSRCS += src/hal_clock.c\
		src/hal_mcu.c
endif

ifeq ($(CONFIG_UART_ENABLE),y)
HEADERS += hal_uart.h
CSRCS += src/hal_uart.c
endif

ifeq ($(CONFIG_DMA_ENABLE),y)
HEADERS += hal_dma.h
# CSRCS += src/hal_dma.c
endif

ifeq ($(CONFIG_RF_ENABLE),y)
HEADERS += hal_rf.h
CSRCS += src/hal_rf.c
endif

# ifeq ($(CONFIG_SPI_ENABLE),y)
# HEADERS += hal_spi.h
# CSRCS += src/hal_spi.c
# endif

# ifeq ($(CONFIG_I2C_ENABLE),y)
# HEADERS += hal_i2c.h
# CSRCS += src/hal_i2c.c
# endif

# ifeq ($(CONFIG_GPIO_ENABLE),y)
# HEADERS += hal_gpio.h
# CSRCS += src/hal_gpio.c
# endif

# ifeq ($(CONFIG_ADC_ENABLE),y)
# HEADERS += hal_adc.h
# CSRCS += src/hal_adc.c
# endif

# ifeq ($(CONFIG_TIMER_ENABLE),y)
# HEADERS += hal_timer.h
# CSRCS += src/hal_timer.c
# endif

# ifeq ($(CONFIG_RTC_ENABLE),y)
# HEADERS += hal_rtc.h
# CSRCS += src/hal_rtc.c
# endif

# ifeq ($(CONFIG_WATCHDOG_ENABLE),y)
# HEADERS += hal_watchdog.h
# CSRCS += src/hal_watchdog.c
# endif

# ifeq ($(CONFIG_FLASH_ENABLE),y)
# HEADERS += hal_flash.h
# CSRCS += src/hal_flash.c
# endif

# ifeq ($(CONFIG_RANDOM_ENABLE),y)
# HEADERS += hal_random.h
# CSRCS += src/hal_random.c
# endif

# ifeq ($(CONFIG_AES_ENABLE),y)
# HEADERS += hal_aes.h
# CSRCS += src/hal_aes.c
# endif

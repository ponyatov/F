ARCH = CortexM3

CFLAGS += -DSTM32F103xB
CFLAGS += -Ihw/$(HW)/CMSIS/Device/ST/STM32F1xx/Include
CFLAGS += -Ihw/$(HW)/Drivers/STM32F1xx_HAL_Driver/Inc
CFLAGS += -Ihw/$(HW)/Drivers/CMSIS/Device/ST/STM32F1xx/Include

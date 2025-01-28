OS  = bare
EXE = .elf

TARGET = arm-none-eabi

TCC  = $(TARGET)-gcc
TCXX = $(TARGET)-g++
TLD  = $(TARGET)-ld
TAS  = $(TCC) -x assembler-with-cpp
TCP  = $(TARGET)-objcopy
TSZ  = $(TARGET)-size

CPUFLAGS += -mthumb
CFLAGS   += -DHSI_VALUE=8000000
CFLAGS   += -DVDD_VALUE=3300
CFLAGS   += -DUSE_FULL_LL_DRIVER

# CFLAGS  += -MMD -MP -MF"$(@:%.o=%.d)"

LDFLAGS += -specs=nano.specs -Thw/$(HW)/$(CPU)x_FLASH.ld

L += -lc -lm -lnosys

OBJ += $(wildcard hw/$(HW)/Core/Src/*.c*)

F=

CFLAGS += -Ihw/$(HW)/Core/Inc
CFLAGS += -Ihw/$(HW)/Drivers/CMSIS/Include

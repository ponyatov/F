OS  = bare
EXE = .elf

TARGET = arm-none-eabi

TCC  = $(TARGET)-gcc
TCXX = $(TARGET)-g++
TLD  = $(TCC)
TAS  = $(TCC) -x assembler-with-cpp
TCP  = $(TARGET)-objcopy
TSZ  = $(TARGET)-size

CPUFLAGS += -mthumb
CFLAGS   += -DHSI_VALUE=8000000
CFLAGS   += -DVDD_VALUE=3300
CFLAGS   += -DUSE_FULL_LL_DRIVER

CFLAGS   += -ffunction-sections -fdata-sections

CXXFLAGS += -fno-rtti -fno-exceptions
# CXXFLAGS += -nostdinc++
CFLAGS   += -nodefaultlibs
# CFLAGS   += -nostdlib

# CFLAGS  += -MMD -MP -MF"$(@:%.o=%.d)"

LDFLAGS += -specs=nano.specs
LDFLAGS += -Thw/$(HW)/$(CPU)x_FLASH.ld
LDFLAGS += -Wl,--gc-sections

L += -lc -lm -lnosys


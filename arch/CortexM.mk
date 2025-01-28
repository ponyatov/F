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

F=

CFLAGS += -Ihw/$(HW)/Core/Inc
CFLAGS += -Ihw/$(HW)/Drivers/CMSIS/Include

CORE = hw/$(HW)/Core/Src
O    = $(wildcard $(CORE)/*.c*)
O   := $(patsubst %.c,%.o,$(O))
O   := $(subst $(CORE)/,tmp/,$(O))
OBJ += $(O)

tmp/%.o: $(CORE)/%.c $(H) $(HP) $(MK)
	$(TCC) $(CPUFLAGS) $(CFLAGS) $(CCFLAGS) -o $@ -c $<

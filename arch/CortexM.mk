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

CFLAGS += -Ihw/$(HW)/Core/Inc
CFLAGS += -Ihw/$(HW)/Drivers/CMSIS/Include
CFLAGS += -Ihw/$(HW)/CMSIS/Device/ST/$(SERIES)xx/Include
CFLAGS += -Ihw/$(HW)/Drivers/$(SERIES)xx_HAL_Driver/Inc
CFLAGS += -Ihw/$(HW)/Drivers/CMSIS/Device/ST/$(SERIES)xx/Include

CORE_ = hw/$(HW)/Core/Src
CORE  = $(wildcard $(CORE_)/*.c)
CORE := $(patsubst %.c,%.o,$(CORE))
CORE := $(subst $(CORE_)/,tmp/,$(CORE))
OBJ  += $(CORE)

tmp/%.o: $(CORE_)/%.c $(H) $(HP) $(MK)
	$(TCC) $(CPUFLAGS) $(CFLAGS) $(CCFLAGS) -o $@ -c $<

HAL_ := hw/$(HW)/Drivers/$(SERIES)xx_HAL_Driver/Src
HAL   = $(wildcard $(HAL_)/*.c)
HAL  := $(patsubst %.c,%.o,$(HAL))
HAL  := $(subst $(HAL_)/,tmp/,$(HAL))
OBJ  += $(HAL)

tmp/%.o: $(HAL_)/%.c $(H) $(HP) $(MK)
	$(TCC) $(CPUFLAGS) $(CFLAGS) $(CCFLAGS) -o $@ -c $<

ASM_  = hw/$(HW)
ASM   = $(wildcard $(ASM_)/*.s)
ASM  := $(patsubst %.s,%.o,$(ASM))
ASM  := $(subst $(ASM_)/,tmp/,$(ASM))
OBJ  += $(ASM)

tmp/%.o: $(ASM_)/%.s $(H) $(HP) $(MK)
	$(TAS) $(CPUFLAGS) $(CFLAGS) $(ASFLAGS) -o $@ -c $<

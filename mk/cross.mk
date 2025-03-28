# HW ?= pc
# HW ?= mega2560
# HW ?= lm3s6
# HW ?= pillF030
# HW ?= pillF103
# HW ?= f4disco
# HW ?= iskra
# HW ?= l496disco
HW ?= f429disco
# HW ?= pi800

BINFILE = $(MODULE)_$(HW)_$(BRANCH)_$(NOW)
 PCFILE = $(MODULE)_pc_$(BRANCH)_$(NOW)

ELF = $(BIN)/$(BINFILE).elf
DFU = $(BIN)/$(BINFILE).dfu

# include   hw/$(HW)/$(HW).mk
# include  cpu/$(CPU)/$(CPU).mk
# include arch/$(ARCH)/$(ARCH).mk
# include   os/$(OS)/$(OS).mk

.PHONY: elf
elf: $(ELF)

.PHONY: dfu
dfu: $(DFU)
$(DFU): $(ELF)
	~/elf2dfuse/bin/elf2dfuse $< $@

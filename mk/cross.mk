# HW ?= pc
# HW ?= pillF030
HW ?= pillF103
# HW ?= IskraJS
# HW ?= F4DISCO

include   hw/$(HW).mk
include  cpu/$(CPU).mk
include arch/$(ARCH).mk
include   os/$(OS).mk

BINFILE = $(MODULE)_$(HW)_$(BRANCH)_$(NOW)$(EXE)

# CC      = $(TARGET)-gcc
# CXX     = $(TARGET)-g++
# AS      = $(CC)
# LD      = $(TARGET)-ld
# SIZE    = $(TARGET)-size
# OBJDUMP = $(TARGET)-objdump
CC      = gcc
CXX     = g++
AS      = $(CC)
LD      = ld
SIZE    = size
OBJDUMP = objdump

CCFLAGS += -Wno-int-to-pointer-cast
CCFLAGS += -Wno-pointer-to-int-cast

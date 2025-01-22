HW ?= pc

include   hw/$(HW).mk
include  cpu/$(CPU).mk
include arch/$(ARCH).mk
include   os/$(OS).mk

BINFILE = $(MODULE)_$(HW)_$(BRANCH)_$(NOW)

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

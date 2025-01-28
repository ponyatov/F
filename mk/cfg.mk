CFLAGS   += -I$(INC) -I$(TMP) -Og -ggdb
CCFLAGS  += -std=gnu17
CXXFLAGS += -std=gnu++17

CFLAGS   += -I$(CWD)/hw/$(HW)/inc     -I$(CWD)/hw/inc
CFLAGS   += -I$(CWD)/cpu/$(CPU)/inc   -I$(CWD)/cpu/inc
CFLAGS   += -I$(CWD)/arch/$(ARCH)/inc -I$(CWD)/arch/inc
CFLAGS   += -I$(CWD)/os/$(OS)/inc	  -I$(CWD)/os/inc

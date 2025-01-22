# all
.PHONY: all run
all: bin/$(BINFILE)$(EXE) $(S)
run: bin/$(BINFILE)$(EXE) $(S)
	$^

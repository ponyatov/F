.PHONY: all run
all: $(BIN)/$(PCFILE) $(S)
run: $(BIN)/$(PCFILE) $(S)
	$^

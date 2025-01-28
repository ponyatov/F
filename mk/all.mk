# all
.PHONY: all run
all: bin/$(BINFILE) $(F)
run: bin/$(BINFILE) $(F)
	$^

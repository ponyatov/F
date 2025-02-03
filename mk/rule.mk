$(BIN)/$(BINFILE): $(C) $(H)
	cmake         --preset glibc
	cmake --build --preset glibc -j

.PHONY: $(ELF)
$(ELF): $(C) $(H)
	cmake         --preset ${HW}
	cmake --build --preset ${HW}

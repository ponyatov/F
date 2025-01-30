$(BIN)/$(BINFILE): $(C) $(H) $(P)
	cmake         --preset linux
	cmake --build --preset linux -j

.PHONY: $(ELF)
$(ELF): $(C) $(H)
	cmake         --preset ${HW}
	cmake --build --preset ${HW}

# bin/$(BINFILE): $(MK) $(OBJ)
# 	# $(TCC) $(CPUFLAGS) $(LDFLAGS) -o $@ $(L) $(OBJ)
# tmp/%.o: src/%.cpp $(H) $(HP) $(MK)
# 	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<
# tmp/%.o: tmp/%.cpp $(H) $(HP) $(MK)
# 	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

# tmp/%.lexer.cpp: $(SRC)/%.lex
# 	flex -o $@ $<
# tmp/%.parser.cpp: $(SRC)/%.yacc
# 	bison -o $@ $<
# tmp/%.ragel.cpp: $(SRC)/%.ragel
# 	ragel -G2 -o $@ $<

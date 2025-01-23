bin/$(BINFILE)$(EXE): $(C) $(H) $(CP) $(HP)
	$(CXX) $(CFLAGS) -o $@ $(C) $(CP) $(L)
$(TMP)/%.lexer.cpp: $(LIB)/cli/src/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(LIB)/cli/src/%.yacc
	bison -o $@ $<

bin/$(BINFILE)$(EXE): $(C) $(H) $(CP) $(HP)
	$(CXX) $(CFLAGS) -o $@ $(C) $(CP) $(L)
$(TMP)/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
$(TMP)/%.ragel.cpp: $(SRC)/%.ragel
	ragel -G2 -o $@ $<

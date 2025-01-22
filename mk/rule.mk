bin/$(BINFILE)$(EXE): $(C) $(H) $(CP) $(HP)
# $(CXX) $(CFLAGS) -o $@ $(C) $(CP) $(L)
	cmake           --preset $(OS) -S . -B tmp/mingw
	cmake --build   --preset $(OS)         tmp/mingw
	cmake --install                        tmp/mingw
$(TMP)/%.lexer.cpp: $(LIB)/cli/src/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(LIB)/cli/src/%.yacc
	bison -o $@ $<

bin/$(BINFILE): $(C) $(H) $(CP) $(HP)
# $(CXX) $(CFLAGS) -o $@ $(C) $(CP) $(L)
	cmake           --preset mingw -S . -B tmp/mingw
	cmake --build   --preset mingw         tmp/mingw
	cmake --install --preset mingw         tmp/mingw
$(TMP)/%.lexer.cpp: $(LIB)/cli/src/%.lex
	flex -o $@ $<
$(TMP)/%.parser.cpp: $(LIB)/cli/src/%.yacc
	bison -o $@ $<

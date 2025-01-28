
OBJ += $(wildcard src/*.c*)
OBJ := $(patsubst %.cpp,%.o,$(OBJ))
OBJ := $(patsubst src/%,tmp/%,$(OBJ))

.PHONY: obj
obj: $(OBJ)

bin/$(BINFILE): $(C) $(H) $(CP) $(HP) $(MK) $(OBJ)
	$(TLD)  $(LDFLAGS) -o $@ $(L) $(OBJ)
tmp/%.o: src/%.cpp $(MK)
	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<
tmp/%.o: tmp/%.cpp $(MK)
	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

tmp/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
tmp/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
tmp/%.ragel.cpp: $(SRC)/%.ragel
	ragel -G2 -o $@ $<

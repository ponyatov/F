
OBJ += $(wildcard src/*.c*)
OBJ := $(patsubst %.cpp,%.o,$(OBJ))
OBJ := $(patsubst %.c,%.o,$(OBJ))
OBJ := $(patsubst src/%,tmp/%,$(OBJ))

.PHONY: obj
obj: $(OBJ)

bin/$(BINFILE): $(MK) $(OBJ)
	$(TCXX) $(CPUFLAGS) $(LDFLAGS) -o $@ $(L) $(OBJ)
tmp/%.o: src/%.cpp $(H) $(HP) $(MK)
	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<
tmp/%.o: tmp/%.cpp $(H) $(HP) $(MK)
	$(TCXX) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

tmp/%.o: hw/$(HW)/Core/Src/%.c $(H) $(HP) $(MK)
	$(TCC) $(CPUFLAGS) $(CFLAGS) $(CXXFLAGS) -o $@ -c $<

tmp/%.lexer.cpp: $(SRC)/%.lex
	flex -o $@ $<
tmp/%.parser.cpp: $(SRC)/%.yacc
	bison -o $@ $<
tmp/%.ragel.cpp: $(SRC)/%.ragel
	ragel -G2 -o $@ $<

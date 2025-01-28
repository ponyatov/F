CFLAGS += -DLINUX
EXE =

TCC  = $(CC)
TCXX = $(CXX)
TLD  = $(LD)
TAS  = $(AS)
TCP  = objcopy
TSZ  = size

CP += $(TMP)/cli.parser.cpp $(TMP)/cli.lexer.cpp
HP += $(TMP)/cli.parser.hpp

F += $(wildcard lib/*.ini) $(wildcard lib/*.f)

CFLAGS += -DLINUX
EXE =

TCXX = $(CXX)

CP += $(TMP)/cli.parser.cpp $(TMP)/cli.lexer.cpp
HP += $(TMP)/cli.parser.hpp

S += $(wildcard lib/*.ini) $(wildcard lib/*.f)

C += $(wildcard src/*.c*) $(wildcard src/rtos/*.c*)
H += $(wildcard inc/*.h*) $(wildcard inc/rtos/*.h*)

C += $(wildcard   hw/$(HW)/src/*.c*)
H += $(wildcard   hw/$(HW)/inc/*.h*)
C += $(wildcard  cpu/$(CPU)/src/*.c*)
H += $(wildcard  cpu/$(CPU)/inc/*.h*)
C += $(wildcard arch/$(ARCH)/src/*.c*)
H += $(wildcard arch/$(ARCH)/inc/*.h*)
C += $(wildcard   os/$(OS)/src/*.c*)   $(wildcard   os/src/*.c*)
H += $(wildcard   os/$(OS)/inc/*.h*)   $(wildcard   os/inc/*.h*)

CP += $(TMP)/cli.parser.cpp $(TMP)/cli.lexer.cpp
HP += $(TMP)/cli.parser.hpp

C += $(wildcard lib/core/src/*.c*)
H += $(wildcard lib/core/inc/*.h*)
C += $(wildcard lib/cli/src/*.c*)
H += $(wildcard lib/cli/inc/*.h*)

S += $(wildcard lib/*.ini) $(wildcard lib/*.f)

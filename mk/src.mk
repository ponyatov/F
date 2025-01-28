MK += Makefile
MK += $(wildcard   mk/*.mk)
MK += $(wildcard   hw/$(HW).mk)
MK += $(wildcard  cpu/$(CPU).mk)
MK += $(wildcard arch/*.mk)
MK += $(wildcard   os/$(OS).mk)

C += $(wildcard src/*.c*)
H += $(wildcard inc/*.h*)

C += $(wildcard   hw/$(HW)/src/*.c*)   $(wildcard   hw/src/*.c*)
H += $(wildcard   hw/$(HW)/inc/*.h*)   $(wildcard   hw/inc/*.h*)
C += $(wildcard  cpu/$(CPU)/src/*.c*)  $(wildcard  cpu/src/*.c*)
H += $(wildcard  cpu/$(CPU)/inc/*.h*)  $(wildcard  cpu/inc/*.h*)
C += $(wildcard arch/$(ARCH)/src/*.c*) $(wildcard arch/src/*.c*)
H += $(wildcard arch/$(ARCH)/inc/*.h*) $(wildcard arch/inc/*.h*)
C += $(wildcard   os/$(OS)/src/*.c*)   $(wildcard   os/src/*.c*)
H += $(wildcard   os/$(OS)/inc/*.h*)   $(wildcard   os/inc/*.h*)

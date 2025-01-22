.PHONY: install update ref gz
install: $(HOST)_install
update: $(HOST)_update
ref: $(RF)
gz:  $(GZ)

Debian_install: update doc ref gz
	sudo dpkg --add-architecture i386
Debian_update:
	sudo apt update
	sudo apt install -uy `cat apt.$(HOST)`

Msys_install:
Msys_update:
	pacman -S $(shell cat apt.$(HOST) | tr '\n' ' ')

$(RUSTUP) $(CARGO):
	curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

.PHONY: rust
rust: $(RUSTUP) $(CARGO)
	rustup target add thumbv6m-none-eabi
	rustup target add thumbv7m-none-eabi
	rustup target add thumbv7em-none-eabihf
	cargo install cargo-binutils
	rustup component add llvm-tools
	curl --proto '=https' --tlsv1.2 -LsSf https://github.com/probe-rs/probe-rs/releases/latest/download/probe-rs-tools-installer.sh | sh

$(BIN)/$(BINFILE): target/debug/$(MODULE)
target/debug/$(MODULE): $(R) Cargo.toml .cargo/config.toml
	cargo build

$(ELF): target/$(RTARGET)/debug/libfortex.d
	cp $< $@
target/$(RTARGET)/debug/libfortex.d: $(R) Cargo.toml .cargo/config.toml
	cargo build --target $(RTARGET) -p fortex

RF += ref/cortex-m-quickstart/README.md
ref/cortex-m-quickstart/README.md:
	$(GITREF) https://github.com/rust-embedded/cortex-m-quickstart.git $(dir $@)

.PHONY: fortex
fortex: $(R) Cargo.toml fortex/Cargo.toml
	cargo build -p fortex

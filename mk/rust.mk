$(RUSTUP) $(CARGO):
	curl --proto '=https' --tlsv1.2 -sSf https://sh.rustup.rs | sh

# rustup target add thumbv7em-none-eabihf
# cargo install cargo-binutils
# rustup component add llvm-tools

$(BIN)/$(BINFILE): target/debug/$(MODULE)
	cp $< $@
target/debug/$(MODULE): $(R) Cargo.toml .cargo/config.toml
	cargo build

$(ELF): target/$(RTARGET)/debug/fortex
	cp $< $@
target/$(RTARGET)/debug/fortex: $(R) Cargo.toml .cargo/config.toml
	cargo build --target $(RTARGET) -p fortex

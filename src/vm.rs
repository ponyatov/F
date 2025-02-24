//! # F Virtual Machine
//! ## minimal version in Rust
//!
//! - FORTH-like multistack
//!   - isolate data from return addresses
//! - dense bytecode
//!   - main target: microcontrollers with a very small RAM
//! - full hw isolation
//!   - no absolute memory `ld`/`st`
//!   - no I/O
//!
//! ## targets:
//! - `x86_64-linux-gnu` (Linux)
//! - `arm-none-eabi` (Cortex-M)

#![allow(dead_code)]
#![allow(non_upper_case_globals)]

/// bytecode memory size, bytes
const Msz: usize = 0x10000;
/// return stack size, calls
const Rsz: usize = 0x100;
/// data stack size, signed machine words (32 bit)
const Dsz: usize = 0x10;

/// address word size in [M]
type Cell = u16;

/// main memory
static mut M: [u8; Msz] = [0; Msz];
/// compiler pointer (first empty byte)
static mut Cp: Cell = 0;
/// instruction pointer (first byte of current command)
static mut Ip: Cell = u16::MAX;

/// `( -- )` empty command: do nothing
fn nop() {}

/// `( -- )` stop system
fn halt() -> ! {
    std::process::exit(0);
}

/// POSIX program entry point
fn main() -> ! {
    nop();
    halt();
}

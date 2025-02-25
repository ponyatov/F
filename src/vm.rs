//! #  F Virtual Machine
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
#![allow(non_camel_case_types)]

/// bytecode memory size, bytes
const Msz: usize = 0x10000;
/// return stack size, [Addr]s
const Rsz: usize = 0x100;
/// data stack size, [Cell]s
const Dsz: usize = 0x10;

/// single byte `=u8`
type Byte = u8;
/// address word size in [M] `=u16`
type Addr = u16;
/// (machine) integer / data word in [D] `=i32`
type Cell = i32;

/// main memory, [Byte]s
static mut M: [Byte; Msz] = [0; Msz];
/// compiler pointer (first empty byte)
static mut Cp: Addr = 0;
/// instruction pointer (first byte of current command)
static mut Ip: Addr = u16::MAX;

/// return stack
static mut R: [Addr; Rsz] = [0; Rsz];
/// return stack pointer
/// limited to 64K, not more then [Rsz]
static mut Rp: usize = 0;

/// data stack
static mut D: [Cell; Dsz] = [0; Dsz];
/// data stack pointer
/// limited to 0x100, not more then [Dsz]
static mut Dp: usize = 0;

/// VM commands opcodes
enum Op {
    // flow control
    /// [nop] `( -- )` empty command
    nop = 0x00,
    /// [halt] `( -- )` stop system
    halt = 0xFF,
    /// [jmp] `( -- )` unconditional jump
    jmp = 0x01,
    /// [qjmp] `( bool -- )` jump if `false`
    qjmp = 0x02,
    /// [call] `(R: -- addr )` nested call
    call = 0x03,
    /// [ret] `(R: addr -- )` return from nested call
    ret = 0x04,
    /// [lit] `( -- n )` integer literal
    lit = 0x05,

    // stack operations
    /// `( a -- a a )` duplicate
    dup = 0x10,
    /// `( a b -- a )`
    drop = 0x11,
    /// `( a b -- b a )`
    swap = 0x12,
    /// `( a b -- a b a )`
    over = 0x13,
    /// `( a b c -- b c a )`
    rot = 0x14,
    /// `( a b c -- c a b )`
    mrot = 0x15,
    /// `( ... i -- ... xi )` fetch item by index
    pick = 0x16,
    /// `( ... -- ... n )` current data stack depth
    depth = 0x17,
}

use std::fmt;

// disassembler
impl fmt::Display for Op {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match *self {
            Op::nop => write!(f, "nop"),
            Op::halt => write!(f, "halt"),
            Op::jmp => write!(f, "jmp"),
            Op::qjmp => write!(f, "qjmp"),
            Op::call => write!(f, "call"),
            Op::ret => write!(f, "ret"),
            Op::lit => write!(f, "lit"),
            _ => write!(f, "???"),
        }
    }
}

// flow control

/// 0x00 `( -- )` empty command: do nothing
fn nop() {}

/// 0xFF `( -- )` stop system
fn halt() -> ! {
    std::process::exit(0);
}

/// get [Addr] from [M]`[addr]` (little endian)
unsafe fn get(addr: Addr) -> Addr {
    u16::from_le_bytes([M[addr as usize + 0], M[addr as usize + 1]])
}

/// `( -- n )` push `n` to [D]
unsafe fn push(n: Cell) {
    assert!(Dp < Dsz);
    D[Dp] = n;
    Dp += 1;
}

/// `( n -- )` pop `n` from top of [D]
unsafe fn pop() -> Cell {
    assert!(Dp > 0);
    Dp -= 1;
    D[Dp]
}

/// `(R: -- addr )` push return [Addr]ess
unsafe fn rpush(addr: Addr) {
    assert!(Rp < Rsz);
    R[Rp] = addr;
    Rp += 1;
}

/// `(R: addr -- )` pop return [Addr]ess
unsafe fn rpop() -> Addr {
    assert!(Rp > 0);
    Rp -= 1;
    R[Rp]
}

/// 0x01 `( -- )` unconditional jump
unsafe fn jmp() {
    Ip = get(Ip);
    assert!((Ip as usize) < Msz);
}

/// 0x02 `( bool -- )` jump if `false`
unsafe fn qjmp() {
    if pop() != 0 {
        jmp();
    }
}

/// 0x03 `(R: -- addr )` nested call
unsafe fn call() {
    rpush(Ip + std::mem::size_of::<Addr>() as Addr);
    jmp();
}

/// 0x04 `(R: addr -- )` return from nested call
fn ret() {
    todo!("");
}

/// 0x05 `( -- n )` integer literal
fn lit() {
    todo!("");
}

// stack operations
/// `( a -- a a )` duplicate
fn dup() {
    todo!("");
}

/// `( a b -- a )`
fn drop() {
    todo!("");
}

/// `( a b -- b a )`
fn swap() {
    todo!("");
}

/// `( a b -- a b a )`
fn over() {
    todo!("");
}

/// `( a b c -- b c a )`
fn rot() {
    todo!("");
}

/// `( a b c -- c a b )`
fn mrot() {
    todo!("");
}

/// `( ... i -- ... xi )` fetch item by index
fn pick() {
    todo!("");
}

/// `( ... -- ... n )` current data stack depth
unsafe fn depth() {
    assert!(Dp < Dsz);
    D[Dp as usize] = Dp as Cell;
    Dp += 1;
}

/// POSIX program entry point
fn main() -> ! {
    // command line arguments
    let args: Vec<String> = std::env::args().collect();
    // program binary name
    println!("{}", args[0]);
    // process script files via parser/compiler
    for src in &args[1..] {
        println!("\t{}", src);
    }
    // stub
    println!("{}", Op::depth);
    nop();
    halt();
}

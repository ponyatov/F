#![no_std]
#![no_main]

use panic_halt as _;

use cortex_m_rt::entry;
use cortex_m_semihosting::hprintln;

use fortex::*;

#[entry]
fn main() -> ! {
    hprintln!("Hello, world!");
    nop();
    halt();
}

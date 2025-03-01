#![no_std]
#![no_main]

use panic_halt as _;

use cortex_m_rt::entry;

use fortex::*;

#[entry]
fn main() -> ! {
    nop();
    halt()
}

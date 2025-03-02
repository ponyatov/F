//! F/Cortex
//!
//! - target: thumbv7m-none-eabihf
//!   - hw:   lm3s6 pillf103
//! - target: thumbv7em-none-eabihf
//!   - hw:   l496disco / f4disco/ iskrajs

#![no_std]

use cortex_m::asm;

pub fn nop() {
    asm::nop();
}

use cortex_m_semihosting::debug;

pub fn halt() -> ! {
    debug::exit(debug::EXIT_SUCCESS);
    loop {}
}

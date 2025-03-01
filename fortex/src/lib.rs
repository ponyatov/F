//! F/Cortex-M4F
//!
//! target: thumbv7em-none-eabihf
//! hw:     l496disco / f4disco/ iskrajs

#![no_main]
#![no_std]
#![allow(dead_code)]

pub fn nop() {}

pub fn halt() {
    loop {}
}

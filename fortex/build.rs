#![allow(non_snake_case)]

use std::env;
use std::fs;
use std::path::PathBuf;

fn main() {
    // Put `memory.x` in our output directory
    // and ensure it's on the linker search path.
    let hw = env::var_os("HW").unwrap();
    let hw = hw.to_str().unwrap();
    let ld = format!("hw/{}/{}.x", hw, hw);
    let out = &PathBuf::from(env::var_os("OUT_DIR").unwrap());
    fs::write(out.join("memory.x"), fs::read_to_string(ld).unwrap()).unwrap();

    //
    println!("cargo:rustc-link-search={}", out.display());
    println!("cargo:rerun-if-changed=memory.x");

    // `--nmagic` is required if memory section addresses are not aligned to 0x10000,
    println!("cargo:rustc-link-arg=--nmagic");

    // Set the linker script to the one provided by cortex-m-rt.
    println!("cargo:rustc-link-arg=-Tlink.x");
}

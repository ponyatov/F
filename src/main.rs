mod vm;
use crate::vm::*;

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
    println!("{} {} {}", Op::nop, Op::halt, Op::depth);
    nop();
    halt();
}

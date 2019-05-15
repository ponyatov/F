# {#metaprogramming}

Metaprogramming is a programming technique in which computer programs
have the ability to treat other programs as their data. 

It means that a program can be designed to read, generate, 
analyze or transform other programs, and even modify itself while running.

Meta allows programmers to automate program development by extending
the meta-enabled language with extra tools targets to
* automate code synthesis, 
* do complex type checking, 
* test generation, 
* create language features not provided by the core language
* use **managed compilation**:
  * (cross-) **compiler is provided in form of library**, and 
  * the *programer manually uses this compiler library* thru the whole
  compilation from source code parsing to target machine code generation
    * has full access to compiler structures on every stage,
    * can set hooks on compiler events, 
    * modify and analyze intermediate program representations, and 
    * modify compiler library itself
* **code generation**:
  * homoiconic interpretive languages tend to be extra slow
  * to avoid slowness and overtake any mainstream compilers we can use
    * **model compiler** converts highest level models into 
      low-level and high optimizing languages (C,C++,Java)
    * generate low-level code via LLVM with a lot of optimizations
      available off-the-shelf
    * in some rare cases generate target machine code
      (data crunching using specific hardware features)

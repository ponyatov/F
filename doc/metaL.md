# {#metaL}

very simple @ref FORTH -like language

* FORTH problems removed:
  * no direct memory access
  	* no system faults on memory overwrite
  * all code represented as executable data
    * arbitrary vocabulary modifications via unified VM interface
  * loose classless OOP
    * uses Marvin Minsky frame model
* optimized to be compatible with modern mainstream languages
  * @ref homoiconic model represents **data structures as programs**
    * fully reprogrammable in runtime
    * @ref metaprogramming support

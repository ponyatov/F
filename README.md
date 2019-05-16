# metaL
## homoiconic metaprogramming language /on top of Python/

### write program code with the speed of thinking

(c) Dmitry Ponyatov <<dponyatov@gmail.com>> CC BY-NC-ND

github: https://github.com/ponyatov/F

* extended Marvin Minsky [[frame model]]
  * ordered `nest[]`ed container added for attribute grammar & AST
  * universal knowledge representation
  * ideal for [[homoiconic]] [[metaprogramming]]
* multiparadigm
  * [[parallel]] [[message passing]]
  * [[declarative]]
  * [[imperative]] but [[avoid sequential programming]]
* multilanguage inspired
  * [[Python]] used for runtime core
    * as a language simplest to learn
    * very light and fast runtime
    * portable
    * easy to write extensions and integrate extra libraries  * [[Smalltalk]] and Self
  * [[Lisp]]
    * [[homoiconic]] from the roots
  * [[FORTH]]
    * world simplest programming language ever can be
    * [[metaL]] : very simple FORTH-like language solved most problems
      * no direct memory faults
* designed for [[embedded system]]s (meta)programming
  * [[CortexM]] (STM32,..)
  * [[MSP430]]
  * [[emLinux]]
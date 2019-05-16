# metaL
## homoiconic metaprogramming language /on top of Python/

### write program code with the speed of thinking

(c) Dmitry Ponyatov <<dponyatov@gmail.com>> CC BY-NC-ND

github: https://github.com/ponyatov/F

wiki: https://github.com/ponyatov/F/wiki

* extended Marvin Minsky [[frame model]]
  * ordered `nest[]`ed container added for attribute grammar & AST
  * **universal knowledge representation**
  * ideal for [[homoiconic]] [[metaprogramming]]
  * [[loosen classless OOP]]
  * [[homoiconic]] universe in form of object graphs
    * **no plain text source code** at all
      * [[metaL]] is an auxiliary tool (command/DDL language)
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
  * [[Smalltalk]] & Self
    * fully dynamic system
    * actor model with [[message passing]]
    * RAM-only: no image persistence, system (re)loads from plain text files
      * friendly with git(hub)
      * manual edit for system definition
  * [[FORTH]]
    * world simplest programming language ever can be
    * [[metaL]] : very simple FORTH-like language solves most problems with classical [[FORTH]]
      * no direct memory faults
      * *is not programming but command and **frame definition** language*
* designed for [[embedded system]]s (meta)programming via [[code generation]]
  * [[CortexM]] (STM32,..)
  * [[MSP430]]
  * [[emLinux]]
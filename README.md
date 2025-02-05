# ![](vscode/logo.png) `F.lang`
## script engine

(c) Dmitry Ponyatov <<dponyatov@gmail.com>> 2025 MIT

github: https://github.com/ponyatov/F

- based on the @ref eds idea
    - dynamic interpreter @ref core
    - uses @ref ograph as a unified data/program representation
- multiplatform

#### Level zero / 0.0.x

- proof-of-concept implementation
    - still be usable for simple practical tasks
        - calculator
        - file manipulations (one-liners for find/rename/transform)
        - embedded hardware control
- `L0` script language
    - @ref FORTH -like: postfix & stack (but typed data and name-bound storage)
    - concatenative programming
    - text console only

#### L0.1 / 0.1.x

+ add base graphics
    - tiny 2D games

#### L0.2 / 0.2.x

+ vector & GUI
    - write tiny GUI tools
    - 2D sketching & CAD

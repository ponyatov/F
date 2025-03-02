MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH =  64K
}

_stack_start = ORIGIN(RAM) + LENGTH(RAM);

SECTIONS
{
    .vector_table :
    {
        . = ALIGN(8);
        KEEP(*(.vector_table))
        . = ALIGN(8);
    } >FLASH

    .text :
    {
        . = ALIGN(8);
        *(.text )
        *(.text*)
        . = ALIGN(8);
        _etext = .;
    } >FLASH

    .rodata :
    {
        . = ALIGN(8);
        _srodata = .;
        *(.rodata )
        *(.rodata*)
        . = ALIGN(8);
        _erodata = .;
    } >FLASH

    _sidata = LOADADDR(.data);
    .data :
    {
        . = ALIGN(8);
        _sdata = .;
        *(.data )
        *(.data*)
        . = ALIGN(8);
        _edata = .;
    } >RAM AT>FLASH

    .bss :
    {
        . = ALIGN(8);
        _sbss = .;
        *(.bss )
        *(.bss*)
        *(COMMON)
        . = ALIGN(8);
        _ebss = .;
    } >RAM
}

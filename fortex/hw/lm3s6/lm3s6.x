/* LM3S6965 */

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 256K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH =  64K
}

/* _stack_start = ORIGIN(RAM) + LENGTH(RAM); @ link.x */

/* l496disco */

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x8000000 , LENGTH = 1024K
    RAM   (rwx) : ORIGIN = 0x20000000, LENGTH =  320K
    CCM   (rwx) : ORIGIN = 0x10000000, LENGTH =   64K
}

/* _stack_start = ORIGIN(CCM) + LENGTH(CCM); @ link.x */

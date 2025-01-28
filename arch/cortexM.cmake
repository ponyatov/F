add_compile_options(
    -mthumb
    -DHSI_VALUE=8000000
    -DVDD_VALUE=3300
    -DUSE_FULL_LL_DRIVER
)
add_link_options(
    -mthumb
    -lc -lm -lnosys
)

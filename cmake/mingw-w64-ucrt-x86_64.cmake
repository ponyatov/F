set(CMAKE_SYSTEM_NAME       Windows)
set(TOOLCHAIN_PREFIX        mingw-w64-ucrt-x86_64)

include(cmake/any_toolchain.cmake)

# force native on-host only
set(CMAKE_C_COMPILER   gcc)
set(CMAKE_ASM_COMPILER ${CMAKE_C_COMPILER})
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_LINKER       g++)
set(CMAKE_OBJCOPY      objcopy)
set(CMAKE_SIZE         size)
set(CMAKE_RC_COMPILER  windres)

add_compile_options(
    "-march=native"
)

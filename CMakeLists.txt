cmake_minimum_required (VERSION 3.22)

project ("cht" LANGUAGES C)

include (CheckCCompilerFlag)
include (CheckIncludeFile)
include (cmake/CheckThreads.cmake)
include (cmake/CCache.cmake)
include (cmake/Config.cmake)

find_package (Threads REQUIRED)
find_package (OpenSSL REQUIRED)

find_program (CCACHE_PROGRAM "ccache")

check_include_file (stdint.h    HAVE_STDINT)
check_include_file (inttypes.h  HAVE_INTTYPES)

cht_check_threads()
cht_ccache()
cht_check_config()

add_executable(main main.c)

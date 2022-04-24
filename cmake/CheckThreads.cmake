cmake_minimum_required (VERSION 3.22)

include (CheckIncludeFile)

macro (cht_check_threads)
    check_include_file ("threads.h" HAVE_THREADS)
endmacro (cht_check_threads)

if (NOT HAVE_THREADS)
    message (STATUS "STD C11 threads not supported by the compiler, will be used tinycthread. https://github.com/ori-d/tinycthread.git")
    add_library("tthreads" STATIC
                           "${CMAKE_SOURCE_DIR}/lib/threads/threads.h"
                           "${CMAKE_SOURCE_DIR}/lib/threads/threads.c")
    include_directories("${CMAKE_SOURCE_DIR}/lib/threads/")
    link_libraries("tthreads")
endif (NOT HAVE_THREADS)

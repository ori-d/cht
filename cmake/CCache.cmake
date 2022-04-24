cmake_minimum_required(VERSION 3.22)

macro(cht_ccache)
    if (CCACHE_PROGRAM)
        message (STATUS "Found \"${CCACHE_PROGRAM}\" and it will be used for compilation.")
        set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
    endif (CCACHE_PROGRAM)
endmacro(cht_ccache)

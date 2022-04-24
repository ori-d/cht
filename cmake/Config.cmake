cmake_minimum_required (VERSION 3.22)

macro(cht_check_config)
    set (CONFIGURE_FILE "${CMAKE_SOURCE_DIR}/inc/cht.config.h")
    if (EXISTS ${CONFIGURE_FILE})
        message (STATUS "Config file found at: ${CONFIGURE_FILE}")
        configure_file (${CONFIGURE_FILE} "config.h" @ONLY)
        add_compile_definitions (HAS_CONFIG)
        include_directories (${CMAKE_BINARY_DIR})
    endif (EXISTS ${CONFIGURE_FILE})
endmacro(cht_check_config)


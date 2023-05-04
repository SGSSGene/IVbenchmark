cmake_minimum_required (VERSION 3.12)

# check if this is the main project
if (NOT DEFINED PROJECT_NAME)
    set(CMAKE_CXX_STANDARD 20)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
    set(IO2_ROOT_PROJECT TRUE)
endif ()

project (io2 LANGUAGES CXX VERSION "${IO2_PROJECT_VERSION}"
             DESCRIPTION "io2 -- I/O library for seqan3 based on seqan2")

include(io2-config.cmake)

if (${IO2_ROOT_PROJECT})
    enable_testing()
#    add_subdirectory(test)
endif()

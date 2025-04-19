cmake_minimum_required(VERSION 3.10)
project(libart C)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)
option(BUILD_STATIC_LIBS "Build static libraries" ON)
option(ENABLE_TESTS "Enable building tests" ON)

add_subdirectory(src)

if(ENABLE_TESTS)
    add_subdirectory(tests)
endif()
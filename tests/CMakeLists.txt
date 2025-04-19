# Add the CMocka submodule
add_subdirectory(${CMAKE_SOURCE_DIR}/external/cmocka external/cmocka_build)

# Test sources
set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/runner.c
)

add_executable(test_art ${TEST_SOURCES})

# Link to the shared library and cmocka
target_link_libraries(test_art PRIVATE art_shared cmocka)

target_include_directories(test_art PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/cmocka/include
)

enable_testing()
add_test(NAME art_tests COMMAND test_art)
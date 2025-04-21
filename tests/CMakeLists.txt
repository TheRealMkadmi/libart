set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/runner.c
)

add_executable(test_art ${TEST_SOURCES})

# Link to the library (alias 'art' resolves to shared or static) and cmocka
target_link_libraries(test_art PRIVATE art cmocka)

target_include_directories(test_art PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/external/cmocka/include
)

enable_testing()
add_test(NAME art_tests COMMAND test_art)
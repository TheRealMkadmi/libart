include(../cmake/FetchCMocka.cmake)

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/runner.c
)

add_executable(test_art ${TEST_SOURCES})
target_compile_features(test_art PRIVATE c_std_99)
target_link_libraries(test_art PRIVATE art cmocka-static)
target_include_directories(test_art PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

enable_testing()
add_test(NAME art_tests COMMAND test_art)
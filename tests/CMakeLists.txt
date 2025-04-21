find_package(CMocka REQUIRED) # Explicitly find the cmocka package

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/runner.c
)

add_executable(test_art ${TEST_SOURCES})

# Link to the library (alias 'art' resolves to shared or static) and cmocka
# Use the target/variables provided by find_package
target_link_libraries(test_art PRIVATE art CMocka::cmocka)

target_include_directories(test_art PRIVATE
    ${CMAKE_SOURCE_DIR}/src
    # Use include directory provided by find_package instead of submodule path
    ${CMOCKA_INCLUDE_DIRS} 
)

enable_testing()
add_test(NAME art_tests COMMAND test_art)
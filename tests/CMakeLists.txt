# Find the cmocka library directly
find_library(CMOCKA_LIBRARY cmocka REQUIRED)

set(TEST_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/runner.c
)

add_executable(test_art ${TEST_SOURCES})

# Link to the library (alias 'art' resolves to shared or static) and cmocka
# Use the found library variable
# On Windows, the library may be in a different location, so handle that if needed
if (WIN32)
    target_link_libraries(test_art PRIVATE art ${CMOCKA_LIBRARY})
    target_include_directories(test_art PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        ${CMAKE_SOURCE_DIR}/external/cmocka/include
    )
else()
    target_link_libraries(test_art PRIVATE art ${CMOCKA_LIBRARY})
    target_include_directories(test_art PRIVATE
        ${CMAKE_SOURCE_DIR}/src
        /usr/include
    )
endif()

enable_testing()
add_test(NAME art_tests COMMAND test_art)
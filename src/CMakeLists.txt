set(ART_SOURCES art.c)
set(ART_HEADERS art.h)

if(BUILD_SHARED_LIBS)
    add_library(art_shared SHARED ${ART_SOURCES} ${ART_HEADERS})
    # Place all output in unified build directories
    set_target_properties(art_shared PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
    )
    if(MSVC)
      # Ensure import library is generated by exporting all symbols on Windows
      set_target_properties(art_shared PROPERTIES WINDOWS_EXPORT_ALL_SYMBOLS ON)
    endif()
    target_include_directories(art_shared PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    set_target_properties(art_shared PROPERTIES OUTPUT_NAME art)
    install(TARGETS art_shared
        EXPORT libartConfig
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
endif()

if(BUILD_STATIC_LIBS)
    add_library(art_static STATIC ${ART_SOURCES} ${ART_HEADERS})
    # Place all output in unified build directories
    set_target_properties(art_static PROPERTIES
      ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
      LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib/$<CONFIG>
      RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>
      OUTPUT_NAME art
    )
    target_include_directories(art_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
    install(TARGETS art_static
        EXPORT libartConfig
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)
endif()

if(TARGET art_shared)
    add_library(art ALIAS art_shared)
elseif(TARGET art_static)
    add_library(art ALIAS art_static)
endif()

install(FILES ${ART_HEADERS} DESTINATION include/libart)
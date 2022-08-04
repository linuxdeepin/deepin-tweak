# Application
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
    add_definitions(-DPLUGINPATH="${LIBRARY_OUTPUT_PATH}")
endif()

add_subdirectory(main)
add_subdirectory(preloadplugin)
add_subdirectory(maincomponentplugin)
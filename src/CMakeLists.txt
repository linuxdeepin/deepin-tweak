# Application
if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    set(LIBRARY_OUTPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib")
    add_definitions(-DLOCALLIBPATH="${LIBRARY_OUTPUT_PATH}")
    add_definitions(-DPLUGINPATH="${CMAKE_CURRENT_SOURCE_DIR}")
endif()

add_subdirectory(main)
add_subdirectory(preloadplugin)
add_subdirectory(maincomponentplugin)
add_subdirectory(plugins)

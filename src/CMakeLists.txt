set(SRCS
  ./main.cpp
)

add_executable(deepin-tweak
  ${src_prop}
)

set_target_properties(deepin-tweak PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER tweak.deepin.org
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_compile_definitions(deepin-tweak
    PRIVATE $<$<OR:$<CONFIG:Debug>,$<CONFIG:RelWithDebInfo>>:QT_QML_DEBUG>
)

target_link_libraries(deepin-tweak
    PRIVATE
    Qt::Quick
)

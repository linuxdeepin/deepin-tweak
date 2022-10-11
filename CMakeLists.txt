# SPDX-FileCopyrightText: 2022 UnionTech Software Technology Co., Ltd.

# SPDX-License-Identifier: CC0-1.0
cmake_minimum_required(VERSION 3.13)

project(deepin-tweak VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 17)

include(GNUInstallDirs)

# generate qm
execute_process(COMMAND bash "translate_generation.sh"
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR})

find_package(QT NAMES Qt5 REQUIRED COMPONENTS Core Quick)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Quick)
find_package(DtkDeclarative REQUIRED)

if (NOT CMAKE_BUILD_TYPE STREQUAL "Release")
    add_definitions(-DPLUGINPATH="${CMAKE_CURRENT_SOURCE_DIR}")
endif()

add_subdirectory(src)
add_subdirectory(plugins)

cmake_minimum_required(VERSION 3.25)

set(PROJECT_VERSION "1.0.0.0" CACHE STRING "Project version")

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

include(target_add_versioninfo)

project(RetroGameLANHook
    VERSION ${PROJECT_VERSION}
)

if (NOT PROJECT_VERSION_PATCH)
    set(PROJECT_VERSION_PATCH 0)
endif()

if (NOT PROJECT_VERSION_TWEAK)
    set(PROJECT_VERSION_TWEAK 0)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(common)

add_subdirectory(lib/asi)
add_subdirectory(lib/wsock32)
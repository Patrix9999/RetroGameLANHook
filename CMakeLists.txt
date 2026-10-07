cmake_minimum_required(VERSION 3.25)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/")

include(target_add_versioninfo)

project(RetroGameLANHook)

add_subdirectory(common)

add_subdirectory(lib/asi)
add_subdirectory(lib/wsock32)
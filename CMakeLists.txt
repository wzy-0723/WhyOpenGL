cmake_minimum_required(VERSION 3.16)

# --- vcpkg
if (DEFINED ENV{VCPKG_ROOT} AND NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    message(STATUS "VCPKG_ROOT: $ENV{VCPKG_ROOT}")
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
endif()

project(WhyOpenGL VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)


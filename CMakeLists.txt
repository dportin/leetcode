cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(
    leetcode
    VERSION 0.0.0.1
    DESCRIPTION "LeetCode Solutions"
    HOMEPAGE_URL "https://github.com/dportin/leetcode-solutions"
    LANGUAGES "CXX"
)

# Add module directory to CMake module search path
# https://cmake.org/cmake/help/latest/variable/CMAKE_MODULE_PATH.html

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(Utilities)
include(FetchContent)

# LeetCode compiles C++ with Clang 19 using the latest C++23 standard and libstdc++ provided by GCC 14
# https://support.leetcode.com/hc/en-us/articles/360011833974-What-are-the-environments-for-the-programming-languages

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${CMAKE_BINARY_DIR}")

# Needed by Clang language server for integration with some editors
# https://cmake.org/cmake/help/latest/variable/CMAKE_EXPORT_COMPILE_COMMANDS.html

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Workaround for VSCode not passing correct targets with build presets
# https://github.com/microsoft/vscode-cmake-tools/issues/1872

add_custom_target(solutions)

# Current version of GTest is 1.15.2
# https://github.com/google/googletest/tree/main/googletest

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(BUILD_GTEST ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)
include(GoogleTest)
enable_testing()

# Add all solutions to custom target

set(
    COMMON_HEADER_FILES
    "${CMAKE_SOURCE_DIR}/include/warnings.hpp"
)

LIST_CHILD_DIRECTORIES(
    SOLUTION_DIRS
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/problems"
)

foreach(SOLUTION_DIR ${SOLUTION_DIRS})
    add_subdirectory("${SOLUTION_DIR}")
endforeach()

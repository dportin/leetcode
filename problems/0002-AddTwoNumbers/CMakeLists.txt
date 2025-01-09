cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

project(
    AddTwoNumbers
    VERSION 1.0.0.0
    DESCRIPTION "Add Two Numbers"
    HOMEPAGE_URL "https://github.com/dportin/leetcode-solutions"
    LANGUAGES "CXX"
)

set(
    SOLUTION_SOURCE_FILES
    "${CMAKE_CURRENT_LIST_DIR}/src/solution_default.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/src/solution_test.cpp"
)

set(
    SOLUTION_HEADER_FILES
    "${CMAKE_CURRENT_LIST_DIR}/include/solution_base.hpp"
    "${CMAKE_CURRENT_LIST_DIR}/include/solution_test.hpp"
)

message("PROJECT_NAME = ${PROJECT_NAME}")

ADD_SOLUTIONS("${PROJECT_NAME}" SOLUTION_SOURCE_FILES SOLUTION_HEADER_FILES)

cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

# Add group of solutions and register tests with Google Test

macro(ADD_SOLUTIONS SOLUTION_TARGET SOLUTION_SOURCES SOLUTION_HEADERS)

  add_executable("${SOLUTION_TARGET}" ${${SOLUTION_SOURCES}} ${${SOLUTION_HEADERS}})
  add_dependencies(solutions "${SOLUTION_TARGET}")
  target_link_libraries("${SOLUTION_TARGET}" gtest)
  target_include_directories("${SOLUTION_TARGET}" PRIVATE ${CMAKE_SOURCE_DIR}/include ${CMAKE_CURRENT_LIST_DIR}/include ${googletest_SOURCE_DIR}/googletest/include/gtest)  
  gtest_discover_tests("${SOLUTION_TARGET}")

endmacro()

# Collect solution directories into list with correct relative paths

macro(LIST_CHILD_DIRECTORIES RESULT_DIRS RELATIVE_DIR PARENT_DIR)

  file(GLOB CHILD_DIRS RELATIVE ${RELATIVE_DIR} ${PARENT_DIR}/*)
  set(TEMP_CHILD_DIRS "")
  foreach(CHILD_DIR ${CHILD_DIRS})
    if(IS_DIRECTORY ${RELATIVE_DIR}/${CHILD_DIR})
      list(APPEND TEMP_CHILD_DIRS ${CHILD_DIR})
    endif()
  endforeach()
  set(${RESULT_DIRS} ${TEMP_CHILD_DIRS})

endmacro()

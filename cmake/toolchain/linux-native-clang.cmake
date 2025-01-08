cmake_minimum_required(VERSION 3.25.0 FATAL_ERROR)

# Default LLVM/Clang version

set(LLVM_VERSION 19 CACHE STRING "LLVM/Clang Version")

# Toolchain file for native compilation with LLVM/Clang

set(CMAKE_SYSTEM_NAME "${CMAKE_HOST_SYSTEM_NAME}")
set(CMAKE_SYSTEM_VERSION "${CMAKE_HOST_SYSTEM_VERSION}")
set(CMAKE_SYSTEM_PROCESSOR "${CMAKE_HOST_SYSTEM_PROCESSOR}")

# Find LLVM/Clang install directory

find_path(
    LLVM_INSTALL_DIR bin/clang
    PATHS "/usr/lib/llvm-${LLVM_VERSION}" # Debian
          "/usr"                          # Fedora
          "/usr/local"                    # User
    DOC "LLVM/Clang Install Directory"
    NO_DEFAULT_PATH
    REQUIRED
)

set(LLVM_BINARY_DIR "${LLVM_INSTALL_DIR}/bin" CACHE PATH "Clang/LLVM Binary Directory")
set(LLVM_LIBRARY_DIR "${LLVM_INSTALL_DIR}/lib" CACHE PATH "Clang/LLVM Library Directory")

# Use symbolic links in LLVM/Clang binary directory

set(CMAKE_C_COMPILER "${LLVM_BINARY_DIR}/clang")
set(CMAKE_ASM_COMPILER "${LLVM_BINARY_DIR}/clang")
set(CMAKE_CXX_COMPILER "${LLVM_BINARY_DIR}/clang++")

set(CMAKE_FLAGS_WARNING_COMMON "-Wno-logical-op-parentheses")
set(CMAKE_FLAGS_COMMON "-Wall -Wextra ${CMAKE_FLAGS_WARNING_COMMON}")

set(CMAKE_C_FLAGS_DEBUG_INIT "${CMAKE_FLAGS_COMMON} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "${CMAKE_FLAGS_COMMON} -g -O0")

set(CMAKE_C_FLAGS_RELEASE_INIT "${CMAKE_FLAGS_COMMON} -O2 -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELEASE_INIT "${CMAKE_FLAGS_COMMON} -O2 -DNDEBUG")

set(CMAKE_C_FLAGS_RELWITHDEBINFO_INIT "${CMAKE_FLAGS_COMMON} -O2 -g -DNDEBUG")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO_INIT "${CMAKE_FLAGS_COMMON} -O2 -g -DNDEBUG")

set(CMAKE_C_FLAGS_MINSIZEREL_INIT "${CMAKE_FLAGS_COMMON} -Os -DNDEBUG")
set(CMAKE_CXX_FLAGS_MINSIZEREL_INIT "${CMAKE_FLAGS_COMMON} -Os -DNDEBUG")
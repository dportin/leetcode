# LeetCode Solutions

## Dependencies

Requires LLVM/Clang 19 and GNU Make or Ninja.

## Quick Start

Run `cmake --list-presets` to list the available CMake presets. Then run

    cmake -S . --preset $PRESET
    cmake --build --preset $PRESET
    ctest --preset $PRESET

to build and run all solutions.

## Dockerfile

    docker build --no-cache --tag leetcode

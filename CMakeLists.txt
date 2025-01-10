# How to use:
#   cmake -S . -B build
#   cd build
#   make

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")

project(
  CSVFormatting
  VERSION 1.0
  LANGUAGES CXX C
)

find_package(Threads REQUIRED)

add_executable(csvFormatting
    tools/csvFormatting.cpp
    tools/csvFormatting.hpp
)

target_include_directories(csvFormatting
  PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/tools"
)

target_link_libraries(csvFormatting
  PRIVATE
    Threads::Threads
    # Add other libraries if needed
)

target_compile_options(csvFormatting
  PRIVATE
    -Wall -Wextra -pedantic -g -O2
)

set_target_properties(csvFormatting
  PROPERTIES
    CXX_STANDARD 17
    CXX_EXTENSIONS OFF
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
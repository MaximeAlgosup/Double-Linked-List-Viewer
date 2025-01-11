# How to use:
# cmake -S . -B build
# cd build
# make

cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "g++")

project(
  ActressSortingProject
  VERSION 1.0
  LANGUAGES CXX
)

find_package(Threads REQUIRED)

add_executable(csvFormatting
  tools/csvFormatting.cpp
)

target_include_directories(csvFormatting
  PRIVATE
  "${CMAKE_CURRENT_SOURCE_DIR}/tools"
)

target_link_libraries(csvFormatting
  PRIVATE
  Threads::Threads
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

add_executable(actressSorting
  "${CMAKE_CURRENT_SOURCE_DIR}/src/doubleLinkedList/list.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/doubleLinkedList/listNode.cpp"
  "${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp"
)

target_include_directories(actressSorting
  PRIVATE
  src/doubleLinkedList
  src
)

target_compile_options(actressSorting
  PRIVATE
  -Wall -Wextra -pedantic -g -O2
)

set_target_properties(actressSorting
  PROPERTIES
  CXX_STANDARD 17
  CXX_EXTENSIONS OFF
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
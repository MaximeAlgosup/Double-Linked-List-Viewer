# Double-Linked-List-Viewer
This workshop serve as training with OOP and data sorting algorithm with C++.

## What you gonna find in this project?
- A data set of actreeses (somthing like 5000 elements)
- A tool to format and merge csv files (available in the `tools` folder)
- A tool to sort data in a double linked list (available in the `src` folder)

## Prerequisites
- g++ compiler
- CMake (3.10 or higher)
- Make
- Git

## How to initiate the project?
1. Clone this repository
2. Run: 
```bash
$ cmake -S . -B build
$ cd build
$ make
```
This will build the project and create an executable file called `actressSorting` and `csvFormatting` in the `bin` folder.

## Good to know
In the `actressSorting` tool, you will find 3 various sorting algorithms:
- A **Merge Sort** algorithm for the ranking sorting
- A **Quick Sort** algorithm for the videos number sorting
- A **Heap Sort** algorithm for the number of views sorting
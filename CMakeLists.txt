cmake_minimum_required(VERSION 3.21)
project(SDIZO)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDIZO main.cpp List.cpp List.h Array.cpp Array.h Heap.cpp Heap.h BinarySearchTree.cpp BinarySearchTree.h Timer.cpp Timer.h TestMenu.cpp TestMenu.h)

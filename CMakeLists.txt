cmake_minimum_required(VERSION 3.9)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled main.cpp Graph/BinarySearchTree.h Graph/Node.h Interfaces/Comparable.h Interfaces/Printable.h Integer.h)
cmake_minimum_required(VERSION 3.17)
project(Oving4)

set(CMAKE_CXX_STANDARD 17)
find_package(gtk REQUIRED)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(Oving4 main.cpp Part1.h Part2.h)


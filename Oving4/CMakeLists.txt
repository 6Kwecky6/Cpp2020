cmake_minimum_required(VERSION 3.13)
project(Oving4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall -Wextra -Wno-unused-parameter")


INCLUDE(FindPkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0 REQUIRED)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})
add_executable(Oving4 main.cpp Part1.h Part2.h)
target_link_libraries(Oving4 ${GTKMM_LIBRARIES})

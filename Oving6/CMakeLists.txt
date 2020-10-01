cmake_minimum_required(VERSION 3.13)
project(Oving6)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -pthread -lboost_system -DBOOST_SYSTEM_NO_DEPRECATED")

find_package(Boost 1.55.0 REQUIRED COMPONENTS system filesystem)
include_directories(Oving6 ${Boost_INCLUDE_DIRS})
link_directories(Oving6 ${Boost_LIBRARY_DIRS})


add_executable(Oving6 main.cpp DrawBoard.h ChessBoard.h SimpleConnectionHandler.h ${Boost_INCLUDE_DIR})

target_link_libraries(Oving6 ${Boost_LIBRARIES})

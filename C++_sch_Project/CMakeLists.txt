cmake_minimum_required(VERSION 3.24)
project(C___sch_Project)

set(CMAKE_CXX_STANDARD 17)

add_executable(C___sch_Project main.cpp)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries(C___sch_Project ${CURSES_LIBRARIES})

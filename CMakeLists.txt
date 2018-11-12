cmake_minimum_required(VERSION 3.12)
project(timber_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(timber_tutorial main.cpp)
target_link_libraries (timber_tutorial sfml-graphics sfml-window sfml-system)
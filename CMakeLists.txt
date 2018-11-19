cmake_minimum_required(VERSION 3.12)
project(cpp-game-tutorials)

set(CMAKE_CXX_STANDARD 14)

add_executable(timber timber.cpp)
target_link_libraries (timber sfml-graphics sfml-audio sfml-window sfml-system)

add_executable(zombie zombie.cpp Player.cpp Player.h)
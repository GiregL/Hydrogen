cmake_minimum_required(VERSION 3.15)
project(Hydrogen)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hydrogen main.cpp Command.cpp Command.h)
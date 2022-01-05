cmake_minimum_required(VERSION 3.17)
project(pi C)

set(CMAKE_C_STANDARD 99)

add_executable(pi main.c list.c list.h unsigned.c unsigned.h big_int.c big_int.h rational.c rational.h)
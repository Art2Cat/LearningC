cmake_minimum_required(VERSION 3.4)

project(aatree)

set(CMAKE_C_STANDARD_REQUIRED 11)

# aux_source_directory(. DIR_SRCS)

add_executable(aatree testaa.c aatree.c)

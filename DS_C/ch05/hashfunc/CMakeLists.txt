
cmake_minimum_required(VERSION 3.4)

project(hashfunc)

set(CMAKE_C_STANDARD_REQUIRED 11)

# aux_source_directory(. DIR_SRCS)

add_executable(hashfunc testhashfunc.c hashfunc.c)

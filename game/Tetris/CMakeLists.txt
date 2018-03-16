cmake_minimum_required(VERSION 2.8)

project(Tetris)

set(CMAKE_C_STANDARD_REQUIRED 11)

#set_property(TARGET tgt PROPERTY C_STANDARD 11)
set (CMAKE_C_STANDARD 11)

message(STATUS "Project: Teris")
message(STATUS "Project Directory: ${PROJECT_SOURCE_DIR}")



aux_source_directory(src DIR_SRCS)	

set(TEST_TETRIS ${DIR_SRCS})

add_executable(${PROJECT_NAME} ${TEST_TETRIS})

target_link_libraries(${PROJECT_NAME} m)

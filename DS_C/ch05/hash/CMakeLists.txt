
cmake_minimum_required(VERSION 3.4)

project(hash)

set(CMAKE_C_STANDARD_REQUIRED 11)

aux_source_directory(. DIR_SRCS)

# 添加 math 子目录
add_subdirectory(hashsep)
add_subdirectory(hashquad)

# 指定生成目标
add_executable(hash ${DIR_SRCS})

# 添加链接库
target_link_libraries(hash Hashsep)

target_link_libraries(hash Hashquad)

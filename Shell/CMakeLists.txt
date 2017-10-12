cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

project(Shell)

add_executable(
 Shell
 main.c 
 ShellController.c
 command_parser.c 
 command_utils.c
 commands.c
 environment.c
 file_service.c
 logger.c
 tokenizer.c
 variables.c )

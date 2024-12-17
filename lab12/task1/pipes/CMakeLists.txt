# Задание: Создать библиотеку pipes из read_pipe.c write_pipe.c

cmake_minimum_required(VERSION 3.5.0) 
project(pipes VERSION 0.1.0 LANGUAGES C)

set(SOURCE_FILES read_pipe.c write_pipe.c)
set(HEADER_FILES pipes.h)

add_library(pipes STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(pipes PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) 
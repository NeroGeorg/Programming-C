# Задание: Создать библиотеку из background.c и слинковать ее с библиотекой pipes

cmake_minimum_required(VERSION 3.5.0)
project(background VERSION 0.1.0 LANGUAGES C)

set(SOURCE_FILES background.c)
set(HEADER_FILES background.h)
add_library(background STATIC ${HEADER_FILES} ${SOURCE_FILES})

target_include_directories(background PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(background PRIVATE pipes)
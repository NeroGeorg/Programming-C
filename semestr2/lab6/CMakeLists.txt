# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(Lab6)

# Опция для выбора типа библиотеки
option(BUILD_SHARED_LIBS "Build shared library instead of static" OFF)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Директории с заголовками
include_directories(include)

# Создаем библиотеку
add_library(train_lib 
    src/train.c
)

# Главная программа
add_executable(main_program main.c)

# Линкуем библиотеку с программой
target_link_libraries(main_program train_lib)

# Для динамических библиотек: настройка rpath
if(BUILD_SHARED_LIBS)
    set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
    set(CMAKE_INSTALL_RPATH "$ORIGIN")
endif()
# Задание: задать имя проекта и версию cmake, добавить subdirectory для background и pipes, в которых 
# тоже есть свои CMakeLists.txt (внутри них тоже нужно добавить одну-две строки для сборки, задание описано в них же)
# Решить проблему с заголовочными файлами, включив директории в корневом CMakeLists.txt (include_directories)
# Слинковать исполняемый файл из src/main.c с библиотекой background
# Все это дело собрать, используя cmake и make
# Для установки cmake нужно установить его: sudo apt install build-essential cmake -y

cmake_minimum_required(VERSION 3.5.0)
project(task1 VERSION 0.1.0 LANGUAGES C)

include_directories(
    ${CMAKE_SOURCE_DIR}/pipes
    ${CMAKE_SOURCE_DIR}/background
)

add_subdirectory(pipes)
add_subdirectory(background)

add_executable(task1 src/main.c)

target_link_libraries(task1 PRIVATE background pipes)
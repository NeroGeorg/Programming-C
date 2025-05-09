cmake_minimum_required(VERSION 3.10)
project(lab8 VERSION 0.1.0 LANGUAGES C)

include(CTest)

find_package(cmocka REQUIRED)

add_executable(test_cmocka /home/jorik/Документы/Programming-C/semestr2/lab8/tests/test_cmocka.c)

target_link_libraries(test_cmocka cmocka)

add_test(NAME SortingTests COMMAND test_cmocka)
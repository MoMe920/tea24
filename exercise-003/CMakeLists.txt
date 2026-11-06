cmake_minimum_required(VERSION 3.15)
project(exercise-003 LANGUAGES CXX)

# 1. Executable für die Übung anlegen
add_executable(exercise-003 main.cpp)

# 2. Gegen die 'version'-Bibliothek und '{fmt}' linken
target_link_libraries(exercise-003 PRIVATE version fmt)
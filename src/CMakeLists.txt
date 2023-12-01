cmake_minimum_required (VERSION 3.8)

add_library(src STATIC
    Main.cpp
    days/Day1.cpp
    days/Day1.h
    helpers/Reader.cpp
    helpers/Reader.h
)

target_include_directories(src PUBLIC 
                            src)
                            
add_executable (App
    Main.cpp
    days/Day1.cpp
    days/Day1.h
    helpers/Reader.cpp
    helpers/Reader.h
)

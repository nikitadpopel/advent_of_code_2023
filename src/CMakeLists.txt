cmake_minimum_required (VERSION 3.8)

add_library(src STATIC
    Main.cpp
    days/Day1.cpp
    days/Day1.h
    days/Day2.cpp
    days/Day2.h
    days/Day3.cpp
    days/Day3.h
    days/Day4.cpp
    days/Day4.h
    days/Day5.cpp
    days/Day5.h
    helpers/Reader.cpp
    helpers/Reader.h
)

target_include_directories(src PUBLIC 
                            src)
                            
add_executable (App
    Main.cpp
    days/Day1.cpp
    days/Day1.h
    days/Day2.cpp
    days/Day2.h
    days/Day3.cpp
    days/Day3.h
    days/Day4.cpp
    days/Day4.h
    days/Day5.cpp
    days/Day5.h
    helpers/Reader.cpp
    helpers/Reader.h
)

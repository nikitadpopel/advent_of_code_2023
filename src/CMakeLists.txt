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
    days/Day6.cpp
    days/Day6.h
    days/Day7.cpp
    days/Day7.h
    days/Day8.cpp
    days/Day8.h
    days/Day9.cpp
    days/Day9.h
    days/Day10.cpp
    days/Day10.h
    days/Day11.cpp
    days/Day11.h
    days/Day12.cpp
    days/Day12.h
    days/Day13.cpp
    days/Day13.h
    days/Day14.cpp
    days/Day14.h
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
    days/Day6.cpp
    days/Day6.h
    days/Day7.cpp
    days/Day7.h
    days/Day8.cpp
    days/Day8.h
    days/Day9.cpp
    days/Day9.h
    days/Day10.cpp
    days/Day10.h
    days/Day11.cpp
    days/Day11.h
    days/Day12.cpp
    days/Day12.h
    days/Day13.cpp
    days/Day13.h
    days/Day14.cpp
    days/Day14.h
    helpers/Reader.cpp
    helpers/Reader.h
)

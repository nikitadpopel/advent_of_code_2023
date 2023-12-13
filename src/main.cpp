#include <iostream>
#include <string>
#include "days\Day1.h"
#include "days\Day2.h"
#include "days\Day3.h"
#include "days\Day4.h"
#include "days\Day5.h"
#include "days\Day6.h"
#include "days\Day7.h"
#include "days\Day8.h"
#include "days\Day9.h"
#include "days\Day10.h"
#include "days\Day11.h"
#include "days\Day12.h"
#include "days\Day13.h"
#include "days\Day14.h"

int main(int argc,char* argv[])
{
	if(argc <= 1)
	{
		std::cout << "Please pass day as an argument!" << std::endl;
		return 0;
	}
	auto inputarg = static_cast<std::string>(argv[1]);
	if(inputarg == "day1")
	{
		Day1 day = Day1();
		day.Solve();
	}
	if(inputarg == "day2")
	{
		Day2 day = Day2();
		day.Solve();
	}
	if(inputarg == "day3")
	{
		Day3 day = Day3();
		day.Solve();
	}
	if(inputarg == "day4")
	{
		Day4 day = Day4();
		day.Solve();
	}
	if(inputarg == "day5")
	{
		Day5 day = Day5();
		day.Solve();
	}
	if(inputarg == "day6")
	{
		Day6 day = Day6();
		day.Solve();
	}
	if(inputarg == "day7")
	{
		Day7 day = Day7();
		day.Solve();
	}
	if(inputarg == "day8")
	{
		Day8 day = Day8();
		day.Solve();
	}
	if(inputarg == "day9")
	{
		Day9 day = Day9();
		day.Solve();
	}
	if(inputarg == "day10")
	{
		Day10 day = Day10();
		day.Solve();
	}
	if(inputarg == "day11")
	{
		Day11 day = Day11();
		day.Solve();
	}
	if(inputarg == "day12")
	{
		Day12 day = Day12();
		day.Solve();
	}
	if(inputarg == "day13")
	{
		Day13 day = Day13();
		day.Solve();
	}
	if(inputarg == "day14")
	{
		Day14 day = Day14();
		day.Solve();
	}
	else
	{
		std::cout << "Please make sure your day input is correct!" << std::endl;
	}
	return 0;
}

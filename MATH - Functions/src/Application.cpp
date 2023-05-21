#include <iostream>
#include <cmath>
#include <numbers>

#include "Intersect.h"
#include "Extremums.h"


int main()
{
	std::cout << "Intersect: " << intersect([](double x) { return std::exp(x) - std::sin(x); }, 0, 13, 0.001) << std::endl;
	Extremums result = extremums([](double x) { return std::log(x) * std::sin(x); }, 0, 13, 1000);
	std::cin.get();
}
#include <iostream>
#include <cmath>

#include "Intersect.h"
#include "Extremums.h"


int main()
{
	auto intersectFunction = [](double x) { return std::exp(x) - std::sin(x); }; // e^x - sin(x)
	auto extremumsFunction = [](double x) { return std::log(x) * std::sin(x); }; // ln(x) * sin(x)
	
	std::cout << "Intersect: " << intersect(intersectFunction, -5, 0, 0.001) << std::endl;
	std::cout << extremums(extremumsFunction, 0, 15, 1000) << std::endl;
	
	std::cin.get();
}
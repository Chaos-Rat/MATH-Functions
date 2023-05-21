#include <iostream>
#include <cmath>
#include <cstdlib>

#include "Intersect.h"
#include "Extremums.h"


int main()
{
	auto intersectFunction = [](double x) { return std::exp(x) - std::sin(x); }; // insert function to be used with the intersect function here. Current example: e^x - sin(x)
	auto extremumsFunction = [](double x) { return std::log(x) * std::sin(x); }; // insert function to be used with the extremums function here. Current example: ln(x) * sin(x)
	
	std::cout << "Intersect: " << intersect(intersectFunction, -5, 0, 0.001) << std::endl;
	std::cout << extremums(extremumsFunction, 0, 15, 1000) << std::endl;
	
	std::system("pause");
}
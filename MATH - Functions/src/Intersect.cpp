#include "Intersect.h"

double intersect(double(*function)(double x), double a, double b, double error)
{
	if (a > b) // a needs to be < b
	{
		double temp = a;
		a = b;
		b = temp;
	}

	double images[2] = { function(a), function(b) };
	
	if (images[0] * images[1] > 0)
		throw std::invalid_argument("The range extremities have the same sign!");

	if (error <= 0)
		throw std::invalid_argument("The error of the result should be > 0!");

	if (images[0] == 0)
		return a;
	if (images[1] == 0)
		return b;
	
	std::uint64_t iterations = (std::uint32_t)(std::log2((b - a) / (error * 2)) + 1); // magic formula (estimated minimum number of excecutions to get the desired precision)
	std::int8_t monotony = images[0] < 0 ? 1 : -1; // if the first image is negative it means that the function (inside the range) goes from - to + and vice versa

	double c;
	double image;

	for (std::uint32_t i = 0; i < iterations; i++)
	{
		c = a + ((b - a) / 2); // no need for std::abs(a - b) because b is always > a
		image = function(c);

		if (image * monotony < 0) // If the new image is < 0 and if the the function is increasing then the lower extremity has to be subsitituted. If descreasing the opposite happens
			a = c;
		else if (image * monotony > 0)
			b = c;
		else
			return c;
	}

	if (std::abs(function(a)) < std::abs(function(b)))
		return a;

	return b;
}
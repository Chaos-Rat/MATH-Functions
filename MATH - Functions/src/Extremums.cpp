#include "Extremums.h"

std::ostream& operator<<(std::ostream& stream, const Extremums& extremums)
{
	stream << "Max: " << extremums.max << ", Min: " << extremums.min;
	return stream;
}

Extremums extremums(double(*function)(double x), double a, double b, std::uint64_t samples)
{
	if (a > b)
		throw std::invalid_argument("Invalid range: the left hand side is greater than the right one!");
	if (samples == 0)
		throw std::invalid_argument("The number of samples needs to be > 0!");

	if (a == b)
	{
		double image = function(a);
		return { image, image };
	}

	double step = (b - a) / samples;
	double image;
	double max = std::numeric_limits<double>::lowest(), min = std::numeric_limits<double>::max();

	for (std::uint64_t i = 0; i < samples + 1; i++) // + 1 for the right side of the range (since we start from 0)
	{
		image = function(a);

		if (image > max)
			max = image;
		if (image < min)
			min = image;

		a += step;
	}

	return { max, min };
}
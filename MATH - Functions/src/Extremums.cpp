#include "Extremums.h"

std::ostream& operator<<(std::ostream& stream, const Extremums& extremums)
{
	stream << "Max: " << extremums.max << ", Min: " << extremums.min;
	return stream;
}

Extremums extremums(double(*function)(double x), double a, double b, std::uint64_t samples)
{
	if (samples == 0)
		throw std::invalid_argument("The number of samples needs to be > 0!");

	double max = std::numeric_limits<double>::max(), min = std::numeric_limits<double>::lowest();

	if (a == b)
	{
		double image = function(a);
		return Extremums(image, image);
	}

	if (a > b)
	{
		double temp = a;
		a = b;
		b = temp;
	}

	double step = b - a;

	for (std::uint64_t i = 0; i < samples; i++)
	{
		+
	}
}
#pragma once

#include <ostream>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <cmath>

struct Extremums
{
	double max, min;

	Extremums(double max, double min)
		: max(max), min(min) {}

	Extremums(const Extremums& other)
		: max(other.max), min(other.min) {}
};

std::ostream& operator<<(std::ostream& stream, const Extremums& extremums);

Extremums extremums(double(*function)(double x), double a, double b, std::uint64_t samples);
#pragma once

#include <ostream>
#include <cstdint>
#include <limits>
#include <stdexcept>
#include <cmath>

/// <summary>
/// Extremums structure. Holds two members of type double: max and min. Used as return type for the <c>extremums</c> function.
/// </summary>
struct Extremums
{
	double max, min;
};

/// <summary>
/// Overload for <c>Extremums</c> objects. Allows such objects to be output to an <c>std::ostream</c>.
/// </summary>
/// <param name="stream">Instance of the stream to output to.</param>
/// <param name="extremums"><c>Extremums</c> instance to be output.</param>
/// <returns>Reference to the <paramref name="stream"/> instance to which the <paramref name="extremums"/> instance has been output to.</returns>
std::ostream& operator<<(std::ostream& stream, const Extremums& extremums);

/// <summary>
/// Finds the maximum and minimum extremums of the given function, given a range [a, b] in which to search, and the number of samples to take.
/// </summary>
/// <param name="function">The function of which to find the extremums.</param>
/// <param name="a">Left side of the [a, b] search range.</param>
/// <param name="b">
/// Right side of the [a, b] search range. Note that the real image of this side might not be considered,
/// as the calculation of the step might generate a close (but not perfect) approximation, which might add up to a small, but present, relative error.
/// </param>
/// <param name="samples">Number of equidistant samples to take from the [a, b] search range, + 1 (since it includes the left side of the range).</param>
/// <returns>An <c>Extremums</c> object containing the found maximum and minimum extremums.</returns>
/// <exception cref="std::invalid_argument">
/// If the left hand side of the [a, b] search range is &gt; the right side, or if the samples are = to 0.
/// </exception>
Extremums extremums(double(*function)(double x), double a, double b, std::uint64_t samples);
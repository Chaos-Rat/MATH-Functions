#pragma once

#include <cmath>
#include <stdexcept>
#include <cstdint>

/// <summary>
/// Finds one x coordinate of the given function which results in an intersection with the x axis (y = 0), given a range [a, b] in which to search, and an absolute error for the result.
/// </summary>
/// <param name="function">The function of which to find the intersection with the x axis (y = 0).</param>
/// <param name="a">Left side of the [a, b] search range.</param>
/// <param name="b">Right side of the [a, b] search range.</param>
/// <param name="error">Absolute error of the result (result ± error).</param>
/// <returns>The x coordinate found, ± the error given.</returns>
/// <exception cref="std::invalid_argument">
/// If left hand side of the search range is &gt; the right one, if the images of the sides of the search range have the same sign,
/// or if the absolute error is &lt;= 0
/// </exception>
double intersect(double(*function)(double x), double a, double b, double error);
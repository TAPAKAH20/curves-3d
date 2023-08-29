#pragma once
#define _USE_MATH_DEFINES
#include <cmath>
#include <array>

class Curve3
{
public:
	virtual std::array<double, 3> point(double t) = 0;
	virtual std::array<double, 3> der1(double t) = 0;
	virtual std::array<double, 2> get_params() = 0;
};


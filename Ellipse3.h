#pragma once
#include "Curve3.h"
class Ellipse3 :
	public Curve3
{
public:
	double radiusX;
	double radiusY;

	Ellipse3(double rx, double ry);
	~Ellipse3();

	std::array<double, 3> point(double t);
	std::array<double, 3> der1(double t);
	std::array<double, 2> get_params();
};

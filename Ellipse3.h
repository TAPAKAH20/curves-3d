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

	Vector3 point(double t);
	Vector3 der1(double t);
};

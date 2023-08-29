#include "Ellipse3.h"

Ellipse3::Ellipse3(double rx, double ry)
{
	this->radiusX = (rx > 0) ? rx : 1.0f;
	this->radiusY = (ry > 0) ? ry : 1.0f;
}

Ellipse3::~Ellipse3()
{
}

std::array<double, 3> Ellipse3::point(double t)
{
	std::array<double, 3> p;
	p[0] = this->radiusX * cos(t);
	p[1] = this->radiusY * sin(t);
	p[2] = 0.0f;
	return p;
}

std::array<double, 3> Ellipse3::der1(double t)
{
	std::array<double, 3> p;
	p[0] = this->radiusX * -sin(t);
	p[1] = this->radiusY * cos(t);
	p[2] = 0.0f;
	return p;
}

std::array<double, 2> Ellipse3::get_params()
{
	return std::array<double, 2>{this->radiusX, this->radiusY};
}
#include "Circle3.h"

Circle3::Circle3(double r)
{
	this->radius = (r > 0) ? r : 1.0f;
}

Circle3::~Circle3()
{
}

std::array<double, 3> Circle3::point(double t)
{
	std::array<double, 3> p;
	p[0] = this->radius * cos(t);
	p[1] = this->radius * sin(t);
	p[2] = 0.0f;
	return p;
}

std::array<double, 3> Circle3::der1(double t)
{
	std::array<double, 3> p;
	p[0] = this->radius * -sin(t);
	p[1] = this->radius * cos(t);
	p[2] = 0.0f;
	return p;
}

std::array<double, 2> Circle3::get_params()
{
	return std::array<double, 2>{this->radius, 0.0f};
}

#include "Helix.h"

Helix::Helix(double r, double st)
{
	this->radius = (r > 0) ? r : 1.0f;
	this->step = st;
}

Helix::~Helix()
{
}

std::array<double, 3>  Helix::point(double t)
{
	std::array<double, 3>  p;
	p[0] = this->radius * cos(t);
	p[1] = this->radius * sin(t);
	p[2] = t*this->step / M_2_PI;
	return p;
}

std::array<double, 3>  Helix::der1(double t)
{
	std::array<double, 3>  p;
	p[0] = this->radius * -sin(t);
	p[1] = this->radius * cos(t);
	p[2] = this->step / M_2_PI;
	return p;
}

std::array<double, 2> Helix::get_params()
{
	return std::array<double, 2>{this->radius, this->step};
}
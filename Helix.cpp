#include "Helix.h"

Helix::Helix(double r, double st)
{
	this->radius = (r > 0) ? r : 1.0f;
	this->step = st;
}

Helix::~Helix()
{
}

Vector3 Helix::point(double t)
{
	Vector3 p;
	p.x = this->radius * cos(t);
	p.y = this->radius * sin(t);
	p.z = t*this->step / M_2_PI;
	return p;
}

Vector3 Helix::der1(double t)
{
	Vector3 p;
	p.x = this->radius * -sin(t);
	p.y = this->radius * cos(t);
	p.z = this->step / M_2_PI;
	return p;
}

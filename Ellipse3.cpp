#include "Ellipse3.h"

Ellipse3::Ellipse3(double rx, double ry)
{
	this->radiusX = (rx > 0) ? rx : 1.0f;
	this->radiusY = (ry > 0) ? ry : 1.0f;
}

Ellipse3::~Ellipse3()
{
}

Vector3 Ellipse3::point(double t)
{
	Vector3 p;
	p.x = this->radiusX * cos(t);
	p.y = this->radiusY * sin(t);
	p.z = 0.0f;
	return p;
}

Vector3 Ellipse3::der1(double t)
{
	Vector3 p;
	p.x = this->radiusX * -sin(t);
	p.y = this->radiusY * cos(t);
	p.z = 0.0f;
	return p;
}

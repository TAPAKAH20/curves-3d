#include "Circle3.h"

Circle3::Circle3(double r)
{
	this->radius = (r > 0) ? r : 1.0f;
}

Circle3::~Circle3()
{
}

Vector3 Circle3::point(double t)
{
	Vector3 p;
	p.x = this->radius * cos(t);
	p.y = this->radius * sin(t);
	p.z = 0.0f;
	return p;
}

Vector3 Circle3::der1(double t)
{
	Vector3 p;
	p.x = this->radius * -sin(t);
	p.y = this->radius * cos(t);
	p.z = 0.0f;
	return p;
}

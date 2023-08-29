#pragma once
#include "TypeStructs.h"

#define _USE_MATH_DEFINES
#include <cmath>

class Curve3
{
public:
	virtual Vector3 point(double t) = 0;
	virtual Vector3 der1(double t) = 0;
};


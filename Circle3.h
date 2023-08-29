#pragma once
#include "Curve3.h"
class Circle3 :
    public Curve3
{
public:
    double radius;

    Circle3(double r);
    ~Circle3();

    Vector3 point(double t);
    Vector3 der1(double t);
};


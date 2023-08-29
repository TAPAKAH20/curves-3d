#pragma once
#include "Curve3.h"
class Helix :
    public Curve3
{
public:
    double radius;
    double step;

    Helix(double r, double st);
    ~Helix();

    Vector3 point(double t);
    Vector3 der1(double t);
};


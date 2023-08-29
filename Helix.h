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

    std::array<double, 3> point(double t);
    std::array<double, 3> der1(double t);
    std::array<double, 2> get_params();
};


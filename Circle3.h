#pragma once
#include "Curve3.h"
#include <array>
class Circle3 :
    public Curve3
{
public:
    double radius;

    Circle3(double r);
    ~Circle3();

    std::array<double, 3> point(double t);
    std::array<double, 3> der1(double t);
    std::array<double, 2> get_params();
};


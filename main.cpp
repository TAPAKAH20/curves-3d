#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>
#include <array>
#include <vector>
#include <memory>


#include "Curve3.h"
#include "Circle3.h"
#include "Ellipse3.h"
#include "Helix.h"

//Random float number in range [0, max]
double rand_float(int max) {
	float fl = (double)rand() / (double)(RAND_MAX);
	return (double)(max)*fl;
}

int main(int argc, char* argv[]) {

	srand(time(NULL));

	const unsigned int n = 5;
	std::array<std::unique_ptr<Curve3>,n> arr1;

	//Curve parameters restrictions
	const double min_rad = 0.0f;
	const int max_rad = 100;
	const double min_step = 0.0f;
	const int max_step = 100;

	//Populate the first array with random curves
	for (int i = 0; i < n; i++) {
		switch (rand() % 3) {
			case 0:
				arr1[i].reset(new Circle3(min_rad + rand_float(max_rad)));
				break;
			case 1:
				arr1[i].reset(new Ellipse3(min_rad + rand_float(max_rad), min_rad + rand_float(max_rad)));
				break;
			case 2:
				arr1[i].reset(new Helix(min_rad + rand_float(max_rad), min_step + rand_float(max_step)));
				break;
		}
	}


	//Print points and derivatives at t=PI/4
	for (int i = 0; i < n; i++) {
		std::array<double, 3>  point, derivative;
		double t = M_PI_4;
		
		point = arr1[i]->point(t);
		derivative = arr1[i]->der1(t);


		std::printf("%d\t%.6lf\t%.6lf\t%.6lf\n"
					"  \t%.6lf\t%.6lf\t%.6lf\n",
					 i, point[0], point[1], point[2],
						derivative[0], derivative[1], derivative[2]);
	}
	

	//Extract all circles
	std::vector<Circle3*> circles;

	for (int i = 0; i < n; i++) {
		std::array<double, 2> curve_params;
		curve_params = arr1[i]->get_params();

		if (curve_params[1] == 0) {
			circles.push_back(dynamic_cast<Circle3*> (arr1[i].get()));
		}
	}


	//Sort the circles in the ascending order
	std::sort(circles.begin(), circles.end(),
		//Lambda comparator funcion	
		[](Circle3* a, Circle3* b) {
			return a->radius < b->radius;
		}	
	);

	//Calculate and print cummulative sum of radii
	double radii_sum = 0.0f;
	for (int i = 0; i < circles.size(); i++) {
		radii_sum += circles[i]->radius;
	}
	std::printf("\n\n%.6lf", radii_sum);

	std::getchar();
	return 0;
}
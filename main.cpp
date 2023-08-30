#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <random>
#include <time.h>
#include <algorithm>
#include <array>
#include <vector>
#include <memory>

#include <omp.h>


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

	unsigned int n = 5;
	std::printf("Number of curves to create: ");
	std::scanf("%d", &n);
	std::printf("\n");


	std::vector<std::unique_ptr<Curve3>> curves(n);

	//Curve parameters restrictions
	const double min_rad = 0.0f;
	const int max_rad = 100;
	const double min_step = 0.0f;
	const int max_step = 100;

	//Populate the first array with random curves
	for (int i = 0; i < n; i++) {
		switch (rand() % 3) {
			case 0:
				curves[i] = (std::make_unique<Circle3>(min_rad + rand_float(max_rad)));
				break;
			case 1:
				curves[i] = (std::make_unique <Ellipse3>(min_rad + rand_float(max_rad), min_rad + rand_float(max_rad)));
				break;
			case 2:
				curves[i] = (std::make_unique <Helix>(min_rad + rand_float(max_rad), min_step + rand_float(max_step)));
				break;
		}
	}


	//Print points and derivatives at t=PI/4
	for (int i = 0; i < n; i++) {
		std::array<double, 3>  point, derivative;
		double t = M_PI_4;
		
		point = curves[i]->point(t);
		derivative = curves[i]->der1(t);


		std::printf("%d\t%.6lf\t%.6lf\t%.6lf\n"
					"  \t%.6lf\t%.6lf\t%.6lf\n",
					 i, point[0], point[1], point[2],
						derivative[0], derivative[1], derivative[2]);
	}
	

	//Extract all circles
	std::vector<Circle3*> circles;

	for (int i = 0; i < n; i++) {
		std::array<double, 2> curve_params;
		curve_params = curves[i]->get_params();

		if (curve_params[1] == 0) {
			circles.push_back(dynamic_cast<Circle3*> (curves[i].get()));
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
	double sum = 0.0f;
	#pragma omp parallel for reduction(+ : sum)
	for (int i = 0; i < circles.size(); i++) {
		sum += circles[i]->radius;
	}
	std::printf("\n\n%.6lf", sum);

	return 0;
}
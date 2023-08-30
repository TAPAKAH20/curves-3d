# curves-3d
Test task v4 for CADEX.

## Build using Microsoft Visual Studio

## Program
All curves are generated with random parameters [0, 100]. If radius is <= 0 then curve is defaulted to the radius of 1.0.
STD vector of `n` unique pointers to randomly generated curves is used to eliminate the need for manual memory deallocation.
Circles are extracted the vector of simple pointers using the fact that `get_params` function returns `(radius, 0)` for circles.
Then the second vector is sorted with `std::sort` using a lambda function as a comparator.
The sum of radii is calculated using `#pragma omp parallel`.

## Input
A single integer that specifies number of curves to generate is a requred input. 

## Output
Standart output, no pause on completion.
For each curve its inedex and x,y and z coordinates at t= PI/4 outputted on the first row and x,y and z derivatives on the second row. The last row is the sum of radii of the circles.


## Task list (from the assignment description)
### Basic tasks
- [x] Support a few types of 3D geometric curves – circles, ellipses and 3D helixes.
- [x] Populate a container (vector) of objects of these types created in random manner with random parameters.
- [x] Print coordinates of points and derivatives of all curves in the container at t=PI/4.
- [x] Populate a second container that would contain only circles from the first container. Make sure the second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
- [x] Sort the second container in the ascending order of circles’ radii.
- [x] Compute the total sum of radii of all curves in the second container.
### Additional optional requirements:
- [ ] Split implementation into a library of curves (.dll or .so) and executable which uses API of this library.
- [x] Implement computation of the total sum of radii using parallel computations (OpenMP).

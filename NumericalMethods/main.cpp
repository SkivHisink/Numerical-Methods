#include <iostream>
#include <math.h>
#include <functional>
#include "Newton_method.h"
#include  "Chord_method.h"

double cube(double x)
{
	return powl(x, 3.0);
}

double derative_of_cube(double x)
{
	return 3 * powl(x, 2.0);
}

int main()
{
	double a, b;
	double precision;

	std::cin >> a >> b >> precision;

	const std::function<double(double)> func = cube;
	std::function<double(double)> derative = derative_of_cube;
	Newton_method newton(a, b, precision, func, derative);
	Chord_method chord(a, b, precision, func);
	std::cout << "Newton method solution is " << newton.solve() << std::endl;
	std::cout << "Chord method solution is " << chord.solve() << std::endl;
	return 0;
}
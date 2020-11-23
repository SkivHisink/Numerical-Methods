#include <iostream>
#include <math.h>
#include <functional>
#include "Newton_method.h"
#include  "Sectant_method.h"

const double value_of_function_in_x(double x)
{
	return powl(x, 3.0);
}

const double value_of_derative_in_x(double x)
{
	return 3 * powl(x, 2.0);
}

int main()
{
	double a, b;
	double precision;

	std::cin >> a >> b >> precision;

	const std::function<double(double)> func = value_of_function_in_x;
	std::function<double(double)> derative = value_of_derative_in_x;
	Newton_method newton(a, b, precision, func, derative);
	Sectant_method sectant(a, b, precision, func);
	newton.solve();
	sectant.solve();
	std::cout << "Newton method solution is " << newton.get_result() << std::endl;
	std::cout << "Sectant method solution is " << sectant.get_result() << std::endl;
	return 0;
}
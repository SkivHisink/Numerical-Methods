#include "Newton_method.h"
#include "NullPointerFunctionException.h"
const double Newton_method::give_random_number_from_interval(double left_boundary_, double right_boundary_)
{
	std::uniform_real_distribution<double> dist(left_boundary_, right_boundary_);
	return dist(rand_engine);
}

void Newton_method::checkingFunctionExisting()
{
	if (function == nullptr || derivative == nullptr) {
		throw NullPointerFunctionException();
	}
}

double Newton_method::solvingMethod(double& prev_res)
{
	double g = derivative(result);
	if (g == 0.0) {
		result = give_random_number_from_interval(left_boundary, right_boundary);
		prev_res = -result;
		return result;
	}
	return (result - function(result) / g);
}

double Newton_method::res_initial_value()
{
	return give_random_number_from_interval(left_boundary, right_boundary);
}


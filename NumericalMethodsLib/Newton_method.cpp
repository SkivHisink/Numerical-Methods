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

double Newton_method::solvingMethod()
{
	double x_ = give_random_number_from_interval(left_boundary, right_boundary);
	double prev_x_ = x_;
	double f = function(x_);
	for (size_t i = 0; i < number_of_iteration; ++i) {
		double g = derivative(x_);
		if (g == 0.0) {
			x_ = give_random_number_from_interval(left_boundary, right_boundary);
			prev_x_ = x_;
			f = function(x_);
			continue;
		}
		x_ = x_ - f / g;
		if (abs(x_ - prev_x_) < precision) {
			break;
		}
		f = function(x_);
		prev_x_ = x_;
	}
	return x_;
}



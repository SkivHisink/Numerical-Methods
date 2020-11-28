#include "Newton_method.h"


bool Newton_method::is_valid()
{
	if (left_boundary > right_boundary || precision > 1 || precision < 0 ||
		left_boundary == right_boundary || function == nullptr || derivative == nullptr) {
		return false;
	}
	return true;
}

double Newton_method::get_next_value(double current)
{
	double x = current;
	double g = derivative(x);
	if (g == 0.0) {
		x = middle_of_interval(left_boundary, right_boundary);
		return x;
	}
	return (x - function(x) / g);
}
double Newton_method::middle_of_interval(const double left_boundary_, const double right_boundary_)
{
	split_ratio += 2;
	return  right_boundary_ - (right_boundary_ - left_boundary_) / split_ratio;
}

double Newton_method::get_initial_value()
{
	return middle_of_interval(left_boundary, right_boundary);
}


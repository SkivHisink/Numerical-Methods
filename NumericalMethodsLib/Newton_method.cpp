#include "Newton_method.h"
#include "NullPointerFunctionException.h"

void Newton_method::solve(const double left_boundary, const double right_boundary,
	const double precision, const std::function<double(double)> function,
	const std::function<double(double)> derivative)
{
	if (!initial_conditions_is_verified(left_boundary, right_boundary, precision)) {
		return;
	}
	if (function == nullptr || derivative == nullptr) {
		throw NullPointerFunctionException();
	}
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
	result = x_;
}
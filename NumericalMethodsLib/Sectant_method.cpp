#include "Sectant_method.h"
#include "NullPointerFunctionException.h"

void Sectant_method::solve(const double left_boundary, const double right_boundary,
	const double precision, const std::function<double(double)> function,
	const std::function<double(double)> derivative)
{
	if (!initial_conditions_is_verified(left_boundary, right_boundary, precision)) {
		return;
	}
	if (function == nullptr) {
		throw NullPointerFunctionException();
	}
	double left = left_boundary;
	double right = right_boundary;
	for (size_t i = 0; i < number_of_iteration; ++i) {
		if (fabs(right - left) < precision) {
			break;
		}
		left = new_value_of_border(right, left, function);
		right = new_value_of_border(right, left, function);
	}
	result = right;
}
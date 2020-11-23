#include "Sectant_method.h"
#include "NullPointerFunctionException.h"

void Sectant_method::checkingFunctionExisting()
{
	if (function == nullptr) {
		throw NullPointerFunctionException();
	}
}

double Sectant_method::solvingMethod()
{
	double left = left_boundary;
	double right = right_boundary;
	for (size_t i = 0; i < number_of_iteration; ++i) {
		if (fabs(right - left) < precision) {
			break;
		}
		left = new_value_of_border(right, left, function);
		if (right == left) {
			break;
		}
		right = new_value_of_border(right, left, function);
	}
	return  right;
}
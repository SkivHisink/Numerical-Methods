#include "Chord_method.h"
#include "NullPointerFunctionException.h"

void Chord_method::checkingFunctionExisting()
{
	if (function == nullptr) {
		throw NullPointerFunctionException();
	}
}

double Chord_method::solvingMethod(double& prev_res)
{
	result = new_value_of_border(result, function);
	return  result;
}

double Chord_method::res_initial_value()
{
	return right_boundary;
}

double Chord_method::prev_res_initial_value()
{
	func_left_value = function(left_boundary);
	return left_boundary;
}

bool Chord_method::add_valid_cond()
{
	return function(left_boundary) * function(right_boundary) >= 0;
}




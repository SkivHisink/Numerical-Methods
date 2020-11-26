#include "Entity.h"

bool Entity::is_valid()
{
	if (left_boundary > right_boundary || precision > 1 || precision < 0 || left_boundary == right_boundary||add_valid_cond()) {
		result = WRONG_SOLUTION;
		return false;
	}
	return true;
}

const double Entity::solve()
{
	checkingFunctionExisting();
	if (!is_valid()) {
		return result;
	}
	result = res_initial_value();
	double prev_res = prev_res_initial_value();
	double f = function(result);
	for (size_t i = 0; i < number_of_iteration; ++i)
	{
		result = solvingMethod(prev_res);
		if (abs(function(result)) < precision) {
			return result;
		}
		prev_res = result;
	}
 	return WRONG_SOLUTION; 
}
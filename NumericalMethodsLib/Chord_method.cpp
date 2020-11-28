#include "Chord_method.h"

double Chord_method::get_next_value(double current)
{
	return  new_value_of_border(current, function);
}

double Chord_method::new_value_of_border(const double first_border, const std::function<double(double)> function)
{
	double f = function(first_border);
	return first_border - (first_border - left_boundary) * f / (f - func_left_value);
}

double Chord_method::get_initial_value()
{
	func_left_value = function(left_boundary);
	return right_boundary;
}

bool Chord_method::is_valid()
{
	if (left_boundary > right_boundary || precision > 1 || precision < 0|| 
		left_boundary == right_boundary || function == nullptr || 
		function(left_boundary) * function(right_boundary) >= 0) {
		return false;
	}
	return true;
}



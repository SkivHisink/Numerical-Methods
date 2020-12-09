#include "Chord_method.h"
#include <cmath>

bool Chord_method::check_result(double current, double previous)
{
	func = function(current);
	return abs(func) < precision;
}

double Chord_method::get_next_value(double current)
{
	return current - (current - left_boundary) * func / (func - func_left_value);
}

double Chord_method::get_initial_value()
{
	func = function(right_boundary);
	return right_boundary;
}

bool Chord_method::is_valid()
{
	if (left_boundary > right_boundary || precision > 1 ||
		precision < 0 || left_boundary - right_boundary >1e-20 ||
		right_boundary - left_boundary < -1e-20 || function == nullptr) {
		return false;
	}
	func_left_value = function(left_boundary);
	if (std::isnan(func_left_value) || func_left_value * function(right_boundary) >= 0) {
		return false;
	}
	return true;
}



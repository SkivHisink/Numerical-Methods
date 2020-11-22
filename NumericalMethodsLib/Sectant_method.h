#pragma once
#include "Entity.h"

class Sectant_method final :public Entity
{
	double new_value_of_border(const double first_border, const double second_border, const std::function<double(double)> function)
	{
		return first_border - (first_border - second_border) * function(first_border) / (function(first_border) - function(second_border));
	}
	void solve(const double left_boundary, const double right_boundary,
		const double precision, const std::function<double(double)> function,
		const std::function<double(double)> derivative = nullptr) override;
public:
	explicit Sectant_method(const double left_boundary, const double right_boundary,
		const double precision, const std::function<double(double)> function,
		const std::function<double(double)> derivative = nullptr)
		: Entity(left_boundary, right_boundary, precision, function, derivative)
	{
		solve(left_boundary, right_boundary, precision, function, derivative);
	}
};

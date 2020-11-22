#pragma once
#include "Entity.h"

class Sectant_method final :public Entity
{
	double new_value_of_border(const double first_border, const double second_border, const std::function<double(double)> function)
	{
		return first_border - (first_border - second_border) * function(first_border) / (function(first_border) - function(second_border));
	}
	void checkingFunctionExisting()override;
	double solvingMethod() override;
public:
	explicit Sectant_method(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_)
		: Entity(left_boundary_, right_boundary_, precision_, function_)
	{
		solve();
	}
};

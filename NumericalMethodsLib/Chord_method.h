#pragma once
#include "Entity.h"

class Chord_method final :public Entity
{
	double new_value_of_border(const double first_border, const std::function<double(double)> function)
	{
		return first_border - (first_border - left_boundary) * function(first_border) / (function(first_border) - func_left_value);
	}
	bool add_valid_cond() override;
	void checkingFunctionExisting()override;
	double res_initial_value() override;
	double prev_res_initial_value() override;
	double solvingMethod(double& prev_res) override;
public:
	explicit Chord_method(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_)
		: Entity(left_boundary_, right_boundary_, precision_, function_)
	{}
private:
	double func_left_value = WRONG_SOLUTION;
};

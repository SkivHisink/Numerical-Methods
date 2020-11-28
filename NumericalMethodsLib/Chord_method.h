#pragma once
#include "Entity.h"

class Chord_method final :public Entity
{
	double func_left_value = WRONG_SOLUTION;
	
	double new_value_of_border(const double first_border, const std::function<double(double)> function);
	
	double get_initial_value() override;
	double get_next_value(double current) override;
	bool is_valid() override;
public:
	explicit Chord_method(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_)
		: Entity(left_boundary_, right_boundary_, precision_, function_)
	{}

};

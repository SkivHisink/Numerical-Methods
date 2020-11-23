#pragma once
#include "Entity.h"

class Newton_method final :public Entity
{
	const double give_random_number_from_interval(double left_boundary_, double right_boundary_);
	void checkingFunctionExisting()override;
	double solvingMethod() override;
public:
	explicit Newton_method(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_,
		const std::function<double(double)>& derivative_)
		: Entity(left_boundary_, right_boundary_, precision_, function_, derivative_)
	{}
};

#pragma once
#include "Entity.h"
#include <random>
class Newton_method final :public Entity
{
	std::random_device rand_device;
	std::mt19937 rand_engine = std::mt19937(rand_device());
	const double give_random_number_from_interval(double left_boundary_, double right_boundary_);
	void checkingFunctionExisting()override;
	double res_initial_value() override;
	double solvingMethod(double& prev_res) override;
public:
	explicit Newton_method(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_,
		const std::function<double(double)>& derivative_)
		: Entity(left_boundary_, right_boundary_, precision_, function_, derivative_)
	{}
};

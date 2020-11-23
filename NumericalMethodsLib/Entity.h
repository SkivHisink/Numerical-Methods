#pragma once
#include <functional>
#include <random>

class Entity
{
protected:
	const size_t number_of_iteration = 100000;
	std::random_device rand_device;
	std::mt19937 rand_engine = std::mt19937(rand_device());
	double result = WRONG_SOLUTION;
	const double left_boundary;
	const double right_boundary;
	const double precision;
	const std::function<double(double)>& function;
	const std::function<double(double)>& derivative;

	virtual void checkingFunctionExisting() { }
	virtual double solvingMethod()
	{
		return WRONG_SOLUTION;
	}
	const bool initial_conditions_is_verified();
public:


	explicit Entity(const double left_boundary_, const double right_boundary_,
		const double precision_, const std::function<double(double)>& function_,
		const std::function<double(double)>& derivative_ = nullptr) :
		left_boundary(left_boundary_), right_boundary(right_boundary_),
		precision(precision_), function(function_), derivative(derivative_) {}

	const double get_result()
	{
		return result;
	}

	void solve();

	const double WRONG_SOLUTION = LDBL_MAX;
};

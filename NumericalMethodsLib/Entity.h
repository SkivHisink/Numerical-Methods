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

	const double give_random_number_from_interval(double left_boundary, double right_boundary)
	{
		std::uniform_real_distribution<double> dist(left_boundary, right_boundary);
		return dist(rand_engine);
	}
	const bool initial_conditions_is_verified(const double left_boundary,
		const double right_boundary, const double precision);
	virtual  void solve(double left_boundary, double right_boundary,
		double precision, std::function<double(double)> function,
		std::function<double(double)> derivative = nullptr) { }
public:
	const double WRONG_SOLUTION = LDBL_MAX;
	
	explicit Entity(const double left_boundary, const double right_boundary,
		const double precision, const std::function<double(double)> function,
		const std::function<double(double)> derivative = nullptr) {}

	const double get_result()
	{
		return result;
	}

};

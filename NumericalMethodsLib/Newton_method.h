#pragma once
#include "Entity.h"


class Newton_method final :public Entity
{
	void solve(const double left_boundary, const double right_boundary,
		const double precision, const std::function<double(double)> function,
		const std::function<double(double)> derivative) override;
public:
	explicit Newton_method(const double left_boundary, const double right_boundary,
		const double precision, const std::function<double(double)> function,
		const std::function<double(double)> derivative = nullptr)
		: Entity(left_boundary, right_boundary, precision, function, derivative)
	{
		solve(left_boundary, right_boundary, precision, function, derivative);
	}
};

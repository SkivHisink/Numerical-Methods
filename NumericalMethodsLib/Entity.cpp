#include "Entity.h"

const bool Entity::initial_conditions_is_verified(const double left_boundary, const double right_boundary,
	const double precision)
{
	if (left_boundary > right_boundary || precision > 1 || precision < 0 || left_boundary == right_boundary) {
		result = WRONG_SOLUTION;
		return false;
	}
	return true;
}
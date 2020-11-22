#include "Entity.h"

const bool Entity::initial_conditions_is_verified()
{
	if (left_boundary > right_boundary || precision > 1 || precision < 0 || left_boundary == right_boundary) {
		result = WRONG_SOLUTION;
		return false;
	}
	return true;
}

void Entity::solve( )
{
	if (!initial_conditions_is_verified()) {
		return;
	}
	checkingFunctionExisting();
	result = solvingMethod();
}
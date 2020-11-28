#include "Entity.h"

double Entity::solve()
{
	if (!is_valid()) {
		return WRONG_SOLUTION;
	}
	double current= get_initial_value();
	for (size_t i = 0; i < number_of_iteration; ++i)
	{
		current = get_next_value(current);
		if (abs(function(current)) < precision) {
			return current;
		}
	}
 	return WRONG_SOLUTION; 
}

//double Entity::solve()
//{
//    if (!is_valid()) {
//        return WRONG_SOLUTION;
//    }
//    double prev = get_initial_value();
//    for (size_t i = 0; i < number_of_iteration; ++i)
//    {
//        auto curr = get_next_value(prev);
//        if (abs(curr - prev) < precision) {
//            return curr;
//        }
//        prev = curr;
//    }
//    return WRONG_SOLUTION;
//}
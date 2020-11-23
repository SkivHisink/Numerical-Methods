#include "pch.h"
#include "Newton_method.h"
#include "Sectant_method.h"
#include "NullPointerFunctionException.h"

const double value_of_function_in_x_1(double x)
{
	return powl(x, 3.0);
}

const double value_of_derative_in_x_1(double x)
{
	return 3 * powl(x, 2.0);
}

const double value_of_function_in_x_2(double x)
{
	return powl(x, 3.0) + x * sin(x);
}

const double value_of_derative_in_x_2(double x)
{
	return 3 * powl(x, 2.0) + sin(x) + x * cos(x);
}

TEST(NEWTON_METHOD, Correct_function_1_similar_correct_intervals) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	std::function<double(double)> derative = value_of_derative_in_x_1;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_1_not_similar_correct_intervals) {
	double a = -1, b = 1000;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	std::function<double(double)> derative = value_of_derative_in_x_1;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_1_left_interval_solution) {
	double a = 0, b = 1000;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	std::function<double(double)> derative = value_of_derative_in_x_1;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_1_right_interval_solution) {
	double a = -102131, b = 0;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	std::function<double(double)> derative = value_of_derative_in_x_1;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_2_correct_intervals_1st_root_interval)
{
	double a = -0.5, b = 2.0;
	double precision = 0.00000001;
	double answer = 0.0;

	const std::function<double(double)> function = value_of_function_in_x_2;
	std::function<double(double)> derative = value_of_derative_in_x_2;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_2_incorrect_intervals_2_roots_in_intervals)
{
	double a = -22523.5, b = 58567.8;
	double precision = 0.00000001;
	double answer = -0.876726215395062;
	double answer2 = 0.0;
	const std::function<double(double)> function = value_of_function_in_x_2;
	std::function<double(double)> derative = value_of_derative_in_x_2;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result() ||
		newton.get_result() < answer2 + precision * 10 &&
		answer2 - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, Correct_function_2_correct_interval_2nd_root_interval)
{
	double a = -22523.5, b = -0.5;
	double precision = 0.00000001;
	double answer = -0.876726215395062;

	const std::function<double(double)> function = value_of_function_in_x_2;
	std::function<double(double)> derative = value_of_derative_in_x_2;
	Newton_method newton(a, b, precision, function, derative);
	newton.solve();
	EXPECT_TRUE(newton.get_result() < answer + precision * 10 &&
		answer - precision * 10 < newton.get_result());
}

TEST(NEWTON_METHOD, InCorrect_function) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = nullptr;
	std::function<double(double)> derative = value_of_derative_in_x_1;
	Newton_method newton(a, b, precision, function, derative);
	EXPECT_THROW(newton.solve(), NullPointerFunctionException);
}

TEST(NEWTON_METHOD, InCorrect_derative) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	std::function<double(double)> derative = nullptr;
	Newton_method newton(a, b, precision, function, derative);
	EXPECT_THROW(newton.solve(), NullPointerFunctionException);
}

TEST(NEWTON_METHOD, InCorrect_derative_and_function) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = nullptr;
	std::function<double(double)> derative = nullptr;
	Newton_method newton(a, b, precision, function, derative);
	EXPECT_THROW(newton.solve(), NullPointerFunctionException);
}

TEST(SECTANT_METHOD, Correct_function_1_similar_correct_intervals) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_1_not_similar_correct_intervals) {
	double a = -1, b = 1000;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_1_left_interval_solution) {
	double a = 0, b = 1000;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_1_right_interval_solution) {
	double a = -102131, b = 0;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_1;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_2_correct_intervals_1st_root_interval)
{
	double a = -0.5, b = 200;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = value_of_function_in_x_2;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_2_incorrect_interval_2_roots_in_interval)
{
	double a = -22523.5, b = 152.9;
	double precision = 0.00000001;
	double answer = -0.876726215395062;
	double answer2 = 0.0;
	const std::function<double(double)> function = value_of_function_in_x_2;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result() ||
		sectant.get_result() < answer2 + precision * 10 &&
		answer2 - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, Correct_function_2_correct_interval_2nd_root_interval)
{
	double a = -22523.5, b = -0.6;
	double precision = 0.00000001;
	double answer = -0.876726215395062;

	const std::function<double(double)> function = value_of_function_in_x_2;
	Sectant_method sectant(a, b, precision, function);
	sectant.solve();
	EXPECT_TRUE(sectant.get_result() < answer + precision * 10 &&
		answer - precision * 10 < sectant.get_result());
}

TEST(SECTANT_METHOD, InCorrect_function) {
	double a = -100, b = 100;
	double precision = 0.00000001;
	double answer = 0;

	const std::function<double(double)> function = nullptr;
	Sectant_method sectant(a, b, precision, function);
	EXPECT_THROW(sectant.solve(), NullPointerFunctionException);
}
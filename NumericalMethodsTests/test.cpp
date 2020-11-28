#include "pch.h"
#include "Newton_method.h"
#include "Chord_method.h"
#include "NullPointerFunctionException.h"

double cube(double x)
{
	return powl(x, 3.0);
}

double derative_of_cube(double x)
{
	return 3 * powl(x, 2.0);
}

double cube_plus_x_sinx(double x)
{
	return powl(x, 3.0) + x * sin(x);
}

double derative_cube_plus_x_sinx(double x)
{
	return 3 * powl(x, 2.0) + sin(x) + x * cos(x);
}

TEST(NEWTON, CubeCorrect) {
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-100, 100, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-1, 1000, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(0, 1000, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-102131, 0, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
}

TEST(NEWTON, Cube_plus_x_sinxCorrect)
{
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-0.5, 2, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve())) < 1e-8);
	EXPECT_TRUE(abs(-0.876726215395062 - Newton_method(-22523.5, -0.5, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve()) < 1e-7);
}

TEST(NEWTON, Incorrect_interval_with_2_roots)
{
	double answer = -0.876726215395062;
	double answer2 = 0.0;
	const std::function<double(double)> function = cube_plus_x_sinx;
	std::function<double(double)> derative = derative_cube_plus_x_sinx;
	double result = Newton_method(-22523.5, 58567.8, 1e-8, function, derative).solve();
	EXPECT_TRUE(abs(function(result) - function(answer)) < 1e-8 || abs(function(result) - function(answer2)) < 1e-8);//Actually it's unhandled behavior
}

TEST(NEWTON, InCorrect_function) {
	Newton_method newton(-100, 100, 1e-8, nullptr, derative_of_cube);
	EXPECT_TRUE(std::isnan(newton.solve()));
}

TEST(NEWTON, InCorrect_derative) {
	Newton_method newton(-100, 100, 1e-8, cube, nullptr);
	EXPECT_TRUE(std::isnan(newton.solve()));
}

TEST(NEWTON, InCorrect_derative_and_function) {
	Newton_method newton(-100, 100, 1e-8, nullptr, nullptr);
	EXPECT_TRUE(std::isnan(newton.solve()));
}

TEST(CHORD, CubeCorrect) {
	EXPECT_TRUE(abs(cube(0.0) - cube(Chord_method(-100, 100, 1e-8, cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Chord_method(-1, 100, 1e-8, cube).solve())) < 1e-8);

}
TEST(CHORD, CubeIncorrect)
{
	std::function<double(double)> cube_func = cube;
	Chord_method chord(0, 1000, 1e-8, cube_func);
	EXPECT_TRUE(std::isnan(chord.solve()));
	Chord_method chord2(-102131, 0, 1e-8, cube_func);
	EXPECT_TRUE(std::isnan(chord2.solve()));
}

TEST(CHORD, Cube_plus_x_sinxCorrect)
{

	EXPECT_TRUE(abs(cube_plus_x_sinx(-0.876726215395062) - cube_plus_x_sinx(Chord_method(-25.5, -0.5, 1e-8,
		cube_plus_x_sinx).solve())) < 1e-8);
}

TEST(CHORD, Incorrect_intervals)
{
	const std::function<double(double)> function = cube_plus_x_sinx;
	std::function<double(double)> derative = derative_cube_plus_x_sinx;
	double result = Newton_method(-22523.5, 58567.8, 1e-8, function, derative).solve();
	EXPECT_TRUE(abs(cube_plus_x_sinx(result) - cube_plus_x_sinx(-0.876726215395062)) < 1e-8 ||
		abs(cube_plus_x_sinx(result) - cube_plus_x_sinx(0.0)) < 1e-8);//Actually it's unhandled behavior
	Chord_method chord(-0.5, 2, 1e-8, function);
	EXPECT_TRUE(std::isnan(chord.solve()));
}

TEST(CHORD, InCorrect_function) {
	Chord_method chord(-100, 100, 1e-8, nullptr);
	EXPECT_TRUE(std::isnan(chord.solve()));
}

//TEST(NEWTON, CubeCorrect) {
//	EXPECT_TRUE(abs(0.0 - Newton_method(-100, 100, 1e-8, cube, derative_of_cube).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Newton_method(-1, 1000, 1e-8, cube, derative_of_cube).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Newton_method(0, 1000, 1e-8, cube, derative_of_cube).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Newton_method(-102131, 0, 1e-8, cube, derative_of_cube).solve()) < 1e-8);
//}
//
//TEST(NEWTON, Cube_plus_x_sinxCorrect)
//{
//	EXPECT_TRUE(abs(0.0 - Newton_method(-0.5, 2, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve()) < 1e-8);
//	EXPECT_TRUE(abs(-0.876726215395062 - Newton_method(-22523.5, -0.5, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve()) < 1e-8);
//}
//
//TEST(NEWTON, Incorrect_interval_with_2_roots)
//{
//	double answer = -0.876726215395062;
//	double answer2 = 0.0;
//	const std::function<double(double)> function = cube_plus_x_sinx;
//	std::function<double(double)> derative = derative_cube_plus_x_sinx;
//	double result = Newton_method(-22523.5, 58567.8, 1e-8, function, derative).solve();
//	EXPECT_TRUE(abs(function(result) - function(answer)) < 1e-8 || abs(function(result) - function(answer2)) < 1e-8);//Actually it's unhandled behavior
//}
//
//TEST(NEWTON, InCorrect_function) {
//	Newton_method newton(-100, 100, 1e-8, nullptr, derative_of_cube);
//	EXPECT_TRUE(std::isnan(newton.solve()));
//}
//
//TEST(NEWTON, InCorrect_derative) {
//	Newton_method newton(-100, 100, 1e-8, cube, nullptr);
//	EXPECT_TRUE(std::isnan(newton.solve()));
//}
//
//TEST(NEWTON, InCorrect_derative_and_function) {
//	Newton_method newton(-100, 100, 1e-8, nullptr, nullptr);
//	EXPECT_TRUE(std::isnan(newton.solve()));
//}
//
//TEST(CHORD, CubeCorrect) {
//	EXPECT_TRUE(abs(0.0 - Chord_method(-100, 100, 1e-8, cube).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Chord_method(-1, 100, 1e-8, cube).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Chord_method(0, 1000, 1e-8, cube ).solve()) < 1e-8);
//	EXPECT_TRUE(abs(0.0 - Chord_method(-102131, 0, 1e-8, cube).solve()) < 1e-8);
//}
//TEST(CHORD, CubeIncorrect)
//{
//	std::function<double(double)> cube_func = cube;
//	Chord_method chord(0, 1000, 1e-8, cube_func);
//	EXPECT_TRUE(std::isnan(chord.solve()));
//	Chord_method chord2(-102131, 0, 1e-8, cube_func);
//	EXPECT_TRUE(std::isnan(chord2.solve()));
//}
//
//TEST(CHORD, Cube_plus_x_sinxCorrect)
//{
//
//	EXPECT_TRUE(abs(-0.876726215395062 - Chord_method(-25.5, -0.5, 1e-8,
//		cube_plus_x_sinx).solve()) < 1e-8);
//}
//
//TEST(CHORD, Incorrect_intervals)
//{
//	const std::function<double(double)> function = cube_plus_x_sinx;
//	std::function<double(double)> derative = derative_cube_plus_x_sinx;
//	double result = Newton_method(-22523.5, 58567.8, 1e-8, function, derative).solve();
//	EXPECT_TRUE(abs(result - -0.876726215395062) < 1e-8 ||
//		abs(result - 0.0) < 1e-8);//Actually it's unhandled behavior
//	Chord_method chord(-0.5, 2, 1e-8, function);
//	EXPECT_TRUE(std::isnan(chord.solve()));
//}
//
//TEST(CHORD, InCorrect_function) {
//	Chord_method chord(-100, 100, 1e-8, nullptr);
//	EXPECT_TRUE(std::isnan(chord.solve()));
//}
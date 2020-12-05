#include "pch.h"
#include "Newton_method.h"
#include "Chord_method.h"

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

double coub_cycle(double x)
{
	return powl(x, 3.0) - 2 * x - 2;
}

double dcoub_cycle(double x)
{
	return 3 * powl(x, 2.0) - 2;
}

double quater_with_square(double x)
{
	return 8 * powl(x, 4.0) - 10 * powl(x, 2.0) + 1;
}

double derative_quater_with_square(double x)
{
	return 32 * powl(x, 3.0) - 20 * x + 1;
}

TEST(NEWTON, CubeCorrect) {
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-100, 100, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-1, 1000, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(0, 1000, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
	EXPECT_TRUE(abs(cube(0.0) - cube(Newton_method(-102131, 0, 1e-8, cube, derative_of_cube).solve())) < 1e-8);
}

TEST(NEWTON, Cube_plus_x_sinxCorrect)
{
	EXPECT_TRUE(abs(-0.876726215395062 - Newton_method(-22523.5, -0.5, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve()) < 1e-7);
}

TEST(NEWTON, Incorrect_interval)
{
	double answer = -0.876726215395062;
	double answer2 = 0.0;
	const std::function<double(double)> function = cube_plus_x_sinx;
	std::function<double(double)> derative = derative_cube_plus_x_sinx;
	double result = Newton_method(-22523.5, 58567.8, 1e-8, function, derative).solve();
	EXPECT_TRUE(abs(function(result) - function(answer)) < 1e-8 || abs(function(result) - function(answer2)) < 1e-8);//Actually it's unhandled behavior
	EXPECT_TRUE(std::isnan(Newton_method(-0.5, 2, 1e-8, cube_plus_x_sinx, derative_cube_plus_x_sinx).solve()));

}

TEST(NEWTON, CubeWithExpansionCorrect)
{
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Newton_method(-4, 7, 1e-8, coub_cycle, dcoub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Newton_method(-12, 16, 1e-8, coub_cycle, dcoub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Newton_method(-32, 4, 1e-8, coub_cycle, dcoub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Newton_method(-2, 42, 1e-8, coub_cycle, dcoub_cycle).solve())) < 1e-8);
}
TEST(NEWTON, CubeWithExpansionIncorrect)
{
	EXPECT_TRUE(std::isnan(Newton_method(-3, 3, 1e-8, coub_cycle, dcoub_cycle).solve()));
	EXPECT_TRUE(std::isnan(Newton_method(-6, 6, 1e-8, coub_cycle, dcoub_cycle).solve()));
	EXPECT_TRUE(std::isnan(Newton_method(-9, 9, 1e-8, coub_cycle, dcoub_cycle).solve()));
	EXPECT_TRUE(std::isnan(Newton_method(-150, 150, 1e-8, coub_cycle, dcoub_cycle).solve()));
}

TEST(NEWTON, QuaterWithSquareCorrect)
{
	EXPECT_TRUE(abs(quater_with_square(-1.06788960253493) -quater_with_square(Newton_method(-1.5, -0.5, 1e-8, quater_with_square, derative_quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(-0.331076723430978) -quater_with_square(Newton_method(-0.5, 0.0, 1e-8, quater_with_square, derative_quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(0.331076723430978) -quater_with_square(Newton_method(0.0, 0.5, 1e-8, quater_with_square, derative_quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(1.06788960253493) - quater_with_square(Newton_method(0.5, 1.5, 1e-8, quater_with_square, derative_quater_with_square).solve())) < 1e-8);
}

TEST(NEWTON, QuaterWithSquareIncorrect)
{
	EXPECT_TRUE(std::isnan(Newton_method(-1.5, 0.1, 1e-8, quater_with_square, derative_quater_with_square).solve()));
	EXPECT_TRUE(std::isnan(Newton_method(-12, 12, 1e-8, quater_with_square, derative_quater_with_square).solve()));
	EXPECT_TRUE(std::isnan(Newton_method(0.2, 12, 1e-8, quater_with_square, derative_quater_with_square).solve()));
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

TEST(CHORD, QuaterWithSquareCorrect)
{
	EXPECT_TRUE(abs(quater_with_square(-1.06788960253493) - quater_with_square(Chord_method(-1.5, -0.5, 1e-8, quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(-0.331076723430978) - quater_with_square(Chord_method(-0.5, 0.0, 1e-8, quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(0.331076723430978) - quater_with_square(Chord_method(0.0, 0.5, 1e-8, quater_with_square).solve())) < 1e-8);
	EXPECT_TRUE(abs(quater_with_square(1.06788960253493) - quater_with_square(Chord_method(0.5, 1.5, 1e-8, quater_with_square).solve())) < 1e-8);
}

TEST(CHORD, QuaterWithSquareIncorrect)
{
	EXPECT_TRUE(std::isnan(Chord_method(-1.5, 0.1, 1e-8, quater_with_square).solve()));
	EXPECT_TRUE(std::isnan(Chord_method(-12, 12, 1e-8, quater_with_square).solve()));
	EXPECT_TRUE(std::isnan(Chord_method(0.2, 12, 1e-8, quater_with_square).solve()));
}

TEST(CHORD, Cube_plus_x_sinxCorrect)
{

	EXPECT_TRUE(abs(cube_plus_x_sinx(-0.876726215395062) - cube_plus_x_sinx(Chord_method(-25.5, -0.5, 1e-8,
		cube_plus_x_sinx).solve())) < 1e-8);
}

TEST(CHORD, CubeWithExpansionCorrect)
{
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Chord_method(-4, 7, 1e-8, coub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Chord_method(-12, 16, 1e-8, coub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Chord_method(-32, 4, 1e-8, coub_cycle).solve())) < 1e-8);
	EXPECT_TRUE(abs(coub_cycle(1.7692923542386314) - coub_cycle(Chord_method(-10, 10, 1e-8, coub_cycle).solve())) < 1e-8);
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
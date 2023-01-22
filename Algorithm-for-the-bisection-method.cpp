#include <iostream>
#include <iomanip>
#include <cmath>

/*
	Problem 1.
	Find the solution of the equation 3/x - ln(2x + 1) = 0
	in [1, 2] by using the bisection method. The solution should have tolerance of less than 10^{-3}
	Problem 2.
	Find the solution of the equation x^2 - 2xcos(x) = 1
	in [0, 2] by using the bisection method. The solution should have tolerance of less than 10^{-4} 
*/

inline double f(double x) {
	return 3/x - std::log(2*x + 1);
}

/*
	Firstly we set a1 = a and b1 = b, then the bisection method consists of the following steps
	1. Define c1 = (a1 + b1)/2
	2. if b1 - c1 <= tolerance accpect c1 as the root and stop
	3. Make the following equations to determine in which subinterval the root
*/
double bisection_method(double a, double b, double error_tolerance, int n, int n_max) {
	// Number of interations for the bisection method
	// |c_n - c| <= (b-a)/2^n when n >= 1
	// we get n >= ln((b - a)/epsilon)/ln(2)

	// Initial interval
	double a1 = a;
	double b1 = b;

	// Define c1
	double c1 = (a1 + b1)/2;

	if (n - 1 >= n_max)
		return c1;

	std::cout << std::setw(2) << std::setprecision (4) << std::fixed << n << " " << std::setw(12) << a1 << " " << std::setw(12) << c1 << " " << std::setw(12) << b1 << " " << std::setw(12) << f(a1) << " " << std::setw(12) << f(c1) << " " << std::setw(12) << f(b1) << std::endl;

	if (f(a1)*f(c1) < 0)
		return bisection_method(a1, c1, error_tolerance, ++n, n_max);
	else if (f(c1)*f(b1) < 0 || f(a1)*f(c1) > 0)
		return bisection_method(c1, b1, error_tolerance, ++n, n_max);
	else
		return c1;
}

int main() {
	std::cout << " n" << std::setw(13) << "a" << std::setw(13) << "c" << std::setw(13) << "b" << std::setw(13) << "f(a)" << std::setw(13) << "f(c)" << std::setw(13) << "f(b)" << std::endl;
	bisection_method(1, 2, 10e-4, 1, std::ceil(std::log((2-1)/(10e-4))/std::log(2)));
	return 0;
}

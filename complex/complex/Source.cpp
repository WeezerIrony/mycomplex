#include "complex.h"
#include <iostream>

const complex i(0, 1);

int main() {
	complex z1;
	complex z2(1, 1);
	complex z3 = 1;
	std::cout << z1 << std::endl;
	std::cout << z2 << std::endl;
	std::cout << z3 << std::endl;
	z1 += z2;
	std::cout << z1 << std::endl;
	z1 /= z2;
	std::cout << z1 << std::endl;
	complex z5;
	std::cin >> z5;
	std::cout << z5;
	std::cout << (z1 + z2) << std::endl;
}

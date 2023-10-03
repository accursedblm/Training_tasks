#include "Integral.h"
#include <math.h>
#include <Windows.h>

double Sin(double x)
{
	return sin(x); // pow(abs(sin(x * cos(x) + 18 * x)), 15);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Integral I(Sin, 0, 6.283, 0.001);
	cout << I;

	print(I);

	return 0;
}
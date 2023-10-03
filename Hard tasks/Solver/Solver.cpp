#include <iostream>
#include "TSolver.h"
#include "Windows.h"

using namespace std;

double f1(double x)
{
	return sin(x) - 0.5 * x;
}
double f2(double x)
{
	return (x + 2) * (x - 2);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int f;
	double a, b, eps;
	double (*Arf[2])(double) = { f1,f2 };
	cout << "Введите через пробел a b eps функция(1/0)";
	cin >> a >> b >> eps >> f;
	TSolver TS(a, b, eps, Arf[f]);
	TS.Root().Print(true);

	return 0;
}
#include "TSolver.h"

using namespace std;

TSolver::TSolver(double a, double b, double eps, TFUN(F))
{
	this->a = a;
	this->b = b;
	this->eps = eps;
	this->Func = F;
}
TSolver& TSolver::Root()
{
	double t;
	if (a > b)
	{	t = a; a = b; b = t;}
	double x1 = a, x2 = a + eps;
	result.clear();
	steps.clear();
	while (x2 < b)
	{
		if (Func(x1) * Func(x2) <= 0)
			result.push_back((x1 + x2) / 2);
		else
			steps.push_back("Промежуток от " + to_string(x1) + " до " + to_string(x2) + " не содержит корней");
		x1 += eps;
		x2 += eps;
	}
	return *this;
}
TSolver& TSolver::Print(bool SStep)
{
	
	if (SStep && steps.size() > 0)
	{
		cout << "Распечатка шагов" << endl;
		for_each(steps.begin(), steps.end(), [](string str) {
			cout << str << endl; });
	}	
	cout << endl << "Всего сделано шагов: " << result.size() + steps.size() << " Корней найдено: " << result.size() << endl;
	if (result.size() > 0)
	{
		cout << "Распечатка корней" << endl;
		for_each(result.begin(), result.end(), [](double k) {
			cout << k << endl; });
	}
	return *this;
}
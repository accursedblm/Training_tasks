#pragma once
#define TFUN(F) double (*F)(double)
#define TSHOW(F) void (*F)(double,double,double (*)(double))
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class TSolver
{
private:
	double a, b, eps;
	vector<double> result;
	vector<string> steps;
	TFUN(Func) 
	{ };
	void ShowStep(double a, double b, TFUN(F))
	{
		std::cout << "\nПроцесс поиска:\t"
			<< a << '\t' << b << 't' << F(a) << '\t' << '\t' << F(b);
	}
public:
	TSolver(double a, double b, double eps, TFUN(F));
	~TSolver()
	{ }
	TSolver& Root();
	TSolver& Print(bool SStep = true);
	TSolver& A(double new_A)
	{	a = new_A;}
	TSolver& B(double new_B)
	{	b = new_B;}
	TSolver& EPS(double new_EPS)
	{	eps = new_EPS;}
	TSolver& SetFunc(TFUN(F))
	{	Func = F;}
};


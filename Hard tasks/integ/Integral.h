#pragma once
#include <iostream>
using namespace std;
using TFunc = double(*)(double);

class Integral
{
	double a, b; //границы
	double h; //шаг интеграла
	TFunc Fun; //указатель на функцию
	bool Search(); //Проверка правильности
public:
	Integral(TFunc F = nullptr, double A = 0, double B = 0, double H = 0)
	{
		Fun = F;
		a = A;
		b = B;
		h = H;
		Search();
	}
	Integral(const Integral& I)
	{
		a = I.a;
		b = I.b;
		h = I.h;
		Fun = I.Fun;
		Search();
	}
	~Integral()
	{}
	void step(double H)
	{
		h = H; //функция изменения шага
	}
	void border(double A, double B)
	{
		a = A; b = B;
	}
	double TRap() const;
	double LeftP() const;
	double RightP() const;
	double MiddleP() const;
	friend ostream& operator << (ostream& out, const Integral& I);
	Integral& operator = (const Integral&);
	double operator[](double x);
	friend void print(Integral& I);
};
void print(Integral& I);


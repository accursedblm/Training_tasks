#include "Integral.h"

bool Integral::Search()
{
	bool res = (Fun != nullptr) && (a < b) && (h > 0) && (h < b - a);
	if (!res)
		cout << "Не верные параметры";
	return res;
}
double Integral::TRap() const
{
	double S = 0, i = a;
	for (; i + h < b; i += h)
		S += (Fun(i) + Fun(i + h)) * h / 2;
	S +=(Fun(i) + Fun(b)) * (b - i) / 2;
	return S;
}
double Integral::LeftP() const
{
	double S = 0, i = a;
	for (; i + h < b; i += h)
		S += Fun(i) * (h);
	S += Fun(i) * (b - i);
	return S;
}
double Integral::RightP() const
{
	double S = 0, i = a;
	for (; i + h < b; i += h)
		S += Fun(i + h) * (h);
	S += Fun(b) * (b - i);
	return S;
}
double Integral::MiddleP() const
{
	double S = 0, i = a;
	for (; i + h < b; i += h)
		S += Fun(i + h / 2) * (h);
	S += Fun((b + i) / 2) * (b - i);
	return S;
}

ostream& operator << (ostream& out, const Integral& I)
{
	out << "Прямоугольник ср=" << I.MiddleP() << endl <<
		"Прямоугольник лев=" << I.LeftP() << endl << 
		"Прямоугольник прав=" << I.RightP() << endl << 
		"Прямоугольник трап=" << I.TRap() << endl ;
	return out;
}

void print(Integral& I)
{
	for (double i = I.a; i + I.h < I.b; i += I.h)
		cout << i << '\t' << I[i] << endl;
	cout << I.b << '\t' << I[I.b] << endl;
}

Integral& Integral::operator = (const Integral& I)
{
	if (this != &I)
	{
		Fun = I.Fun;
		a = I.a;
		b = I.b;
		h = I.h;
	}
	Search();
	return *this;
}

double Integral::operator[](double x)
{
	return Fun(x);
}

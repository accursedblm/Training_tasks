#pragma once
#include <iostream>
using namespace std;
class TRect
{
protected:
	double Fx1, Fx2; //ширина длина
public:
	void SetSize(double x1, double x2)
	{
		Fx1 = x1 < 0 ? 0 : x1;
		Fx2 = x2 < 0 ? 0 : x2;
	}
	TRect(double x1 = 0, double x2 = 0)
	{
		SetSize(x1, x2);
	}
	double Area() const
	{
		return Fx1 * Fx2;
	}
	TRect& operator = (const TRect&) = default; //явно разрешено создавать побитовое равно. Можно вообще эту строку не писать
	friend ostream& operator << (ostream&, const TRect&);
	friend istream& operator >> (istream&, const TRect&);
};


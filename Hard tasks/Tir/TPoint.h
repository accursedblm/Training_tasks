#pragma once
#include <iostream>
using namespace std;
class TPoint
{
	double Fx, Fy;
public:
	TPoint(double x = 0, double y = 0) : Fx(x), Fy(y)
	{}
	TPoint(const TPoint& P) : Fx(P.Fx), Fy(P.Fy)
	{}
	virtual ~TPoint() //В данном случае virtual не обязательно
	{};
	void Set(double x, double y)
	{
		Fx = x;
		Fy = y;
	}
	double x() { return Fx; }
	double y() { return Fy; }
	friend istream& operator >> (istream&, TPoint&);
	friend ostream& operator << (ostream&, const TPoint&);
};




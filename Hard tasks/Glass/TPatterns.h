#pragma once
#include <iostream>
using namespace std;

class TPatterns
{
protected:
	float Fprice;//цена за 1 м2
	int Fcount; //кол0во копий
public:
	TPatterns(float Fp = 0, int Fc = 1) : Fprice(Fp), Fcount(Fc) {}
	virtual ~TPatterns() = 0 {}
	virtual float GetArea() const = 0;
	virtual char* GetType() const = 0;
	float GetCost() const
	{
		return GetArea() * Fprice * Fcount;
	}
	virtual void Read(istream& in);
	virtual void Print(ostream& out) const;
};


#pragma once
#include <iostream>
#include <algorithm>

class TGoods
{
protected:
	double Fprice;			//���� �� �2
	static double Fextra;	//�������
public:
	TGoods(double p = 0) :Fprice(0)
	{}
	void SetPrise(double p)
	{
		Fprice = p;
	}
	static void SetExtra(double p)
	{
		Fextra = p;
	}
	double FullPrice() const
	
	{
		return Fprice * (1 + Fextra);
	}
};


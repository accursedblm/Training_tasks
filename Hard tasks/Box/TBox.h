#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class TBox
{
private:
	float bx, by, bz;
public:

	TBox(float x = 0, float y= 0 , float z = 0)
	{bx = x; by = y; bz = z; }
	~TBox()
	{ }
	TBox& BoxResize(float x, float y, float z);
	float SizeX();
	float SizeY();
	float SizeZ();
	TBox& SizeX(float x);
	TBox& SizeY(float y);
	TBox& SizeZ(float z);
	float Volume();
	int HowMachTkInside(TBox&);
	void Print();
};


#pragma once
#include "TPoint.h"
static TPoint Temp(0, 0);
class TSetPoint
{
protected:
	int Fsize;
	int Fcount;
	TPoint* Buff;

public:
	TSetPoint(int n = 0);

	virtual ~TSetPoint()
	{
		if (!Buff)
			delete[] Buff;
	}

	int Count()
	{
		return Fcount;
	}

	//���������� ����� �����
	TSetPoint& operator >> (TPoint& P);
	//������ � ��������
	TPoint& operator [] (int i)
	{
		if (i < 0 || i >= Fcount)
			return Temp;
		else
			return Buff[i];
	}
};
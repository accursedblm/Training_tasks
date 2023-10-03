#include "TSetPoint.h"

TSetPoint::TSetPoint(int n)
{
	if (n < 0)
		n = 0;
	Fsize = n;
	Fcount = 0;
	if (!Fsize)
		Buff = nullptr;
	else
	{
		Buff = new (nothrow) TPoint[n];
		if (Buff == nullptr)
			exit;
	}
}

TSetPoint& TSetPoint::operator >> (TPoint& P)
{
	if (Fcount == Fsize)
	{
		TPoint* tmp = new (nothrow) TPoint[Fsize * 2];
		if (tmp == nullptr)
			exit;
		for (int i = 0; i < Fsize; i++)
			tmp[i] = Buff[i];
		Fsize = Fsize * 2;
		delete [] Buff;
		Buff = tmp;
	}
	Buff[Fcount++].Set(P.x(), P.y());
	return *this;
}
#include "TPoint.h"

istream& operator >> (istream& in, TPoint& P)
{
	return in >> P.Fx >> P.Fy;
}

ostream& operator << (ostream& out, const TPoint& P)
{
	return out << "(" << P.Fx << "; " << P.Fy << ")" << endl;
}
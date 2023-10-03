#include "TRect.h"

ostream& operator<<(ostream& out, const TRect& R)
{
	return out << "(" << R.Fx1 << "x" << R.Fx2 << ")";
}

istream& operator>>(istream& in, const TRect& R)
{
	return in >> R.Fx1 >> R.Fx2;
}

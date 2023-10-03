#include "TTarget.h"

void TTarget::operator >> (TPoint& P)
{
	double l = P.x() * P.x() + P.y() * P.y();
	if (Fr * Fr > l)
	{
		TSetPoint::operator >> (P);
		FBall += 10 - (int)(10 * l / (Fr * Fr) + 0, 5);
		FNumber++;
	}

}

ostream& operator << (ostream& out, TTarget& P)
{
	out << "Кол-во попаданий " << P.FNumber << endl
		<< "Баллы " << P.FBall << endl
		<< "Координаты попаданий: " << endl;
	for (int i = 0; i < P.FNumber; i++)
		out << P[i];
	return out;
}

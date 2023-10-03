#include "TPatterns.h"

void TPatterns::Read(istream& in)
{
	cout << GetType() << endl
		<< "Кол-во экземпляров: ";
	in >> Fcount;
	cout << "Цена за 1м2: ";
	in >> Fprice;
}

void TPatterns::Print(ostream& out) const
{
	cout << GetType() << endl
		<< "Кол-во,шт: " << endl;
	out << Fcount << endl;
	cout << "По цене за 1м2: " << endl;
	out << Fprice << endl;
}


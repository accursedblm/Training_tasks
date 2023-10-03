#include "TPatterns.h"

void TPatterns::Read(istream& in)
{
	cout << GetType() << endl
		<< "���-�� �����������: ";
	in >> Fcount;
	cout << "���� �� 1�2: ";
	in >> Fprice;
}

void TPatterns::Print(ostream& out) const
{
	cout << GetType() << endl
		<< "���-��,��: " << endl;
	out << Fcount << endl;
	cout << "�� ���� �� 1�2: " << endl;
	out << Fprice << endl;
}


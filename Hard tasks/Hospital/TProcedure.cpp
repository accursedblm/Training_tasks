#include "TProcedure.h"

void TProcedure::read(istream& in)
{
	TRemedy::read(in);
    cout << "������� ����������: \t\t";
    in >> How; cout << endl;
    cout << "����������������� � �������:\t";
    in >> DTime; cout << endl;
}

void TProcedure::write(ostream& out) const
{
    TRemedy::write(out);
    cout << "������� ����������: \t\t";
    out << How; cout << endl;
    cout << "����������������� � �������:\t";
    out << DTime; cout << endl;
}

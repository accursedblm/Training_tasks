#include "TMedicine.h"

void TMedicine::read(istream& in)
{
    TRemedy::read(in);
    cout << "������ ������: \t\t";
    in >> How; cout << endl;
    cout << "���������:\t\t";
    in >> Dose; cout << endl;
}

void TMedicine::write(ostream& out) const
{
    TRemedy::write(out);
    cout << "������ ������: \t";
    out << How; cout << endl;
    cout << "���������:\t\t";
    out << Dose; cout << endl;
}
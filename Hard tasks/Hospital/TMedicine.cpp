#include "TMedicine.h"

void TMedicine::read(istream& in)
{
    TRemedy::read(in);
    cout << "Способ приема: \t\t";
    in >> How; cout << endl;
    cout << "Дозировка:\t\t";
    in >> Dose; cout << endl;
}

void TMedicine::write(ostream& out) const
{
    TRemedy::write(out);
    cout << "Способ приема: \t";
    out << How; cout << endl;
    cout << "Дозировка:\t\t";
    out << Dose; cout << endl;
}
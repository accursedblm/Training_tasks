#include "TProcedure.h"

void TProcedure::read(istream& in)
{
	TRemedy::read(in);
    cout << "Условия проведения: \t\t";
    in >> How; cout << endl;
    cout << "Продолжительность в минутах:\t";
    in >> DTime; cout << endl;
}

void TProcedure::write(ostream& out) const
{
    TRemedy::write(out);
    cout << "Условия проведения: \t\t";
    out << How; cout << endl;
    cout << "Продолжительность в минутах:\t";
    out << DTime; cout << endl;
}

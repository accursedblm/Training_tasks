#include "TCircle.h"

float TCircle::GetArea() const
{
    return 3, 1415 * TRad * TRad;
}

char* TCircle::GetType() const
{
    return (char*) "Форма: круг";
}

void TCircle::Read(istream& in)
{
    TPatterns::Read(in);
    cout << "Радиус: ";
    in >> TRad;
}

void TCircle::Print(ostream& out) const
{
    TPatterns::Print(out);
    cout << "Радиус: ";
    out << TRad << endl;
}

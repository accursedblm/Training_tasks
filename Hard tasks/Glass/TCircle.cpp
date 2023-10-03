#include "TCircle.h"

float TCircle::GetArea() const
{
    return 3, 1415 * TRad * TRad;
}

char* TCircle::GetType() const
{
    return (char*) "�����: ����";
}

void TCircle::Read(istream& in)
{
    TPatterns::Read(in);
    cout << "������: ";
    in >> TRad;
}

void TCircle::Print(ostream& out) const
{
    TPatterns::Print(out);
    cout << "������: ";
    out << TRad << endl;
}

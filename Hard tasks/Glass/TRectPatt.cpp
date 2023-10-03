#include "TRectPatt.h"

float TRectPatt::GetArea() const
{
    return FHeight*FWidth;
}

char* TRectPatt::GetType() const
{
    return (char*) "�����: �������������";
}

void TRectPatt::Read(istream& in)
{
    TPatterns::Read(in);
    cout << "������: ";
    in >> FHeight;
    cout << "������: ";
    in >> FWidth;
}

void TRectPatt::Print(ostream& out) const
{
    TPatterns::Print(out);
    cout << "������: ";
    out << FHeight << endl;
    cout << "������: ";
    out << FWidth << endl;
}

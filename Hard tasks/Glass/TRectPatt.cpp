#include "TRectPatt.h"

float TRectPatt::GetArea() const
{
    return FHeight*FWidth;
}

char* TRectPatt::GetType() const
{
    return (char*) "Форма: прямоугольная";
}

void TRectPatt::Read(istream& in)
{
    TPatterns::Read(in);
    cout << "Высота: ";
    in >> FHeight;
    cout << "Ширина: ";
    in >> FWidth;
}

void TRectPatt::Print(ostream& out) const
{
    TPatterns::Print(out);
    cout << "Высота: ";
    out << FHeight << endl;
    cout << "Ширина: ";
    out << FWidth << endl;
}

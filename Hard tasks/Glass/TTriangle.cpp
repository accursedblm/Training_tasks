#include "TTriangle.h"

float TTriangle::GetArea() const
{
    return FHeight*FWidth/2;
}

char* TTriangle::GetType() const
{
    return (char*) "Форма: Треугольник";
}

void TTriangle::Read(istream& in)
{
    TRectPatt::Read(in);
}

void TTriangle::Print(ostream& out) const
{
    TRectPatt::Print(out);
}
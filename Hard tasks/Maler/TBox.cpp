#include "TBox.h"

ostream& operator<<(ostream& out, const TBox& B)
{
    return out << "(" << B.Fx0 << "x" << B.Fx1 << "x" << B.Fx2 << ")";
}

istream& operator>>(istream& in, TBox& B)
{
    return in >> B.Fx0 >> B.Fx1 >> B.Fx2;
}

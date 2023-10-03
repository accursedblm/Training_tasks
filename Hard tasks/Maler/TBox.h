#pragma once
#include "TRect.h"
class TBox :
    public TRect
{
protected:
    double Fx0;
public:
    void SetSize(double x0 = 0)
    {
        Fx0 = x0 < 0 ? 0 : x0;
    }
    void SetSize(double x0, double x1, double x2)
    {
        TRect::SetSize(x1, x2);
        SetSize(x0);
    }
    TBox(double x0 = 0, double x1 = 0, double x2 = 0)
    {
        SetSize(x0, x1, x2);
    }
    double Area() const
    {
        return 2 * (Fx0 * Fx1 + Fx0 * Fx2 + Fx1 * Fx2);
    }
    TRect GetRect(int i, int j) const //Метод получения грани
    {
        double d[3];
        d[0] = Fx0; d[1] = Fx1; d[2] = Fx2;
        return TRect(d[i], d[j]);
    }
    TRect operator ()(int i, int j) const
    {
        return GetRect(i, j);
    }
    TBox& operator = (const TBox&) = default;
    friend ostream& operator << (ostream&, const TBox&);
    friend istream& operator >> (istream&, TBox&);
};


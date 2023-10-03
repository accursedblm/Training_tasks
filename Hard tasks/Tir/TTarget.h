#pragma once
#include "TSetPoint.h"
class TTarget :
    public TSetPoint
{
    double Fr;      //Радиус
    int FBall;      //Кол-во очков
    int FNumber;    //Кол-во попаданий
public:
    TTarget(double r = 0) : TSetPoint(10), Fr(r), FBall(), FNumber() // FBall() и FNumber() это конструкторы по умолчанию для int. Для всех стандартных типов есть конструктор по умолчанию.
    {}
    void operator >> (TPoint& p);
    friend ostream& operator << (ostream&, TTarget&);
};


#pragma once
#include "Pack.h"
class Batch :
    public Pack
{
protected:
    int Num; //Количество упаковок
    static float Extra; //Добавочная наценка
public:
    Batch(const char Nam[] = "NoName", float Pr = 0, const char Inf[] = "NoInformation",
        int Cou = 0, int Num = 0, float Extra = -1);
    static void SetExtra(float Extra = 15) { Batch::Extra = Extra; }
    //static float GetExtra() { return Extra; }
    void SetNum(int Num) { Batch::Num = Num; }
    float GetExtra() { return Price * Count * Num * (1 + Extra / 100);}
    void Read(istream& in = std::cin) override;
    void Print(ostream& out = std::cout) override;
    Batch& operator = (Batch& b);
    friend istream& operator >> (istream& in, Batch& p);
    friend ostream& operator << (ostream& out, const Batch& p);
};
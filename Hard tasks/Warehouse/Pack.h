#pragma once
#include "Goods.h"
class Pack : //Упаковка (блок) товара
    public Goods
{
protected:
    int Count; //Количество в упаковке
public:
    Pack(const char Nam[] = "NoName", float Pr = 0, const char Inf[] = "", int Cou = 0);
    void SetCount(int Cou);
    void Set(const char Nam[], float Pr, const char Inf[], int Cou);
    void Read(istream& in = std::cin) override;
    void Print(ostream& out = std::cout) override;
    float CostPack() { return Price * Count; }; //Стоимость упаковки
    Pack& operator = (Pack& p);
    friend istream& operator >> (istream& in, Pack& p);
    friend ostream& operator << (ostream& out, Pack& p);
    ~Pack();
};
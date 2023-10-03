#pragma once
#include "TPatterns.h"
#include "TRectPatt.h"
#include "TTriangle.h"
#include "TCircle.h"

class TOrder :
    public TPatterns
{
private:
    TPatterns** Fp;
    int FNum, FMaxNum;
    void Copy(const TOrder& z);
    void Move(TOrder& z);
    static TPatterns* TmpPat;
public:
    TOrder(int Max = 10)
    {
        Max = Max < 1 ? 10 : Max;
        Fp = new TPatterns * [Max];
        FMaxNum = Max;
        FNum = 0;
        if (TmpPat == 0)
            TmpPat = new TRectPatt;
    }
    ~TOrder()
    {
        if (!Fp)
            return;
        else
            for (int i = 0; i < FNum; i++)
                delete Fp[i];
        delete[] Fp;
    }
    static void DeleteStaticFields()
    {
        if (TmpPat)
            delete TmpPat;
        TmpPat = nullptr;
    }
    TOrder(const TOrder& z)
    {
        Fp = 0;
        Copy(z);
    }
    TOrder(TOrder&& z)
    {
        Fp = 0;
        Move(z);
    }
    TOrder& operator = (const TOrder& z);
    TOrder& operator = (TOrder&& z);
    TPatterns* operator[](int i)
    {
        if (i < 0 || i >= FNum)
            return TmpPat;
        else
            return Fp[i];
    }
    int GetCount() const
    {
        return FNum;
    }
    int Add(TPatterns* p);
    static TPatterns* CreateGroup(char type);
    static char GetNewType(char* types)
    {
        char type;
        cout << "”кажите форму (т-треугольник,п-пр€моугольник,к-круг: ";
        do
        {
            cin >> type;
        } while (type == ','||!strchr(types,type));
        return type;
    }
    void Read(char* types);
    void Print() const;
};


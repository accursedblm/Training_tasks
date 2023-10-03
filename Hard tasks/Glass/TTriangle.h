#pragma once
#include "TRectPatt.h"
class TTriangle :
    public TRectPatt
{
public:
    ~TTriangle() {}
    float GetArea() const override;
    char* GetType() const override;
    virtual void Read(istream& in) override;
    virtual void Print(ostream& out) const override;
};


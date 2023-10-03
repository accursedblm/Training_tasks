#pragma once
#include "TPatterns.h"
class TRectPatt :
    public TPatterns
{
protected:
    float FHeight{ 0 };
    float FWidth{ 0 };
public:
    virtual ~TRectPatt() {}
    float GetArea() const override;
    char* GetType() const override;
    virtual void Read(istream& in) override;
    virtual void Print(ostream& out) const override;
};


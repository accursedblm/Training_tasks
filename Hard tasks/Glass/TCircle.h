#pragma once
#include "TPatterns.h"


class TCircle :
    public TPatterns
{
protected:
    float TRad{ 0 };
public:
    virtual ~TCircle() {}
    float GetArea() const override;
    char* GetType() const override;
    virtual void Read(istream& in) override;
    virtual void Print(ostream& out) const override;
};


#pragma once
#include "TRemedy.h"
class TMedicine :
    public TRemedy
{
protected:
	string How; //способ приема
	int Dose; //продолжжительность минут
public:
	TMedicine() : TRemedy(), How(), Dose() {};
	TMedicine(string N, int L, int HM, int HC, int P, string H, int D) :
		TRemedy(N, L, HM, HC, P), How(H), Dose(D) {};
	TMedicine(const TMedicine& M) : TRemedy(M), How(M.How), Dose(M.Dose) {};
	virtual ~TMedicine() {};
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;
};
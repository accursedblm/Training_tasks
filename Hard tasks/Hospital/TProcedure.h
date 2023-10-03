#include "TRemedy.h"

class TProcedure :
	public TRemedy
{
protected:
	string How; //условие проведения
	int DTime; //продолжжительность минут
public:
	TProcedure() : TRemedy(), How(), DTime() {};
	TProcedure(string N, int L, int HM, int HC, int P, string H, int D) :
		TRemedy(N, L, HM, HC, P), How(H), DTime(D) {};
	TProcedure(const TProcedure& P) : TRemedy(P), How(P.How), DTime(P.DTime) {};
	virtual ~TProcedure() {};
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;
};

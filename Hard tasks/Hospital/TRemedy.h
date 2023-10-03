#pragma once
#include "TBase.h"

class TRemedy :
	public TBase
{
protected:
	string Name;	//название
	int Long;		//длительность применения
	int HowMany;	//сколько применить
	int HowCourse;	// кол-во курсов
	int Price;		//Цена
public:
	TRemedy() :
		Name(), Long(), HowMany(), HowCourse(), Price() {} //Инициализируются нулями через конструкторы по умолчанию ()
	TRemedy(string N, int L, int HM, int HC, int P) : 
		Name(N), Long(L), HowMany(HM), HowCourse(HC), Price(P) {}
	TRemedy(const TRemedy& R):
		Name(R.Name), Long(R.Long), HowMany(R.HowMany), HowCourse(R.HowCourse), Price(R.Price) {}
	virtual ~TRemedy() {}
	int& setget_HowCourse() {return HowCourse;}
	virtual void read(istream& in) override;
	virtual void write(ostream& out) const override;
	int HowPrice();
};


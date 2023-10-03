#pragma once
#include "TBase.h"

class TRemedy :
	public TBase
{
protected:
	string Name;	//��������
	int Long;		//������������ ����������
	int HowMany;	//������� ���������
	int HowCourse;	// ���-�� ������
	int Price;		//����
public:
	TRemedy() :
		Name(), Long(), HowMany(), HowCourse(), Price() {} //���������������� ������ ����� ������������ �� ��������� ()
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


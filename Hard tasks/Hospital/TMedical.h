#pragma once
#include "TRemedy.h"
#include "TMedicine.h"
#include "TProcedure.h"
class TMedical
{
private:
	TRemedy** R; //������ �������� �������
	int Count; //����� ������ �������
	int n; //���-�� ������������� �������
public:
	TMedical(int c = 5)
	{
		R = new TRemedy * [c];
		Count = c; n = 0;
	}
	~TMedical()
	{
		for (int i = 0; i < n; i++)
			delete R[i];
		delete[] R;
	}
	void Add_Console();
	int SumPrice();
	void write(ostream&) const;
	void del(int j);
	TRemedy* operator [] (int i) {return R[i];}
};


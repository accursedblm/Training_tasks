#include "TOrder.h"
TPatterns* TOrder::TmpPat;

void TOrder::Copy(const TOrder& z)
{
	if (!Fp)
		Fp = new TPatterns * [z.FMaxNum];
	FMaxNum = z.FMaxNum;
	FNum = z.FNum;
	for (int i = 0; i < FNum; i++)
	{
		char* s = z.Fp[i]->GetType();
		char c = s[7];
		switch (c)
		{
		case 'п': 
			Fp[i] = new TRectPatt;
			*((TRectPatt*)Fp[i]) = *((TRectPatt*)z.Fp[i]);
			break;
		case 'т':
			Fp[i] = new TTriangle;
			*((TTriangle*)Fp[i]) = *((TTriangle*)z.Fp[i]);
			break;
		case 'к':
			Fp[i] = new TCircle;
			*((TCircle*)Fp[i]) = *((TCircle*)z.Fp[i]);
			break;
		}
	}
}

void TOrder::Move(TOrder& z)
{
	FMaxNum = z.FMaxNum;
	FNum = z.FNum;
	Fp = z.Fp;
	z.Fp = nullptr;
}

TOrder& TOrder::operator=(const TOrder& z)
{
	if (this != &z)
	{
		for (int i = 0; i < FNum; i++)
			delete Fp[i];
		FNum = 0;
		if (FMaxNum != z.FMaxNum)
		{
			delete[]Fp; Fp = nullptr;
		}
		Copy(z);
	}
	return *this;
}

TOrder& TOrder::operator=(TOrder&& z)
{
	for (int i = 0; i < FNum; i++)
		delete Fp[i];
	delete[] Fp;
	Move(z);
	return *this;
}

int TOrder::Add(TPatterns* p)
{
	TPatterns** Ptmp;
	int Plus = 5;
	if (FNum = FMaxNum)
	{
		Ptmp = new (nothrow) TPatterns * [FMaxNum + Plus];
		if (!Ptmp)
			return -1;
		for (int i = 0; i < FNum; i++)
			Ptmp[i] = Fp[i];
		delete[] Fp;
		Fp = Ptmp;
		FMaxNum += Plus;
	}
	Fp[FNum++] = p;
	return 0;
}

TPatterns* TOrder::CreateGroup(char type)
{
	TPatterns* pp = nullptr;
	switch (type)
	{
	case 'п': 
		pp = (TPatterns*) new TRectPatt;
		break;
	case 'т':
		pp = (TPatterns*) new TTriangle;
		break;
	case 'к':
		pp = (TPatterns*) new TCircle;
		break;
	default:
		break;
	}
	return pp;
}

void TOrder::Read(char* types)
{
	int n, i;
	char type;
	TPatterns* pp;

	for (i = 0; i < FNum; i++)
		delete Fp[i];
	delete[] Fp;
	FNum = 0;
	cout << "Сколько групп стекла";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		type = GetNewType(types);
		pp = CreateGroup(type);
		if (Add(pp) == -1)
		{
			cout << "Места нет :(" << endl;
			break;
		}
		else
		{
			cout << "Позиция создана, введите информацию";
			pp->Read(cin);
		}
	}
	return;
}

void TOrder::Print() const
{
	cout << "Кол-во позиций в заказа:" << FNum << endl;
	float sum = 0;
	for (int i = 0; i < FNum; i++)
	{
		Fp[i]->Print(cout);
		cout << endl;
		sum += Fp[i]->GetCost();
	}
}

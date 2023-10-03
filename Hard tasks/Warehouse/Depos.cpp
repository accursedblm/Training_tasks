#include "Depos.h"

int Depos::searchBatch(const char* Name)
{
	Err = DEP_NO;
	for (int i = 0; i < BatchCount; i++)
		if (Strcmp(B[i].GetName(), Name) == 0)
		{
			Err = DEP_OK;
			return i;
		}
			
	return Err;
}

Depos::Depos(int Size, float Extra)
{
	if (Size > 0)
	{
		B = new (nothrow) Batch[Size];
		if (B == nullptr)
		{
			cout << "Ошибка выделения памяти";
			cin.get();
			exit;
		}
		SizeDep = Size;
		BatchCount = 0;
		Batch::SetExtra(Extra);
		Err = DEP_OK;
	}
	else
	{
		SizeDep = 0;
		BatchCount = 0;
		Batch::SetExtra(Extra);
		Err = DEP_NO;
	}
}

Depos::Depos(const Depos& d)
{
	*this = d;
}

Depos::Depos(Depos&& d)
{
	if (d.SizeDep > 0)
	{
		B = new (nothrow) Batch[d.SizeDep];
		if (B == nullptr)
		{
			cout << "Ошибка выделения памяти";
			cin.get();
			exit;
		}
		B = d.B;
		d.B = nullptr;
		//Batch::SetExtra()
		SizeDep = d.SizeDep;
		BatchCount = d.BatchCount;
		Err = DEP_OK;
	}
	else
		Err = DEP_NO;
}

Depos& Depos::operator = (const Depos& d)
{
	if (&d != this && d.SizeDep > 0)
	{
		if (B != nullptr)
			delete[] B;
		B = new (nothrow) Batch[d.SizeDep];
		if (B == nullptr)
		{
			cout << "Ошибка выделения памяти";
			cin.get();
			exit;
		}
		for (int i = 0; i < d.BatchCount; i++)
			B[i] = d.B[i];
		SizeDep = d.SizeDep;
		BatchCount = d.BatchCount;
		Err = DEP_OK;
	}
	else
		Err = DEP_NO;
	return *this;
}

int Depos::Delete(int iBatch)
{
	if (iBatch >= BatchCount)
		Err = DEP_NO;
	else
	{
		for (int i = iBatch; i < BatchCount - 1; i++)
			B[i] = B[i + 1];
		BatchCount--;
		Err = DEP_OK;
	}
	return Err;
}

int Depos::Add(Batch& b)
{
	if (BatchCount == SizeDep)
	{
		Err = DEP_FULL;
	}
	else if (b.GetName() == "NoName")
	{
		Err = DEP_NO;
	}
	else
	{
		B[BatchCount++] = b;
		Err = DEP_OK;
	}
	return Err;
}

Batch Depos::Sell(char* Name, float Cost)
{
	int m = -1;
	float p, pi, pt;
	Err = DEP_NO;

	if (BatchCount <= 0)
	{
		Batch b;
		return b;
	}
	else
	{
		pi = B[BatchCount - 1].GetPrice();
		p = Cost > pi ? Cost - pi : pi - Cost;
		m = BatchCount - 1;
	}
	for (int i = 0; i < BatchCount; i++)
	{
		if (Strcmp(B[i].GetName(), Name) == 0)
		{
			m = i; 
			pi = B[i].GetPrice();
			pt = Cost > pi ? Cost - pi : pi - Cost;
			p = pt < p ? pt : p;
			m = pt < p ? i : m;
			Batch b(B[m]);
			Delete(m);
			Err = DEP_OK;
			return b;
		}
	}
	Batch b;
	return b;
}

int Depos::GetError()
{
	return Err;
}

void Depos::Print(const char* Name)
{
	int pos = searchBatch(Name);
	if (pos < 0)
		cout << "Партия c таким именем не найдена";
	else
		cout << B[pos];
}

int Depos::Strcmp(const char* a, const char* b)
{
	int i = 0, answer = -2;
	while (1)
	{
		if (a == NULL || b == NULL)
			return answer;
		if (a[i] < b[i])
		{
			answer = -1;
			return answer;
		}
		else if (a[i] == b[i])
		{
			answer = 0;
		}
		else
		{
			answer = 1;
			return answer;
		}
		if (a[i] == '\0' || b[i] == '\0')
			return answer;
		i++;
	}
}
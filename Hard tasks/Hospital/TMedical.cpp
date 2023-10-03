#include "TMedical.h"

void TMedical::Add_Console()
{
	int k;
	cout << "Что добавить? (1 -процедура, 2-лекарство): " << endl;
	cin >> k;
	if (n == Count)
	{
		TRemedy** tmp = new TRemedy*[Count + 10];
		for (int i = 0; i < Count; i++)
		{
			tmp[i] = R[i];
		}
		delete[] R;
		R = tmp;
		Count += 10;
	}
	if (k == 1)
	{
		R[n++] = new TProcedure;
		R[n - 1]->read(cin);
	}
	else
	{
		R[n++] = new TMedicine;
		R[n - 1]->read(cin);
	}
}

int TMedical::SumPrice()
{
	int sum = 0;
	for (int i = 0; i < n; i++)
		sum += R[i]->HowPrice();
	return sum;
}

void TMedical::write(ostream& out) const
{
	for (int i = 0; i < n; i++)
	{
		out << i + 1;
		R[i]->write(out);
	}
}

void TMedical::del(int j)
{
	delete R[j];
	for (int i = j + 1; i < n; i++)
		R[i - 1] = R[i];
	n--;
}

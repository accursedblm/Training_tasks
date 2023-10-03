#include "Set.h"

void Set::print()
{
	cout << kol << ":{";
	for (int i = 0; i < kol - 1; ++i)
		cout << mas[i] << ", ";
	cout << mas[kol - 1] << "}" << endl;
}


Set Set::operator+(const Set& S)
{
	int i,j,c,f,k = 0;
	//Нужно определить кол-во элементов во множестве
	for (i = 0; i < S.kol; ++i)
	{
		f = 1; // Элемента нет - флаг
		for (int j = 0; j < kol; ++j)
			if (mas[j] == S.mas[i])
				f = 0;
		if (f == 1)
			++k;
	}
	//Создаем динамический массив в котором кол-во элементов больше на k чем кол-во исходных
	int* tmp = new int[kol + k];
	for (i = 0; i < kol; ++i)
		tmp[i] = mas[i];
	c = kol;
	for (i = 0; i < S.kol; ++i)
	{
		f = 1;
		for (j = 0; j < kol; ++j)
			if (mas[j] == S.mas[i])
			{
				f = 0; break;
			}
		if(f)
			tmp[c++]=S.mas[i];
	}
	Set Snew(c, tmp);
	delete[] tmp;
	return Snew;
}



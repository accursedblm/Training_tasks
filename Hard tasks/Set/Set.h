#pragma once
#include <iostream>

using namespace std;
class Set
{
private:
	int kol;
	int* mas;
public:
	Set()
	{
		kol = 1;
		mas = new int[1];
		*mas = 0;
	}
	Set(int n, int* m)
	{
		kol = n;
		mas = new int[n];
		for (int i = 0; i < n; i++)
			mas[i] = m[i];
	}
	Set(const Set& S)  //Обязательно нужно ставить & иначе будет рекурсия на конструкторе копирования
	{
		kol = S.kol;
		mas = new int[kol];
		for (int i = 0; i < kol; i++)
		{
			this->mas[i] = S.mas[i];
		}
	}
	~Set()
	{
		delete[] mas;
	}
	Set& operator = (const Set& S)
	{
		if (this != &S)
		{
			delete[] mas;
			kol = S.kol;
			mas = new int[kol];
			for (int i = 0; i < kol; i++)
				mas[i] = S.mas[i];
			return *this;
		}
	}
	Set operator + (const Set& S);
	void print();

};


#include "TString.h"
//#include <cstring>
//#include <iostream>
#include <new>

using namespace std;

void TString::printd(char* a)
{
	if (pf)
		cout << endl << "деструктор.удаляем адрес: " << &a << endl;
}
void TString::printc(char* a)
{
	if (pf)
		cout << endl << "конструктор.создается адрес: " << &a << endl;
}
TString::TString(const TString& str)
{
	*this = str;
}
TString::TString(const char* str)
{
	if (s != nullptr)
	{
		delete[] s;
		s = nullptr;
		printd(s);
	}
	for (Len = 0; str[Len] != '\0' && Len != 10000; Len++) 
	{
		if (Len == 10000)
		{
			Len = 0; return;
		}
	}
	Len += 1;
	s = new (nothrow) char[Len];
	if (s == nullptr)
	{
		cout << "ошибка выделения памяти под строку";
	}
	else
	{
		printc(s);
		strcpy_s(s, sizeof(char) * Len, str);
	}
}
TString& TString::operator = (const TString& str)
{
	if (&str != this)
	{
		if (s != nullptr)
		{
			delete[] s;
			s = nullptr;
		}
		Len = str.Len;
		s = new (nothrow) char[Len];
		if (s == nullptr)
		{
			Len = 0;
		}
		else
		{
			printc(s);
			strcpy_s(s, sizeof(char) * Len, str.s);
		}
	}
	return *this;
}
TString TString::operator + (const TString& str)
{
	if (!str.Len)
		return *this;
	char* st = new (nothrow) char[Len+str.Len-1];
	if (st == nullptr)
	{
		cout << "ошибка выделения памяти под строку";
		return *this;
	}
	printc(st);
	strcpy_s(st, Len + str.Len - 1, s);
	printc(st);
	strcat_s(st, Len + str.Len - 1, str.s);
	printc(st);
	TString Res(st);
	delete[] st;
	return Res;
}
int TString::operator == (const TString& str)
{
	return (!strcmp(this->s, str.s)) ? 1 : 0;
}
int TString::operator != (const TString& str)
{
	return (int) !(*this == str);
}
int TString::operator < (const TString& str)
{
	return (strcmp(this->s, str.s) < 0) ? 1 : 0;
}
int TString::operator <= (const TString& str)
{
	return (*this < str || *this == str) ? 1 : 0;
}
int TString::operator > (const TString& str)
{
	return (strcmp(this->s, str.s) > 0) ? 1 : 0;
}
int TString::operator >= (const TString& str)
{
	return (*this > str || *this == str) ? 1 : 0;
}
ostream& operator<<(ostream& out, const TString& S)
{
	out << (char*) S;
	return out;
}
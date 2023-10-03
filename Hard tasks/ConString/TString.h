#pragma once
#include <cstring>
#include <iostream>
using namespace std;
class TString
{
private: 
	char* s = nullptr; 
	int Len;
	bool pf = false;
	void printd(char*);
	void printc(char*);
public:
	TString(int L = 0)
	{
		Len = L;
	}
	TString(const TString&);
	TString(const char*); 
	~TString()
	{
		printd(s);
		delete[] s;
	}
	operator char* () const
	{
		return s;
	}
	TString& operator = (const TString& str);
	TString operator + (const TString&);
	int operator == (const TString&);
	int operator!= (const TString&);
	int operator < (const TString&);
	int operator <= (const TString&);
	int operator > (const TString&);
	int operator >= (const TString&);
	friend ostream& operator << (ostream& out, const TString& S);
};
#pragma once
#include <iostream>
#include <fstream>
using namespace std;
struct shifr
{
	unsigned int k1 : 8;
	unsigned int k2 : 8;
	unsigned int k3 : 8;
	unsigned int k4 : 8;
};
shifr f(unsigned int n); //функция шифрования
unsigned int def(shifr S); //Расшифровка
void print(shifr S, ostream& out);
bool up(shifr& a, shifr& b);
bool down(shifr& a, shifr& b);
void SORT(shifr* arr, int n, bool(*f)(shifr& a, shifr& b));

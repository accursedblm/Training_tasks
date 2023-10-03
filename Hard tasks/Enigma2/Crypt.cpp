#include "Crypt.h"

shifr f(unsigned int n)
{
	shifr tmp;
	tmp.k1 = (n << 24) >> 24;
	//tmp.k1 = n&255; //0xFF
	tmp.k2 = (n << 16) >> 24;
	//tmp.k2 = (n&0xFF00) >> 8;
	tmp.k3 = (n << 8) >> 24;
	//tmp.k2 = (n&0xFF0000) >> 16;
	tmp.k4 = n >> 24;
	//tmp.k2 = (n&0xFF000000) >> 24;
	return tmp;
}
unsigned int def(shifr S) //Расшифровка
{
	unsigned int n = (((((S.k4 << 8) | S.k3) << 8) | S.k2) << 8) | S.k1;
	return n;
}
void print(shifr S, ostream& out)
{
	out << "Шифр: " << S.k4 << "\t" << S.k3 << "\t" << S.k2 << "\t" << S.k1 << endl;
}
bool up(shifr& a, shifr& b)	//Сортировка вверх
{
	return (a.k4 > b.k4) ||
		(a.k4 == b.k4 && a.k3 > b.k3) ||
		(a.k4 == b.k4 && a.k3 == b.k3 && a.k2 > b.k2) ||
		(a.k4 == b.k4 && a.k3 == b.k3 && a.k2 == b.k2 && a.k1 > b.k1);
}
bool down(shifr& a, shifr& b)	//Сортировка вниз
{
	return (a.k4 < b.k4) ||
		(a.k4 == b.k4 && a.k3 < b.k3) ||
		(a.k4 == b.k4 && a.k3 == b.k3 && a.k2 < b.k2) ||
		(a.k4 == b.k4 && a.k3 == b.k3 && a.k2 == b.k2 && a.k1 < b.k1);
}
void SORT(shifr* arr, int n, bool(*f)(shifr& a, shifr& b)) //Сортировка
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (f(arr[j], arr[j + 1]))
			{
				shifr tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
}
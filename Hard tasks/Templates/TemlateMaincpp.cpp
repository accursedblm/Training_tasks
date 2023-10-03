#include <iostream>
#include "Windows.h"
#pragma warning(disable : 4996)
using namespace std;

template<class T>
T* del_el(T* arr, int& n, T e)
{
	int pos = 0, kol = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] != e)
			arr[pos++] = arr[i];
		else
			kol++;
	}
	T* p;
	if (kol == n)
	{
		delete[] arr;
		arr = nullptr;
	}
	else if (kol)
	{
		p = new T[n - kol];
		for (int i = 0; i < n - kol; i++)
			p[i] = arr[i];
		delete[] arr;
		arr = p;
	}
	n = n - kol;
	return arr;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char S[100];
	int n;
	cout << "¬ведите строку" << endl;
	cin.getline(S, 100);
	char* st = new char[strlen(S) + 1];
	strcpy(st, S);
	char del;
	cout << "¬ведите удал€емый символ: " << endl;
	del = cin.get();
	n = strlen(st)+1;
	st = del_el(st, n, del);
	cout << "–езультат: " << endl << st << endl;
	cout << "¬ведите кол-во целых элементов" << endl;
	cin >> n;
	int* arr = new int[n];
	cout << "¬ведите элементы массива" << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "¬ведите элементи дл€ удалени€" << endl;
	int num;
	cin >> num;
	arr = del_el(arr, n, num);
	cout << "–езультат: " << endl;
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}
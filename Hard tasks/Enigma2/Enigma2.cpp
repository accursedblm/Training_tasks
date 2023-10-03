// Enigma2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <windows.h>
#include "Crypt.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите натуральное число" << endl;
	unsigned int n;
	cin >> n;
	shifr s = f(n);
	print(s, cout);
	cout << "Исходное число" << def(s) << endl;

	cout << "Работа с файлом" << endl;
	ifstream fin("Shifr.txt");
	ofstream fout("result.txt");
	int kol = 0;
	shifr arr[20];
	while (1)
	{
		fin >> n;
		if (fin.eof())
			break;
		s = f(n);
		arr[kol++] = s;
	}
	for (int i = 0; i < kol; i++)
	{
		print(arr[i], cout);
		print(arr[i], fout);
	}
	cout << "Сортировка по убыванию" << endl;
	SORT(arr, kol, down);
	for (int i = 0; i < kol; i++)
	{
		print(arr[i], cout);
		print(arr[i], fout);
	}

}

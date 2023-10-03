// Enigma.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include "Crypt.h"

using namespace std;
using namespace Crypt;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int c[3];
	fstream fin, fout;
	crInt i;

	cout << "Введите три целых числа через пробел" << endl;
	cin >> c[0] >> c[1] >> c[2];

	fin = fstream("tempin.txt", ios::binary | ios::in | ios::out); //Побитовое ИЛИ значек |
	if (!fin) //Нет привязки к файлу
		return -1;
	fout = fstream("tempout.txt", ios::binary | ios::in | ios::out);
	if (!fout) //Нет привязки к файлу
		{ fin.close(); return -2;}

	fin.write((char*)&c[0], sizeof(int));
	fin.write((char*)&c[1], sizeof(int));
	fin.write((char*)&c[2], sizeof(int));

	fin.seekg(0, fin.beg);
	cout << endl << "Зашифрованные числа: " << endl;
	while (1)
	{
		fin.read((char*)&i, sizeof(i));
		if (fin.eof())
			break;
		encryptor(i);
		cout << *((int*)&i) << " ";
		fout.write((char*)&i, sizeof(i));
	}
	fin.close();

	cout << endl << "Расшифрованные числа: " << endl;
	
	fout.clear();
	fout.seekg(0, fout.beg);
	while (1)
	{
		fout.read((char*)&i, sizeof(i));
		if (fout.eof())
			break;
		decryptor(i);
		cout << *((int*)&i) << " ";
	}
	fout.close();
}

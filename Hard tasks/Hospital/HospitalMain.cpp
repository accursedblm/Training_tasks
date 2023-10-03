#include <iostream>
#include <Windows.h>
#include "TMedical.h"

using namespace std;

int main()
{
	//Русифицируем консоль
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TMedical M; //Создали объект
	int k; //номер
	int kol;
	cout << "Сколько назначено лечебных средств";
	cout << endl;
	cin >> kol;
	for(int i=0;i<kol;++i) //заполнение контейнера
		M.Add_Console();
	cout << "Потрачено на лечение" << M.SumPrice() << endl;
	cout << "Лечение состоит из:" << endl;
	M.write(cout); //Распечатка. Выводим на дисплей
	cout << "Введите номер для удаления объекта";
	cin >> k;
	M.del(k-1); //Удаление (к-1 т.к. нумерация с 0)
	//Распечатка
	M.write(cout);
	cout << "Введите номер элемента для изменения курса" << endl;
	cin >> k;
	cout << "Введите новое кол-во курсов" << endl;
	cin >> kol;
	M[k-1]->setget_HowCourse() = kol;
	//Распечатка
	M.write(cout);
	return 0;
}
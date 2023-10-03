// PhoneDirectory.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>		//Вывод
//#include <cstring>		//Библиотека работы со строками в терминальном формате
#include "windows.h"	//Для руссификации консоли windows
#include <cstdlib>
#include <locale>		//Для руссификации
#include "NOTEB.h"

using namespace std;
using namespace NOTEB;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	bool full_screening;
	int nsel;
	cout << "Показывать удаленные записи?(0-нет,1-да): ";
	cin >> full_screening;
	set_mode_screening(full_screening);
	cin.get();
	int kod;
	if ((kod = notebook_open((char*)"a.txt")) == -1)
	{
		cout << "Ошибка открытия";
		return 0;
	}
	if (!kod)
	{
		cout << "Ошибка выделяемой памяти";
		return 0;
	}
	do
	{
		cout << "1-доб,2-просм,3-найти,4-удалить,5-выйти" << endl;
		cin >> nsel;
		cin.get();
		char title[LENFIO];
		switch (Action(nsel))
		{
		case Action::ADD:
			add_to_notebook();
			break;
		case Action::PRINT:
			notebook_display();
			break;
		case Action::SEARCH:
			cout << "Введите фамилию для поиска - ";
			cin.getline(title, LENFIO);
			if (!search_person(title))
				cout << "Поиск не дал результатов" << endl;
			break;
		case Action::DEL:
			cout << "Введите фамилию для удаления - ";
			cin.getline(title, LENFIO);
			if (delete_person(title))
				cout << "Запись удалена" << endl;
			else
				cout << "Таких нет" << endl;

		}
	} while (nsel != int(Action::CLOSE));
	NOTEB::notebook_close();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

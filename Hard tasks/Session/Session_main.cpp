#include "Session.h"
#include <Windows.h>

//Это не полныйный проект. Попросили проверить/исправить ошибки в коде
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	vector <students> groupA;
	string surname;
	cout << "Введите фамилии студентов:" << endl;
	while (cin >> surname)
	{
		groupA.push_back(surname);
	}
	cout << "Студентов, сдающих сессию:\t" << groupA.size() << endl;
	return 0;
}
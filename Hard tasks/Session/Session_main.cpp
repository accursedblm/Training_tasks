#include "Session.h"
#include <Windows.h>

//��� �� ��������� ������. ��������� ���������/��������� ������ � ����
int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	vector <students> groupA;
	string surname;
	cout << "������� ������� ���������:" << endl;
	while (cin >> surname)
	{
		groupA.push_back(surname);
	}
	cout << "���������, ������� ������:\t" << groupA.size() << endl;
	return 0;
}
#include "Session.h"
ifstream stin = ifstream("StudentsGroup.txt");
ofstream stout = ofstream("StudentsGroup.txt");

students::students(string sur)
{
	Surname = sur;
	cout << "�������� �����������" << endl;
	for (int i = 0; i < ML; i++)
	{
		exam.emplace(objects[i], 0);
		stout << Surname << endl;
		stout << objects[i] << '\n' << '0' << "\n\n";
	}
}

void students::add_grade()
{
	cout << "������� �������:\t";
	string obj;
	cin >> obj;
	auto gr = exam.find(obj);
	if (gr != exam.end())
	{
		cout << "������� ������ �� ��������" << obj << ":\t";
		cin >> gr->second;
	}
	else
		cout << "������� �� ������." << endl;
}
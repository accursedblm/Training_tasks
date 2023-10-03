#include "Session.h"
ifstream stin = ifstream("StudentsGroup.txt");
ofstream stout = ofstream("StudentsGroup.txt");

students::students(string sur)
{
	Surname = sur;
	cout << "Вызвался конструктор" << endl;
	for (int i = 0; i < ML; i++)
	{
		exam.emplace(objects[i], 0);
		stout << Surname << endl;
		stout << objects[i] << '\n' << '0' << "\n\n";
	}
}

void students::add_grade()
{
	cout << "Введите предмет:\t";
	string obj;
	cin >> obj;
	auto gr = exam.find(obj);
	if (gr != exam.end())
	{
		cout << "Введите оценку по предмету" << obj << ":\t";
		cin >> gr->second;
	}
	else
		cout << "Предмет не найден." << endl;
}
#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <string>
#include <fstream>
#include <iterator>
#include <algorithm>
#include "RusConsole.h"

using namespace std;
void Zad1();
void Zad2();
void Zad3();

int main()
{
	
	RusCon();
	//Zad1();
	//Zad2();
	Zad3();
	return 0;
}

void Zad1()
{
	//������ ������ ������� �������� ������� ����� ������ �� �����. ���������� ������������ ����� �� N ����.
	ifstream fin("input.txt");
	if (!fin)
	{
		cout << "���� �� ������ :'(";
		exit;
	}
	queue<string>first;
	string name;
	int i = 0, n;
	while (!fin.eof())
	{
		fin >> name;
		cout << (++i) << " " << name << endl;
		first.push(name);
	}
	cout << "������� ���-�� ����: ";
	cin >> n;
	queue<string>* second = new queue<string>[n];
	while (!first.empty())
	{
		second[(i++) % n].push(first.front()); //(i++) % n ������� �� ������� ����� ������� ���� ������
		first.pop();
	}

	for (i = 0; i < n; i++)
	{
		cout << (i + 1) << endl;
		while (!second[i].empty())
		{
			cout << second[i].front() << endl;
			second[i].pop();
		}
	}
	delete[] second;
	fin.close();
}

void Zad2()
{
	//� ���������� �������� N ����� �����������. � ������ ���� ����������� ��� ����������, ���-�� ������� � ����. ��� ������ �������
	//� ���� ���� ���-�� � ��� �������. 1. ���������� ������� ������� �������� 2. ���������� ���-�� ������� ���������� ������.
	map<string, int>Name;
	map<string, int>tovar;
	string F, T;
	int n, kol, price, i, j, poz;
	cout << "������� ���-�� �������" << endl;
	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << "������� �������";
		cin >> F;
		cout << "���-�� ��������� �������";
		cin >> poz;


		cout << "����� \t ����\t ���-��" << endl;
		for (j = 1; j <= poz; j++)
		{
			cin >> T;
			cin >> price >> kol;
			if (Name.count(F))
				Name[F] += price * kol;
			else
				Name[F] = price * kol;
			if (tovar.count(T))
				tovar[T] += kol;
			else
				tovar[T] = kol;
		}
	}
	cout << "���������� \t �������" << endl;
	for (map<string, int>::iterator p = Name.begin(); p != Name.end(); p++)
	{
		cout << p->first << "\t" << p->second << endl;
	}
	cout << "����� \t ���-��" << endl;
	for (map<string, int>::iterator p = tovar.begin(); p != tovar.end(); p++)
	{
		cout << p->first << "\t" << p->second << endl;
	}
}

int vis(int year)
{
	/*���������� ��� ��� ��� ������� �������� �� 4, �� ��� ���� �� 100 �� ��������; ��� �������� �� 400.*/
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
		return 1;
	else
		return 0;
}

void init(istream& in, map<string, int>& Ship)
{
	//������� ���������� �� �������� �������� � ���� . ����, ���� ������ � �������. ������� ���� � ������� ���� ������� ��������� � �����
	int arr[2][13] = { {0,31,28,31,30,31,30,30,31,30,31,30,31},{0,31,29,31,30,31,30,30,31,30,31,30,31} };
	//������ ���� dd.mm.yyyy
	string name, date1, date2;
	int day1, day2, month1, month2,
		year1, year2, d_in_y1=0, d_in_y2=0,
		n, kol;
	in >> n;
	for (int i = 1; i <= n; i++)
	{
		in >> name >> date1 >> date2;
		day1 = (date1[0] - '0') * 10 + (date1[1] - '0');
		day2 = (date2[0] - '0') * 10 + (date2[1] - '0');
		month1 = (date1[3] - '0') * 10 + (date1[4] - '0');
		month2 = (date2[3] - '0') * 10 + (date2[4] - '0');
		year1 = (date1[6] - '0') * 1000 + (date1[7] - '0')*100 + (date1[8] - '0') * 10 + (date1[9] - '0');
		year2 = (date2[6] - '0') * 1000 + (date2[7] - '0') * 100 + (date2[8] - '0') * 10 + (date2[9] - '0');
		d_in_y1 = day1;
		for (int j = 1; j < month1; j++)
			d_in_y1 += arr[vis(year1)][j];
		d_in_y2 = day2;
		for (int j = 1; j < month2; j++)
			d_in_y2 += arr[vis(year2)][j];
	}
	kol = d_in_y2 - d_in_y1 + 1;
	if (Ship.count(name))
		Ship[name] += kol;
	else
		Ship[name] = kol;
}
void print(ostream& out, map<string, int>& Ship)
{
	out << "�������� \t ���-�� ���� \n";
	for (map<string, int>::iterator p = Ship.begin(); p != Ship.end(); p++)
		out << p->first << "\t\t" << p->second << endl;
}
void Zad3()
{
	map<string, int>Ship;
	ifstream fin("getfile.txt");
	ofstream fout("putfile.txt");
	if (!fin)
	{
		cout << "���� �� ������ :'(";
		exit;
	}
	init(fin, Ship);
	print(cout, Ship);
	print(fout, Ship);
	fin.close();
	fout.close();
}

void Zad4()
{
	list<int>S;
	ifstream fin("a.txt");
	ofstream fout("b.txt");
	if (!fin)
	{
		cout << "���� �� ������ :'(";
		exit;
	}
	istream_iterator<int>file_in(fin);
	istream_iterator<int>end_of_stream;
	copy(file_in, end_of_stream, back_inserter(S));
	ostream_iterator<int> file_out(fout, " ");
	copy(S.begin(), S.end(), file_out);
	ostream_iterator<int> cons_out(cout, "");
	copy(S.begin(), S.end(), cons_out);
	fin.close();
	fout.close();
}
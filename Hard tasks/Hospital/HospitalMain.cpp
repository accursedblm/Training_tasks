#include <iostream>
#include <Windows.h>
#include "TMedical.h"

using namespace std;

int main()
{
	//������������ �������
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TMedical M; //������� ������
	int k; //�����
	int kol;
	cout << "������� ��������� �������� �������";
	cout << endl;
	cin >> kol;
	for(int i=0;i<kol;++i) //���������� ����������
		M.Add_Console();
	cout << "��������� �� �������" << M.SumPrice() << endl;
	cout << "������� ������� ��:" << endl;
	M.write(cout); //����������. ������� �� �������
	cout << "������� ����� ��� �������� �������";
	cin >> k;
	M.del(k-1); //�������� (�-1 �.�. ��������� � 0)
	//����������
	M.write(cout);
	cout << "������� ����� �������� ��� ��������� �����" << endl;
	cin >> k;
	cout << "������� ����� ���-�� ������" << endl;
	cin >> kol;
	M[k-1]->setget_HowCourse() = kol;
	//����������
	M.write(cout);
	return 0;
}
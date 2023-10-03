#include <iostream>
#include <windows.h>
#include "TBox.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TBox box1(100, 100, 100);
	TBox box2(20, 20, 20);
	float x1, y1, z1, x2, y2, z2;

	cout << "������: � ������� 100�100�100 ��������� " << box1.HowMachTkInside(box2) << " ������� 20�20�20\n";
	cout << "������� ������� ������� 1:\n";
	cin >> x1 >> y1 >> z1;
	cout << "������� ������� ������� 2:\n";
	cin >> x2 >> y2 >> z2;
	cout << "� ������� "; box1.BoxResize(x1, y1, z1).Print(); 
	cout << " ��������� " << box1.HowMachTkInside(box2.BoxResize(x2, y2, z2)) << " ������� "; box2.Print(); cout << endl;
	cout << "����� ������ ������� = " << box1.Volume();
	cout << "����� ������ ������� = " << box2.Volume();
	return 0;
}
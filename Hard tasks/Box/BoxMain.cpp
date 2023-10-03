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

	cout << "Пример: В коробку 100х100х100 вмещается " << box1.HowMachTkInside(box2) << " коробок 20х20х20\n";
	cout << "Введите размеры коробки 1:\n";
	cin >> x1 >> y1 >> z1;
	cout << "Введите размеры коробки 2:\n";
	cin >> x2 >> y2 >> z2;
	cout << "В коробку "; box1.BoxResize(x1, y1, z1).Print(); 
	cout << " вмещается " << box1.HowMachTkInside(box2.BoxResize(x2, y2, z2)) << " коробок "; box2.Print(); cout << endl;
	cout << "Объем первой коробки = " << box1.Volume();
	cout << "Объем второй коробки = " << box2.Volume();
	return 0;
}
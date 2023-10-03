#include "Depos.h"
#include "Windows.h"

/*
Программа с иерархией классов, моделирующих понятия "товар",
"упаковка товара","партии товаров на склада","склад спартиями товара":

Goods(товары) -> Pack(упаковки товаров) -> Batch(партии тов-в склада) 
и Depos(склад с партиями товара)
*/
Batch cb(const char Nam[], float Pr, const char Inf[], int Cou, int Num, float Extra = 1.0)
{
	Batch newB(Nam, Pr, Inf, Cou, Num, Extra);
	return newB;
}

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Batch newB1("Шоколадка", 50.0, "Очень вкусная", 1, 5, 1.0);
	Batch newB2("Пряники", 30.0, "Мятные", 3, 5, 2.0);
	Batch newB3("Зефир", 70.0, "В шоколаде", 2, 3, 3.0);
	Depos sklad1(3), sklad3(2);

	sklad1.Add(newB1);
	sklad1.Add(newB2);
	sklad1.Add(newB3);
	sklad1.Add(newB3);

	Depos sklad2(sklad1);
	sklad3 = sklad1;

	Batch::SetExtra(5.0);

	cout << "______________" << endl << "Склад1" << endl;
	sklad1.Print("Шоколадка");
	sklad1.Print("Зефир");
	sklad1.Print("Пряники");
	cout << "______________" << endl << "Склад2" << endl;
	sklad2.Print("Шоколадка");
	sklad2.Print("Зефир");
	sklad2.Print("Пряники");
	cout << "______________" << endl << "Склад3" << endl;
	sklad3.Print("Шоколадка");
	sklad3.Print("Зефир");
	sklad3.Print("Пряники");

	return 0;
}

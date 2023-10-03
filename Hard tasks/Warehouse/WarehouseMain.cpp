#include "Depos.h"
#include "Windows.h"

/*
��������� � ��������� �������, ������������ ������� "�����",
"�������� ������","������ ������� �� ������","����� ��������� ������":

Goods(������) -> Pack(�������� �������) -> Batch(������ ���-� ������) 
� Depos(����� � �������� ������)
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
	Batch newB1("���������", 50.0, "����� �������", 1, 5, 1.0);
	Batch newB2("�������", 30.0, "������", 3, 5, 2.0);
	Batch newB3("�����", 70.0, "� ��������", 2, 3, 3.0);
	Depos sklad1(3), sklad3(2);

	sklad1.Add(newB1);
	sklad1.Add(newB2);
	sklad1.Add(newB3);
	sklad1.Add(newB3);

	Depos sklad2(sklad1);
	sklad3 = sklad1;

	Batch::SetExtra(5.0);

	cout << "______________" << endl << "�����1" << endl;
	sklad1.Print("���������");
	sklad1.Print("�����");
	sklad1.Print("�������");
	cout << "______________" << endl << "�����2" << endl;
	sklad2.Print("���������");
	sklad2.Print("�����");
	sklad2.Print("�������");
	cout << "______________" << endl << "�����3" << endl;
	sklad3.Print("���������");
	sklad3.Print("�����");
	sklad3.Print("�������");

	return 0;
}

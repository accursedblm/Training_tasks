#include <iostream>
#include "Set.h"
#include "Windows.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int arr[20];
	int i,n;
	cout << "������ 1-�� ���������: ";
	cin >> n;
	cout << "������� ��. ��-�� ����� ������:" << endl << "  ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	Set A(n, arr);
	cout << endl;

	cout << "������ 2-�� ���������: ";
	cin >> n;
	cout << "������� ��. ��-�� ����� ������:" << endl << "  ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	Set B(n, arr);
	Set C = A + B; // ������(�����) ������  C.operator=(A.operator+(B))

	cout << endl;
	cout << "��������� �" << endl << "  ";
	A.print();
	cout << "��������� B" << endl << "  ";
	B.print();
	cout << "��������� C" << endl << "  ";
	C.print();
}

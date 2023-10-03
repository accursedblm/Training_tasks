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
	cout << "Размер 1-го множества: ";
	cin >> n;
	cout << "Введите эл. мн-ва через пробел:" << endl << "  ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	Set A(n, arr);
	cout << endl;

	cout << "Размер 2-го множества: ";
	cin >> n;
	cout << "Введите эл. мн-ва через пробел:" << endl << "  ";
	for (i = 0; i < n; i++)
		cin >> arr[i];
	Set B(n, arr);
	Set C = A + B; // полная(явная) запись  C.operator=(A.operator+(B))

	cout << endl;
	cout << "Множество А" << endl << "  ";
	A.print();
	cout << "Множество B" << endl << "  ";
	B.print();
	cout << "Множество C" << endl << "  ";
	C.print();
}

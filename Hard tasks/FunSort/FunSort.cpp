// FunSort.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <windows.h>
#include <iomanip>
#include "FSORT.h"

using namespace std;
using namespace FSORT;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int i;
    Ftype A[3];
    Ftype* Ft = A;

    cout << "Нужно заполнить массив структур для сортировки" << endl
         << "Введите строку формата Имя, Фамилия, Индекс через пробел (повторить три раза)" << endl;
    for (i = 0; i < 3; i++)
        cin >> A[i].Name >> A[i].Lastname >> A[i].Index;

    FSort(Ft, 3, CompFtype,fDown);

    cout << "Отсортированный массив структур: " << endl;
    for (i = 0; i < 3; i++)
         cout << setw(20) << A[i].Name << setw(20) << A[i].Lastname << setw(5) << A[i].Index << endl;


}


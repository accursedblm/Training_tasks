#pragma warning (disable : 4996)
#include <cstring> //���������� ������ �� �������� � ������������ �������
#include <iostream> //�����
#include "windows.h"
#include <cstdlib>
#include <locale>
#include <cmath>
#include <string.h>
#include "Zadachi.h"

using namespace std;
using namespace Zadachi;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//system("chcp 1251");
	
	Zadachi::Zadacha105d();
	//����� ���������
	cout << endl;
	system("pause");
	return 0;
}
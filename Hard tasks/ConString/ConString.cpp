#include <iostream>
#include "TString.h"
#include "Windows.h"

using namespace std;
int main()
{
	//double a = 2.3, b = 2.9, c;
	//cout << "a= " << (int)a << " b= " << (int)b;
	//cin >> c;
	//return 0;

	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TString str1("Hello ");
	TString str2("World! :)");
	TString str;
		str = str1 + str2;
	TString str3(str);

	cout << " Строка 1:" << endl
		<< str1 << endl
		<< " Строка 2:" << endl
		<< str2 << endl
		<< " Строка  :" << endl
		<< str3 << endl
		<< " Строка 3:" << endl
		<< str3 << endl
		<< " Cтрока 1 > Строки 3" << endl 
		<< (str1 > str3) << endl
		<< " Cтрока 1 < Строки 3" << endl
		<< (str1 < str3) << endl
		<< " Cтрока 1 <= Строки 3" << endl
		<< (str1 <= str3) << endl
		<< " Cтрока 1 >= Строки 3" << endl
		<< (str1 >= str3) << endl
		<< " Cтрока == Строке 3" << endl
		<< (str == str3) << endl
		<< " Cтрока != Строке 3" << endl
		<< (str != str3) << endl;
	return 0;
}
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

	cout << " ������ 1:" << endl
		<< str1 << endl
		<< " ������ 2:" << endl
		<< str2 << endl
		<< " ������  :" << endl
		<< str3 << endl
		<< " ������ 3:" << endl
		<< str3 << endl
		<< " C����� 1 > ������ 3" << endl 
		<< (str1 > str3) << endl
		<< " C����� 1 < ������ 3" << endl
		<< (str1 < str3) << endl
		<< " C����� 1 <= ������ 3" << endl
		<< (str1 <= str3) << endl
		<< " C����� 1 >= ������ 3" << endl
		<< (str1 >= str3) << endl
		<< " C����� == ������ 3" << endl
		<< (str == str3) << endl
		<< " C����� != ������ 3" << endl
		<< (str != str3) << endl;
	return 0;
}
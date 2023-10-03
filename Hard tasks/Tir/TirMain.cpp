#include "Windows.h"
#include "TTarget.h"

using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TTarget t(5);
	TPoint p;
	int n;
	cout << "Кол-во выстрелов" << endl;
	cin >> n;
	cout << "Введите выстрелы" << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		t >> p;
	}
	cout << t;
	return 0;
}

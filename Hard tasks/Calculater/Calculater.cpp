#include <iostream>
#include <windows.h>
#include "TCalculater.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;

	cout << "Введите кол-во слагаемых" << endl;
	cin >> n;

	if (n <= 0)
		return 0;

	TCalculater A, B, C(10);
	float x;

	for (int i = 1; i <= n; i++)
	{
		cout << endl << "Введите " << i << "-ое значение" << endl;
		cin >> x;
		//cin.ignore(cin.rdbuf()->in_avail());
		A.Add(x);
		(C += x) += x;
		if (x < 0)
			B.Add(x);
		cout << "A=" << A.FResult() << endl;
		cout << "Предудущее A=" << A.FlastArg() << endl;
		cout << "B=" << B.FResult() << endl;
		cout << "Предудущее B=" << B.FlastArg() << endl;
		cout << "C=" << C.FResult() << endl;
		cout << "Предудущее C=" << C.FlastArg() << endl;
		cout << endl;
	}
			A = (++B)++;
		cout << "A=" << A.FResult() << endl;
		cout << "Предудущее A=" << A.FlastArg() << endl;
		cout << "B=" << B.FResult() << endl;
		cout << "Предудущее B=" << B.FlastArg() << endl;
		cout << "C=" << C.FResult() << endl;
		cout << "Предудущее C=" << C.FlastArg() << endl;
		cout << endl;
			
			A += 2;
		cout << "A += 2 результат = " << A.FResult() << endl;
			A *= 2;
		cout << "A *= 2 результат = " << A.FResult() << endl;
			A /= 2;
		cout << "A /= 2 результат = " << A.FResult() << endl;
}



#include <iostream>
#include "windows.h"
using namespace std;


class A
{
public:
	A();
	~A();
	A(const A& x)
	{
		cout << "���������� �����������" << endl;
	}
	A(A&& x)
	{
		cout << "���������� �����������" << endl;
	}

private:

};

A::A()
{
}

A::~A()
{
}

void test(A&& x) 
{
	cout << "���������" << endl;
}
void test(A& x)
{
	cout << "������" << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	A a;

	test(A());
	test(a);
	return 0;
}
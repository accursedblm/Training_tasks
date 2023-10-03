#include <memory>
#include <list>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <iterator>
#include "RusConsole.h"

using namespace std;
class Ta
{
	int a{ 123 };
public:
	static int Count;
	Ta(int _a) :a(_a)
	{
		Count++;
	}
	Ta() = delete;
	Ta(const Ta&) = delete;
	Ta(Ta&&) = delete;
	~Ta()
	{
		Count--;
		cout << endl << "~Ta:Count=" << Count;
	}
	int& A()& //������������ & ����� ������� ������ ������� ��� ������ ������ ������ ������������ � ��������� lvalue ������, �.�. �� ������
	{
		return a;
	}
	int A()&&
	{
		return a; //������� && �������� ������� ����� �������
	}
};

int Ta::Count = 0;
using ShPtrTa = std::shared_ptr<Ta>;
using ListShPtrTa = std::list<ShPtrTa>;

void Transform(ShPtrTa& pTa)
{
	pTa->A() *= 3;
}

void Transform1(int& i)
{
	i = i - 1;
}

int Transform2(int& i)
{
	return i + 5;
}

void FillList(ListShPtrTa& List)
{
	ShPtrTa p1(new Ta(111));
	ShPtrTa p2(new Ta(222));
	ShPtrTa p3(new Ta(303));
	ShPtrTa p4(new Ta(444));
	List = ListShPtrTa({ p1, p2, p3, p4 });
}

ostream& operator << (ostream& out, Ta& pTa)
{
	return out << pTa.A();
}

ostream& operator << (ostream& out, const ShPtrTa& pTa)
{
	return out << *pTa.get(); // get ���� ����� �� ��������� ������
}

int main()
{
	RusCon();
	cout << "������ � ������ �����������" << endl;
	{
		ShPtrTa pA(new Ta(777));
		{
			ShPtrTa pB(new Ta(888));
			{
				ShPtrTa pC(pB);
			}
		}
	}
	//������ ���������� � �������������� ��������
	cout << endl << "������ ���������� � �������������� ��������" << endl;
	std::list<int> listInt{ 1, 4, -2, 5, 3, 0 };
	std::list<int>::iterator iT = min_element(listInt.begin(), listInt.end()); //end - ��������� ����� ���������� ��������
	int min = *iT;
	cout << "algorithm:min_element=" << min << endl;
	iT = max_element(listInt.begin(), listInt.end());
	int max = *iT;
	cout << "algorithm:max_element=" << max << endl;
	std::list<int>::iterator BEGIN = listInt.begin();
	std::list<int>::iterator END = --listInt.end();
	cout << "������ ������� ������ " << *BEGIN << endl;
	cout << "��������� ������� ������ " << *END << endl;
	iT = min_element(listInt.begin(), listInt.end(), [](int newval, int oldval) {return newval < oldval; });
	cout << "����������� ������� ����� ������ " << *iT << endl;
	transform(listInt.begin(), listInt.end(), listInt.begin(), [](int cur) {
			return cur * 2;
		});
	ostream_iterator<int>outlist(cout, " ");
	copy(listInt.begin(), listInt.end(), outlist);
	cout << endl;
	//������������� ���������1. �������� �������� �� ������
	for_each(listInt.begin(), listInt.end(), Transform1);
	copy(listInt.begin(), listInt.end(), outlist);
	//�������� �������� � ����������������
	transform(listInt.begin(), listInt.end(),listInt.begin(),Transform2);
	copy(listInt.begin(), listInt.end(), outlist);
	//�����
	ofstream fout("a.txt");
	ostream_iterator<int> outlistfile(fout, " ");
	copy(listInt.begin(), listInt.end(), outlistfile);
	//������ ���������� �� ������� ������ ����� ����������
	cout << endl << "������ ���������� �� ������� ������ ����� ����������" << endl;
	ListShPtrTa listTa;
	FillList(listTa);
	ostream_iterator<ShPtrTa> outlistTa (cout, " ");
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "� Transform" << endl;
	for_each(listTa.begin(), listTa.end(), Transform);
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "c for_each � ��������������� � lvalue" << endl;
	for_each(listTa.begin(), listTa.end(), [](ShPtrTa& cur)->void {
			cur->A() / 2; //lvalue
		});
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "������� ��� ��������� �� ����������" << endl;
	for (ShPtrTa& pTa : listTa)
	{
		pTa->A() += 1;
	}
	cout << "�������� ����������+1" << endl;
	copy(listTa.begin(), listTa.end(), outlistTa);
	//��������� �� ������ ����� ����������
	ListShPtrTa::iterator ItTa;
	int ExtraValue = 400;
	//������ ��� �������� ������ ExtraValue
	ItTa = remove_if(listTa.begin(), listTa.end(), [ExtraValue](ShPtrTa& pTa) {  //remove_if ���������� �������� ����������� �� ������ �� ��������� ������� ����� �������
		return pTa->A() < ExtraValue;
		});
	cout << "ListTaSize()" << listTa.size() << endl;
	listTa.erase(ItTa, listTa.end());
	cout << "�������� ���������� ����� �������� > 300" << endl;
	copy(listTa.begin(), listTa.end(), outlistTa);
	//����� �� ��������
	ItTa = min_element(listTa.begin(), listTa.end(), [](ShPtrTa newVal, ShPtrTa oldVal) {
		return newVal->A() < oldVal->A();
		});
	int minTa = (*ItTa)->A();
	cout << "����������� �������" << minTa;
	return 0;
}


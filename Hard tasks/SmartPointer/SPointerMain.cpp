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
	int& A()& //квалификатор & после круглых скобок говорит что данная версия метода используется в контексте lvalue вызова, т.е. по ссылке
	{
		return a;
	}
	int A()&&
	{
		return a; //двойной && означает возврат копии объекта
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
	return out << *pTa.get(); // get дает адрес на ссылаемый объект
}

int main()
{
	RusCon();
	cout << "работа с умными указателями" << endl;
	{
		ShPtrTa pA(new Ta(777));
		{
			ShPtrTa pB(new Ta(888));
			{
				ShPtrTa pC(pB);
			}
		}
	}
	//Работа алгоритмов с целочисленными списками
	cout << endl << "Работа алгоритмов с целочисленными списками" << endl;
	std::list<int> listInt{ 1, 4, -2, 5, 3, 0 };
	std::list<int>::iterator iT = min_element(listInt.begin(), listInt.end()); //end - положение после последнего элемента
	int min = *iT;
	cout << "algorithm:min_element=" << min << endl;
	iT = max_element(listInt.begin(), listInt.end());
	int max = *iT;
	cout << "algorithm:max_element=" << max << endl;
	std::list<int>::iterator BEGIN = listInt.begin();
	std::list<int>::iterator END = --listInt.end();
	cout << "Первый элемент списка " << *BEGIN << endl;
	cout << "Последний элемент списка " << *END << endl;
	iT = min_element(listInt.begin(), listInt.end(), [](int newval, int oldval) {return newval < oldval; });
	cout << "Минимальный элемент через лямбду " << *iT << endl;
	transform(listInt.begin(), listInt.end(), listInt.begin(), [](int cur) {
			return cur * 2;
		});
	ostream_iterator<int>outlist(cout, " ");
	copy(listInt.begin(), listInt.end(), outlist);
	cout << endl;
	//использование трансформ1. Меняются элементы по ссылке
	for_each(listInt.begin(), listInt.end(), Transform1);
	copy(listInt.begin(), listInt.end(), outlist);
	//Меняются элементы и перезаписываются
	transform(listInt.begin(), listInt.end(),listInt.begin(),Transform2);
	copy(listInt.begin(), listInt.end(), outlist);
	//Файлы
	ofstream fout("a.txt");
	ostream_iterator<int> outlistfile(fout, " ");
	copy(listInt.begin(), listInt.end(), outlistfile);
	//Работа алгоритмов на примере списка умных указателей
	cout << endl << "Работа алгоритмов на примере списка умных указателей" << endl;
	ListShPtrTa listTa;
	FillList(listTa);
	ostream_iterator<ShPtrTa> outlistTa (cout, " ");
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "с Transform" << endl;
	for_each(listTa.begin(), listTa.end(), Transform);
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "c for_each и преобразованием в lvalue" << endl;
	for_each(listTa.begin(), listTa.end(), [](ShPtrTa& cur)->void {
			cur->A() / 2; //lvalue
		});
	copy(listTa.begin(), listTa.end(), outlistTa);
	cout << endl << "Изменим все перебором по контейнеру" << endl;
	for (ShPtrTa& pTa : listTa)
	{
		pTa->A() += 1;
	}
	cout << "Элементы контейнера+1" << endl;
	copy(listTa.begin(), listTa.end(), outlistTa);
	//Итераторы на список умных указателей
	ListShPtrTa::iterator ItTa;
	int ExtraValue = 400;
	//Удалим все элементы больше ExtraValue
	ItTa = remove_if(listTa.begin(), listTa.end(), [ExtraValue](ShPtrTa& pTa) {  //remove_if Возвращает итератор указывающий на первый из элементов который нужно удалить
		return pTa->A() < ExtraValue;
		});
	cout << "ListTaSize()" << listTa.size() << endl;
	listTa.erase(ItTa, listTa.end());
	cout << "Элементы контейнера после удаления > 300" << endl;
	copy(listTa.begin(), listTa.end(), outlistTa);
	//Поиск по критерию
	ItTa = min_element(listTa.begin(), listTa.end(), [](ShPtrTa newVal, ShPtrTa oldVal) {
		return newVal->A() < oldVal->A();
		});
	int minTa = (*ItTa)->A();
	cout << "Минимальный элемент" << minTa;
	return 0;
}


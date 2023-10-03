// Файл List.cpp

#include "stdafx.h"
#include "List.h"

size_t List::Size() // Возвращает количество элементов списка

{
	int n = 0;
	for (Iterator p = Begin(), pe = End(); p != pe; ++p)
		n++;
	return n;
}

void List::Push_Front(T Val) // Вставить новое звено в начало списка
{
	Node* tmp = new Node(Val); // (2) Создание звена
	if (!Empty()) { // Если список не пуст,
		tmp->next = first; // (3) новое звено ставим перед первым
		first = tmp;
	} // (4) и новое звено делаем первым

	else // Если список пока пустой,
		first = last = tmp;
} // (3) новое звено делаем первым и последним

void List::Push_Back(T val) { // Вставить новое звено в конец списка
	Node* tmp = new Node(val); // (2) Создание нового звена
	if (!Empty()) { // Если список не пуст,
		last->next = tmp; // (3) новое звено ставим после последнего
		last = tmp;
	} // (4) и новое звено делаем последним
	else // Если список был пуст,
		first = last = tmp;
} // (3) новое звено делаем и первым и последним

T List::Pop_Front() { // Удаление первого звена
	T inf = first->d; // Информация первого звена
	Node* tmp = first; // (1) Указатель на удаляемое звено
	first = first->next; // (2) Второе звено списка делаем первым
	delete tmp; // (3) Удаление первого звена
	return inf;
} // Возвращаем информацию первого звена

List::~List() { // Деструктор

	while (first) // Пока в списке есть звенья,

		Pop_Front();
} // удаляем первое звено

List::Iterator List::InsertAfter(Iterator p, T val) { // Вставка звена со значением val после итератора p
	if (p == last) { // Вставка после последнего звена
		Push_Back(val);
		return Iterator(last);
	}
	else { // Вставка внутрь списка
		Node* tmp = new Node(val); // (2) Создание нового звена
		tmp->next = p.operator->()->next; // (3) Связь нового со следующим
		p->next = tmp; // (4) Связь текущего звена с новым
		return Iterator(tmp);
	} // Возвращается итератор
}

void List::EraseAfter(Iterator p) { // EraseAfter: удаляет узел после итератора p
	Iterator q = p->next; // (1) Итератор на удаляемое звено
	p->next = q->next; // (2) Исключение звена из списка
	delete&* q;
} // (3) Удаление звена

void List::del_e(T e)
{
	while (!Empty() && Front() == e)
		Pop_Front();
	List::Iterator P = Begin(), E = Begin();
	if (E != End())
	{
		E++;
		while (E!=End())
		{
			if (E->d == e)
			{
				E++;
				EraseAfter(P);
			}
			else
				{ P++; E++;}
		}
	}

}

void PrintList(List& L, char delimiter) // Вывод списка

{
	for (List::Iterator p = L.Begin(), pe = L.End(); p != pe; ++p)
		cout << p->d << delimiter;
}
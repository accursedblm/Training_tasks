#include "SLCList.h"

void List::Push_Front(T Val) { // Вставить новое звено в начало списка
	Node* tmp = new Node(Val); // (2) Создание звена
	if (!Empty()) { // Список не пуст
		tmp->next = this->next; // (3) Новое звено ставим перед первым,
		this->next = tmp;
	} // (4) Связывание списка с первым звеном
	else { // Список пуст
		tmp->next = this; // (3) Новое звено связываем со списком
		this->next = tmp; // (4) Список связываем с первым звеном
		last = tmp;
	}
} // (5) Новое звено отмечаем как последнее

void List::Push_Back(T val) { // Вставить новое звено в конец списка
	Node* tmp = new Node(val); // (2) Создание нового звена
	if (!Empty()) { // Список не пуст,
		tmp->next = last->next; // (3) Новое звено связываем со списком
		last->next = tmp; // (4) Последнее звено связывается с новым
		last = tmp;
	} // (5) Новое звено делаем последним
	else { // Список пуст
		tmp->next = this; // (3) Связь нового звено со списком
		this->next = tmp; // (4) Список связывается с новым звеном
		last = tmp;
	}
} // (5) Новое звено фиксируем как последнее

T List::Pop_Front() { // Удаление первого звена
	T inf = this->next->d; // Информация первого звена
	Node* tmp = this->next; // (1) Указатель на удаляемое звено
	this->next = tmp->next; // (2) Первым делаем второе звено
	if (this->next == this) // Если удаляется последнее звено
		last = 0; // Фиксируем, что список теперь пуст
	delete tmp; // (3) Удаление первого звена
	return inf;
} // Возвращаем информацию первого звена

List::~List() { // Деструктор
	while (last) // Пока в списке есть звенья,
		Pop_Front();
} // удаляем первое звено

void List::Swap(Iterator a, Iterator b)
{
	if (a == b)
		return;
	// a и b рядом, b после a
	if (a->next == b.operator->())
	{
		Node* post_b = b->next;
		Node* tmp = this;
		while (tmp->next != a.operator->())
			tmp = tmp -> next;
		Node* pred_a = tmp;
		pred_a->next = &(*b);
		b->next = &(*a);
		a->next = post_b;
	}
	// a и b рядом, a после b
	if (b->next == a.operator->())
	{
		Node* post_a = a->next;
		Node* tmp = this;
		while (tmp->next != b.operator->())
			tmp = tmp -> next;
		Node* pred_b = tmp;
		pred_b->next = &(*a);
		b->next = &(*b);
		a->next = post_a;
	}
	//Общий случай
	else
	{
		Node* tmp = this;
		while (tmp->next != &(*a))
			tmp = tmp->next;
		Node* pred_a = tmp;
		tmp = this;
		while (tmp->next != &(*b))
			tmp = tmp->next;
		Node* pred_b = tmp;
		Node* post_a = a->next;
		Node* post_b = b->next;
		pred_a->next = &(*b);
		b->next = post_a;
		pred_b->next = &(*a);
		a->next = post_b;
	}
	//Учет последних звеньев
	if (last == &(*a))
		last = &(*b);
	else if (last == &(*b))
		last = &(*a);
}

bool up(T a, T b)
{
	return a > b;
}

bool down(T a, T b)
{
	return a < b;
}

void List::Sort(bool(*f)(T a, T b))
{
	for (Iterator i = Begin(); i != End(); i++)
	{
		for (Iterator j = i; j != End(); j++)
		{
			Swap(i, j);
			Iterator tmp = i;
			i = j;
			j = tmp;
		}
	}
	}

size_t List::Size() // Возвращает количество элементов списка

{
	int n = 0;
	for (Iterator p = Begin(), pe = End(); p != pe; ++p)
		n++;
	return n;
}

void List::EraseAfter(Iterator p) { // EraseAfter: удаляет узел после итератора p
	Iterator q = p->next; // (1) Итератор на удаляемое звено
	p->next = q->next; // (2) Исключение звена из списка
	delete&* q;
} // (3) Удаление звена

void PrintList(List& L, char delimiter) // Вывод списка

{
	for (List::Iterator p = L.Begin(), pe = L.End(); p != pe; ++p)
		cout << p->d << delimiter;
}

	
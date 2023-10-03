#pragma once
#include "stdafx.h"

typedef string T; // Тип величин, хранящихся в списке
struct Node { // Класс звеньев списка
	T d; // d - информация звена списка
	Node* next; // Указатель на следующее звено списка
	Node(T _d = T()) : d(_d) // Конструктор звена списка
	{
		next = this;
	}
}; // Звено ссылается само на себя

class List : public Node { // Класс списков. Наследуемое звено
// используем как фиктивное последнее звено
	Node* last; // Указатель на действительное последнее звено
public:
	List() : Node() // Конструктор по умолчанию создает фиктивное
	{
		last = 0;
	} // последнее звено для пустого списка
	~List(); // Деструктор
	// Проверка пустоты списка
	bool Empty() const { return (last == 0); }
	T& Front() { return this->next->d; } // Ссылка на первый элемент
	T Pop_Front(); // Удаление первого звена
	void Push_Front(T Val); // Вставить новое звено в начало списка
	void Push_Back(T Val); // Вставить новое звено в конец списка
	size_t Size(); // Количество элементов списка
	class Iterator { // Класс итераторов списка
		Node* curr; // Указатель на текущее звено списка
	public:
		Iterator(Node* pn = 0) // Конструктор создает итератор
		{
			curr = pn;
		} // по указателю pn на звено списка

// Конструктор копирования
		Iterator(const Iterator& p) { curr = p.curr; }
		// Доступ к текущему звену
		Node& operator*() { return *curr; }
		// Указатель на текущее звено
		Node* operator->() { return curr; }
		Iterator& operator++() // Префиксный инкремент
		{
			curr = curr->next; return *this;
		}
		Iterator operator++(int) // Постфиксный инкремент
		{
			Iterator tmp = *this; curr = curr->next; return tmp;
		}
		// Сравнение итераторов на равенство
		bool operator== (Iterator p)
		{
			return curr == p.curr;
		}
		// Сравнение итераторов на неравенство
		bool operator!=(Iterator p)
		{
			return curr != p.curr;
		}
	}; // Конец объявления класса Iterator
	Iterator Begin() // Получение итератора
	{
		return Iterator(this->next);
	} // на первое звено списка
	Iterator End() // Получение итератора на звено списка,
	{
		return Iterator(this);
	} // следующее за последним звеном

	Iterator InsertAfter(Iterator p, T val); // Вставляет val после p
	void EraseAfter(Iterator p); // Удаляет узел после итератора p
	void Swap(Iterator a, Iterator b);
	void Sort(bool (*f)(T a, T b));

};

bool up(T a, T b);
bool down(T a, T b);
void PrintList(List& L, char delimiter = ' ');
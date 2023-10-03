#pragma once
// Продолжение файла List.h
typedef char T; // Тип величин, хранящихся в списке

struct Node { // Структура, описывающая звено списка
	T d; // d - информация звена списка
	Node* next; // Указатель на следующее звено списка

	Node(T _d = T()) : d(_d) // Конструктор звена списка
	{
		next = 0;
	} // T( ) – вызов конструктора по умолчанию для типа T
};

class List { // Класс списков
	Node* first; // Указатель на первое звено
	Node* last; // Указатель на последнее звено
public:
	List() // Конструктор по умолчанию
	{
		first = 0; last = 0;
	} // создает пустой список

	~List(); // Деструктор
	bool Empty() const // Проверка, не пуст ли список
	{
		return (first == 0);
	}

	T& Front() { return first->d; } // Ссылка на первый элемент
	void Push_Front(T Val); // Вставить новое звено в начало списка
	void Push_Back(T Val); // Вставить новое звено в конец списка
	T Pop_Front(); // Удаление первого звена
	size_t Size(); // Количество звеньев списка

	class Iterator { // Класс итераторов списка
		Node* curr; // Указатель на текущее звено списка
	public:
		Iterator(Node* pn = 0) // Конструктор создает итератор
		{
			curr = pn;
		} // по указателю pn на звено списка

		Iterator(const Iterator& p) // Конструктор копирования
		{
			curr = p.curr;
		}

		Node& operator*() // Доступ к текущему звену
		{
			return *curr;
		}

		Node* operator->() // Указатель на текущее звено списка
		{
			return curr;
		}

		Iterator& operator++() // Префиксный инкремент
		{ // Используется в виде ++p
			curr = curr->next; // Возвращает итератор на
			return *this; // следующее звено списка
		}

		Iterator operator++(int) // Постфиксный инкремент

		{ // Используется в виде p++
			Iterator tmp = *this; // tmp – копия текущего итератора
			curr = curr->next; // Изменение текущего итератора
			return tmp;
			// Возвращение предыдущего значения итератора
		}

		bool operator== (Iterator p)
			// Сравнение итераторов на равенство
		{
			return curr == p.curr;
		}

		bool operator!=(Iterator p)
			// Сравнение итераторов на неравенство
		{
			return curr != p.curr;
		}

	}; // Конец объявления класса Iterator

	Iterator Begin() // Получение итератора
	{
		return Iterator(first);
	} // на первое звено списка

	Iterator End() // Получение итератора на звено списка,
	{
		return Iterator(0);
	} // следующее за последним звеном

	Iterator InsertAfter(Iterator p, T val);
	// Вставка звена после итератора
	
	void EraseAfter(Iterator p);
	// Удаление звена после итератора p

	void del_e(T e);
};

void PrintList(List& L, char delimiter = ' '); // Вывод списка
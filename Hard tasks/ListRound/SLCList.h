#pragma once
#include "stdafx.h"

typedef string T; // ��� �������, ���������� � ������
struct Node { // ����� ������� ������
	T d; // d - ���������� ����� ������
	Node* next; // ��������� �� ��������� ����� ������
	Node(T _d = T()) : d(_d) // ����������� ����� ������
	{
		next = this;
	}
}; // ����� ��������� ���� �� ����

class List : public Node { // ����� �������. ����������� �����
// ���������� ��� ��������� ��������� �����
	Node* last; // ��������� �� �������������� ��������� �����
public:
	List() : Node() // ����������� �� ��������� ������� ���������
	{
		last = 0;
	} // ��������� ����� ��� ������� ������
	~List(); // ����������
	// �������� ������� ������
	bool Empty() const { return (last == 0); }
	T& Front() { return this->next->d; } // ������ �� ������ �������
	T Pop_Front(); // �������� ������� �����
	void Push_Front(T Val); // �������� ����� ����� � ������ ������
	void Push_Back(T Val); // �������� ����� ����� � ����� ������
	size_t Size(); // ���������� ��������� ������
	class Iterator { // ����� ���������� ������
		Node* curr; // ��������� �� ������� ����� ������
	public:
		Iterator(Node* pn = 0) // ����������� ������� ��������
		{
			curr = pn;
		} // �� ��������� pn �� ����� ������

// ����������� �����������
		Iterator(const Iterator& p) { curr = p.curr; }
		// ������ � �������� �����
		Node& operator*() { return *curr; }
		// ��������� �� ������� �����
		Node* operator->() { return curr; }
		Iterator& operator++() // ���������� ���������
		{
			curr = curr->next; return *this;
		}
		Iterator operator++(int) // ����������� ���������
		{
			Iterator tmp = *this; curr = curr->next; return tmp;
		}
		// ��������� ���������� �� ���������
		bool operator== (Iterator p)
		{
			return curr == p.curr;
		}
		// ��������� ���������� �� �����������
		bool operator!=(Iterator p)
		{
			return curr != p.curr;
		}
	}; // ����� ���������� ������ Iterator
	Iterator Begin() // ��������� ���������
	{
		return Iterator(this->next);
	} // �� ������ ����� ������
	Iterator End() // ��������� ��������� �� ����� ������,
	{
		return Iterator(this);
	} // ��������� �� ��������� ������

	Iterator InsertAfter(Iterator p, T val); // ��������� val ����� p
	void EraseAfter(Iterator p); // ������� ���� ����� ��������� p
	void Swap(Iterator a, Iterator b);
	void Sort(bool (*f)(T a, T b));

};

bool up(T a, T b);
bool down(T a, T b);
void PrintList(List& L, char delimiter = ' ');
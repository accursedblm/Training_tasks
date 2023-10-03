#pragma once
// ����������� ����� List.h
typedef char T; // ��� �������, ���������� � ������

struct Node { // ���������, ����������� ����� ������
	T d; // d - ���������� ����� ������
	Node* next; // ��������� �� ��������� ����� ������

	Node(T _d = T()) : d(_d) // ����������� ����� ������
	{
		next = 0;
	} // T( ) � ����� ������������ �� ��������� ��� ���� T
};

class List { // ����� �������
	Node* first; // ��������� �� ������ �����
	Node* last; // ��������� �� ��������� �����
public:
	List() // ����������� �� ���������
	{
		first = 0; last = 0;
	} // ������� ������ ������

	~List(); // ����������
	bool Empty() const // ��������, �� ���� �� ������
	{
		return (first == 0);
	}

	T& Front() { return first->d; } // ������ �� ������ �������
	void Push_Front(T Val); // �������� ����� ����� � ������ ������
	void Push_Back(T Val); // �������� ����� ����� � ����� ������
	T Pop_Front(); // �������� ������� �����
	size_t Size(); // ���������� ������� ������

	class Iterator { // ����� ���������� ������
		Node* curr; // ��������� �� ������� ����� ������
	public:
		Iterator(Node* pn = 0) // ����������� ������� ��������
		{
			curr = pn;
		} // �� ��������� pn �� ����� ������

		Iterator(const Iterator& p) // ����������� �����������
		{
			curr = p.curr;
		}

		Node& operator*() // ������ � �������� �����
		{
			return *curr;
		}

		Node* operator->() // ��������� �� ������� ����� ������
		{
			return curr;
		}

		Iterator& operator++() // ���������� ���������
		{ // ������������ � ���� ++p
			curr = curr->next; // ���������� �������� ��
			return *this; // ��������� ����� ������
		}

		Iterator operator++(int) // ����������� ���������

		{ // ������������ � ���� p++
			Iterator tmp = *this; // tmp � ����� �������� ���������
			curr = curr->next; // ��������� �������� ���������
			return tmp;
			// ����������� ����������� �������� ���������
		}

		bool operator== (Iterator p)
			// ��������� ���������� �� ���������
		{
			return curr == p.curr;
		}

		bool operator!=(Iterator p)
			// ��������� ���������� �� �����������
		{
			return curr != p.curr;
		}

	}; // ����� ���������� ������ Iterator

	Iterator Begin() // ��������� ���������
	{
		return Iterator(first);
	} // �� ������ ����� ������

	Iterator End() // ��������� ��������� �� ����� ������,
	{
		return Iterator(0);
	} // ��������� �� ��������� ������

	Iterator InsertAfter(Iterator p, T val);
	// ������� ����� ����� ���������
	
	void EraseAfter(Iterator p);
	// �������� ����� ����� ��������� p

	void del_e(T e);
};

void PrintList(List& L, char delimiter = ' '); // ����� ������
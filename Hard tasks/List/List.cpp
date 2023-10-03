// ���� List.cpp

#include "stdafx.h"
#include "List.h"

size_t List::Size() // ���������� ���������� ��������� ������

{
	int n = 0;
	for (Iterator p = Begin(), pe = End(); p != pe; ++p)
		n++;
	return n;
}

void List::Push_Front(T Val) // �������� ����� ����� � ������ ������
{
	Node* tmp = new Node(Val); // (2) �������� �����
	if (!Empty()) { // ���� ������ �� ����,
		tmp->next = first; // (3) ����� ����� ������ ����� ������
		first = tmp;
	} // (4) � ����� ����� ������ ������

	else // ���� ������ ���� ������,
		first = last = tmp;
} // (3) ����� ����� ������ ������ � ���������

void List::Push_Back(T val) { // �������� ����� ����� � ����� ������
	Node* tmp = new Node(val); // (2) �������� ������ �����
	if (!Empty()) { // ���� ������ �� ����,
		last->next = tmp; // (3) ����� ����� ������ ����� ����������
		last = tmp;
	} // (4) � ����� ����� ������ ���������
	else // ���� ������ ��� ����,
		first = last = tmp;
} // (3) ����� ����� ������ � ������ � ���������

T List::Pop_Front() { // �������� ������� �����
	T inf = first->d; // ���������� ������� �����
	Node* tmp = first; // (1) ��������� �� ��������� �����
	first = first->next; // (2) ������ ����� ������ ������ ������
	delete tmp; // (3) �������� ������� �����
	return inf;
} // ���������� ���������� ������� �����

List::~List() { // ����������

	while (first) // ���� � ������ ���� ������,

		Pop_Front();
} // ������� ������ �����

List::Iterator List::InsertAfter(Iterator p, T val) { // ������� ����� �� ��������� val ����� ��������� p
	if (p == last) { // ������� ����� ���������� �����
		Push_Back(val);
		return Iterator(last);
	}
	else { // ������� ������ ������
		Node* tmp = new Node(val); // (2) �������� ������ �����
		tmp->next = p.operator->()->next; // (3) ����� ������ �� ���������
		p->next = tmp; // (4) ����� �������� ����� � �����
		return Iterator(tmp);
	} // ������������ ��������
}

void List::EraseAfter(Iterator p) { // EraseAfter: ������� ���� ����� ��������� p
	Iterator q = p->next; // (1) �������� �� ��������� �����
	p->next = q->next; // (2) ���������� ����� �� ������
	delete&* q;
} // (3) �������� �����

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

void PrintList(List& L, char delimiter) // ����� ������

{
	for (List::Iterator p = L.Begin(), pe = L.End(); p != pe; ++p)
		cout << p->d << delimiter;
}
#include "SLCList.h"

void List::Push_Front(T Val) { // �������� ����� ����� � ������ ������
	Node* tmp = new Node(Val); // (2) �������� �����
	if (!Empty()) { // ������ �� ����
		tmp->next = this->next; // (3) ����� ����� ������ ����� ������,
		this->next = tmp;
	} // (4) ���������� ������ � ������ ������
	else { // ������ ����
		tmp->next = this; // (3) ����� ����� ��������� �� �������
		this->next = tmp; // (4) ������ ��������� � ������ ������
		last = tmp;
	}
} // (5) ����� ����� �������� ��� ���������

void List::Push_Back(T val) { // �������� ����� ����� � ����� ������
	Node* tmp = new Node(val); // (2) �������� ������ �����
	if (!Empty()) { // ������ �� ����,
		tmp->next = last->next; // (3) ����� ����� ��������� �� �������
		last->next = tmp; // (4) ��������� ����� ����������� � �����
		last = tmp;
	} // (5) ����� ����� ������ ���������
	else { // ������ ����
		tmp->next = this; // (3) ����� ������ ����� �� �������
		this->next = tmp; // (4) ������ ����������� � ����� ������
		last = tmp;
	}
} // (5) ����� ����� ��������� ��� ���������

T List::Pop_Front() { // �������� ������� �����
	T inf = this->next->d; // ���������� ������� �����
	Node* tmp = this->next; // (1) ��������� �� ��������� �����
	this->next = tmp->next; // (2) ������ ������ ������ �����
	if (this->next == this) // ���� ��������� ��������� �����
		last = 0; // ���������, ��� ������ ������ ����
	delete tmp; // (3) �������� ������� �����
	return inf;
} // ���������� ���������� ������� �����

List::~List() { // ����������
	while (last) // ���� � ������ ���� ������,
		Pop_Front();
} // ������� ������ �����

void List::Swap(Iterator a, Iterator b)
{
	if (a == b)
		return;
	// a � b �����, b ����� a
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
	// a � b �����, a ����� b
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
	//����� ������
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
	//���� ��������� �������
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

size_t List::Size() // ���������� ���������� ��������� ������

{
	int n = 0;
	for (Iterator p = Begin(), pe = End(); p != pe; ++p)
		n++;
	return n;
}

void List::EraseAfter(Iterator p) { // EraseAfter: ������� ���� ����� ��������� p
	Iterator q = p->next; // (1) �������� �� ��������� �����
	p->next = q->next; // (2) ���������� ����� �� ������
	delete&* q;
} // (3) �������� �����

void PrintList(List& L, char delimiter) // ����� ������

{
	for (List::Iterator p = L.Begin(), pe = L.End(); p != pe; ++p)
		cout << p->d << delimiter;
}

	
#ifndef TablH
#define TablH
#define MAX 50
#include "word.h"
struct tabl
{
	word* mas[MAX];           // ������ ���������� �� �����
	int kol;                  // ���������� ���� � �������
	void newword(word* W);   // ���������� ������ ����� � ������
	int poisk(char* s);      // ����� ����� s � ������� ����
	// ��������� ������� �������, � ������� ��������� �����, � -1, ���� ����� ���
	void newpos(int P, int p);// ���������� ������� ��������� p ��� ����� � ������� P
	void print();             // ���������� �������
	void sort();              // ���������� �� ������
	char* nword(int p);       // ����������� ����� � �������� �������
	int kolword();            // ���������� ���� � ������
	void printtext();         // ���������� ���� � ������� ��������� � ������
	void printrewerstext();   // ���������� ���� � �������� ������� ��������� � ������
	void delword(int p);      // �������� ����� �� ������� p
};
#endif
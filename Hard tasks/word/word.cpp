#include "word.h"
#include <string.h>
word* init(char* s, int k)
{
	word* tmp = new word;       // ������� ������ �����
	tmp->w = new char[strlen(s) + 1];  // �������� ������ ��� ���� �����
	strcpy(tmp->w, s);              // �������� �����
	tmp->n = 1;                      // ����� ���������
	tmp->pos = new int[1];           // ������� ������ ��������� �� ������ ��������
	tmp->pos[0] = k;                 // ������� ������� ���������
	return tmp;               // ���������� ����� ���������� ������� �����
}
#include "tabl.h"
#include <string.h>
#include "iostream"
using namespace std;
// ���������� ������ ����� � ������
void tabl::newword(word* W)
{
	mas[kol++] = W;
}
// ����� ����� s � ������� ����
// ��������� ������� �������, � ������� ��������� �����, � -1, ���� ����� ���
int tabl::poisk(char* s)
{
	for (int i = 0; i < kol; i++)
		if (strcmp(mas[i]->w, s) == 0)
			return i;
	return -1;
}
// ���������� ������� ��������� p ��� ����� � ������� P
void tabl::newpos(int P, int p)
{
	int* tmp = new int[(mas[P]->n) + 1];
	for (int i = 0; i < mas[P]->n; i++)
		tmp[i] = (mas[P]->pos)[i]; // ����������� ������ ���������
	tmp[(mas[P]->n)++] = p;                // ���������� ����� ������� ���������
	delete[] mas[P]->pos;        // �������� �������� ������� ������� ���������
	mas[P]->pos = tmp;             // ��������������� ������� ������� ���������

}
// ���������� �������
void tabl::print()
{
	for (int i = 0; i < kol; i++)
	{
		cout << i << ": " << mas[i]->w << '\t';
		for (int j = 0; j < mas[i]->n; j++)
			cout << (mas[i]->pos)[j] << ' ';
		cout << endl;
	}
}
// ���������� �� ������
void tabl::sort()
{
	for (int i = 0; i < kol - 1; i++)
		for (int j = i + 1; j < kol; j++)
			if (strcmp(mas[i]->w, mas[j]->w) > 0) // ����� ������� ����� ������ ����� ��������
			{
				word* tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
}
// ����������� ����� � �������� �������
char* tabl::nword(int p)
{
	for (int i = 0; i < kol; i++) // ������ �� ������
		for (int j = 0; j < mas[i]->n; j++) // ������ �� ������� ������� ���������
			if ((mas[i]->pos)[j] == p) // ���������� �������
				return mas[i]->w;
	return (char*)"";

}
// ���������� ���� � ������
int tabl::kolword()
{
	int k = 0;   // ������� ����
	for (int i = 0; i < kol; i++)
		k += mas[i]->n; //���������� ���������� ���� �� ����� ��������� ��������
	return k;
}
// ���������� ���� � ������� ��������� � ������
void tabl::printtext()
{
	for (int i = 1; i <= kolword(); i++)
		cout << nword(i) << ' ';
	cout << endl;
}
// ���������� ���� � �������� ������� ��������� � ������
void tabl::printrewerstext()
{
	for (int i = kolword(); i > 0; i--)
		cout << nword(i) << ' ';
	cout << endl;
}
// �������� ����� �� ������� p ������� ����
void tabl::delword(int p)
{
	for (int i = 0; i < mas[p]->n; i++) // ���������� ������� ��������� �����
	{
		//����� ��������� � �������� �������� � ������
		for (int j = 0; j < kol; j++) // ������� ����
			for (int l = 0; l < mas[j]->n; l++)  // ������� ������� ���������
				if ((mas[j]->pos)[l] > (mas[p]->pos)[i]) //���� ������� �������� ����� 
													   //������ ������� ����������
					((mas[j]->pos)[l])--;              // ��������� �������
	}
	delete[] mas[p]->pos; // ����������� ������ ��� ������ �������
	delete[] mas[p]->w;  // ������������ ������ ��� ������
	delete mas[p]; // ����������� ������ ��� ��������� �����
	for (int i = p + 1; i < kol; i++) //�������� ��� ����� ����� ���������� �����
		mas[i - 1] = mas[i];       // �� 1 �����
	kol--;  // ��������� ���������� ����
}
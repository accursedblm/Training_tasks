#ifndef WordH
#define WordH
#pragma warning (once : 4996)
struct word
{
	char* w;   // ��������� �� �����
	int n;     // ������� ���������
	int* pos;  // ��������� �� ������,
			   //��������� ������� ���������
};
word* init(char* s, int k); // �������
	// ��������� ������ ����� � ����������� 
	// ��������� �� ����, s - �����, 
	// k - ������� ���������
#endif


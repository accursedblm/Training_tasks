#pragma once
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//���������� ������� Int ���������
int arr_sort_bubble(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	return 0;
}

//���������� ������� Double ���������
int arr_sort_bubble(double arr[], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int b = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = b;
			}
		}
	}
	return 0;
}

//������� ��������� �����
int CharStrictMatching(char str1[], char str2[])
{
	int i=0;
	while (1)
	{
		if (str1[i] != str2[i])
			break;
		if (str1[i] == '\0' && str2[i] == '\0')
			return 1;
		i++;
	}
	return 0;
}

//�� ������� ��������� �����
int CharNotStrictMatching(char str[], char mask[], char mask_symbol)
{
	int i = 0;
	while (1)
	{
		if (str[i] != mask[i] && mask[i] != mask_symbol)
			break;
		if (str[i] == '\0' && mask[i] == '\0')
			return 1;
		i++;
	}
	return 0;
}

//���������� ������� ��������
int CharArrPrint(char arr[], int size, bool withspace = false)
{
	for (int i = 0; i < size; i++)
		if (withspace)
			cout << arr[i] << " ";
		else
			cout << arr[i];
	cout << endl;
	return 0;
}

//���������� ������� ��������
int CharArr2DinamicPrint(char** arr, int rows, int columns, char separator = ' ')
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << arr[i][j] << separator; // \t  - ���������
		cout << endl;
	}
	return 0;
}

//���������� ������� int
void IntArrPrint(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//���������� ������� Double
void DoubleArrPrint(double arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//���� ����� � ������ �����
int CharArrFill(char* str[], int n, int l)
{
	int i = 0;
	//cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(str[i], l);
	while (i < n)
	{
		cin.getline(str[i], l);
		i++;
	}	
	return 0;
}

//���� ��������� � ������ �����
int IntArrFill(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	return 0;
}

//�������� �� ���������
int IsCharPalindrom(char str[], int l)
{
	int i,j;
	for (i = -1; i < l && str[i+1] != '\0'; i++);
	for (j = 0; j <= i/2; j++)
	{
		if (str[j] != str[i-j])
			return 0;
	}
	return 1;
}

//������ �������� � ������ Double � ��������� �������, � ���������� ������� �������
int DoubleArrAddElement(double arr[], int &arr_size, int pos, double element)
{
	//������� �����
	for (int i = arr_size; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = element;
	arr_size++;

	return 0;
}

//�������� �������� �� ������� Double �� ��������� �������, � ���������� ������� �������.
int ArrDeleleElement(double arr[], int& arr_size, int pos)
{
	for (int i = pos; i < arr_size - 1; i++)
		arr[i] = arr[i + 1];
	arr_size -= 1;
	return 0;
}

//�������� �������� �� ������� Int �� ��������� �������, � ���������� ������� �������.
int ArrDeleleElement(int arr[], int& arr_size, int pos)
{
	for (int i = pos; i < arr_size - 1; i++)
		arr[i] = arr[i + 1];
	arr_size -= 1;
	return 0;
}

//������ ������
void revers_char_arr_v2(char s[])

{
	int i, j; // ������ � �������� ��������
	char tmp; // ��� ������ ��������
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
void revers_char_arr(char str[])
{
	char tmp; // ��� ������ ��������
	char* s, * e;
	e = s = &str[0];
	while (*e != '\0')
		e++;
	e -= 1;
	while (s < e)
	{
		tmp = *s; *s = *e; *e = tmp;
		s++; e--;
	}
}

//������ �������� ������� int
int arr_revers(int arr[], int& arrsize)
{
	int  i, tmp, up, down;
	for (i = 0; i < arrsize; i++)
	{
		up = 0;
		down = arrsize - 1;
		while (up < down)
		{
			if (up < down)
			{
				tmp = arr[up];
				arr[up] = arr[down];
				arr[down] = tmp;
				up++;
				down--;
			}
		}
	}
	return 0;
}

//������ �������� ������� double
int arr_revers(double arr[], int& arrsize)
{
	int  i, up, down;
	double tmp;
	for (i = 0; i < arrsize; i++)
	{
		up = 0;
		down = arrsize - 1;
		while (up < down)
		{
			if (up < down)
			{
				tmp = arr[up];
				arr[up] = arr[down];
				arr[down] = tmp;
				up++;
				down--;
			}
		}
	}
	return 0;
}

//��������� �������� � ���c�� char
bool PosElementInChar(char* s, char c, int* st, int* fin)
{
	bool f = false;
	for (int i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == c)
			if (f == false)
			{
				*st = i;
				f = true;
			}
		*fin = i;
	}
	return f;
}

//��������� ������� �������� � ������ double
bool PosFirstElementInArray(double arr[], double chislo, int arrsize, int& first)
{
	for (int i=0; i < arrsize; i++)
		if (arr[i] == chislo)
		{
			first = i;
			return true;
		}
	return false;
}

//��������� ���������� �������� � ������ double
bool PosLastElementInArray(double arr[], double chislo, int arrsize, int& last)
{
	last = -1;
	for (int i=0; i < arrsize; i++)
		if (arr[i] == chislo)
			last = i;
	if (last != -1)
		return true;
	else
		return false;
}

//��������� ������� �������� � ������ double ������� � �������� �������
bool PosFirstElementInArray(double arr[], double chislo, int arrsize, int startpos, int& first)
{
	for (int i = startpos; i < arrsize; i++)
		if (arr[i] == chislo)
		{
			first = i;
			return true;
		}
	return false;
}

//��������� ������� �������� � ������ int
bool PosFirstElementInArray(int arr[], int chislo, int arrsize, int& first)
{
	for (int i=0; i < arrsize; i++)
		if (arr[i] == chislo)
		{
			first = i;
			return true;
		}
	return false;
}

//��������� ���������� �������� � ������ int
bool PosLastElementInArray(int arr[], int chislo, int arrsize, int& last)
{
	last = -1;
	for (int i=0; i < arrsize; i++)
		if (arr[i] == chislo)
			last = i;
	if (last != -1)
		return true;
	else
		return false;
}

//��������� ������� �������� � ������ int ������� � �������� �������
bool PosFirstElementInArray(int arr[], int chislo, int arrsize, int startpos, int& first)
{
	for (int i = startpos; i < arrsize; i++)
		if (arr[i] == chislo)
		{
			first = i;
			return true;
		}
	return false;
}

//������������� ����� 0-9 ��������� ������� � ����� int.
int CharDigitToInt(char a)
{
	return (int)a - '0';
}

//�������������� ����� ����� ������ � ����� int.
int CharNumberToInt(char a[], int lenght_a = 0, int pos = 0)
{
	int sl = lenght_a > 0 ? lenght_a: strlen(a);
	int result=0;
	for (int i = pos; i < sl; i++)
	{
		result = result + CharDigitToInt(a[i]) * pow(10, sl - i - 1);
	}
	return result;
}

//��������� ������ ����� ���������� �������
int IntArrFillRandom(int* y, int n, int d=10)
{
	srand((unsigned)time(NULL)); // ������������� ���������� ��������� �����
	for (int i = 0; i < n; i++)
		y[i] = rand()%d; // rand() ���������� ����� ��������� �����
	return 0;
}
//char* pc;
//pc = (char*)"� ������"
//(int*)pc - ������� ������ �������

int IntArrDeleteDuplicate(int a, int n);

//����� ������� ������������� �������� � ������� int
int IntArrMaxFind(int* arr, int sizearr, int& pos)
{
	if (sizearr)
		pos = arr[0];
	else
		return -1;
	for (int i = 0; i < sizearr; i++)
		if (arr[pos] < arr[i])
			pos = i;
	return 0;
}

int int_join(int a, int b) {
	int times = 1;
	while (times <= b)
		times *= 10;
	return a * times + b;
}


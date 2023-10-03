#pragma once
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

//Сортировка массива Int пузырьком
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

//Сортировка массива Double пузырьком
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

//Строгое сравнение строк
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

//Не строгое сравнение строк
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

//Распечатка массива символов
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

//Распечатка массива символов
int CharArr2DinamicPrint(char** arr, int rows, int columns, char separator = ' ')
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
			cout << arr[i][j] << separator; // \t  - табуляция
		cout << endl;
	}
	return 0;
}

//Распечатка массива int
void IntArrPrint(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Распечатка массива Double
void DoubleArrPrint(double arr[], int n)
{
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//Ввод строк в массив строк
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

//Ввод элементов в массив интов
int IntArrFill(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	return 0;
}

//Проверка на палиндром
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

//Втавка элемента в массив Double в указанную позицию, с изменением размера массива
int DoubleArrAddElement(double arr[], int &arr_size, int pos, double element)
{
	//Вставка числа
	for (int i = arr_size; i > pos; i--)
	{
		arr[i] = arr[i - 1];
	}
	arr[pos] = element;
	arr_size++;

	return 0;
}

//Удаление элемента из массива Double по указанной позиции, с изменением размера массива.
int ArrDeleleElement(double arr[], int& arr_size, int pos)
{
	for (int i = pos; i < arr_size - 1; i++)
		arr[i] = arr[i + 1];
	arr_size -= 1;
	return 0;
}

//Удаление элемента из массива Int по указанной позиции, с изменением размера массива.
int ArrDeleleElement(int arr[], int& arr_size, int pos)
{
	for (int i = pos; i < arr_size - 1; i++)
		arr[i] = arr[i + 1];
	arr_size -= 1;
	return 0;
}

//Реверс строки
void revers_char_arr_v2(char s[])

{
	int i, j; // Прямой и обратный счетчики
	char tmp; // Для обмена символов
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
	}
}
void revers_char_arr(char str[])
{
	char tmp; // Для обмена символов
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

//Реверс значений массива int
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

//Реверс значений массива double
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

//Вхождение элемента в масcив char
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

//Вхождение первого элемента в массив double
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

//Вхождение последнего элемента в массив double
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

//Вхождение первого элемента в массив double начиная с заданной позиции
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

//Вхождение первого элемента в массив int
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

//Вхождение последнего элемента в массив int
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

//Вхождение первого элемента в массив int начиная с заданной позиции
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

//Преобразовать число 0-9 записаное строкой в число int.
int CharDigitToInt(char a)
{
	return (int)a - '0';
}

//Преобразование цыфры ввиде строки в число int.
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

//Заполняет массив интов случайными числами
int IntArrFillRandom(int* y, int n, int d=10)
{
	srand((unsigned)time(NULL)); // Инициализация генератора случайных чисел
	for (int i = 0; i < n; i++)
		y[i] = rand()%d; // rand() генерирует целое случайное число
	return 0;
}
//char* pc;
//pc = (char*)"Я строка"
//(int*)pc - вывести адресс массива

int IntArrDeleteDuplicate(int a, int n);

//Найти позицию максимального элемента в массиве int
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


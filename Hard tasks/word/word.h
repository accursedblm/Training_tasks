#ifndef WordH
#define WordH
#pragma warning (once : 4996)
struct word
{
	char* w;   // указатель на слово
	int n;     // частота вхождения
	int* pos;  // указатель на массив,
			   //содежащий позиции вхождения
};
word* init(char* s, int k); // функция
	// создающая объект слова и возращающая 
	// указатель на него, s - слова, 
	// k - позиция вхождения
#endif


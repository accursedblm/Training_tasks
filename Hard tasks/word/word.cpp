#include "word.h"
#include <string.h>
word* init(char* s, int k)
{
	word* tmp = new word;       // создаем объект слово
	tmp->w = new char[strlen(s) + 1];  // выделяем память под само слово
	strcpy(tmp->w, s);              // Копируем слово
	tmp->n = 1;                      // Првое вхождение
	tmp->pos = new int[1];           // создаем массив вхождений из одного элемента
	tmp->pos[0] = k;                 // заносим позицию вхождения
	return tmp;               // Возвращаем адрес созданного объекта слова
}
#ifndef TablH
#define TablH
#define MAX 50
#include "word.h"
struct tabl
{
	word* mas[MAX];           // ћассив указателей на слова
	int kol;                  //  оличество слов в массиве
	void newword(word* W);   // ƒобавление нового слова в список
	int poisk(char* s);      // ѕоиск слова s в массиве слов
	// ¬озращает позицию массива, в которой находитс€ слово, и -1, если слова нет
	void newpos(int P, int p);// ƒобавление позиции вхождени€ p дл€ слова с номером P
	void print();             // –аспечатка таблицы
	void sort();              // —ортировка по словам
	char* nword(int p);       // ќпределение слова в заданной позиции
	int kolword();            //  оличество слов в строке
	void printtext();         // распечатка слов в пор€дке по€влени€ в тексте
	void printrewerstext();   // распечатка слов в обратном пор€дке по€влени€ в тексте
	void delword(int p);      // ”даление слова из позиции p
};
#endif
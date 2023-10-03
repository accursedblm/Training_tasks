#include "tabl.h"
#include <string.h>
#include "iostream"
using namespace std;
// ƒобавление нового слова в список
void tabl::newword(word* W)
{
	mas[kol++] = W;
}
// ѕоиск слова s в массиве слов
// ¬озращает позицию массива, в которой находитс€ слово, и -1, если слова нет
int tabl::poisk(char* s)
{
	for (int i = 0; i < kol; i++)
		if (strcmp(mas[i]->w, s) == 0)
			return i;
	return -1;
}
// ƒобавление позиции вхождени€ p дл€ слова с номером P
void tabl::newpos(int P, int p)
{
	int* tmp = new int[(mas[P]->n) + 1];
	for (int i = 0; i < mas[P]->n; i++)
		tmp[i] = (mas[P]->pos)[i]; //  опирование старых вхождений
	tmp[(mas[P]->n)++] = p;                // ƒобавление новой позиции вхождени€
	delete[] mas[P]->pos;        // ”даление прошлого массива позиций вхождени€
	mas[P]->pos = tmp;             // ѕереопределение массива позиций вхождени€

}
// –аспечатка таблицы
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
// —ортировка по словам
void tabl::sort()
{
	for (int i = 0; i < kol - 1; i++)
		for (int j = i + 1; j < kol; j++)
			if (strcmp(mas[i]->w, mas[j]->w) > 0) // –анее сто€щее слово больше позже сто€щего
			{
				word* tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
}
// ќпределение слова в заданной позиции
char* tabl::nword(int p)
{
	for (int i = 0; i < kol; i++) // ѕроход по словам
		for (int j = 0; j < mas[i]->n; j++) // ѕроход по массиву позиций вхождени€
			if ((mas[i]->pos)[j] == p) // —овпадение позиций
				return mas[i]->w;
	return (char*)"";

}
//  оличество слов в строке
int tabl::kolword()
{
	int k = 0;   // счетчик слов
	for (int i = 0; i < kol; i++)
		k += mas[i]->n; //увеличение количества слов на число вхождений текущего
	return k;
}
// распечатка слов в пор€дке по€влени€ в тексте
void tabl::printtext()
{
	for (int i = 1; i <= kolword(); i++)
		cout << nword(i) << ' ';
	cout << endl;
}
// распечатка слов в обратном пор€дке по€влени€ в тексте
void tabl::printrewerstext()
{
	for (int i = kolword(); i > 0; i--)
		cout << nword(i) << ' ';
	cout << endl;
}
// ”даление слова из позиции p таблицы слов
void tabl::delword(int p)
{
	for (int i = 0; i < mas[p]->n; i++) // перебираем позиции вхождени€ слова
	{
		//поиск вхождений с большими номерами в строке
		for (int j = 0; j < kol; j++) // перебор слов
			for (int l = 0; l < mas[j]->n; l++)  // перебор позиций вхождений
				if ((mas[j]->pos)[l] > (mas[p]->pos)[i]) //если позици€ текущего слова 
													   //больше позиции удал€емого
					((mas[j]->pos)[l])--;              // уменьшаем позицию
	}
	delete[] mas[p]->pos; // освобождаем пам€ть под массив позиций
	delete[] mas[p]->w;  // ќсвобождение пам€ти под строку
	delete mas[p]; // освобождаем пам€ть под удал€емое слово
	for (int i = p + 1; i < kol; i++) //сдвигаем все слова после удал€емого слова
		mas[i - 1] = mas[i];       // на 1 влево
	kol--;  // уменьшаем количество слов
}
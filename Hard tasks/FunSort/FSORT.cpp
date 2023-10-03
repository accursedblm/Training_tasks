#include <cstring>
#include "FSORT.h"
#define CompFunc(F) bool (*F)(Ftype& A, Ftype& B, fWay way)
using namespace std;

namespace FSORT
{
	void FSort(Ftype* Ft, int size, CompFunc(F), fWay way)
	{
        //Указатели в начало и в конец массива
        int i = 0;
        int j = size - 1;

        //Центральный элемент массива
        Ftype mid = Ft[size / 2];

        //Делим массив
        do {
            //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
            //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
            while (F(mid, Ft[i], way))      //(mas[i] < mid)
                i++;

            //В правой части пропускаем элементы, которые больше центрального
            while (F(Ft[j], mid, way))      //(mas[j] > mid)
                j--;

            //Меняем элементы местами
            if (i <= j) {
                FtypeSwap(Ft[i], Ft[j]);
                i++; j--;
            }
        } while (i <= j);

        //Рекурсивные вызовы, если осталось, что сортировать
        if (j > 0) {
            //"Левый кусок"
            FSort(Ft, j + 1, F, way);    //qsortRecursive(mas, j + 1);
        }
        if (i < size) {
            //"Правый кусок"
            FSort(&Ft[i], size - i, F, way);   //qsortRecursive(&mas[i], size - i);
        }
	}
    //Сравнение типа структур
	bool CompFtype(Ftype& A, Ftype& B, fWay way)
	{
		bool cf;
		if (strcmp(A.Name, B.Name) == 0)
			if (strcmp(A.Lastname, B.Lastname) == 0)
                if (A.Index == B.Index)
                    {cf = 0; return cf;}
				else
					A.Index > B.Index ? cf = 1 : cf = 0;
			else
				cf = strcmp(A.Lastname, B.Lastname) > 0 ? 1 : 0;
		else
			cf = strcmp(A.Name, B.Name) > 0 ? 1 : 0;
		if (way)
			cf = !cf;
        return cf;
	}
    //Поменять элементы местами
    void FtypeSwap(Ftype& A, Ftype& B)
    {
        Ftype tmp;
        tmp = A;
        A = B;
        B = tmp;
    }
}
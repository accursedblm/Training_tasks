#include <cstring>
#include "FSORT.h"
#define CompFunc(F) bool (*F)(Ftype& A, Ftype& B, fWay way)
using namespace std;

namespace FSORT
{
	void FSort(Ftype* Ft, int size, CompFunc(F), fWay way)
	{
        //��������� � ������ � � ����� �������
        int i = 0;
        int j = size - 1;

        //����������� ������� �������
        Ftype mid = Ft[size / 2];

        //����� ������
        do {
            //��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
            //� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
            while (F(mid, Ft[i], way))      //(mas[i] < mid)
                i++;

            //� ������ ����� ���������� ��������, ������� ������ ������������
            while (F(Ft[j], mid, way))      //(mas[j] > mid)
                j--;

            //������ �������� �������
            if (i <= j) {
                FtypeSwap(Ft[i], Ft[j]);
                i++; j--;
            }
        } while (i <= j);

        //����������� ������, ���� ��������, ��� �����������
        if (j > 0) {
            //"����� �����"
            FSort(Ft, j + 1, F, way);    //qsortRecursive(mas, j + 1);
        }
        if (i < size) {
            //"������ �����"
            FSort(&Ft[i], size - i, F, way);   //qsortRecursive(&mas[i], size - i);
        }
	}
    //��������� ���� ��������
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
    //�������� �������� �������
    void FtypeSwap(Ftype& A, Ftype& B)
    {
        Ftype tmp;
        tmp = A;
        A = B;
        B = tmp;
    }
}
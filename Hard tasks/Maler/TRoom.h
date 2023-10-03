#pragma once
#include <algorithm>
#include "Base.h"
#include "TGoods.h"
#include "TBox.h"
#include "TRect.h"
using namespace std;

class TRoom: public TGoods, public TBox
{
	
public:
	struct TRects : TRect
	{
		int Fcount;
		TRects(const TRect& R, int cou) : TRect(R)
		{
			Fcount = cou;
		}
	};
private:
	TRect* Frect; // Массив доп.перегородок
	int* Find; // Признаки и кол-во конструкций
	int FMaxRect; // Размер динамического массива
	int Fn{ 0 }; // Кол-во элементов
	TErr Ferror{ TErr::OK };
	static TRect BadRect;
public:
	TRoom(int maxrect = 10) : TGoods(), TBox()
	{
		if (maxrect < 1)
			maxrect = 1;
		FMaxRect = maxrect;
		Frect = new TRect[FMaxRect];
		Find = new int[FMaxRect];
	}
	~TRoom()
	{
		if (Frect)
			delete[] Frect;
		if (Find)
			delete[] Find;
	}

	TRect& operator[](const int& i)
	{
		if (i < 0 || i >= Fn)
			return BadRect;
		else
			return Frect[i];
	}
	TErr ErrState() const
	{
		return Ferror;
	}
	void ClearErrState()
	{
		Ferror = TErr::OK;
	}

	TRoom& operator+=(const TRect& r); //Прибавление элемента к площади
	TRoom& operator-=(const TRect& r); //Вычитание элемента из площади
	TRoom& operator+=(const TRects& RS);
	TRoom& operator-=(const TRects& RS);

	double GetCost() const;
	friend ostream& operator << (ostream&, const TRoom&);
	friend istream& operator >> (istream&, TRoom&);
	void copy(const TRoom& R);

	TRoom& operator = (const TRoom& R);

	TRoom(const TRoom& R)
	{
		copy(R);
	}
	void Move(TRoom& R);

	TRoom(TRoom&& R)
	{
		Move(R);
	}
	TRoom& operator = (TRoom&& R) //&& - перемещающий оператор присваивания  - вызывается если для копирования передан временный объект(копия)
	{
		delete[] Frect;
		delete[] Find;
		Move(R);
		cout << "=&&" << endl;
		return *this;
	}

};


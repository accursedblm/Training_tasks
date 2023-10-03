#include "TRoom.h"

TRect TRoom::BadRect;

TRoom& TRoom::operator += (const TRect& r)
{
	if (Fn == FMaxRect)
	{
		Ferror = TErr::BUFFER_OVERFLOW;
		return *this;
	}
	Frect[Fn] = r;
	Find[Fn] = +2; //считает что у перегородки две стороны под обклейку
	Fn++;
	return *this;
}

TRoom& TRoom::operator -= (const TRect& r)
{
	if (Fn == FMaxRect)
	{
		Ferror = TErr::BUFFER_OVERFLOW;
		return *this;
	}
	Frect[Fn] = r;
	Find[Fn] = -1; //элемент вычитаемы из площади
	Fn++;
	return *this;
}

TRoom& TRoom::operator += (const TRects& RS)
{
	if (Fn == FMaxRect)
	{
		Ferror = TErr::BUFFER_OVERFLOW;
		return *this;
	}
	Frect[Fn] = TRect(RS);
	Find[Fn] = 2 * RS.Fcount;
	Fn++;
	return *this;
}

TRoom& TRoom::operator -= (const TRects& RS)
{
	if (Fn == FMaxRect)
	{
		Ferror = TErr::BUFFER_OVERFLOW;
		return *this;
	}
	Frect[Fn] = TRect(RS);
	Find[Fn] = -RS.Fcount;
	Fn++;
	return *this;
}

double TRoom::GetCost() const
{
	double c = Area();
	for (int i = 0; i < Fn; i++)
		c += Frect[i].Area() * Find[i];
	return c * FullPrice();
}

void TRoom::copy(const TRoom& R)
{
	*((TBox*)this) = *((TBox*)&R);
	*((TGoods*)this) = *((TGoods*)&R);
	FMaxRect = R.FMaxRect;
	Fn = R.Fn;
	Frect = new TRect[FMaxRect];
	Find = new int[FMaxRect];
	std::copy(R.Frect, R.Frect + FMaxRect, Frect);
	std::copy(R.Find, R.Find + FMaxRect, Find);
	/*
		//Вариант без алгоритма copy
		for (int i = 0; i < FMaxRect; i++)
		Frect[i] = R.Frect[i];
	*/
	cout << "copy";
}

TRoom& TRoom::operator = (const TRoom& R)
{
	if (this == &R)
		return *this;
	delete[] Frect;
	delete[] Find;
	copy(R);
	cout << "=&" << endl;
	return *this;
}

void TRoom::Move(TRoom& R)
{
	*((TBox*)this) = *((TBox*)&R);
	*((TGoods*)this) = *((TGoods*)&R);
	FMaxRect = R.FMaxRect;
	Fn = R.Fn;
	Frect = R.Frect;
	Find = R.Find;
	R.Frect = nullptr;
	R.Find = nullptr;
	cout << "Move" << endl;
}

ostream& operator<<(ostream& out, const TRoom& r)
{
	out << "Комната ";
	out << "(" << r.Fx0 << "x" << r.Fx1 << "x" << r.Fx2 << ")" << endl;
	out << "Элементы" << endl;
	for (int i = 0; i < r.Fn; i++)
	{
		if (r.Find[i] > 0)
		{
			out << "Перегородка (" << r.Find[i] << " штук)" << endl;
			out << r.Frect[i] << endl;
		}
		else
		{
			out << "Проем (" << -(r.Find[i]) << " штук) " << endl;
			out << r.Frect[i] << endl;
		}
	}
	return out;
}

istream& operator>>(istream& in, TRoom& r)
{
	cout << "Комната ";
	in >> r.Fx0 >> r.Fx1 >> r.Fx2;
	int n;
	cout << "Количество перегородок: ";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		double x1, x2;
		in >> x1 >> x2;
		r += TRect(x1, x2);
	}
	cout << "Количество проемов: ";
	in >> n;
	for (int i = 0; i < n; i++)
	{
		double x1, x2;
		in >> x1 >> x2;
		r -= TRect(x1, x2);
	}
	return in;
}

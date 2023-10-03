#include "Goods.h"

Goods::Goods(const char Nam[], float Pr, const char Inf[]) :Price(Pr)
{
	gcopy(Nam, Name);//Заполняем имя
	gcopy(Inf, Info);//Заполняем инфо
	cName = nullptr;
	cInfo = nullptr;
}

void Goods::Set(const char Nam[], float Pr, const char Inf[])
{
	gcopy(Nam, Name); //Заполняем имя
	gcopy(Inf, Info); //Заполняем инфо
	Price = Pr; //Заполняем Price
}

void Goods::Read(istream& in)
{
	in >> *this;
}

void Goods::Print(ostream& out)
{
	out << *this;
}

char* Goods::GetName()
{
	if (cName != nullptr)
		delete[] cName;
	cName = new (nothrow) char[80];
	if (cName == nullptr)
	{
		cout << "Ошибка выделения памяти";
		cin.get();
		exit;
	}
	gcopy(Name, cName);
	return cName;
}

char* Goods::GetInfo()
{
	if (cInfo != nullptr)
		delete[] cInfo;
	cInfo = new (nothrow) char[80];
	if (cInfo == nullptr)
	{
		cout << "Ошибка выделения памяти";
		cin.get();
		exit;
	}
	int i;
	gcopy(Info, cInfo);
	return cInfo;
}

float Goods::GetPrice()
{
	return Price;
}

Goods::~Goods()
{
	destr();
}

Goods& Goods::operator = (const Goods& g)
{
	this->Set(g.Name, g.Price, g.Info);
	return *this;
}

void Goods::gcopy(const char* Source, char* Dest)
{
	int i = 0;
	for (; Source[i] != '\0' || i == 78; i++)
		Dest[i] = Source[i];
	Dest[i] = '\0';
}

void Goods::destr()
{
	if (cName != nullptr)
	{
		delete[] cName; cName = nullptr;
	}
		
	if (cInfo != nullptr)
	{
		delete[] cInfo; cInfo = nullptr;
	}
	
}

istream& operator >> (istream& in, Goods& g)
{
	in.getline(g.Name, 80);
	in.getline(g.Info, 80);
	in >> g.Price;
	return in;
}

ostream& operator << (ostream& out, const Goods& g)
{
	out << "Имя товара : """ << g.Name << """" << endl
		<< "Информация : """ << g.Info << """" << endl
		<< "Цена : """ << g.Price << """" << endl;
	return out;
}

#include "Pack.h"

Pack::Pack(const char Nam[], float Pr, const char Inf[], int Cou) :Count(Cou)
{
	Goods::Set(Nam, Pr, Inf);
	Count = Cou;
}

void Pack::SetCount(int Cou)
{
	Count = Cou;
}

void Pack::Set(const char Nam[], float Pr, const char Inf[], int Cou)
{
	Goods::Set(Nam, Pr, Inf);
	Count = Cou;
}

void Pack::Read(istream& in)
{
	in >> *this;
}

void Pack::Print(ostream& out)
{
	out << *this;
}

Pack& Pack::operator = (Pack& p)
{
	Set(p.GetName(), p.GetPrice(), p.GetInfo(), p.Count);
	return *this;
}

Pack::~Pack()
{
	destr();
}

istream& operator>>(istream& in, Pack& p)
{
	((Goods*)&p)->Goods::Read(in);
	in >> p.Count;
	return in;
}

ostream& operator<<(ostream& out, Pack& p)
{
	((Goods*)&p)->Goods::Print(out);
	out << "Кол-во в упаковке : """ << p.Count << """" << endl;
	return out;
}

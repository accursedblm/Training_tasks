#include "TRemedy.h"

void TRemedy::read(istream& in)
{
    cout << "Название: \t\t";
    in >> Name; cout << endl;
    cout << "Длительность применения:\t";
    in >> Long; cout << endl;
    cout << "Кол-во раз \t\t"; cout << endl;
    in >> HowMany;  cout << endl;
    cout << "Кол-во курсов \t\t"; cout << endl;
    in >> HowCourse;  cout << endl;
    cout << "Цена за курс \t\t"; cout << endl;
    in >> Price;  cout << endl;
}

void TRemedy::write(ostream& out) const
{
    cout << "Название: \t\t";
    out << Name; cout << endl;
    cout << "Длительность применения:\t";
    out << Long; cout << endl;
    cout << "Кол-во раз \t\t"; cout << endl;
    out << HowMany;  cout << endl;
    cout << "Кол-во курсов \t\t"; cout << endl;
    out << HowCourse;  cout << endl;
    cout << "Цена за курс \t\t"; cout << endl;
    out << Price;  cout << endl;
}

int TRemedy::HowPrice()
{
    return HowCourse * Price;
}

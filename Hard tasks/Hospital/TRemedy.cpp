#include "TRemedy.h"

void TRemedy::read(istream& in)
{
    cout << "��������: \t\t";
    in >> Name; cout << endl;
    cout << "������������ ����������:\t";
    in >> Long; cout << endl;
    cout << "���-�� ��� \t\t"; cout << endl;
    in >> HowMany;  cout << endl;
    cout << "���-�� ������ \t\t"; cout << endl;
    in >> HowCourse;  cout << endl;
    cout << "���� �� ���� \t\t"; cout << endl;
    in >> Price;  cout << endl;
}

void TRemedy::write(ostream& out) const
{
    cout << "��������: \t\t";
    out << Name; cout << endl;
    cout << "������������ ����������:\t";
    out << Long; cout << endl;
    cout << "���-�� ��� \t\t"; cout << endl;
    out << HowMany;  cout << endl;
    cout << "���-�� ������ \t\t"; cout << endl;
    out << HowCourse;  cout << endl;
    cout << "���� �� ���� \t\t"; cout << endl;
    out << Price;  cout << endl;
}

int TRemedy::HowPrice()
{
    return HowCourse * Price;
}

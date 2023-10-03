#pragma once

#include <string>
#include <cstring>
#include <iostream>
using namespace std;

template <class Chislo>
void input_chislo(Chislo & a)
{
    while (!(cin >> a) || (cin.peek() != '\n'))
    {
        cin.clear();
        while (cin.get() != '\n');
        cout << "Ошибка ввода! Попробуйте еще раз: " << endl;
    }
}

string intdate(int a)
{
    string ans;
    if (a < 10)
    { 
        ans = "0" + to_string(a);
        return ans;
    }
    else
    { return to_string(a); }
}

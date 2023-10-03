// MyPrintF.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdarg>
using namespace std;

void print(int n = 0, ...)
{
    va_list num_ptr;
    va_start(num_ptr, n);
    int inum;
    double dnum;
    char cnum, tip;

    for (int i = 1; i <= n; i++)
    {
        tip = va_arg(num_ptr, char);
        if (tip == 'i')
        {
            inum = va_arg(num_ptr, int);
            cout << inum << " ";
        }
        else if (tip == 'd')
        {
            dnum = va_arg(num_ptr, double);
            cout << dnum << " ";
        }
        else if (tip == 'c')
        {
            cnum = va_arg(num_ptr, char);
            cout << cnum << " ";
        }
        else
            break;
    }
    va_end(num_ptr);
}

int main()
{
    //std::cout << "Hello World!\n";
    print();
}




//'i' int
//'d' double
//'c' char

//Входные пар
//(кол-во, тип1, пер1, тип2, пер2, ... )
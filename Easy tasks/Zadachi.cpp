#pragma warning (disable : 4996)
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "windows.h"
#include <algorithm> //алгоритмы
#include "MyClasses.h"
#include "UniversalFunc.h"
#include "Zadachi.h"

using namespace std;

namespace Zadachi
{
	//ЗАДАЧИ С ЛЕКЦИИ
	void Zadacha1()
	{
		string s = "Это моя первая программа! \n";
		double c = 0;
		int a = 0, b = 0;
		setlocale(LC_ALL, "Russian");
		cout << "Введите значение а="; cin >> a;
		cout << "Введите значение b="; cin >> b;
		c = (double)a / b;
		cout << s << "Решение задачи = " << c;
	}
	void Zadacha2()
	{
		int mo, ho, mp, hp; //, m, h;

		//РЕШЕНИЕ 1
		cout << "РЕШЕНИЕ 1:";
		cout << "Введите время отправления = " << endl;
		cin >> ho >> mo;
		cin.clear();
		cout << "Введите время в пути = " << endl;
		cin >> hp >> mp;

		//m = (mo + mp) % 60;
		//h = (ho + hp + (mo + mp) / 60) % 24;

		//cout << "Время прибытия = " << endl << h << ":" << m <<endl; 
		cout << "Время прибытия = " << endl
			<< (ho + hp + (mo + mp) / 60) % 24
			<< ":"
			<< (mo + mp) % 60
			<< endl;

		//РЕШЕНИЕ 2
		cout << "РЕШЕНИЕ 2:";
		int  mind;
		mind = (ho * 60 + mo) + (hp * 60 + mp);

		cout << "Время прибытия";
		if ((mind % (24 * 60)) / 60 < 10)
			cout << 0;
		cout << (mind % (24 * 60)) / 60 << ":";

		if ((mind % (24 * 60)) % 60 < 10) //Если минуты менее 10 то добавить перед ней 0 в вывод
			cout << 0;
		cout << (mind % (24 * 60)) % 60;
	}
	void Zadacha3()
	{
		double a, b;
		cout << "Введите 2 числа" << endl;
		cin >> a >> b;
		if (a > b)
		{
			cout << a;
		}
		else
		{
			cout << b;
		}
	}
	void Zadacha4()
	{
		double a, b, x;
		cout << "Введите 3 числа" << endl;
		cin >> a >> b >> x;
		if (x >= a && x <= b)
		{
			cout << "X находится между А и В";
		}
		else
		{
			cout << "X не находится А и В";
		}
	}


	/*ДОМАШНЕЕ ЗАДАНИЕ от 04.10.2022*/
		// ВАЛЮТА
	void Zadacha1d() // ВАЛЮТА
	{
		//Переменные
		double kurs, sm;
		char a[4];

		kurs = 25; //курс

		cout.precision(2);
		cout << "Вас приветствует конвертер валют USD<->RUR, курс 1 USD = " << kurs << " RUR" << endl
			<< "Введите направление расчета где +1 это USD->RUR, а -1 это RUR->USD" << endl;

		while (true)
		{
			cin.get(a, 4);
			if (strcmp(a, "+1") == 0 || strcmp(a, "-1") == 0) { break; }
			else { cout << ":( неверный ввод, следовало ввести +1 или -1, попробуйте еще раз" << endl; cin.get(); }
		}

		cout << endl;

		if (strcmp(a, "+1") == 0)
		{
			cout << "Введите сумму USD: ";
			input_chislo(sm);
			cout << endl << "Сумма в рублях: ";
			sm = sm * kurs;
			cout << sm << endl;
		}

		if (strcmp(a, "-1") == 0)
		{
			cout << "Введите сумму RUR: ";
			input_chislo(sm);
			cout << endl << "Сумма в $: ";
			sm = sm / kurs;
			cout << sm << endl;
		}

	}
	// УПАКОВКА
	void Zadacha2d() //УПАКОВКА
	{
		int k, j;
		cout << "Введите максимальное кол-во товара помещаемое в ящик, шт: ";
		input_chislo(j);
		cin.clear();
		cout << "Введите кол-во товара для упаковки, шт: ";
		input_chislo(k);

		cout << "Необходимое кол-во ящиков  = " << ceil((double)k / j) << endl;
		if (k % j != 0)
		{
			cout << "Последний ящик заполнен не полностью - " << k % j << " из " << j - k % j << endl;
		}
	}
	// ДВЕРЬ
	void Zadacha3d() //ДВЕРЬ
	{
		int cube[3] = {}, dx, dy;

		cout << "Введите через пробел размеры ящика x y z в мм: ";
		cin >> cube[0] >> cube[1] >> cube[2];
		cout << "Введите размеры расчетного проема: ";
		cin >> dx >> dy;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j)
				{
					if ((cube[i] <= dx && cube[j] <= dy) || (cube[j] <= dx && cube[i] <= dy))
					{
						cout << endl << "Куб " << cube[0] << "x" << cube[1] << "x" << cube[2] << "мм"
							<< " пролезет в дверь " << dx << "x" << dy << "мм" << " торцом " << cube[i] << "x" << cube[j] << "мм!" << endl;
						system("pause");
						exit(0);
					}
				}
			}
		}
		cout << endl << "Куб " << cube[0] << "x" << cube[1] << "x" << cube[2] << "мм"
			<< " не пролезет в дверь " << dx << "x" << dy << "мм ни одним торцом!" << endl;
	}
	// ДАТЫ
	void Zadacha4d() //ДАТЫ
	{
		int d1, m1, d2, m2;
		cout << "Введите две даты через пробел в формате Д1 М1 Д2 М2, где Д - день а М -месяц:";
		cin >> d1 >> m1 >> d2 >> m2;
		if ((d1 == d1) && (m1 == m2))
		{
			cout << "Даты совпадают";
		}
		else if (m1 < m2)
		{
			cout << "Дата " << intdate(d1) << "." << intdate(m1) << " раньше " << intdate(d2) << "." << intdate(m2) << endl;
		}
		else
		{
			cout << "Дата " << intdate(d2) << "." << intdate(m2) << " раньше " << intdate(d1) << "." << intdate(m1) << endl;
		}
	}
	// ТРЕУГОЛЬНИК
	void Zadacha5d() //ТРЕУГОЛЬНИК
	{
		int a, b, c;
		double pp;
		cout << "Введите размеры трех сторон треугольника через пробел в мм: ";
		cin >> a >> b >> c;
		pp = (double)(a + b + c) / 2;
		cout << endl << "Периметр треугольника равен: " << pp * 2;
		cout << endl << "Площать треугольника по формуле Герона равна: " << sqrt(pp * (pp - a) * (pp - b) * (pp - c)) << endl;
	}
	// РАСКРОЙ
	void Zadacha6d()
	{
		int x, y, a, b, v1, v2;
		cout << "Введите размеры заготовки X*Y и размеры листа A*B через пробел в формате X Y A B:" << endl;
		cin >> x >> y >> a >> b;
		v1 = (a / x) * (b / y);
		v2 = (b / x) * (a / y);
		cout << "Раскладка по 1 варианту ( сторона x вдоль a) - " << v1 << " заготовок с листа" << endl;
		cout << "Раскладка по 2 варианту ( сторона y вдоль a) - " << v2 << " заготовок с листа" << endl;
		if (v1 > v2)
		{
			cout << "1 вариант раскладки лучше" << endl;
		}
		else if (v1 == v2)
		{
			cout << "оба варианта имеют одинаковой кол-во заготовок с листа" << endl;
		}
		else
		{
			cout << "2 вариант раскладки лучше" << endl;
		}
	}
	// ПРОГНОЗ
	void Zadacha7d()
	{
		double p0, p1, p;
		int t1 = 0, dt;
		double t;
		cout << "Введите через пробел p0, p1, p, dt." << endl
			<< "	p0 - курс на момент времени 0" << endl
			<< "	p1 - курс на момент времени dt" << endl
			<< "	p - курс для которого нужно найти момент времени" << endl
			<< "	dt - второй момент времени, дней с нулевой точки" << endl;
		cin >> p0 >> p1 >> p >> dt;
		//линейная интерполяция
		t = double(dt) + (t1 - dt) * (p - p1) / (p0 - p1);
		cout << "Искомый курс валюты будет достигнут через " << t << " дней с момента времени ноль." << endl;
	}
	// ПЕРЕСЕЧЕНИЕ
	void Zadacha8d()
	{
		double x1, y1, x2, y2, x3, y3, x4, y4;
		double i[5] = {}, j[5] = {};
		bool xc = true;
		bool yc = true;

		cout << "Введите координаты первого окна через пробел x1 y1 x2 y2: ";
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "Введите координаты второго окна через пробел x1 y1 x2 y2: ";
		cin >> x3 >> y3 >> x4 >> y4;

		i[1] = min(x1, x2); j[1] = min(y1, y2);
		i[2] = max(x1, x2); j[2] = max(y1, y2);
		i[3] = min(x3, x4); j[3] = min(y3, y4);
		i[4] = max(x3, x4); j[4] = max(y3, y4);



		if ((i[1] > i[4]) || (i[2] < i[3])) { xc = false; }
		if ((j[1] > j[4]) || (j[2] < j[3])) { yc = false; }

		if (xc * yc)
		{
			cout << "Окна пересекаются" << endl;
		}
		else
		{
			cout << "Окна не пересекаются" << endl;
		}

		//_____________________________________________________________________
		// Вариант практики
		double a1, a2, a3, a4, b1, b2, b3, b4;

		a1 = x1 < x3 ? x1 : x3;
		a4 = x4 > x2 ? x4 : x2;
		b1 = y1 < y3 ? y1 : y3;
		b4 = y4 > y2 ? y4 : y2;

		if (a1 == x1)
		{
			a2 = x3 < x2 ? x3 : x2;
		}
		else
		{
			a2 = x1 < x4 ? x1 : x4;
		}
		if (a4 == x4)
		{
			a3 = x3 > x2 ? x3 : x2;
		}
		else
		{
			a3 = x4 > x1 ? x4 : x1;
		}

		if (b1 == y1)
		{
			b2 = y3 < y2 ? y3 : y2;
		}
		else
		{
			b2 = y1 < y4 ? y1 : y4;
		}
		if (b4 == y4)
		{
			b3 = y3 > y2 ? y3 : y2;
		}
		else
		{
			b3 = y4 > y1 ? y4 : y1;
		}

		if ((a2 == x2 && a3 == x3) || (a2 == x4 && a3 == x1) || (b2 == y2 && b3 == y3) || (b2 == y4 && b3 == y1))
		{
			cout << "Нет пересечения";
		}
		else
		{
			cout << "(" << a2 << ";" << b2 << ");(" << a3 << ";" << b3 << ")";
		}
	}
	// ДОМ
	void Zadacha9d()
	{
		int p, N, k0, k, a, b;
		cout << "Введите через пробел кол-во подъездов, этажей и квартир на этаже.: ";
		cin >> p >> N >> k0;
		cin.clear();
		cout << endl << "Введите номер квартиры для поиска подъезда и этажа: ";
		cin >> k;

		if (k > p * N * k0)
		{
			cout << endl << "Такой квартиры в доме нет" << endl;
		}
		else
		{
			a = k / (N * k0);
			if (k % (N * k0) != 0) { a++; }
			b = ceil((double)(k - N * k0 * (k / (N * k0))) / k0);
			if (b == 0) { b = 4; }
			cout << endl << "	Квартира находится в подъезде № " << a << endl
				<< "			   на этаже   № " << b << endl;
		}
		//Альтернативное решение 1 без математических функций
		int pod, et;
		pod = (k - 1) / (N * k0) + 1;
		et = ((k - 1) % (N * k0)) / k0 + 1;
		cout << "альтернативный вариант 1. Ответ - подъезд: " << pod << " этаж: " << et << endl << endl;

		//Альтернативное решение 2
		pod = 0; et = 0;
		if (k % (N * k0) == 0)
		{
			pod = k / (N * k0);
		}
		else
		{
			pod = k / (N * k0) + 1;
		}
		if (k % (N * k0) == 0)
		{
			et = N;
		}
		else
		{
			et = (k % (N * k0)) / k0 + 1;
		}
		cout << "альтернативный вариант 2. Ответ - подъезд: " << pod << " этаж: " << et << endl << endl;
	}
	// ВСТРЕЧА
	void Zadacha10d()
	{
		int Ds1, Ms1, Df1, Mf1, Ds2, Ms2, Df2, Mf2;
		int d1, d2, d3, d4;
		//while (true)
		//{ 
		cout << "Введите данные 1-го человка: ";
		cin >> Ds1 >> Ms1 >> Df1 >> Mf1;
		cout << "Введите данные 2-го человка: ";
		cin >> Ds2 >> Ms2 >> Df2 >> Mf2;

		d1 = --Ms1 * 30 + Ds1;
		d2 = --Mf1 * 30 + Df1;
		d3 = --Ms2 * 30 + Ds2;
		d4 = --Mf2 * 30 + Df2;

		if (d1 <= d3 && d4 <= d2)
		{
			cout << "люди пересекуться на кол-во дней:" << d4 - d3 + 1 << endl;
		}
		else if (d1 >= d3 && d1 <= d4)
		{
			cout << "люди пересекуться на кол-во дней:" << d4 - d1 + 1 << endl;
		}
		else if (d3 >= d1 && d3 <= d2)
		{
			cout << "люди пересекуться на кол-во дней:" << d2 - d3 + 1 << endl;
		}
		else if (d3 < d1 && d2 < d4)
		{
			cout << "люди пересекуться на кол-во дней:" << d2 - d1 + 1 << endl;
		}
		else
		{
			cout << "люди не пересекутся" << endl;
		}
		//}
	}
	// МАРШРУТ
	void Zadacha11d()
	{
		int L1, L2, M;
		cout << "Введите через пробел размеры очередей на остановках L1, L2 и максимальное кол-во челове к маршрутке M" << endl;
		cin >> L1 >> L2 >> M;
		if (M - L1 <= 0)
		{
			cout << "Очередь на 1-ой остановке останется = " << L1 - M << ". На 2-ой остановке останется = " << L2 << endl;
		}
		else if (L2 + L1 >= M)
		{
			cout << "Очередь на 1-ой остановке останется = 0. На 2-ой остановке останется = " << L2 + L1 - M << endl;
		}
		else
		{
			cout << "Очередь на 1-ой остановке останется = 0. На 2-ой остановке останется = 0. В маршрутке останется свободных мест = " << M - L2 - L1 << endl;
		}
	}
	// РАЗНОСТЬ ДАТ
	void Zadacha12d()
	{
		int d1, m1, y1, d2, m2, y2, dt1, dt2;
		cout << "Первая дата";
		cin >> d1 >> m1 >> y1;
		cout << "Вторая дата";
		cin >> d2 >> m2 >> y2;

		dt1 = y1 * 365 + m1 * 30 + d1;
		dt2 = y2 * 365 + m2 * 30 + d2;

		if (dt1 > dt2)
		{
			cout << "Дата 1 меньше даты 2";
		}
		else if (dt1 = dt2)
		{
			cout << "Даты равны";
		}
		else
		{
			cout << "Дата 2 меньше даты 1";
		}

		//---------------------------------------------
		cout << endl << endl;
		if (y1 < y2)
		{
			cout << "Первая дата меньше ворой";
		}
		else if (y1 = y2)
		{
			if (m1 < m2)
			{
				cout << "Первая дата меньше второй";
			}
			if (m1 > m2)
			{
				cout << "Первая дата больше второй";
			}
			if (m1 = m2)
			{

			}
		}
		if (y1 > y2)
		{
			cout << "Первая дата больше второй";
		}
		//---------------------------------------------
		cout << endl << endl;
		if (d1 == d2 && m1 == m2 && d1 == d2)
		{
			cout << "d1=d2";
		}
		else if (y1 > y2 || y1 == y2 && m1 > m2 || y1 == y2 && m1 == m2 && d1 > d2)
		{
			cout << "d1>d2";
		}
		else
		{
			cout << "d2>d1";
		}


	}

	/*ДОМАШНЕЕ ЗАДАНИЕ ПОСЛОЖНЕЕ от 10.10.2022*/
		//ТИХИЙ ДОМ
	void Zadacha13a()
	{
		//vector<char*> N();
		//vector<char*> M();

		cout << "Введите координаты (вдоль улицы - одна координата на объект) домов через пробел: " << endl;
		cin;


	}

	/*ПРАКТИКА 17.10.2022*/
		//СУММА ПАРЫ ЧИСЕЛ
	void Zadacha5()
	{
		//Ctrl + Z - конец потока, закрытие
		double a, b;	//числа
		int Count;		//счетчик пар
		double sum;		//сумма
		int vers;		//версия программы

		while (true)
		{
			Count = 0;
			sum = 0;
			cout << "Укажите вариант программы 1-3: ";
			cin >> vers;

			switch (vers) {
			case 1:
				while (1)
				{
					cout << "Введите пару чисел или Ctrl+Z: " << endl;
					cin >> a >> b;
					//cin.eof() - возвращает 1 если находимся в конце потока и 0 если конец потока не достигнут.
					if (cin.eof())
						break;
					sum += a + b;
					Count++;
					cin.ignore(cin.rdbuf()->in_avail());
					/*
					cin.clear;
					cin.sync;
					*/
				}
				break;
			case 2:
				while (cout << "Введите 2 числа или Ctrl+Z: " << endl, cin >> a >> b)
				{
					//Оператор 
					Count++;
					sum += a + b;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			case 3:
				for (;; Count++)
				{
					cout << "Введите пару чисел или Ctrl+Z: " << endl;
					cin >> a >> b;
					if (cin.eof())
						break;
					sum += a + b;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			case 4:
				for (; cout << "Введите пару чисел или Ctrl+Z: " << endl, cin >> a >> b; )
				{
					sum += a + b;
					Count++;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			default: cout << "Вариант программы должен быть в диапазоне 1-3!";
			}
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "Сумма равна: " << sum << endl;
			cout << "Кол-во равно: " << Count << endl;
		}
	}
	//Стрельба по мешени
	void Zadacha6()
	{
		int n;			//Кол-во необходимых попаданий
		double r, x, y; //Радиус, Х и Y координаты выстрела
		int k;			//Кол-во произведенных выстрелов
		int i;			//Кол-во совершенных попаданий

		do
		{
			cout << "Введите радиус и кол-во попаданий: ";
			cin >> r >> n;
		} while (r <= 0 || n <= 0);

		for (k = 0, i = 0; i < n; k++)
		{
			cout << "Введите координаты выстрела: ";
			cin >> x >> y;
			if (x * x + y * y <= r * r)
				i++;
		}

		cout << endl << "Для " << n << " попаданий было " << k << " выстрелов." << endl;
	}
	//Найти наименьшее число
	void Zadacha7()
	{
		int max = -1, pos = 1, r = 0;
		int n;

		cout << "Введите число: ";
		cin >> n;


		while (n > 0 || r == 0)
		{
			r++;
			if (n % 10 > max && (n % 10) % 2 == 0) // n%2==0
			{
				max = n % 10;
				pos = r;
			}
			n = n / 10;
		}
		if (max == -1)
		{
			cout << "Максимальная четная цифра отсутствует" << endl;
		}
		else
		{
			cout << "Максимальная четная цифра " << max << ", находится на позиции " << r << endl;
		}
	}
	//Последовательность натуральных чисел
	void Zadacha8()
	{
		int t,			//Текущее значение
			p,			//Предыдущее значение
			i,			//Номер текущего элемента
			kol,		//Кол одинаковых элементов
			pos,		//Начало последовательности
			maxpos = 0,	//Максимальная позиция
			maxkol = 0, //Максимальное кол-во
			maxe;		//максимальная цифра

		maxkol = 0;
		cout << "Введите последовательность натуральных положительных чисел через пробел заканчивающуюся 0: " << endl;
		cin >> p;
		i = 1;
		kol = 1;
		pos = 1;
		cin >> t;
		i = 2;

		while (t)
		{
			if (t == p)
			{
				kol++;
			}
			else
			{
				if (kol > maxkol)
				{
					maxpos = pos, maxkol = kol, maxe = p;
				}
				kol = 1, pos = i;
			}
			p = t;
			cin >> t;
			i++;
		}
		cout << "Максимальная длинна " << maxkol << ", Позиция последовательности " << maxpos << ", Элемент последовательности " << pos;
	}

	/*ДОМАШНЕЕ ЗАДАНИЕ от 17.10.2022*/
		//ВКЛАД
	void Zadacha13d()
	{
		double S, A;
		int N;

		cout << "Введите сумму вклада S: ";
		input_chislo(S);
		cout << "Введите процентную ставку вклада: ";
		input_chislo(A);
		cout << "Введите кол-во месяцев целым числом: ";
		input_chislo(N);

		for (int i = 1; i <= N; i++)
		{
			S *= 1 + A / 100;
		}

		cout << "Размер вклада будет равен = " << round(S * 100) / 100 << endl;
	}
	//ПОГОДА
	void Zadacha14d()
	{
		int i = 0, j = 0;
		double t, tmax, tmp = -1, tso = 0;
		cout << "Введите значение температуры или Ctrl+Z: " << endl;

		while (1)
		{
			cin >> t;
			//cin.eof() - возвращает 1 если находимся в конце потока и 0 если конец потока не достигнут.
			if (cin.eof())
				break;
			//Находим максимальную температуру
			i == 0 ? tmax = t : tmax = t > tmax ? t : tmax;

			//Минимальную температуру среди положительных
			tmp = t >= 0 && (tmp == -1 || tmp > t) ? t : tmp;

			//Среднее среди отрицательных температур
			j += t < 0 ? 1 : 0;
			tso += t < 0 ? t : 0;

			//Счетчик введенных значений и очистка потока
			i++;
			cin.ignore(cin.rdbuf()->in_avail());
		}
		cout << endl << "Кол-во введенных температур: " << i << endl;
		if (i == 0) { cout << endl; return; }

		cout << "Максимальная температура: " << tmax << endl;

		if (tmp != -1)
		{
			cout << "Минимальное значение среди положительных температур: " << tmp << endl;
		}
		else
		{
			cout << "Положительные температуры не вводились" << endl;
		}

		if (j != 0)
		{
			cout << "Средне-отрицательная температура: " << round(tso / j * 100) / 100 << endl;
		}
		else
		{
			cout << "Отрицательные температуры не вводились" << endl;
		}

		cout << endl;
	}
	//ПЕРЕВЕРНУТОЕ ЧИСЛО
	void Zadacha15d()
	{
		int a, b = 0;
		cout << "Введите целое число N: ";
		cin >> a;

		while (1)
		{
			if (a % 10 == 0 && a / 10 == 0) break;
			b = b * 10 + a % 10;
			a = a / 10;
		}

		cout << "Перевернутое число: " << b << endl << endl;
	}
	//ЦЕНЫ
	void Zadacha16d()
	{
		double i, j = 0, imax = -1, imin = -1;
		cout << "Введите значения цен, после завершению Ctrl+Z" << endl;

		while (1)
		{
			cin >> i;
			if (cin.eof()) break;
			if (i < 0)
			{
				cout << "Цена не может быть отрицательной!" << endl; continue;
			}
			else
			{
				j++;
			}
			imax = imax < i || imax == -1 ? i : imax;
			imin = imin > i || imin == -1 ? i : imin;
		}

		if (imax != -1)
		{
			cout << "По ценам " << j << " точек города:" << endl << "Максимальная цена на масло: " << imax << endl << "Минимальная цена на масло: " << imin << endl << endl;
		}
		else
		{
			cout << "Цены не вводились :(";
		}
	}
	//НАИМЕНЬШАЯ НАИБОЛЬШАЯ ЦИФРА
	void Zadacha17d()
	{
		int a, i, max, min;
		cout << "Введите положительное целое число, для окончания введите Ctrl+Z" << endl;

		while (1)
		{
			cin >> a;
			if (cin.eof()) break;
			i = 0, max = -1, min = -1;

			while (1)
			{
				if (a % 10 == 0 && a / 10 == 0) break;
				i++;
				min = min == -1 || min > a % 10 ? a % 10 : min;
				max = max == -1 || (max < a % 10 && i % 2 != 0) ? a % 10 : max;
				a /= 10;
			}
			if (max == -1) { min = 0, max = 0; }
			cout << "Минимальная цифра в этом числе: " << min << endl;
			cout << "Максимальная цифра в разрядах с нечетными номерами в этом числе: " << max << endl << endl;
		}
	}
	//ЛОТЕРЕЯ
	void Zadacha18d()
	{
		const int r1 = 1, r2 = 5;
		int p1, p2, i = 0,
			x1 = 0, x2 = 0, x3 = 0;
		cout << "Введите прогноз ввиде двух числа через пробел, по окончанию Ctrl+Z:";
		while (1)
		{
			cin >> p1 >> p2;
			if (cin.eof()) break;

			if (p1 == r1 && p2 == r2) x1++;
			else if (p1 == r1 || p2 == r2) x2++;
			else x3++;

			i++;

		}
		cout << "Результаты розыгрыша были: " << r1 << " " << r2 << endl
			<< "Два числа угадали: " << x1 << " людей" << endl
			<< "Одно число угадали: " << x2 << " людей" << endl
			<< "Ноль чисел угадали: " << x3 << " людей" << endl
			<< "Данные прислали " << i << " людей" << endl;
	}
	//СОМНОЖИТЕЛИ
	bool prostoe(int n)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0) return false;
		return true;
	}
	void Zadacha19d()
	{
		int n;
		cout << "Введите целое число N: ";
		cin >> n;

		if (prostoe(n)) { cout << "Число само по себе простое"; return; }

		cout << "N = 1";
		for (int i = 2; i <= n; i++)
		{
			if (prostoe(i) && n % i == 0)
			{
				cout << "*" << i;
				n /= i;
				if (n == 1) break;
				i = 1;
			}

		}
		cout << endl;
	}
	void Zadacha19dv2()
	{
		int n;
		cout << "Введите целое число N: ";
		cin >> n;

		cout << "N = 1";
		for (int i = 2; n != 1; i++)
		{
			if (n % i == 0)
			{
				n /= i;
				cout << "*" << i;
				--i;
			}
			else continue;
		}
		cout << endl;
	}
	//РОСТ КУРСА
	void Zadacha20d()
	{
		int n = 0, kur = 0, kurold = 0, kup = 0, kupall = 0, max = 0;

		cout << "Введите через пробел значения курса валют" << endl;
		while (1)
		{
			cin >> kur;
			if (cin.eof())
				break;
			n++;
			if (kur > kurold && kurold)
			{
				kup++;
				kupall++;
				if (max < kup)
					max = kup;
			}
			else
				kup = 0;
			kurold = kur;
		}
		cout << "Самый продолжительный рост был " << max << " дней." << endl;
		cout << "Курс рос " << kupall << " дней из " << n << " дней, т.е. " << kupall * 100 / n << "% дней";
	}
	//СТРАННОЕ УРАВНЕНИЕ
	void Zadacha21d()
	{
		int k, i;
		bool y;
		while (1)
		{
			cout << "Введите число k: ";
			cin >> k;
			if (cin.eof()) break;
			cout << "\t Число N = ";
			y = false;
			i = 1;
			for (int t = k; t / 10 != 0; i++) { t /= 10; }
			for (; i * k < pow(10, i) && i * k >= pow(10, i - 1); i++)
			{
				for (int j = pow(10, i - 1); ; j++)
				{
					if (j == i * k)
					{
						cout << (y ? " ," : "") << j;
						y = true;
						break;
					}
				}
			}
			if (!y) { cout << "Не имеет решения" << endl; }
			else { cout << endl; }
		}
	}
	//ЗАДАЧА Л.ЭЙЛЕРА
	void Zadacha22d()
	{
		int x, y, n,
			s = 1770,
			c1 = 31, c2 = 21;

		cout << "Задача имеет решения ({лошадей:коров}): " << endl;
		for (int n = 10; n < 1770 / 21; n += 10)
		{
			x = (1770 - 21 * n) / 10;
			y = n - x;
			if (y >= 0) { cout << "{" << x << ":" << y << "}" << endl; }
		}
		/* Составим систему уравнений по условию задачи.
		31x + 21y = 1770;
		x + y = N.

		y = N - x;
		31x + 21(N - x) = 1770;
		31x + 21N - 21x = 1770;
		10x = 1770 - 21N;
		x = (1770 - 21N)/10.

		Условию задачи будут удовлетворять те решения системы уравнений, при которых N кратно 10, а x + y = N.
		Для N = 10 нет решений:
		x = (1770 - 210)/10 = 1560/10 = 156.
		Для N = 20:
		x = (1770 - 420)/10 = 135.

		Для N = 30:
		x = (1770 - 630)/10 = 114.

		Для N = 40:
		x = (1770 - 840)/10 = 93.

		Для N = 50:
		x = (1770 - 1050)/10 = 72.

		Для N = 60:
		x = (1770 - 1260)/10 = 51;
		y = 60 - 51 = 9.

		Для N = 70:
		x = (1770 - 1470)/10 = 30;
		y = 70 - 30 = 30.

		Для N = 80:
		x = (1770 - 1680)/10 = 9.
		y = 80 - 9 = 71.

		Ответ: задача имеет три решения (51; 9), (30; 30), (9; 71).*/
	}
	void Zadacha22dv2()
	{
		int y;
		for (y = 1; y <= 84; y++)
			if ((1770 - 21 * y) % 31 == 0)
				cout << (1770 - 21 * y) / 31 << "Лошадей и" << y << " быков" << endl;
	}
	//ЛЕСТНИЦА
	void Zadacha23d()
	{
		//int w = 1, h;
	}

	/*ПРАКТИКА 25.10.2022*/
		//Цифровой корень		
	void Zadacha24()
	{
		int n, s = -1;

		cout << "Введите число n: ";
		cin >> n;
		while (n / 10 != 0)
		{
			s = 0;
			while (n % 10 != 0)
			{
				s += n % 10;
				n /= 10;
			}
			n = s;
		}
		cout << endl << "Цифровой корень числа = " << n;
	}
	//Выкидывание числа
		/*Дано число пример 5385324 ответ 38324*/
	void Zadacha25()
	{
		int a, b, c = 0;
		cout << "Введите число a и какое число выкинуть из а: ";
		cin >> a >> b;

		for (int i = 0; a % 10 != 0; i++)
		{
			if (a % 10 != b)
			{
				c += (a % 10) * pow(10, i);
			}
			else
			{
				i -= 1;
			}
			a /= 10;
		}
		cout << "Ответ = " << c << endl;
	}
	//Треугольник - пересечение с точкой
	void Zadacha26()
	{
		int x1, y1,
			x2, y2,
			x3, y3,
			xt, yt,
			a, b, c, p1, p2, p3,
			s1, s2, s3, s4;

		cout << "Введите координаты точки A: ";
		cin >> x1 >> y1;
		cout << "Введите координаты точки B: ";
		cin >> x2 >> y2;
		cout << "Введите координаты точки C: ";
		cin >> x3 >> y3;
		cout << "Введите координаты точки O: ";
		cin >> xt >> yt;

		a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
		b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
		c = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
		p1 = sqrt(pow(x1 - xt, 2) + pow(y1 - yt, 2));
		p2 = sqrt(pow(x2 - xt, 2) + pow(y2 - yt, 2));
		p3 = sqrt(pow(x3 - xt, 2) + pow(y3 - yt, 2));

		s1 = sqrt(pow(pow(a, 2) + pow(b, 2) + pow(c, 2), 2) - 2 * (pow(a, 4) + pow(b, 4) + pow(c, 4)));
		s2 = sqrt(pow(pow(a, 2) + pow(p1, 2) + pow(p2, 2), 2) - 2 * (pow(a, 4) + pow(p1, 4) + pow(p2, 4)));
		s3 = sqrt(pow(pow(b, 2) + pow(p2, 2) + pow(p3, 2), 2) - 2 * (pow(b, 4) + pow(p2, 4) + pow(p3, 4)));
		s4 = sqrt(pow(pow(c, 2) + pow(p3, 2) + pow(p1, 2), 2) - 2 * (pow(c, 4) + pow(p3, 4) + pow(p1, 4)));

		if (s1 >= s2 + s3 + s4)
		{
			cout << "Точка лежит внутри треугольника";
		}
		{
			cout << "Точка не лежит внутри треугольника";
		}
	}
	//КОПИЛКА - НАЙТИ НАИБОЛЬШУЮ ПОСЛЕДОВАТЕЛЬНОСТЬ
	void Zadacha27()
	{
		int n, x, sum, max;
		max = 0;
		sum = 0;
		cout << "Введите кол-во элементов: 0";
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> x;
			sum = sum + x;
			if (sum > max)
				max = sum;
			if (sum < 0)
				sum = 0;
			if (max == 0)
				cout << "Не было положительных чисел :(";
			else
				cout << max;
		}
	}

	/*ПРАКТИКА 01.11.2022*/
		// Двумерные массивы. Задача про 3 магазина с 4 товарами
	void Zadacha28()
	{
		const int NSHOP = 3; // Число магазинов
		const int NGOODS = 4; // Число товаров
		double r[NSHOP][NGOODS]; // Двумерный
		double svg[4] = { 0, 0, 0, 0 }; //Массив сумм по товарам

		//массив для выручки
		double srshop, sum = 0; // Выручка по
		//магазинам, товарам, общая

		cout << "Введите выручку от чая, сахара, крупы, колбасы \n";

		// Ввод данных
		for (int i = 0; i < NSHOP; i++) { // Перебор магазинов
			cout << "Магазин " << i + 1 << ": ";
			for (int j = 0; j < NGOODS; j++) // Перебор товаров
				cin >> r[i][j];
		} // Ввод выручки i-го магазина от продажи j-го товара

		cout << endl;
		for (int i = 0; i < NSHOP; i++) { // Перебор магазинов
			srshop = 0;
			for (int j = 0; j < NGOODS; j++) // Перебор товаров
			{
				srshop += r[i][j];
				svg[j] += r[i][j];
			}
			cout << "Выручка по магазину:" << i << "= ";
			cout << srshop << endl;
			sum += srshop;
		}

		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "Выручка по товару:" << i << "=" << svg[i] << endl;
		}

		cout << "\n Всего продано за день на: " << sum
			<< endl;
	}
	// Сортировка массива по возрастанию
	void Zadacha29()
	{
		double arr[100], min;
		int n, i, j, imin;

		cout << "Введите элементы массива" << endl;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		for (i = 0; i < n; i++)
		{
			min = arr[i];
			imin = i;
			for (j = i + 1; j < n; j++)
			{
				if (arr[j] < min)
				{
					min = arr[j];
					imin = j;
				}
				double tmp = arr[i];
				arr[i] = arr[imin];
				arr[imin] = tmp;
			}
		}
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	// Сортировка массива по возрастанию вставкой
	void Zadacha30()
	{
		double arr[100], tmp;
		int n, i, j, k;

		cout << "Введите элементы массива" << endl;
		cin >> n;
		for (i = 0; i < n; i++)
			cin >> arr[i];

		for (i = 1; i < n; i++)
		{
			j = 0;
			while (arr[j] < arr[i])
				j++;
			tmp = arr[i];
			for (k = i - 1; k >= j; k--)
				arr[k + 1] = arr[k];
			arr[j] = tmp;

		}

		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
	}
	// С клавиатуры вводится порядок чисел от 0 до 100. Вывести эти числа в порядке возрастания.
	void Zadacha31()
	{
		int t, arr[101] = { 0 };
		int n, i, j;

		cout << "Введите элементы массива" << endl;
		cin >> n;
		for (i = 1; i <= n; i++)
		{
			cin >> t;
			arr[t]++;
		}
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= arr[i]; j++)
				cout << i << " ";
		}
	}
	// Площадки (найти максимальную длинну и высоту площадки лестницы)
	void Zadacha32()
	{
		int h[] = { 1,0,0,-1,2,3,4,5,5,7,4,3,3,3,1,2,3,4,4,4,1,1,1,1,5 };
		int StepsCount = sizeof(h) / sizeof(int);
		int  i, startArea, endArea, maxLArea, maxHArea, Imax = -1;

		for (i = 0; i < StepsCount; i++)
		{
			if (i == 0 || h[i] != h[i - 1])
				startArea = i;
			if (i == StepsCount - 1 || h[i] != h[i + 1])
			{
				endArea = i;
				if (Imax == -1 || endArea - startArea + 1 > maxLArea || endArea - startArea + 1 == maxLArea && h[i] > maxHArea)
				{
					Imax = 1;
					maxLArea = endArea - startArea + 1;
					maxHArea = h[i];
				}
			}
		}
		cout << "Площадка максимальной длинны" << maxLArea << "и макс высоты" << maxHArea << endl;
	}
	//Найти кол-во вхождений каждой цифры в массив
	void Zadacha33()
	{
		int arr[10] = { 0 };
		int n, i;

		cout << "Введите натуральное число: ";
		cin >> n;
		while (n > 0)
		{
			arr[n % 10]++;
			n /= 10;
		}
		for (i = 0; i < 10; i++)
		{
			if (arr[i] != 0)
				cout << "Цифра " << i << " входила " << arr[i] << " раз" << endl;
		}
	}

	/*ДОМАШНЕЕ ЗАДАНИЕ ОТ 31.11.2022*/
			/*Часть 1. Типовые операции с массивами*/
		//Вставить в указанную позицию j числового массива, содержащего N чисел (J < N), заданное число (кол-во элементов должно стать N+1)
	void Zadacha34d()
	{
		int n, i, j;
		double k;

		cout << "Введите кол-во элементов массива" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива" << endl;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		n++;

		cout << "Введите через пробел номер позиции и число" << endl;
		cin >> j >> k;

		//Вставка числа
		for (i = n; i > j - 1; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[j - 1] = k;

		cout << "Получившийся массив: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//Выяснить, содержиться ли в массиве из N элементов заданное значение, если содержитсья то с каким номером(и какой номер последнего такого числа)
	void Zadacha35d()
	{
		int n, i, jone = -1, jlast = -1;
		double k;

		cout << "Введите кол-во элементов массива" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива" << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "Введите искомое число" << endl;
		cin >> k;

		//поиск
		for (i = 0; i < n - 1; i++)
		{
			if (arr[i] == k)
			{
				if (jone == -1)
					jone = i;
				jlast = i;
			}
		}

		if (jone != -1)
		{
			cout << "Певая позиция найденого элемента: " << jone + 1 << endl
				<< "Последняя позиция найденого элемента: " << jlast + 1 << endl;
		}
		else
		{
			cout << "В массиве не искомого числа";
		}
	}
	//Удалить из массива j-й элемент со сдвигом (и сохранением порядка следования последующих элементов)
	void Zadacha36d()
	{
		int n, i = 0, j = 0;

		cout << "Введите кол-во элементов массива" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива" << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "Введите номер позиции j для удаления" << endl;
		cin >> j;

		//удаление
		for (i = j - 1; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}

		//Вывод
		cout << "Получился следущий массив: " << endl;
		for (i = 0; i < n - 1; i++)
		{
			cout << arr[i] << " ";
		}
	}
	//Удалить из массива первый элемент, содержащий заданное число
	void Zadacha37d()
	{
		int n, i;
		double j;
		bool y = false;
		cout << "Введите кол-во элементов массива: " << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива: " << endl;
		for (i = 0; i <= n - 1; i++)
		{
			cin >> arr[i];
		}

		cout << "Введите число для удаления: " << endl;
		cin >> j;

		//удаление
		for (i = 0; i < n; i++)
		{
			if (arr[i] == j)
				y = true;
			if (y && i < n - 1)
				arr[i] = arr[i + 1];
		}
		if (y)
			n--;

		//Вывод
		cout << "Получился следущий массив: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//Удалить из массива последний элемент содержащий заданное число
	void Zadacha38d()
	{
		int n, i, j;
		double k;
		bool y = false;
		cout << "Введите кол-во элементов массива: " << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "Введите число для удаления: " << endl;
		cin >> k;

		//удаление
		for (i = n - 1; i > -1; i--)
		{
			if (arr[i] == k)
			{
				y = true;
				j = i;
				n--;
				break;
			}
		}

		for (i = j; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}

		//Вывод
		cout << "Получился следущий массив: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}

	}
	//Развернуть элементы массива местами
	void Zadacha39d()
	{
		int n, i, j, tmp;
		cout << "Введите кол-во элементов массива: " << endl;
		cin >> n;
		double* arr = new double[n];
		arr[0] = { 0 };

		cout << "Введите элементы массива: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		//цикл
		for (i = 0; i < n / 2; i++)
		{
			tmp = arr[i];
			arr[i] = arr[n - i - 1];
			arr[n - i - 1] = tmp;
		}

		//Вывод
		cout << "Получился следущий массив: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//Упорядочевание элементов по возрастанию, убыванию
	void Zadacha40d()
	{
		//см.Zadacha30()
	}
	//Устранение в массиве повторяющихся элементов
	void Zadacha41d()
	{
		int i, j, k, arr[10] = { 2,5,10,2,6,9,9,5,8,9 };
		int e = 9;

		cout << "Дан массив: " << endl;
		for (i = 0; i <= e; i++)
			cout << arr[i] << " ";
		//удаляем дубликаты
		for (i = 0; i <= e; i++)
		{
			for (j = i + 1; j <= e; j++)
			{
				if (arr[j] == arr[i])
				{
					for (k = j; k < e; k++)
						arr[k] = arr[k + 1];
					e--;
				}
			}
		}
		//Вывод
		cout << endl << "Получился массив:" << endl;
		for (i = 0; i <= e; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	//В двух массивах выделить общие элементы
	void Zadacha42d()
	{
		char m[5][7] = { "Один","Два","Три","Четыре","Пять" };
		char m2[5][7] = { "Три","Один","Два","Семь","Один" };
		char m3[5][7] = { 0 };
		int i, j, l, k, p, n = 0;
		for (i = 0; i < 5; i++)
		{
			for (l = 0; l < 5; l++)
			{
				for (j = 0; ; j++)
					if (m2[i][j] == '\0' || m2[i][j] != m[l][j])
						break;
				if (m2[i][j] == '\0')
				{
					for (k = 0; k < n; k++)
					{
						for (p = 0; p < 7; p++)
							if (m3[k][p] == '\0' || m3[k][p] != m2[i][p])
								break;
						if (m3[k][p] == '\0')
							break;
					}
					if (k == n)
					{
						for (k = 0; ; k++)
						{
							m3[n][k] = m2[i][k];
							if (m2[n][k] == '\0')
								break;
						}
						n++;
					}

					break;
				}
			}

		}
		cout << "Общие елемены: " << endl;
		if (n)
			for (i = 0; i < n; i++)
				cout << m3[i] << endl;
		else
			cout << "нет общих элементов :(";
	}
	//Исключить из массива элементы содержащиеся во втором массиве
	void Zadacha43d()
	{
		int i, j, n = 10, n2 = 10, arr1[50], arr2[50];
		IntArrFillRandom(arr1, n);
		IntArrFillRandom(arr2, n);

		cout << "Массив1" << endl;
		IntArrPrint(arr1, n);
		cout << "Массив2" << endl;
		IntArrPrint(arr2, n2);

		for (i = 0; i < n; i++)
			for (j = 0; j < n2; j++)
				if (arr1[i] == arr2[j])
					ArrDeleleElement(arr1, n, i);

		cout << "Массив1? без значений из массива2" << endl;
		IntArrPrint(arr1, n);
	}
	//Добавить в первый массив те элементы из второго, которых не было в первом.
	void Zadacha44d()
	{
		int arr1[20], arr2[10], n1 = 10, n2 = 10, i, j;
		IntArrFillRandom(arr1, n1);
		Sleep(1000);
		IntArrFillRandom(arr2, n1);

		cout << "Массив1: " << endl;
		IntArrPrint(arr1, n1);
		cout << "Массив2: " << endl;
		IntArrPrint(arr2, n2);

		for (i = 0; i < n2; i++)
		{
			for (j = 0; j < n1; j++)
				if (arr2[i] == arr1[j])
					break;
			if (j == n1)
			{
				arr1[n1] = arr2[i];
				n1++;
			}
		}

		cout << "Массив1 получившийся в результате: " << endl;
		IntArrPrint(arr1, n1);
	}
	/*Часть 2. Задачи на массивы и циклы*/
//ИНВЕРСИЯ
	void Zadacha45d()
	{
		//см.Zadacha39d()
	}
	//УСЕЧЕНОЕ СРЕДНЕЕ
	void Zadacha46d()
	{
		int arr1[10], n1 = 10, i, MAX, MIN, cMAX = 0, cMIN = 0, SUM = 0;
		IntArrFillRandom(arr1, n1);
		cout << "Массив1 из 10 чисел: " << endl;
		IntArrPrint(arr1, n1);
		cout << "Усеченное среднее равно: " << endl;
		MAX = arr1[0]; MIN = arr1[0];
		for (i = 0; i < n1; i++)
		{
			if (MAX == arr1[i])
			{
				MAX = arr1[i]; cMAX++;
			}
			if (MAX < arr1[i])
			{
				MAX = arr1[i]; cMAX = 1;
			}
			if (MIN == arr1[i])
			{
				MIN = arr1[i]; cMIN++;
			}
			if (MIN > arr1[i])
			{
				MIN = arr1[i]; cMIN = 1;
			}
			SUM += arr1[i];
		}
		cout << "Максимальное число равно " << MAX << ", оно встречается " << cMAX << " раз" << endl;
		cout << "Минимальное число равно " << MIN << ", оно встречается " << cMIN << " раз" << endl;
		cout << "Среднее арифметическое без учета MIN и MAX равно: " << (SUM - MAX * cMAX - MIN * cMIN) / (n1 - cMAX - cMIN) << endl;
	}
	//ДОХОДЫ
	void Zadacha47d()
	{
		int arr[12], n = 12, i, SUM = 0;
		IntArrFillRandom(arr, n);
		cout << "Доходы по 12 месяцам: " << endl;
		IntArrPrint(arr, n);
		for (i = 0; i < n; i++)
			SUM += arr[i];
		cout << "Номера месяцев где доходы были выше среднего значения: " << SUM / n << endl;
		for (i = 0; i < n; i++)
			if (arr[i] > (SUM / n))
				cout << i + 1 << " ";
	}
	//СЖАТИЕ
	void Zadacha48d()
	{
		int arr[12], n = 12, i, j;
		IntArrFillRandom(arr, n);
		cout << "Дан случайный массив из 12 элементов: " << endl;
		IntArrPrint(arr, n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
				if (arr[i] == arr[j])
				{
					ArrDeleleElement(arr, n, i);
				}
		}
		cout << "Массив без повторений: " << endl;
		IntArrPrint(arr, n);
	}
	//ДНИ РОЖДЕНИЯ
	void Zadacha49d()
	{
		char Days[7][12] = { "Понедельник","Вторник","Среда","Четверг","Пятница","Суббота","Воскресение" };
		int dayn, pod[7] = { 0 };

		cout << "Введите N дня рождения, по окончанию Ctrl+Z:" << endl;
		while (1)
		{
			cin >> dayn;
			if (cin.eof())
				break;
			else
				if (dayn > 0 && dayn < 8)
					pod[dayn - 1]++;
		}

		for (int i = 0; i < 7; i++)
			cout << Days[i] << " " << pod[i] << endl;

	}
	//ДЛИННАЯ ЦЕПОЧКА НУЛЕЙ
	void Zadacha50d()
	{
		int ch, max = 0, i = 0;
		cout << "Введите числоис нулями" << endl;
		cin >> ch;

		while (ch)
		{
			if (ch % 10 == 0)
			{
				i++;
				if (max < i)
					max = i;
			}
			else
				i = 0;
			ch /= 10;
		}
		cout << "Максимальное число подряд идущих нулей равно " << max << endl;
	}
	//ФОРМИРОВАНИЕ УПОРЯДОЧЕННОГО МАССИВА ВСТАВКАМИ
	void Zadacha51d()
	{
		//см. Zadacha30
	}
	//УПОРЯДОЧЕНИЕ РАСХОДОВ
	void Zadacha52d()
	{
		int arr[12][2], n = 12, i, j, b;
		srand((unsigned)time(NULL));
		for (i = 0; i < n; i++)
		{
			arr[i][0] = i;
			arr[i][1] = rand() % 1000;
		}
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n - 1; j++)
			{
				if (arr[j][1] > arr[j + 1][1])
				{
					b = arr[j][1];
					arr[j][1] = arr[j + 1][1];
					arr[j + 1][1] = b;
					b = arr[j][0];
					arr[j][0] = arr[j + 1][0];
					arr[j + 1][0] = b;
				}
			}
		}

		cout << "Вывод месяцев по убыванию суммы оплаты" << endl;
		for (i = n - 1; i > -1; i--)
			cout << "Месяц номер " << arr[i][0] + 1 << " сумма " << arr[i][1] << endl;
	}
	//ТИХИЙ ДОМ
	void Zadacha53d()
	{
		//см.Zadacha34
	}
	//ДЛИТЕЛЬНОСТИ РАЗГОВОРОВ
	void Zadacha54d()
	{
		//см. Zadacha36
	}
	//АКТУАЛЬНЫЕ ТЕЛЕФОНЫ
	void Zadacha55d()
	{
		int arr1[10], arr2[10], arr3[10] = { 0 }, i, j;
		IntArrFillRandom(arr1, 10);
		Sleep(1000);
		IntArrFillRandom(arr2, 10);
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < 10; j++)
			{
				if (arr1[i] == arr2[j])
				{
					arr3[i] = 1;
					break;
				}
			}
		}
		cout << "Список телефонов: " << endl;
		IntArrPrint(arr1, 10);
		cout << "Список устаревших телефонов: " << endl;
		IntArrPrint(arr2, 10);
		cout << "Актуальные телефонные номера: " << endl;
		for (i = 0; i < 10; i++)
			if (!arr3[i])
				cout << arr1[i] << " ";
	}
	//ЛОТЕРЕЯ
	void Zadacha56d()
	{
		//см.Zadacha38
	}
	//БЫСТРЫЙ ПОИСК*
	void Zadacha57d()
	{
		//см.Zadacha35
	}
	//ГИРИ*
	void Zadacha58d()
	{
		int arr[100], n, i, ch1[100], ch2[100], r1 = 0, r2 = 0, sum1 = 0, sum2 = 0, max;
		cout << "Введите кол-во гирь:" << endl;
		cin >> n;
		cout << "Введите веса гирь" << endl;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		while (n)
		{
			IntArrMaxFind(arr, n, max);
			if (sum1 == 0 || sum1 <= sum2)
			{
				r1++;
				ch1[r1 - 1] = arr[max];
				sum1 += arr[max];
			}
			else
			{
				r2++;
				ch2[r2 - 1] = arr[max];
				sum2 += arr[max];
			}
			ArrDeleleElement(arr, n, max);
		}

		cout << "Гири на первой чаше:" << endl;
		IntArrPrint(ch1, r1);
		cout << "Гири на второй чаше:" << endl;
		IntArrPrint(ch2, r2);
		cout << "Разница между весом чаш: " << abs(sum1 - sum2) << endl;

	}
	//ТОМА**
	void Zadacha59d()
	{
		int arr[100], n, i, j, K, sh, tmp, Max, Min, Krat, gK = 0, gR = -1, gKMax = 0, gKMin = 0;
		cout << "Введите кол-во отчетов:" << endl;
		cin >> n;

		for (i = 0; i < n; i++)
		{
			cout << "Введите кол-во страниц в " << i << "-ом отчете" << endl;
			cin >> arr[i];
		}

		for (K = 2; K < n; K++)
		{
			Max = 0;
			Min = 0;
			Krat = (int)round((double)n / K);
			sh = 0;
			for (i = 0; i < n; i += Krat)
			{
				tmp = 0;
				if (sh == K)
					break;
				for (j = i; j < n && (j < i + Krat || sh == K - 1); j++)
					tmp += arr[j];
				if (Max < tmp)
					Max = tmp;
				if (Min > tmp || Min == 0)
					Min = tmp;
				sh++;
			}
			if (gR > Max - Min || gR == -1)
			{
				gK = K;
				gR = Max - Min;
				gKMax = Max;
				gKMin = Min;
			}
		}

		cout << "Самый лучший вариант разделить на К=" << gK << " томов." << endl <<
			"Максимально страниц в томе " << gKMax << ", а минимально " << gKMin << endl <<
			"Разница между страницами в томах составит " << gR << " страниц" << endl;

	}


	/*ПРАКТИКА 08.11.2022*/
		//Тихий дом
	void Zadacha34()
	{
		double h[100], sh[100];
		int N, M, i, j;
		double max = 0, min, ihouse;

		cout << "Введите кол-во домов: " << endl;
		cin >> N;

		cout << "Введите координаты дома: " << endl;
		for (i = 0; i < N; i++)
		{
			cin >> h[i];
		}

		cout << "Введите кол-во источников шума: " << endl;
		cin >> M;

		cout << "Введите координаты источников шума: " << endl;
		for (i = 0; i < M; i++)
		{
			cin >> sh[i];
		}

		//ТИХИЙ ДОМ
		for (i = 0; i < N; i++)
		{
			min = fabs(h[i] - sh[0]);
			for (j = 1; j < M; j++)
			{
				if (fabs(h[i] - sh[j]) < min)
					min = fabs(h[i] - sh[j]);
				if (min > max)
				{
					max = min;
					ihouse = h[i];
				}
			}
		}

		cout << "Дом " << ihouse << " Расстояние " << max;

	}
	//Быстрый поиск в массиве упорядоченном по возрастанию
	void Zadacha35()
	{
		int dat, n, b, e, i, sr = 0, arr[100];
		cout << "введите кол-во элементов массива";
		cin >> n;

		for (i = 0; i < n; i++)
			arr[i] = i;
		cout << "Введите элемент";
		cin >> dat;

		b = 0; e = n;
		while (b != e)
		{
			sr = (b + e) / 2; //ищем серединку
			if (arr[sr] == dat)
				break;
			if (arr[sr] > dat)
				e = sr;
			else
				b = sr + 1;
		}
		if (sr == dat)
			cout << "Найдено";
		else
			cout << "Не найдено";

	}
	//Длительность разговоров
	void Zadacha36()
	{
		int arr[100][2];
		int num, time, n, i, j, kol = 0;

		cout << "Введите кол-во разговоров";
		cin >> n;
		cout << "Введите телефон и продолжительность";

		for (i = 1; i <= n; i++)
		{
			cin >> num >> time;
			j = 0;
			while (j < kol && arr[j][0] != num)
				j++;
			if (j < kol)
				arr[j][1] += time;
			else
			{
				arr[j][0] = num;
				arr[j][1] = time;
				kol++;
			}

			cout << "Тел \t время" << endl;
			cout << arr[i][0] << "\t" << arr[i][1] << endl;
		}
	}
	//Реверс массива (с двумя счетчиками)
	void Zadacha37()
	{
		int arr[100], n, tmp, i, up, down;
		cout << "Введите кол-во лементов";
		cin >> n;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
			up = 0;
			down = n - 1;
			while (up < down)
			{
				if (up < down)
				{
					tmp = arr[up];
					arr[up] = arr[down];
					arr[down] = tmp;
					up++;
					down--;
				}
			}
		}
		for (i = 0; i < n; i++)
			cout << arr[i] << "j";
	}
	//Лотерея
	void Zadacha38()
	{
		int arr[100][2], n, i, num1, num2, k, win[3] = { 0 };
		cout << "Введите кол-во участников";
		cin >> n;
		cout << "Введите данные участников";
		for (i = 0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1];
		cout << "Введите выигрышные номера: " << endl;
		cin >> num1 >> num2;
		for (i = 0; i < n; i++)
		{
			k = 0;
			if (arr[i][0] == num1 && arr[i][1] == num1)
				k++;
			if (arr[i][1] == num2 && arr[i][1] == num2)
				k++;
			win[k]++;
		}
		for (i = 0; i < 3; i++)
			cout << i << "чисел совпало у " << win[i] << " человек";
	}
	/* С клавиатуры вводятся вводится натуральное число, определить можно ли из него путем перестановок цикл получить полиндром*/
	/*Построить максимальный и минимальный полиндромы */
	void Zadacha39()
	{
		int i, j, k, l, a, nech = 0, n, arr[10] = { 0 };
		int centr = -1;
		bool prtnull = false;

		cout << "Введите кол-во лементов: " << endl;
		cin >> n;
		cout << "Введите " << n << " элементов массива: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> a;
			arr[a]++;
		}

		//Строим максимальный полиндром
		cout << "Максимальный полиндром: " << endl;
		for (i = 9; i >= 0; i--)
		{
			if (arr[i] % 2 != 0)
			{
				nech++;
				centr = i;
			}
			if (nech > 1)
			{
				cout << "Палиндром построить нельзя. Много нечетных количеств цифр :(";
				break;
			}
			for (j = 0; j < arr[i] / 2; j++)
			{
				cout << i;
			}
		}
		if (centr != -1)
			cout << centr;
		for (i = 0; i < 10; i++)
		{
			for (j = 0; j < arr[i] / 2; j++)
			{
				cout << i;
			}
		}


		//Строим минимальный полиндром
		nech = 0;
		cout << endl << "Минимальный полиндром: " << endl;
		for (i = 1; i < 10; i++)
		{
			if (arr[i] % 2 != 0)
			{
				nech++;
				centr = i;
			}
			if (nech > 1)
			{
				cout << "Палиндром построить нельзя. Много нечетных количеств цифр :(";
				break;
			}
			for (j = 0; j < arr[i] / 2; j++)
			{
				cout << i;
				if (prtnull == false)
				{
					l = i;
					for (k = 0; k < arr[0] / 2; k++)
					{
						cout << "0";
						if (arr[0] % 2 != 0)
						{
							nech++;
							centr = 0;
						}
					}
					prtnull = true;
				}
			}
		}
		if (centr != -1)
			cout << centr;
		prtnull = false;
		for (i = 9; i > 0; i--)
		{
			for (j = 0; j < arr[i] / 2; j++)
			{
				cout << i;
				if (i == l + 1)
				{
					if (prtnull == false)
					{
						for (k = 0; k < arr[0] / 2; k++)
						{
							cout << "0";
							if (arr[0] % 2 != 0)
							{
								nech++;
								centr = 0;
							}
						}
						prtnull = true;
					}
				}
			}
		}
		cout << endl;
	}
	void Zadacha39v2()
	{
		int arr[10] = { 0 };
		int n, i, j, f = -1, kol_nech = 0, kol = 0, pos = 1;

		cout << "Введите число: ";
		cin >> n;
		while (n > 0)
		{
			arr[n % 10]++;
			n = n / 10;
			kol++;
		}
		for (i = 0; i < 10; i++)
			if (arr[i] % 2)
			{
				kol_nech++;
				f = i;
			}
		if (arr[0] == kol - 1)
			cout << "Нельзя построить полиндром :(" << endl;
		if (kol_nech > 1)
			cout << "Нельзя построить полиндром :(" << endl;
		else
		{
			cout << "Максимальный полиндром: " << endl;
			for (i = 9; i >= 0; i--)
			{
				for (j = 1; j <= arr[i] / 2; j++)
					cout << i;
			}
			if (f != -1)
				cout << f;
			for (i = 0; i < 10; i++)
			{
				for (j = 1; j <= arr[i] / 2; j++)
					cout << i;
			}

			cout << endl << "Минимальный полиндром: " << endl;
			while (arr[pos] < 2)
				pos++;
			cout << pos;
			arr[pos] -= 2;
			for (i = 0; i < 10; i++)
				for (j = 1; j <= arr[i] / 2; j++)
					cout << i;
			if (f != -1)
				cout << f;
			for (i = 9; i >= 0; i--)
				for (j = 1; j <= arr[i] / 2; j++)
					cout << i;
			cout << pos << endl;
		}
	}

	/*ПРАКТИКА 15.11.2022*/
		//Замена элементов массива
	void Swap(double arr[], int down, int up)
	{
		double tmp = arr[down];
		arr[down] = arr[up];
		arr[up] = tmp;
	}
	int del_el(double arr[], int n, int pos)
	{
		for (int i = pos + 1; i < n; i++)
			arr[i - 1] = arr[i];

		//Второй вариант переезда
		//for (int i = pos; i < n - 1; i++)
		//	arr[i] = arr[i + 1];

		return n - 1;
	}
	int main_swap(double arr[], int n)
	{
		int down = 0, up = n - 1;
		while (down <= up)
		{
			if (arr[up] == 0)
			{
				n = del_el(arr, n, up);
				up--;
			}
			else if (arr[down] == 0)
			{
				arr[down++] = arr[up--];
				n = del_el(arr, n, up + 1);
			}
			else
			{
				Swap(arr, down, up);
				down++;
				up--;
			}
		}
		return n;
	}
	void Scan_arr(double arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
	}
	void Print_arr(double arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	void Scan_arr(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cin >> arr[i];
	}
	void Print_arr(int arr[], int n)
	{
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
	}
	void Zadacha40()
	{
		double arr[100];
		int n;
		cout << "Введите кол-во элементов: ";
		cin >> n;

		Scan_arr(arr, n);
		n = main_swap(arr, n);
		cout << "Измененный массив: " << endl;
		Print_arr(arr, n);

		cout << endl;
	}

	//Список фамилий
	void Zadacha41()
	{
		const int MAXCount = 100;
		const int MAXLENNAME = 20;
		const int MAXLENPHONE = 16;
		int n = 4, i, j, f, Count = 0;

		char tmp[MAXLENPHONE];

		char name[MAXCount][MAXLENNAME] = { "Иванов ИИ","Петров ПП","Зайцев АС","Волков ВП" };
		char phone[MAXCount][MAXLENPHONE] = { "461-74-88","452-74-85","950-261-74-83","950-382-47-83" };

		cout << "Введите шаблон телефона: " << endl;
		cin >> tmp;
		//cin.getline(tmp, MAXLENPHONE); //Вариант

		for (i = 0; i < n; i++)
		{
			f = 1;
			for (j = 0; tmp[j] != '\0'; j++)
			{
				if (tmp[j] != phone[i][j] && tmp[j] != '?')
				{
					f = 0;
					break;
				}
			}
			if (f == 1)
			{
				cout << "Фамилия ";
				for (j = 0; name[i][j] != '\0'; j++)
				{
					cout << name[i][j];
				}
				for (j = 0; phone[i][j] != '\0'; j++)
					cout << phone[i][j];
				//cout << "Фамилия " << name[i] << "\t" << "Телефон " << phone[i];
				Count++;
			}
		}
		if (Count == 0)
			cout << endl << "Подходящих номеров нет :(";
	}
	//СДЕЛАТЬ ЗАДАЧУ 41 С ФУНКЦИЯМИ(МОДИФИЦИРОВАТЬ)!!!

	/*ДОМАШНЕЕ ЗАДАНИЕ ОТ 18.11.2022*/
		/*ЧАСТЬ 1*/
	//ПРОСТОЙ ПАЛИНДРОМ
	void Zadacha60d()
	{
		int l;
		cout << "Введите макс длинну строки: ";
		cin >> l;
		cout << endl;
		char* str = new char[l];
		cout << "Введите строку: " << endl;
		cin >> str;
		if (IsCharPalindrom(str, l))
			cout << "Да, строка палиндром :)";
		else
			cout << "Нет, увы строка не палиндром :(";
	}
	//ПОИСК СТРОКИ В МАССИВЕ
	void Zadacha61d()
	{
		int i = 0, j = 0, f = 0;
		char Name[][20] = { "Строка1","Строка2","Строка3","Строка4" };
		char Search[20];

		cout << "Введите строку для поиска: ";
		cin.getline(Search, 20);

		while (i < sizeof(Name) / sizeof(Name[0]))
		{
			while (j < 20)
			{
				if (Search[j] != Name[i][j])
					break;
				if (Search[j] == '\0' && Name[i][j] == '\0')
				{
					f = i; break;
				}
				j++;
			}
			i++;
		}
		if (f)
		{
			cout << "В массиве есть такая строка, позиция " << f << endl;
		}
		else
		{
			cout << "В массиве нет искомой строки :( " << endl;
		}
	}
	//СПИСОК
	void Zadacha62d()
	{
		int N, l, i, j, s;

		cout << "Введите кол-во строк массива: ";
		cin >> N;
		cout << "Введите длинну строк массива: ";
		cin >> l;

		char** Names = new char* [N];
		for (i = 0; i < N; i++)
			Names[i] = new char[l];

		int* st = new int[N];
		char* f = new char[l];

		cout << endl << "Введите Фамилии: " << endl;
		CharArrFill(Names, N, l);

		cout << endl << "Введите стаж: " << endl;
		IntArrFill(st, N);


		cout << endl << "А. Введите Фамилию для поиска: ";
		cin >> f;
		for (i = 0; i < N; i++)
		{
			if (CharStrictMatching(f, Names[i]))
			{
				cout << "Стаж работника равен: " << st[i] << endl;
			}
		}

		cout << endl << "Б. Введите стаж: ";
		cin >> s;
		cout << "С выбранным стажем: " << endl;
		for (i = 0; i < N; i++)
		{
			if (st[i] == s)
				cout << Names[i] << endl;
		}

		cout << endl << "В. Фамилии с максимальным стажем: " << endl;
		s = 0;
		for (i = 0; i < N; i++)
			if (st[i] > s)
				s = st[i];
		for (i = 0; i < N; i++)
		{
			if (st[i] == s)
				cout << Names[i] << endl;
		}
	}
	//КЛЮЧ С'?'										
	void Zadacha63d()
	{
		char str[25];
		char mask[25];
		cout << "Введите маску для поиска (спец символ для неизвестных символов - ?): " << endl;
		cin >> mask;

		cout << "Введите строку для поиска соответствия маске либо Ctrl + Z: " << endl;
		while (1)
		{
			cin >> str;
			if (cin.eof())
				break;
			cin.ignore(cin.rdbuf()->in_avail());
			if (CharNotStrictMatching(str, mask, '?'))
				cout << "Слово совпадает с маской :)" << endl;
			else
				cout << "Слово не совпадает с маской :(" << endl;
		}
	}
	//НАИБОЛЬШЕЕ ПОВТОРЕНИЕ СИМВОЛА					
	int Zadacha64_func1(char str[], char Symbol, int& MaxOccurrences)
	{
		int Occ = 0;
		MaxOccurrences = 0;
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == Symbol)
				Occ++;
			else
				Occ = 0;
			if (Occ > MaxOccurrences)
				MaxOccurrences = Occ;
		}
		return 0;
	}
	void Zadacha64d()
	{
		int max;
		char str[20], c;
		cout << "Введите строку: " << endl;
		cin >> str;
		cout << "Введите символ: " << endl;
		cin >> c;
		Zadacha64_func1(str, c, max);
		cout << "Максимальное повторение символа '" << c << "' в строке: " << endl << max << endl;
	}
	//ДЛИННАЯ ЦЕПОЧКА
	void Zadacha65d()
	{
		int max = 0, i = 0, cmax = 0;
		char str[20], c;
		cout << "Введите строку: " << endl;
		cin >> str;
		while (str[i] != '\0')
		{
			Zadacha64_func1(str, str[i], max);
			if (max > cmax)
			{
				cmax = max;
				c = str[i];
			}
			i++;
		}
		cout << "Максимально в строке повторяется символ '" << c << "' в кол-ве " << cmax << " раз" << endl;
	}
	//СКОБКИ
		/*Вариант со счетчиком*/
	void Zadacha66d()
	{
		char s[100];
		int Count = 0, i;
		bool f = true;

		cout << "Введите строку: ";
		cin.getline(s, 100);

		for (i = 0; s[i] != '\0'; i++) //i < strlen(s)
		{
			if (s[i] == '(')
			{
				Count++;
			}
			else if (s[i] == ')')
			{
				if (Count > 0)
					Count--;
				else
				{
					f = false;
					break;
				}
			}
		}

		if (f && Count == 0)
			cout << "Скобки расставлены правильно :)";
		else
			cout << "Скобки расставлены не правильно :(";
	}
	//Варинат без счетчика
	void Zadacha66v2()
	{
		char s[100];
		int Count = 0;
		bool f = true;
		cout << "Введите строку со скобками";
		cin.getline(s, 100);

		char* ps = s;
		for (; *ps != '\0'; ps++)
		{
			if (*ps == '(')
				Count++;
			else if (*ps == ')')
			{
				if (Count > 0)
					Count--;
				else
				{
					f = false;
					break;
				}
			}
			if (f && Count == 0)
				cout << "Скобки расставлены правильно :)";
			else
				cout << "Скобки расставлены не правильно :(";
		}
	}
	//НАИБОЛЕЕ ГЛУБОКО ВЛОЖЕННЫЙ ТЕКСТ
	void Zadacha67d()
	{
		char s[100];
		char* ps, * st, * fin;
		int level = 0, maxlevel = 0;
		bool f = false;

		cout << "Введите строку";
		cin.getline(s, 100);
		st = s; fin = s;
		for (ps = s; *ps != '\0'; ps++)
		{
			if (*ps == '(')
			{
				level++;
				f = true;
			}
			else if (*ps == ')')
			{
				if ((*(ps - 1) != '(' || *(ps - 1) != ')') && (level > maxlevel))
				{
					maxlevel = level;
					fin = ps - 1;
				}
				level--;
			}
			else
			{
				if (ps != s && *(ps - 1) == '(' && level > maxlevel)
					st = ps;
			}
		}

		cout << "Введите строку";
		if (f)
			while (st <= fin)
				cout << *(st++);
		else
			cout << s;

	}
	//АРИФМЕТИКА									
	void Zadacha68d()
	{
		char a[100], b[100], c[101];
		int i, cel = 0, c_a, c_b;

		cout << "Введите первое число: ";
		cin >> a; //Считываем слово
		cout << "Введите второе число: ";
		cin >> b; //Считываем слово

		revers_char_arr(a);
		revers_char_arr(b);

		if (strlen(a) > strlen(b))
		{
			for (i = strlen(b); i < strlen(a); i++)
				b[i] = '0';
			b[strlen(a)] = '\0';
		}
		else if (strlen(b) > strlen(a))
		{
			for (i = strlen(a); i < strlen(b); i++)
				a[i] = '0';
			a[strlen(b)] = '\0';
		}
		for (i = 0; a[i] != '\0'; i++)
		{
			c_a = a[i] - '0';
			c_b = b[i] - '0';
			c[i] = (c_a + c_b + cel) % 10 + '0';
			cel = (c_a + c_b) / 10;
		}
		if (cel > 0)
			c[i++] = cel + '0';
		c[i] = '\0';
		revers_char_arr(a);
		revers_char_arr(b);
		revers_char_arr(c);

		cout << endl << "Решение: " << endl;
		cout << a << "+" << b << "=" << c;
	}
	//ВЫБРАКОВКА++
	int* Zadacha69dfunc(int arr[], int sizearr, int& sizeculling)
	{
		int* carr = (int*)malloc(0 * sizeof(int));
		sizeculling = 0;
		for (int i = 0; i < sizearr; i++)
		{
			if (arr[i] > 0)
			{
				sizeculling++;
				carr = (int*)realloc(carr, sizeculling * sizeof(int));
				carr[sizeculling - 1] = arr[i];
			}
		}
		if (sizeculling)
			return carr;
		else
			return NULL;
	}
	void Zadacha69d()
	{
		int a[100], n, s;
		int* c;

		cout << "Введите размер массива не более 100: " << endl;
		cin >> n;
		cout << "Введите числа массива: " << endl;
		IntArrFill(a, n);
		c = Zadacha69dfunc(a, n, s);
		cout << "Массив выбраковки: " << endl;
		Print_arr(c, s);
	}
	//ПОИСК+ЗАМЕНА									
	char* Zadacha70dfunc(char arr[], int size, char c)
	{
		for (int i = 0; i < size; i++)
			if (arr[i] == c)
				return &arr[i];
		return NULL;
	}
	void Zadacha70d()
	{
		int n = 0;
		char a[100], c;
		char* u;

		cout << "Введите символ для внесения в массив или Ctrl+Z: " << endl;
		while (1)
		{
			if (cin.eof())
			{
				n--;
				break;
			}
			cin >> a[n];
			n++;
			cin.ignore(cin.rdbuf()->in_avail());
		}


		cout << "Получился массив: " << endl;
		CharArrPrint(a, n);

		cin.clear();
		cout << "Введите символ для замены" << endl;
		cin >> c;
		u = Zadacha70dfunc(a, n, c);
		if (u == NULL)
		{
			cout << "Символ в массиве не найден";
			return;
		}
		else
			cout << "Символ найден и заменен на '@'" << endl;

		while (1)
		{
			u = Zadacha70dfunc(a, n, c);
			if (u != NULL)
				*u = '@';
			else
				break;

		}
		cout << "После замены получился массив: " << endl;
		CharArrPrint(a, n);
	}
	//РАСШИФРОВКА**
	int Zadacha71dfunc(char a[], int size_a)
	{
		int n1 = 0, n2 = 0;
		for (int i = 0; i + 1 < size_a; i += 2)
		{
			if (CharNumberToInt(a, 2, i) < 32)
				n1++;
			if (i + 2 < size_a && CharNumberToInt(a, 2, i + 1) < 32)
				n2++;
		}
		return n1 + n2; //n1 > n2 ? n1 : n2;
	}
	void Zadacha71d()
	{
		int s, max;
		char* str;


		cout << "Введите размер строки: " << endl;
		cin >> s;
		str = new char[s];

		cin.ignore(cin.rdbuf()->in_avail());
		cout << "Введите закодированную строку: " << endl;
		cin.getline(str, s);

		max = Zadacha71dfunc(str, s);

		cout << "Возможное кол-во вариантов расшифровки " << pow(2, max) << endl;

	}
	/*ЧАСТЬ ВТОРАЯ*/
//1.Вставка в указанную позицию числового массива заданного значения (количество элементов должно возрасти).
	void Zadacha72d()
	{
		int n; //Размер массива
		int j; //Позиция для замены
		double k; //Число для замены

		cout << "Введите кол-во элементов массива" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива" << endl;
		Scan_arr(arr, n);

		cout << "Введите через пробел номер позиции и число" << endl;
		cin >> j >> k;

		DoubleArrAddElement(arr, n, j, k);

		cout << "Получившийся массив: " << endl;
		Print_arr(arr, n);
		cout << endl << endl;
	}
	//2. Загрузка в массив заданного размера данных с консоли.
	void Zadacha73d()
	{
		int n; //Размер массива

		cout << "Введите кол-во элементов массива" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "Введите элементы массива" << endl;
		Scan_arr(arr, n);

		cout << "Проверка введенного массива" << endl;
		Print_arr(arr, n);
	}
	//3. Определение позиции первого / последнего вхождения в заданный массив заданного значения.
	void Zadacha74d()
	{
		int i, st, fin;
		char s[100], c;

		cout << "Введите строку" << endl;
		cin.getline(s, 100);

		cout << "Введите символ" << endl;
		cin.get(c);

		cout << "Первое вхождение элемента" << endl;
		if (PosElementInChar(s, c, &st, &fin))
			cout << "Позиция первого вхождения элемента: " << st << endl << "Позиция последнего вхождения элемента: " << fin;
		else
			cout << "Элемент не найден";
	}
	//4.Удаление из массива элемента с заданным номером(с сохранением порядка следования) последующих элементов.
	int delchar_Zadacha75d(char s[], char c)

	{
		int i, j = 0;
		for (i = 0; s[i] != '\0'; ++i) // перебор элементов
			if (s[i] != c)
			{ // Если символ s[i] не удаляемый,
				s[j] = s[i]; // копируется на новое место строки
				++j; // Счетчик оставленных в строке символов
			}

		s[j] = '\0'; // Фиксируем новый конец строки
		return j; //Возврат кол-ва символов в строке
	}
	void Zadacha75d()
	{
		const int N = 200; // Размер массива
		char st[N]; // Массив для строки
		setlocale(LC_ALL, "Russian");
		cout << "Введите строку:\n";
		cin.getline(st, N); // Ввод строки
		int n = strlen(st); // Находим длину строки
		cout << "Длина введенной строки: " << n;
		cout << endl;
		cout << "Введите удаляемый символ ";
		char dc = cin.get(); // Ввод символа
		n = delchar_Zadacha75d(st, dc); // Вызов функции
		cout << "Обработанная строка:\n";

		// Настройка на кодовую страницу 866
		// для вывода русских символов
		setlocale(LC_ALL, ".866");
		cout << st << endl;
		setlocale(LC_ALL, "Russian");
		cout << "ее длина: " << n << endl;
	}
	//5. Удаление из массива первого элемента, совпадающего с заданным числом.
	void Zadacha76d()
	{
		int arr[5], n = 5, pos, c;
		cout << "Введите " << n << " шт. элементов массива: " << endl;
		IntArrFill(arr, n);
		cout << "Введите элемент для удаления: " << endl;
		cin >> c;
		if (PosFirstElementInArray(arr, c, n, pos))
		{
			ArrDeleleElement(arr, n, pos);
			cout << "Элемент удален, массив в результате: " << endl;
		}
		else
			cout << "Элемент найден, исходный массив: " << endl;
		Print_arr(arr, n);
	}
	//6. Удаление из массива всех элементов, содержащих заданное число.
	void Zadacha77d()
	{
		int arr[5], n = 5, pos, c;
		cout << "Введите " << n << " шт. элементов массива: " << endl;
		IntArrFill(arr, n);
		cout << "Введите элемент для удаления: " << endl;
		cin >> c;
		while (PosFirstElementInArray(arr, c, n, pos))
			ArrDeleleElement(arr, n, pos);
		cout << "Массив в результате:" << endl;
		Print_arr(arr, n);
	}
	//7. Перестановка элементов массива в обратном порядке.
	void revers_Zadacha78d(char s[])

	{

		int i, j; // Прямой и обратный счетчики

		char tmp; // Для обмена символов

		for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {

			tmp = s[i];

			s[i] = s[j];

			s[j] = tmp;
		}

	}
	void Zadacha78d()
	{
		setlocale(LC_ALL, "Russian");
		const int MAX = 100; // Размер строк
		char orig_s[MAX]; // Исходная строка
		char rev_s[MAX]; // Реверсированная строка

		cout << "Введите строку: ";
		cin.getline(orig_s, MAX); // Ввод строки
		strcpy(rev_s, orig_s); // Копируем orig_s в rev_s
		revers_Zadacha78d(rev_s); // Реверсирование строки rev_s

		cout << "Реверсированная строка: ";
		cout << rev_s << endl; // Вывод rev_s
	}
	//8. Упорядочение элементов массива по возрастанию / убыванию.													
	void Zadacha79d()
	{
		int arr[5], n = 5;
		cout << "Введите " << n << " шт. элементов массива: " << endl;
		IntArrFill(arr, n);
		arr_sort_bubble(arr, n);
		cout << endl << "Массив отсортирован по возрастанию" << endl;
		Print_arr(arr, n);
		cout << endl << "Массив отсортирован по убыванию" << endl;
		arr_revers(arr, n);
		Print_arr(arr, n);
	}
	//9. Устранение из массива повторяющихся элементов.
	void Zadacha80d()
	{
		int arr[5], n = 5, pos;
		cout << "Введите " << n << " шт. элементов массива: " << endl;
		IntArrFill(arr, n);
		for (int i = 0; i < n - 1; i++)
		{
			while (PosFirstElementInArray(arr, arr[i], n, i + 1, pos))
				ArrDeleleElement(arr, n, pos);
		}
		cout << "Массив без повторений" << endl;
		Print_arr(arr, n);
	}
	//10. Удаление из массива элементов, содержащихся во втором массиве.
	void Zadacha81d()
	{
		int arr1[5], arr2[3], n = 5, n2 = 3, pos;
		cout << "Введите " << n << " шт. элементов первого массива: " << endl;
		IntArrFill(arr1, n);
		cout << "Введите " << n2 << " шт. элементов второго массива: " << endl;
		IntArrFill(arr2, n2);
		for (int i = 0; i < n2; i++)
		{
			while (PosFirstElementInArray(arr1, arr2[i], n, pos))
				ArrDeleleElement(arr1, n, pos);
		}

		cout << "Массив 1 без значений массива 2:" << endl;
		Print_arr(arr1, n);
	}
	/*ПРАКТИКА 22.11.2022*/
	void Zadacha42()
	{
		//Рассматривали задачи Скобки два варианта, Поиск строки, Арифметика
	}

	/*ПРАКТИКА 29.11.2022*/
	//Написать функцию рекурсивного вычисления факториала используя внутренее расширяющееся хранилище
	using ulong = unsigned long long; //свой тип
	using uint = unsigned int;
	ulong Do_fact(uint n)
	{
		static uint maxn = n;
		static ulong* buf = nullptr;
		uint i;
		if (buf == nullptr || maxn < n)
		{
			ulong* b = new (nothrow) ulong[n + 1];
			if (!b)  //b==nullptr
			{
				if (buf)
				{
					delete[] buf;
					buf = nullptr;
					maxn = 0;
					return 0;
				}
			}
			for (i = 0; i <= n; i++)
			{
				if (buf && i <= maxn)
					b[i] = buf[i];
				else
					b[i] = 0;
			}
			delete[] buf;
			buf = b;
			maxn = n;
		}
		if (n == 0) //очистка буффера
		{
			delete[] buf;
			buf = nullptr;
			maxn = 0;
			return 1;
		}
		if (n == 1)
			return 1;
		if (buf[n])
			return buf[n];
		if (buf[n - 1])
			buf[n] = buf[n - 1] * n;
		else
			buf[n] = Do_fact(n - 1) * n;
		return buf[n];
	}
	void Zadacha43()
	{
		uint N;
		cout << "Введите N=";
		cin >> N;
		cout << Do_fact(N);
	}

	// Рекурсивный поиск позиции в отсортированном массиве.Если элемент не найден возвращаем - 1; На основе бинарного поиска
	int SearchInArr(int* x, int dat, int down, int up)
	{
		int sr;
		if (down > up)
			return -1;
		sr = (up + down) / 2;
		if (x[sr] == dat)
			return sr;
		if (dat < x[sr])
			SearchInArr(x, dat, down, sr - 1);
		else
			SearchInArr(x, dat, sr + 1, up);
	}
	void Zadacha44()
	{
		int N, arr[9] = { 1,2,3,4,5,6,7,8,9 };
		cout << "Введите N для поиска" << endl;
		cin >> N;
		cout << "Позиция искомого элемента" << endl << SearchInArr(arr, N, 0, 9);

	}

	//Телефонный справочник
	void replace_phone(char** name, char** phone, int Count, char* N, char* P)
	{
		int i = 0;
		while (i < Count && strcmp(name[i], N))
			i++;
		if (i < Count)
		{
			delete[] phone[i];
			phone[i] = new char[strlen(P) + 1];
			strcpy(phone[i], P);
		}
	}
	void Zadacha45()
	{
		char* name[100], * phone[100];
		int n;
		char N[20], P[20];

		cout << "Введите кол-во телефонов" << endl;
		cin >> n;

		cout << "Введите Имя и Телефон: " << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> N >> P;
			name[i] = new char[strlen(N) + 1];
			strcpy(name[i], N);
			phone[i] = new char[strlen(P) + 1];
			strcpy(phone[i], P);
		}

		cout << "Введите Имя и Телефон для замены" << endl;
		cin >> N >> P;
		replace_phone(name, phone, n, N, P);
		for (int i = 0; i < n; i++)
			cout << name[i] << " " << phone[i] << endl;
	}

	//Написать рекурсивную функцию считающий N-ый элемент последовательности Фибоначчи
	int fib(int n)
	{
		if (n <= 2)
			return 1;
		else
			return(fib(n - 1) + fib(n - 2));
	}

	/*ДОМАШНЕЕ ЗАДАНИЕ от 29.11.2022*/
	//Транспонирование
	void Zadacha82d_transp(float* X[], int MaxN)
	{
		int r = MaxN, c = MaxN;
		float tmp;
		for (r = 0; r < MaxN; r++)
			for (c = r; c < MaxN; c++)
			{
				tmp = X[r][c];
				X[r][c] = X[c][r];
				X[c][r] = tmp;
			}
	}
	void Zadacha82d_transp2(float* X[], int MaxN, int N)
	{
		int r, c;
		float tmp;
		for (c = 0; c < MaxN; c++)
		{
			tmp = X[N][c];
			X[N][c] = X[c][N];
			X[c][N] = tmp;
		}
	}
	void Zadacha82d()
	{
		int N, MaxN, r, c;
		cout << "Введите кол-во строк и столбцов N, " << endl;
		cin >> N;
		MaxN = N;
		float** arr = new (nothrow) float* [N];
		if (!arr)
		{
			delete[] arr;
			return;
		}
		srand((unsigned)time(NULL));
		for (r = 0; r < N; r++)
		{
			arr[r] = new (nothrow) float[MaxN];
			if (!arr[r])
			{
				delete[] arr;
				return;
			}
			for (c = 0; c < MaxN; c++)
			{
				arr[r][c] = rand() % 10;
			}
		}

		cout << "Дан массив: " << endl;
		for (r = 0; r < N; r++)
		{
			for (c = 0; c < MaxN; c++)
			{
				cout << arr[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
		Zadacha82d_transp(arr, MaxN);
		cout << "Массив после транспонирования: " << endl;
		for (r = 0; r < N; r++)
		{
			for (c = 0; c < MaxN; c++)
			{
				cout << arr[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	//Наибольшее сверху
	int Zadacha82d_sum(int* X[], int MaxN)
	{
		int r = MaxN, c = MaxN;
		int MAX;
		MAX = X[1][2];
		for (r = 0; r < MaxN; r++)
			for (c = r + 1; c < MaxN; c++)
			{
				if (MaxN < X[r][c])
					MaxN = X[r][c];
			}
		return MAX;
	}
	void Zadacha83d()
	{
		int N, MaxN, r, c, MAX;
		cout << "Введите кол-во строк и столбцов N, " << endl;
		cin >> N;
		MaxN = N;
		int** arr = new (nothrow) int* [N];
		if (!arr)
		{
			delete[] arr;
			return;
		}
		srand((unsigned)time(NULL));
		for (r = 0; r < N; r++)
		{
			arr[r] = new (nothrow) int[MaxN];
			if (!arr[r])
			{
				delete[] arr;
				return;
			}
			for (c = 0; c < MaxN; c++)
			{
				arr[r][c] = rand() % 10;
			}
		}

		cout << "Дан массив: " << endl;
		for (r = 0; r < N; r++)
		{
			for (c = 0; c < MaxN; c++)
			{
				cout << arr[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
		MAX = Zadacha82d_sum(arr, MaxN);
		cout << "Массив после транспонирования: " << endl;
		for (r = 0; r < N; r++)
		{
			for (c = 0; c < MaxN; c++)
			{
				cout << arr[r][c] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	//Часть строки
	char* Zadacha84d_func(char* str, int pos, int kol)
	{
		int l = strlen(str), j = 0;
		char* s1 = new char[kol + 1];
		for (int i = pos - 1; i < l && i < (pos + kol - 1); j++, i++)
			s1[j] = str[i];
		s1[j] = '\0';
		delete[] str;
		return s1;
	}
	void Zadacha84d()
	{
		char* str = new char[100];
		int pos, kol;
		cout << "Введите строку" << endl;
		cin.getline(str, 20);
		cout << "Введите позицию и кол-во символов" << endl;
		cin >> pos >> kol;
		str = Zadacha84d_func(str, pos, kol);
		cout << "Вернувшаяся строка" << endl << str;
		delete[] str;
	}
	//Удаление части строки
	char* Zadacha85d_del(char* s, int kol, int pos)
	{
		char* s1 = new char[strlen(s) - kol + 1];
		int i;
		for (i = 0; i < pos; i++)
			s1[i] = s[i];
		for (int j = pos + kol; j != '\0'; i++, j++)
		{
			s1[i] = s[j];
		}
		s1[i] = '\0';
		delete[] s;
		return s1;
	}
	char* Zadacha85d_del2(char* s, int kol, int pos)
	{
		char* s1 = new char[strlen(s) - kol + 1];
		int i;
		for (i = 0; i < pos; i++)
			s1[i] = s[i];
		for (i = pos + kol; (s[i - kol] = s[i]) != '\0'; i++);
		delete[] s;
		return s1;
	}
	void Zadacha85d()
	{
		char* S = new char[100];
		int kol, pos;
		cout << "Введите строку: " << endl;
		cin.getline(S, 100);
		cout << "Введите кол-во символов для удаления: " << endl;
		cin >> kol;
		cout << "Введите позицию начала удаления: " << endl;
		cin >> pos;
		S = Zadacha85d_del2(S, kol, pos);
		cout << "Конечная строка" << S;
		delete[] S;
	}
	//Рекурсия														//не все варианты
	void Zadacha86d()
	{
		int n;
		cout << "Введите число n" << endl;
		cin >> n;
		cout << "Значение Fn числа Фибоначчи" << fib(n);

	}
	//Распределение													//не все варианты
	int** Zadacha87d_funk_v1(int arr[], int& n, int& size1, int& size2)
	{
		int i;
		int* a1 = new int[n];
		int* a2 = new int[n];
		int** u = new int* [2];
		size1 = 0;
		size2 = 0;
		for (i = 0; i < n; i++)
			if (arr[i] >= 0)
				a1[size1++] = arr[i];
			else
				a2[size2++] = arr[i];
		u[0] = a1;
		u[1] = a2;
		return u;
	}
	void Zadacha87d()
	{
		int arr[100] = { 0 }, n = 0, size1, size2;
		int** a;

		cout << "Введите элементы массива" << endl;
		while (!cin.eof())
			cin >> arr[n++];
		n--;
		a = Zadacha87d_funk_v1(arr, n, size1, size2);
		cout << "Массив положительных чисел" << endl;
		IntArrPrint(a[0], size1);
		cout << "Массив отрицательных чисел" << endl;
		IntArrPrint(a[1], size2);
		delete[] a[0];
		delete[] a[1];
		delete[] a;

	}
	//Длительность разговоров(телефоны)
	/*см.в Header //struct Zadacha88d_Trec { int phone; float dt; };*/
	Zadacha88d_Trec* Zadacha88dDlit(Zadacha88d_Trec* arr, int& n)
	{
		int i, j, l = n;
		for (i = 0; i < n; i++)
		{
			for (j = i + 1; j < n; j++)
				if (arr[i].phone == arr[j].phone && arr[j].dt != -1)
				{
					arr[i].dt += arr[j].dt;
					arr[j].dt = -1;
					l--;
				}
		}

		Zadacha88d_Trec* tmp = new Zadacha88d_Trec[l];
		for (i = 0, l = 0; i < n; i++)
			if (arr[i].dt != -1)
			{
				tmp[l].phone = arr[i].phone;
				tmp[l].dt = arr[i].dt;
				l++;
			}

		delete[] arr;
		arr = tmp;
		tmp = nullptr;
		n = l;
		return arr;
	}
	void Zadacha88d()
	{
		int i, n = 0;
		Zadacha88d_Trec* arr = new Zadacha88d_Trec[100];
		cout << "Введите через пробел номер телефона и длительность раз" << endl;
		while (!cin.eof())
			cin >> arr[n].phone >> arr[n].dt, n++;
		n--;

		cout << endl << "Структура без повторений" << endl;
		arr = Zadacha88dDlit(arr, n);
		for (i = 0; i < n; i++)
			cout << arr[i].phone << "\t" << arr[i].dt << endl;

		delete[] arr;
	}
	//Палиндром-рекурсия
	bool Zadacha89d_func(char str[], int s, int e)
	{
		if (str[s] != str[e] && str[e] != ' ' && str[s] != ' ')
			return false;
		if (s >= e)
			return true;
		if (str[s] == ' ')
			return Zadacha89d_func(str, s + 1, e);
		if (str[e] == ' ')
			return Zadacha89d_func(str, s, e - 1);
		if (str[s] == str[e])
			return Zadacha89d_func(str, s + 1, e - 1);
	}
	void Zadacha89d()
	{
		char str[] = "А РОЗА УПАЛА НА ЛАПУ АЗОРА";
		int l = strlen(str);
		cout << (Zadacha89d_func(str, 0, l - 1) ? "Да это палиндром" : "Нет не палиндром");
	}
	//Синтез*
	int* convert10to3(int a, int* arr)
	{
		int n = 0, j = 0, i;
		int* b = new int[8];
		while (a > 0)
		{
			arr[n++] = a % 3;
			a /= 3;
		}
		for (int i = 7; i >= 0; i--, j++)
		{
			if (i > n)
				b[j] = 0;
			else
				b[j] = arr[i];
		}
		delete[] arr;
		arr = b;
		b = nullptr;
		return arr;
	}
	int Zadacha90d_calc(int* a)
	{
		int res = 1, tmp, j;
		for (int i = 0; i < 8; i++)
		{
			if (a[i] == 0)
				res = int_join(res, i + 2);
			else if (a[i + 1] != 0)
				if (a[i] == 1)
					res += i + 2;
				else
					res -= i + 2;
			else
			{
				tmp = i + 2;
				j = i;
				while (a[i + 1] != 0 && i < 8);
				{
					tmp = int_join(tmp, i + 3);
					i++;
				}
				if (a[j] == 1)
					res += tmp;
				else
					res -= tmp;
			}
		}
		return res;
	}
	void Zadacha90d_print_result(int* a)
	{
		cout << "M = ";
		for (int i = 0; i < 9; i++)
		{
			cout << i + 1;
			if (a[i] == 1)
				cout << "+";
			else if (a[i] == 2)
				cout << "-";
		}
		cout << endl;
	}
	void Zadacha90d()
	{
		int M, i; // num[9] = { 1,2,3,4,5,6,7,8,9 };
		int* a = new int[8];
		cout << "Введите целое число М для синтеза" << endl;
		cin >> M;
		for (i = 0; i <= 6560; i++)
		{
			a = convert10to3(i, a);
			if (Zadacha90d_calc(a) == M)
				Zadacha90d_print_result(a);
		}

		delete[] a;
	}
	//Путь*
	int Zadacha91Track(char** a, int& rows, int& columns, int& sr, int& sc, int step = -1)
	{
		int route = -1;
		char r, l, u, d;
		a[sr][sc] = '*';
		step++;
		if (step > 1000)
		{
			cout << "Слишком много шагов :(";
			return 1;
		}
		if (sc + 1 < columns)	r = a[sr][sc + 1];	else r = 'e';
		if (sc - 1 >= 0)		l = a[sr][sc - 1];	else l = 'e';
		if (sr + 1 < rows)		d = a[sr + 1][sc];	else d = 'e';
		if (sr - 1 >= 0)		u = a[sr - 1][sc];	else u = 'e';
		if ((r == 'e' || l == 'e' || d == 'e' || u == 'e') && step)
		{
			for (int i = 0; i < rows; i++)
				for (int j = 0; j < columns; j++)
					if (a[i][j] == 'x') a[i][j] = ' ';
			return 0;
		}
		else if (r == ' ') sc += 1;
		else if (l == ' ') sc -= 1;
		else if (d == ' ') sr += 1;
		else if (u == ' ') sr -= 1;
		else
		{
			a[sr][sc] = 'x';
			if (r == '*') sc += 1;
			else if (l == '*') sc -= 1;
			else if (d == '*') sr += 1;
			else if (u == '*') sr -= 1;
			else
				return 2;
		}
		return Zadacha91Track(a, rows, columns, sr, sc, step);
	}
	void Zadacha91d()
	{
		int i, j, s = 10;
		int sr = 0, sc = 1;
		char** arr = new char* [s];
		for (i = 0; i < 10; i++)
			arr[i] = new char[s];
		char arrconst[10][10] = { {'#',' ','#','#','#','#','#','#','#','#'},
								 {'#',' ',' ','#',' ',' ',' ',' ',' ','#'},
								 {'#',' ','#','#',' ','#','#','#',' ','#'},
								 {'#',' ',' ',' ',' ',' ',' ','#',' ','#'},
								 {'#','#','#','#','#','#','#','#',' ','#'},
								 {'#',' ',' ',' ',' ',' ',' ',' ',' ','#'},
								 {'#','#',' ','#','#','#','#','#','#','#'},
								 {'#',' ',' ',' ','#',' ',' ',' ','#','#'},
								 {'#','#','#',' ',' ',' ','#',' ',' ','#'},
								 {'#','#','#','#','#','#','#','#',' ','#'} };
		for (i = 0; i < 10; i++)
			for (j = 0; j < 10; j++)
				arr[i][j] = arrconst[i][j];

		if (!Zadacha91Track(arr, s, s, sr, sc))
		{
			cout << "Пройденый лабиринт" << endl;
			CharArr2DinamicPrint(arr, s, s, ' ');
		}
		else
			cout << "Лабиринт не проходим :-(";

		for (i = 0; i < s; i++)
			delete[] arr[i];
		delete[] arr;
	}

	/*ПРАКТИКА 06.12.2022*/
//Поиск пересечения произвольной функции оси координат Х
	double binSearch(double a, double b, double eps, double (*f)(double))
	{
		double sr = (a + b) / 2;
		if (f(sr) == 0 || (b - a) <= eps)
			return sr;
		if (f(a) * f(sr) < 0)  // сравнение двух чисел на разные знаки, если знаки разные то будет меньше нуля.
			return binSearch(a, sr, eps, f);
		else
			return binSearch(sr, b, eps, f);
	}
	double Zadacha46_f(double x)
	{
		return sin(x); // страшное выражение
	}
	void Zadacha46()
	{
		double a = 1, b = 4, eps = 0.0001;
		double res = binSearch(a, b, eps, Zadacha46_f);
		cout << res;
	}
	//Найти наибольшую цифру в натуральном числе рекурсией
	int Zadacha47_f(int n)
	{
		if (n <= 9)
			return n;
		return n % 10 > Zadacha47_f(n / 10) ? (n % 10) : Zadacha47_f(n / 10);
	}
	void Zadacha47()
	{
		int n;
		cout << "Введите число n: ";
		cin >> n;
		cout << "Максимальная цифра равна: " << Zadacha47_f(n);
	}
	//С клавиатуры  вводится динамическая матрица n*m, удалить из нее все строки содержащие отрицательные элементы.
	int** Zadacha48_funk(int** M, int* n, int m)   //n - кол-во строк m - кол-во столбцов
	{
		int j = 0;
		for (int i = 0; i < *n; i++)
		{
			bool f = true;
			for (int k = 0; k < m; k++)
				if (M[i][k] < 0)
				{
					f = false;
					break;
				}
			if (!f)
				delete[] M[i];
			else
				M[j++] = M[i];
		}
		*n = j;

		int** tmp = new int* [*n];
		for (int i = 0; i < *n; i++)
			tmp[i] = M[i];
		delete[] M;
		return tmp;
	}
	void Zadacha48()
	{
		int** M;
		int n, m, i, j;
		cout << "Введите кол-во строк и столбцов" << endl;
		cin >> n >> m;

		M = new int* [n];
		for (i = 0; i < n; i++)
			M[i] = new int[m];
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> M[i][j];
		M = Zadacha48_funk(M, &n, m);
		cout << "Результирующая матрица" << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
				cout << M[i][j] << '\t';
			cout << endl;
		}
		for (i = 0; i < n; i++)
			delete[] M[i];
		delete[] M;
	}

	/*ПРАКТИКА 13.12.2022*/
//Привести строку к правильному виду заменив все множественные пробелы одним и привести к окончательному виду
	void Zadacha49()

	{
		char s[100];
		cout << "Введите строку" << endl;
		cin.getline(s, 100);
		while (strstr(s, "  "))
		{
			strcpy(strstr(s, "  "), strstr(s, "  ") + 1);//куда копируем и откуда.
		}
		if (s[0] == ' ') strcpy(s, s + 1);
		if (s[strlen(s)] == ' ') s[strlen(s)] = '\0';
		cout << s;
	}
	void Zadacha49_string()
	{
		string s;
		cout << "Введите строку содержащую двойные пробелы" << endl;
		getline(cin, s);// s = " " + s + " " (можно написать так и удалит пробелы в начале и конце)
		while (s.find("  ") != string::npos)
			s.erase(s.find("  "), 1);
		string::size_type p = s.find("  ");
		while (p != string::npos)
		{
			s.erase(p, 1);
			p = s.find("  ");
		}
		if (s[0] == ' ')
			s.erase(0, 1);
		if (s[s.length() - 1] == ' ')
			s.erase(s.length() - 1, 1);
		cout << s;
	}
	//Дана строка с правильным видом, распечатать по слову.
	void Zadacha50()
	{
		char s[100];
		cout << "Введите строку: " << endl;
		cin.getline(s, 100);
		char* p = strchr(s, ' ');
		cout << endl;
		while (p)
		{
			for (int i = 0; s[i] != ' '; i++)
			{
				cout << s[i];
			}
			strcpy(s, p + 1);
			p = strchr(s, ' ');
			cout << endl;
		}
		cout << s;
		cout << endl;
	}
	void Zadacha50_string()
	{
		string s;
		cout << "Введите строку: " << endl;
		getline(cin, s);
		int b = 0;//начало текущего слова
		string::size_type p = s.find(" ");
		while (p != string::npos)
		{
			cout << s.substr(b, p - b) << endl;
			b = p + 1;
			p = s.find(" ", b);
		}
		cout << s.substr(b, s.length() - b);
	}
	void Zadacha50_rasiasnenia()
	{
		char s[100];
		char Raz[] = " ,.-\t\n";//массив разделителей
		char* word = NULL;
		char* next_word = NULL;
		cin.getline(s, 100);
		cout << "Слова: " << endl;
		word = strtok_s(s, Raz, &next_word);//строка где ищем, символы до какого ищем. _S-безопасный
		while (word != NULL)
		{
			cout << word << endl;//delete[] word;
			word = strtok_s(NULL, Raz, &next_word);
		}
	}
	//Удалить в строке все слова помечанные символом #.
	void Zadacha51()
	{
		string Raz(" ., :;-()[]|!?");
		string str;
		getline(cin, str);
		str += Raz[0];
		vector<string>w;
		while (1)
		{
			string::size_type p1, p0 = str.find("#");
			if (p0 == string::npos) break;
			p1 = p0;
			while (Raz.find(str[p1]) == string::npos)
			{
				p1++;
			}
			w.push_back(str.substr(p0, p1 - p0));
			str.erase(p0, p1 - p0);
		}
		cout << "Найдено и удалено " << endl;
		for (int i = 0; i < w.size(); i++)
		{
			cout << w[i] << endl;
		}
		cout << "Изменённая строка " << endl;
		cout << str;
	}
	//Дана строка, где слова отделены пробелом, удалить слова введённые с клавиатуры.
	void Zadacha52()
	{
		string s, word;
		cout << "Введите строку: \0" << endl;
		getline(cin, s);
		cout << "Введите слово: \0" << endl;
		getline(cin, word);
		s = " " + s + " ";
		word = " " + word + " ";
		string::size_type p = s.find(word);
		while (p != string::npos)
		{
			s.erase(p, word.length() - 1);
			p = s.find(word);
		}
		s.erase(0, 1);
		s.erase(s.length() - 1);
		cout << "Изменённая строка: \0" << endl;
		cout << s;
	}
	//Старая задачка! Функция проверяет равно ли кол-во четных чисел не четным из введенных 6 чисел
	void Zadacha53()
	{
		int a, b, c, d, f, g;
		cout << "Введите шесть чисел" << endl;
		cin >> a >> b >> c >> d >> f >> g;
		if (((a & 1) + (b & 1) + (c & 1) + (d & 1) + (f & 1) + (g & 1)) == 3)
		{
			cout << "Совпадает" << endl;
		}
		else
		{
			cout << "Не совпадает" << endl;
		}
	}

	/*ДОМАШНЕЕ ЗАДАНИЕ от 13.12.2022*/
//СРАВНЕНИЕ СТРОК
	void Zadacha92d()
	{
		string s1, s2;
		cout << "Введите первую строку: " << endl;
		cin >> s1;
		cout << "Введите вторую строку: " << endl;
		cin >> s2;

		cout << "Длиннее строка" << endl << (s1.length() > s2.length() ? s1 : s2) << endl;
		cout << "Порядок по алфавиту: " << endl << (s1 < s2 ? s1 : s2) << endl << (s1 > s2 ? s1 : s2);
	}
	//УДАЛЕНИЕ СИМВОЛА
	void Zadacha93d()
	{
		char s1[100];
		char _s;
		char* sy = NULL;
		char* next_word = NULL;
		string s2;
		string::size_type p;

		cout << "Введите строку в S1: " << endl;
		cin.getline(s1, 99);

		cout << "Введите строку в S2: " << endl;
		getline(cin, s2);

		cout << "Введите символ для удаления" << endl;
		cin >> _s;

		//Для char
		sy = strchr(s1, _s);//строка где ищем, символы до какого ищем. _S-безопасный
		while (sy != NULL)
		{
			while (*sy != '\0')
			{
				*sy = *(sy + 1);
				sy++;
			}
			sy = strchr(s1, _s);
		}
		cout << "Строка Char с удаленными элементами" << endl << s1 << endl;

		//Для string
		p = s2.find(_s);
		while (p != string::npos)
		{
			s2.erase(p, 1);
			p = s2.find(_s);
		}
		cout << "Строка Char с удаленными элементами" << endl << s2 << endl;
	}
	//ПРОСТОЙ ПАЛИНДРОМ
	void Zadacha94d()
	{
		int i;
		char s1[100]; char _s1[100];
		string s2, _s2;
		cout << "Введите строку" << endl;
		cin.getline(s1, 99);

		s2 = s1;

		//Для char
		strcpy(_s1, s1);
		revers_char_arr(_s1);
		if (!strcmp(s1, _s1))
			cout << "Вариант Char. Строка является полиндромом" << endl;
		else
			cout << "Вариант Char. Строка НЕ является полиндромом" << endl;

		//Для string
		_s2 = s2;
		reverse(_s2.begin(), _s2.end());
		if (s2 == _s2)
			cout << "Вариант String. Строка является полиндромом" << endl;
		else
			cout << "Вариант String. Строка НЕ является полиндромом" << endl;
	}
	//ПОИСК СТРОКИ В МАССИВЕ
	void Zadacha95d_func(char arr[][20], int size, char raz[])
	{
		int i;
		char* p = nullptr;
		for (i = 0; i < size; i++)
		{
			p = strpbrk(arr[i], raz);
			if (p != NULL)
				if (p == &arr[i][0])
					cout << "Найден символ " << *p << " встречается в начале строки" << "\t" << arr[i] << endl;
				else if (p == &arr[i][strlen(arr[i]) - 1])
					cout << "Найден символ " << *p << " встречается в конце строки" << "\t" << arr[i] << endl;
				else
					cout << "Символ " << *p << " встречается в середине строки" << "\t" << arr[i] << endl;
		}
		p = nullptr;
	}
	void Zadacha95d()
	{
		char arr[5][20] = { "#Строка1", "Строка, 2", "Стро-ка3", "Строка4 :", "#Строка 5;" };
		char raz[50];
		int size = 5;
		cout << "Введите строку со знаками" << endl;
		cin.getline(raz, 50);
		Zadacha95d_func(arr, size, raz);

	}
	//ФУНКЦИЯ СЛИЯНИЯ
	char* strcatnewmy(char* s1, char* s2)
	{
		int n = 0;
		char* c, * i;
		c = &s1[0];
		while (*c != '\0')
			n++, c++;
		c = &s2[0];
		while (*(c - 1) != '\0')
			n++, c++;
		char* s = new char[n];
		c = &s[0]; i = &s1[0];
		while (*i != '\0')
		{
			*c = *i;
			c++; i++;
		}
		i = &s2[0];
		while (*(i - 1) != '\0')
		{
			*c = *i;
			c++; i++;
		}
		c = nullptr, i = nullptr;
		return s;
	}
	void Zadacha96d()
	{
		char s1[100], s2[100];
		char* s;

		cout << "Введите первую строку" << endl;
		cin.getline(s1, 99);
		cout << "Введите вторую строку" << endl;
		cin.getline(s2, 99);
		s = strcatnewmy(s1, s2);
		cout << "Суммарная строка: " << endl << s;

		delete[] s;
	}
	//СКЛЕЙКА СЛОВ
	void Zadacha97d()
	{
		char instr[20];
		char* sum = nullptr;
		cout << "Введите строку для слияния" << endl;
		cin.getline(instr, 20);
		while (!cin.eof())
		{
			if (!sum)
			{
				sum = new char[20];
				strcpy(sum, instr);
			}
			else
			{
				strcat(sum, instr);
			}
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin.getline(instr, 20);
		}
		cout << "Сумма строк: " << sum;
		delete[] sum;
	}
	//КОПИРОВАНИЕ ДО ПОМЕТКИ
	void Zadacha98d_funk(vector<string*>& w, string str)
	{
		string::size_type p;
		string* tmp = new string;
		p = str.find("#");
		if (p != string::npos)
		{
			*tmp = str.substr(0, p);
			if ((*tmp).length())
				w.push_back(tmp);
			else
				delete tmp;
		}
		else
		{
			*tmp = str;
			w.push_back(tmp);
		}
	}
	void Zadacha98d()
	{
		vector<string*>w;
		string str;

		cout << "Введите строку для добавления в вектор, # это граница копирования" << endl;
		getline(cin, str);
		while (!cin.eof())
		{
			Zadacha98d_funk(w, str);
			//cin.ignore(std::cin.rdbuf()->in_avail());
			getline(cin, str);
		}

		cout << endl << "Строки сохраненные в векторе" << endl;
		for (int i = 0; i < w.size(); i++)
		{
			cout << *(w.at(i)) << endl;
			delete w.at(i);
		}
	}
	//РАЗДЕЛЕНИЕ
	//struct Zadacha99d_dec { char* w; char* t; };
	void Zadacha99d()
	{
		int N, i = 0;
		char* str = nullptr;
		cout << "Введите кол-во строк N" << endl;
		cin >> N;
		Zadacha99d_dec* arr = new Zadacha99d_dec[N];

		cout << "Введите пары слов через дефис" << endl;
		while (i < N)
		{
			str = new char[100];
			cin.getline(str, 100);
			if (strchr(str, '-'))
			{
				arr[i].w = strtok(str, "-");
				arr[i++].t = strtok(NULL, "-");
			}
			else
			{
				delete[] str;
				str = nullptr;
			}
			cin.ignore(std::cin.rdbuf()->in_avail());
		}

		cout << "Записаны следующие пары:" << endl;
		for (i = 0; i < N; i++)
		{
			cout << "Слово: " << arr[i].w << "\t Перевод: " << arr[i].t << endl;
			delete[] arr[i].w;
		}
		delete[] arr;
	}
	//ПОИСК СЛОВА
	string SearchStrInStr(string& source_str, string& find, string raz = " .,-+*{}[]:;&^%$#@!~")
	{
		char* found = strtok(&source_str[0], &raz[0]);
		while (found != NULL)
		{
			if (!strcmp(&find[0], found))
				return string(found);
			found = strtok(NULL, &raz[0]);
		}
		return "";
	}
	void Zadacha100d()
	{
		string source_str;
		string find;
		string answer;
		cout << "Введите строку в которой будет осуществляться поиск" << endl;
		getline(cin, source_str);
		cout << "Введите слово для поиска" << endl;
		getline(cin, find);
		answer = SearchStrInStr(source_str, find);

		if (!answer.empty())
			cout << "Cлово найдено :)";
		else
			cout << "Cлово не найдено :(";
	}
	//ПОМЕТКИ
	void Zadacha101d()
	{
		Zadacha51();
	}
	//ПРОСТАЯ АРИФМЕТИКА
	void Zadacha102d()
	{
		string s, num1, num2, sum_num, tmp;
		int sum, i1, i2, raz = 0;
		char c;
		sum_num = "";
		cout << "Введите строку, содержащую операцию сложения двух целых чисел" << endl;
		getline(cin, s);
		int pluse = s.find("+");
		num1 = s.substr(0, pluse);
		num2 = s.substr(pluse + 1, s.length() - pluse - 1);
		if (num1.length() < num2.length())
		{
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		i1 = num1.length() - 1;
		i2 = num2.length() - 1;
		for (; i2 >= 0; i1--, i2--)
		{
			sum = num1[i1] - '0' + num2[i2] - '0' + raz;
			raz = sum / 10;
			c = sum % 10 + '0';
			sum_num = c + sum_num;
		}
		for (; i1 >= 0; i1--)
		{
			sum = num1[i1] - '0' + raz;
			raz = sum / 10;
			c = sum % 10 + '0';
			sum_num = c + sum_num;
		}
		if (raz)
		{
			c = raz + '0';
			sum_num = c + sum_num;
		}
		cout << "=" << sum_num << endl;

		//Терминальные строки cstring.h, cstring. Объект string <string>
	}
	//РАЗДЕЛЕНИЕ СПИСКА ФАМИЛИЙ
	void Zadacha103d()
	{
		int N;
		string family;
		vector<char*> family1;
		vector<string> family2;

		//Вводим исходные данные
		cout << "Введите число фамилий N: " << endl;
		cin >> N;
		cout << "Введите фамилии" << endl;
		cin.get();
		while (N-- > 0)
		{
			getline(cin, family);
			family1.push_back(strdup(&family[0]));
			family2.push_back(strdup(&family[0]));
		}


		//Сортировка
		sort(family1.begin(), family1.end(), [](const char* s1, const char* s2) {return strcmp(s1, s2) <= 0; });
		sort(family2.begin(), family2.end(), [](const string s1, const string s2) {return strcmp(&s1[0], &s2[0]) <= 0; });

		//Вывод
		cout << endl << "Получился следующий список char*:" << endl;
		for (unsigned int i = 0; i < family1.size(); i++)
			cout << family1[i] << endl;
		cout << endl << "Получился следующий список string:" << endl;
		for (unsigned int i = 0; i < family2.size(); i++)
			cout << family2[i] << endl;

		//Очистка вектора char*;
		for_each(family1.begin(), family1.end(), [](char* s) {delete[] s; });
	}
	//РАЗБОР АРИФМЕТИЧЕСКОГО ВЫРАЖЕНИЯ
	string funcPLUS(string num1, string num2)
	{
		string sum_num, tmp;
		int sum, i1, i2, raz = 0;
		char c;

		if (num1.length() < num2.length())
		{
			tmp = num1;
			num1 = num2;
			num2 = tmp;
		}
		i1 = num1.length() - 1;
		i2 = num2.length() - 1;
		for (; i1 >= 0; i1--, i2--)
		{
			if (i2 >= 0)
				sum = num1[i1] - '0' + num2[i2] - '0' + raz;
			else
				sum = num1[i1] - '0' + raz;
			raz = sum / 10;
			c = sum % 10 + '0';
			sum_num = c + sum_num;
		}
		if (raz)
		{
			c = raz + '0';
			sum_num = c + sum_num;
		}
		return sum_num;
	}
	string funcMINUS(string num1, string num2)
	{
		string sum_num, tmp;
		int sum, i1, i2, raz = 0, z = 0;
		char c;

		if (num1.compare(num2) < 0 && num1.length() <= num2.length() || num1.length() < num2.length())
		{
			tmp = num1;
			num1 = num2;
			num2 = tmp;
			z = 1;
		}
		i1 = num1.length() - 1;
		i2 = num2.length() - 1;
		for (; i1 >= 0; i1--, i2--)
		{
			if (i2 >= 0)
				sum = num1[i1] - '0' - num2[i2] + '0' - raz;
			else
				sum = num1[i1] - '0' - raz;
			if (sum < 0)
			{
				sum += 10; raz = 1;
			}
			else
				raz = 0;
			c = sum + '0';
			sum_num = c + sum_num;
		}
		while (sum_num[0] == '0' && sum_num.length() != 1)
			sum_num.erase(0, 1);
		if (z)
		{
			sum_num = '-' + sum_num;
		}
		return sum_num;
	}
	void Zadacha104d()
	{
		string s, num, sum_num, tmp;
		int sum, i1, i2, raz = 0;
		char c;
		char seps[] = "+-";
		char znak;
		int token;
		sum_num = "";
		cout << "Введите строку без скобок содержашую выражение со знаками + и - " << endl;
		getline(cin, s);
		//Получаем первое число для действия
		token = strcspn(&s[0], seps);
		if (token != -1)
		{
			s[token] == '+' ? znak = '+' : znak = '-';
			sum_num.assign(&s[0], token);
			s.assign(&s[0], token + 1, s.length() - token - 1);
		}
		else
		{
			cout << "	Нет операторов + и - " << endl;
			return;
		}

		//Ищем следующую операцию
		token = strcspn(&s[0], seps);
		while (1)
		{
			//Получаем число(в виде строки) для действия
			if (token != s.length())
				num.assign(&s[0], token);
			else
				num = s;
			//Расчет с выбором варианта в зависимости от знаков + и -
			if (znak == '+' && sum_num[0] != '-')
				sum_num = funcPLUS(sum_num, num);
			else if (znak == '+' && sum_num[0] == '-')
				sum_num = funcMINUS(num, sum_num.erase(0, 1));
			else if (znak == '-' && sum_num[0] != '-')
				sum_num = funcMINUS(sum_num, num);
			else
				sum_num = '-' + funcPLUS(num.erase(0, 1), sum_num.erase(0, 1));
			//Выходим из цикла если оператор не найден
			if (token == s.length())
				break;
			s[token] == '+' ? znak = '+' : znak = '-';
			s.assign(&s[0], token + 1, s.length() - token - 1);
			//Ищем вхождение следующего оператора + или -
			token = strcspn(&s[0], seps);
		}
		cout << "Ответ равен: " << endl << sum_num << endl;
	}

	/*ПРАКТИКА 20.12.2022*/
//Сортировка строк
	using Tcstrings_vect = vector<char*>;
	using Tchar_vect = vector<char>;
	bool words_cmp1(char* s1, char* s2)
	{
		return strcmp(s1, s2) <= 0;
	}  // s1<=s2
	bool words_cmp2(char* s1, char* s2)
	{
		return strcmp(s1, s2) >= 0;
	}
	int StrToWords(char* str, char* Raz, Tcstrings_vect& word)
	{
		static Tchar_vect w; //вектор для текущего слова
		int wcount = 0;
		unsigned int l = strlen(str);
		str[l++] = Raz[0];
		str[l] = '\0';
		for (unsigned int i = 0; i < l; i++)
		{
			if (!strchr(Raz, str[i]))
				w.push_back(str[i]);
			else if (!w.size())
				continue;
			else
			{
				w.push_back('\0');
				wcount++;
				word.push_back(_strdup(&w[0]));
				w.clear();
			}
		}
		return wcount;
	}
	void Zadacha54()
	{
		char Razd[] = " .,:;-()[]{}<>!?";
		char buff[1000];
		int wcount;
		Tcstrings_vect words;
		cout << "Введите строки текста через Enter и пустую строку для завершения" << endl;
		while (1)
		{
			cout << "Строка:" << endl;
			cin.getline(buff, 1000);
			if (!strlen(buff))
				break;
			wcount = StrToWords(buff, Razd, words);
			cout << "Выделено" << wcount << "слов" << endl;
		}

		int sort_type;
		cout << "Введите в каком направлении сортируем: 1(возр.),-1(убыв.)" << endl;
		cin >> sort_type;
		if (sort_type == 1)
			sort(words.begin(), words.end(), words_cmp1);
		else
			sort(words.begin(), words.end(), words_cmp2);

		//Сортировка через лямбда выражение
		sort(words.begin(), words.end(), [sort_type](const char* s1, const char* s2) {return sort_type * strcmp(s1, s2) <= 0; });

		//Вывод
		cout << "После сортировки: " << endl;
		for (unsigned int i = 0; i < words.size(); i++)
			cout << words[i];

		//Вывод через лямбда выражение
		for_each(words.begin(), words.end(), [](char* s) {cout << s << endl; });

		//Очистка вектора
		for_each(words.begin(), words.end(), [](char* s) {delete[] s; });
	}

	/*ПРАКТИКА 27.12.2022* Работа с файлами*/
//Считаем счета за электричество, воду, газ. Сумма за год. Максимальную трату
	void Zadacha55(int argc, char* argv[])
	{
		int e, v, g, sum_e = 0, sum_v = 0, sum_g = 0, i, max_sum = 0, max_month;
		//setlocale(LC_ALL, "rus");
		ifstream fin;
		ofstream fout;
		char name[20];

		if (argc < 3)
		{
			cout << "Нет данных о файлах" << endl;
			return;
		}

		fin.open(argv[1]);
		if (!fin)
		{
			cout << "Файл " << argv[1] << " не найден" << endl;
			return;
			//exit(0);
		}

		//cout << "Введите имя входного файла" << endl;
		//cin >> name;
		//do
		//{
		//	cout << "Введите имя исходного файла" << endl;
		//	cin >> name;
		//	fin.open(name);
		//	if (!fin)
		//		cout << "Файл не найден, введите заново";
		//} while (!fin);



		//cout << "Введите имя выходного файла" << endl;
		//cin >> name;
		//fout.open(name);
		fout.open(argv[2]);
		for (i = 1; i <= 12; i++)
		{
			fin >> e >> v >> g;
			sum_e += e;
			sum_v += v;
			sum_g += g;
			//определяем месяц когда затраты были больше всего
			if (e + v + g > max_sum)
			{
				max_sum = e + v + g;
				max_month = i;
			}
		}
		cout << "Траты за год: " << endl <<
			"Электричество: " << "\t " << sum_e << endl <<
			"Вода: " << "\t " << sum_v << endl <<
			"Газ: " << "\t " << sum_g << endl <<
			"Суммарные затраты:" << sum_e + sum_v + sum_g << endl <<
			"Больше всего было потрачено: " << max_sum << ", в месяце " << max_month;
		fout << "Траты за год: " << endl <<
			"Электричество: " << "\t " << sum_e << endl <<
			"Вода: " << "\t " << sum_v << endl <<
			"Газ: " << "\t " << sum_g << endl <<
			"Суммарные затраты:" << sum_e + sum_v + sum_g << endl <<
			"Больше всего было потрачено: " << max_sum << ", в месяце " << max_month;
		fin.close();
		fout.close();
	}
	//Дан текстовый файл. рассчитать кол-во вхождений всех латинских символов в него
	void Zadacha56()
	{
		ifstream fin;
		ofstream fout;
		char s[20];
		char c;
		int arr[26] = { 0 };
		do
		{
			cout << "Введите имя входного файла" << endl;
			cin >> s;
			fin.open(s);
			if (!fin)
				cout << "Файл не найден, введите заново" << endl;
		} while (!fin);
		cout << "Введите имя выходного файла" << endl;
		cin >> s;
		fout.open(s);
		while (fin)
		{
			c = fin.get();
			if (c >= 'A' && c <= 'Z')
				arr[c - 'A']++;
			if (c >= 'a' && c <= 'z')
				arr[c - 'a']++;
		}
		fout << "Буква\t" << "Кол-во вхождений" << endl;
		for (int i = 0; i < 26; i++)
			fout << (char)('a' + i) << "\t" << arr[i] << endl;
		fin.close();
		fout.close();
	}
	//Перевести в файле все латинсткие буквы из маленьких в большие, а большие на маленькие БЕЗ лямбда
	void Zadacha57()
	{
		ifstream fin;
		ofstream fout;
		char sn[20];
		string s;
		do
		{
			cout << "Введите имя входного файла" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "Файл не найден, введите заново" << endl;
		} while (!fin);
		cout << "Введите имя выходного файла" << endl;
		cin >> sn;
		fout.open(sn);
		do
		{
			getline(fin, s);
			for (int i = 0; i < s.length(); i++)
				if (s[i] >= 'a' && s[i] <= 'z')
					s[i] = s[i] - 'a' + 'A';
				else if (s[i] >= 'A' && s[i] <= 'Z')
					s[i] = s[i] - 'A' + 'a';
			fout << s << endl;
		} while (!fin);
		fin.close();
		fout.close();
	}
	//Перевести в файле все латинсткие буквы из маленьких в большие, а большие на маленькие С лямбда
	void Zadacha58()
	{
		//С лямбдой
		ifstream fin;
		ofstream fout;
		char sn[100];
		char s[100];
		do
		{
			cout << "Введите имя входного файла" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "Файл не найден, введите заново" << endl;
		} while (!fin);
		cout << "Введите имя выходного файла" << endl;
		cin >> sn;
		fout.open(sn);
		do
		{
			fin.getline(s, 100);
			transform(s, s + strlen(s), s, [](char c)->char
				{
					if (c >= 'a' && c <= 'z')
						c = (c - 'a' + 'A');
					else if (c >= 'A' && c >= 'Z')
						c = (c - 'A' + 'a');
					else
						return c;
				}
			);
			fout << s << endl;
		} while (!fin);
		fin.close();
		fout.close();
	}
	//Перевести в файле все латинсткие буквы из маленьких в большие, а большие на маленькие С лямбда и string
	void Zadacha59()
	{
		//Без лямбда
		ifstream fin;
		ofstream fout;
		char sn[100];
		string s;
		do
		{
			cout << "Введите имя входного файла" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "Файл не найден, введите заново" << endl;
		} while (!fin);
		cout << "Введите имя выходного файла" << endl;
		cin >> sn;
		fout.open(sn);
		do
		{
			getline(fin, s);
			fin.get();
			transform(s.begin(), s.end(), s.begin(), [](char c)->char
				{
					if (c >= 'a' && c <= 'z')
						return (c - 'a' + 'A');
					else if (c >= 'A' && c >= 'Z')
						return (c - 'A' + 'a');
					else
						return c;
				}
			);
			fout << s << endl;
		} while (fin);
		fin.close();
		fout.close();
	}


	/*ПРАКТИКА 17.01.2023*/
//Функция с неопределенным кол-вом параметров, определяющая максимальное значение парамеров.
#define EOL -1    //Деректива означающая что EOL это -1
	void maxfinder(int* max, ...)
	{
		int maxval, num;
		va_list num_ptr;			//Указатель на параметры функции
		va_start(num_ptr, max);		//Установка параметра на первый мараметр
		maxval = EOL;				//-1
		while ((num = va_arg(num_ptr, int)) != EOL)
			if (num > maxval)
				maxval = num;
		va_end(num_ptr);
		*max = maxval;
	}
	void Zadacha60()
	{
		int max;
		maxfinder(&max, 3, 8, 15, 2, 13, EOL);
		cout << "Максимальное значение ровно = " << max << endl;
	}

#define TFUN(F) double (*F)(double)
#define TSHOW(F) void (*F)(double,double,double (*)(double)) //Функция для распечатки промежуточных значений в указаном диапазоне 
	//УКАЗАТЕЛИ НА ФУНКЦИЮ
		/*Поиск уравнение F(c) равное нулю на отрезке[a, b] с точностью эпсилан.TSHOW функция передаваяемая для печати проммежуточных
		значений в случае нахождения корней. Функция возвращает 1 при нахождении корня, 0 при его отсутствии.*/
	int Root(double a, double b, double eps, TFUN(F), double& C, TSHOW(Show));
	//int Root(double a, double b, double eps, double(*f)(double), double& C, void (*Show)(double,double,double (*)(double))); 
	void (*Show)(double, double, double(*)(double));
	void ShowStep(double a, double b, TFUN(f));
	void ShowEmpty(double a, double b, TFUN(f)) //Не обязательно большая F можно любое
	{

	}
	int Root(double a, double b, double eps, TFUN(F), double& C, TSHOW(Show))
	{
		if (F(a) * F(b) > 0)
			return 0; //нет корней
		Show(a, b, F);
		while ((b - a) > eps)
		{
			C = (a + b) / 2;
			if (F(a) * F(C) < 0)
				b = C;
			else
				a = C;
			Show(a, b, F);
		}
		C = (a + b) / 2;
		return 1;
	}
	void ShowStep(double a, double b, TFUN(f))
	{
		cout << "\nПроцесс поиска:\t"
			<< a << '\t' << b << 't' << f(a) << '\t' << '\t' << f(b);
	}
	double f1(double x)
	{
		return sin(x) - 0.5 * x;
	}
	double f2(double x)
	{
		return (x + 2) * (x - 2);
	}
	void Zadacha61()
	{
		double (*Arf[2])(double) = { f1,f2 };
		double x;
		//Первая функция
		if (Root(1.5, 3.1, 0.001, Arf[0], x, ShowStep))
			cout << endl << "Корень равен = " << x << endl;
		else
			cout << "Корень нет" << endl;
		//Вторая функция
		if (Root(1.5, 3.1, 0.001, Arf[1], x, ShowEmpty))
			cout << "Корень равен = " << x << endl;
		else
			cout << "Корень нет" << endl;
	}

	//Побитовые поля
	void Zadacha62()
	{
		unsigned int a = 15;	//1111
		unsigned int b = 17;	//10001
		unsigned int c = a & b; //=1       И - если хотя бы один 0 то 1 (0 или 1 дает 0, 1 и 1 дает 1)
		c = a | b;				//=11111   ИЛИ - если хотя бы одна 1 то 1 (0 или 1 дает 1)
		unsigned int n = 2;
		c = a << n;				//=111100  Сдвиг влево - сдвигаем влево, справа освободившиеся ячейки заполняются 0, то что вылетит за пределы пропадает.
		n = 3;
		c = a >> n;				//=1 Сдвиг вправо - аналогично сдвигу слева только в другую сторону
		c = a ^ b;				//=30 Исключающее ИЛИ - Если биты одинаковые ставится 0 если разное то еденичка.
		c = ~b;					//=4294967278 Инверсия - Просто меняет 1 на 0, а 0 на 1
		cout << c << endl;

		cout << a << '\t' << b << endl;
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		cout << a << '\t' << b << endl;

	}

	/*ДОМАШНЕЕ ЗАДАНИЕ 17.12.2023*/
	void Zadacha105d()
	{
		bool (*f)(void) = Z105d_VarSort;
		vector<Z105d_TDate>vd;
		unsigned short D[3];
		cout << "Введите дату(день месяц год) в формате 30 12 22, для отмены введите CTRL+Z и Enter" << endl;
		while (1)
		{
			fill(&D[0], &D[2],0);
			cin >> D[0] >> D[1] >> D[2];
			if (cin.eof()) break;
			if (D[0] + D[1] + D[2])
				vd.push_back({{D[0]},{D[1]},{D[2]}});
		}
		Z105d_SortDate(vd, f);
		cout << endl << "Отсортированный вектор структур: " << endl;
		for_each(vd.begin(), vd.end(), [](Z105d_TDate i) {
			cout << endl << '\t' << 
				(i.nMonthDay < 10 ? "0" : "")	<< i.nMonthDay << "." <<
				(i.nMonth < 10 ? "0" : "")		<< i.nMonth << "." <<
				(i.nYear < 10 ? "0" : "")		<< i.nYear << endl;
			});	
	}
	void Z105d_SortDate(vector<Z105d_TDate>& vd, Z105d_TypeSort(F))
	{
		bool compare = F();
		for (int i = 0; i < vd.size(); i++)
			for (int j = 0; j < vd.size() - 1; j++)
			{
				if (Z105d_СompTDate(vd[j], vd[j + 1], compare))
					swap(vd[j], vd[j + 1]);
			}
		return;
	}
	bool Z105d_VarSort()
	{
		cin.clear();
		cout << endl << "Введите тип сортировки 0 - по возрастанию, 1 - по убыванию" << endl;
		return cin.get();
	}
	bool Z105d_СompTDate(const Z105d_TDate& i1, const Z105d_TDate& i2,const bool& compare)
	{
		bool ret;
		if (i1.nYear == i2.nYear)
			if (i1.nMonth == i2.nYear)
				if (i1.nMonthDay == i2.nMonthDay)
					{ ret = false; return ret; }
				else
					ret = (i1.nMonthDay > i2.nMonthDay ? true : false);
			else
				ret = (i1.nMonth > i2.nMonth ? true : false);
		else
			ret = (i1.nYear > i2.nYear ? true : false);
		return compare ? ret : !ret;
	}
}
#pragma warning (disable : 4996)
#include <cstring>
#include <iostream>
#include <fstream>
#include <vector>
#include "windows.h"
#include <algorithm> //���������
#include "MyClasses.h"
#include "UniversalFunc.h"
#include "Zadachi.h"

using namespace std;

namespace Zadachi
{
	//������ � ������
	void Zadacha1()
	{
		string s = "��� ��� ������ ���������! \n";
		double c = 0;
		int a = 0, b = 0;
		setlocale(LC_ALL, "Russian");
		cout << "������� �������� �="; cin >> a;
		cout << "������� �������� b="; cin >> b;
		c = (double)a / b;
		cout << s << "������� ������ = " << c;
	}
	void Zadacha2()
	{
		int mo, ho, mp, hp; //, m, h;

		//������� 1
		cout << "������� 1:";
		cout << "������� ����� ����������� = " << endl;
		cin >> ho >> mo;
		cin.clear();
		cout << "������� ����� � ���� = " << endl;
		cin >> hp >> mp;

		//m = (mo + mp) % 60;
		//h = (ho + hp + (mo + mp) / 60) % 24;

		//cout << "����� �������� = " << endl << h << ":" << m <<endl; 
		cout << "����� �������� = " << endl
			<< (ho + hp + (mo + mp) / 60) % 24
			<< ":"
			<< (mo + mp) % 60
			<< endl;

		//������� 2
		cout << "������� 2:";
		int  mind;
		mind = (ho * 60 + mo) + (hp * 60 + mp);

		cout << "����� ��������";
		if ((mind % (24 * 60)) / 60 < 10)
			cout << 0;
		cout << (mind % (24 * 60)) / 60 << ":";

		if ((mind % (24 * 60)) % 60 < 10) //���� ������ ����� 10 �� �������� ����� ��� 0 � �����
			cout << 0;
		cout << (mind % (24 * 60)) % 60;
	}
	void Zadacha3()
	{
		double a, b;
		cout << "������� 2 �����" << endl;
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
		cout << "������� 3 �����" << endl;
		cin >> a >> b >> x;
		if (x >= a && x <= b)
		{
			cout << "X ��������� ����� � � �";
		}
		else
		{
			cout << "X �� ��������� � � �";
		}
	}


	/*�������� ������� �� 04.10.2022*/
		// ������
	void Zadacha1d() // ������
	{
		//����������
		double kurs, sm;
		char a[4];

		kurs = 25; //����

		cout.precision(2);
		cout << "��� ������������ ��������� ����� USD<->RUR, ���� 1 USD = " << kurs << " RUR" << endl
			<< "������� ����������� ������� ��� +1 ��� USD->RUR, � -1 ��� RUR->USD" << endl;

		while (true)
		{
			cin.get(a, 4);
			if (strcmp(a, "+1") == 0 || strcmp(a, "-1") == 0) { break; }
			else { cout << ":( �������� ����, ��������� ������ +1 ��� -1, ���������� ��� ���" << endl; cin.get(); }
		}

		cout << endl;

		if (strcmp(a, "+1") == 0)
		{
			cout << "������� ����� USD: ";
			input_chislo(sm);
			cout << endl << "����� � ������: ";
			sm = sm * kurs;
			cout << sm << endl;
		}

		if (strcmp(a, "-1") == 0)
		{
			cout << "������� ����� RUR: ";
			input_chislo(sm);
			cout << endl << "����� � $: ";
			sm = sm / kurs;
			cout << sm << endl;
		}

	}
	// ��������
	void Zadacha2d() //��������
	{
		int k, j;
		cout << "������� ������������ ���-�� ������ ���������� � ����, ��: ";
		input_chislo(j);
		cin.clear();
		cout << "������� ���-�� ������ ��� ��������, ��: ";
		input_chislo(k);

		cout << "����������� ���-�� ������  = " << ceil((double)k / j) << endl;
		if (k % j != 0)
		{
			cout << "��������� ���� �������� �� ��������� - " << k % j << " �� " << j - k % j << endl;
		}
	}
	// �����
	void Zadacha3d() //�����
	{
		int cube[3] = {}, dx, dy;

		cout << "������� ����� ������ ������� ����� x y z � ��: ";
		cin >> cube[0] >> cube[1] >> cube[2];
		cout << "������� ������� ���������� ������: ";
		cin >> dx >> dy;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i != j)
				{
					if ((cube[i] <= dx && cube[j] <= dy) || (cube[j] <= dx && cube[i] <= dy))
					{
						cout << endl << "��� " << cube[0] << "x" << cube[1] << "x" << cube[2] << "��"
							<< " �������� � ����� " << dx << "x" << dy << "��" << " ������ " << cube[i] << "x" << cube[j] << "��!" << endl;
						system("pause");
						exit(0);
					}
				}
			}
		}
		cout << endl << "��� " << cube[0] << "x" << cube[1] << "x" << cube[2] << "��"
			<< " �� �������� � ����� " << dx << "x" << dy << "�� �� ����� ������!" << endl;
	}
	// ����
	void Zadacha4d() //����
	{
		int d1, m1, d2, m2;
		cout << "������� ��� ���� ����� ������ � ������� �1 �1 �2 �2, ��� � - ���� � � -�����:";
		cin >> d1 >> m1 >> d2 >> m2;
		if ((d1 == d1) && (m1 == m2))
		{
			cout << "���� ���������";
		}
		else if (m1 < m2)
		{
			cout << "���� " << intdate(d1) << "." << intdate(m1) << " ������ " << intdate(d2) << "." << intdate(m2) << endl;
		}
		else
		{
			cout << "���� " << intdate(d2) << "." << intdate(m2) << " ������ " << intdate(d1) << "." << intdate(m1) << endl;
		}
	}
	// �����������
	void Zadacha5d() //�����������
	{
		int a, b, c;
		double pp;
		cout << "������� ������� ���� ������ ������������ ����� ������ � ��: ";
		cin >> a >> b >> c;
		pp = (double)(a + b + c) / 2;
		cout << endl << "�������� ������������ �����: " << pp * 2;
		cout << endl << "������� ������������ �� ������� ������ �����: " << sqrt(pp * (pp - a) * (pp - b) * (pp - c)) << endl;
	}
	// �������
	void Zadacha6d()
	{
		int x, y, a, b, v1, v2;
		cout << "������� ������� ��������� X*Y � ������� ����� A*B ����� ������ � ������� X Y A B:" << endl;
		cin >> x >> y >> a >> b;
		v1 = (a / x) * (b / y);
		v2 = (b / x) * (a / y);
		cout << "��������� �� 1 �������� ( ������� x ����� a) - " << v1 << " ��������� � �����" << endl;
		cout << "��������� �� 2 �������� ( ������� y ����� a) - " << v2 << " ��������� � �����" << endl;
		if (v1 > v2)
		{
			cout << "1 ������� ��������� �����" << endl;
		}
		else if (v1 == v2)
		{
			cout << "��� �������� ����� ���������� ���-�� ��������� � �����" << endl;
		}
		else
		{
			cout << "2 ������� ��������� �����" << endl;
		}
	}
	// �������
	void Zadacha7d()
	{
		double p0, p1, p;
		int t1 = 0, dt;
		double t;
		cout << "������� ����� ������ p0, p1, p, dt." << endl
			<< "	p0 - ���� �� ������ ������� 0" << endl
			<< "	p1 - ���� �� ������ ������� dt" << endl
			<< "	p - ���� ��� �������� ����� ����� ������ �������" << endl
			<< "	dt - ������ ������ �������, ���� � ������� �����" << endl;
		cin >> p0 >> p1 >> p >> dt;
		//�������� ������������
		t = double(dt) + (t1 - dt) * (p - p1) / (p0 - p1);
		cout << "������� ���� ������ ����� ��������� ����� " << t << " ���� � ������� ������� ����." << endl;
	}
	// �����������
	void Zadacha8d()
	{
		double x1, y1, x2, y2, x3, y3, x4, y4;
		double i[5] = {}, j[5] = {};
		bool xc = true;
		bool yc = true;

		cout << "������� ���������� ������� ���� ����� ������ x1 y1 x2 y2: ";
		cin >> x1 >> y1 >> x2 >> y2;
		cout << "������� ���������� ������� ���� ����� ������ x1 y1 x2 y2: ";
		cin >> x3 >> y3 >> x4 >> y4;

		i[1] = min(x1, x2); j[1] = min(y1, y2);
		i[2] = max(x1, x2); j[2] = max(y1, y2);
		i[3] = min(x3, x4); j[3] = min(y3, y4);
		i[4] = max(x3, x4); j[4] = max(y3, y4);



		if ((i[1] > i[4]) || (i[2] < i[3])) { xc = false; }
		if ((j[1] > j[4]) || (j[2] < j[3])) { yc = false; }

		if (xc * yc)
		{
			cout << "���� ������������" << endl;
		}
		else
		{
			cout << "���� �� ������������" << endl;
		}

		//_____________________________________________________________________
		// ������� ��������
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
			cout << "��� �����������";
		}
		else
		{
			cout << "(" << a2 << ";" << b2 << ");(" << a3 << ";" << b3 << ")";
		}
	}
	// ���
	void Zadacha9d()
	{
		int p, N, k0, k, a, b;
		cout << "������� ����� ������ ���-�� ���������, ������ � ������� �� �����.: ";
		cin >> p >> N >> k0;
		cin.clear();
		cout << endl << "������� ����� �������� ��� ������ �������� � �����: ";
		cin >> k;

		if (k > p * N * k0)
		{
			cout << endl << "����� �������� � ���� ���" << endl;
		}
		else
		{
			a = k / (N * k0);
			if (k % (N * k0) != 0) { a++; }
			b = ceil((double)(k - N * k0 * (k / (N * k0))) / k0);
			if (b == 0) { b = 4; }
			cout << endl << "	�������� ��������� � �������� � " << a << endl
				<< "			   �� �����   � " << b << endl;
		}
		//�������������� ������� 1 ��� �������������� �������
		int pod, et;
		pod = (k - 1) / (N * k0) + 1;
		et = ((k - 1) % (N * k0)) / k0 + 1;
		cout << "�������������� ������� 1. ����� - �������: " << pod << " ����: " << et << endl << endl;

		//�������������� ������� 2
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
		cout << "�������������� ������� 2. ����� - �������: " << pod << " ����: " << et << endl << endl;
	}
	// �������
	void Zadacha10d()
	{
		int Ds1, Ms1, Df1, Mf1, Ds2, Ms2, Df2, Mf2;
		int d1, d2, d3, d4;
		//while (true)
		//{ 
		cout << "������� ������ 1-�� �������: ";
		cin >> Ds1 >> Ms1 >> Df1 >> Mf1;
		cout << "������� ������ 2-�� �������: ";
		cin >> Ds2 >> Ms2 >> Df2 >> Mf2;

		d1 = --Ms1 * 30 + Ds1;
		d2 = --Mf1 * 30 + Df1;
		d3 = --Ms2 * 30 + Ds2;
		d4 = --Mf2 * 30 + Df2;

		if (d1 <= d3 && d4 <= d2)
		{
			cout << "���� ������������ �� ���-�� ����:" << d4 - d3 + 1 << endl;
		}
		else if (d1 >= d3 && d1 <= d4)
		{
			cout << "���� ������������ �� ���-�� ����:" << d4 - d1 + 1 << endl;
		}
		else if (d3 >= d1 && d3 <= d2)
		{
			cout << "���� ������������ �� ���-�� ����:" << d2 - d3 + 1 << endl;
		}
		else if (d3 < d1 && d2 < d4)
		{
			cout << "���� ������������ �� ���-�� ����:" << d2 - d1 + 1 << endl;
		}
		else
		{
			cout << "���� �� �����������" << endl;
		}
		//}
	}
	// �������
	void Zadacha11d()
	{
		int L1, L2, M;
		cout << "������� ����� ������ ������� �������� �� ���������� L1, L2 � ������������ ���-�� ������ � ��������� M" << endl;
		cin >> L1 >> L2 >> M;
		if (M - L1 <= 0)
		{
			cout << "������� �� 1-�� ��������� ��������� = " << L1 - M << ". �� 2-�� ��������� ��������� = " << L2 << endl;
		}
		else if (L2 + L1 >= M)
		{
			cout << "������� �� 1-�� ��������� ��������� = 0. �� 2-�� ��������� ��������� = " << L2 + L1 - M << endl;
		}
		else
		{
			cout << "������� �� 1-�� ��������� ��������� = 0. �� 2-�� ��������� ��������� = 0. � ��������� ��������� ��������� ���� = " << M - L2 - L1 << endl;
		}
	}
	// �������� ���
	void Zadacha12d()
	{
		int d1, m1, y1, d2, m2, y2, dt1, dt2;
		cout << "������ ����";
		cin >> d1 >> m1 >> y1;
		cout << "������ ����";
		cin >> d2 >> m2 >> y2;

		dt1 = y1 * 365 + m1 * 30 + d1;
		dt2 = y2 * 365 + m2 * 30 + d2;

		if (dt1 > dt2)
		{
			cout << "���� 1 ������ ���� 2";
		}
		else if (dt1 = dt2)
		{
			cout << "���� �����";
		}
		else
		{
			cout << "���� 2 ������ ���� 1";
		}

		//---------------------------------------------
		cout << endl << endl;
		if (y1 < y2)
		{
			cout << "������ ���� ������ �����";
		}
		else if (y1 = y2)
		{
			if (m1 < m2)
			{
				cout << "������ ���� ������ ������";
			}
			if (m1 > m2)
			{
				cout << "������ ���� ������ ������";
			}
			if (m1 = m2)
			{

			}
		}
		if (y1 > y2)
		{
			cout << "������ ���� ������ ������";
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

	/*�������� ������� ��������� �� 10.10.2022*/
		//����� ���
	void Zadacha13a()
	{
		//vector<char*> N();
		//vector<char*> M();

		cout << "������� ���������� (����� ����� - ���� ���������� �� ������) ����� ����� ������: " << endl;
		cin;


	}

	/*�������� 17.10.2022*/
		//����� ���� �����
	void Zadacha5()
	{
		//Ctrl + Z - ����� ������, ��������
		double a, b;	//�����
		int Count;		//������� ���
		double sum;		//�����
		int vers;		//������ ���������

		while (true)
		{
			Count = 0;
			sum = 0;
			cout << "������� ������� ��������� 1-3: ";
			cin >> vers;

			switch (vers) {
			case 1:
				while (1)
				{
					cout << "������� ���� ����� ��� Ctrl+Z: " << endl;
					cin >> a >> b;
					//cin.eof() - ���������� 1 ���� ��������� � ����� ������ � 0 ���� ����� ������ �� ���������.
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
				while (cout << "������� 2 ����� ��� Ctrl+Z: " << endl, cin >> a >> b)
				{
					//�������� 
					Count++;
					sum += a + b;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			case 3:
				for (;; Count++)
				{
					cout << "������� ���� ����� ��� Ctrl+Z: " << endl;
					cin >> a >> b;
					if (cin.eof())
						break;
					sum += a + b;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			case 4:
				for (; cout << "������� ���� ����� ��� Ctrl+Z: " << endl, cin >> a >> b; )
				{
					sum += a + b;
					Count++;
					cin.ignore(cin.rdbuf()->in_avail());
				}
				break;
			default: cout << "������� ��������� ������ ���� � ��������� 1-3!";
			}
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << "����� �����: " << sum << endl;
			cout << "���-�� �����: " << Count << endl;
		}
	}
	//�������� �� ������
	void Zadacha6()
	{
		int n;			//���-�� ����������� ���������
		double r, x, y; //������, � � Y ���������� ��������
		int k;			//���-�� ������������� ���������
		int i;			//���-�� ����������� ���������

		do
		{
			cout << "������� ������ � ���-�� ���������: ";
			cin >> r >> n;
		} while (r <= 0 || n <= 0);

		for (k = 0, i = 0; i < n; k++)
		{
			cout << "������� ���������� ��������: ";
			cin >> x >> y;
			if (x * x + y * y <= r * r)
				i++;
		}

		cout << endl << "��� " << n << " ��������� ���� " << k << " ���������." << endl;
	}
	//����� ���������� �����
	void Zadacha7()
	{
		int max = -1, pos = 1, r = 0;
		int n;

		cout << "������� �����: ";
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
			cout << "������������ ������ ����� �����������" << endl;
		}
		else
		{
			cout << "������������ ������ ����� " << max << ", ��������� �� ������� " << r << endl;
		}
	}
	//������������������ ����������� �����
	void Zadacha8()
	{
		int t,			//������� ��������
			p,			//���������� ��������
			i,			//����� �������� ��������
			kol,		//��� ���������� ���������
			pos,		//������ ������������������
			maxpos = 0,	//������������ �������
			maxkol = 0, //������������ ���-��
			maxe;		//������������ �����

		maxkol = 0;
		cout << "������� ������������������ ����������� ������������� ����� ����� ������ ��������������� 0: " << endl;
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
		cout << "������������ ������ " << maxkol << ", ������� ������������������ " << maxpos << ", ������� ������������������ " << pos;
	}

	/*�������� ������� �� 17.10.2022*/
		//�����
	void Zadacha13d()
	{
		double S, A;
		int N;

		cout << "������� ����� ������ S: ";
		input_chislo(S);
		cout << "������� ���������� ������ ������: ";
		input_chislo(A);
		cout << "������� ���-�� ������� ����� ������: ";
		input_chislo(N);

		for (int i = 1; i <= N; i++)
		{
			S *= 1 + A / 100;
		}

		cout << "������ ������ ����� ����� = " << round(S * 100) / 100 << endl;
	}
	//������
	void Zadacha14d()
	{
		int i = 0, j = 0;
		double t, tmax, tmp = -1, tso = 0;
		cout << "������� �������� ����������� ��� Ctrl+Z: " << endl;

		while (1)
		{
			cin >> t;
			//cin.eof() - ���������� 1 ���� ��������� � ����� ������ � 0 ���� ����� ������ �� ���������.
			if (cin.eof())
				break;
			//������� ������������ �����������
			i == 0 ? tmax = t : tmax = t > tmax ? t : tmax;

			//����������� ����������� ����� �������������
			tmp = t >= 0 && (tmp == -1 || tmp > t) ? t : tmp;

			//������� ����� ������������� ����������
			j += t < 0 ? 1 : 0;
			tso += t < 0 ? t : 0;

			//������� ��������� �������� � ������� ������
			i++;
			cin.ignore(cin.rdbuf()->in_avail());
		}
		cout << endl << "���-�� ��������� ����������: " << i << endl;
		if (i == 0) { cout << endl; return; }

		cout << "������������ �����������: " << tmax << endl;

		if (tmp != -1)
		{
			cout << "����������� �������� ����� ������������� ����������: " << tmp << endl;
		}
		else
		{
			cout << "������������� ����������� �� ���������" << endl;
		}

		if (j != 0)
		{
			cout << "������-������������� �����������: " << round(tso / j * 100) / 100 << endl;
		}
		else
		{
			cout << "������������� ����������� �� ���������" << endl;
		}

		cout << endl;
	}
	//������������ �����
	void Zadacha15d()
	{
		int a, b = 0;
		cout << "������� ����� ����� N: ";
		cin >> a;

		while (1)
		{
			if (a % 10 == 0 && a / 10 == 0) break;
			b = b * 10 + a % 10;
			a = a / 10;
		}

		cout << "������������ �����: " << b << endl << endl;
	}
	//����
	void Zadacha16d()
	{
		double i, j = 0, imax = -1, imin = -1;
		cout << "������� �������� ���, ����� ���������� Ctrl+Z" << endl;

		while (1)
		{
			cin >> i;
			if (cin.eof()) break;
			if (i < 0)
			{
				cout << "���� �� ����� ���� �������������!" << endl; continue;
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
			cout << "�� ����� " << j << " ����� ������:" << endl << "������������ ���� �� �����: " << imax << endl << "����������� ���� �� �����: " << imin << endl << endl;
		}
		else
		{
			cout << "���� �� ��������� :(";
		}
	}
	//���������� ���������� �����
	void Zadacha17d()
	{
		int a, i, max, min;
		cout << "������� ������������� ����� �����, ��� ��������� ������� Ctrl+Z" << endl;

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
			cout << "����������� ����� � ���� �����: " << min << endl;
			cout << "������������ ����� � �������� � ��������� �������� � ���� �����: " << max << endl << endl;
		}
	}
	//�������
	void Zadacha18d()
	{
		const int r1 = 1, r2 = 5;
		int p1, p2, i = 0,
			x1 = 0, x2 = 0, x3 = 0;
		cout << "������� ������� ����� ���� ����� ����� ������, �� ��������� Ctrl+Z:";
		while (1)
		{
			cin >> p1 >> p2;
			if (cin.eof()) break;

			if (p1 == r1 && p2 == r2) x1++;
			else if (p1 == r1 || p2 == r2) x2++;
			else x3++;

			i++;

		}
		cout << "���������� ��������� ����: " << r1 << " " << r2 << endl
			<< "��� ����� �������: " << x1 << " �����" << endl
			<< "���� ����� �������: " << x2 << " �����" << endl
			<< "���� ����� �������: " << x3 << " �����" << endl
			<< "������ �������� " << i << " �����" << endl;
	}
	//�����������
	bool prostoe(int n)
	{
		for (int i = 2; i < n; i++)
			if (n % i == 0) return false;
		return true;
	}
	void Zadacha19d()
	{
		int n;
		cout << "������� ����� ����� N: ";
		cin >> n;

		if (prostoe(n)) { cout << "����� ���� �� ���� �������"; return; }

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
		cout << "������� ����� ����� N: ";
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
	//���� �����
	void Zadacha20d()
	{
		int n = 0, kur = 0, kurold = 0, kup = 0, kupall = 0, max = 0;

		cout << "������� ����� ������ �������� ����� �����" << endl;
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
		cout << "����� ��������������� ���� ��� " << max << " ����." << endl;
		cout << "���� ��� " << kupall << " ���� �� " << n << " ����, �.�. " << kupall * 100 / n << "% ����";
	}
	//�������� ���������
	void Zadacha21d()
	{
		int k, i;
		bool y;
		while (1)
		{
			cout << "������� ����� k: ";
			cin >> k;
			if (cin.eof()) break;
			cout << "\t ����� N = ";
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
			if (!y) { cout << "�� ����� �������" << endl; }
			else { cout << endl; }
		}
	}
	//������ �.������
	void Zadacha22d()
	{
		int x, y, n,
			s = 1770,
			c1 = 31, c2 = 21;

		cout << "������ ����� ������� ({�������:�����}): " << endl;
		for (int n = 10; n < 1770 / 21; n += 10)
		{
			x = (1770 - 21 * n) / 10;
			y = n - x;
			if (y >= 0) { cout << "{" << x << ":" << y << "}" << endl; }
		}
		/* �������� ������� ��������� �� ������� ������.
		31x + 21y = 1770;
		x + y = N.

		y = N - x;
		31x + 21(N - x) = 1770;
		31x + 21N - 21x = 1770;
		10x = 1770 - 21N;
		x = (1770 - 21N)/10.

		������� ������ ����� ������������� �� ������� ������� ���������, ��� ������� N ������ 10, � x + y = N.
		��� N = 10 ��� �������:
		x = (1770 - 210)/10 = 1560/10 = 156.
		��� N = 20:
		x = (1770 - 420)/10 = 135.

		��� N = 30:
		x = (1770 - 630)/10 = 114.

		��� N = 40:
		x = (1770 - 840)/10 = 93.

		��� N = 50:
		x = (1770 - 1050)/10 = 72.

		��� N = 60:
		x = (1770 - 1260)/10 = 51;
		y = 60 - 51 = 9.

		��� N = 70:
		x = (1770 - 1470)/10 = 30;
		y = 70 - 30 = 30.

		��� N = 80:
		x = (1770 - 1680)/10 = 9.
		y = 80 - 9 = 71.

		�����: ������ ����� ��� ������� (51; 9), (30; 30), (9; 71).*/
	}
	void Zadacha22dv2()
	{
		int y;
		for (y = 1; y <= 84; y++)
			if ((1770 - 21 * y) % 31 == 0)
				cout << (1770 - 21 * y) / 31 << "������� �" << y << " �����" << endl;
	}
	//��������
	void Zadacha23d()
	{
		//int w = 1, h;
	}

	/*�������� 25.10.2022*/
		//�������� ������		
	void Zadacha24()
	{
		int n, s = -1;

		cout << "������� ����� n: ";
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
		cout << endl << "�������� ������ ����� = " << n;
	}
	//����������� �����
		/*���� ����� ������ 5385324 ����� 38324*/
	void Zadacha25()
	{
		int a, b, c = 0;
		cout << "������� ����� a � ����� ����� �������� �� �: ";
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
		cout << "����� = " << c << endl;
	}
	//����������� - ����������� � ������
	void Zadacha26()
	{
		int x1, y1,
			x2, y2,
			x3, y3,
			xt, yt,
			a, b, c, p1, p2, p3,
			s1, s2, s3, s4;

		cout << "������� ���������� ����� A: ";
		cin >> x1 >> y1;
		cout << "������� ���������� ����� B: ";
		cin >> x2 >> y2;
		cout << "������� ���������� ����� C: ";
		cin >> x3 >> y3;
		cout << "������� ���������� ����� O: ";
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
			cout << "����� ����� ������ ������������";
		}
		{
			cout << "����� �� ����� ������ ������������";
		}
	}
	//������� - ����� ���������� ������������������
	void Zadacha27()
	{
		int n, x, sum, max;
		max = 0;
		sum = 0;
		cout << "������� ���-�� ���������: 0";
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
				cout << "�� ���� ������������� ����� :(";
			else
				cout << max;
		}
	}

	/*�������� 01.11.2022*/
		// ��������� �������. ������ ��� 3 �������� � 4 ��������
	void Zadacha28()
	{
		const int NSHOP = 3; // ����� ���������
		const int NGOODS = 4; // ����� �������
		double r[NSHOP][NGOODS]; // ���������
		double svg[4] = { 0, 0, 0, 0 }; //������ ���� �� �������

		//������ ��� �������
		double srshop, sum = 0; // ������� ��
		//���������, �������, �����

		cout << "������� ������� �� ���, ������, �����, ������� \n";

		// ���� ������
		for (int i = 0; i < NSHOP; i++) { // ������� ���������
			cout << "������� " << i + 1 << ": ";
			for (int j = 0; j < NGOODS; j++) // ������� �������
				cin >> r[i][j];
		} // ���� ������� i-�� �������� �� ������� j-�� ������

		cout << endl;
		for (int i = 0; i < NSHOP; i++) { // ������� ���������
			srshop = 0;
			for (int j = 0; j < NGOODS; j++) // ������� �������
			{
				srshop += r[i][j];
				svg[j] += r[i][j];
			}
			cout << "������� �� ��������:" << i << "= ";
			cout << srshop << endl;
			sum += srshop;
		}

		cout << endl;
		for (int i = 0; i < 4; i++)
		{
			cout << "������� �� ������:" << i << "=" << svg[i] << endl;
		}

		cout << "\n ����� ������� �� ���� ��: " << sum
			<< endl;
	}
	// ���������� ������� �� �����������
	void Zadacha29()
	{
		double arr[100], min;
		int n, i, j, imin;

		cout << "������� �������� �������" << endl;
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
	// ���������� ������� �� ����������� ��������
	void Zadacha30()
	{
		double arr[100], tmp;
		int n, i, j, k;

		cout << "������� �������� �������" << endl;
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
	// � ���������� �������� ������� ����� �� 0 �� 100. ������� ��� ����� � ������� �����������.
	void Zadacha31()
	{
		int t, arr[101] = { 0 };
		int n, i, j;

		cout << "������� �������� �������" << endl;
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
	// �������� (����� ������������ ������ � ������ �������� ��������)
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
		cout << "�������� ������������ ������" << maxLArea << "� ���� ������" << maxHArea << endl;
	}
	//����� ���-�� ��������� ������ ����� � ������
	void Zadacha33()
	{
		int arr[10] = { 0 };
		int n, i;

		cout << "������� ����������� �����: ";
		cin >> n;
		while (n > 0)
		{
			arr[n % 10]++;
			n /= 10;
		}
		for (i = 0; i < 10; i++)
		{
			if (arr[i] != 0)
				cout << "����� " << i << " ������� " << arr[i] << " ���" << endl;
		}
	}

	/*�������� ������� �� 31.11.2022*/
			/*����� 1. ������� �������� � ���������*/
		//�������� � ��������� ������� j ��������� �������, ����������� N ����� (J < N), �������� ����� (���-�� ��������� ������ ����� N+1)
	void Zadacha34d()
	{
		int n, i, j;
		double k;

		cout << "������� ���-�� ��������� �������" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������" << endl;
		for (i = 0; i < n; i++)
			cin >> arr[i];
		n++;

		cout << "������� ����� ������ ����� ������� � �����" << endl;
		cin >> j >> k;

		//������� �����
		for (i = n; i > j - 1; i--)
		{
			arr[i] = arr[i - 1];
		}
		arr[j - 1] = k;

		cout << "������������ ������: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//��������, ����������� �� � ������� �� N ��������� �������� ��������, ���� ����������� �� � ����� �������(� ����� ����� ���������� ������ �����)
	void Zadacha35d()
	{
		int n, i, jone = -1, jlast = -1;
		double k;

		cout << "������� ���-�� ��������� �������" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������" << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "������� ������� �����" << endl;
		cin >> k;

		//�����
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
			cout << "����� ������� ��������� ��������: " << jone + 1 << endl
				<< "��������� ������� ��������� ��������: " << jlast + 1 << endl;
		}
		else
		{
			cout << "� ������� �� �������� �����";
		}
	}
	//������� �� ������� j-� ������� �� ������� (� ����������� ������� ���������� ����������� ���������)
	void Zadacha36d()
	{
		int n, i = 0, j = 0;

		cout << "������� ���-�� ��������� �������" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������" << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "������� ����� ������� j ��� ��������" << endl;
		cin >> j;

		//��������
		for (i = j - 1; i < n; i++)
		{
			arr[i] = arr[i + 1];
		}

		//�����
		cout << "��������� �������� ������: " << endl;
		for (i = 0; i < n - 1; i++)
		{
			cout << arr[i] << " ";
		}
	}
	//������� �� ������� ������ �������, ���������� �������� �����
	void Zadacha37d()
	{
		int n, i;
		double j;
		bool y = false;
		cout << "������� ���-�� ��������� �������: " << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������: " << endl;
		for (i = 0; i <= n - 1; i++)
		{
			cin >> arr[i];
		}

		cout << "������� ����� ��� ��������: " << endl;
		cin >> j;

		//��������
		for (i = 0; i < n; i++)
		{
			if (arr[i] == j)
				y = true;
			if (y && i < n - 1)
				arr[i] = arr[i + 1];
		}
		if (y)
			n--;

		//�����
		cout << "��������� �������� ������: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//������� �� ������� ��������� ������� ���������� �������� �����
	void Zadacha38d()
	{
		int n, i, j;
		double k;
		bool y = false;
		cout << "������� ���-�� ��������� �������: " << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << "������� ����� ��� ��������: " << endl;
		cin >> k;

		//��������
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

		//�����
		cout << "��������� �������� ������: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}

	}
	//���������� �������� ������� �������
	void Zadacha39d()
	{
		int n, i, j, tmp;
		cout << "������� ���-�� ��������� �������: " << endl;
		cin >> n;
		double* arr = new double[n];
		arr[0] = { 0 };

		cout << "������� �������� �������: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		//����
		for (i = 0; i < n / 2; i++)
		{
			tmp = arr[i];
			arr[i] = arr[n - i - 1];
			arr[n - i - 1] = tmp;
		}

		//�����
		cout << "��������� �������� ������: " << endl;
		for (i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	//�������������� ��������� �� �����������, ��������
	void Zadacha40d()
	{
		//��.Zadacha30()
	}
	//���������� � ������� ������������� ���������
	void Zadacha41d()
	{
		int i, j, k, arr[10] = { 2,5,10,2,6,9,9,5,8,9 };
		int e = 9;

		cout << "��� ������: " << endl;
		for (i = 0; i <= e; i++)
			cout << arr[i] << " ";
		//������� ���������
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
		//�����
		cout << endl << "��������� ������:" << endl;
		for (i = 0; i <= e; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	//� ���� �������� �������� ����� ��������
	void Zadacha42d()
	{
		char m[5][7] = { "����","���","���","������","����" };
		char m2[5][7] = { "���","����","���","����","����" };
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
		cout << "����� �������: " << endl;
		if (n)
			for (i = 0; i < n; i++)
				cout << m3[i] << endl;
		else
			cout << "��� ����� ��������� :(";
	}
	//��������� �� ������� �������� ������������ �� ������ �������
	void Zadacha43d()
	{
		int i, j, n = 10, n2 = 10, arr1[50], arr2[50];
		IntArrFillRandom(arr1, n);
		IntArrFillRandom(arr2, n);

		cout << "������1" << endl;
		IntArrPrint(arr1, n);
		cout << "������2" << endl;
		IntArrPrint(arr2, n2);

		for (i = 0; i < n; i++)
			for (j = 0; j < n2; j++)
				if (arr1[i] == arr2[j])
					ArrDeleleElement(arr1, n, i);

		cout << "������1? ��� �������� �� �������2" << endl;
		IntArrPrint(arr1, n);
	}
	//�������� � ������ ������ �� �������� �� �������, ������� �� ���� � ������.
	void Zadacha44d()
	{
		int arr1[20], arr2[10], n1 = 10, n2 = 10, i, j;
		IntArrFillRandom(arr1, n1);
		Sleep(1000);
		IntArrFillRandom(arr2, n1);

		cout << "������1: " << endl;
		IntArrPrint(arr1, n1);
		cout << "������2: " << endl;
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

		cout << "������1 ������������ � ����������: " << endl;
		IntArrPrint(arr1, n1);
	}
	/*����� 2. ������ �� ������� � �����*/
//��������
	void Zadacha45d()
	{
		//��.Zadacha39d()
	}
	//�������� �������
	void Zadacha46d()
	{
		int arr1[10], n1 = 10, i, MAX, MIN, cMAX = 0, cMIN = 0, SUM = 0;
		IntArrFillRandom(arr1, n1);
		cout << "������1 �� 10 �����: " << endl;
		IntArrPrint(arr1, n1);
		cout << "��������� ������� �����: " << endl;
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
		cout << "������������ ����� ����� " << MAX << ", ��� ����������� " << cMAX << " ���" << endl;
		cout << "����������� ����� ����� " << MIN << ", ��� ����������� " << cMIN << " ���" << endl;
		cout << "������� �������������� ��� ����� MIN � MAX �����: " << (SUM - MAX * cMAX - MIN * cMIN) / (n1 - cMAX - cMIN) << endl;
	}
	//������
	void Zadacha47d()
	{
		int arr[12], n = 12, i, SUM = 0;
		IntArrFillRandom(arr, n);
		cout << "������ �� 12 �������: " << endl;
		IntArrPrint(arr, n);
		for (i = 0; i < n; i++)
			SUM += arr[i];
		cout << "������ ������� ��� ������ ���� ���� �������� ��������: " << SUM / n << endl;
		for (i = 0; i < n; i++)
			if (arr[i] > (SUM / n))
				cout << i + 1 << " ";
	}
	//������
	void Zadacha48d()
	{
		int arr[12], n = 12, i, j;
		IntArrFillRandom(arr, n);
		cout << "��� ��������� ������ �� 12 ���������: " << endl;
		IntArrPrint(arr, n);
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < i; j++)
				if (arr[i] == arr[j])
				{
					ArrDeleleElement(arr, n, i);
				}
		}
		cout << "������ ��� ����������: " << endl;
		IntArrPrint(arr, n);
	}
	//��� ��������
	void Zadacha49d()
	{
		char Days[7][12] = { "�����������","�������","�����","�������","�������","�������","�����������" };
		int dayn, pod[7] = { 0 };

		cout << "������� N ��� ��������, �� ��������� Ctrl+Z:" << endl;
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
	//������� ������� �����
	void Zadacha50d()
	{
		int ch, max = 0, i = 0;
		cout << "������� ������� ������" << endl;
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
		cout << "������������ ����� ������ ������ ����� ����� " << max << endl;
	}
	//������������ �������������� ������� ���������
	void Zadacha51d()
	{
		//��. Zadacha30
	}
	//������������ ��������
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

		cout << "����� ������� �� �������� ����� ������" << endl;
		for (i = n - 1; i > -1; i--)
			cout << "����� ����� " << arr[i][0] + 1 << " ����� " << arr[i][1] << endl;
	}
	//����� ���
	void Zadacha53d()
	{
		//��.Zadacha34
	}
	//������������ ����������
	void Zadacha54d()
	{
		//��. Zadacha36
	}
	//���������� ��������
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
		cout << "������ ���������: " << endl;
		IntArrPrint(arr1, 10);
		cout << "������ ���������� ���������: " << endl;
		IntArrPrint(arr2, 10);
		cout << "���������� ���������� ������: " << endl;
		for (i = 0; i < 10; i++)
			if (!arr3[i])
				cout << arr1[i] << " ";
	}
	//�������
	void Zadacha56d()
	{
		//��.Zadacha38
	}
	//������� �����*
	void Zadacha57d()
	{
		//��.Zadacha35
	}
	//����*
	void Zadacha58d()
	{
		int arr[100], n, i, ch1[100], ch2[100], r1 = 0, r2 = 0, sum1 = 0, sum2 = 0, max;
		cout << "������� ���-�� ����:" << endl;
		cin >> n;
		cout << "������� ���� ����" << endl;
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

		cout << "���� �� ������ ����:" << endl;
		IntArrPrint(ch1, r1);
		cout << "���� �� ������ ����:" << endl;
		IntArrPrint(ch2, r2);
		cout << "������� ����� ����� ���: " << abs(sum1 - sum2) << endl;

	}
	//����**
	void Zadacha59d()
	{
		int arr[100], n, i, j, K, sh, tmp, Max, Min, Krat, gK = 0, gR = -1, gKMax = 0, gKMin = 0;
		cout << "������� ���-�� �������:" << endl;
		cin >> n;

		for (i = 0; i < n; i++)
		{
			cout << "������� ���-�� ������� � " << i << "-�� ������" << endl;
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

		cout << "����� ������ ������� ��������� �� �=" << gK << " �����." << endl <<
			"����������� ������� � ���� " << gKMax << ", � ���������� " << gKMin << endl <<
			"������� ����� ���������� � ����� �������� " << gR << " �������" << endl;

	}


	/*�������� 08.11.2022*/
		//����� ���
	void Zadacha34()
	{
		double h[100], sh[100];
		int N, M, i, j;
		double max = 0, min, ihouse;

		cout << "������� ���-�� �����: " << endl;
		cin >> N;

		cout << "������� ���������� ����: " << endl;
		for (i = 0; i < N; i++)
		{
			cin >> h[i];
		}

		cout << "������� ���-�� ���������� ����: " << endl;
		cin >> M;

		cout << "������� ���������� ���������� ����: " << endl;
		for (i = 0; i < M; i++)
		{
			cin >> sh[i];
		}

		//����� ���
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

		cout << "��� " << ihouse << " ���������� " << max;

	}
	//������� ����� � ������� ������������� �� �����������
	void Zadacha35()
	{
		int dat, n, b, e, i, sr = 0, arr[100];
		cout << "������� ���-�� ��������� �������";
		cin >> n;

		for (i = 0; i < n; i++)
			arr[i] = i;
		cout << "������� �������";
		cin >> dat;

		b = 0; e = n;
		while (b != e)
		{
			sr = (b + e) / 2; //���� ���������
			if (arr[sr] == dat)
				break;
			if (arr[sr] > dat)
				e = sr;
			else
				b = sr + 1;
		}
		if (sr == dat)
			cout << "�������";
		else
			cout << "�� �������";

	}
	//������������ ����������
	void Zadacha36()
	{
		int arr[100][2];
		int num, time, n, i, j, kol = 0;

		cout << "������� ���-�� ����������";
		cin >> n;
		cout << "������� ������� � �����������������";

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

			cout << "��� \t �����" << endl;
			cout << arr[i][0] << "\t" << arr[i][1] << endl;
		}
	}
	//������ ������� (� ����� ����������)
	void Zadacha37()
	{
		int arr[100], n, tmp, i, up, down;
		cout << "������� ���-�� ��������";
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
	//�������
	void Zadacha38()
	{
		int arr[100][2], n, i, num1, num2, k, win[3] = { 0 };
		cout << "������� ���-�� ����������";
		cin >> n;
		cout << "������� ������ ����������";
		for (i = 0; i < n; i++)
			cin >> arr[i][0] >> arr[i][1];
		cout << "������� ���������� ������: " << endl;
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
			cout << i << "����� ������� � " << win[i] << " �������";
	}
	/* � ���������� �������� �������� ����������� �����, ���������� ����� �� �� ���� ����� ������������ ���� �������� ���������*/
	/*��������� ������������ � ����������� ���������� */
	void Zadacha39()
	{
		int i, j, k, l, a, nech = 0, n, arr[10] = { 0 };
		int centr = -1;
		bool prtnull = false;

		cout << "������� ���-�� ��������: " << endl;
		cin >> n;
		cout << "������� " << n << " ��������� �������: " << endl;
		for (i = 0; i < n; i++)
		{
			cin >> a;
			arr[a]++;
		}

		//������ ������������ ���������
		cout << "������������ ���������: " << endl;
		for (i = 9; i >= 0; i--)
		{
			if (arr[i] % 2 != 0)
			{
				nech++;
				centr = i;
			}
			if (nech > 1)
			{
				cout << "��������� ��������� ������. ����� �������� ��������� ���� :(";
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


		//������ ����������� ���������
		nech = 0;
		cout << endl << "����������� ���������: " << endl;
		for (i = 1; i < 10; i++)
		{
			if (arr[i] % 2 != 0)
			{
				nech++;
				centr = i;
			}
			if (nech > 1)
			{
				cout << "��������� ��������� ������. ����� �������� ��������� ���� :(";
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

		cout << "������� �����: ";
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
			cout << "������ ��������� ��������� :(" << endl;
		if (kol_nech > 1)
			cout << "������ ��������� ��������� :(" << endl;
		else
		{
			cout << "������������ ���������: " << endl;
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

			cout << endl << "����������� ���������: " << endl;
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

	/*�������� 15.11.2022*/
		//������ ��������� �������
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

		//������ ������� ��������
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
		cout << "������� ���-�� ���������: ";
		cin >> n;

		Scan_arr(arr, n);
		n = main_swap(arr, n);
		cout << "���������� ������: " << endl;
		Print_arr(arr, n);

		cout << endl;
	}

	//������ �������
	void Zadacha41()
	{
		const int MAXCount = 100;
		const int MAXLENNAME = 20;
		const int MAXLENPHONE = 16;
		int n = 4, i, j, f, Count = 0;

		char tmp[MAXLENPHONE];

		char name[MAXCount][MAXLENNAME] = { "������ ��","������ ��","������ ��","������ ��" };
		char phone[MAXCount][MAXLENPHONE] = { "461-74-88","452-74-85","950-261-74-83","950-382-47-83" };

		cout << "������� ������ ��������: " << endl;
		cin >> tmp;
		//cin.getline(tmp, MAXLENPHONE); //�������

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
				cout << "������� ";
				for (j = 0; name[i][j] != '\0'; j++)
				{
					cout << name[i][j];
				}
				for (j = 0; phone[i][j] != '\0'; j++)
					cout << phone[i][j];
				//cout << "������� " << name[i] << "\t" << "������� " << phone[i];
				Count++;
			}
		}
		if (Count == 0)
			cout << endl << "���������� ������� ��� :(";
	}
	//������� ������ 41 � ���������(��������������)!!!

	/*�������� ������� �� 18.11.2022*/
		/*����� 1*/
	//������� ���������
	void Zadacha60d()
	{
		int l;
		cout << "������� ���� ������ ������: ";
		cin >> l;
		cout << endl;
		char* str = new char[l];
		cout << "������� ������: " << endl;
		cin >> str;
		if (IsCharPalindrom(str, l))
			cout << "��, ������ ��������� :)";
		else
			cout << "���, ��� ������ �� ��������� :(";
	}
	//����� ������ � �������
	void Zadacha61d()
	{
		int i = 0, j = 0, f = 0;
		char Name[][20] = { "������1","������2","������3","������4" };
		char Search[20];

		cout << "������� ������ ��� ������: ";
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
			cout << "� ������� ���� ����� ������, ������� " << f << endl;
		}
		else
		{
			cout << "� ������� ��� ������� ������ :( " << endl;
		}
	}
	//������
	void Zadacha62d()
	{
		int N, l, i, j, s;

		cout << "������� ���-�� ����� �������: ";
		cin >> N;
		cout << "������� ������ ����� �������: ";
		cin >> l;

		char** Names = new char* [N];
		for (i = 0; i < N; i++)
			Names[i] = new char[l];

		int* st = new int[N];
		char* f = new char[l];

		cout << endl << "������� �������: " << endl;
		CharArrFill(Names, N, l);

		cout << endl << "������� ����: " << endl;
		IntArrFill(st, N);


		cout << endl << "�. ������� ������� ��� ������: ";
		cin >> f;
		for (i = 0; i < N; i++)
		{
			if (CharStrictMatching(f, Names[i]))
			{
				cout << "���� ��������� �����: " << st[i] << endl;
			}
		}

		cout << endl << "�. ������� ����: ";
		cin >> s;
		cout << "� ��������� ������: " << endl;
		for (i = 0; i < N; i++)
		{
			if (st[i] == s)
				cout << Names[i] << endl;
		}

		cout << endl << "�. ������� � ������������ ������: " << endl;
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
	//���� �'?'										
	void Zadacha63d()
	{
		char str[25];
		char mask[25];
		cout << "������� ����� ��� ������ (���� ������ ��� ����������� �������� - ?): " << endl;
		cin >> mask;

		cout << "������� ������ ��� ������ ������������ ����� ���� Ctrl + Z: " << endl;
		while (1)
		{
			cin >> str;
			if (cin.eof())
				break;
			cin.ignore(cin.rdbuf()->in_avail());
			if (CharNotStrictMatching(str, mask, '?'))
				cout << "����� ��������� � ������ :)" << endl;
			else
				cout << "����� �� ��������� � ������ :(" << endl;
		}
	}
	//���������� ���������� �������					
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
		cout << "������� ������: " << endl;
		cin >> str;
		cout << "������� ������: " << endl;
		cin >> c;
		Zadacha64_func1(str, c, max);
		cout << "������������ ���������� ������� '" << c << "' � ������: " << endl << max << endl;
	}
	//������� �������
	void Zadacha65d()
	{
		int max = 0, i = 0, cmax = 0;
		char str[20], c;
		cout << "������� ������: " << endl;
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
		cout << "����������� � ������ ����������� ������ '" << c << "' � ���-�� " << cmax << " ���" << endl;
	}
	//������
		/*������� �� ���������*/
	void Zadacha66d()
	{
		char s[100];
		int Count = 0, i;
		bool f = true;

		cout << "������� ������: ";
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
			cout << "������ ����������� ��������� :)";
		else
			cout << "������ ����������� �� ��������� :(";
	}
	//������� ��� ��������
	void Zadacha66v2()
	{
		char s[100];
		int Count = 0;
		bool f = true;
		cout << "������� ������ �� ��������";
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
				cout << "������ ����������� ��������� :)";
			else
				cout << "������ ����������� �� ��������� :(";
		}
	}
	//�������� ������� ��������� �����
	void Zadacha67d()
	{
		char s[100];
		char* ps, * st, * fin;
		int level = 0, maxlevel = 0;
		bool f = false;

		cout << "������� ������";
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

		cout << "������� ������";
		if (f)
			while (st <= fin)
				cout << *(st++);
		else
			cout << s;

	}
	//����������									
	void Zadacha68d()
	{
		char a[100], b[100], c[101];
		int i, cel = 0, c_a, c_b;

		cout << "������� ������ �����: ";
		cin >> a; //��������� �����
		cout << "������� ������ �����: ";
		cin >> b; //��������� �����

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

		cout << endl << "�������: " << endl;
		cout << a << "+" << b << "=" << c;
	}
	//����������++
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

		cout << "������� ������ ������� �� ����� 100: " << endl;
		cin >> n;
		cout << "������� ����� �������: " << endl;
		IntArrFill(a, n);
		c = Zadacha69dfunc(a, n, s);
		cout << "������ ����������: " << endl;
		Print_arr(c, s);
	}
	//�����+������									
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

		cout << "������� ������ ��� �������� � ������ ��� Ctrl+Z: " << endl;
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


		cout << "��������� ������: " << endl;
		CharArrPrint(a, n);

		cin.clear();
		cout << "������� ������ ��� ������" << endl;
		cin >> c;
		u = Zadacha70dfunc(a, n, c);
		if (u == NULL)
		{
			cout << "������ � ������� �� ������";
			return;
		}
		else
			cout << "������ ������ � ������� �� '@'" << endl;

		while (1)
		{
			u = Zadacha70dfunc(a, n, c);
			if (u != NULL)
				*u = '@';
			else
				break;

		}
		cout << "����� ������ ��������� ������: " << endl;
		CharArrPrint(a, n);
	}
	//�����������**
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


		cout << "������� ������ ������: " << endl;
		cin >> s;
		str = new char[s];

		cin.ignore(cin.rdbuf()->in_avail());
		cout << "������� �������������� ������: " << endl;
		cin.getline(str, s);

		max = Zadacha71dfunc(str, s);

		cout << "��������� ���-�� ��������� ����������� " << pow(2, max) << endl;

	}
	/*����� ������*/
//1.������� � ��������� ������� ��������� ������� ��������� �������� (���������� ��������� ������ ��������).
	void Zadacha72d()
	{
		int n; //������ �������
		int j; //������� ��� ������
		double k; //����� ��� ������

		cout << "������� ���-�� ��������� �������" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������" << endl;
		Scan_arr(arr, n);

		cout << "������� ����� ������ ����� ������� � �����" << endl;
		cin >> j >> k;

		DoubleArrAddElement(arr, n, j, k);

		cout << "������������ ������: " << endl;
		Print_arr(arr, n);
		cout << endl << endl;
	}
	//2. �������� � ������ ��������� ������� ������ � �������.
	void Zadacha73d()
	{
		int n; //������ �������

		cout << "������� ���-�� ��������� �������" << endl;
		cin >> n;
		double* arr = new double[n + 1];
		arr[0] = { 0 };

		cout << "������� �������� �������" << endl;
		Scan_arr(arr, n);

		cout << "�������� ���������� �������" << endl;
		Print_arr(arr, n);
	}
	//3. ����������� ������� ������� / ���������� ��������� � �������� ������ ��������� ��������.
	void Zadacha74d()
	{
		int i, st, fin;
		char s[100], c;

		cout << "������� ������" << endl;
		cin.getline(s, 100);

		cout << "������� ������" << endl;
		cin.get(c);

		cout << "������ ��������� ��������" << endl;
		if (PosElementInChar(s, c, &st, &fin))
			cout << "������� ������� ��������� ��������: " << st << endl << "������� ���������� ��������� ��������: " << fin;
		else
			cout << "������� �� ������";
	}
	//4.�������� �� ������� �������� � �������� �������(� ����������� ������� ����������) ����������� ���������.
	int delchar_Zadacha75d(char s[], char c)

	{
		int i, j = 0;
		for (i = 0; s[i] != '\0'; ++i) // ������� ���������
			if (s[i] != c)
			{ // ���� ������ s[i] �� ���������,
				s[j] = s[i]; // ���������� �� ����� ����� ������
				++j; // ������� ����������� � ������ ��������
			}

		s[j] = '\0'; // ��������� ����� ����� ������
		return j; //������� ���-�� �������� � ������
	}
	void Zadacha75d()
	{
		const int N = 200; // ������ �������
		char st[N]; // ������ ��� ������
		setlocale(LC_ALL, "Russian");
		cout << "������� ������:\n";
		cin.getline(st, N); // ���� ������
		int n = strlen(st); // ������� ����� ������
		cout << "����� ��������� ������: " << n;
		cout << endl;
		cout << "������� ��������� ������ ";
		char dc = cin.get(); // ���� �������
		n = delchar_Zadacha75d(st, dc); // ����� �������
		cout << "������������ ������:\n";

		// ��������� �� ������� �������� 866
		// ��� ������ ������� ��������
		setlocale(LC_ALL, ".866");
		cout << st << endl;
		setlocale(LC_ALL, "Russian");
		cout << "�� �����: " << n << endl;
	}
	//5. �������� �� ������� ������� ��������, ������������ � �������� ������.
	void Zadacha76d()
	{
		int arr[5], n = 5, pos, c;
		cout << "������� " << n << " ��. ��������� �������: " << endl;
		IntArrFill(arr, n);
		cout << "������� ������� ��� ��������: " << endl;
		cin >> c;
		if (PosFirstElementInArray(arr, c, n, pos))
		{
			ArrDeleleElement(arr, n, pos);
			cout << "������� ������, ������ � ����������: " << endl;
		}
		else
			cout << "������� ������, �������� ������: " << endl;
		Print_arr(arr, n);
	}
	//6. �������� �� ������� ���� ���������, ���������� �������� �����.
	void Zadacha77d()
	{
		int arr[5], n = 5, pos, c;
		cout << "������� " << n << " ��. ��������� �������: " << endl;
		IntArrFill(arr, n);
		cout << "������� ������� ��� ��������: " << endl;
		cin >> c;
		while (PosFirstElementInArray(arr, c, n, pos))
			ArrDeleleElement(arr, n, pos);
		cout << "������ � ����������:" << endl;
		Print_arr(arr, n);
	}
	//7. ������������ ��������� ������� � �������� �������.
	void revers_Zadacha78d(char s[])

	{

		int i, j; // ������ � �������� ��������

		char tmp; // ��� ������ ��������

		for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {

			tmp = s[i];

			s[i] = s[j];

			s[j] = tmp;
		}

	}
	void Zadacha78d()
	{
		setlocale(LC_ALL, "Russian");
		const int MAX = 100; // ������ �����
		char orig_s[MAX]; // �������� ������
		char rev_s[MAX]; // ��������������� ������

		cout << "������� ������: ";
		cin.getline(orig_s, MAX); // ���� ������
		strcpy(rev_s, orig_s); // �������� orig_s � rev_s
		revers_Zadacha78d(rev_s); // �������������� ������ rev_s

		cout << "��������������� ������: ";
		cout << rev_s << endl; // ����� rev_s
	}
	//8. ������������ ��������� ������� �� ����������� / ��������.													
	void Zadacha79d()
	{
		int arr[5], n = 5;
		cout << "������� " << n << " ��. ��������� �������: " << endl;
		IntArrFill(arr, n);
		arr_sort_bubble(arr, n);
		cout << endl << "������ ������������ �� �����������" << endl;
		Print_arr(arr, n);
		cout << endl << "������ ������������ �� ��������" << endl;
		arr_revers(arr, n);
		Print_arr(arr, n);
	}
	//9. ���������� �� ������� ������������� ���������.
	void Zadacha80d()
	{
		int arr[5], n = 5, pos;
		cout << "������� " << n << " ��. ��������� �������: " << endl;
		IntArrFill(arr, n);
		for (int i = 0; i < n - 1; i++)
		{
			while (PosFirstElementInArray(arr, arr[i], n, i + 1, pos))
				ArrDeleleElement(arr, n, pos);
		}
		cout << "������ ��� ����������" << endl;
		Print_arr(arr, n);
	}
	//10. �������� �� ������� ���������, ������������ �� ������ �������.
	void Zadacha81d()
	{
		int arr1[5], arr2[3], n = 5, n2 = 3, pos;
		cout << "������� " << n << " ��. ��������� ������� �������: " << endl;
		IntArrFill(arr1, n);
		cout << "������� " << n2 << " ��. ��������� ������� �������: " << endl;
		IntArrFill(arr2, n2);
		for (int i = 0; i < n2; i++)
		{
			while (PosFirstElementInArray(arr1, arr2[i], n, pos))
				ArrDeleleElement(arr1, n, pos);
		}

		cout << "������ 1 ��� �������� ������� 2:" << endl;
		Print_arr(arr1, n);
	}
	/*�������� 22.11.2022*/
	void Zadacha42()
	{
		//������������� ������ ������ ��� ��������, ����� ������, ����������
	}

	/*�������� 29.11.2022*/
	//�������� ������� ������������ ���������� ���������� ��������� ��������� ������������� ���������
	using ulong = unsigned long long; //���� ���
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
		if (n == 0) //������� �������
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
		cout << "������� N=";
		cin >> N;
		cout << Do_fact(N);
	}

	// ����������� ����� ������� � ��������������� �������.���� ������� �� ������ ���������� - 1; �� ������ ��������� ������
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
		cout << "������� N ��� ������" << endl;
		cin >> N;
		cout << "������� �������� ��������" << endl << SearchInArr(arr, N, 0, 9);

	}

	//���������� ����������
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

		cout << "������� ���-�� ���������" << endl;
		cin >> n;

		cout << "������� ��� � �������: " << endl;
		for (int i = 0; i < n; i++)
		{
			cin >> N >> P;
			name[i] = new char[strlen(N) + 1];
			strcpy(name[i], N);
			phone[i] = new char[strlen(P) + 1];
			strcpy(phone[i], P);
		}

		cout << "������� ��� � ������� ��� ������" << endl;
		cin >> N >> P;
		replace_phone(name, phone, n, N, P);
		for (int i = 0; i < n; i++)
			cout << name[i] << " " << phone[i] << endl;
	}

	//�������� ����������� ������� ��������� N-�� ������� ������������������ ���������
	int fib(int n)
	{
		if (n <= 2)
			return 1;
		else
			return(fib(n - 1) + fib(n - 2));
	}

	/*�������� ������� �� 29.11.2022*/
	//����������������
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
		cout << "������� ���-�� ����� � �������� N, " << endl;
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

		cout << "��� ������: " << endl;
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
		cout << "������ ����� ����������������: " << endl;
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
	//���������� ������
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
		cout << "������� ���-�� ����� � �������� N, " << endl;
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

		cout << "��� ������: " << endl;
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
		cout << "������ ����� ����������������: " << endl;
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
	//����� ������
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
		cout << "������� ������" << endl;
		cin.getline(str, 20);
		cout << "������� ������� � ���-�� ��������" << endl;
		cin >> pos >> kol;
		str = Zadacha84d_func(str, pos, kol);
		cout << "����������� ������" << endl << str;
		delete[] str;
	}
	//�������� ����� ������
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
		cout << "������� ������: " << endl;
		cin.getline(S, 100);
		cout << "������� ���-�� �������� ��� ��������: " << endl;
		cin >> kol;
		cout << "������� ������� ������ ��������: " << endl;
		cin >> pos;
		S = Zadacha85d_del2(S, kol, pos);
		cout << "�������� ������" << S;
		delete[] S;
	}
	//��������														//�� ��� ��������
	void Zadacha86d()
	{
		int n;
		cout << "������� ����� n" << endl;
		cin >> n;
		cout << "�������� Fn ����� ���������" << fib(n);

	}
	//�������������													//�� ��� ��������
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

		cout << "������� �������� �������" << endl;
		while (!cin.eof())
			cin >> arr[n++];
		n--;
		a = Zadacha87d_funk_v1(arr, n, size1, size2);
		cout << "������ ������������� �����" << endl;
		IntArrPrint(a[0], size1);
		cout << "������ ������������� �����" << endl;
		IntArrPrint(a[1], size2);
		delete[] a[0];
		delete[] a[1];
		delete[] a;

	}
	//������������ ����������(��������)
	/*��.� Header //struct Zadacha88d_Trec { int phone; float dt; };*/
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
		cout << "������� ����� ������ ����� �������� � ������������ ���" << endl;
		while (!cin.eof())
			cin >> arr[n].phone >> arr[n].dt, n++;
		n--;

		cout << endl << "��������� ��� ����������" << endl;
		arr = Zadacha88dDlit(arr, n);
		for (i = 0; i < n; i++)
			cout << arr[i].phone << "\t" << arr[i].dt << endl;

		delete[] arr;
	}
	//���������-��������
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
		char str[] = "� ���� ����� �� ���� �����";
		int l = strlen(str);
		cout << (Zadacha89d_func(str, 0, l - 1) ? "�� ��� ���������" : "��� �� ���������");
	}
	//������*
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
		cout << "������� ����� ����� � ��� �������" << endl;
		cin >> M;
		for (i = 0; i <= 6560; i++)
		{
			a = convert10to3(i, a);
			if (Zadacha90d_calc(a) == M)
				Zadacha90d_print_result(a);
		}

		delete[] a;
	}
	//����*
	int Zadacha91Track(char** a, int& rows, int& columns, int& sr, int& sc, int step = -1)
	{
		int route = -1;
		char r, l, u, d;
		a[sr][sc] = '*';
		step++;
		if (step > 1000)
		{
			cout << "������� ����� ����� :(";
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
			cout << "��������� ��������" << endl;
			CharArr2DinamicPrint(arr, s, s, ' ');
		}
		else
			cout << "�������� �� �������� :-(";

		for (i = 0; i < s; i++)
			delete[] arr[i];
		delete[] arr;
	}

	/*�������� 06.12.2022*/
//����� ����������� ������������ ������� ��� ��������� �
	double binSearch(double a, double b, double eps, double (*f)(double))
	{
		double sr = (a + b) / 2;
		if (f(sr) == 0 || (b - a) <= eps)
			return sr;
		if (f(a) * f(sr) < 0)  // ��������� ���� ����� �� ������ �����, ���� ����� ������ �� ����� ������ ����.
			return binSearch(a, sr, eps, f);
		else
			return binSearch(sr, b, eps, f);
	}
	double Zadacha46_f(double x)
	{
		return sin(x); // �������� ���������
	}
	void Zadacha46()
	{
		double a = 1, b = 4, eps = 0.0001;
		double res = binSearch(a, b, eps, Zadacha46_f);
		cout << res;
	}
	//����� ���������� ����� � ����������� ����� ���������
	int Zadacha47_f(int n)
	{
		if (n <= 9)
			return n;
		return n % 10 > Zadacha47_f(n / 10) ? (n % 10) : Zadacha47_f(n / 10);
	}
	void Zadacha47()
	{
		int n;
		cout << "������� ����� n: ";
		cin >> n;
		cout << "������������ ����� �����: " << Zadacha47_f(n);
	}
	//� ����������  �������� ������������ ������� n*m, ������� �� ��� ��� ������ ���������� ������������� ��������.
	int** Zadacha48_funk(int** M, int* n, int m)   //n - ���-�� ����� m - ���-�� ��������
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
		cout << "������� ���-�� ����� � ��������" << endl;
		cin >> n >> m;

		M = new int* [n];
		for (i = 0; i < n; i++)
			M[i] = new int[m];
		for (i = 0; i < n; i++)
			for (j = 0; j < m; j++)
				cin >> M[i][j];
		M = Zadacha48_funk(M, &n, m);
		cout << "�������������� �������" << endl;
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

	/*�������� 13.12.2022*/
//�������� ������ � ����������� ���� ������� ��� ������������� ������� ����� � �������� � �������������� ����
	void Zadacha49()

	{
		char s[100];
		cout << "������� ������" << endl;
		cin.getline(s, 100);
		while (strstr(s, "  "))
		{
			strcpy(strstr(s, "  "), strstr(s, "  ") + 1);//���� �������� � ������.
		}
		if (s[0] == ' ') strcpy(s, s + 1);
		if (s[strlen(s)] == ' ') s[strlen(s)] = '\0';
		cout << s;
	}
	void Zadacha49_string()
	{
		string s;
		cout << "������� ������ ���������� ������� �������" << endl;
		getline(cin, s);// s = " " + s + " " (����� �������� ��� � ������ ������� � ������ � �����)
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
	//���� ������ � ���������� �����, ����������� �� �����.
	void Zadacha50()
	{
		char s[100];
		cout << "������� ������: " << endl;
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
		cout << "������� ������: " << endl;
		getline(cin, s);
		int b = 0;//������ �������� �����
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
		char Raz[] = " ,.-\t\n";//������ ������������
		char* word = NULL;
		char* next_word = NULL;
		cin.getline(s, 100);
		cout << "�����: " << endl;
		word = strtok_s(s, Raz, &next_word);//������ ��� ����, ������� �� ������ ����. _S-����������
		while (word != NULL)
		{
			cout << word << endl;//delete[] word;
			word = strtok_s(NULL, Raz, &next_word);
		}
	}
	//������� � ������ ��� ����� ���������� �������� #.
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
		cout << "������� � ������� " << endl;
		for (int i = 0; i < w.size(); i++)
		{
			cout << w[i] << endl;
		}
		cout << "��������� ������ " << endl;
		cout << str;
	}
	//���� ������, ��� ����� �������� ��������, ������� ����� �������� � ����������.
	void Zadacha52()
	{
		string s, word;
		cout << "������� ������: \0" << endl;
		getline(cin, s);
		cout << "������� �����: \0" << endl;
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
		cout << "��������� ������: \0" << endl;
		cout << s;
	}
	//������ �������! ������� ��������� ����� �� ���-�� ������ ����� �� ������ �� ��������� 6 �����
	void Zadacha53()
	{
		int a, b, c, d, f, g;
		cout << "������� ����� �����" << endl;
		cin >> a >> b >> c >> d >> f >> g;
		if (((a & 1) + (b & 1) + (c & 1) + (d & 1) + (f & 1) + (g & 1)) == 3)
		{
			cout << "���������" << endl;
		}
		else
		{
			cout << "�� ���������" << endl;
		}
	}

	/*�������� ������� �� 13.12.2022*/
//��������� �����
	void Zadacha92d()
	{
		string s1, s2;
		cout << "������� ������ ������: " << endl;
		cin >> s1;
		cout << "������� ������ ������: " << endl;
		cin >> s2;

		cout << "������� ������" << endl << (s1.length() > s2.length() ? s1 : s2) << endl;
		cout << "������� �� ��������: " << endl << (s1 < s2 ? s1 : s2) << endl << (s1 > s2 ? s1 : s2);
	}
	//�������� �������
	void Zadacha93d()
	{
		char s1[100];
		char _s;
		char* sy = NULL;
		char* next_word = NULL;
		string s2;
		string::size_type p;

		cout << "������� ������ � S1: " << endl;
		cin.getline(s1, 99);

		cout << "������� ������ � S2: " << endl;
		getline(cin, s2);

		cout << "������� ������ ��� ��������" << endl;
		cin >> _s;

		//��� char
		sy = strchr(s1, _s);//������ ��� ����, ������� �� ������ ����. _S-����������
		while (sy != NULL)
		{
			while (*sy != '\0')
			{
				*sy = *(sy + 1);
				sy++;
			}
			sy = strchr(s1, _s);
		}
		cout << "������ Char � ���������� ����������" << endl << s1 << endl;

		//��� string
		p = s2.find(_s);
		while (p != string::npos)
		{
			s2.erase(p, 1);
			p = s2.find(_s);
		}
		cout << "������ Char � ���������� ����������" << endl << s2 << endl;
	}
	//������� ���������
	void Zadacha94d()
	{
		int i;
		char s1[100]; char _s1[100];
		string s2, _s2;
		cout << "������� ������" << endl;
		cin.getline(s1, 99);

		s2 = s1;

		//��� char
		strcpy(_s1, s1);
		revers_char_arr(_s1);
		if (!strcmp(s1, _s1))
			cout << "������� Char. ������ �������� �����������" << endl;
		else
			cout << "������� Char. ������ �� �������� �����������" << endl;

		//��� string
		_s2 = s2;
		reverse(_s2.begin(), _s2.end());
		if (s2 == _s2)
			cout << "������� String. ������ �������� �����������" << endl;
		else
			cout << "������� String. ������ �� �������� �����������" << endl;
	}
	//����� ������ � �������
	void Zadacha95d_func(char arr[][20], int size, char raz[])
	{
		int i;
		char* p = nullptr;
		for (i = 0; i < size; i++)
		{
			p = strpbrk(arr[i], raz);
			if (p != NULL)
				if (p == &arr[i][0])
					cout << "������ ������ " << *p << " ����������� � ������ ������" << "\t" << arr[i] << endl;
				else if (p == &arr[i][strlen(arr[i]) - 1])
					cout << "������ ������ " << *p << " ����������� � ����� ������" << "\t" << arr[i] << endl;
				else
					cout << "������ " << *p << " ����������� � �������� ������" << "\t" << arr[i] << endl;
		}
		p = nullptr;
	}
	void Zadacha95d()
	{
		char arr[5][20] = { "#������1", "������, 2", "����-��3", "������4 :", "#������ 5;" };
		char raz[50];
		int size = 5;
		cout << "������� ������ �� �������" << endl;
		cin.getline(raz, 50);
		Zadacha95d_func(arr, size, raz);

	}
	//������� �������
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

		cout << "������� ������ ������" << endl;
		cin.getline(s1, 99);
		cout << "������� ������ ������" << endl;
		cin.getline(s2, 99);
		s = strcatnewmy(s1, s2);
		cout << "��������� ������: " << endl << s;

		delete[] s;
	}
	//������� ����
	void Zadacha97d()
	{
		char instr[20];
		char* sum = nullptr;
		cout << "������� ������ ��� �������" << endl;
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
		cout << "����� �����: " << sum;
		delete[] sum;
	}
	//����������� �� �������
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

		cout << "������� ������ ��� ���������� � ������, # ��� ������� �����������" << endl;
		getline(cin, str);
		while (!cin.eof())
		{
			Zadacha98d_funk(w, str);
			//cin.ignore(std::cin.rdbuf()->in_avail());
			getline(cin, str);
		}

		cout << endl << "������ ����������� � �������" << endl;
		for (int i = 0; i < w.size(); i++)
		{
			cout << *(w.at(i)) << endl;
			delete w.at(i);
		}
	}
	//����������
	//struct Zadacha99d_dec { char* w; char* t; };
	void Zadacha99d()
	{
		int N, i = 0;
		char* str = nullptr;
		cout << "������� ���-�� ����� N" << endl;
		cin >> N;
		Zadacha99d_dec* arr = new Zadacha99d_dec[N];

		cout << "������� ���� ���� ����� �����" << endl;
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

		cout << "�������� ��������� ����:" << endl;
		for (i = 0; i < N; i++)
		{
			cout << "�����: " << arr[i].w << "\t �������: " << arr[i].t << endl;
			delete[] arr[i].w;
		}
		delete[] arr;
	}
	//����� �����
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
		cout << "������� ������ � ������� ����� �������������� �����" << endl;
		getline(cin, source_str);
		cout << "������� ����� ��� ������" << endl;
		getline(cin, find);
		answer = SearchStrInStr(source_str, find);

		if (!answer.empty())
			cout << "C���� ������� :)";
		else
			cout << "C���� �� ������� :(";
	}
	//�������
	void Zadacha101d()
	{
		Zadacha51();
	}
	//������� ����������
	void Zadacha102d()
	{
		string s, num1, num2, sum_num, tmp;
		int sum, i1, i2, raz = 0;
		char c;
		sum_num = "";
		cout << "������� ������, ���������� �������� �������� ���� ����� �����" << endl;
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

		//������������ ������ cstring.h, cstring. ������ string <string>
	}
	//���������� ������ �������
	void Zadacha103d()
	{
		int N;
		string family;
		vector<char*> family1;
		vector<string> family2;

		//������ �������� ������
		cout << "������� ����� ������� N: " << endl;
		cin >> N;
		cout << "������� �������" << endl;
		cin.get();
		while (N-- > 0)
		{
			getline(cin, family);
			family1.push_back(strdup(&family[0]));
			family2.push_back(strdup(&family[0]));
		}


		//����������
		sort(family1.begin(), family1.end(), [](const char* s1, const char* s2) {return strcmp(s1, s2) <= 0; });
		sort(family2.begin(), family2.end(), [](const string s1, const string s2) {return strcmp(&s1[0], &s2[0]) <= 0; });

		//�����
		cout << endl << "��������� ��������� ������ char*:" << endl;
		for (unsigned int i = 0; i < family1.size(); i++)
			cout << family1[i] << endl;
		cout << endl << "��������� ��������� ������ string:" << endl;
		for (unsigned int i = 0; i < family2.size(); i++)
			cout << family2[i] << endl;

		//������� ������� char*;
		for_each(family1.begin(), family1.end(), [](char* s) {delete[] s; });
	}
	//������ ��������������� ���������
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
		cout << "������� ������ ��� ������ ���������� ��������� �� ������� + � - " << endl;
		getline(cin, s);
		//�������� ������ ����� ��� ��������
		token = strcspn(&s[0], seps);
		if (token != -1)
		{
			s[token] == '+' ? znak = '+' : znak = '-';
			sum_num.assign(&s[0], token);
			s.assign(&s[0], token + 1, s.length() - token - 1);
		}
		else
		{
			cout << "	��� ���������� + � - " << endl;
			return;
		}

		//���� ��������� ��������
		token = strcspn(&s[0], seps);
		while (1)
		{
			//�������� �����(� ���� ������) ��� ��������
			if (token != s.length())
				num.assign(&s[0], token);
			else
				num = s;
			//������ � ������� �������� � ����������� �� ������ + � -
			if (znak == '+' && sum_num[0] != '-')
				sum_num = funcPLUS(sum_num, num);
			else if (znak == '+' && sum_num[0] == '-')
				sum_num = funcMINUS(num, sum_num.erase(0, 1));
			else if (znak == '-' && sum_num[0] != '-')
				sum_num = funcMINUS(sum_num, num);
			else
				sum_num = '-' + funcPLUS(num.erase(0, 1), sum_num.erase(0, 1));
			//������� �� ����� ���� �������� �� ������
			if (token == s.length())
				break;
			s[token] == '+' ? znak = '+' : znak = '-';
			s.assign(&s[0], token + 1, s.length() - token - 1);
			//���� ��������� ���������� ��������� + ��� -
			token = strcspn(&s[0], seps);
		}
		cout << "����� �����: " << endl << sum_num << endl;
	}

	/*�������� 20.12.2022*/
//���������� �����
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
		static Tchar_vect w; //������ ��� �������� �����
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
		cout << "������� ������ ������ ����� Enter � ������ ������ ��� ����������" << endl;
		while (1)
		{
			cout << "������:" << endl;
			cin.getline(buff, 1000);
			if (!strlen(buff))
				break;
			wcount = StrToWords(buff, Razd, words);
			cout << "��������" << wcount << "����" << endl;
		}

		int sort_type;
		cout << "������� � ����� ����������� ���������: 1(����.),-1(����.)" << endl;
		cin >> sort_type;
		if (sort_type == 1)
			sort(words.begin(), words.end(), words_cmp1);
		else
			sort(words.begin(), words.end(), words_cmp2);

		//���������� ����� ������ ���������
		sort(words.begin(), words.end(), [sort_type](const char* s1, const char* s2) {return sort_type * strcmp(s1, s2) <= 0; });

		//�����
		cout << "����� ����������: " << endl;
		for (unsigned int i = 0; i < words.size(); i++)
			cout << words[i];

		//����� ����� ������ ���������
		for_each(words.begin(), words.end(), [](char* s) {cout << s << endl; });

		//������� �������
		for_each(words.begin(), words.end(), [](char* s) {delete[] s; });
	}

	/*�������� 27.12.2022* ������ � �������*/
//������� ����� �� �������������, ����, ���. ����� �� ���. ������������ �����
	void Zadacha55(int argc, char* argv[])
	{
		int e, v, g, sum_e = 0, sum_v = 0, sum_g = 0, i, max_sum = 0, max_month;
		//setlocale(LC_ALL, "rus");
		ifstream fin;
		ofstream fout;
		char name[20];

		if (argc < 3)
		{
			cout << "��� ������ � ������" << endl;
			return;
		}

		fin.open(argv[1]);
		if (!fin)
		{
			cout << "���� " << argv[1] << " �� ������" << endl;
			return;
			//exit(0);
		}

		//cout << "������� ��� �������� �����" << endl;
		//cin >> name;
		//do
		//{
		//	cout << "������� ��� ��������� �����" << endl;
		//	cin >> name;
		//	fin.open(name);
		//	if (!fin)
		//		cout << "���� �� ������, ������� ������";
		//} while (!fin);



		//cout << "������� ��� ��������� �����" << endl;
		//cin >> name;
		//fout.open(name);
		fout.open(argv[2]);
		for (i = 1; i <= 12; i++)
		{
			fin >> e >> v >> g;
			sum_e += e;
			sum_v += v;
			sum_g += g;
			//���������� ����� ����� ������� ���� ������ �����
			if (e + v + g > max_sum)
			{
				max_sum = e + v + g;
				max_month = i;
			}
		}
		cout << "����� �� ���: " << endl <<
			"�������������: " << "\t " << sum_e << endl <<
			"����: " << "\t " << sum_v << endl <<
			"���: " << "\t " << sum_g << endl <<
			"��������� �������:" << sum_e + sum_v + sum_g << endl <<
			"������ ����� ���� ���������: " << max_sum << ", � ������ " << max_month;
		fout << "����� �� ���: " << endl <<
			"�������������: " << "\t " << sum_e << endl <<
			"����: " << "\t " << sum_v << endl <<
			"���: " << "\t " << sum_g << endl <<
			"��������� �������:" << sum_e + sum_v + sum_g << endl <<
			"������ ����� ���� ���������: " << max_sum << ", � ������ " << max_month;
		fin.close();
		fout.close();
	}
	//��� ��������� ����. ���������� ���-�� ��������� ���� ��������� �������� � ����
	void Zadacha56()
	{
		ifstream fin;
		ofstream fout;
		char s[20];
		char c;
		int arr[26] = { 0 };
		do
		{
			cout << "������� ��� �������� �����" << endl;
			cin >> s;
			fin.open(s);
			if (!fin)
				cout << "���� �� ������, ������� ������" << endl;
		} while (!fin);
		cout << "������� ��� ��������� �����" << endl;
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
		fout << "�����\t" << "���-�� ���������" << endl;
		for (int i = 0; i < 26; i++)
			fout << (char)('a' + i) << "\t" << arr[i] << endl;
		fin.close();
		fout.close();
	}
	//��������� � ����� ��� ���������� ����� �� ��������� � �������, � ������� �� ��������� ��� ������
	void Zadacha57()
	{
		ifstream fin;
		ofstream fout;
		char sn[20];
		string s;
		do
		{
			cout << "������� ��� �������� �����" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "���� �� ������, ������� ������" << endl;
		} while (!fin);
		cout << "������� ��� ��������� �����" << endl;
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
	//��������� � ����� ��� ���������� ����� �� ��������� � �������, � ������� �� ��������� � ������
	void Zadacha58()
	{
		//� �������
		ifstream fin;
		ofstream fout;
		char sn[100];
		char s[100];
		do
		{
			cout << "������� ��� �������� �����" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "���� �� ������, ������� ������" << endl;
		} while (!fin);
		cout << "������� ��� ��������� �����" << endl;
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
	//��������� � ����� ��� ���������� ����� �� ��������� � �������, � ������� �� ��������� � ������ � string
	void Zadacha59()
	{
		//��� ������
		ifstream fin;
		ofstream fout;
		char sn[100];
		string s;
		do
		{
			cout << "������� ��� �������� �����" << endl;
			cin >> sn;
			fin.open(sn);
			if (!fin)
				cout << "���� �� ������, ������� ������" << endl;
		} while (!fin);
		cout << "������� ��� ��������� �����" << endl;
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


	/*�������� 17.01.2023*/
//������� � �������������� ���-��� ����������, ������������ ������������ �������� ���������.
#define EOL -1    //��������� ���������� ��� EOL ��� -1
	void maxfinder(int* max, ...)
	{
		int maxval, num;
		va_list num_ptr;			//��������� �� ��������� �������
		va_start(num_ptr, max);		//��������� ��������� �� ������ ��������
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
		cout << "������������ �������� ����� = " << max << endl;
	}

#define TFUN(F) double (*F)(double)
#define TSHOW(F) void (*F)(double,double,double (*)(double)) //������� ��� ���������� ������������� �������� � �������� ��������� 
	//��������� �� �������
		/*����� ��������� F(c) ������ ���� �� �������[a, b] � ��������� �������.TSHOW ������� ������������� ��� ������ ��������������
		�������� � ������ ���������� ������. ������� ���������� 1 ��� ���������� �����, 0 ��� ��� ����������.*/
	int Root(double a, double b, double eps, TFUN(F), double& C, TSHOW(Show));
	//int Root(double a, double b, double eps, double(*f)(double), double& C, void (*Show)(double,double,double (*)(double))); 
	void (*Show)(double, double, double(*)(double));
	void ShowStep(double a, double b, TFUN(f));
	void ShowEmpty(double a, double b, TFUN(f)) //�� ����������� ������� F ����� �����
	{

	}
	int Root(double a, double b, double eps, TFUN(F), double& C, TSHOW(Show))
	{
		if (F(a) * F(b) > 0)
			return 0; //��� ������
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
		cout << "\n������� ������:\t"
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
		//������ �������
		if (Root(1.5, 3.1, 0.001, Arf[0], x, ShowStep))
			cout << endl << "������ ����� = " << x << endl;
		else
			cout << "������ ���" << endl;
		//������ �������
		if (Root(1.5, 3.1, 0.001, Arf[1], x, ShowEmpty))
			cout << "������ ����� = " << x << endl;
		else
			cout << "������ ���" << endl;
	}

	//��������� ����
	void Zadacha62()
	{
		unsigned int a = 15;	//1111
		unsigned int b = 17;	//10001
		unsigned int c = a & b; //=1       � - ���� ���� �� ���� 0 �� 1 (0 ��� 1 ���� 0, 1 � 1 ���� 1)
		c = a | b;				//=11111   ��� - ���� ���� �� ���� 1 �� 1 (0 ��� 1 ���� 1)
		unsigned int n = 2;
		c = a << n;				//=111100  ����� ����� - �������� �����, ������ �������������� ������ ����������� 0, �� ��� ������� �� ������� ���������.
		n = 3;
		c = a >> n;				//=1 ����� ������ - ���������� ������ ����� ������ � ������ �������
		c = a ^ b;				//=30 ����������� ��� - ���� ���� ���������� �������� 0 ���� ������ �� ��������.
		c = ~b;					//=4294967278 �������� - ������ ������ 1 �� 0, � 0 �� 1
		cout << c << endl;

		cout << a << '\t' << b << endl;
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
		cout << a << '\t' << b << endl;

	}

	/*�������� ������� 17.12.2023*/
	void Zadacha105d()
	{
		bool (*f)(void) = Z105d_VarSort;
		vector<Z105d_TDate>vd;
		unsigned short D[3];
		cout << "������� ����(���� ����� ���) � ������� 30 12 22, ��� ������ ������� CTRL+Z � Enter" << endl;
		while (1)
		{
			fill(&D[0], &D[2],0);
			cin >> D[0] >> D[1] >> D[2];
			if (cin.eof()) break;
			if (D[0] + D[1] + D[2])
				vd.push_back({{D[0]},{D[1]},{D[2]}});
		}
		Z105d_SortDate(vd, f);
		cout << endl << "��������������� ������ ��������: " << endl;
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
				if (Z105d_�ompTDate(vd[j], vd[j + 1], compare))
					swap(vd[j], vd[j + 1]);
			}
		return;
	}
	bool Z105d_VarSort()
	{
		cin.clear();
		cout << endl << "������� ��� ���������� 0 - �� �����������, 1 - �� ��������" << endl;
		return cin.get();
	}
	bool Z105d_�ompTDate(const Z105d_TDate& i1, const Z105d_TDate& i2,const bool& compare)
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
#pragma once
#include <iostream>
#include <string>
#include <map>
//#include <memory>
#include <fstream>
#include <algorithm>
#include <vector>


using namespace std;
#define ML 10
static string objects[ML] = { "������","��������","�������","���������",
						"��������������","�����������","�����","�������","��������������","�����������"};

//ifstream fin("FalseExam.txt");
//ofstream fout("FalseExam.txt");
//ifstream gin("Grants.txt");
//ofstream gout("Grants.txt");
struct students
{
	string Surname;				//������� ��������
	map<std::string, int> exam;		//������ �� ��������
	
	students(string sur);
	void add_grade();
	void fill_group(vector<students>& group);

};
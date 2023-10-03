#include <cstring>
#include <fstream>
#include <iostream>
#include "NOTEB.h"

using namespace std;
namespace NOTEB
{
	static fstream* Arch;
	static bool Full_screening;
	void set_mode_screening(bool full_screening)
	{
		full_screening = full_screening;
	}
	int notebook_open(char* file_name)
	{
		Arch = new(nothrow)fstream(file_name, ios::binary | ios::in | ios::out); //��������� ��� ������ | ios::binary |
		if (!Arch)  //�� �������� ������
			return 0;
		if (!(*Arch)) //��� �������� � �����
		{
			delete Arch;

			Arch = nullptr;
			return -1;
		}
		return 1; //��� ������
	}
	void notebook_close()
	{
		if (Arch)
		{
			if (*Arch)
				Arch->close(); // -> ������������ (*Arch).close() �.�. ������������ � ����������� �������� � ����.
			delete Arch;
			Arch = nullptr;
		}
	}
	bool person_input(TPerson* man)
	{
		cout << "������� �.�.�(��� ������ �����): ";
		cin.getline(man->fio, LENFIO);
		if (strcmp(man->fio, ".") != 0)
		{
			cout << "������� ����� ��������: ";
			cin >> man->phone;
			cin.get();
		}
		return strcmp(man->fio, ".");
	}
	void person_display(const TPerson& man)
	{
		cout << "\t\t ���������� � ������ � ���������� �����" << endl;
		cout << "\t �.�.�. " << man.fio;
		cout << "\t ����� �������� " << man.phone;
	}
	void add_to_notebook()
	{
		TPerson man;
		bool flag;
		cout << "\t\t ���������� � ���������� �����" << endl;
		Arch->seekp(0, ios::end); //��������� �� ����� ������;
		while (1)
		{
			flag = person_input(&man);
			if (!flag) //if(flag==0)
				break;
			void* p = &man; //������������� ������
			Arch->write((char*)p, sizeof(TPerson)); //Arch->write((char*)&man, sizeof(TPerson));
			Arch->flush(); //����� ������ � ����
		}
	}
	void notebook_display()
	{
		TPerson man;
		void* p = &man;
		cout << "\t\t �������� ���������� �����" << endl;
		Arch->seekg(0, ios::beg);
		do
		{
			Arch->read((char*)p, sizeof(TPerson));
			if (Arch->eof())
			{
				cout << endl << "\t ����� �����" << endl;
				break;
			}
			int pos = Arch->gcount();
			if (pos == sizeof(TPerson))
			{
				if (!man.fio[0] && !Full_screening)
					continue;
				else
					person_display(man);
			}

		} while (!Arch->eof());
		Arch->clear();
		Arch->ignore(Arch->rdbuf()->in_avail());
	}
	int search_person(char* title) //����� �������
	{
		int search = 0;
		TPerson man;
		void* p = &man;
		cout << "\t\t ����� �������� � ���������� �����" << endl;
		Arch->seekg(0, ios::beg);
		do
		{
			Arch -> read((char*)p, sizeof(TPerson));
			if (Arch->eof())
			{
				cout << endl << "\t ����� �����" << endl;
				break;
			}
			int pos = Arch->gcount();
			if (pos == sizeof(TPerson))
			{
				if (strcmp(man.fio, "") != 0 && strstr(man.fio, title) != NULL)
				{
					search++;
					person_display(man);
				}
			}
		} while (!Arch->eof());
		Arch->clear();
		Arch->ignore(Arch->rdbuf()->in_avail());
		return search;
	}
	int delete_person(char* title)
	{
		int search = 0;
		TPerson man;
		void* p = &man;
		cout << "\t\t �������� �������� �� ���������� �����" << endl;
		Arch->seekg(0, ios::beg);
		do
		{
			Arch->read((char*)p, sizeof(TPerson));
			if (Arch->eof())
			{
				cout << endl << "\t ����� �����" << endl;
				break;
			}
			int pos = Arch->gcount();
			if (pos == sizeof(TPerson))
			{
				if (strcmp(man.fio, title) == 0)
				{
					search++;
					long pos; //pos - ���������, �� ����� ��������� � int pos
					pos = Arch->tellg();
					pos -= sizeof(TPerson);
					Arch->seekp(pos);
					man.fio[0] = '\0';
					Arch->write((char*)p, sizeof(TPerson));
					Arch->flush();
					break;
				}
			}
		} while (!Arch->eof());
		if (Arch->eof())
		{
			Arch->clear();
			Arch->ignore(Arch->rdbuf()->in_avail());
		}
		return search;
	}
}
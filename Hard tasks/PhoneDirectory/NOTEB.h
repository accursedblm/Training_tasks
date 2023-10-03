#pragma once

namespace NOTEB
{
	const int LENFIO = 30;
	using TPerson = struct personrec
	{
		char fio[LENFIO];
		int phone;
	};
	enum Action { ADD = 1, PRINT, SEARCH, DEL, CLOSE };
	int notebook_open(char* file_name); //Открытие справочника
	void notebook_close();
	bool person_input(TPerson* man);
	void person_display(const TPerson& man);
	void notebook_display();
	int search_person(char* title);
	int delete_person(char* title);
	void add_to_notebook();
	void set_mode_screening(bool full_screening);
}

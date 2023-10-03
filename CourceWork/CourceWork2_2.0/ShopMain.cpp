#include <ctime>
#include "TShop.h"
#include "RusConsole.h"

enum Action { ADD = 1, LOAD, SAVE, PRINT, CLEAR, DEL_EL, SAVE_MATH, CLOSE };

using namespace std;
int main()
{
	RusCon(); //Русифицируем консоль
	TShop Mag;
	time_t now;
	cout << "Добро пожаловать в зачетное задание Печникова Виктора Константиновича :)" << endl;
	int nsel = 0;
	do
	{
		cout << "Меню: \t1-ДобавитьЗаказ,2-ЗагрузитьФайл,3-СохранитьФайл,4-ВывестиВКонсоль," << endl
			<< "\t5-ОчиститьВсеЗаказы,6-УдалитьЗаказ,7-СохранитьЗадание,8-Выйти" << endl;
		cin >> nsel;
		cin.get();
		switch (Action(nsel))
		{
		case Action::ADD:
			float prc;
			cout << "Введите цену заказа: ";
			cin >> prc;
			cin.get();
			now = time(0);
			tm ltm;
			localtime_s(&ltm, &now);
			Mag.AddOrder(ltm.tm_hour, ltm.tm_min, prc);
			break;
		case Action::LOAD:
			Mag.ImportFromFile("Orders.txt");
			break;
		case Action::SAVE:
			Mag.ExportToFile("Orders.txt");
			break;
		case Action::PRINT:
			cout << Mag;
			break;
		case Action::CLEAR:
			Mag.ClearALLOrders();
			break;
		case Action::DEL_EL:
			int ind;
			cout << "Введите индекс заказа для удаления - ";
			cin >> ind;
			Mag.DeleteOrder(ind);
			break;
		case Action::SAVE_MATH:
			Mag.ExportToFileZadanie("OrdersMath.txt");
			break;
		default:
			if (nsel != Action::CLOSE)
				cout << "Неправильный номер функции, попробуйте еще раз :)" << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (nsel != int(Action::CLOSE));

	cout << endl << "Спасибо за внимание :)" << endl;
	system("pause");
	return 0;
}
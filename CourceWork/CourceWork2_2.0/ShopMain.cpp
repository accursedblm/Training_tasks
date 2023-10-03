#include <ctime>
#include "TShop.h"
#include "RusConsole.h"

enum Action { ADD = 1, LOAD, SAVE, PRINT, CLEAR, DEL_EL, SAVE_MATH, CLOSE };

using namespace std;
int main()
{
	RusCon(); //������������ �������
	TShop Mag;
	time_t now;
	cout << "����� ���������� � �������� ������� ��������� ������� ��������������� :)" << endl;
	int nsel = 0;
	do
	{
		cout << "����: \t1-�������������,2-�������������,3-�������������,4-���������������," << endl
			<< "\t5-�����������������,6-������������,7-����������������,8-�����" << endl;
		cin >> nsel;
		cin.get();
		switch (Action(nsel))
		{
		case Action::ADD:
			float prc;
			cout << "������� ���� ������: ";
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
			cout << "������� ������ ������ ��� �������� - ";
			cin >> ind;
			Mag.DeleteOrder(ind);
			break;
		case Action::SAVE_MATH:
			Mag.ExportToFileZadanie("OrdersMath.txt");
			break;
		default:
			if (nsel != Action::CLOSE)
				cout << "������������ ����� �������, ���������� ��� ��� :)" << endl;
		}
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
	} while (nsel != int(Action::CLOSE));

	cout << endl << "������� �� �������� :)" << endl;
	system("pause");
	return 0;
}
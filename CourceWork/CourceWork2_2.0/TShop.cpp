#include "TShop.h"

TShop& TShop::AddOrder(int hour, int minutes, float price)
{
	std::pair<int, float> Order;
	Order.first = hour * 60 + minutes;
	Order.second = price;
	Orders.insert(Order);
	return *this;
}

TShop& TShop::DeleteOrder(int index)
{
	if (index > 0 && index < Orders.size() + 1)
	{
		auto iter = next(Orders.begin(),index-1);
		Orders.erase(iter);
	}
	return *this;
}

void TShop::ImportFromFile(const char* Path)
{
	std::ifstream fin;
	fin.open(Path);
	if (!fin)
	{
		std::cout << "�� ������� ������� ������� ���� :(" << std::endl;
		system("pause");
		exit(1);
	}
	fin >> *this;
	std::cout << "������ ������� ���������" << std::endl;
	fin.close();
}

void TShop::ExportToFile(const char* Path)
{
	std::ofstream fout;
	fout.open(Path);
	if (!fout)
	{
		std::cout << "�� ������� ������� �������� ���� :(" << std::endl;
		system("pause");
		exit(1);
	}
	fout << *this;
	std::cout << "������ ������� ��������� � ����" << std::endl;
	fout.close();
}

void TShop::ExportToFileZadanie(const char* Path)
{
	if (Orders.empty()) return;
	float sum = 0, sred;
	std::for_each(Orders.begin(), Orders.end(), [&sum](std::pair<int,float> i){sum += i.second;});
	sred = sum / Orders.size();
	std::ofstream fout;
	fout.open(Path);
	if (!fout)
	{
		std::cout << "�� ������� ������� �������� ���� ��� �������� ������� :(" << std::endl;
		system("pause");
		exit(1);
	}
	fout << "����� ���� ������� �����: " << sum << "���." << std::endl;
	fout << "������� ���� ������: " << sred << "���." << std::endl;
	std::cout << "������ ������� ��������� � ����" << std::endl;
	fout.close();
}

TShop& TShop::ClearALLOrders()
{
	if (!Orders.empty())
		Orders.clear();
	return *this;
}

std::ostream& operator << (std::ostream& out, TShop& T)
{
	if (!T.Orders.empty())
	{
		// ������� ��������, ���������� �� ������
		std::map<int, float>::iterator it = T.Orders.begin();

		// ���� �� �������
		while (it != T.Orders.end())
		{
			out << "�����_������ " << std::setfill('0') << std::setw(2) << it->first/60 << " : "
								   << std::setfill('0') << std::setw(2) << it->first % 60 
								   << " ���� " << it->second << std::endl;
			++it;
		}
	}
	out << std::endl;
	return out;
}

std::istream& operator >> (std::istream& in, TShop& T)
{
	char tmp[50];
	int hh, mm;
	float pp;
	while (1)
	{
		in >> tmp >> hh >> tmp >> mm >> tmp >> pp;
		if (in.eof()) 
			break;
		else
			T.AddOrder(hh, mm, pp);
	}
	return in;
}

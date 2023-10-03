#include "TShop.h"

void TShop::ResizeOrders()
{
	for (int i = 0; i < 5; i++)
		Orders.push_back(std::make_shared<sTime>());
}

TShop& TShop::AddOrder(int hour, int minutes, float price)
{
	if (Orders.size() == quantity)
		ResizeOrders();
	Orders[quantity++] = std::make_shared<sTime>(hour, minutes, price);
	return *this;
}

TShop& TShop::DeleteOrder(int index)
{
	//if (index == -1)
	//	index = quantity;
	if (index > -1 && index < quantity)
	{
		auto iter = Orders.begin() + index;
		Orders.erase(iter);
		quantity--;
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
	if (!quantity)
		return;
	float sum = 0, sred;
	std::for_each(Orders.begin(), Orders.begin() + quantity,
		[&sum](std::shared_ptr<TShop::sTime> i){sum += i->price;});
	sred = sum / quantity;
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
	if (!quantity)
		return *this;
	std::for_each(Orders.begin(), Orders.begin() + quantity,
		[](std::shared_ptr<TShop::sTime> i)
		{
			i->vs(0, 0); i->pr(0);
		});
	this->quantity = 0;
	return *this;
}

std::ostream& operator << (std::ostream& out, const TShop& T)
{
	if (!T.quantity)
		return out;
	std::for_each(T.Orders.begin(), T.Orders.begin() + T.quantity,
		[&out](std::shared_ptr<TShop::sTime> i)
		{
			out << "�����_������ " << (i->h < 10 ? "0" : "") << i->h << " : " 
								   << (i->m < 10 ? "0" : "") << i->m 
				<< " ���� " << i->price << std::endl;
		});
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

#include "TShop.h"

void TShop::ResizeOrders()
{
	for (int i = 0; i < 5; i++)
		Orders.insert(std::pair<int, std::shared_ptr<sTime>>(Orders.size(), std::make_shared<sTime>()));
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
	if (index > -1 && index < quantity)
	{
		auto iter = next(Orders.begin(),index);
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
		std::cout << "Не удалось открыть входной файл :(" << std::endl;
		system("pause");
		exit(1);
	}
	fin >> *this;
	std::cout << "Заказы успешно загружены" << std::endl;
	fin.close();
}

void TShop::ExportToFile(const char* Path)
{
	std::ofstream fout;
	fout.open(Path);
	if (!fout)
	{
		std::cout << "Не удалось открыть выходной файл :(" << std::endl;
		system("pause");
		exit(1);
	}
	fout << *this;
	std::cout << "Заказы успешно выгружены в файл" << std::endl;
	fout.close();
}

void TShop::ExportToFileZadanie(const char* Path)
{
	if (!quantity)
		return;
	float sum = 0, sred;
	std::for_each(Orders.begin(), next(Orders.begin(),quantity),
		[&sum](std::pair<int, std::shared_ptr<sTime>> i){sum += i.second->price;});
	sred = sum / quantity;
	std::ofstream fout;
	fout.open(Path);
	if (!fout)
	{
		std::cout << "Не удалось открыть выходной файл для выгрузки решения :(" << std::endl;
		system("pause");
		exit(1);
	}
	fout << "Сумма всех заказов равна: " << sum << "руб." << std::endl;
	fout << "Средняя цена заказа: " << sred << "руб." << std::endl;
	std::cout << "Заказы успешно выгружены в файл" << std::endl;
	fout.close();
}

TShop& TShop::ClearALLOrders()
{
	if (!quantity)
		return *this;
	std::for_each(Orders.begin(), next(Orders.begin(), quantity),
		[](std::pair<int, std::shared_ptr<sTime>> i)
		{
			i.second->vs(0, 0); i.second->pr(0);
		});
	this->quantity = 0;
	return *this;
}

std::ostream& operator << (std::ostream& out, const TShop& T)
{
	if (!T.quantity)
		return out;
	std::for_each(T.Orders.begin(), next(T.Orders.begin(), T.quantity),
		[&out](std::pair<int, std::shared_ptr<TShop::sTime>> i)
		{
			out << "Время_заказа " << i.second->h << " : " << i.second->m << " Цена " << i.second->price << std::endl;
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

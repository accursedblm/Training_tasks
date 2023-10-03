#pragma once
#include <memory>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>

class TShop
{

private:
	struct sTime
	{
		int h{}, m{};								//Часы, минуты
		float price{};								//Цена
		sTime() {};									
		sTime(int hh, int mm, float pp)
		{
			vs(hh, mm);
			pr(pp);
		}
		~sTime() {};
		int vs(int hh=-1,int mm=-1)					//Сет-геттер, отдает в формате время с начала суток в минутах
		{
			if (hh > -1 && hh < 24)
				h = hh;
			if (mm > -1 && mm < 61)
				m = mm;
			if (hh == -1 || mm == -1)
				return -1;
			return h * 60 + m;
		}
		float pr(float pp = -1)						//Сет-геттер, отдает цену
		{
			if (pp > -1)
				price = pp;
			else
				return -1;
		}
	};
	std::vector<std::shared_ptr<sTime>> Orders;	//Вектор умных указателей на структуру
	int quantity{};									//Индекс последнего занятого элемента
protected:
	void ResizeOrders();							//Изменить размер вектора заказов
public:
	TShop()
	{
		ResizeOrders();
	}
	~TShop() {}
	TShop(const TShop& T)
	{
		std::copy(T.Orders.begin(), T.Orders.begin() + T.quantity, back_inserter(Orders));
		quantity = T.quantity;
	}
	TShop& AddOrder(int hour, int minutes, float price);
	TShop& DeleteOrder(int index = -1);
	TShop& ClearALLOrders();
	friend std::ostream& operator << (std::ostream&, const TShop&);
	friend std::istream& operator >> (std::istream&, TShop&);
	void ImportFromFile(const char* Path);
	void ExportToFile(const char* Path);
	void ExportToFileZadanie(const char* Path);
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
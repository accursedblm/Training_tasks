#pragma once
#include <memory>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class TShop
{
private:
	std::multimap<int, float> Orders; //Ассоциативный массив
public:
	TShop() {}
	~TShop() {}
	TShop(const TShop& T) : Orders(T.Orders){}
	TShop& AddOrder(int hour, int minutes, float price);
	TShop& DeleteOrder(int index = -1);
	TShop& ClearALLOrders();
	friend std::ostream& operator << (std::ostream&, TShop&);
	friend std::istream& operator >> (std::istream&, TShop&);
	void ImportFromFile(const char* Path);
	void ExportToFile(const char* Path);
	void ExportToFileZadanie(const char* Path);
};


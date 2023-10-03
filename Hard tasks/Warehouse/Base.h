#pragma once
#include <iostream>
class Base
{
public:
	Base() {}
	virtual void Print(std::ostream& out = std::cout) = 0;
	virtual void Read(std::istream& in = std::cin) = 0;
};
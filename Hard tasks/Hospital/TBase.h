#pragma once
#include <iostream>
#include <string>
using namespace std;
class TBase
{
	virtual void read(istream& in) = 0;
	virtual void write(ostream& out) const = 0;
};


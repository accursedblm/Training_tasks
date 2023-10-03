#pragma once
#include <iostream>
template <class T>
class vec_iterator;

template <class T>
class Vec
{
	T* p;
	int size;
	friend class vec_iterator <T>;
public:
	Vec(int n = 10)
	{
		p = new T[n];
		size = n;
	}
	~Vec()
	{
		delete[] p;
	}
};


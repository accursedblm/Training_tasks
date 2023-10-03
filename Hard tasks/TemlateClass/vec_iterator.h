#pragma once
#include "Vec.h"

template<class T>
class vec_iterator
{
	Vec<T>* pv;
	int ind;
public:
	vec_iterator(Vec<T>& v):ind(), pv(&v) 
	{}
	void rewind()
	{
		ind = 0;
	}
	T& next();

	int end()
	{ return ind == (pv->size); }
};

template<class T>
T& vec_iterator<T>::next()
{
	if (ind == pv->size)
		return (pv->p[ind = 0]);
	else
		return (pv->p[ind++]);
}

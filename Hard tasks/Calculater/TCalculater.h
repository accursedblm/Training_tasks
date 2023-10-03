#pragma once
class TCalculater
{
private:
	float lastArg;
	float Result;
public:
	//конструкторы
	TCalculater(float res = 0)
	{
		lastArg = 0;
		Result = res;
	}
	TCalculater(const TCalculater& T)
	{
		lastArg = 0;
		Result = T.Result;
	}
	//Деструктор
	~TCalculater()
	{ }
	//Операторы
	float Add(float arg);
	TCalculater& operator +=(float arg);
	TCalculater& operator +=(TCalculater& T);
	TCalculater& operator -=(float arg);
	TCalculater& operator -=(TCalculater& T);
	TCalculater& operator *=(float arg);
	TCalculater& operator *=(TCalculater& T);
	TCalculater& operator /=(float arg);
	TCalculater& operator /=(TCalculater& T);
	float FlastArg()
	{
		return lastArg;
	}
	float FResult()
	{
		return Result;
	}
	void Clear()
	{
		Result = 0;
	}
	//Префиксный ++
	TCalculater& operator ++ ()
	{
		Add(1);
		return *this;
	}

	//Постфиксный ++
	TCalculater operator ++ (int)
	{
		TCalculater tmp = *this;
		Add(1);
		return tmp;
	}
};
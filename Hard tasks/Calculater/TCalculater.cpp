#include "TCalculater.h"

float TCalculater::Add(float arg)
{
	lastArg = Result;
	Result += arg;
	return Result;
}
TCalculater& TCalculater::operator +=(float arg)
{
	lastArg = Result;
	Result += arg;
	return *this;
}
TCalculater& TCalculater::operator +=(TCalculater& T)
{
	lastArg = Result;
	Result += T.Result;
	return *this;
}
TCalculater& TCalculater::operator -=(float arg)
{
	lastArg = Result;
	Result -= arg;
	return *this;
}
TCalculater& TCalculater::operator -=(TCalculater& T)
{
	lastArg = Result;
	Result -= T.Result;
	return *this;
}
TCalculater& TCalculater::operator *=(float arg)
{
	lastArg = Result;
	Result *= arg;
	return *this;
}
TCalculater& TCalculater::operator *=(TCalculater& T)
{
	lastArg = Result;
	Result *= T.Result;
	return *this;
}
TCalculater& TCalculater::operator /=(float arg)
{
	lastArg = Result;
	Result /= arg;
	return *this;
}
TCalculater& TCalculater::operator /=(TCalculater& T)
{
	lastArg = Result;
	Result /= T.Result;
	return *this;
}
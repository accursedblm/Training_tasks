#include "TRoom.h"

TRoom DoRoomCopy(TRoom R)
{
	return R;
}

TRoom& DoRoomCopy1(TRoom& R)
{
	return R;
}
int main()
{
	setlocale(LC_ALL, "rus");
	TRoom T;
	cin >> T;
	cout << T;
	TRoom S = T; // скопирует
	TRoom Q = DoRoomCopy(T); //переместить
	TRoom W, E;
	W = T; //скопирует
	E = DoRoomCopy(T); //переместит
	E = DoRoomCopy1(T); //скопирует
	return 0;
}
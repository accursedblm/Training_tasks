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
	TRoom S = T; // ���������
	TRoom Q = DoRoomCopy(T); //�����������
	TRoom W, E;
	W = T; //���������
	E = DoRoomCopy(T); //����������
	E = DoRoomCopy1(T); //���������
	return 0;
}
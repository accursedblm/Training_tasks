#pragma once
#include "TSetPoint.h"
class TTarget :
    public TSetPoint
{
    double Fr;      //������
    int FBall;      //���-�� �����
    int FNumber;    //���-�� ���������
public:
    TTarget(double r = 0) : TSetPoint(10), Fr(r), FBall(), FNumber() // FBall() � FNumber() ��� ������������ �� ��������� ��� int. ��� ���� ����������� ����� ���� ����������� �� ���������.
    {}
    void operator >> (TPoint& p);
    friend ostream& operator << (ostream&, TTarget&);
};


#pragma once
#include <Windows.h>
#include <locale>
void RusCon()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
}

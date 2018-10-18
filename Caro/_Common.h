#ifndef _COMMON_H
#define _COMMON_H
#include <iostream>
#include <Windows.h>
using namespace std;
#include <conio.h>
class _Common {
public:
	static void fixConsoleWindow();
	static void gotoXY(int, int);// Đưa con trỏ tới vị trí có tọa độ pX, pY
};

#endif


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
void _Common::gotoXY(int pX, int pY) {
	COORD coord;
	coord.X = pX;
	coord.Y = pY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void _Common::fixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

#endif


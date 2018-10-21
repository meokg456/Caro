#pragma once
#ifndef _Design__
#define _Design__
#include "_Common.h"
#include <cwchar>
#include <string>
#define BLACK_COLOR			0
#define DARK_BLUE_COLOR		1 
#define DARK_GREEN_COLOR	2
#define DARK_CYAN_COLOR		3
#define DARK_RED_COLOR		4
#define DARK_PINK_COLOR		5
#define DARK_YELLOW_COLOR	6
#define DARK_WHITE_COLOR	7
#define GREY_COLOR			8
#define BLUE_COLOR			9
#define GREEN_COLOR			10
#define CYAN_COLOR			11
#define RED_COLOR			12
#define PINK_COLOR			13
#define YELLOW_COLOR		14
#define WHITE_COLOR			15
class Design
{
public:
	static void SetColor(unsigned short);
	static void LoadingWord();//Hiển thị loading game
	static void setFontSize(int FontSize);
	static void CaroWord(int,int);
	static void Menu(int ,int,int);
	static int RunMenu(int left, int top, int size);
	static void XoaTro(int left, int top, int k);
	static void ConTro(int left, int top, int k);
};


#endif


#pragma once
#ifndef _Design__
#define _Design__
#include "_Common.h"
#include <string>
#include <fstream>
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
	static void GamOverWord(int left, int top);
	static void Clear();
	static void ThongTin1NguoiChoi(int x,int y);
	static void ThongTin2NguoiChoi();
};


#endif


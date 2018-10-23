#ifndef _BOARD_H
#define _BOARD_H
#include"_Point.h"
#include <iostream>
using namespace std;
class _Board {

private:

	int _size;// kích thước dài và rộng của bàn cờ

	int _left, _top;// _left là khoảng cách từ mép TRÁI MÀN HÌNH CONSOLE tới mép TRÁI BÀN CỜ
					// _top là khoảng cách từ mép TRÊN MÀN HÌNH CONSOLE tới mép TRÊN BÀN CỜ

	_Point** _pArr;// Quản lí tất cả vị trí đánh quân cờ(các vị trí trên bàn cờ)

public:

	int getSize();

	int getLeft();

	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void setCheck(int, int,int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard();

	_Board(int, int, int);
	~_Board();

	int KiemTraDoc();
	bool isFullBoard();
	int KiemTraNgang();
	int KiemTraCheoTrai();
	int KiemTraCheoPhai();
	friend class _Game;//thêm cái này để class Game gọi được các private trong class Board
};

 
#endif
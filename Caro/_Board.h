#ifndef _BOARD_H
#define _BOARD_H
#include"_Point.h"
struct Move
{
	int x = 0;
	int y = 0;
};
class _Board {

private:
	int _size;// kích thước dài và rộng của bàn cờ

	int _left, _top;// _left là khoảng cách từ mép TRÁI MÀN HÌNH CONSOLE tới mép TRÁI BÀN CỜ
					// _top là khoảng cách từ mép TRÊN MÀN HÌNH CONSOLE tới mép TRÊN BÀN CỜ

	_Point** _pArr;// Quản lí tất cả vị trí đánh quân cờ(các vị trí trên bàn cờ)

public:
	friend class _Game;	//thêm cái này để class Game gọi được các private trong class Board
	int getSize();

	int getLeft();

	int getTop();
	int getXAt(int, int);
	int getYAt(int, int);
	void resetData();
	void drawBoard();
	int checkBoard(int, int, bool);
	int testBoard();

	_Board(int, int, int);
	~_Board();

	int KiemTraDoc();
	bool isFullBoard();
	Move Heuristic();
	int KiemTraNgang();
	int KiemTraCheoTrai();
	int KiemTraCheoPhai();
	int DiemTanCongDoc_DaDanh(int dong, int cot);
	int DiemTanCongNgang_DaDanh(int dong, int cot);
	int DiemTanCongCheoXuong_DaDanh(int dong, int cot);
	int DiemTanCongCheoLen_DaDanh(int dong, int cot);
	int DiemPhongNguDoc_DaDanh(int dong, int cot);
	int DiemPhongNguNgang_DaDanh(int dong, int cot);
	int DiemPhongNguCheoXuong_DaDanh(int dong, int cot);
	int DiemPhongNguCheoLen_DaDanh(int dong, int cot);

};

 
#endif
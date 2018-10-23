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

 int _Board::getSize() { return _size; }
 int _Board::getLeft() { return _left; }
 int _Board::getTop() { return _top; }
 int _Board::getXAt(int i, int j)// Lấy ra hoành độ của quân cờ tại ô nhớ có vị trí i, j
 {
	 return _pArr[i][j].getX();

 }
 int _Board::getYAt(int i, int j)// Lấy ra tung độ của quân cờ tại ô nhớ có vị trí i, j
 {
	 return _pArr[i][j].getY();

 }
void _Board::setCheck(int x, int y,int valua)
{
	_pArr[x][y].setCheck(valua);
}
 _Board::_Board(int pSize, int pX, int pY) {

	 _size = pSize;

	 _left = pX;

	 _top = pY;
	 _pArr = new _Point*[pSize];

	 for (int i = 0; i < pSize; i++) _pArr[i] = new _Point[pSize];

 }
 _Board::~_Board() {
	 for (int i = 0; i < _size; i++) delete[] _pArr[i];
	 delete[] _pArr;

 }
 void _Board::resetData() {

	 if (_size == 0) return; // Phải gọi constructor trước khi resetData

	 for (int i = 0; i < _size; i++) {

		 for (int j = 0; j < _size; j++) {
			 _pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ; hoành độ vị trí đánh quân cờ 
			 _pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ; tung độ vị trí đánh quần cờ 
			 _pArr[i][j].setCheck(0);

		 }

	 }

 }
 void _Board::drawBoard() {
	 if (_pArr == NULL) return; // phải gọi constructor trước
	 for (int i = 0; i <= _size; i++) {					// vẽ theo i là vẽ từ trái sang
		 for (int j = 0; j <= _size; j++) {
			 _Common::gotoXY(_left + 4 * i, _top + 2 * j);// vẽ theo j là vẽ dọc từ trên xuống(vẽ trước)
			 printf(".");

		 }

	 }
	 _Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu

 }
 int _Board::checkBoard(int pX, int pY, bool pTurn)// pX: hoành độ quân cờ; pY: tung độ quân cờ; pTurn: Trang thái lượt đánh của 2 người
 {

	 for (int i = 0; i < _size; i++) {

		 for (int j = 0; j < _size; j++) {

			 if (_pArr[i][j].getX() == pX && _pArr[i][j].getY() == pY && _pArr[i][j].getCheck() == 0) {
				 if (pTurn) _pArr[i][j].setCheck(-1);// Nếu lượt hiện hành là true: c = -1

				 else _pArr[i][j].setCheck(1);// Nếu lượt hiện hành là false: c = 1
				 return _pArr[i][j].getCheck();

			 }

		 }

	 }
	 return 0;

 }
 int _Board::testBoard()
 {
	 int temp = 2;
	 if (isFullBoard())
		 return 0;
	 else
	 {
		 if (KiemTraDoc()!=0)
			 temp= KiemTraDoc();
		 if (KiemTraNgang() != 0)
			 temp = KiemTraNgang();
		 if (KiemTraCheoTrai() != 0)
			 temp = KiemTraCheoTrai();
		 if (KiemTraCheoPhai() != 0)
			 temp = KiemTraCheoPhai();
		 return temp;
	 }
 } // Trả mặc định là hòa// Viết lại hàm 

 int _Board::KiemTraDoc()
 {
	 for (int j = 0; j < _size; j++)
	 {
		 for (int i = 0; i < _size; i++)
		 {
			 if (_pArr[i][j].getCheck() != 0)
			 {
				 int temp = _pArr[i][j].getCheck();
				 int Dem = 1;
				 while (Dem != 5 && i < _size-1)
				 {
					 if ((_pArr[i][j].getCheck()) == (_pArr[i + 1][j].getCheck()))
					 {
						 Dem++;
						 i++;
					 }
					 else
						 break;
				 }
				 if (Dem == 5)
				 {
					 if (temp == 1)
						 return 1;
					 else
						 return -1;
				 }
			 }

		 }
	 }
	 return 0;
 }

 int _Board::KiemTraNgang()
 {
	 for (int i = 0; i < _size; i++)
	 {
		 for (int j = 0; j < _size; j++)
		 {
			 if (_pArr[i][j].getCheck() != 0)
			 {
				 int temp = _pArr[i][j].getCheck();
				 int Dem = 1;
				 while (Dem != 5 && j < _size-1)
				 {
					 if ((_pArr[i][j].getCheck()) == (_pArr[i][j+1].getCheck()))
					 {
						 Dem++;
						 j++;
					 }
					 else
						 break;
				 }
				 if (Dem == 5)
				 {
					 if (temp == 1)
						 return 1;
					 else
						 return -1;
				 }
			 }

		 }
	 }
	 return 0;
 }

 int _Board::KiemTraCheoTrai()
 {
	 for (int i = 0; i < _size; i++)
	 {
		 for (int j = 0; j < _size; j++)
		 {
			 if (_pArr[i][j].getCheck() != 0)
			 {
				 int temp = _pArr[i][j].getCheck();
				 int Dem = 0;
				 int k = i;
				 int l = j;
				 while ((Dem != 5) && (k <_size) && (l < _size))
				 {
					 if ((_pArr[i][j].getCheck()) == (_pArr[k][l].getCheck()))
					 {
						 Dem++;
						 k++;
						 l++;
					 }
					 else
						 break;
				 }
				 if (Dem == 5)
				 {
					 if (temp == 1)
						 return 1;
					 else
						 return -1;
				 }
				 
			 }

		 }
	 }
	 return 0;
 }

 int _Board:: KiemTraCheoPhai()
 {
	 for (int i = 0; i<_size; i++)
	 {
		 for (int j = _size-1; j >=0; j--)
		 {
			 if (_pArr[i][j].getCheck() != 0)
			 {
				 int temp = _pArr[i][j].getCheck();
				 int Dem = 0;
				 int k = i;
				 int l = j;
				 while ((Dem != 5) && (k < _size) && (l >=0))
				 {
					 if ((_pArr[i][j].getCheck()) == (_pArr[k][l].getCheck()))
					 {
						 Dem++;
						 k++;
						 l--;
					 }
					 else
						 break;
				 }
				 if (Dem == 5)
				 {
					 if (temp == 1)
						 return 1;
					 else
						 return -1;
				 }

			 }

		 }
	 }
	 return 0;
 }

 bool _Board::isFullBoard()
 {
	 for (int i = 0; i < _size; i++)
		 for (int j = 0; j < _size; j++)
		 {
			 if (_pArr[i][j].getCheck() == 0)
				 return false;
		 }
	 return true;
 }
#endif
#ifndef _BOARD_H
#define _BOARD_H
#include"_Point.h"
#include <iostream>
using namespace std;
class _Board {

private:

	int _size;

	int _left, _top;

	_Point** _pArr;

public:

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

};
 int _Board::getSize() { return _size; }
 int _Board::getLeft() { return _left; }
 int _Board::getTop() { return _top; }
 int _Board::getXAt(int i, int j) {
	 return _pArr[i][j].getX();

 }
 int _Board::getYAt(int i, int j) {
	 return _pArr[i][j].getY();

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
			 _pArr[i][j].setX(4 * j + _left + 2); // Trùng với hoành độ màn hình bàn cờ
			 _pArr[i][j].setY(2 * i + _top + 1); // Trùng với tung độ màn hình bàn cờ
			 _pArr[i][j].setCheck(0);

		 }

	 }

 }
 void _Board::drawBoard() {
	 if (_pArr == NULL) return; // phải gọi constructor trước
	 for (int i = 0; i <= _size; i++) {
		 for (int j = 0; j <= _size; j++) {
			 _Common::gotoXY(_left + 4 * i, _top + 2 * j);
			 printf(".");

		 }

	 }
	 _Common::gotoXY(_pArr[0][0].getX(), _pArr[0][0].getY());// di chuyển vào ô đầu

 }
 int _Board::checkBoard(int pX, int pY, bool pTurn) {

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
 int _Board::testBoard() { return 2; } // Trả mặc định là hòa




#endif
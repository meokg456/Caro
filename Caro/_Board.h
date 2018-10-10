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



#endif
#pragma once
#include"_Common.h"
class _Point {

	int _x, _y, _check;

public:

	_Point();

	_Point(int, int);

	bool setCheck(int);// Cập nhật trạng thái của _check

	int getX();

	int getY();

	int getCheck();
	void setX(int);
	void setY(int);

};
 


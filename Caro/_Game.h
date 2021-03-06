﻿#ifndef _Game_H
#define _Game_H
#include"_Board.h"

#include <string>
#include <fstream>
class _Game {

	_Board* _b;// một bàn cờ

	bool _turn;// lượt chơi: true lượt người một & false lượt người thứ hai

	int _x, _y; // Tọa độ hiện hành của nháy chuột

	int _command; // phím gõ từ người dùng

	bool _loop; // Biến quyết định thoát game hay không
	int DemX, DemO;

public:
	int getCommand();

	bool isContinue();

	bool GetTurn();

	char waitKeyBoard(); // Hàm nhận phím từ người dùng

	char askContinue();
	void startGame(); // Hàm bắt đầu game
	void resetGame();
	void LoadGame();
	int processFinish();

	bool processCheckBoard();

	void SaveGame();

	void moveRight();

	void moveLeft();
	void moveUp();

	void AI(int);


	void moveDown();
	void exitGame();
	_Game(int, int, int);
	~_Game();

};




#endif
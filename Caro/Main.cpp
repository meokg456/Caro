#include "_Game.h"
#include "Design.h"
#define BOARD_SIZE 24
#define LEFT 45
#define TOP 5
#define LEFT_caro 55
#define TOP_caro 5
#define LEFT_menu  60
#define TOP_menu   20
#define SIZE_menu  29
void main() {
	_Common::resizeConsole(1370, 750);
	_Common::fixConsoleWindow();
	//Design::LoadingWord();
	Design::CaroWord(LEFT_caro,TOP_caro);	int i = Design::RunMenu(LEFT_menu,TOP_menu,SIZE_menu); 
	_getch();

	_Game g(BOARD_SIZE, LEFT, TOP);


	char test;
	cout << "neu muon load lai game thi nhan phim T: " ;
	cin >> test;
	if (test == 'T')
		g.LoadGame();
	else
		g.startGame();

	switch (i)
	{
	case 1:
	{
		g.startGame();
		break;
	}
	case 2:
	{
		// Xu ly choi voi may' 
		break;
	}
	case 3:
	{
		g.exitGame();
		break;
	}
	}

	while (g.isContinue()) {

		g.waitKeyBoard();

		if (g.getCommand() == 27) {
			system("cls");
			cout << "neu muon luu thi nhan phim L: ";
			cin >> test;
			if (test == 'L')
				g.SaveGame();
			g.exitGame();
		}
		else {

			switch (g.getCommand()) {

			case 'A':

				g.moveLeft();

				break;

			case 'W':

				g.moveUp();

				break;

			case 'S':

				g.moveDown();

				break;

			case 'D':

				g.moveRight();

				break;

			case 13:

				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục

				if (g.processCheckBoard()) {

					switch (g.processFinish()) {

					case -1: case 1: case 0:;
					if (g.askContinue() == 'Y')  g.startGame();
					else {
						g.exitGame();
						system("cls");
						cout << "neu muon luu thi nhan phim L: ";
						cin >> test;
						if (test == 'L')
							g.SaveGame();
					}
					}

				}

			}

		}

	}

}

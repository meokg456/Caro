#include "_Game.h"

#define BOARD_SIZE 10
#define LEFT 5
#define TOP 5
void main() {

	_Common::fixConsoleWindow();

	_Game g(BOARD_SIZE, LEFT, TOP); // Sinh viên tự định nghĩa các hằng số

	g.startGame();

	while (g.isContinue()) {

		g.waitKeyBoard();

		if (g.getCommand() == 27) g.exitGame();

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

					case -1: case 1: case 0:


						if (g.askContinue() != 'Y') g.exitGame();

						else g.startGame();

					}

				}

			}

		}

	}
}

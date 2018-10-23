#include "_Game.h"
#define BOARD_SIZE 20
#define LEFT 0
#define TOP 0
void main() {

	_Common::fixConsoleWindow();

	_Game g(BOARD_SIZE, LEFT, TOP);

	/*cout << "hay la em cua ngya hom qua" << endl;*/
	char test;
	cout << "neu muon load lai game thi nhan phim T: " ;
	cin >> test;
	if (test == 'T')
		g.LoadGame();
	else
	g.startGame();

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

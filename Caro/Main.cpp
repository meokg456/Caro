#include "_Game.h"
#include "Design.h"
#define BOARD_SIZE 24
#define LEFT 35
#define TOP 5
#define LEFT_caro 55
#define TOP_caro 5
#define LEFT_menu  60
#define TOP_menu   20
#define SIZE_menu  29

void main() {
	/*for (int i = 0; i < 256; i++) {
		Design::SetColor(i);
		cout << "\n=> MAU: " << i;
	}
	_getch();*/
	
	_Common::fixConsoleWindow();

	/*Design::GamOverWord(55, 25);
	_getch();*/
	
	Design::CaroWord(LEFT_caro,TOP_caro);	
	int i = Design::RunMenu(LEFT_menu, TOP_menu, SIZE_menu);

	//Design::LoadingWord();
	Design::CaroWord(LEFT_caro, TOP_caro);	int i = Design::RunMenu(LEFT_menu, TOP_menu, SIZE_menu);

	_getch();

	_Game g(BOARD_SIZE, LEFT, TOP);
	bool AI = false;
	switch (i)
	{
	case 1:
	{
		system("cls");
		/*Design::LoadingWord();*/
		Design::ThongTin2NguoiChoi();
		Design::SetColor(15);//Trả lại nền đen màu trắng
		g.startGame();
		break;
	}
	case 2:
	{
		g.LoadGame();
		break;
	}
	case 3:
	{
		g.startGame();
		AI = true;
		break;
	}
	case 4:
	{
		g.exitGame();
		break;
	}
	}

	
	while (g.isContinue()) {
			if (AI == true)
			{
				g.AI(1);
			}
			else
			{
				g.waitKeyBoard();
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
				case 27:
					g.exitGame();
					break;
				case 'L':
					g.SaveGame();
					break;
				case'T':
					g.LoadGame();
					break;
				case 13:

				break;
			case 27:
				g.SaveGame();
				g.exitGame();
				break;
			/*case 'L'://để thế này thì không thể gọi được khi đang chơi dở
				g.SaveGame();
				break;
			case'T':
				g.LoadGame();
				break;*/
			case 13:

				//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục
				if (g.processCheckBoard()) {
					//Đánh dấu bàn cờ, sau đó kiểm tra và xử lý thắng/thua/hòa/tiếp tục

					if (g.processCheckBoard()) {

						switch (g.processFinish()) {

						case -1: case 1: case 0:;
							if (g.askContinue() == 'Y')  g.resetGame();
							else {
								g.exitGame();
							}


						}

					case -1: case 1: case 0:;
					if (g.askContinue() == 'Y')  g.startGame();
					else {
						g.exitGame();
						g.SaveGame();
					}

				}
			}
	}
}
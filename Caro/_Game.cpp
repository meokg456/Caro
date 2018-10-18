#include"_Game.h"
_Game::_Game(int pSize, int pLeft, int pTop) {
	_b = new _Board(pSize, pLeft, pTop);
	_loop = _turn = true;
	_command = -1; // Gán lượt và phím mặc định
	_x = pLeft; _y = pTop;

}

_Game::~_Game() { delete _b; }
int _Game::getCommand() { return _command; }
bool _Game::isContinue() { return _loop; }
char _Game::waitKeyBoard() {
	_command = toupper(_getch());
	if (_command == 0) _command = toupper(_getch());
	return _command;
}
char _Game::askContinue() {
	_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 3);// Đưa con trỏ ra khỏi bàn cờ để không cho người chơi 
																			// tiếp tục đánh 
	cout << "Ban co muon choi lai khong? (y/n)" << endl;
	return waitKeyBoard();
}
void _Game::startGame() {

	system("cls");
	_b->resetData(); // Khởi tạo dữ liệu gốc
	_b->drawBoard(); // Vẽ màn hình game
	_x = _b->getXAt(0, 0);
	_y = _b->getYAt(0, 0);

}
void _Game::exitGame() {
	system("cls");
	//Có thể lưu game trước khi exit
	_loop = false;

}
bool _Game::processCheckBoard()
{
	switch (_b->checkBoard(_x, _y, _turn))
	{
	case -1:
		printf("X");
		break;
	case 1:

		printf("O");
		break;
	case 0: return false; // Khi đánh vào ô đã đánh rồi

	}
	return true;

}
int _Game::processFinish()
{
	// Nhảy tới vị trí thích hợp để in chuỗi thắng/thua/hòa



	int pWhoWin = _b->testBoard();

	switch (pWhoWin) {

	case -1:
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false);

		break;

	case 1:
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false, true);

		break;

	case 0:
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
		printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);

		break;

	case 2:

		_turn = !_turn; // Đổi lượt nếu không có gì xảy ra

	}


	return pWhoWin;

}

void _Game::moveRight()
{

	if (_x < _b->getXAt(_b->getSize() - 1, _b->getSize() - 1))
	{

		_x += 4;

		_Common::gotoXY(_x, _y);

	}

}

void _Game::moveLeft() {

	if (_x > _b->getXAt(0, 0)) {

		_x -= 4;

		_Common::gotoXY(_x, _y);

	}

}

void _Game::moveDown() {

	if (_y < _b->getYAt(_b->getSize() - 1, _b->getSize() - 1)) {

		_y += 2;

		_Common::gotoXY(_x, _y);

	}

}

void _Game::moveUp() {

	if (_y > _b->getYAt(0, 0)) {

		_y -= 2;

		_Common::gotoXY(_x, _y);

	}
}

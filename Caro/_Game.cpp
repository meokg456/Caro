#include"_Game.h"
#include "Design.h"
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
		Design::SetColor(12);//Tạo màu đỏ
		printf("X");
		Design::SetColor(15);//Trả lại màu trắng cho console
		break;
	case 1:
		Design::SetColor(11);//Tạo màu xanh duong nhat
		printf("O");
		Design::SetColor(15);//Trả lại màu trắng cho console
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
		//Ve nen chu Winword
		Design::Winword(35, 5);
		Design::Loseword(86, 5);
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", true, false+2);
		//Nguoi choi 1 win, Nguoi choi 2 lose
		break;
	case 1:
		_Common::gotoXY(0, _b->getYAt(_b->getSize() - 1, _b->getSize() - 1) + 2);
		printf("Nguoi choi %d da thang va nguoi choi %d da thua\n", false+2, true+1);

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
void _Game::SaveGame()
{
	string name;
	system("cls");
	cout << "nhap ten file ban muon luu: ";
	fflush(stdin);
	cin >> name;
	ofstream f(name, ios::out);
	if (f.fail()) cout << "mo khong duoc";
	if (f) {
		int n = _b->getSize();
		f << n << endl;
		f << _x << endl;
		f << _y << endl;
		f << _turn << endl;
		f << _loop << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				f << _b->_pArr[i][j].getCheck() << "   " << _b->_pArr[i][j].getX() << "    " << _b->_pArr[i][j].getY() << "             ";
				if (f.fail()) break;
			}
			f << endl;
			if (f.fail()) break;
		}
		f.close();
		system("cls");
		_b->drawBoard();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (_b->_pArr[i][j].getCheck() != 0) {
					_Common::gotoXY(_b->_pArr[i][j].getX(), _b->_pArr[i][j].getY());
					switch (_b->_pArr[i][j].getCheck())
					{
					case -1:
						Design::SetColor(12);//Tạo màu đỏ
						printf("X");
						Design::SetColor(15);//Trả lại màu trắng cho console
						break;
					case 1:
						Design::SetColor(11);//Tạo màu xanh duong nhat
						printf("O");
						Design::SetColor(15);//Trả lại màu trắng cho console
						break;
					}
				}
			}
		}
		}
}
void _Game::LoadGame()
{
	string name;
	system("cls");
	cout << "Nhap ten file: ";
	fflush(stdin);
	cin >> name;
	ifstream f(name);
	if (f) {
		int n, x, y;
		f >> n;
		f >> _x;
		f >> _y;
		f >> _turn;
		f >> _loop;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int check, x1, y1;
				f >> check;
				_b->_pArr[i][j].setCheck(check);
				f >> x1;
				_b->_pArr[i][j].setX(x1);
				f >> y1;
				_b->_pArr[i][j].setY(y1);
				if (f.fail()) break;
			}
			if (f.fail()) break;
		}
		system("cls");
		_b->drawBoard();
		bool turn = TRUE;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (_b->_pArr[i][j].getCheck() != 0) {
					_Common::gotoXY(_b->_pArr[i][j].getX(), _b->_pArr[i][j].getY());
					switch (_b->_pArr[i][j].getCheck())
					{
					case -1:
						Design::SetColor(12);//Tạo màu đỏ
						printf("X");
						Design::SetColor(15);//Trả lại màu trắng cho console
						break;
					case 1:
						Design::SetColor(11);//Tạo màu xanh duong nhat
						printf("O");
						Design::SetColor(15);//Trả lại màu trắng cho console
						break;
					}
					turn = !turn;
				}
			}
		}
		if (_loop == false) {

			switch (processFinish()) {

			case -1: case 1: case 0:;
				if (askContinue() == 'Y')  startGame();
			}
			return;
		}
		_Common::gotoXY(_x, _y);
		_turn = !_turn;
		f.close();
	}
}
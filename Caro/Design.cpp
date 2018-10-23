#include "Design.h"



void Design::SetColor(unsigned short i)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, i);
}

void Design::LoadingWord()
{
	int x = 20;
	int y = 25;
	_Common::gotoXY(x+5, y-3);
	cout << "LOADING...";

	Design::SetColor(9);//tạo màu xanh cho hộp loading
	for (int i = 0; i < 100; i++) {
		_Common::gotoXY(x, y);
		cout << char(219);
		_Common::gotoXY(x, y+1);
		cout << char(219);
		_Common::gotoXY(x, y + 2);
		cout << char(219);
		x++;
		if (i < 10)
		{
			Sleep(200);
		}
		else if (i < 50) {
			Sleep(70);
		}
		else{
			Sleep(10);
		}
	}
	Design::SetColor(15);// Trả về kí tự màu trắng cho màn hình console
	system("cls");
}

void Design::setFontSize(int FontSize)
{
	{
		CONSOLE_FONT_INFOEX info = { 0 };
		info.cbSize = sizeof(info);
		info.dwFontSize.Y = FontSize; // leave X as zero
		info.FontWeight = FW_NORMAL;
		wcscpy_s(info.FaceName, L"Lucida Console");
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), NULL, &info);
	}
}

void Design::CaroWord(int x,int y)
{	
	Design::SetColor(12);
	_Common::gotoXY(x, y);
	cout << " +      +               +         +                ++    ++    ++";
	_Common::gotoXY(x, y+1);
	cout << " _______    +       +          _______ _   \\\\/ \\/ \\//           +      ";
	_Common::gotoXY(x, y+2);
	cout << "(_______)                     (_______) |   \\______/               +  +";
	_Common::gotoXY(x, y + 3);
	cout << "_         _____  ____ ___      _      | |__  _____  ___  ___     +      ";
	_Common::gotoXY(x, y + 4);
	cout << "|  |  +  (____ |/ ___)  _ \\   | |  +  |  _ \\| ___ |/___)/___)         +  ";
	_Common::gotoXY(x, y + 5);
	cout << "|  |_____/ ___ | |   | |_| |  | |_____| | | | ____|___ |___ |  (\\/)";
	_Common::gotoXY(x, y + 6);
	cout << " \\______)_____ |_|   \\_____/  \\_______)_| |_|_____|___/(___/   (/\\) O";
	_Common::gotoXY(x, y + 7);
	cout << "  +       +                                                            +";
	_Common::gotoXY(x, y+8);
	cout << "     +          +             +               +               +    +     ";
	Design::SetColor(15);//Trả lại màu trắng cho màn hình console
}
void Design::Menu(int left,int top,int size)
{
	Design::SetColor(11);
	_Common::gotoXY(left, top);

	int outofleft;
	int outofright;

	//Vẽ khung menu
	for (int i = 1; i <= size; i++) {
		//Vẽ viền trái 
		_Common::gotoXY(left, top+i);
		cout << char(179);
		_Common::gotoXY(left, top + i+1);
		cout << char(179);

		//Vẽ viền trái ngoài
		outofleft = left - 3;
		outofright = top - 2;
		_Common::gotoXY(outofleft, outofright + i);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 1);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 2);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 3);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 4);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 5);
		cout << char(179);
		//Vẽ viền phải
		_Common::gotoXY(left+ size*2, top+i);
		cout << char(179);
		_Common::gotoXY(left+ size*2, top +i+1);
		cout << char(179);

		//Vẽ viền phải ngoài
		outofleft = left +size*2+3;
		outofright = top - 2;
		_Common::gotoXY(outofleft, outofright + i);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 1);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 2);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 3);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 4);
		cout << char(179);
		_Common::gotoXY(outofleft, outofright + i + 5);
		cout << char(179);

		//Vẽ viền trên
		_Common::gotoXY(left+i, top);
		cout << "_____________________________";

		//Vẽ viền trên ngoài
		outofleft = left - 3;
		_Common::gotoXY(outofleft + i, outofright);
		cout << "___________________________________";

		//Vẽ viền dưới
		_Common::gotoXY(left + i, top +size+1);
		cout << "_____________________________";

		//Vẽ viền dưới ngoài
		outofleft = left - 3;
		outofright = top + size + 1;
		_Common::gotoXY(outofleft + i, outofright+2);
		cout << "___________________________________";
	}

	//_Common::gotoXY(x, y);
	//cout << char(32) << "     New game     " << char(32) << endl;

	Design::SetColor(14);
	int inofleft= left + 25;
	int inofright = top + 7;
	_Common::gotoXY(inofleft, inofright);
	cout << " New Game";
	_Common::gotoXY(inofleft, inofright += 5);
	cout << " Load Game";
	_Common::gotoXY(inofleft, inofright += 5);
	cout << " One Player";
	_Common::gotoXY(inofleft, inofright += 5);
	cout << " Exit Game";
}

int Design::RunMenu(int left, int top, int size)
{
	Menu(left, top, size);
	int lleft = left + 21;
	int ltop = top + 2;
	int i = 1;
	int NUMLIST = 4;
	ConTro(lleft, ltop, i);
	while (true) {

		int key = _getch();
		XoaTro(lleft, ltop, i);

		switch (key)
		{
		case 13:
		{
			return i;
			break;
		}
		case'S':case's':
		{
			i++;

			break;
		}
		case'W':case'w':
		{
	
			i--;

			break;
		}

		}
		if (i == 0) i = NUMLIST;
		if (i > NUMLIST) i = 1;
		ConTro(lleft, ltop, i);
	}
}
void Design::XoaTro(int left, int top, int k)
{
	_Common::gotoXY(left, top + k * 5);
	cout << char(32);
	_Common::gotoXY(left + 17, top + k * 5);
	cout << char(32);
}
void Design::ConTro(int left, int top, int k)
{
	_Common::gotoXY(left, top + 5*k);
	cout << char(175);
	_Common::gotoXY(left +17, top + 5*k);
	cout << char(174);

}

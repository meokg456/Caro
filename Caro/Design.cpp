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

void Design::CaroWord()
{
	int x, y;
	x = 55;
	y = 10;

	
	_Common::gotoXY(x, y);
	Design::SetColor(12);
	cout << " +      +               +         +                ++    ++    ++";
	_Common::gotoXY(x, y+1);
	cout << " _______    +       +          _______ _   \\\\/ \\/ \\//           +      ";
	_Common::gotoXY(x, y+2);
	cout << "(_______)                     (_______) |   \\______/               +  +";
		_Common::gotoXY(x, y+3);
		cout << "_         _____  ____ ___      _      | |__  _____  ___  ___     +      ";
		_Common::gotoXY(x, y+4);
		cout << "|  |  +  (____ |/ ___)  _ \\   | |  +  |  _ \\| ___ |/___)/___)         +  ";
		_Common::gotoXY(x, y+5);
		cout << "|  |_____/ ___ | |   | |_| |  | |_____| | | | ____|___ |___ |  (\\/)";
		_Common::gotoXY(x, y+6);
		cout << " \\______)_____ |_|   \\_____/  \\_______)_| |_|_____|___/(___/   (/\\) O";
		_Common::gotoXY(x, y+7);
		cout << "  +       +                                                           +   ";
		_Common::gotoXY(x, y+8);
		cout << "     +          +             +               +               +    +     ";

		/*cout << " +      +               +         +                ++    ++    ++" << endl;
		cout << " _______    +       +          _______ _   \\/ \/ \//           +      " << endl;
		cout << "(_______)                     (_______) |   \______/               +  +" << endl;
		cout << "_         _____  ____ ___      _      | |__  _____  ___  ___     +      " << endl;
		cout << "|  |  +  (____ |/ ___)  _ \   | |  +  |  _ \| ___ |/___)/___)         +  " << endl;
		cout << "|  |_____/ ___ | |   | |_| |  | |_____| | | | ____|___ |___ |  (\/)" << endl;
		cout << " \______)_____ |_|    \___/    \______)_| |_|_____|___/(___/   (/\) O" << endl;
		cout << "  +       +                                                           +   " << endl;
		cout << "     +          +             +               +               +    +     " << endl;*/
}
void Design::Menu()
{
	int x = 78;
	int y = 35;
	Design::SetColor(13);
	_Common::gotoXY(x, y);
	cout << char(175) << "     New game     " << char(174);
	//_Common::gotoXY(x, y);
	//cout << char(32) << "     New game     " << char(32) << endl;
}
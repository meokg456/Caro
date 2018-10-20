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
	x = 15;
	y = 15;
	
	Design::SetColor(14);
	çout << "xoxoxoxoxoxoxoxo"<<en====
	cout << "xoxoxoxoxoxoxoxo";
	cout << "xoxoxoxoxoxoxox";
	
	
		
		 
		

		/*______  __    __   _______     _______._______.
		/      ||  |  |  | |   ____|   /       |    /       |
		|, ----'|  |__|  | |  |__     |   (----`   |   (----`
		|  |     |   __   | |   __ | \   \        \   \
		| `--- - .|  |  |  | |  |____.----) | .----) |
		\______ || __|  |__| |_______ | _______/    |_______ /
*/
		/*cout << " +      +               +         +                ++    ++    ++";
		cout << " _______    +       +          _______ _   \\/ \/ \//           +      ";
		cout << "(_______)                     (_______) |   \______/               +  +";
		cout << "_         _____  ____ ___      _      | |__  _____  ___  ___     +      ";
		cout << "|  |  +  (____ |/ ___)  _ \   | |  +  |  _ \| ___ |/___)/___)         +  ";
		cout << "|  |_____/ ___ | |   | |_| |  | |_____| | | | ____|___ |___ |  (\/)";
		cout << " \______)_____ |_|    \___/    \______)_| |_|_____|___/(___/   (/\) O";
		cout << "  +       +                                                           +   ";
		cout << "     +          +             +               +               +    +     ";*/
}

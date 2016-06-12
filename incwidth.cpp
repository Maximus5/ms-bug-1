
#include <windows.h>
#include <stdio.h>

void main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	CONSOLE_CURSOR_INFO ci = {};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &csbi);
	GetConsoleCursorInfo(hOut, &ci);
	printf("Cursor height before=%i%%\n", ci.dwSize);
	csbi.dwSize.X++;
	SetConsoleScreenBufferSize(hOut, csbi.dwSize);
	GetConsoleCursorInfo(hOut, &ci);
	printf("Cursor height after=%i%%\n", ci.dwSize);
}

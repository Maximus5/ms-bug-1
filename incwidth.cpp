
#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	CONSOLE_CURSOR_INFO ci = {};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &csbi);
	GetConsoleCursorInfo(hOut, &ci);
	printf("Cursor height before=%i%%\r\n", ci.dwSize);
	SetConsoleTitle(_T("Increasing ScreenBufferSize"));
	Sleep(2500);
	csbi.dwSize.X++;
	SetConsoleScreenBufferSize(hOut, csbi.dwSize);
	SetConsoleTitle(_T("Quering current cursor information"));
	Sleep(2500);
	GetConsoleCursorInfo(hOut, &ci);
	printf("Cursor height after=%i%%\r\n", ci.dwSize);
}

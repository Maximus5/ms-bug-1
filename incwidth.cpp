
#include <windows.h>

void main()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi = {};
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hOut, &csbi);
	csbi.dwSize.X++;
	SetConsoleScreenBufferSize(hOut, csbi.dwSize);
}

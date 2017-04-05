// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using std::cout;

int _tmain(int argc, _TCHAR* argv[])
{

	std::cout << " Par1: \n Par2: \n Sum: \n Par2: \n Sqr: \n Diff: \n";
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = { 0, 0 };
	for (int i = 0; i < 1000; i++){
		Sleep(10);
		position.X = 7; position.Y = 0;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << i;
		position.X = 7; position.Y = 1;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << (999-i);
		position.X = 7; position.Y = 2;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << ((999 - i)+i);
		position.X = 7; position.Y = 3;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << (i-(999 - i));
		position.X = 7; position.Y = 4;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << (999-i)*(999 - i);
		position.X = 7; position.Y = 5;
		SetConsoleCursorPosition(hConsole, position);
		std::cout << (i*i);


	}
	int c;
	std::cin >> c;
	return 0;
}

/*

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using std::cout;

int main()
{
setlocale(LC_ALL, "rus");
bool exit = false;
int ch;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position = { 0, 0 };
cout << (char)16 << "Создать базу \n Редактировать \n Удалить";
SetConsoleCursorPosition(hConsole, position);
while (!exit)
{
ch = _getch();
switch (ch)
{
case 224:
{
switch (_getch())
{
case 72:
{// нажата клавиша вверх
if (position.Y)
{
cout << " ";
position.Y--;
SetConsoleCursorPosition(hConsole, position);
cout << (char)16;
SetConsoleCursorPosition(hConsole, position);
}
break;
}
case 80:
{// нажата клавиша вниз
if (position.Y < 2)
{
cout << " ";
position.Y++;
SetConsoleCursorPosition(hConsole, position);
cout << (char)16;
SetConsoleCursorPosition(hConsole, position);
}
break;
}
default:
break;
}
break;
}
case 27:
{
exit = true;
break;
}
default:
break;
}
}
return 0;
}

*/
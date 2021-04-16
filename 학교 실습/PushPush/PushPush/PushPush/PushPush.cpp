#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define UP		72
#define DOWN	80
#define LEFT	75
#define RIGHT	77

int currentX, currentY;
int totalMove;

char backgroundMap[10][16];

char Stage[10][16] =
{
	"+++++++++++++++",
	"+++++++++++++++",
	"++++&  ++++++++",
	"++++ OO++++++++",
	"++++ O ++++.+++",
	"++++++ ++++.+++",
	"++++++     .+++",
	"+++++    +  +++",
	"+++++    ++++++",
	"+++++++++++++++"
};

void gotoXY(int x, int y)
{
	HANDLE hOut;
	COORD Cur;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(hOut, Cur);
}

void clrscr()
{
	system("cls");
}

void InitScreen()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			gotoXY(x, y);
			_putch(backgroundMap[y][x]);
		}
	}
	gotoXY(currentX, currentY);
	_putch('&');
}

bool checkEnd()
{
	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (Stage[y][x] == '.' && backgroundMap[y][x] != 'O')
			{
				return false;
			}
		}
	}
	return true;
}

void move(int dir)
{
	int dir_x = 0, dir_y = 0;

	switch (dir)
	{
	case LEFT:
		dir_x = -1;
		break;
	case RIGHT:
		dir_x = 1;
		break;		
	case UP:
		dir_y = -1;
		break;
	case DOWN:
		dir_y = 1;
		break;
	}

	if (backgroundMap[currentY + dir_y][currentX + dir_x] != '+')
	{
		if (backgroundMap[currentY + dir_y][currentX + dir_x] == 'O')
		{
			if (backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == 'O' || backgroundMap[currentY + dir_y * 2][currentX + dir_x * 2] == '.')
			{
				//TODO: STAGE 꺼를 바꿔. 
			}
		}
		currentX += dir_x;
		currentY += dir_y;
	}
}

int main()
{
	memcpy(backgroundMap, Stage, sizeof(backgroundMap));

	for (int y = 0; y < 10; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			if (backgroundMap[y][x] == '&')
			{
				currentX = x;
				currentY = y;
				backgroundMap[y][x] = ' ';
			}
		}
	}
	InitScreen();	
	gotoXY(20, 20);
	return 0;
}

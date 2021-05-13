#pragma once
#include "cGameEngine.h"

void SetConsoleView()
{
    system("mode con:cols=50 lines=25");
    system("title Math RPG");
}

void GotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}

void SetTextColor(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void Clrscr()
{
    system("cls");
}
void beep(int tone, int delay)
{
    Beep(tone, delay);
}

int GetKeyDown()
{
    if (_kbhit() != 0)
    {
        return _getch();
    }

    return 0;
}
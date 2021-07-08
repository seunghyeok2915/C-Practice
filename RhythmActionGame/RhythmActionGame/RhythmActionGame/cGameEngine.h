#pragma once
#include <iostream>
#include <Windows.h>
#include <conio.h>

extern void SetConsoleView();
extern void GotoXY(int x, int y);
extern void SetTextColor(int color);
extern void Clrscr();
extern void beep(int tone, int delay);
extern int GetKeyDown();

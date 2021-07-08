#pragma once

#include "Note.h"
#include "cGameEngine.h"

using namespace std;

void Note::InitNote()
{
    this->idx = rand() % 7 + 1;

    x = idx * 2;
    y = 0;

}

void Note::DrawNote()
{
    GotoXY(x, y);
    SetTextColor(14);
    cout << "Q";
    SetTextColor(15);
}


void Note::DownNote()
{
    y++;
}

void Note::CheckEnd()
{
    int temp = GetKeyDown();
    if (temp == idx + 48 && (y == 10 || y == 11))
    {
        playSound();
        InitNote();
    }
    if (y == 12)
    {
        InitNote();
    }
}

void Note::playSound()
{
    int data[7] = { 523,587,659,698,784,880,988 };
    beep(data[idx - 1], 500);
}
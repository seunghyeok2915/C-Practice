//20312이승혁
#include <iostream>
#include <time.h>

#include "Note.h"
#include "cGameEngine.h"

using namespace std;

void DrawScreen()
{
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "|               |" << endl;
    cout << "  1 2 3 4 5 6 7  " << endl;
    GotoXY(1, 10);
    SetTextColor(1);
    cout << "---------------";
    SetTextColor(15);
}

int main()
{
    srand((unsigned)time(NULL));

    Note* note = new Note();
    note->InitNote();

    while (true)
    {
        DrawScreen();

        note->DrawNote();
        note->DownNote();
        note->CheckEnd();

        GotoXY(16, 12);
        Sleep(100);
        Clrscr();
    }
    return 0;
}


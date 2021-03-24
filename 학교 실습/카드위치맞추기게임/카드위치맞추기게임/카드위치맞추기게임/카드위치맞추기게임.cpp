#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>

using namespace std;

void gotoXY(int x, int y)
{
    HANDLE hOut;
    COORD Cur;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Cur.X = x;
    Cur.Y = y;
    SetConsoleCursorPosition(hOut, Cur);
}


int main()
{
    srand((unsigned)time(NULL));

    int randNums[20] = { 0, };
    int numCheck[10] = { 0, };

    int i = 0;
    while (randNums[i] == 0)
    {
        int ranNum = rand() % 10;
        if (numCheck[ranNum] != 2)
        {
            randNums[i] = ranNum;
            numCheck[ranNum]++;
            ++i;
        }
        else
        {
            randNums[i] == 0;
        }
    }


    /*
    for (int i = 0; i < 4; i++)
    {
    for (int j = 0; j < 5; j++)
    {
    cout << randNums[i*5 +j] << " ";
    }
    cout << endl;
    }
    */

    for (int i = 0; i < 20; i++)
    {
        gotoXY(i % 5, i / 5);
        cout << "*";
    }


    int numCode[20] = { 49,50,51,52,53,113,119,101,114,116,97,115,100,102,103,122,120,99,118,98 };
    int check = 0;
    int tempNum[2] = { 0, };
    int tempi[2] = { 0, };
    while (true)
    {
        while (true)
        {
            int key = _getch();

            for (int i = 0; i < 20; i++)
            {
                if (key == numCode[i])
                {
                    gotoXY(i % 5, i / 5);
                    cout << randNums[i];
                    tempNum[check] = randNums[i];
                    tempi[check] = i;
                    check++;
                }
            }
            if (tempNum[0] != tempNum[1] && check == 2)
            {
                Sleep(1000);
                for (int a = 0; a < 2; a++)
                {
                    gotoXY(tempi[a] % 5, tempi[a] / 5);
                    cout << "*";
                    check = 0;
                }
            }
            else if(tempNum[0] == tempNum[1])
            {
                check = 0;
            }
    }

    }



}

/*
int samenum = 0;
const int num = 20;
int Number[num] = { 0, };
bool bSame = false;

for (int i = 0; i < num; i++)
{
do
{
samenum = 0;
bSame = false;
Number[i] = rand() % 10 + 1;

if (i > 1)
{
for (int j = 0; j < i; j++)
{
if (Number[i] == Number[j])
{
samenum++;
}
}
if (samenum > 1)
{
bSame = true;
}
}

} while (bSame);
}
*/
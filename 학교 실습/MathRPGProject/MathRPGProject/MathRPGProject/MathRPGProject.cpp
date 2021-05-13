#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <string>
#include "cGameEngine.h"


using namespace std;

void DrawOnGame()
{
    Clrscr();
    GotoXY(60, 5);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    GotoXY(60, 30);
    cout << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
    GotoXY(50, 16);
    cout << "여기 수학문제:";
}

class TestClass
{
public:
    string name;
    int money;
};

int main()
{
    TestClass ManufacturingBusiness;
    TestClass ServiceBusiness;
    ManufacturingBusiness.name = "Hong";
    ManufacturingBusiness.money = 200;
    ServiceBusiness.name = "Wow";
    ServiceBusiness.money = 300;
    cout << "사업 정보" << endl;
    cout << (ManufacturingBusiness.money + ServiceBusiness.money) / 2 << endl;
	//SetConsoleView();
    while (true)
    {
        //DrawOnGame();
        Sleep(50);
    }
    return 0;
}



#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct tag_Munje
{
	string Question;
	string Answer;
	int wordCount;
	bool bUsed;
};

tag_Munje Munje[] =
{
{"********", "alphabet", 8 , false}
};

int main()
{
	char ch, checkch;
	string tempQuestion;
	int checkCount, checkStar;

	tempQuestion = Munje[0].Question;

	cout << "------------------------------" << endl;
	cout << "|   alphatbet 맞히기 게임   |" << endl;
	cout << "------------------------------" << endl;
	cout << "|  설명 : 알파벳을 누르세요.|" << endl;
	cout << "------------------------------" << endl;
	cout << tempQuestion << endl;

	checkCount = 0;
	checkStar = 0;
	for (int i = 0; i < Munje[0].wordCount; i++)
	{
		checkch = _getch();
		for (int j = 0; j < Munje[0].wordCount; j++)
		{
			if (Munje[0].Answer[j] == checkch)
			{
				tempQuestion[j] = checkch;
			}

		}
		cout << tempQuestion << endl;
	}
	return 0;

}
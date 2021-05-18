#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstring>
#include <vector>
#include "cGameEngine.h"

using namespace std;
#define QUESTIONLINE 9


void drawUI(string name,float hp, float maxHp, int x, int y, int numOfBar)
{
	float temp = (float)hp / (float)maxHp;
	float a = numOfBar * temp;
	GotoXY(x, y);
	cout << name << " " << hp << " / " << maxHp;

	SetTextColor(15);
	GotoXY(x, y + 1);
	for (int i = 0; i < numOfBar; i++)
	{
		cout << "-";
	}
	GotoXY(x, y + 2);
	for (int i = 0; i < numOfBar; i++)
	{
		cout << " ";
	}

	GotoXY(x, y + 2);
	for (int i = 0; i < numOfBar; i++)
	{
		if (i < a)
			SetTextColor(4);
		else
			SetTextColor(8);
		cout << "@";
	}

	SetTextColor(15);
	GotoXY(x, y + 3);
	for (int i = 0; i < numOfBar; i++)
	{
		cout << "-";
	}
}

vector<string> split(string s, string divid) {
	vector<string> v;
	char* c = strtok((char*)s.c_str(), divid.c_str());
	while (c) {
		v.push_back(c);
		c = strtok(NULL, divid.c_str());
	}
	return v;
}

class LivingEntity
{
public:
	string name;
	float maxHp;
	float hp = 0;
	float damage = 0;
	LivingEntity(string _name, float _hp, float _damage) : name(_name), maxHp(_hp), damage(_damage) { hp = maxHp; }
	virtual void die() = 0;
	virtual void onDamage(float damage) = 0;
};
class Monster : public LivingEntity
{
public:
	Monster(string _name, float _hp, float _damage) : LivingEntity(_name,_hp, _damage) {}
	virtual void onDamage(float damage)
	{
		system("color 4f");
		Sleep(50);
		hp -= damage;
		drawUI(name,hp, maxHp, 92, 19, 50);
		system("color 15f");
		if (hp <= 0)
			die();
	}
	virtual void die()
	{
		cout << "이겼습니다";
		exit(0);
		return;
	}
};

class Player : public LivingEntity
{
public:
	Player(string _name,float _hp, float _damage) : LivingEntity(_name,_hp, _damage) {}
	virtual void onDamage(float damage)
	{
		system("color 4f");
		Sleep(50);
		hp -= damage;
		drawUI(name,hp, maxHp, 0, 30, 50);
		system("color 15f");
		if (hp <= 0)
			die();
	}
	virtual void die()
	{
		cout << "졌습니다";
		return;
	}
};

class Question
{
public:
	bool isUsed = false;
	Question()
	{
		question = "없음";
		answer = 0;
		dmg = 0;
	}
	string question;
	float answer;
	int dmg;
};

class GameManager
{
	float ans = 0;
	Question* curQuestion = new Question();
	Monster* monster = new Monster("Boss",1000, 100);
	Player* player = new Player("John",500, 100);
public:
	Question** questionList;
	int num_of_questions;
	GameManager(Question** question, int num_of_questions)
	{
		questionList = question;
		this->num_of_questions = num_of_questions;
	}
	void run()
	{
		while (true)
		{
			Clrscr();
			//drawBackGround(50, 25, "TextBox.txt");
			drawBackGround(99, 0, "Boss.txt");
			drawBackGround(7, 15, "Player.txt");
			drawUI(monster->name,monster->hp, monster->maxHp, 92, 19, 50);
			drawUI(player->name,player->hp, player->maxHp, 0, 30, 50);
			pickRandQuestion();
			drawQuestion(1, 1);
			cin >> ans;
			float randn = (float)(rand() % 40 + 80) / 100;
			if (ans == curQuestion->answer)
			{
				monster->onDamage(player->damage * randn + (player->damage * curQuestion->dmg / 100));
			}
			else
			{
				player->onDamage(monster->damage * randn + (monster->damage * curQuestion->dmg / 100));
			}
		}
	}

	void drawBackGround(int x, int y, string fileName)
	{
		char print_temp[256];
		FILE* rfp;
		rfp = fopen(fileName.c_str(), "rt");

		if (rfp == NULL)
		{
			cout << "파일읽기 실패";
			return;
		}

		int i = 0;
		while (fgets(print_temp, 255, rfp) != NULL)
		{
			GotoXY(x, i + y);
			i++;
			cout << print_temp;
		}
		fclose(rfp);
	}

	void drawQuestion(int x, int y)
	{
		GotoXY(x, y);
		cout << curQuestion->question;
	}

	void pickRandQuestion()
	{
		int value = rand() % QUESTIONLINE;

		if (!questionList[value]->isUsed)
		{
			curQuestion = questionList[value];
			curQuestion->isUsed = true;
		}
		else pickRandQuestion();
	}

};




int main()
{
	SetConsoleView();
	srand((unsigned)time(NULL));

	Question* questions[QUESTIONLINE];

	ifstream mathQusetion;
	mathQusetion.open("MathQuestions.txt");
	string buffer;

	for (int i = 0; i < QUESTIONLINE; i++) // 문제 저장
	{
		getline(mathQusetion, buffer);
		vector<string> v = split(buffer, "ans,dmg");

		questions[i] = new Question();
		questions[i]->dmg = stoi(v.back());
		v.pop_back();
		questions[i]->answer = stof(v.back());
		v.pop_back();
		questions[i]->question = v.back();
		v.pop_back();
	}
	mathQusetion.close();

	GameManager gameManager(questions, QUESTIONLINE);
	gameManager.run();
	return 0;
}



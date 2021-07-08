#pragma once
#include "cGameEngine.h"
#include "LivingEntity.h"
#include "Question.h"

class GameManager
{
	string ans = "";
	Question* curQuestion = new Question();
	Monster* monster;
	Player* player;
public:
	Question** questionList;
	int num_of_questions;
	int bossAttackTimer = 0;
	GameManager(Question** question, int num_of_questions)
	{
		questionList = question;
		this->num_of_questions = num_of_questions;
	}

	void Init(string playerName, float playerHp, float playerDamage, string bossName, float bossHp, float BossDamage)
	{
		player = new Player(playerName, playerHp, playerDamage, this);
		monster = new Monster(bossName, bossHp, BossDamage, this);
	}
	void run()
	{
		pickRandQuestion();
		isPlay = true;
		while (isPlay)
		{
			int key = getKeyDown();
			clrscr();
			//drawBackGround(50, 25, "TextBox.txt");
			drawBackGround(99, 0, "Boss.txt");
			drawBackGround(7, 15, "Player.txt");
			drawUI(monster->name, monster->hp, monster->maxHp, 92, 19, 50);
			drawUI(player->name, player->hp, player->maxHp, 0, 30, 50);

			drawQuestion(70, 30);
			gotoXY(70, 31);
			cout << ans;
			//gotoXY(70, 32);
			//cout << curQuestion->answer;
			gotoXY(70, 1);
			cout << bossAttackTimer;
			float randn = (float)(rand() % 40 + 80) / 100;
			switch (key)
			{
			case 13:
				if (ans == curQuestion->answer || ans == "99")
				{
					monster->onDamage(player->damage * randn + (player->damage * curQuestion->dmg / 100));
				}
				else
				{
					player->onDamage(monster->damage * randn + (monster->damage * curQuestion->dmg / 100));
				}
				pickRandQuestion();
				ans = "";
				break;
			default:
				break;
			}
			if (to_string(key) >= "48" && to_string(key) <= "58")
				ans += to_string(key - 48);
			if (bossAttackTimer % 25 >= 24)
			{
				player->onDamage(monster->damage * randn + (monster->damage * curQuestion->dmg / 100));
			}
			bossAttackTimer++;
			Sleep(100);
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
			gotoXY(x, i + y);
			i++;
			cout << print_temp;
		}
		fclose(rfp);
	}

	void drawQuestion(int x, int y)
	{
		gotoXY(x, y);
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

	void OnPlayerWin()
	{
		isPlay = false;
		clrscr();
		gotoXY(60, 2);
		cout << "******************************";
		gotoXY(60, 3);
		cout << "*         Win         *";
		gotoXY(60, 4);
		cout << "******************************";
		gotoXY(60, 20);
		PlayerRank player = PlayerRank(playerName, RankType::Fool, bossAttackTimer);

		system("pause");
	}

	void OnPlayerLose()
	{
		isPlay = false;
		clrscr();
		gotoXY(60, 2);
		cout << "******************************";
		gotoXY(60, 3);
		cout << "*         Lose         *";
		gotoXY(60, 4);
		cout << "******************************";
		gotoXY(60, 20);
		system("pause");
	}

};

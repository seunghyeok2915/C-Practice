#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <time.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <Windows.h>
#include <cstring>
#include <algorithm>
#include <vector>
#include<MMSystem.h> // 배경음악 때문에 사용
#pragma comment(lib,"Winmm.lib") // 배경음악

#include "cGameEngine.h"
#include "LivingEntity.h"

using namespace std;
#define QUESTIONLINE 1000
bool isPlay;
int i = 0;
string playerName = "";

void OnPlayerWin() //UI
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
	//PlayerRank player = PlayerRank(playerName, RankType::Fool, time);
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

void drawUI(string name, float hp, float maxHp, int x, int y, int numOfBar)
{
	float temp = (float)hp / (float)maxHp;
	float a = numOfBar * temp;
	gotoXY(x, y);
	cout << name << " " << hp << " / " << maxHp;

	setTextColor(15);
	gotoXY(x, y + 1);
	for (int i = 0; i < numOfBar; i++)
	{
		cout << "-";
	}
	gotoXY(x, y + 2);
	for (int i = 0; i < numOfBar; i++)
	{
		cout << " ";
	}

	gotoXY(x, y + 2);
	for (int i = 0; i < numOfBar; i++)
	{
		if (i < a)
			setTextColor(4);
		else
			setTextColor(8);
		cout << "@";
	}

	setTextColor(15);
	gotoXY(x, y + 3);
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

class Monster : public LivingEntity
{
public:
	Monster(string _name, float _hp, float _damage) : LivingEntity(_name, _hp, _damage) {}
	virtual void onDamage(float damage)
	{
		system("color 4f");
		Sleep(50);
		hp -= damage;
		drawUI(name, hp, maxHp, 92, 19, 50);
		system("color 0f");
		if (hp <= 0)
			die();
	}
	virtual void die()
	{
		OnPlayerWin();
		return;
	}
};

class Player : public LivingEntity
{
public:
	Player(string _name, float _hp, float _damage) : LivingEntity(_name, _hp, _damage) {}
	virtual void onDamage(float damage)
	{
		system("color 4f");
		Sleep(50);
		hp -= damage;
		drawUI(name, hp, maxHp, 0, 30, 50);
		system("color 0f");
		if (hp <= 0)
			die();
	}
	virtual void die()
	{
		OnPlayerLose();
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
		answer = "없음";
		dmg = 0;
	}
	string question;
	string answer;
	int dmg;
};

class GameManager // 게임의 전체적인 내용을 담당함
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

	void Init(string playerName, float playerHp, float playerDamage, string bossName, float bossHp, float BossDamage) //초기설정
	{
		player = new Player(playerName, playerHp, playerDamage);
		monster = new Monster(bossName, bossHp, BossDamage);
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
				if (ans == curQuestion->answer) //문제 맞추는 부분
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

	void drawBackGround(int x, int y, string fileName) //백그라운드 그리기
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
	}//문제 그리기ㅣ

	void pickRandQuestion() // 랜덤 문제 뽑기
	{
		int value = rand() % QUESTIONLINE;

		if (!questionList[value]->isUsed) //사용하지 않은 문제라면
		{
			curQuestion = questionList[value];
			curQuestion->isUsed = true;
		}
		else pickRandQuestion();
	}

};

int SelectLevel() // 레벨 선택
{
	int y = 8;
	while (1)
	{
		system("cls");
		gotoXY(60, 2);
		cout << "******************************";
		gotoXY(60, 3);
		cout << "*         난이도선택         *";
		gotoXY(60, 4);
		cout << "******************************";
		gotoXY(60, 8);
		cout << "초보자 모드";
		gotoXY(60, 9);
		cout << "도전자 모드";
		gotoXY(60, 10);
		cout << "헬 모드" << endl;
		gotoXY(60, 11);
		cout << "랭킹 보기" << endl;
		gotoXY(60, 20);
		cout << "시작 하려면 엔터" << endl;

		gotoXY(75, y);
		cout << "☜";

		switch (_getch())
		{
		case 80:
			y++;
			break;
		case 72:
			y--;
			break;
		case 13:
			return y - 8;
			break;
		default:
			break;
		}
	}
}


enum class RankType
{
	Genius,
	Fool
};

class PlayerRank //랭킹 시스템
{
public:
	string name;
	RankType rankType;
	int time;
	PlayerRank() {}
	PlayerRank(string name, RankType rankType, int time)
	{
		this->name = name;
		this->rankType = rankType;
		this->time = time;
	}
};

bool compareFunction(const PlayerRank* o1, const PlayerRank* o2) {
	return o1->time < o2->time;
}


class RankManager
{
public:
	PlayerRank* allPlayer[100];
	vector<PlayerRank*> geniusPlayers;
	vector<PlayerRank*> foolPlayers;
	RankManager() {}
	static RankManager& instance()
	{
		if (instance_ == NULL)
		{
			instance_ = new RankManager();
		}

		return *instance_;
	}
	static RankManager* instance_;

	void SetPlayerList() //플레이어 리스트를 가져오는 함수
	{
		ifstream playerRank;
		string buffer;
		playerRank.open("PlayerRank.txt");
		foolPlayers.clear();
		geniusPlayers.clear();
		while (!playerRank.eof()) 
		{
			getline(playerRank, buffer);
			vector<string> v = split(buffer, "/");

			allPlayer[i] = new PlayerRank();

			if (v.back() == "Fool")
			{
				allPlayer[i]->rankType = RankType::Fool;
				v.pop_back();
				foolPlayers.push_back(allPlayer[i]);
			}
			else
			{
				allPlayer[i]->rankType = RankType::Genius;
				v.pop_back();
				geniusPlayers.push_back(allPlayer[i]);
			}


			allPlayer[i]->time = stoi(v.back());
			v.pop_back();

			allPlayer[i]->name = v.back();

			i++;
		}
		playerRank.close();
	} 

	void AddPlayer(PlayerRank newPlayer) //PlayRank 클래스를 받아서 파일에 저장해주는 함수
	{
		SetPlayerList();
		ofstream ofile;
		ofile.open("PlayerRank.txt");
		for (int j = 0; j < i; j++)
		{
			string playerData = allPlayer[j]->name + "/" + to_string(allPlayer[j]->time) + "/";
			switch (allPlayer[j]->rankType)
			{
			case RankType::Fool:
				playerData += "Fool";
				break;
			case RankType::Genius:
				playerData += "Genius";
				break;
			}
			playerData += "\n";
			ofile.write(playerData.c_str(), playerData.size());
		}

		string playerData = newPlayer.name + "/" + to_string(newPlayer.time) + "/";
		switch (newPlayer.rankType)
		{
		case RankType::Fool:
			playerData += "Fool";
			break;
		case RankType::Genius:
			playerData += "Genius";
			break;
		}
		ofile.write(playerData.c_str(), playerData.size());

		ofile.close();
	}

	void GetGeniusRank() // 천재플레이어 가져오는 함수
	{
		SetPlayerList();
		sort(geniusPlayers.begin(), geniusPlayers.end(), compareFunction);
		gotoXY(10, 9);
		cout << "천재 순위";
		for (int j = 0; j < geniusPlayers.size(); j++)
		{
			gotoXY(10, 10 + j);
			cout << j + 1 << ". " << geniusPlayers[j]->name << " " << geniusPlayers[j]->time << "초 만에 클리어 하셨습니다.";
		}
	}

	void GetFoolRank() // 바보플레이어 가져오는 함수
	{
		SetPlayerList();
		sort(foolPlayers.begin(), foolPlayers.end(), compareFunction);
		gotoXY(70, 9);
		cout << "바보 순위";
		for (int j = 0; j < foolPlayers.size(); j++)
		{
			gotoXY(70, 10 + j);
			cout << j + 1 << ". " << foolPlayers[j]->name << " " << foolPlayers[j]->time << "초 만에 죽으셨습니다.";
		}
	}
};



int main()
{
	setConsoleView();
	srand((unsigned)time(NULL));
	sndPlaySoundA("bg.wav", SND_ASYNC);

	Question* questions[QUESTIONLINE];
	ifstream mathQusetion;
	string buffer;

	RankManager* rankManager = new RankManager();

	gotoXY(50, 10);
	cout << "MATH RPG 게임은 수학 문제를 풀고 적을 몰아내는 게임입니다.";
	gotoXY(50, 11);
	cout << "적은 일정 시간마다 플레이어를 공격하니 조심하세요!";
	gotoXY(50, 20);
	cout << "플레이어 이름을 입력해주세요 : ";
	cin >> playerName;

	while (true)
	{
		int level = SelectLevel();

		switch (level)
		{
		case 0:
			mathQusetion.open("MathQuestions1.txt");
			break;
		case 1:
			mathQusetion.open("MathQuestions2.txt");
			break;
		case 2:
			mathQusetion.open("MathQuestions3.txt");
			break;
		case 3:
			clrscr();
			rankManager->GetFoolRank();
			rankManager->GetGeniusRank();
			gotoXY(1, 1);
			cout << "돌아가려면 엔터";
			while (true)
			{
				if (getKeyDown() == 13)
				{
					break;
				}
			}
			continue;
		}

		for (int i = 0; i < QUESTIONLINE; i++) // 문제 저장
		{
			getline(mathQusetion, buffer);
			vector<string> v = split(buffer, "ans,dmg");

			questions[i] = new Question();
			questions[i]->dmg = stoi(v.back());
			v.pop_back();
			questions[i]->answer = v.back();
			questions[i]->answer.erase(remove(questions[i]->answer.begin(), questions[i]->answer.end(), ' '), questions[i]->answer.end());
			v.pop_back();
			questions[i]->question = v.back();
			v.pop_back();
		}
		mathQusetion.close();

		GameManager gameManager(questions, QUESTIONLINE);
		switch (level)
		{
		case 0:
			gameManager.Init("John", 1000, 200, "Boss", 1000, 100);
			break;
		case 1:
			gameManager.Init("John", 3000, 200, "Boss", 2000, 100);
			break;
		case 2:
			gameManager.Init("John", 1000, 1000, "Boss", 10000, 100);
			break;
		}
		gameManager.run();
	}

	return 0;
}



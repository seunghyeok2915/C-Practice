#include <iostream>
#include <Windows.h>
using namespace std;

#define MAZESIZE_X 12
#define MAZESIZE_Y 22
#define EXIT_X 11
#define EXIT_Y 16

typedef struct Position
{
	int x;
	int y;
	int d;
} Position;
typedef struct Mtable
{
	int x;
	int y;
} Mtable;
int Maze[12][22] = {
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
Mtable Move[4] = {
	{0,1},
	{1,0},
	{0,-1},
	{-1,0}
};
int Mark[MAZESIZE_X][MAZESIZE_Y];
int top;
Position Trace[(MAZESIZE_X - 2) * (MAZESIZE_Y - 2)];

void ShowMaze(Position);
void Push(Position);
void Pop(Position* P);

void MakeMap()
{
	srand((unsigned)time(NULL));
	for (int i = 0; i < 80; i++)
	{
		int ranX = rand() % 22 + 1;
		int ranY = rand() % 12 + 1;
		if (Maze[ranY][ranX] != 1)
		{
			Maze[ranY][ranX] = 1;
		}
		else
		{
			i--;
		}
	}
}


int main()
{
	MakeMap();
	int isFound = FALSE;
	int i, dir = 0;
	Position Now = { 1,1,0 };
	Position Next;
	Push(Now);

	while (!isFound && top > 0)
	{
		Pop(&Now);
		while (dir < 4)
		{
			Next.x = Now.x + Move[dir].x;
			Next.y = Now.y + Move[dir].y;
			if (Next.x == EXIT_X && Next.y == EXIT_Y)
			{
				Next.d = dir;
				Push(Next);
				isFound = TRUE;
				break;
			}
			else if ((Maze[Next.x][Next.y] == 0) && (Mark[Next.x][Next.y] == 0))
			{
				Now.d = ++dir;
				Push(Now);
				Now.x = Next.x;
				Now.y = Next.y;
				dir = 0;

				Mark[Next.x][Next.y] = 1;
			}
			else dir++;

			ShowMaze(Now);
		}
	}
	if(isFound == TRUE)
		for (int i = 0; i < top; i++)
		{
			ShowMaze(Trace[i]);
		}
	else
	{
		cout << "출구를 못찾았어용" << endl;
	}

	system("pause");
	return 0;
}

void ShowMaze(Position P)
{
	int i, j;
	Sleep(50);
	system("cls");

	cout << " 출구는 (11,16)" << endl;
	cout << "현재좌표는 " << P.x << " " << P.y << " " << P.d << endl;

	for (int i = 0; i < MAZESIZE_X; i++)
	{
		for (int j = 0; j < MAZESIZE_Y; j++)
		{
			if (Maze[i][j] == 1) cout << "#";
			else if (P.x == i && P.y == j)
				cout << "&";
			else cout << " ";
		}
		cout << endl;
	}
}

void Push(Position P)
{
	Trace[top].x = P.x;
	Trace[top].y = P.y;
	Trace[top].d = P.d;
	top++;
}

void Pop(Position* P)
{
	top--;
	P->x = Trace[top].x;
	P->y = Trace[top].y;
	P->d = Trace[top].d;
}
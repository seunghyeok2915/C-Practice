// 1708순위구하기.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
int main() {
	int num;
	int score[1000];
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		cin >> score[i];
	}

	for (int i = 0; i < num; i++) {
		cout << score[i] << " ";
		int order = 1;
		for (int j = 0; j < num; j++) 
		{
			if (score[i] < score[j])
				order++;
		}
		cout << order << endl;
	}

	return 0;
}

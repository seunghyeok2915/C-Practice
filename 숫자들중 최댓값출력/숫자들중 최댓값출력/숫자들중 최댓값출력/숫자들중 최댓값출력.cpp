//20312이승혁
#include <iostream>

using namespace std;

int FindMaxRecursive(int num[], int n) //n 은 배열의 개수임.
{
	if (n == 1)
	{
		if (num[n] > num[n - 1])
			return num[n];
		else
			return num[n - 1];
	}

	if (num[n] > FindMaxRecursive(num, n - 1))
		return num[n];
	else return FindMaxRecursive(num, n - 1);
}
int main()
{
	int a[100];
	int num = 0;
	cout << " 하나씩 입력해줘 0하면 입력 끝이야.";

	for (int i = 0; i < 100; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
		{
			break;
		}
		num++;
	}
	cout << FindMaxRecursive(a, num);


}
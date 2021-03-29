#include <iostream>

using namespace std;

int sum = 0;
int b = 0;
int Maxnum(int a[], int i)
{
	if (sum < a[b])
		sum = a[b];
	++b;
	if (b == i)
	{
		return sum;
	}
	else
	{
		Maxnum(a, i);
	}
}
int main()
{
	int a[100];
	int i = 0;
	cout << "숫자를 입력해주세요 0은 끝";
	while (a[i - 1] != 0)
	{
		cin >> a[i];
		++i;
	}
	cout << Maxnum(a , i);

	
}
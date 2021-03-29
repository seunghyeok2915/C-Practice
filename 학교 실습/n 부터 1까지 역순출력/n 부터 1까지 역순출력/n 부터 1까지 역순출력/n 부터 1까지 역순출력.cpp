#include <iostream>
using namespace std;

void ReverseNum(int n)
{
	if (n == 0)
		return;
	cout << n << endl;
	--n;
	ReverseNum(n);
}

int main()
{
	ReverseNum(100);
}

#include <iostream>

using namespace std;

int Gausfuc(int a)
{
	if (a == 1)
	{
		return 1;
	}
	else
		return Gausfuc(a - 1) + a;
}
int main()
{
	cout << Gausfuc(100);
}
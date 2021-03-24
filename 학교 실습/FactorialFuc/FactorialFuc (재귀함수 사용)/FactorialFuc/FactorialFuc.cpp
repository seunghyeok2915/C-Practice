#include <iostream>

using namespace std;
int sum = 1;
void FactorialFuc(int a)
{
	if (a != 0)
	{
		sum *= a;
		--a;
		FactorialFuc(a);
	}
	else
		cout << sum;
}
int main()
{
	FactorialFuc(5);
}


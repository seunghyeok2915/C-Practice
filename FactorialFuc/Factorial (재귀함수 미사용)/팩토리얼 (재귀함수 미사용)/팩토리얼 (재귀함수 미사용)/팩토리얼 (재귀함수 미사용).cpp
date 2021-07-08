#include <iostream>

int factorialFun(int a)
{
	int sum = 1;
	for (int i = a; i > 0; i--)
	{
		sum *= i;
	}
	return sum;
}
int main()
{
	std::cout << factorialFun(5);
}

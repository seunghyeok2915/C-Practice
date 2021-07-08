#include <iostream>

using namespace std;

void Reversenum(int a)
{
	if (a > 0)
	{

		cout << a % 10;
		a = a / 10;
		Reversenum(a);
	}
}

int main()
{
    int a;  
    cin >> a;
	Reversenum(a);
}


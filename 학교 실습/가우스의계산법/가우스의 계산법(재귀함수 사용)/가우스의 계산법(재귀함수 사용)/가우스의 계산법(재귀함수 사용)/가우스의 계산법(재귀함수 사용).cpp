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
		int a = 0;
		cin >> a;
		cout << Gausfuc(a);
	}
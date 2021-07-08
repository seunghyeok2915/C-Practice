//20312이승혁
#include <iostream>
#include <stack>
#include <string>

using namespace std;
int main()
{
	stack<char> stack;

	string a;

	cout << "현우야 어떤숫자를 쓰렴" << endl;

	cin >> a;
	for (int i = 0; i < a.length(); i++)
	{
		if (0 < a[i] - '0' && a[i] - '0' < 9)
			stack.push(a[i]);
		else
		{
			cout << "정수가 아닌게 들어가있습니다. 프로그램을 종료합니다.";
			return 0;
		}

	}

	while (!stack.empty())
	{
		cout << stack.top();
		stack.pop();
	}
}


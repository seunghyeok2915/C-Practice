//20312 이승혁

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	string s;
	stack<char> stack1;

	stack<char> stack;

	int n = 0;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (0 < s[i] - '0' && s[i] - '0' < 9)
			stack.push(s[i]);
		else
		{
			cout << "정수만 입력해줘요!";
			return 0;
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		stack1.push(stack.top());
		stack.pop();

		n++;
		if (n % 3 == 0 && n < s.length())
		{
			stack1.push(',');
		}
	}

	while (!stack1.empty())
	{
		cout << stack1.top();
		stack1.pop();
	}

}


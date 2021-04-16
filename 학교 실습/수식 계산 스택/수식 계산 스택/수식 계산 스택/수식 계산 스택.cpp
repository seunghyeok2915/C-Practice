#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

struct oper {
	int p;
	string o;
};

stack<int> num;
stack<oper> op;

void calc() {
	int a, b, result;
	b = num.top();
	num.pop();
	a = num.top();
	num.pop();
	string oper = op.top().o;
	op.pop();

	if (oper == "*")
		result = a * b;
	else if (oper == "/")
		result = a / b;
	else if (oper == "+")
		result = a + b;
	else if (oper == "-")
		result = a - b;
	num.push(result);
}

int main() {
	string input = "( 1 + 9 ) * 3 / 3 - 2"; // 8
	stringstream ss(input);
	string tok;
	while (ss >> tok) {
		if (tok == "(") {
			op.push({ 0, tok });
		}
		else if (tok == ")") {
			while (op.top().o != "(")
				calc();
			op.pop();
		}
		else if (tok == "*" || tok == "/" || tok == "+" || tok == "-") {
			int prior = 0;
			if (tok == "*")
				prior = 2;
			else if (tok == "/")
				prior = 2;
			else if (tok == "+")
				prior = 1;
			else if (tok == "-")
				prior = 1;

			while (!op.empty() && prior <= op.top().p)
				calc();
			op.push({ prior, tok });
		}
		else
			num.push(stoi(tok));
	}
	while (!op.empty())
		calc();

	cout << num.top();

	return 0;
}

//20312이승혁
#include <iostream>
#include <stack>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

double PostCalculator(char exp[]) {
    stack<double> stack;
    int len = strlen(exp);
    char tok;
    for (int i = 0; i < len; i++) {
        tok = exp[i];
        if (isdigit(tok)) {
            stack.push((double)(tok - '0'));
        }
        else {
            double op2 = stack.top(); stack.pop();
            double op1 = stack.top(); stack.pop();

            switch (tok) {
            case '+':
                stack.push(op1 + op2);
                break;
            case '-':
                stack.push(op1 - op2);
                break;
            case '*':
                stack.push(op1 * op2);
                break;
            case '/':
                stack.push(op1 / op2);
                break;
            }
        }
    }
    return stack.top();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    stack<char> op;
    queue<char> qc;
    cin >> s;

    char num[100] = { 0, };

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            qc.push(s[i]);
        }
        else
        {
            if (s[i] == '(')
                op.push(s[i]);
            else if (s[i] == '*' || s[i] == '/')
            {
                while (!op.empty() && (op.top() == '*' || op.top() == '/'))
                {
                    qc.push(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                while (!op.empty() && op.top() != '(')
                {
                    qc.push(op.top());
                    op.pop();
                }
                op.push(s[i]);
            }
            else if (s[i] == ')')
            {
                while (!op.empty() && op.top() != '(')
                {
                    qc.push(op.top());
                    op.pop();
                }
                op.pop();
            }
        }
    }
    string sss = "";
    while (!op.empty())
    {
        qc.push(op.top());
        op.pop();
    }

    int i = 0;
    while (!qc.empty())
    {
        num[i] = qc.front();
        i++;
        qc.pop();
    }

    cout << PostCalculator(num);


    return 0;
}
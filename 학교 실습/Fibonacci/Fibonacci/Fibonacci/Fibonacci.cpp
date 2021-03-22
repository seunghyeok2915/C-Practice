#include <iostream>

using namespace std;

int a = 0, b = 1;
int num = 0;
void FibonacciFuc(int a,int b)
{
    a = a + b;
    cout << a<<endl;
    b = a + b;
    cout << b;
    cout << endl;
    ++num;
    if (num == 22)
    {
        cout << "끝";
    }
    else
    {

    FibonacciFuc(a, b);
    }
}

int main()
{
    FibonacciFuc(a, b);
}


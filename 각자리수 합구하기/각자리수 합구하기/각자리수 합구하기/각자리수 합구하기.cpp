#include <iostream>
using namespace std;
int sum = 0;
void SumOfnum(int n)
{
    if (n == 0)
    {
        cout << sum;
        return;
    }
    sum += n % 10;
    n /= 10;

    SumOfnum(n);
}

int main()
{
    int a = 55215;
    SumOfnum(a);
}

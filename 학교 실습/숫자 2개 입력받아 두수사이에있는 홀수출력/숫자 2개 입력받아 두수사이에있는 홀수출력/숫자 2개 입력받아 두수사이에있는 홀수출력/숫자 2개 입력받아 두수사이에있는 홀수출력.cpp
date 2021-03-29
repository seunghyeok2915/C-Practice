#include <iostream>
int n = 0;
using namespace std;
void CoutOddNum(int a, int b)
{
    if (n < a)
    {
        ++n;
        CoutOddNum(a, b);
    }
    if (n > b)
    {
        return;
    }
    if (n % 2 == 1)
    {
        cout << n << " ";
        ++n;
        CoutOddNum(a, b);
    }
    else
    {
        ++n;
        CoutOddNum(a, b);
    }
}
int main()
{
    int a = 0;
    int b = 100;
    CoutOddNum(a, b);
}

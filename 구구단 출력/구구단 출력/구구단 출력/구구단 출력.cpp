#include <iostream>
using namespace std;

    int x = 1;
void Gugudan(int a, int b, int c)
{
    cout << a << " x " << x << " = " << a * x << endl;
    ++x;
    if (x == c)
    {
        ++a;
        x = 1;
        if(a == b)
            return;
    }

    Gugudan(a, b, c);
}
int main()
{
    int a = 1, b = 10; // 1~ 9
    int c = 10; // 9 까지 곱함
    Gugudan(a, b, c);
}

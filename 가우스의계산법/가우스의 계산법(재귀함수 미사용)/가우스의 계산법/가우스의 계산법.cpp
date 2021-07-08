#include <iostream>
using namespace std;
int sum = 0;
void GausFuc(int n)
{
    sum = ((1 + n) * n) / 2;
    cout << sum;
}
int main()
{
    GausFuc(100);
}


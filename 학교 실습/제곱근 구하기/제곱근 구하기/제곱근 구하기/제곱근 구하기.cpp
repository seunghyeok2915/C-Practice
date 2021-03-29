
#include <stdio.h>
#include <iostream>
#include <conio.h>

using namespace std;

double sqrt(double a)
{
    double x = 71;

    for (int i = 0; i < 10; i++)
    {
        x = (x + (a / x)) / 2;
    }

    return x;
}

void main()
{
    double a;

    cin >> a;

    double result = sqrt(a);

    cout << result;

}
//20312이승혁
#include <iostream>
using namespace std;

void ReverseChar(char a[])
{
    int i, len = 0;

    while (a[len] != 0) len++;

    for (i = len - 1; i >= 0; i--) {
        cout << a[i];
    }
    cout << endl;
}

int main()
{
    char word[3][10] = { 0, };

    for (int i = 0; i < 3; i++)
    {
        cin >> word[i];
    }

    ReverseChar(word[0]);
    ReverseChar(word[1]);
    ReverseChar(word[2]);
}
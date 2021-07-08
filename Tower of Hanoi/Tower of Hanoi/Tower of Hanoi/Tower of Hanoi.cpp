#include <iostream>
int Hanoi(int from, int to, int n);
using namespace std;
int main()
{
    Hanoi(1, 5, 6);
}

int Hanoi(int from, int to, int n) // from번 기둥에서 to번 기둥으로 n개
{
    if (n == 1)
    {
        cout << from << "번 기둥에서" << to << "번 기둥으로 이동" << endl;
        return 0;
    }

    Hanoi(from, 6 - from - to, n - 1);
    cout << from << "번 기둥에서" << to << "번 기둥으로 이동" << endl;
    Hanoi(6 - from - to, to, n - 1);
    return 0;
}
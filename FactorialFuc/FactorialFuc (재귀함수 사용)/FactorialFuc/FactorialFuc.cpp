#include <iostream>

using namespace std;

int FactorialRecursive(int n)
{
    if (n == 1)    
        return 1;   
    return n * FactorialRecursive(n - 1);
}

int main()
{
	cout << FactorialRecursive(5);
}


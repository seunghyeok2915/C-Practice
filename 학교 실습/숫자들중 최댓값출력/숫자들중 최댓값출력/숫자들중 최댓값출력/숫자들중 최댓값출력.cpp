#include <iostream>

using namespace std;

#define MAX(x,y) ((x) > (y) ? (x) : (y))

int findMax(int arr[], int n)
{
	if (n == 1)
		return MAX(arr[n], arr[n - 1]);
	return MAX(arr[n], findMax(arr, n - 1));
}
int main()
{
	int a[100] = { 1,8,2,5,8,10 };
	cout << findMax(a, 6);
}
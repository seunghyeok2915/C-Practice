#include <iostream>

using namespace std;


int main()
{
	int n = 0;
	cout << "서브넷 마스크 1개수 입력";
	cin >> n;

	int temp = 256 / pow(2, n);
	int tempp = pow(2, n);
	int m = 0;
	n = 0;
	for (int i = 0; i < tempp; i++)
	{
		n += temp;
		cout << m << " ~ " << n - 1 << endl;
		m += temp;
	}
}
ㅇ

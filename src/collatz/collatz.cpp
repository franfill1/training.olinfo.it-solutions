#include<iostream>
using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	
	int L = 1;
	while(N != 1)
	{
		if (N % 2 == 0)
		{
			N = N / 2;
		}
		else
		{
			N = N * 3 + 1;
		}
		L = L + 1;
	}
	cout << L;
}

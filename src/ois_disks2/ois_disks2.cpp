#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, T;
	cin >> N >> T;
	int a, b;
	cin >> a >> b;

	for (int i = 0; i < N-1; i++)
	{
		cin >> a;
		if (24-b + a >= T)
		{
			cout << i << "\n";
			return 0;
		}
		cin >> b;
	}
	cout << -1 << "\n";
}

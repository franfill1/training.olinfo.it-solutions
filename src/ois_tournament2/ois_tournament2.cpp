#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int N, R, T;
	cin >> N >> R >> T;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int x;
		cin >> x;
		sum += x;
	}
	if (sum >= (R+T)*N)
		cout << "Cheater\n";
	else
		cout << "Innocent\n";
}

int main()
{
	int K;
	cin >> K;
	while(K--)
		solve();
}

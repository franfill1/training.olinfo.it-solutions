#include<bits/stdc++.h>
using namespace std;

void solve()
{
	int N, Q;
	cin >> N >> Q;
	vector < int > P(N);
	for (auto &p : P)
		cin >> p;
	int cur = 0;
	vector < int > L(Q);
	for (auto &l : L)
		cin >> l;
	for (auto &l : L)
	{
		if (l > 0)
			cur += l;
		else
		{
			if ((cur -= P[-l-1]) < 0)
			{
				cout << "HACKER\n";
				return;
			}
		}
	}
	cout << "OK\n";
	return;
}

int main()
{
	int T;
	cin >> T;
	while(T--)
		solve();
}

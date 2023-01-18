#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map < int , int > st, en;
	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		st[a]++, en[b]++;
	}
	for (auto [x, c] : st)
		N -= min(c, en[x]);
	cout << N << "\n";
}

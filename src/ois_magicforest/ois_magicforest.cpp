#include<bits/stdc++.h>
using namespace std;
constexpr int MOD = 1000000007;

int main()
{
	int n, m;
	cin >> n >> m;
	map < int , vector < pair < int , int > > > g;
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[w].emplace_back(a, b);
		g[w].emplace_back(b, a);
	}
	vector < map < int , int > > dp(n);
	int ans = -m;
	for (auto it = g.rbegin(); it != g.rend(); it++)
	{
		int e = it->first;
		for (auto [a, b] : it->second)
		{
			ans = (ans+dp[b][e+1]+1) % MOD;
			dp[a][e] = (dp[a][e]+dp[b][e+1]+1) % MOD;
		}
	}
	cout << ans << "\n";
}

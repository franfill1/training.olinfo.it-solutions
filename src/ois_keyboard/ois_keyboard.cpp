#include<bits/stdc++.h>
using namespace std;
constexpr int inf = 1<<30;

inline int pos_of(int d, int a = 0, int b = 0)
{
	if (d == a | d == b)
		d = a + b - d;
	return d;
}

int dp[100001][10][10];
void solve()
{
	string s;
	cin >> s;
	for (int a = 0; a < 10; a++)
		for (int b = 0; b <= a; b++)
			if (a == 0 && b == 0)
				dp[0][a][b] = 0;
			else
				dp[0][a][b] = inf;
	for (int i = 0; i < s.size(); i++)
		for (int a = 10; a >= 0; a--)
			for (int b = 0; b <= a; b++)
			{
				if (a == b && a > 0)
					continue;
				int lp = i ? pos_of(s[i-1]-'0', a, b) : 0, c = s[i] - '0';
				int p = c;
				dp[i+1][a][b] = min(inf, dp[i][a][b] + abs(pos_of(c, a, b) - lp));
				if (a == 0 && b == 0)
					for (int d = 0; d < 10; d++)
					{
						int na = max(c, d), nb = min(c, d);
						dp[i+1][na][nb] = min(dp[i+1][na][nb], dp[i][a][b] + abs(d - lp));
					}
			}
	int ans = dp[s.size()][0][0];
	for (int a = 1; a < 10; a++)
		for (int b = 0; b < a; b++)
		{
			ans = min(ans, dp[s.size()][a][b]);
		}
	cout << ans << "\n";
}

int main()
{
 	int t;
	cin >> t;
	while(t--)
		solve();
}

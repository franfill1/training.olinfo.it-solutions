#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1000000][3][3];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N, M=1000000;
	cin >> N >> M;
	string s;
	cin >> s;

	for (int x = 0; x <= 2; x++) for (int y = 0; y <= 2; y++) dp[0][x][y] = 1;

	for (int c = 1; c < N; c++)
	{
		for (int x = 0; x <= 2; x++) for (int y = 0; y <= x; y++)
		{
			dp[c][x][y] = 0;
			if (y < 2) dp[c][x][y] += dp[c-1][max(x-1, 0)][y+1];
			if (x < 2) dp[c][x][y] += dp[c-1][x+1][max(y-1, 0)];
			dp[c][x][y] %= M;
			dp[c][y][x] = dp[c][x][y];
		}
	}

	int ans = 1;
	int x=0, y=0;
	for (int i = 0; i < N; i++)
	{
		if (s[i] == 'P')
		{
			if (x < 2)
			{
				ans += dp[N-i-1][x+1][max(y-1, 0)];
				ans %= M;
			}
			y++;
			x = max(x-1, 0);
		}
		else
		{
			x++;
			y = max(y-1, 0);
		}
	}
	cout << ans << "\n";
}

#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

typedef long long ll;

int ContaPercorsi(int N, int M, int K, int* X, int* Y) 
{
	queue < pair < ll , ll > > q;
	vector < vector < ll > > p(N, vector < ll > (M, 1<<30));
    for (ll i = 0; i < K; i++)
    {
    	pair < ll , ll > pa = {X[i], Y[i]};
    	q.push(pa);
    	p[pa.first][pa.second] = 0;
	}
	while(!q.empty())
	{
		ll x = q.front().first, y = q.front().second;
		q.pop();
		ll d = p[x][y];
		
		vector < int > dx {0, 0, 1, -1};
		vector < int > dy {1, -1, 0, 0};
		for (ll i = 0; i < 4; i++)
		{
			ll nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < M && p[nx][ny] > d+1)
			{
				p[nx][ny] = d+1;
				q.push({nx, ny});
			}
		}
	}
	
	vector < vector < ll > > dp(N, vector < ll > (M, 0));
	dp[0][0] = p[0][0];
	for (ll i = 0; i < N; i++)
	{
		for (ll j = 0; j < M; j++)
		{
			if (i > 0)
			{
				dp[i][j] = max(min(dp[i-1][j], p[i][j]), dp[i][j]);
			}
			if (j > 0)
			{
				dp[i][j] = max(min(dp[i][j-1], p[i][j]), dp[i][j]);
			}
		}
	}
	
	ll t = dp[N-1][M-1];
	
	vector < vector < ll > > memo(N, vector < ll > (M, 0));
	memo[N-1][M-1] = 1;
	for (ll i = N-1; i >= 0; i--)
	{
		for (ll j = M-1; j >= 0; j--)
		{
			if (p[i][j] < t)
			{
				continue;
			}
			if (i < N-1)
			{
				memo[i][j] += memo[i+1][j];
				memo[i][j] %= MOD;
			}
			if (j < M-1)
			{
				memo[i][j] += memo[i][j+1];
				memo[i][j] %= MOD;
			}
		}
	}
	return memo[0][0];
}
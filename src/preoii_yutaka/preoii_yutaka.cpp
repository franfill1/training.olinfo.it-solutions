#include <bits/stdc++.h>
#define M 1000000007

using namespace std;

typedef long long ll;

int taglia(int N, int sushi[])
{
	vector < ll > dp(N+1, 0);
	dp[N] = 1;
	vector < ll > sum(N+2, 0);
	sum[N] = 1;
	vector < int > last(10000000, N+1);
	
	ll j = N+1;
	
	for (ll i = N-1; i >= 0; i--)
	{
		if (last[sushi[i]] < j)
		{
			j = last[sushi[i]];
		}
		last[sushi[i]] = i+1;
		dp[i] = (sum[i+1] - sum[j]);
		dp[i] = (dp[i] %M + M) % M;		
		sum[i] = (sum[i+1] + dp[i]);
		sum[i] = (sum[i]%M + M) % M;
	}
	return dp[0];
}
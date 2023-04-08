#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll T;
ll calc(ll t)
{
	ll b = (t / (2*T))*2*T;
	if (t >= b+T) return b + 2*T;
	return t;
}

int main()
{
	int N, R, L;
	cin >> N >> R >> T >> L;
	vector < ll > X(N);
	for (ll &x : X) cin >> x;
	X.push_back(L);
	
	vector < vector < ll > > dp(N+1, vector < ll > (R+1, 1ll<<60));
	dp[0][R] = X[0];
	for (int i = 0; i < N; i++)
	{
		dp[i+1][0] = calc(dp[i][0]) + X[i+1] - X[i];
		for (int r = 1; r <= R; r++)
		{
			dp[i+1][r] = min(dp[i+1][r], calc(dp[i][r]) + X[i+1] - X[i]);
			dp[i+1][r-1] = min(dp[i+1][r-1], dp[i][r] + X[i+1] - X[i]);
		}
	}
	ll ans = 1ll<<60;
	for (int r = 0; r <= R; r++) ans = min(ans, dp[N][r]);
	cout << ans << "\n";
}



#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;
constexpr ll MAXV = 200001;
constexpr ll MAXK = 100;

ll modpow(ll b, ll e)
{
	if (e == 0)
		return 1;
	ll t = modpow(b, e/2);
	t = t * t % MOD;
	if (e % 2)
		t = t * b % MOD;
	return t;
}

inline ll inv (ll x)
{
	return modpow(x, MOD-2);
}

ll fact[MAXV], ifact[MAXV], sfact[MAXV];
inline ll bin(ll n, ll x)
{
	return fact[n] * ifact[x] % MOD * ifact[n-x] % MOD;
}

ll tr[MAXK][MAXK], dp[MAXK+1][MAXK];
int main()
{
	fact[0] = 1;
	for (int i = 1; i < MAXV; i++)
		fact[i] = fact[i-1]*i % MOD;
	ifact[MAXV-1] = inv(fact[MAXV-1]);
	for (int i = MAXV-2; i >= 0; i--)
		ifact[i] = ifact[i+1] * (i+1) % MOD;

	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int v;
		cin >> v;
		int r = 0;
		for (int x = 0; x <= v; x++)
		{
			tr[i][r] += bin(v, x);
			r += i+1;
			if (r >= K)
				r -= K;
		}
		for (int x = 0; x < K; x++)
			tr[i][x] %= MOD;
	}
	dp[K][0] = 1;
	for (int i = K-1; i >= 0; i--)
		for (int r = 0; r < K; r++)
		{
			int j = r;
			for (int x = 0; x < K; x++)
			{
				dp[i][r] += dp[i+1][j] * tr[i][x] % MOD;
				j++;
				if (j == K)
					j = 0;
			}
			dp[i][r] %= MOD;
		}
	cout << dp[0][0] << "\n";
}

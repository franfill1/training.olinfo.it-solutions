#include<bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr ll MOD = 1000000007;
constexpr ll MAXN = 100001;

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

inline ll inv(ll x)
{
	return modpow(x, MOD-2);
}

ll fact[MAXN];

inline ll bin(ll n, ll x)
{
	assert(0 <= x && x <= n);
	return fact[n] * inv(fact[x]) % MOD * inv(fact[n-x]) % MOD;
}

int main()
{
	int n;
	cin >> n;
	fact[0] = 1;
	for (int i = 1; i <= n; i++)
		fact[i] = fact[i-1]*i % MOD;
	map < ll , ll > cnt;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		cnt[x]++;
	}

	ll ans = 1;
	for (ll y = 1; y <= n; y++)
	{
		vector < ll > rem;
		ll cur = 1;
		for (auto [x, c] : cnt)
		{
			if (c == y)
				rem.emplace_back(x);
			cur *= bin(c, y) + 1;
			cur %= MOD;
		}
		ans += cur-1;
		ans %= MOD;
		for (auto x : rem)
			cnt.erase(x);
	}
	cout << ans << "\n";
}

/**
* user:  t-emi-032
* fname: Roiti1
* lname: Liceo Scientifico A. Roiti, Ferrara
* task:  dream
* score: 100.0
* date:  2022-11-14 15:54:22.703436
*/
#include <bits/stdc++.h>
#define f first
#define s second
#define pii pair < int, int >
#define pll pair < ll, ll >
#define ll long long
#define pb push_back
#define popb pop_back

using namespace std;

#define MOD 666013

ll mod_pow(ll base, ll exp)
{
	if (exp == 0) return 1;
	ll n = mod_pow(base, exp / 2);
	if (exp % 2 == 0) return (n * n) % MOD;
	return (((n * n) % MOD) * base) % MOD;
}

int main()
{
	int K, X;
	cin >> K >> X;
	//ll ans = ((((K * (K - 1) / 2) % MOD) + ((mod_pow(10, X / 2 + 1) * K) % MOD)) * mod_pow(10, X / 2)) % MOD;
	ll dim = 1;
	ll ans = 0;
	bool ok = true;
	for (int i = X / 2 - 1; i > 0; i--)
	{
		if (dim > K)
		{
			ok = false;
			break;
		}
		ll cnt = K / (dim*10);
		ans += (((cnt * dim) % MOD * 45) % MOD * ((mod_pow(10, i) + mod_pow(10, X-i-1)) % MOD)) % MOD;
		ans %= MOD;
		ll res = K % (dim*10);
		int c = 0;
		while(res)
		{
			ll cnt = min(dim, res);
			ans += ((cnt * c) % MOD * ((mod_pow(10, i) + mod_pow(10, X-i-1)) % MOD)) % MOD;
			ans %= MOD;
			res -= cnt;
			c++;
		}
		dim *= 10;
	}
	if (!ok || dim*10 < K)
	{
		ans += (K * ((mod_pow(10, 0) + mod_pow(10, X-0-1)) % MOD)) % MOD;
		ans %= MOD;
	}
	else
	{
		//RICORDA i = 0
		ll res = K;
		{
			int c = 1;
			while(res && c < 10)
			{
				ll cnt = min(dim, res);
				ans += ((cnt * c) % MOD * ((mod_pow(10, 0) + mod_pow(10, X-0-1)) % MOD)) % MOD;
				ans %= MOD;
				c++;
				res -= cnt;
			}
		}
		
		ll cnt = res / (dim*10);
		ans += (((cnt * dim) % MOD * 45) % MOD * ((mod_pow(10, 0) + mod_pow(10, X-0-1)) % MOD)) % MOD;
		ans %= MOD;
		res = res % (dim*10);
		int c = 0;
		while(res)
		{
			ll cnt = min(dim, res);
			ans += ((cnt * c) % MOD * ((mod_pow(10, 0) + mod_pow(10, X-0-1)) % MOD)) % MOD;
			ans %= MOD;
			res -= cnt;
			cerr << res << "\n";
			c++;
		}
	}
	cout << ans << "\n";
	
}


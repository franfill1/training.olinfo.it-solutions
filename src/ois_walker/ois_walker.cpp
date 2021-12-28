#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");


typedef long long ll;

const ll M = 666013;

ll modpow(ll b, ll e)
{
	if (e == 0)
	{
		return 1;
	}
	ll ans = modpow(b, e/2);
	ans *= ans;
	if (e % 2)
	{
		ans *= b;
	}
	return ans % M;
}

main()
{
	ll N, K;
	fin >> N >> K;
	
	N %= M;
	
	ll r = (K / 2);

	ll x = N - 1;
	ll ans = (modpow(x, ((2*r) % (M-1))) - 1) * modpow(N, M - 2);
	ans %= M;
	
	if (K % 2)
	{
		ans *= x;
		ans %= M;
	}
	else
	{
		ans++;
		ans %= M;
	}
	fout << ans;
}
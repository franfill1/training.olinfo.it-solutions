#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll mod = 1000000007;

int main()
{
	int N;
	cin >> N;
	ll f1=1, f2=1, f3;
	for (int i = 1; i <= 2*N; i++)
	{
		f2 = f2 * i % mod;
		f1 = (i == N+1) ? f2 : f1, f3 = (i == N) ? f2 : f3;
	}

	ll inv=1, p = f1;
	for (int e = 0; e < 30; e++)
	{
		if ((1ll<<e) & (mod-2))
			inv = inv * p % mod;
		p = p * p % mod;
	}
	f2 = f2 * inv % mod * inv % mod * inv % mod * (N+1) % mod * (N+1) % mod * f3 % mod;
	if (f2 % 2)
		f2 += mod;
	cout << (f2>>1) << "\n";
}

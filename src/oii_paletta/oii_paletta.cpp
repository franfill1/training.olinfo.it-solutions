#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct fenwick
{
	vector < ll > T;
	int n;

	fenwick(int _n) : n(_n)
	{
		T.resize(n+1, 0);
	}

	void add(int k, ll v)
	{
		for(k++; k <= n; k += k&-k) T[k] += v;
	}

	ll get(int k)
	{
		ll v = 0;
		for (k++; k > 0; k -= k&-k) v += T[k];
		return v;
	}
};

long long paletta_sort(int N, int V[]) 
{
	ll ans = 0;
	fenwick par(N), dis(N);
	for (int i = 0; i < N; i += 2)
	{
		if (V[i] % 2 == 1) return -1;
		ans += i/2 - par.get(V[i]);
		par.add(V[i], 1);
	}

	for (int i = 1; i < N; i+= 2)
	{
		if (V[i] % 2 == 0) ans = -1;
		ans += i/2 - dis.get(V[i]);
		dis.add(V[i], 1);
	}
	return ans;
}


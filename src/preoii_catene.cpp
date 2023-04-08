#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

vector < ll > ans1;
vector < ll > ans2;
vector < vector < ii > > g;

void dp(ll n, ll from)
{
	ll be1 = -1, be2 = -1;
	ll tot = 0;
	for (ii nep : g[n])
	{
		ll ne = nep.first;
		if (ne == from) continue;
		ll w = nep.second;
		dp(ne, n);
		tot += ans1[ne];
		ll g = w + ans2[ne] - ans1[ne];
		if (be1 == -1 || g > be1)
		{
			be2 = be1;
			be1 = g;
		}
		else if (be2 == -1 || g > be2)
		{
			be2 = g;
		}
	}
	ans1[n] = tot;
	if (be1 > 0) ans1[n] += be1;
	if (be2 > 0) ans1[n] += be2;
	ans2[n] = tot;
	if (be1 > 0) ans2[n] += be1;
}

long long profitto_massimo(int N, int U[], int V[], int W[])
{
    ans1.resize(N);
    ans2.resize(N);
    g.resize(N);
    for (int i = 0; i < N-1; i++)
    {
    	g[U[i]-1].push_back(make_pair(V[i]-1, W[i]));
    	g[V[i]-1].push_back(make_pair(U[i]-1, W[i]));
	}
	dp(0, -1);
	return ans1[0];
}
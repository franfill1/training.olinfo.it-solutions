#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > ii;

#define P 17
#define MAXN 100000

ll GT;

vector < ll > dist;
vector < vector < ii > > g;

ll anc[P][MAXN];
ll sum[P][MAXN];
ll mi[P][MAXN];
ll mat[P][MAXN];
ll maf[P][MAXN];
ll mal[P][MAXN];
 
void dfs(ll n, ll f)
{
	for (ii nep : g[n])
	{
		ll ne = nep.first, w = nep.second;
		if (ne != f)
		{
			dist[ne] = dist[n]+1;
			dfs(ne, n);
			
			anc[0][ne] = n;
			if (GT == 1 || GT == 3) sum[0][ne] = w;
			if (GT == 2) mi[0][ne] = w;
			if (GT == 3)
			{
				mat[0][ne] = max(0ll, w);
				maf[0][ne] = max(0ll, w);
				mal[0][ne] = max(0ll, w);
			}
		}
	}
}

void inizia(int N, int T, int A[], int B[], int C[]) 
{
	GT = T;
	g.resize(N);
	dist.resize(N);
	for (ll i = 0; i < N-1; i++)
	{
		g[A[i]].push_back({B[i], C[i]});
		g[B[i]].push_back({A[i], C[i]});
	}
	if (T == 1 || T == 3) 
	{
		sum[0][0] = 0;
	}
	
	if (T == 2) 
	{
		mi[0][0] = 1<<30; 
	}
	
	if (T == 3)
	{
		mat[0][0] = 0; maf[0][0] = 0; mal[0][0] = 0;
	}

	dist[0] = 0; anc[0][0] = 0; 
	dfs(0, 0);
		
	for (ll p = 1; p < P; p++)
	{
		for (ll n = 0; n < N; n++)
		{
			anc[p][n] = anc[p-1][anc[p-1][n]];
			if (T == 3)
			{
				mat[p][n] = max(mal[p-1][n] + maf[p-1][anc[p-1][n]], max(mat[p-1][n], mat[p-1][anc[p-1][n]]));
				maf[p][n] = max(maf[p-1][n], sum[p-1][n] + maf[p-1][anc[p-1][n]]);
				mal[p][n] = max(mal[p-1][anc[p-1][n]], sum[p-1][anc[p-1][n]] + mal[p-1][n]);
				sum[p][n] = sum[p-1][n] + sum[p-1][anc[p-1][n]];
			}
			else if (T == 1) sum[p][n] = sum[p-1][n] + sum[p-1][anc[p-1][n]];
			else if (T == 2) mi[p][n] = min(mi[p-1][n], mi[p-1][anc[p-1][n]]);
		}
	}
}

ll nAnc(ll n, ll x)
{
	for (ll p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			n = anc[p][n];
		}
	}
	return n;
}

ll nSum(ll n, ll x)
{
	ll ans = 0;
	for (ll p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			ans += sum[p][n];
			n = anc[p][n];
		}
	}
	return ans;
}

ll nMin(ll n, ll x)
{
	ll ans = 1<<30;
	for (ll p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			ans = min(ans, mi[p][n]);
			n = anc[p][n];
		}
	}
	return ans;
}

inline ll nMax(ll n, ll x, ll &tail)
{
	ll ans = 0;
	tail = 0;
	for (ll p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			ans = max(ans, max(mat[p][n], maf[p][n] + tail));
			tail = max(mal[p][n], tail + sum[p][n]);
			n = anc[p][n];
		}
	}
	return ans;
}

inline ll lca(ll a, ll b)
{
	ll d = min(dist[a], dist[b]);
	a = nAnc(a, dist[a] - d);
	b = nAnc(b, dist[b] - d);
	if (a == b)
	{
		return a;
	}
	
	for (ll p = P-1; p >= 0; p--)
	{
		ll na = anc[p][a], nb = anc[p][b];
		if (na != nb)
		{
			a = na;
			b = nb;
		}
	}
	return anc[0][a];
}

long long distanza1(int u, int v) 
{
	return dist[u] + dist[v] - 2 * dist[lca(u, v)];
}

long long distanza2(int u, int v) 
{
	ll x = lca(u, v);
	ll s1 = nSum(u, dist[u] - dist[x]);
	ll s2 = nSum(v, dist[v] - dist[x]);
	return s1 + s2;
}

long long minimo(int u, int v) 
{
	ll x = lca(u, v);
	ll m1 = nMin(u, dist[u] - dist[x]);
	ll m2 = nMin(v, dist[v] - dist[x]);
	return min(m1, m2);
}

long long massimo(int u, int v) 
{
	ll x = lca(u, v);
	ll t1, t2;
	ll m1 = nMax(u, dist[u] - dist[x], t1);
	ll m2 = nMax(v, dist[v] - dist[x], t2);
	return max(t1 + t2, max(m1, m2));
}

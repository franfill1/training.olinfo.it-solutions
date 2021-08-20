#include <bits/stdc++.h>
#define P 20

using namespace std;

typedef pair < int , int > ii;

vector < int > dist;
vector < vector < ii > > g;
vector < vector < int > > anc;
vector < vector < int > > ma;

void dfs(int n, int f)
{
	for (ii nep : g[n])
	{
		if (nep.first != f)
		{
			anc[0][nep.first] = n;
			ma[0][nep.first] = nep.second;
			dist[nep.first] = dist[n] + 1;
			dfs(nep.first, n);
		}
	}
}

int nAnc(int n, int x)
{
	for (int p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			n = anc[p][n];
		}
	}
	return n;
}

int nMa(int n, int x)
{
	int ans = 0;
	for (int p = P-1; p >= 0; p--)
	{
		if (1<<p <= x)
		{
			x -= 1<<p;
			ans = max(ans, ma[p][n]);
			n = anc[p][n];
		}
	}
	return ans;
}

int lc(int a, int b)
{
	if (dist[a] > dist[b])
	{
		a = nAnc(a, dist[a] - dist[b]);
	}
	else
	{
		b = nAnc(b, dist[b] - dist[a]);
	}
	if (a == b)
	{
		return a;
	}
	for (int p = P-1; p >= 0; p--)
	{
		int na = anc[p][a];
		int nb = anc[p][b];
		if (na != nb)
		{
			a = na; b = nb;
		}
	}
	return anc[0][a];
}

int query(int a, int b)
{
	int x = lc(a, b);
	int da = dist[a] - dist[x];
	int db = dist[b] - dist[x];
	return max(nMa(a, da), nMa(b, db));
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol)
{
	int i;
	for(i=0; i<Q; i++) sol[i] = i;
	dist.resize(N);
	g.resize(N);
	anc.resize(P, vector < int > (N));
	ma.resize(P, vector < int > (N));
	for (int i = 0; i < N-1; i++)
	{
		int w = max(briganti[A[i]], briganti[B[i]]);
		g[A[i]].push_back({B[i], w});
		g[B[i]].push_back({A[i], w});
	}
	anc[0][0] = 0; dist[0] = 0; ma[0][0] = briganti[0];
	dfs(0, -1);
	for (int p = 1; p < P; p++)
	{
		for (int n = 0; n < N; n++)
		{
			anc[p][n] = anc[p-1][anc[p-1][n]];
			ma[p][n] = max(ma[p-1][n], ma[p-1][anc[p-1][n]]);
		}
	}
	
	for (int i = 0; i < Q; i++)
	{
		if (start[i] == end[i])
		{
			sol[i] = briganti[start[i]];
		}
		else sol[i] = query(start[i], end[i]);
	}
}
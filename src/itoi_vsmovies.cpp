#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

#define inf numeric_limits<int>::max()
#define P 19
#define MAXN 100001
#define MAXM 500001

using namespace std;

typedef pair < int , int > ii;

struct edge
{
	int b, w, id;
};

struct edgee
{
	int a, b, w;
};

int anc[P][MAXN];
int ma[P][MAXN];

int de[MAXN];

int lift(int n, int x)
{
	for (int p = P-1; p >= 0; p--)
	{
		if (x >= (1<<p))
		{
			x -= 1<<p;
			n = anc[p][n];
		}
	}
	return n;
}

int mali(int n, int x)
{
	int ans = 0;
	for (int p = P-1; p >= 0; p--)
	{
		if (x >= 1<<p)
		{
			x -= 1<<p;
			ans = max(ans, ma[p][n]);
			n = anc[p][n];
		}
	}
	return ans;
}

int lca(int a, int b)
{
	a = lift(a, max(0, de[a] - de[b]));
	b = lift(b, max(0, de[b] - de[a]));
	
	if (a == b)
	{
		return a;
	}
	else
	{
		for (int p = P-1; p >= 0; p--)
		{
			int na = anc[p][a], nb = anc[p][b];
			if (na != nb)
			{
				a = na;
				b = nb;
			}
		}
		return anc[0][a];
	}
}

int query(int a, int b)
{
	int lc = lca(a, b);
	int as = mali(a, de[a] - de[lc]);
	int bs = mali(b, de[b] - de[lc]);
	return max(as, bs);
}

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
    int M, N;
    fin >> M >> N;
    
    vector < vector < edge > > g(N);
    edgee ws[M];
    for (int i = 0; i < M; i++)
    {
    	int a, b, w;
    	fin >> a >> b >> w;
    	g[a].push_back({b, w, i});
    	g[b].push_back({a, w, i});
    	ws[i] = {a, b, w};
	}
	
	bool vis[N];
	bool us[M];
	int fro[N];
	int D[N];
	for (int i = 0; i < N; i++)
	{
		vis[i] = false;
		fro[i] = -1;
		D[i] = inf;
	} 
	for (int i = 0; i < M; i++)
	{
		us[i] = false;
	}
	
	priority_queue < ii, vector < ii > , greater < ii > > pq;
	D[0] = 0;
	anc[0][0] = 0;
	ma[0][0] = 0;
	pq.push({0, 0});
	
	int t = 0;
	
	while(!pq.empty())
	{
		int n = pq.top().second;
		pq.pop();
		if (!vis[n])
		{
			t += D[n];
			if (fro[n] != -1)
			{
				us[fro[n]] = true;
			}
			for (edge ned : g[n])
			{
				int ne = ned.b;
				int w = ned.w;
				if (!vis[ne] && D[ne] > w)
				{
					D[ne] = w;
					fro[ne] = ned.id;
					anc[0][ne] = n;
					ma[0][ne] = w;
					de[ne] = de[n] +1;
					pq.push({w, ne});
				}
			}
		}
		vis[n] = true;
	}
	
	for (int p = 1; p < P; p++)
	{
		for (int n = 0; n < N; n++)
		{
			anc[p][n] = anc[p-1][anc[p-1][n]];
			ma[p][n] = max(ma[p-1][n], ma[p-1][anc[p-1][n]]);
		}
	}
	
	for (int i = 0; i < M; i++)
	{
		if (us[i])
		{
			fout << t << "\n";
		}
		else
		{
			int a = ws[i].a, b = ws[i].b;
			fout << t + ws[i].w - query(a, b) << "\n";
		}
	}
}

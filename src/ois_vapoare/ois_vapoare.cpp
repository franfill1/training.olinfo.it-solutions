#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

struct edge
{
	int a, b, w;
};

bool operator < (edge a, edge b)
{
	return a.w > b.w;
}

vector < int > pa;
vector < int > siz;

int find(int x)
{
	if (pa[x] == x)
	{
		return x;
	}
	else
	{
		return pa[x] = find(pa[x]);
	}
}

void unite(int a, int b)
{
	a = find(a); b = find(b);
	if (siz[a] > siz[b])
	{
		pa[b] = a;
		siz[a] += siz[b];
	}
	else
	{
		pa[a] = b;
		siz[b] += siz[a];
	}
}

int main()
{
	int N, K, T;
	fin >> N >> K >> T;
	vector < edge > V;
	for (int i = 0; i < K; i++)
	{
		int a, b, w;
		fin >> a >> b >> w;
		a--; b--;
		V.push_back({a, b, w});
	}
	vector < pair < int , int > > G(T);
	for (int i = 0; i < T; i++)
	{
		fin >> G[i].first;
		G[i].second = i;
	}
	sort(V.begin(), V.end());
	sort(G.rbegin(), G.rend());
	
	pa.resize(N);
	siz.resize(N, 1);
	for (int i = 0; i < N; i++) pa[i] = i;
	
	vector < int > ans(T);
	
	int c = 0, i = 0, j = 0;
	
	while(c != N-1 && i < K && j < T)
	{
		int a = V[i].a, b = V[i].b, w = V[i].w;
		while(j < T && G[j].first > w)
		{
			ans[G[j].second] = N - c;
			j++;
		}
		
		if (find(a) != find(b))
		{
			c++;
			unite(a, b);
		}
		i++;
	}
	while(j < T)
	{
		ans[G[j].second] = N - c;
		j++;
	}
	
	for (int i = 0; i < T; i++)
	{
		fout << ans[i] << "\n";
	}
}

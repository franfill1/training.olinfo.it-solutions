#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef unsigned long long ll;
typedef pair < ll , ll > pll;
ll inf = 1ull<<63;

ll N, M, K;
vector < vector < pll > > g;

void dijkstra(ll s, vector < ll > &D)
{
	D.resize(N, inf);
	D[s] = 0;
	
	priority_queue < pll , vector < pll > , greater < pll > > pq;
	pq.push({0, s});
	
	while(!pq.empty())
	{
		ll n = pq.top().second, d = pq.top().first;
		pq.pop();
		
		for (pll nep : g[n])
		{
			ll ne = nep.first;
			ll w = nep.second;
			ll nd = d + w;
			if (D[ne] > nd)
			{
				D[ne] = nd;
				pq.push({nd, ne});
			}
		}
	}
}

int main()
{
	fin >> N >> M >> K;
	vector < ll > st(K);
	
	for (int i = 0; i < K; i++)
	{
		fin >> st[i];
	}
	vector < ll > P(K);
	for (int i = 0; i < K; i++)
	{
		fin >> P[i];
	}
	
	g.resize(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		fin >> a >> b >> w;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	
	vector < ll > I(N, 0);
	for (int i = 0; i < K; i++)
	{
		vector < ll > D;
		dijkstra(st[i], D);
		for (int j = 0; j < N; j++)
		{
			I[j] += D[j] * P[i];
		}
	}
	
	ll ans = inf;
	ll tot = 0;
	for (int i = 0; i < N; i++)
	{
		if (I[i] < ans)
		{
			ans = I[i];
			tot = 1;
		}
		else if (I[i] == ans)
		{
			tot++;
		}
	}
	fout << tot << "\n" << ans << "\n";
}

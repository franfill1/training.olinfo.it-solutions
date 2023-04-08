#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using pll = pair < ll , ll >;
constexpr ll inf = 1ll<<60;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector < vector < pll > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		ll w;
		cin >> a >> b >> w;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}
	auto dijkstra = [&] (int s)
	{
		vector < ll > D(n, inf);
		D[s] = 0;
		priority_queue < pll , vector < pll > , greater < pll > > pq;
		pq.emplace(D[s], s);
		while(!pq.empty())
		{
			auto [d, x] = pq.top();
			pq.pop();
			if (d > D[x])
				continue;
			for (auto [y, w] : g[x])
				if (d + w < D[y])
				{
					D[y] = d + w;
					pq.emplace(D[y], y);
				}
		}
		return D;
	};

	auto Ds = dijkstra(0), Df = dijkstra(n-1);
	ll cur = Ds[n-1];
	vector < bool > vis(n, false);
	for (int i = 0; i < n; i++)
		if (Ds[i] + Df[i] == cur)
			vis[i] = true;
	ll ans = inf;
	for (int x = 0; x < n; x++)
		for (auto [y, w] : g[x])
			if (!vis[y] || !vis[x])
			{
				ll ma = cur - 1 - (Ds[x] + Df[y]);
				if (ma <= 0)
					continue;
				ans = min(ans, w-ma);
			}
	cout << (ans != inf ? ans : -1) << "\n";
}

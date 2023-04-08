#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

struct edge
{
	ll to, w;
	bool E;
};

int main()
{
	int N, M, T;
	cin >> N >> M >> T;
	vector < vector < edge > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, w, e;
		cin >> a >> b >> w >> e;
		g[a].push_back({b, w, e});
	}

	vector < ll > D(N, 1ll<<60);
	priority_queue < pll , vector < pll > , greater < pll > > pq;
	pq.push({0, 0});
	D[0] = 0;

	while(!pq.empty())
	{
		auto [d, x] = pq.top();
		pq.pop();
		if (d != D[x]) continue;

		for (auto [y, w, e] : g[x])
		{
			if (!e || d + w <= T)
			{
				if (d + w < D[y])
				{
					D[y] = d + w;
					pq.push({D[y], y});
				}
			}
		}
	}
	cout << (D[N-1] != (1ll<<60) ? D[N-1] : -1) << "\n";
}


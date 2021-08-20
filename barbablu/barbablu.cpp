#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using namespace std;

struct state
{
	int d, n, a;
};

bool operator < (state a, state b)
{
	return a.d > b.d;
}

typedef pair < int , int > ii;

int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int N, M, C, K;
    cin >> N >> M >> C >> K;
	C--;
    vector < bool > isA (N, false);
    for (int i = 0; i < K; i++)
    {
    	int el;
    	cin >> el;
    	el--;
    	isA[el] = true;
	}
	
	vector < vector < ii > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--; b--;
		g[a].push_back({b, w});
		g[b].push_back({a, w});
	}
	
	vector < vector < int > > D(N, vector < int > (21, numeric_limits<int>::max()));
	
	priority_queue < state > pq;
	pq.push({0, 0, 20});
	D[0][20] = 0;
	while(!pq.empty())
	{
		int n = pq.top().n, a = pq.top().a, d = pq.top().d;
		pq.pop();
		if (n == C)
		{
			cout << D[n][a] << "\n";
			return 0;
		}
		if (d == D[n][a])
		{
			for (ii nep : g[n])
			{
				int ne = nep.first;
				int w = nep.second;
				int na = a - w;
				int nd = d + w;
				if (na >= 0 )
				{
					if (isA[ne])
					{
						na = 20;
					}
					if (D[ne][na] > nd)
					{
						D[ne][na] = nd;
						pq.push({nd, ne, na});
					}
				}
			}
		}
	}
	cout << -1 << "\n";
}

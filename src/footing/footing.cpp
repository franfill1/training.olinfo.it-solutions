#include <bits/stdc++.h>
#pragma gcc Optimize("Ofast")

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct edge
{
	int to, w, id;
};

typedef pair < int , int > ii;

vector < vector < edge > > g;
int N, M, ans = 1<<30;

int cicleFrom(int s)
{
	vector < int > D(N, 1<<30);

	vector < bool > used(M, false);
	
	priority_queue < ii , vector < ii > , greater < ii > > pq;
	pq.push({0, s});
	
	int ans = 1<<30;
	while(!pq.empty())
	{
		int n = pq.top().second, d = pq.top().first;
		if (d > ans) return ans;
		pq.pop();
		for (edge ned : g[n])
		{
			if (!used[ned.id])
			{
				used[ned.id] = true;
				int ne = ned.to;
				int nd = ned.w + d;
				ans = min(ans, D[ne] + nd);
				if (nd < D[ne])
				{
					D[ne] = nd;
					pq.push({nd, ne});
				}
			}
		}
	}
	return ans;
}

int main()
{
	fin >> N >> M;
	g.resize(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		fin >> a >> b >> w;
		a--; b--;
		g[a].push_back({b, w, i});
		g[b].push_back({a, w, i});
	}
	
	for (int i = 0; i < N; i++)
	{
		if (g[i].size() > 1) ans = min(ans, cicleFrom(i));
	}
	fout << ans;
}

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < vector < int > > g(N);
	vector < int > siz(N);
	vector < bool > VV(N, false);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
		siz[a]++;
		siz[b]++;
	}

	queue < int > q;
	for (int i = 0; i < N; i++) if (siz[i] == 1) q.emplace(i);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		VV[x] = true;
		for (int y : g[x]) if (!VV[y])
		{
			cout << x << " " << y << "\n";
			if (--siz[y] == 1) q.emplace(y);
		}
	}

	vector < bool > vis(N, false);
	function < void(int, int) > dfs = [&] (int x, int p) -> void
	{
		vis[x] = true;
		for (auto y : g[x]) if (y != p && !VV[y])
		{
			cout << x << " " << y << "\n";
			if (!vis[y]) dfs(y, x);
		}
		VV[x] = true;
	};
	for (int i = 0; i < N; i++) if (!vis[i]) dfs(i, i);
}

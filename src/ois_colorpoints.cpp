#include<vector>
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

struct edge
{
        int to, w;
        int r;
        edge(int _to, int _w, int _r) : to(_to), w(_w), r(_r) {};
};
vector < vector < edge > > g;
vector < int > f;
vector < int > d;

int bfs(int s, int fi)
{
	f.assign(g.size(), -1);
	d.resize(g.size());
	d[0] = 1<<30;
	queue < int > q;
	q.emplace(0);
	while(q.size())
	{
		int x = q.front();
		q.pop();
		for (auto &[y, w, r] : g[x]) if (w != 0 && f[y] == -1)
		{
			d[y] = min(d[x], w);
			f[y] = r;
			q.push(y);
			if (y == fi) return d[y];
		}
	}
	return 0;
}

int max_flow(int s, int fi)
{
	int flow = 0;
	int new_flow;
	while((new_flow = bfs(s, fi)))
	{
		flow += new_flow;
		int x = fi;
		while(x != s)
		{
			g[x][f[x]].w += new_flow;
			int p = g[x][f[x]].r;
			x = g[x][f[x]].to;
			g[x][p].w -= new_flow;
		}
	}
	return flow;
}

int main()
{
	int N;
	cin >> N;
	map < int , int > R, C, rR, rC;
	vector < pair < int , int > > P(N);
	for (auto &[x, y] : P)
	{
		cin >> x >> y;
		if (!R.count(x)) R[x] = R.size()+1;
		if (!C.count(y)) C[y] = C.size()+1;
	}
	for (auto &[k, v] : C) v += R.size();

	g.resize(R.size() + C.size() + 2);
	for (auto &[x, y] : P)
	{
		g[R[x]].emplace_back(C[y], 1, g[C[y]].size());
		g[C[y]].emplace_back(R[x], 0, g[R[x]].size()-1);
	}

	for (auto &[k, x] : R)
	{
		rR[x] = k;
		if (g[x].size() % 3)
		{
				cout << "No\n";
				return 0;
		}
		int w = g[x].size() / 3;
		g[0].emplace_back(x, w, g[x].size());
		g[x].emplace_back(0, 0, g[0].size()-1);
	}

	for (auto &[k, y] : C)
	{
		rC[y] = k;
		if (g[y].size() % 3)
		{
				cout << "No\n";
				return 0;
		}
		int w = g[y].size() / 3;
		g[y].emplace_back(g.size()-1, w, g.back().size());
		g.back().emplace_back(y, 0, g[y].size()-1);
	}
	cout << "Yes\n" << max_flow(0, g.size()-1) << "\n";

	for (auto &[k, x] : R) for (auto &[y, w, r] : g[x]) if (w == 0 && y > x)
	{
		cout << rR[x] << " " << rC[y] << "\n";
	}
}


#include<bits/stdc++.h>
using namespace std;

long long modpow(long long b, long long e)
{
	if (e == 0)
		return 1;
	long long tmp = modpow(b, e/2);
	tmp = (tmp*tmp) % 1000000007;
	if (e % 2)
		tmp = (tmp*b) % 1000000007;
	return tmp;
}

int main()
{
	int n;
	cin >> n;
	vector < vector < int > > t(n), anc(30, vector < int > (n, 0));
	vector < int > d(n, 0);

	for (int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		t[a].emplace_back(b);
		t[b].emplace_back(a);
	}

	auto dfs = [&] (int x, auto dfs) -> void
	{
		for (auto y : t[x])
			if (y != anc[0][x])
			{
				anc[0][y] = x;
				d[y] = d[x]+1;
				dfs(y, dfs);
			}
	};
	dfs(0, dfs);

	for (int p = 1; p < 30; p++)
		for (int i = 0; i < n; i++)
			anc[p][i] = anc[p-1][anc[p-1][i]];

	auto kanc = [&] (int x, int k) -> int
	{
		for (int p = 0; p < 30; p++)
			if (k & (1<<p))
				x = anc[p][x];
		return x;
	};

	int m;
	cin >> m;
	vector < vector < int > > G(n);
	vector < int > p = anc[0];
	vector < int > up(n);
	iota(up.begin(), up.end(), 0);
	vector < bool > us(n, false);
	auto find = [&] (int x, auto find) -> int
	{
		if (x == up[x])
			return x;
		return up[x] = find(up[x], find);
	};
	auto add_path = [&](int a, int l) -> void
	{
		a = find(a, find);
		while(d[a] > d[l]+1)
		{
			assert(!us[a]);
			G[a].emplace_back(p[a]);
			G[p[a]].emplace_back(a);
			up[a] = p[a];
			us[a] = true;
			a = find(a, find);
		}
	};
	while(m--)
	{
		int x, y, x_ori, y_ori;
		cin >> x >> y;
		x--, y--;
		if (d[x] < d[y])
			swap(x, y);
		x_ori = x, y_ori = y;
		x = kanc(x, d[x] - d[y]);
		if (x != y)
		{
			for (int p = 29; p >= 0; p--)
				if (anc[p][x] != anc[p][y])
					x = anc[p][x], y = anc[p][y];
			assert(x != y);
			G[x].emplace_back(y);
			G[y].emplace_back(x);
			x = p[x], y = p[y];
		}

		add_path(x_ori, x);
		add_path(y_ori, y);
	}
	vector < int > col(n, 0);
	int cnt = 0;
	for (int i = 1; i < n; i++)
		if (!col[i])
		{
			cnt++;
			col[i] = 1;
			queue < int > q;
			q.emplace(i);
			while(!q.empty())
			{
				int x = q.front();
				assert(x != 0);
				q.pop();
				for (int y : G[x])
				{
					if (!col[y])
					{
						col[y] = -col[x];
						q.emplace(y);
					}
					assert(col[y] == -col[x]);
				}
			}
		}
	cout << modpow(2, cnt) << "\n";
}

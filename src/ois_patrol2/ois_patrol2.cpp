#include<bits/stdc++.h>
using namespace std;


int main()
{
	int n, m, l;
	cin >> n >> m >> l;
	vector < vector < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	vector < int > C(l);
	for (auto &x : C)
		cin >> x;
	vector < int > d(n, -1);
	queue < int > q;
	d[0] = 0;
	q.emplace(0);
	while(!q.empty())
	{
		int x = q.front();
		q.pop();
		if (C[d[x] % l] == x)
		{
			q.emplace(x);
			d[x]++;
			continue;
		}
		for (auto y : g[x])
			if (d[y] == -1)
			{
				d[y] = d[x] + 1;
				q.emplace(y);
			}
	}
	cout << d[n-1] << "\n";
}

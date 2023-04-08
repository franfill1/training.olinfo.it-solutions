// @check-accepted: *

#include <bits/stdc++.h>
using namespace std;
typedef pair < int , int > pii;

struct best3 : public array < pii , 3 > 
{
	int sum = 0;
	best3()
	{
		at(0) = at(1) = at(2) = make_pair(0, -1);
	}
	void emplace(int v, int id)
	{
		if (v > at(2).first)
		{
			sum += v - at(2).first;
			at(2) = make_pair(v, id);
			for (int i = 2; i > 0 && at(i) > at(i-1); i--)
				std::swap(at(i), at(i-1));
		}
	}
};

int build(int n, vector<int> a, vector<int> b) {
	vector < vector < int > > g(n);
	for (int i = 0; i < n-1; i++)
	{
		g[a[i]].emplace_back(b[i]);
		g[b[i]].emplace_back(a[i]);
	}
	vector < best3 > be(n);

	auto dfs = [&] (int x, int p, auto dfs) -> int
	{
		for (auto y : g[x]) if (y != p)
			be[x].emplace(dfs(y, x, dfs), y);
		return be[x][0].first + 1;
	};
	dfs(0, 0, dfs);
	int ans = 0;
	auto dfs2 = [&] (int x, int p, auto dfs2) -> void
	{
		ans = max(ans, be[x].sum);
		for (auto y : g[x]) if (y != p)
		{
			if (be[x][0].second == y)
				be[y].emplace(be[x][1].first+1, x);
			else
				be[y].emplace(be[x][0].first+1, x);
			dfs2(y, x, dfs2);
		}
	};
	dfs2(0, 0, dfs2);
	return ans*2;
}

#include<bits/stdc++.h>
using namespace std;

struct xor_set
{
	vector < int > cnt;
	vector < pair < int , int > > nxt;
	int max_xor = 0;
	stack < pair < int , int > > history;

	xor_set()
	{
		cnt.resize(1, 0);
		nxt.resize(1, make_pair(-1, -1));
	}

	void increase(int v, int a)
	{
		int x = 0;
		for (int p = 30; p >= 0; p--)
		{
			cnt[x] += a;
			if (nxt[x].first == -1)
			{
				nxt[x].first = cnt.size();
				cnt.emplace_back(0);
				nxt.emplace_back(-1, -1);
				nxt[x].second = cnt.size();
				cnt.emplace_back(0);
				nxt.emplace_back(-1, -1);
			}
			if (v & (1<<p))
				x = nxt[x].second;
			else
			  x = nxt[x].first;
		}
		cnt[x] += a;
	}

	void insert(int v)
	{
		history.emplace(max_xor, v);
		if (cnt[0])
		{
			int x = 0, cur = 0;
			for (int p = 30; p >= 0; p--)
			{
				assert(cnt[x]);
				auto &[l, r] = nxt[x];
				if ((cnt[r] == 0) | ((v & (1<<p)) && cnt[l]))
					x = l;
				else
					x = r, cur += (1<<p);
			}
			assert(cnt[x]);
			max_xor = max(max_xor, v ^ cur);
		}
		increase(v, 1);
	}

	void rollback()
	{
		assert(history.size());
		auto [m, v] = history.top();
		max_xor = m;
		increase(v, -1);
		history.pop();
	}
};


struct segtree
{
	int n;
	vector < vector < int > > T;
	vector < int > val;
	segtree(int n_, vector < int > &val_)
	{
		val = val_;
		for(n = 1; n < n_; n <<= 1);
		T.resize(2*n);
	}

	void add(int l, int r, int v)
	{
		l += n;
		r += n-1;
		while(l <= r)
		{
			if (l % 2 == 1) 
				T[l++].emplace_back(v);
			if (r % 2 == 0) 
				T[r--].emplace_back(v);
			l /= 2;
			r /= 2;
		}
	}

	void dfs(int x, xor_set &s, vector < int > &res)
	{
		for (auto v : T[x])
			s.insert(val[v]);
		if (x >= n)
			res.emplace_back(s.max_xor);
		else
		{
			dfs(x*2, s, res);
			dfs(x*2+1, s, res);
		}
		for (auto v : T[x])
			s.rollback();
	}
};


int main()
{
	int n, q;
	cin >> n >> q;
	vector < vector < pair < int , int > > > g(n);
	for (int i = 0; i < n-1; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		a--, b--;
		g[a].emplace_back(b, w);
		g[b].emplace_back(a, w);
	}
	vector < int > v(n, 0);
	auto dfs = [&] (int x, int p, auto dfs) -> void
	{
		for (auto [y, w] : g[x])
			if (y != p)
			{
				v[y] = v[x] ^ w;
				dfs(y, x, dfs);
			}
	};
	dfs(0, 0, dfs);
	segtree seg(q+1, v);
	vector < int > last(n, -1);
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		x--;
		if (last[x] == -1)
			last[x] = i;
		else
		{
			seg.add(last[x], i, x);
			last[x] = -1;
		}
	}
	for (int x = 0; x < n; x++)
		if (last[x] != -1)
			seg.add(last[x], q, x);
	vector < int > res;
	xor_set s;
	seg.dfs(1, s, res);
	for (int i = 0; i < q; i++)
		cout << res[i] << "\n";
}

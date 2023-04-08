#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct fenwick
{
	ll n;
	vector < ll > T;
	fenwick(ll n_) : n(n_) , T(n_+1, 0)
	{
	}

	void add(ll k, ll v)
	{
		for (k++; k <= n; k += k&-k)
			T[k] += v;
	}

	ll get(ll k)
	{
		ll ans = 0;
		for (k++; k; k -= k&-k)
			ans += T[k];
		return ans;
	}

	void add_range(ll l, ll r, ll v)
	{
		add(r, -v);
		add(l, v);
	}
};

int main()
{
	ll n, m;
	vector < vector < ll > > g1, g2;	

	cin >> n;
	g1.resize(n);
	for (ll i = 1; i < n; i++)
	{
		ll p;
		cin >> p;
		p--;
		g1[p].emplace_back(i);
	}

	cin >> m;
	g2.resize(m);
	for (ll i = 1; i < m; i++)
	{
		ll p;
		cin >> p;
		p--;
		g2[p].emplace_back(i);
	}

	ll t = 0;
	vector < ll > start(m), end(m);
	auto dfs2 = [&] (ll x, auto dfs2) -> void
	{
		start[x] = t++;
		for (ll y : g2[x])
			dfs2(y, dfs2);
		end[x] = t;
	};
	dfs2(0, dfs2);

	ll k;
	vector < vector < pair < ll , ll > > > upd(n);
	cin >> k;
	for (ll i = 0; i < k; i++)
	{
		ll x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		upd[x].emplace_back(y, w);
	}

	ll q;
	vector < vector < pair < ll , ll > > > query(n);
	cin >> q;
	for (ll i = 0; i < q; i++)
	{
		ll u, v;
		cin >> u >> v;
		u--, v--;
		query[u].emplace_back(v, i);
	}

	fenwick fen(m);
	vector < ll > ans(q);
	auto dfs1 = [&] (ll x, auto dfs1) -> void
	{
		for (auto [y, w] : upd[x])
			fen.add_range(start[y], end[y], w);
		for (auto [y, i] : query[x])
			ans[i] = fen.get(start[y]);
		for (auto y : g1[x])
			dfs1(y, dfs1);
		for (auto [y, w] : upd[x])
			fen.add_range(start[y], end[y], -w);
	};
	dfs1(0, dfs1);
	for (auto v : ans)
		cout << v << "\n";
}

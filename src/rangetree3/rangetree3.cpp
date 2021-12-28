#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll inf = 1ll<<60;

struct node
{
	ll v, l, r, t;
	node(ll iv) : v(iv) , t(iv) , l(iv) , r(iv){}
	node() {node(0);}
};

ostream& operator << (ostream& os, node n)
{
	os << "{" << n.v << ", " << n.l << ", " << n.r << ", " << n.t << "}";
	return os;
}

void merge(node a, node b, node &c)
{
	c.l = max(a.l, a.t + b.l);
	c.r = max(a.r + b.t, b.r);
	c.t = a.t + b.t;
	c.v = max(max(a.v, b.v), a.r + b.l);
}

struct segtree
{
	int n;
	vector < node > v;

	segtree(vector < ll > iv) : n(iv.size())
	{
		v.resize(n, node(-inf));

		for (int i = 0; i < n; i++)
		{
			v.emplace_back(iv[i]);
		}

		for (int i = n-1; i > 0; i--)
		{
			merge(v[i*2], v[i*2+1], v[i]);
		}
	}

	void set(ll x, ll y)
	{
		x += n;
		v[x] = node(y);
		
		while(x /= 2)
		{
			merge(v[x*2], v[x*2+1], v[x]);
		}
	}

	ll get(ll x, ll y)
	{
		x += n;
		y += n;

		node nx(-inf), ny(-inf);

		while(x <= y)
		{
			if (x % 2) merge(nx, v[x++], nx);
			if (y % 2 == 0) merge(v[y--], ny, ny);

			x /= 2;
			y /= 2;
		}

		merge(nx, ny, nx);
		return nx.v;
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	cin >> n;

	int p = 1;
	while(p < n) p *= 2;

	vector < ll > v(p, 0);
	for (int i = 0; i < n; i++) cin >> v[i];

	segtree seg(v);

	int m;
	cin >> m;

	while(m--)
	{
		bool q;
		ll x, y;
		cin >> q >> x >> y;
		if (q)
		{
			cout << seg.get(--x, --y) << "\n";
		}
		else
		{
			seg.set(--x, y);
		}
	}
}

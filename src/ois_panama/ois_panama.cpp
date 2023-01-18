#include<bits/stdc++.h>
#include <complex>
using namespace std;
using ll = long long;

struct segtree
{
	struct node
	{
		ll sum, val=0, rval=0, lval=0;
		node(ll v) : sum(v)
		{
			if (v > 0)
				val = rval = lval = v;
		}
		node () : sum(0)
		{
		}
	};

	void merge(node &a, node &b, node &c)
	{
		a.val = max(max(b.val, c.val), b.rval + c.lval);
		a.lval = max(b.lval, b.sum + c.lval);
		a.rval = max(b.rval + c.sum, c.rval);
		a.sum = b.sum + c.sum;
	}

	int n;
	vector < node > T;

	segtree(vector < ll > &V)
	{
		for (n = 1; n < V.size(); n <<= 1);
		T.resize(n*2);
		for (int i = 0; i < V.size(); i++)
			T[n+i] = node(V[i]);
		for (int k = n-1; k; k--)
		{
			merge(T[k], T[k*2], T[k*2+1]);
		}
		for (int k = 2*n-1; k; k--)
		{
		}
	}

	void update(int k, int v)
	{
		k += n;
		T[k] = node(v);
		for (k>>=1; k; k>>=1)
			merge(T[k], T[k*2], T[k*2+1]);
	}

	ll get(int l, int r)
	{
		l += n, r += n-1;
		node lans(0), rans(0);
		while(l <= r)
		{
			if (l % 2 == 1)
				merge(lans, lans, T[l++]);
			if (r % 2 == 0)
				merge(rans, T[r--], rans);
			l>>=1, r>>=1;
		}
		merge(lans, lans, rans);
		return lans.val;
	}
};

int main()
{
	int N, Q;
	cin >> N >> Q;
	vector < ll > V1(N), V2(N);
	for (int i = 0; i < N; i++)
	{
		cin >> V1[i];
		if (i % 2)
			V1[i] = -V1[i];
		V2[i] = -V1[i];
	}
	segtree seg1(V1);
	segtree seg2(V2);
	while(Q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int a, b;
			cin >> a >> b;
			a--;
			if (a % 2)
				b = -b;
			seg1.update(a, b);
			seg2.update(a, -b);
		}
		else 
		{
			int l, r;
			cin >> l >> r;
			l--;
			cout << max(seg1.get(l, r), seg2.get(l, r)) << "\n";
		}
	}
}

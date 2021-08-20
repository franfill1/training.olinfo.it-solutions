#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf = 1ll<<60;

struct segtree
{
	struct node
	{
		ll su=0, mi=inf, ad=0, se, cn=1;
		bool ts = false;
		node(ll v) : su(v) , mi(v){}
		node(){}
	};

	void merge(node a, node b, node &c)
	{
		c.su = a.su + b.su;
		c.mi = min(a.mi, b.mi);
		c.cn = a.cn + b.cn;
	}

	int n;
	vector < node > T;

	segtree ( vector < ll > V)
	{
		n = 1; while(n < V.size()) n*=2;

		T.resize(2*n);
		for (int i = 0; i < V.size(); i++) T[i+n] = node(V[i]);
		for (int i = n-1; i; i--) 
		{
			merge(T[i*2], T[i*2+1], T[i]);
		}
	}

	void propagate(int k)
	{
		if (T[k].ts)
		{
			T[k].su = T[k].se * T[k].cn;
			T[k].mi = T[k].se;
		}
		T[k].su += T[k].ad * T[k].cn;
		T[k].mi += T[k].ad;

		if (k < n)
		{
			if (T[k].ts)
			{
				T[k*2].ts = true;
				T[k*2].se = T[k].se;
				T[k*2].ad = T[k].ad;

				T[k*2+1].ts = true;
				T[k*2+1].se = T[k].se;
				T[k*2+1].ad = T[k].ad;
			}
			else
			{
				T[k*2].ad += T[k].ad;
				T[k*2+1].ad += T[k].ad;
			}
		}
		T[k].ad = 0;
		T[k].ts = 0;
	}

	void add (int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (a <= x && y <= b) T[k].ad += v;
		propagate(k);
		if (a <= x && y <= b) return;
		if (b <= x || y <= a) return;
		int m = (x+y)/2;
		add(a, b, v, k*2, x, m);
		add(a, b, v, k*2+1, m, y);
		merge(T[k*2], T[k*2+1], T[k]);
	}

	void set (int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		if (a <= x && y <= b)
		{
			T[k].ad = 0;
			T[k].ts = 1;
			T[k].se = v;
		}
		propagate(k);
		if (a <= x && y <= b) return;
		if (b <= x || y <= a) return; 
		int m = (x+y)/2;
		set(a, b, v, k*2, x, m);
		set(a, b, v, k*2+1, m, y);
		merge(T[k*2], T[k*2+1], T[k]);
	}

	ll getSum (int a, int b, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (a <= x && y <= b) return T[k].su;
		if (b <= x || y <= a) return 0;
		int m = (x+y)/2;
		return getSum(a, b, k*2, x, m) + getSum(a, b, k*2+1, m, y);
	}

	ll getMin (int a, int b, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (a <= x && y <= b) return T[k].mi;
		if (b <= x || y <= a) return inf;
		int m = (x+y)/2;
		return min(getMin(a, b, k*2, x, m), getMin(a, b, k*2+1, m, y));
	}

	int lowerBound(int a, int b, ll v, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (T[k].mi > v) return -1;
		if (b <= x || y <= a) return -1;
		if (x == y-1) return x;
		int m = (x+y)/2;
		int an = lowerBound(a, b, v, k*2, x, m);
		if (an == -1) an = lowerBound(a, b, v, k*2+1, m, y);
		return an;
	}

};

segtree *seg;

void init(vector<long long> a) 
{
	seg = new segtree(a);
}

long long get_sum(int l, int r) 
{
	return seg->getSum(l, r);
}

void add(int l, int r, long long x) 
{
	seg->add(l, r, x);
}

void set_range(int l, int r, long long x) 
{
	seg->set(l, r, x);
}

long long get_min(int l, int r) 
{
	return seg->getMin(l, r);
}

int lower_bound(int l, int r, long long x) 
{
	return seg->lowerBound(l, r, x);
}

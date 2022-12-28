#include<bits/stdc++.h>
using namespace std;

struct segtree
{
	int n;
	vector < int > ma;
	vector < int > mi;

	segtree(vector < int > &v)
	{
		for (n = 1; n <= v.size(); n<<=1);
		ma.resize(n*2, 0);
		mi.resize(n*2, 0);
		for (int i = 0; i < v.size(); i++)
		{
			ma[i+n] = v[i];
			mi[i+n] = v[i];
		}
		for (int i = n-1; i != 0; i--)
		{
			ma[i] = max(ma[i<<1], ma[(i<<1)+1]);
			mi[i] = min(mi[i<<1], mi[(i<<1)+1]);
		}
	}

	void set(int k, int v)
	{
		k += n;
		ma[k] = mi[k] = v;
		for (k >>= 1; k; k>>=1)
		{
			ma[k] = max(ma[k<<1], ma[(k<<1)+1]);
			mi[k] = min(mi[k<<1], mi[(k<<1)+1]);
		}
	}

	int getMax(int l, int r)
	{
		int ans = 0;
		l += n; r += n-1;
		while(r >= l)
		{
			if (l % 2 == 1) ans = max(ans, ma[l++]);
			if (r % 2 == 0) ans = max(ans, ma[r--]);
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}

	int getMin(int l, int r)
	{
		int ans = 1<<30;
		l += n; r += n-1;
		while(r >= l)
		{
			if (l % 2) ans = min(ans, mi[l++]);
			if (r % 2 == 0) ans = min(ans, mi[r--]);
			l >>= 1;
			r >>= 1;
		}
		return ans;
	}
};

segtree *seg1, *seg2;
vector < set < int > > pos;
vector < int > sf;

void inizio(int N,int M, int sfere[])
{
	pos.resize(N);
	sf.resize(N);
	vector < int > nex(N, N);
	for (int i = 0; i < N; i++) 
	{
		sfere[i]--;
		sf[i] = sfere[i];
		if (!pos[sf[i]].empty())
		{
			nex[*prev(pos[sf[i]].end())] = i;
		}
		pos[sf[i]].insert(i);
	}
	for (int i = 0; i < N; i++) pos[i].insert(N);

	seg1 = new segtree(sf);
	seg2 = new segtree(nex);
}

void modifica(int k,int v)
{
	v--;
	seg1->set(k, v);	
	auto it = pos[sf[k]].lower_bound(k);
	if (it != pos[sf[k]].begin())
	{
		seg2->set(*prev(it), *next(it));
	}
	pos[sf[k]].erase(k);

	it = pos[v].upper_bound(k);
	if (it != pos[v].begin())
	{
		seg2->set(*prev(it), k);
	}
	seg2->set(k, *it);
	pos[v].insert(k);
	sf[k] = v;
}

bool verifica(int l,int r)
{
	r++;
	int a = seg1->getMax(l, r);
	int b = seg2->getMin(l, r);
	if (a != (r-l-1)) return false;

	if (b < r) return false;
	return true;
}

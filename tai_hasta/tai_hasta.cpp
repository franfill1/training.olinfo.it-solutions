#include <bits/stdc++.h>

using namespace std;

struct segtree
{
	struct node
	{
		int val=0, x, y;
		node *l=NULL, *r=NULL;

		node(int a, int b) : x(a) , y(b)
		{
			if (a != b-1)
			{
				int m = (a+b)/2;
				l = new node(a, m);
				r = new node(m, b);
			}
		}

		node(node *n)
		{
			val = n->val; x = n->x; y = n->y;
			l = n->l; r = n->r;
		}

		node* sum(int a, int v)
		{
			node *n = new node(this);
			if (x == y-1) n->val += v;
			else
			{
				int m = (x+y)/2;
				if (a < m) n->l = l->sum(a, v);
				else n->r = r->sum(a, v);
				n->val = n->l->val + n->r->val;
			}
			return n;
		}

		int get(int a, int b)
		{
			if (a <= x && y <= b) return val;
			if (b <= x || y <= a) return 0;
			return l->get(a, b) + r->get(a, b);
		}
	};

	int n;
	vector < node* > roots;

	segtree(int in)
	{
		n = 1; while(n < in) n*=2;
		roots.push_back(new node(0, n));
	}

	void sum(int a, int v)
	{
		roots.push_back(roots.back()->sum(a, v));
	}

	int get(int k, int a, int b)
	{
		return roots[k]->get(a, b);
	}
};

#define MAXN 200000

int V[MAXN], R[MAXN], id[MAXN];
vector < int > P[MAXN];
segtree* seg;

void inizia(int N, int K, int Vi[],int Ri[])
{
	for (int i = 0; i < N; i++) V[i] = Vi[i];
	for (int i = 0; i < K; i++) R[i] = Ri[i];
	seg = new segtree(N+1);

	for (int i = 0; i < K; i++) P[i].push_back(-1);
	for (int i = 0; i < N; i++)
	{
		int c = V[i];
		P[c].push_back(i);
		if (P[c].size() > R[c]+1)
		{
			int l = P[c][P[c].size() - R[c] - 2]+1;
			int r = P[c][P[c].size() - R[c] - 1]+1;
			int r2 = P[c][P[c].size() - R[c]    ]+1;
			seg->sum(l, -R[c]);
			seg->sum(r, R[c]*2);
			seg->sum(r2, -R[c]);
		}
		else if (P[c].size() >= R[c]+1)
		{
			int l = P[c][P[c].size() - R[c] - 1]+1;
			int r = P[c][P[c].size() - R[c]    ]+1;
			seg->sum(l, R[c]);
			seg->sum(r, -R[c]);
		}
		id[i] = seg->roots.size() - 1;
	}
}

int istiga(int i,int j)
{
	return seg->get(id[j], 0, i+1);
}

#include<bits/stdc++.h>
using namespace std;

struct segtree
{
	struct node
	{
		int val=0, siz=1;
		bool flip=false;
		node(int _v) : val(_v) {};
		node() {};
	};
	vector < node > T;
	int n;
	
	segtree(vector < int > &V)
	{
		for (n = 1; n < V.size(); n <<= 1);
		T.resize(n<<1);

		for (int i = 0; i < V.size(); i++) T[i+n] = node(V[i]);
		for (int i = n-1; i; i--)
		{
			T[i].val = T[i*2].val + T[i*2+1].val;
			T[i].siz = T[i*2].siz + T[i*2+1].siz;
		}
	}
	
	segtree(int _n)
	{
		for (n = 1; n < _n; n<<=1);
		T.resize(n<<1);

		for (int i = n-1; i; i--)
		{
			T[i].siz = T[i*2].siz + T[i*2+1].siz;
		}
	}

	void propagate(int k)
	{
		auto &[val, siz, flip] = T[k];
		if (flip)
		{
			val = siz - val;	
			flip = 0;
			if (k < n)
			{
				T[k*2].flip = !T[k*2].flip;
				T[k*2+1].flip = !T[k*2+1].flip;
			}
		}
	}

	void flip(int l, int r, int k=1, int x=0, int y=-1)
	{
		if(y == -1) y = n;
		if (l <= x && y <= r)
		{
			T[k].flip = !T[k].flip;
		}
		propagate(k);
		if (l <= x && y <= r) return;
		if (r <= x || y <= l) return;
		int m = (x+y)/2;
		flip(l, r, k*2, x, m);
		flip(l, r, k*2+1, m, y);
		T[k].val = T[k*2].val + T[k*2+1].val;
	}

	int get(int l, int r, int k=1, int x=0, int y=-1)
	{
		if (y == -1) y = n;
		propagate(k);
		if (l <= x && y <= r) return T[k].val;
		if (r <= x || y <= l) return 0;
		int m= (x+y)/2;
		return get(l, r, k*2, x, m) + get(l, r, k*2+1, m, y);
	}
};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, q;
	cin >> n >> q;
	segtree seg(n);
	while(q--)
	{
		int t, a, b;
		cin >> t >> a >> b;
		b++;
		if (t)
		{
			cout << seg.get(a, b) << "\n";
		}
		else
		{
			seg.flip(a, b);
		}
	}
}

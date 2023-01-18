#include <utility>
#include <iostream>
#include <vector>
using namespace std;

struct segtree
{
	int n;
	vector < int > T;
	
	segtree(vector < int > &H)
	{
		for (n = 1; n < H.size(); n <<= 1);
		T.resize(n*2);
		for (int i = 0; i < H.size(); i++)
			T[n+i] = H[i];
		for (int k = n-1; k; k--)
			T[k] = max(T[k*2], T[k*2+1]);
	}
	
	void set(int k, int v)
	{
		k += n;
		T[k] = v;
		for (k >>= 1; k; k >>= 1)
		{
			T[k] = max(T[k*2], T[k*2+1]);
		}
	}
	
	int left_bound(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y == -1)
			y = n;
		if (T[k] <= v)
			return -1;
		if (r <= x || y <= l)
			return -1;
		if (x == y-1)
			return x;
		int m = (x+y)/2;
		int ans = left_bound(l, r, v, k*2+1, m, y);
		if (ans == -1)
			ans = left_bound(l, r, v, k*2, x, m);
		return ans;
	}
	
	int right_bound(int l, int r, int v, int k=1, int x=0, int y=-1)
	{
		if (y == -1)
			y = n;
		if (T[k] <= v)
			return n;
		if (r <= x || y <= l)
			return n;
		if (x == y-1)
		{
			return x;
		}
		int m = (x+y)/2;
		int ans = right_bound(l, r, v, k*2, x, m);
		if (ans == n)
		{
			ans = right_bound(l, r, v, k*2+1, m, y);
		}
		return ans;
	}
};
segtree *seg;
vector < int > H;
int n;

pair<int, int> chiedi(int x) {
    return {max(0, seg->left_bound(0, x, H[x])), min(n-1, seg->right_bound(x, n, H[x]))};
}

void cambia(int x, int h) {
	seg->set(x, h);
	H[x] = h;
    return;
}

void inizializza(int N, vector<int> H) {
	::H = H;
	seg = new segtree(H);
	n = N;
	return;
}


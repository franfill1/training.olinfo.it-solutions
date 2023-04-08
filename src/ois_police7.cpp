#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct segtree
{
	struct node
	{
		ll a, b, sum=0;

		node (ll v) : a(v) , b(v), sum(v) {}
		node() {}
	};

	vector < node > T;
	int n;

	segtree (vector < ll > V)
	{
		for (n = 1; n < V.size(); n<<=1);
		T.resize(2*n);
		for (int i = 0; i < V.size(); i++) T[i+n] = node(V[i]);
		for (int k = n-1; k; k--) calc(k);
	}

	void calc(int k)
	{
		T[k].a = max(T[k*2].a, T[k*2+1].a);	
		T[k].b = T[k*2+1].b;
		T[k].sum = getpre(k*2, T[k*2+1].a) + T[k*2+1].sum;
	}

	ll getpre(int k, ll low)
	{
		if (T[k].a <= low) return 0;
		ll ans = T[k].sum;
		if (k >= n) return ans;
		ans -= T[k*2+1].sum;
		ll temp = getpre(k*2+1, low);
		if (temp != 0) return ans + temp;
		else return getpre(k*2, low);
	}

	void set(int i, ll v)
	{
		int k = i+n;
		T[k].a = T[k].b = T[k].sum = v;
		for (k >>= 1; k; k >>= 1) calc(k);
	}

	ll get()
	{
		return T[1].sum;
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n, q = 0;
	cin >> n >> q;
	vector < ll > V(n);
	for (ll &v : V) cin >> v;
	segtree seg(V);
	while(q--)
	{
		int p;
		ll s;
		cin >> p >> s;
		seg.set(p, s);
		cout << seg.get() << "\n";
	}

}

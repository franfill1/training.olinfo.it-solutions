#include<bits/stdc++.h>
#define mod 1000000007
#pragma gcc Optimize("O3")
using namespace std;
typedef long long ll;

ll modpow(ll b, ll e)
{
	if (e == 0) return 1;
	ll t = modpow(b, e/2);
	return ((t*t)%mod * (e % 2 ? b : 1))%mod;
}

vector < double > logg(100005);

struct LiChao
{
	struct func
	{
		ll b=1, c=0;	

		func (){}
		func (ll _b, ll _c) : b(_b) , c(_c){};
		double prev(ll x)
		{ 
			x++;
			return logg[b] + logg[x] * c;
		}

		ll eval(ll x)
		{
			x++;
			ll p = modpow(x, c);	
			return (b%mod * p)%mod;
		}
	};

	bool cmp(func a, func b, ll x)
	{
		return a.prev(x) > b.prev(x); 
	}

	ll n;
	vector < func > t;

	LiChao(ll _n)
	{
		n = 1;
		while(n < _n) n*=2;
		t.resize(n*2);
	}

	void upd(ll l, ll r, ll b, ll c)
	{
		func f {b, c};
		upd(l, r, f, 1, 0, n);
	}

	void upd(ll l, ll r, func f, ll k, ll x, ll y)
	{
		//cout << l << " " << r << " " << x << " " << y << "!\n";
		if (r <= x || y <= l) return;
		if (l <= x && y <= r)
		{
			//cout << "add " << x << " " << y << "\n";
			add(f, k, x, y);
			//cout << "done\n";
			return;
		}

		ll m = (x+y)/2;
		upd(l, r, f, k*2, x, m);
		upd(l, r, f, k*2+1, m, y);
	}

	void add(func f, ll k, ll x, ll y)
	{
		//cout << k << "add: " << f.b << " " << f.c << "\n";
		ll m = (x+y)/2;	
		bool lef = cmp(f, t[k], x);
		bool mid = cmp(f, t[k], m);
		if (mid)
		{
			//cout << "ehi\n";
			swap(t[k], f);
		}

		if (y-x == 1) return;
		else if (lef != mid)
		{
			add(f, k*2, x, m);
		}
		else
		{
			add(f, k*2+1, m, y);
		}
	}

	ll query(ll i)
	{
		ll ans = 0;	
		ll be = i+n;
		for (ll k = (i+n)/2; k; k/=2)
		{
			if (cmp(t[k], t[be], i)) be = k;
		}
		return t[be].eval(i);
	}
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	for (int i = 1; i < logg.size(); i++)
	{
		logg[i] = log(i);
	}
	int N;
	cin >> N;
	LiChao L(N);
	vector < ll > a(N);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
		L.upd(i, i+1, a[i], 0);
	}
	//cout << L.query(0) << "!\n";

	int Q;
	cin >> Q;
	while(Q--)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int x;
			cin >> x;
			x--;
			cout << L.query(x) << "\n";
		}
		else
		{
			int x, y;
			ll b, c;
			cin >> x >> y >> b >> c;
			x--;
			L.upd(x, y, b, c);
		}
	}
}


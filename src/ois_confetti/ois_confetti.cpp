#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mcd(ll a, ll b)
{
	while(b != 0)
	{
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ll n, m;
	cin >> n >> m;
	while(--n)
	{
		ll e; cin >> e;
		m = mcd(m, e);
	}

	stack < ll > s;

	for (ll i = 1; i*i <= m; i++)
	{
		if (m % i == 0)
		{
			cout << i << " ";
			if (i*i != m) s.push(m/i);
		}
	}

	while(!s.empty())
	{
		cout << s.top() << " "; s.pop();
	}
}

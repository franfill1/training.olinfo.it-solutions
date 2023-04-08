#pragma GCC Optimize("O3")
#include<bits/stdc++.h>
using namespace std;

using ll=long long;
constexpr ll maxv = 30000;
constexpr ll maxn = 100000;

unordered_map < ll , ll > cnt[maxn], tot[maxn];
bool isprime[maxv+1], ok[maxv+1];
ll dis[maxn], sign[maxv+1], V[maxn];
vector < ll > divs[maxv+1], g[maxn];
ll ans = 0;

void dfs(int x, int p)
{
		dis[x] = dis[p] + V[x];
		for (auto y : g[x])
			if (y != p)
			{
				dfs(y, x);
				assert(cnt[y].size() == tot[y].size());
				if (cnt[y].size() > cnt[x].size())
				{
					swap(cnt[x], cnt[y]);
					swap(tot[x], tot[y]);
				}
				for (auto [d, c1] : cnt[y])
				{
					ll &c2 = cnt[x][d], &t1 = tot[y][d], &t2 = tot[x][d];
					ll t = t2*c1 + c2*t1 - c2*c1*((dis[x]<<1)-V[x]);
					ans += t*sign[d];
					t2 += t1; 
					c2 += c1;
				}
			}
		for (ll d : divs[V[x]])
		{
			ll &t2 = tot[x][d], &c2 = cnt[x][d];
			ll t = t2 + c2*dis[x] - c2*(2*dis[x]-V[x]);
			ans += t*sign[d];
			t2 += dis[x];
			c2++;
		}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> V[i];
	for (ll i = 0; i < n-1; i++)
	{
		ll a, b;
		cin >> a >> b;
		a--, b--;
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}	

	fill(isprime+2, isprime+maxv+1, 1);
	fill(ok+2, ok+maxv+1, 1);
	vector < int > primes;
	for (ll i = 2; i <= maxv; i++)
	{
		if (isprime[i])
		{
			sign[i] = 1;
			primes.emplace_back(i);
		}

		for (auto p : primes)
		{
			if (i*p > maxv)
				break;
			ok[i*p] = ok[i];
			isprime[i*p] = false;
			sign[i*p] = -sign[i];
			if (i % p == 0)
			{
				ok[i*p] = false;
				break;
			}
		}
	}

	for (ll d = 2; d <= maxv; d++)
		if (ok[d])
			for (int i = 1; d*i <= maxv; i++)
				divs[i*d].emplace_back(d);

	dfs(0, 0);
	cout << ans << "\n";
}

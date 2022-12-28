#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long long ll;
typedef pair < ll , ll > pll;
ll inf = 1ll<<60;

int main()
{
	int N, M;
	fin >> N >> M;
	
	vector < vector < pll > > g(N);
	for (int i = 0; i < M; i++)
	{
		ll a, b, w;
		fin >> a >> b >> w;
		a--; b--;
		g[a].push_back(make_pair(b, w));
		g[b].push_back(make_pair(a, w));
	}
	
	vector < ll > D(N, inf);
	D[0] = 0;
	
	priority_queue < pll , vector < pll > , greater < pll > > pq;
	pq.push({0, 0});
	
	while(!pq.empty())
	{
		ll d = pq.top().first;
		ll n = pq.top().second;
		pq.pop();
		for (pll nep : g[n])
		{
			ll b = nep.first;
			ll w = nep.second;
			
			ll nd = d + w;
			if (nd < D[b])
			{
				D[b] = nd;
				pq.push({nd, b});
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		int ma = (i + 1)*10;
		if(D[i] <= ma)
		{
			ans++;
		}
	}
	fout << ans;
}
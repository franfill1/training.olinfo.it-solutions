#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < ll , ll > pll;
ll inf = 1ll<<62;

long long costruisci(int N, int M, vector<long long>& H, vector<int>& A, vector<int>& B, vector<int>& C) {
    vector < vector < pll > > g(N);
    for (int i = 0; i < M; i++)
    {
    	g[A[i]].push_back({B[i], C[i]});
	}
	
	priority_queue < pll , vector < pll > , greater < pll > > pq;
	for (int i = 0; i < N; i++)
	{
		pq.push({H[i], i});
	}
	
	while(!pq.empty())
	{
		ll n = pq.top().second, h = pq.top().first;
		pq.pop();
		for (pll nep : g[n])
		{
			ll ne = nep.first;
			ll c = nep.second;
			ll nh = h + c;
			if (nh < H[ne])
			{
				H[ne] = nh;
				pq.push({nh, ne});
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += H[i];
	}
	return ans;
}
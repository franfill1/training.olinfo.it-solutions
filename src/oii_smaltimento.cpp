#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < ll , ll > pll;

ll smaltisci(int N, int M, vector<int> A, vector<vector<int>> B) 
{
    vector < vector < ll > > g(N+M);

    vector < ll > dist(N+M, 1ll<<50);
    priority_queue < pll , vector < pll > , greater < pll > > pq;
    for (ll i = 0; i < M; i++)
    {
        if (B[i].size() == 0)
        {
            pq.push({1, A[i]});
            dist[A[i]] = 1;
        }
        g[N+i].push_back(A[i]);

        for (ll e : B[i])
        {
            g[e].push_back(N+i);
        }
    }

    vector < ll > cnt(M, 0);
    vector < bool > vis(N, 0);
    for (ll i = N; i < N+M; i++) dist[i] = 0;

    while(!pq.empty())
    {
        auto [d, x] = pq.top();
        pq.pop();
        if (dist[x] < d) continue;
        
        if (x >= N)
        {
            assert(g[x].size() == 1);
            ll y = g[x][0];
            if (dist[y] > d+1)
            {
                dist[y] = d+1;
                pq.push({d+1, y});
            }
        }
        else
        {
            for (ll y : g[x])
            {
                dist[y] += d;
                cnt[y-N]++;
                if (cnt[y-N] == B[y-N].size())
                {
                    pq.push({dist[y], y});
                }
            }
        }
    }
    return dist[0];
}

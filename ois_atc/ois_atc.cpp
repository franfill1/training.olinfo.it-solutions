#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct nod
{
	ll i, j;
	ll w;
	ll d;
};

bool operator < (nod a, nod b)
{
	return a.w > b.w;
}

main ()
{
    ll N;
    cin >> N;
	    
    vector<string> matrix(N+1);
    for (ll i=0; i<N; i++)
        cin >> matrix[i];        
			
    deque < nod > q;
    
    vector<vector < ll > > dis(N+1, vector < ll > (N+1, N*N));
    
    dis[0][0] = 0;
    
    q.push_front({0, 0, 0, 0});
    q.push_front({0, 0, 0, 2});
    
    vector < ll > dx {1, -1, 0, 0};
    vector < ll > dy {0, 0, 1, -1};
    
    while (!q.empty())
    {
        nod p = q.front();
        q.pop_front();
        
        for (ll d = 0; d < 4; d++)
        {
        	ll i = p.i + dx[d], j = p.j + dy[d];
        	if (i >= 0 && i < N && j >= 0 && j < N && matrix[i][j] != '#')
        	{
	            ll cost = (p.d == d ? 0 : 1);
	            if (p.w + cost <= dis[i][j])
	            {
	            	dis[i][j] = p.w + cost;
	            	if (cost) q.push_back({i, j, dis[i][j], d});
	            	else q.push_front({i, j, dis[i][j], d});
				}
	        }
        }
    }
    
    
    if (dis[N-1][N-1] == N*N)
    	cout << "-1";
    else
    	cout << dis[N-1][N-1];
}
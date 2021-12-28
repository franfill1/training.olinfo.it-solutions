#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair < int , ll > pill;
typedef pair < ll , int > plli;

int travel_plan(int N, int M, int R[][2], int L[], int K, int P[])
{
    vector < vector < pill > > g(N);
    for (int i = 0; i < M; i++)
    {
    	g[R[i][0]].push_back({R[i][1], L[i]});
    	g[R[i][1]].push_back({R[i][0], L[i]});
	}
	
	vector < vector < ll > > D(N, {1ll<<60, 1ll<<60});
	priority_queue < plli , vector < plli > , greater < plli > > pq;
	for (int i = 0; i < K; i++)
	{
		D[P[i]] = {0, 0};
		pq.push({0, P[i]});
	}
	
	while(!pq.empty())
	{
		int n = pq.top().second; ll d = pq.top().first;
		pq.pop();
		if (n == 0)
		{
			break;
		}
		else if (d == D[n][1])
		{
			for (pill nep : g[n])
			{
				int ne = nep.first;
				ll w = nep.second;
				ll nd = d + w;
				
				ll past = D[ne][1];
				
				if (D[ne][0] > nd)
				{
					D[ne][1] = D[ne][0];
					D[ne][0] = nd;
				}
				else if (D[ne][1] > nd)
				{
					D[ne][1] = nd;
				}
				
				if (D[ne][1] != past)
				{
					pq.push({D[ne][1], ne});
				}
			}
		}
	}
	return D[0][1];
}
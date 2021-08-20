#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")

using namespace std;

typedef pair < int , int > ii;

int inf = 1<<20;
int N;

vector < vector < ii > > g;

int dijkstra (int st)
{
	vector < int > D(N, inf);
	priority_queue < ii , vector < ii > , greater < ii > > pq;
	pq.push({0, st});
	D[st] = 0;
	int ans = 0;
	while(!pq.empty())
	{
		int n = pq.top().second, d = pq.top().first;
		pq.pop();
		if (d == D[n])
		{
			ans = max(ans, d);
			for (ii nep : g[n])
			{
				if (D[nep.first] > nep.second + d)
				{
					D[nep.first] = nep.second + d;
					pq.push({D[nep.first], nep.first});
				}
			}
		}
	}
	return ans;
}

int latenza(int NN, int M, int A[], int B[], int L[])
{
	N = NN;
    vector < vector < int > > G(N, vector < int > (N, inf));
    
    g.resize(N);
    
    for (int i = 0; i < M; i++)
    {
    	A[i]--; B[i]--;
    	g[A[i]].push_back({B[i], L[i]});
    	g[B[i]].push_back({A[i], L[i]});
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dijkstra(i));
	}
	
	return ans;
}
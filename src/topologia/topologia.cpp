#include<bits/stdc++.h>
using namespace std;

int n;
vector < vector < int > > g;
vector < bool > vis;
vector < bool > v;

bool checkStar(int x)
{
	if (g[x].size() == 2 || g[x].size() == 0) return false;
	if (g[x].size() == 1) return checkStar(g[x][0]); 
	for (int y : g[x]) if (g[y].size() != 1) return false;
	return true;
}

void Analizza(int N, int M, int* A, int* B, int* T) 
{
	n = N;		
	g.resize(n);
	vis.resize(n, false);
	v.resize(n, false);
	for (int i = 0; i < M; i++)
	{
		A[i]--; B[i]--;
		g[A[i]].push_back(B[i]);
		g[B[i]].push_back(A[i]);
	}

	for (int i = 0; i < n; i++) if(!v[i])
	{
		int t = 1;
		v[i] = 1;
		if (g[i].size() == 0) continue;

		queue < int > q; q.push(i);

		while(!q.empty())
		{
			int x = q.front(); q.pop();

			if (g[x].size() > 2) t = -1;
			if (t != -1 && g[x].size() == 1) t = 0;

			for (int y : g[x]) if (!v[y])
			{
				v[y] = true;
				q.push(y);
			}
		}

		if( t == -1 && checkStar(i)) T[2]++;
		else T[t]++;
	}
}

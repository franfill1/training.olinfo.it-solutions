#include <bits/stdc++.h>

using namespace std;

vector < pair < int , int > > F;
int N;

int inf = numeric_limits<int>::max();

int getDist (int a , int b)
{
	if (b == 0 || b == F.size()+1)
	{
		swap(a, b);
	}
	if (a == 0)
	{
		if (b == 0 || b == F.size()+1)
		{
			return inf;
		}
		else
		{
			b--;
			return min(N-1-F[b].first, F[b].second);
		}	
	}
	else if (a == F.size()+1)
	{
		if (b == 0 || b == F.size()+1)
		{
			return inf;
		}
		else
		{
			b--;
			return min(F[b].first, N-1-F[b].second);
		}
	}
	else
	{
		a--; b--;
		int dx = abs(F[a].first - F[b].first);
		int dy = abs(F[a].second - F[b].second);
		if (dx == 0)
		{
			return (dy/2);
		}
		else if (dy == 0)
		{
			return (dx/2);
		}
		else
		{
			return (dx + dy - 1)/2;
		}
	}

}

int alzati(int n, int M, int X[], int Y[]) 
{
	N = n;
	F.resize(M);
	for (int i = 0; i < M; i++)
	{
		F[i] = {X[i], Y[i]};
	}
	vector < int > D(M+2, inf);
	D[0] = 0;
	vector < bool > vis(M+2, false);
	
	while(!vis[M+1])
	{
		int n = -1;
		for (int i = 0; i < M+2; i++)
		{
			if (!vis[i] && (n == -1 || D[i] < D[n]))
			{
				n = i;
			}
		}
		vis[n] = true;
		for (int i = 0; i < M+2; i++)
		{
			if (!vis[i])
			{
				D[i] = min(D[i], max(D[n], getDist(n, i)));
			}
		}
	}
	return D[M+1]-1;
}
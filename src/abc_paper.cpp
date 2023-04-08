#include <bits/stdc++.h>

using namespace std;

vector < vector < int > > g;
vector < vector  < int > > gr;
vector < int > ts;
vector < int > comp;

void dfs(int n)
{
	comp[n] = 1;
	for (int ne : g[n])
	{
		if (!comp[ne])
		{
			dfs(ne);
		}
	}
	ts.push_back(n);
}

void dfs1(int n, int c)
{
	comp[n] = c;
	for (int ne : gr[n])
	{
		if (comp[ne] == -1)
		{
			dfs1(ne, c);
		}
	}
}

int paper(int N, int M, int A[], int B[]) 
{
    g.resize(N);
    gr.resize(N);
    comp.resize(N, 0);
    for (int i = 0; i < M; i++)
    {
    	g[A[i]-1].push_back(B[i]-1);
    	gr[B[i]-1].push_back(A[i]-1);
	}
	
	for (int i = 0; i < N; i++)
	{
		if (comp[i] == 0) dfs(i);
	}

	comp.assign(N, -1);
	int c = 0;
	for (int i = N-1; i >= 0; i--)
	{
		int n = ts[i];
		if (comp[n] == -1)
		{
			dfs1(n, c);
			c++;
		}
	}

	vector < bool > toDo(c,1);
	for (int n = 0; n < N; n++)
	{
		for (int ne : g[n])
		{
			if (comp[ne] != comp[n]) toDo[comp[ne]] = 0;
		}
	}
	
	int co = -1;
	for (int i = 0; i < c; i++)
	{
		if (toDo[i])
		{
			if (co != -1)
			{
				return 0;
			}
			else
			{
				co = i;
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += (comp[i] == co);
	}
	return ans;
}
#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	
	vector < vector < int > > g(N);
	for (int i = 0; i < N; i++)
	{
		g.resize(0);
	}
	
	vector < int > mon(N);
	for (int i = 0; i < N; i++)
	{
		fin >> mon[i];
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	queue < int > q;
	vector < bool > vis (N, false);
	vis[0] = true;
	q.push(0);
	
	while(!q.empty())
	{
		int n = q.front();
		vis[n] = true;
		q.pop();
		
		for (int i = 0; i < g[n].size(); i++)
		{
			int nxt = g[n][i];
			if (!vis[nxt])
			{
				q.push(nxt);
				
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (vis[i])
		{
			ans += mon[i];
		}
	}
	fout << ans;
}

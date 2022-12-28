#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int inf = 1<<30;

int main()
{
	int N, M, K;
	fin >> N >> M >> K;
	
	vector < int > s(K);
	for (int i = 0; i < K; i++)
	{
		fin >> s[i];
		s[i]--;
	}
	
	vector < vector < int > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector < int > d1 (N, inf);
	d1[0] = 0;
	
	queue < int > q;
	q.push(0);
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		for (int ne : g[n])
		{
			if (d1[ne] == inf)
			{
				d1[ne] = d1[n] + 1;
				q.push(ne);
			}
		}
	}
	
	vector < int > d2(N, inf);
	d2[N-1] = 0;
	
	q.push(N-1);
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		for (int ne : g[n])
		{
			if (d2[ne] == inf)
			{
				d2[ne] = d2[n] + 1;
				q.push(ne);
			}
		}
	}
	
	int ans = inf;
	for (int i = 0; i < K; i++)
	{
		int dtot = d1[s[i]] + d2[s[i]];
		ans = min(ans, dtot);
	}
	fout << ans;
}

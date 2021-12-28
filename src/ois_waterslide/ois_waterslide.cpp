#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

stack < int > s;
vector < vector < int > > g;
vector < bool > vis;

void topoSort(int n)
{
	vis[n] = true;
	for (int ne : g[n])
	{
		if (!vis[ne])
		{
			topoSort(ne);
		}
	}
	s.push(n);
}

int main()
{
	int N, M, P;
	fin >> N >> M >> P;
	g.resize(N);
	vis.resize(N, false);
	for (int i = 0; i < M; i++)
	{
		int a,b;
		fin >> a >> b;
		g[a].push_back(b);
	}
	
	topoSort(0);
	
	vector < double > C(N, 0);
	C[0] = 1;
	
	while(!s.empty())
	{
		int n = s.top();
		for (int ne : g[n])
		{
			C[ne] += C[n] / g[n].size();
		}
		s.pop();
	}
	
	int ans = N - P;
	for (int i = N - P; i < N; i++)
	{
		if (C[i] > C[ans])
		{
			ans = i;
		}
	}
	fout << ans;
}

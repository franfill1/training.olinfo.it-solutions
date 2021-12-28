#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	vector < int > H(N);
	for (int i = 0; i < N; i++)
	{
		fin >> H[i];
	}
	
	vector < vector < int > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vector < int > visited(N, false);
	int n = 0;
	int last = -1;
	while(!visited[n])
	{
		visited[n] = true;
		int m = -1;
		for (int i = 0; i < g[n].size(); i++)
		{
			if (g[n][i] != last)
			{
				if (m == -1 || H[g[n][i]] < H[m])
				{
					m = g[n][i];
				}
			}
		}
		if (m == -1)
		{
			break;
		}
		else
		{
			last = n;
			n = m;
		}
	}
	fout << n;
}

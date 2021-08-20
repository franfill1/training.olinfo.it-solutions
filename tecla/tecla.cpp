#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < vector < int > > g;
vector < vector < bool > > vis;

vector < int > ans;

bool dfs (int n, bool a)
{
	if (n == 0 && a == true)
	{
		ans.push_back(n);
		return true;
	}
	for (int ne : g[n])
	{
		int na = !a;
		if (!vis[ne][na])
		{
			vis[ne][na] = true;
			bool ok = dfs(ne, na);
			if (ok)
			{
				ans.push_back(n);
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int N, M;
	fin >> N >> M;
	g.resize(N);
	
	vis.resize(N);
	for (int i = 0; i < N; i++)
	{
		vis[i].resize(2, false);
	}
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	vis[0][0] = true;
	dfs(0, 0);
	fout << ans.size() - 1 << "\n";
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		fout << ans[i] << " ";
	}
	
}

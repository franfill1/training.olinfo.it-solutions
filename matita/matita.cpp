#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int n, m, f, t;
	fin >> n >> m >> f >> t; f--; t--;

	vector < unordered_set < int > > g(n);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		fin >> a >> b; a--; b--;
		g[a].insert(b); g[b].insert(a);
	}

	stack < int > s;
	vector < int > sol;
	s.push(t);
	while(!s.empty())
	{
		int u = s.top();
		if (g[u].size() == 0)
		{
			sol.push_back(u);
			s.pop();
		}
		else
		{
			int v = *g[u].begin();
			g[u].erase(v); g[v].erase(u);
			s.push(v);
		}
	}

	for (int j = 0; j < sol.size()-1; j++)
	{
   	    fout << sol[j]+1 << " " << sol[j+1]+1 << "\n";
	}
}

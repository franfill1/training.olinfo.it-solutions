#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	
	vector < vector < int > > g(N);
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		g[a].push_back(b);
	}
	
	vector < vector < bool > > vis(N, {false, false});
	queue < pair < int , bool > > q;
	q.push({0, false});
	
	int ans = 1;
	vis[0][0] = true;
	
	while(!q.empty())
	{
		int n = q.front().first;
		bool v = q.front().second;
		q.pop();
		
		for (int ne : g[n])
		{
			int nv = !v;
			if (!vis[ne][nv])
			{
				q.push(make_pair(ne, nv));
				vis[ne][nv] = true;
				ans += (!nv);
			}
		}
	}
	fout << ans;
}

#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	
	vector < vector < int > > g(N);
	vector < int > L(N);
	
	queue < int > q;
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		int M;
		fin >> M >> L[i];
		
		for (int j = 0; j < M; j++)
		{
			int a;
			fin >> a;
			g[a].push_back(i);
		}
		
		if (L[i] == 0)
		{
			q.push(i);
			ans++;
		}
	}
	
	while(!q.empty())
	{
		int n = q.front();
		q.pop();
		
		for (int ne : g[n])
		{
			if (L[ne] != 0)
			{
				L[ne]--;
				if (L[ne] == 0)
				{
					q.push(ne);
					ans++;
				}
			}
		}
	}
	
	fout << ans;
}
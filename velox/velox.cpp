#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct edge
{
	int a, b, w;	
};

int N, M;

vector < edge > l;
vector < vector < int > > out;
vector < int > ans(M, -1);

int dfs(int id)
{
	if (ans[id] != -1)
	{
		return ans[id];
	}
	else
	{
		ans[id] = 1;
		for (int ned : out[l[id].b])
		{
			if (l[ned].w > l[id].w)
			{
				ans[id] = max(ans[id], dfs(ned) + 1);
			}
		}
		return ans[id];
	}
}

int main()
{
	fin >> N >> M;

	out.resize(N);
	
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		fin >> a >> b >> w;
		out[a].push_back(i);
		l.push_back({a, b, w});
	}
	
	ans.resize(M, -1);
	
	int a = 0;
	for (int i = 0; i < M; i++)
	{
		a = max(a, dfs(i));
	}
	fout << a;
}

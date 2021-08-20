#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < vector < int > > T;

int ans = 0;

int dp (int n, int from)
{
	int be1 = 0, be2 = 0;
	
	for (int ne : T[n])
	{
		if (ne != from)
		{
			int md = dp(ne, n) + 1;
			if (md > be1)
			{
				be2 = be1;
				be1 = md;
			}
			else if (md > be2)
			{
				be2 = md;
			}
		}
	}
	int maxP = be1 + be2;
	if (maxP > ans)
	{
		ans = maxP;
	}
	return be1;
}

int main()
{
	int N;
	fin >> N;
	T.resize(N);
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		fin >> a >> b;
		
		T[a].push_back(b);
		T[b].push_back(a);
	}
	dp(0, 0);
	
	fout << ans * 2;
}

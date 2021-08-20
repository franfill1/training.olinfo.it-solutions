#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef long long ll;


vector < vector < char > > mappa;
vector < vector < ll > > memo;

ll walk(int n, int m)
{
	if (memo[n][m] != -1)
	{
		return memo[n][m];
	}
	else
	{
		int maxN = mappa.size() - 1;
		int maxM = mappa[0].size() - 1;
		if (n == maxN && m == maxM)
		{
			return 1;
		}
		else
		{
			ll ans = 0;
			if (n + 1 <= maxN && mappa[n + 1][m] != '+')
			{
				ans += walk(n + 1, m);
			}
			
			if (m + 1 <= maxM && mappa[n][m + 1] != '+')
			{
				ans += walk(n, m + 1);
			}
			memo[n][m] = ans;
			return ans;
		}
	}
}


int main()
{
	int N, M;
	fin >> N >> M;
	
	mappa.resize(N);
	memo.resize(N);
	for (int i = 0; i < N; i++)
	{
		mappa[i].resize(M);
		memo[i].resize(M, -1);
		for (int j = 0; j < M; j++)
		{
			fin >> mappa[i][j];
		}
	}
	
	fout << walk(0, 0);
}

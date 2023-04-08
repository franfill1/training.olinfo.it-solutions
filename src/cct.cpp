#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int inf = 1<<30;

int main()
{
	int N, K;
	fin >> N >> K;
	
	vector < int > V(N);
	for (int i = 0; i < N; i++)
	{
		fin >> V[i];
	}
	
	vector < int > C(N);
	for (int i = 0; i < N; i++)
	{
		fin >> C[i];
	}
	
	vector < vector < int > > memo(N+1, vector < int > (K+1, inf));
	
	memo[0][0] = 0;
	
	for (int n = 0; n < N; n++)
	{
		for (int k = 0; k <= K; k++)
		{
			int nk = min(K, k + C[n]);
			memo[n+1][nk] = min(memo[n+1][nk], memo[n][k] + V[n]);
			
			if (k == K)
			{
				memo[n+1][0] = min(memo[n+1][0], memo[n][k]);
			}
		}
	}
	
	int ans = inf;
	for (int i = 0; i <= K; i++)
	{
		ans = min(ans, memo.back()[i]);
	}
	
	fout << ans;
}

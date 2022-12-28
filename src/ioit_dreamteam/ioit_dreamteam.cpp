#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int K, N;
	fin >> N >> K;
	
	vector < int > F(N);
	vector < int > P(N);
	vector < int > Q(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> F[i] >> P[i] >> Q[i];
	}
	
	vector < bool > c(N, false);
	for (int i = 0; i < N; i++)
	{
		if(!c[i])
		{
			c[i] = true;
			c[F[i]] = true;
			if (P[i] > P[F[i]])
			{
				P[F[i]] = Q[i] + Q[F[i]] - P[i];
			}
			else
			{
				P[i] = Q[i] + Q[F[i]] - P[F[i]];
			}
		}
	}
	sort(P.rbegin(), P.rend());
	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		ans += P[i];
	}
	fout << ans;
}

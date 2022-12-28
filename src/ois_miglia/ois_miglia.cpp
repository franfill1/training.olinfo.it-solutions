#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair < int , int > ii;
typedef pair < int , pair < int , int > > iii;

int main()
{
	int K, N, M;
	fin >> K >> N >> M;
	vector < vector < ii > > g(N);
	for (int i = 0; i < M; i++)
	{
		int da, a, v;
		fin >> da >> a >> v;
		g[da].push_back(make_pair(a, v));
	}
	
	vector < vector < int > > D(N, vector < int > (K+1, -1));
	D[0][0] = 0;
	
	for (int k = 0; k < K; k++)
	{
		for (int n = 0; n < N; n++)
		{
			if (D[n][k] != -1)
			{
				for (auto ne : g[n])
				{
					D[ne.first][k+1] = max(D[ne.first][k+1], D[n][k] + ne.second);
				}
			}
		}
	}
	
	fout << D[0][K];
}

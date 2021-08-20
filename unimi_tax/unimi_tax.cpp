#include <bits/stdc++.h>

using namespace std;

double starting = 1;

int main()
{
	int N, M;
	cin >> N >> M;
	vector < vector < double > > D(N, vector < double > (N, 0));
	for (int i = 0; i < M; i++)
	{
		int a, b, p;
		cin >> a >> b >> p;
		D[a][b] = starting * (1000 - (double)p) / 1000;
	}
	for (int i = 0; i < N; i++)
	{
		D[i][i] = 1;
	}
	
	for (int h = 0; h < N; h++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				D[i][j] = max(D[i][j], D[i][h] * D[h][j]);
			}
		}
	}
	int ii = 0, jj = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (D[i][j] < D[ii][jj])
			{
				ii = i;
				jj = j;
			}
		}
	}
	cout << ii << " " << jj << "\n";
}

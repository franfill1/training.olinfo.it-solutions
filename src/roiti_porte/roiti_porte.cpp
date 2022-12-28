#include <bits/stdc++.h>

#define M 1000000007

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < int > P(N);
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	
	vector < int > memo(N, 0);
	memo[N-1] = 1;
	for (int i = N - 2; i >= 0; i--)
	{
		for (int d = 1; i + d < N; d *= 2)
		{
			int j = i + d;
			if ((P[i] + P[j]) % d == 0)
			{
				memo[i] += memo[j];
				memo[i] %= M;
			}
		}
	}
	fout << memo[0];
}

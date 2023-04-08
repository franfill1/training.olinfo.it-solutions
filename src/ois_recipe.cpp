#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

typedef long double ld;

int main()
{
	int N, M;
	fin >> N >> M;
		
	vector < ld > final (N, 0);
	
	for (int i = 0; i < M; i++)
	{
		vector < ld > ric(N);
		ld sum = 0;
		for (int j = 0; j < N; j++)
		{
			fin >> ric[j];
			sum += ric[j];
		}
		
		ld conv = ((ld)(1000000)) / sum;
		
		for (int j = 0; j < N; j++)
		{
			final[j] += ric[j] * conv;
		}
	}
	
	for (int i = 0; i < N; i++)
	{
		fout << (int)(final[i] / M) << " ";
	}
}

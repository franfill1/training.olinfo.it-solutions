#include<bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main()
{
	int N;
	fin >> N;
	
	vector < int > P(N, 0);
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		
		for (int j = 0; j < N + 1; j++)
		{
			int sc;
			fin >> sc;
			P[i] += sc;
		}
		
		P[i]++;
		
		if (P[i] > P[ans])
		{
			ans = i;
		}
		
		fout << ans + 1 << "\n";
	}
}
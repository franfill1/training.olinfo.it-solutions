#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	int N, M;
	fin >> N >> M;
	
	vector < int > P(N);
	vector < int > C(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	for (int i = 0; i < N; i++)
	{
		fin >> C[i];
	}
	
	int ans = 0;
	
	for (int i = 0; i < N; i++)
	{
		if (M >= P[i])
		{
			ans++;
			M -= P[i];
		}
		else
		{
			M += C[i];
		}
	}
	
	fout << ans << " " << M;
	return 0;
}


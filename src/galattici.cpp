#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int L, N, M;
	fin >> M >> N >> L;
	string S;
	for (int i = 0; i < L; i++)
	{
		char c;
		fin >> c;
		S += (c-'a');
	}
	
	vector < vector < int > > g(N, vector < int > (27));
	
	for (int i = 0; i < M; i++)
	{
		int f, t;
		char c;
		fin >> f >> t >> c;
		f--; t--; c -= 'a';
		g[f][c] = t;
	}
	int n = 0;
	for (int i = 0; i < L; i++)
	{
		n = g[n][S[i]];
	}
	fout << ++n;
}

#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector < vector < int > > tri;
vector < vector < int > > memo;

int discMass(int r, int c)
{
	if (memo[r][c] != -1)
	{
		return memo[r][c];
	}
	else if (r == tri.size() - 1) 
	{
		return tri[r][c];
	}
	else
	{
		memo[r][c] = max(discMass(r+1, c), discMass(r+1, c+1)) + tri[r][c];
		return memo[r][c];
	}
}


int main()
{
	int N;
	fin >> N;
	tri.resize(N);
	memo.resize(N);
	
	for (int i = 0; i < N; i++)
	{
		tri[i].resize(i + 1);
		memo[i].resize(i + 1, -1);
		for (int j = 0; j < i + 1; j++)
		{
			fin >> tri[i][j];
		}
	}
	
	fout << discMass(0, 0);
}

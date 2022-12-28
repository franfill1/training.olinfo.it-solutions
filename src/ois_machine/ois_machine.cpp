#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

const int inf = 1<<30;

int main()
{
	int C, D, Y;
	fin >> C >> D >> Y;
	vector < int > M(D+1);
	vector < int > P(D+1);
	for (int i = 1; i <= D; i++)
	{
		fin >> M[i];
	}
	for (int i = 1; i <= D; i++)
	{
		fin >> P[i];
	}
	
	vector < int > cos(D+1, C);
	for (int i = 1; i <= D; i++)
	{
		cos[i] = cos[i-1] + M[i];
	}
	for (int i = 1; i <= D; i++)
	{
		cos[i] -= P[i];
	}
	D = min(D, Y);
	vector < int > memo(Y+1, inf);
	vector < int > useful(0);
	memo[0] = 0;
	for (int i = 0; i <= D; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			memo[i] = min(memo[i], memo[i-j] + cos[j]);
		}
		
		if (cos[i] == memo[i])
		{
			useful.push_back(i);
		}
	}
	
	for (int i = 0; i <= Y; i++)
	{
		for (auto j : useful)
		{
			if (i - j >= 0)
			{
				memo[i] = min(memo[i], memo[i-j] + cos[j]);
			}
		}
	}
	fout << memo[Y];
}

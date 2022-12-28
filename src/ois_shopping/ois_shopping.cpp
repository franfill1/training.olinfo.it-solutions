#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int inf = 1<<20;

int main()
{
	int N, E;
	fin >> N >> E;
	vector < vector < int > > memo(N+1, vector < int > (2, -1));
	memo[0][0] = E;
	memo[0][1] = 0;

	
	for (int i = 1; i <= N; i++)
	{
		int c;
		fin >> c;
		
		memo[i][0] = max(memo[i-1][1], min(memo[i-1][0], c-1));
		memo[i][1] = max(memo[i-1][1] - c, memo[i-1][0] - c);
	}
	
	fout << max(memo[N][0], memo[N][1]);
}

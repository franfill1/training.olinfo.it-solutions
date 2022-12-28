#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

vector < int > state;
vector < int > nex;

int dfs(int n, int d)
{
	if (state[n] == -2)
	{
		return 0;
	}
	else if (state[n] == -1)
	{
		state[n] = d;
		int ans = dfs(nex[n], d+1);
		state[n] = -2;
		return ans;
	}
	else
	{
		int ans = d - state[n];
		state[n] = -2;
		return ans;
	}
}

int main()
{
	int N;
	fin >> N;
	state.resize(N, -1); nex.resize(N);
	for (int i = 0; i < N; i++)
	{
		fin >> nex[i];
	}
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, dfs(i, 0));
	}
	fout << ans;
}

#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N;
	fin >> N;
	vector < int > next(N);
	for (int i = 0; i < N; i++)
	{
		fin >> next[i];
		next[i] += i+1;
		next[i] %= N;
	}
	vector < bool > vis(N, false);
	
	int ans = N;
	int n = 0;
	while(!vis[n])
	{
		vis[n] = true;
		ans--;
		n = next[n];
	}
	
	fout << ans << "\n";
	for (int i = 0; i < N; i++)
	{
		if (!vis[i])
		{
			fout << i + 1 << " ";
		}
	}
}

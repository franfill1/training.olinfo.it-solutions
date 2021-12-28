#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	
	vector < bool > B(N);
	for (int i = 0; i < N; i++)
	{
		bool el;
		fin >> el;
		B[i] = el;
	}
	
	int ans = 0;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		fin >> a >> b;
		if (B[a] && B[b])
		{
			ans++;
		}
	}
	fout << ans;
}

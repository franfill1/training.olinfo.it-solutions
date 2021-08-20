#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef unsigned long long ull;

int main()
{
	ull N, D;
	fin >> N >> D;
	vector < ull > P(N);
	for (int i = 0; i < N; i++)
	{
		fin >> P[i];
	}
	
	queue < ull > q;
	ull ans = 0;
	for (int i = 0; i < N; i++)
	{
		while(!q.empty() && P[i] - q.front() >= D)
		{
			q.pop();
		}
		ans += q.size();
		
		q.push(P[i]);
	}
	fout << ans;
}

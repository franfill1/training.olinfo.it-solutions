#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, K;
	fin >> N >> K;
	vector < int > D(N);
	for (int i = 0; i < N; i++)
	{
		fin >> D[i];
	}
	sort(D.begin(), D.end());
	
	int ans = 1<<30;
	for (int i = 0; i + K - 1 < N; i++)
	{
		ans = min(ans, D[i + K - 1] - D[i]);
	}
	fout << ans << "\n";
}

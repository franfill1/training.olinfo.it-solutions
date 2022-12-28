#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
    int N, X;
    fin >> N >> X;
    vector < int > P(N), Q(N);
    for (int i = 0; i<  N; i++)
    {
    	fin >> P[i] >> Q[i];
	}

	int ans = 0;
	vector < int > cur(X+1, 0);
	for (int i = 0; i < N; i++)
	{
		vector < int > n = cur;
		for (int x = 0; x <= X; x++)
		{
			if (x + Q[i] <= X)
			{
				n[x + Q[i]] = max(n[x + Q[i]], cur[x] + P[i]);
			}
		}
		cur = n;
	}
	for (int i = 0; i <= X; i++)
	{
		ans = max(ans, cur[i]);
	}
	fout << ans;
}

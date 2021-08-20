#include<bits/stdc++.h>
using namespace std;

void visita(int N, int *PRE, int *POST, int *SIMM )
{
	stack < int > s;
	s.push(PRE[0]);
	int i = 0, j = 0, k = 0;
	vector < int > cnt(N+1, 0);

	function<void(int)> dfs = [&dfs, PRE, POST, &SIMM, &i, &j, &k](int x) -> void
	{
		if (x == POST[j])
		{
			SIMM[k++] = x; j++;
		}
		else
		{
			dfs(PRE[++i]);
			SIMM[k++] = x;
			dfs(PRE[++i]);
			j++;
		}
	};
	dfs(PRE[0]);
}

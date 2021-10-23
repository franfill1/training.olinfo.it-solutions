#include<bits/stdc++.h>
using namespace std;

void scavi(int R, int C, int Q, vector<int> &x1, vector<int> &y1, vector<int> &x2, vector<int> &y2, vector<int> &P, vector<vector<int>> &ter)
{
	vector < vector < int > > pre(R+1, vector < int > (C+1, 0));
	for (int q = 0; q < Q; q++)
	{
		y2[q]++; x2[q]++;
		pre[x1[q]][y1[q]] += P[q];	
		pre[x1[q]][y2[q]] -= P[q];
		pre[x2[q]][y1[q]] -= P[q];
		pre[x2[q]][y2[q]] += P[q];
	}

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			ter[i][j] = pre[i][j];
			if (i != 0) ter[i][j] += ter[i-1][j];
			if (j != 0) ter[i][j] += ter[i][j-1];
			if (i != 0 && j != 0) ter[i][j] -= ter[i-1][j-1];
		}
	}
}

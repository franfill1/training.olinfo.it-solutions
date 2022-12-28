#include <bits/stdc++.h>

using namespace std;

typedef pair < int , int > ii;

int inf = 1<<30;

void Colora(int N, int Q, vector <int> &A, vector <int> &B, vector <int> &C, vector <int> &murale)
{
    murale = vector < int > (N, -1);
	vector < int > end(N, -1);
	for (int i = Q-1; i >= 0; i--)
	{
		for (int j = A[i]; j <= B[i]; j++)
		{
			int t = end[j];
            end[j] = max(end[j], B[i]);
            if (t != -1)
			{
				j = t;
			}
			else if (murale[j] == -1)
			{
				murale[j] = C[i];
			}
		}
		end[A[i]] = max(end[A[i]], B[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (murale[i] == -1) murale[i] = 0;
		if (end[i] != -1) i = end[i];
	}
}
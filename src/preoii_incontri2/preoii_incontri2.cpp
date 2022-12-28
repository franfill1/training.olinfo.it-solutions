#include <bits/stdc++.h>

bool visita(int N, int A[]) 
{
	int B[N];
	B[0] = 0;
	for (int i = 1; i < N; i++)
	{
		B[i] = B[i-1] + A[i-1];
	}
	int t = 0;
	for (int i = N-1; i >= 0; i--)
	{
		if (t == B[i])
		{
			return 1;
		}
		else
		{
			t+=A[i];
		}
	}
	return 0;
}
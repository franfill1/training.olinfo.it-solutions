#include <vector>
#include <bits/stdc++.h>

using namespace std;

int direziona(int N, vector<int> A, vector<int> B) 
{
	int ma = 0;
	{
		int j = 0;
		for (int i = 0; i < N; i++)
		{
			while (j < N && A[i] >= B[j]) 
			    j++;
			if (j < N) 
			    ma++, j++;
		}
	}
	int mi = N;
	{
		int j = N-1;
		for (int i = N-1; i >= 0; i--)
		{
			while(j >= 0 && A[i] < B[j]) 
			    j--;
			if (j >= 0) 
			    mi--, j--;
		}
	}
	return ma - mi + 1;
}

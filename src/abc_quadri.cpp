#include<algorithm>
#include<iostream>
int quadri(int N, long long M, int V[]) {
	long long cur = 0;
	int B = N;
	int r = 0;
	for (int l = 0; l < N && r < N; l++)
	{
		while(cur <= M && r < N)
		{
			cur += V[r++];
		}
		if (cur > M) cur -= V[--r];
		B = std::min(B, r-l);
		cur -= V[l];
	}
    return B;
}

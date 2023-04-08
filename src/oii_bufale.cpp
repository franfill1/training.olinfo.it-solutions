#include<algorithm>
long long solve(int n, int* M, int* P) {
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		M[i] -= P[i];
		ans += (long long) P[i];
	}
	
	std::nth_element(M, M + n/2, M+n);
	int cnt = 0;
	for (int i = 0; i < n; i++) if (M[i] >= M[n/2]) 
	{
	    ans += (long long)M[i];
	    cnt++;
	}
	ans -= M[n/2]*(cnt - n/2);
	return ans;
}
#include <bits/stdc++.h>
#define M 1000000007
using namespace std;
typedef long long ll;

int trova(int N)
{
	if (N <= 2) return N;
	ll cur = 1;
	ll ans = 2;
	for (int i = 0; i < N; i++)
	{
		ans += cur;
		ans %= M;
		cur *= (i+1);
		cur %= M;
	}
	return ans;
}

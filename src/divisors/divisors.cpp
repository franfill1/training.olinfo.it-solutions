#include <bits/stdc++.h>

#define ma 1000000

using namespace std;

typedef long long ll;

long long compute(long long n) {
	long long i = 1;
	long long ans = 0;
	while(i <= n)
	{
		ll r = n / i;
		ll s = (n % i) / r + 1;
		ans += r * s;
		i += s;
	}
	return ans;
}
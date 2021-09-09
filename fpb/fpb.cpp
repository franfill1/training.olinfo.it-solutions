#include<bits/stdc++.h>
#define M 1000000007
#define MAXN 50001
#define MAXK 21
#pragma GCC Optimize("O3")
using namespace std;
typedef long long ll;

ll D[MAXK+1][MAXN+1];
ll B[MAXK+1][MAXN+1];
ll S[MAXK+1][MAXN+2];
ll V[MAXN];
ll L[MAXN];

int main()
{
	ll N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> V[i];

	for (int n = 0; n <= N; n++) D[0][n] = 1; 
	for (int n = 0; n <= N+1; n++) S[0][n] = n;
	B[0][0] = 1;

	for (int k = 1; k <= K; k++)
	{
		for (int n = 0; n <= N; n++)
		{
			D[k][n] = S[k-1][n];
			if (n) D[k][n] += D[k][n-1];
			S[k][n+1] = S[k][n] + D[k][n];
			D[k][n] %= M;
			S[k][n+1] %= M;
		}
	}

	for (int n = 0; n < N; n++) L[n] = n+1;

	ll ans = 0;
	for (ll i = N-1; i+1; i--)
	{
		ll v = V[i];
		ll p = i;
		while(p < N)
		{
			v = __gcd(v, V[p]);

			while(L[p] < N && V[L[p]] % v == 0) L[p] = L[L[p]];

			for (ll k = 0; k < K; k++, ans %= M) 
				ans += ((v*D[k][i])%M*((S[K-k-1][N-p] - S[K-k-1][N-L[p]]) + M)%M)%M;
			p = L[p];
		}
	}

	cout << ans << "\n";
}

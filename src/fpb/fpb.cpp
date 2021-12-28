#include<bits/stdc++.h>
#define M 1000000007
#define MAXN 50001
#define MAXK 21
using namespace std;
typedef long long ll;

ll D[MAXK+1][MAXN+1];
ll S[MAXK+1][MAXN+1];
ll V[MAXN];
ll L[MAXN];
ll G[MAXN+1];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ll N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> V[i];

	for (int n = 0; n <= N; n++) D[0][n] = 1, S[0][n] = n; 

	for (int k = 1; k <= K; k++) for (int n = k; n <= N; n++)
	{
		D[k][n] = S[k-1][n];
		if (n) D[k][n] += D[k][n-1];
		S[k][n] = D[k][n-1];
		if (n) S[k][n] += S[k][n-1];
		D[k][n] %= M;
		S[k][n] %= M;
	}

	ll ans = 0;
	G[N] = 1;
	for (ll i = N-1; i+1; i--)
	{
		L[i] = i+1;
		G[i] = V[i];
		for (ll j = i; j < N; j = L[j])
		{
			while(L[j] < N && V[L[j]] % G[j] == 0) L[j] = L[L[j]];
			if (L[j] == N || G[j] % V[L[j]] == 0) break;

			G[L[j]] = __gcd(G[j], V[L[j]]);
		}
		
		for (ll j = i; j < N; j = L[j])	
		{
			for (ll k = 0; k < K; k++, ans %= M) 
				ans += ((G[j]*D[k][i])%M*((S[K-k-1][N-j] - S[K-k-1][N-L[j]]) + M)%M)%M;
		}
	}

	cout << ans << "\n";
}

#pragma gcc optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1000000007;

inline void merge(vector < ll > &a, vector < ll > &b, vector < ll > &res)
{
	for (int s = 0; s < a.size(); s++)
	{
		res[s] = 0;
		for (int x = 0; x < a.size(); x++)
		{
			int y = s - x;
			if (y < 0)
				y += a.size();
			res[s] = (res[s] + a[x] * b[y]) % MOD;
		}
	}
}

int main()
{
	ll N;
	int M, L, R, K;
	cin >> N >> M >> L >> R >> K;
	R++;
	vector < ll > cur(M), res(M), slave(M);
	for (ll i = 0; i < M; i++)
	{
		if (L/M == R/M)
			cur[i] = (i >= (L % M)) && (i < (R % M));
		else
		{
			ll Ll = L % M ? (L + M - (L % M)) : L, Rr = (R % M) ? (R - (R % M)) : R;
			cur[i] = (Rr-Ll)/M;
			if (L != Ll && i >= L%M)
				cur[i]++;
			if (R != Rr && i < R%M)
				cur[i]++;
		}
		cur[i] %= MOD;
	}

	bool init = false;
	for (ll p = 1; p <= N; p<<=1)
	{
		if (p != 1)
		{
			merge(cur, cur, slave);
			swap(cur, slave);
		}
		if (N & p)
		{
			if (init)
			{
				merge(res, cur, slave);
				swap(res, slave);
			}
			else
			{
				for (int i = 0; i < M; i++)
					res[i] = cur[i];
				init = true;
			}
		}
	}
	cout << res[K] << "\n";
}

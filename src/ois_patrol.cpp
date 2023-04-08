#pragma gcc optimize("O3")
#include<bits/stdc++.h>
using namespace std;

constexpr short int maxn = 10000;
constexpr short int maxmod = 420;
vector < short int > g[maxn];
bool occ[maxn][7][7];
unsigned int D[maxn][maxmod];

inline __attribute__((always_inline)) unsigned int fast_read_int()
{
    int c, n = 0;
    do
    {
        c = getchar_unlocked();
    } while (c < '0' || c > '9');
    do
    {
        n = (n << 3) + (n << 1) + (c - '0');
        c = getchar_unlocked();
    } while (c >= '0' && c <= '9');
    return n;
}


inline __attribute__((always_inline)) void fast_write_uint(unsigned int n)
    {
        unsigned int N = n, rev, count = 0;
        rev = N;
        if (N == 0) { putchar_unlocked('0'); return ;}
        while ((rev % 10) == 0) { count++; rev /= 10;} //obtain the count of the number of 0s
        rev = 0;
        while (N != 0) { rev = (rev<<3) + (rev<<1) + N % 10; N /= 10;}  //store reverse of N in rev
        while (rev != 0) { putchar_unlocked(rev % 10 + '0'); rev /= 10;}
        while (count--) putchar_unlocked('0');
    }


int main()
{
	int N = fast_read_int(), M = fast_read_int(), K = fast_read_int();
	for (int i = 0; i < M; i++)
	{
		int a = fast_read_int(), b = fast_read_int();
		g[a].emplace_back(b);
		g[b].emplace_back(a);
	}
	for (int i = 0; i < N; i++)
		g[i].emplace_back(i);

	int mod = 1;
	for (int i = 0; i < K; i++)
	{
		int L = fast_read_int();
		assert(L <= 7);
		mod = mod*L / __gcd(mod, L);
		for (int j = 0; j < L; j++)
		{
			int x = fast_read_int();
			occ[x][L-1][j] = true;
		}
	}

	queue < pair < int , int > > q;
	q.emplace(0, 0);
	D[0][0] = 1;
	while(!q.empty())
	{
		auto [x, t] = q.front();
		q.pop();
		if (x == N-1)
		{
			fast_write_uint(D[x][t]-1);
			return 0;
		}
		int nt = (t+1)%mod;
		for (int y : g[x])
			if (!D[y][nt])
			{
				bool ok = true;
				for (int l = 1; l <= 7; l++)
					if (occ[y][l-1][nt % l])
						ok = false;
				if (ok)
				{
					D[y][nt] = D[x][t] + 1;
					q.emplace(y, nt);
				}
			}
	}
	putchar_unlocked('-');
	putchar_unlocked('1');
}

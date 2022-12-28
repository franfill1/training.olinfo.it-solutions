#include<bits/stdc++.h>
using namespace std;

short N, M;
bool must_place[11][10];
short memo[10][10][1<<6][1<<6][3];
short comb[1<<6][1<<6];

inline __attribute__((always_inline)) void setbit(short &m, short i, bool val)
{
	if (((m & (1<<i)) != 0) != val)
		m ^= 1<<i;
}

short dp(short x, short y, short mask1, short mask2, short state)
{
	if (x >= N)
	{
		//setbit(mask1, x-2, state & 1); //(N-2)
		//setbit(mask1, x-1, state & 2); //(N-1)
        mask1 = (x >= 2 ? ((mask1 & ~(3<<(x-2))) | (state<<(x-2))) : (x == 1 ? ((mask1 & ~1) | (state>>1)) : mask1)), x = 0, y++, state = 0;
		swap(mask1, mask2);
	}
	if (x == N+1000)
	{
		setbit(mask1, x-2, state & 1); //(N-1)
		x = 0, y++, state = 0;
		swap(mask1, mask2);
	}
	if (y == M)
		return 1;
	if (memo[x][y][mask1][mask2][state])
		return memo[x][y][mask1][mask2][state];
	short ans = 0, nmask1;
	if (comb[mask1][mask2] == 0)
	    comb[mask1][mask2] = (~(((mask1>>2) & (mask2>>1)) | ((mask1<<2) & (mask2<<1)) | (mask1 & mask2))) + 1;
	if ((1<<x) & (comb[mask1][mask2]-1))
	{
		if (state & 2) //salto a x+2
		{
			if (!must_place[x+1][y])
				ans = max((short)(dp(x+2, y, (x >= 2 ? ((mask1 & ~(3<<(x-2))) | (state<<(x-2))) : (x == 1 ? ((mask1 & ~1) | (state>>1)) : mask1)), mask2, 1)+(short)1), ans);
		}
		else //salto a x+1
			ans = max((short)(dp(x+1, y, x >= 2 ? ((mask1 & ~(1<<(x-2))) | ((state&1)<<(x-2))) : mask1, mask2, 2)+(short)1), ans);
	}

	if (!must_place[x][y]) //salto a x+1
		ans = max(dp(x+1, y, x >= 2 ? ((mask1 & ~(1<<(x-2))) | ((state&1)<<(x-2))) : mask1, mask2, state>>1), ans);
	return memo[x][y][mask1][mask2][state] = ans;
}

int main()
{

	N = getchar_unlocked() - '0';
	char ch = getchar_unlocked();
	if (ch != ' ')
	{
		N = N*10 + (ch - '0');
		getchar_unlocked();
	}
	M = getchar_unlocked() - '0';
	ch = getchar_unlocked();
	if (ch != '\n')
	{
		M = M*10 + (ch - '0');
		getchar_unlocked();
	}

	short cnt = 1, v;
	for (short i = 0; i < N; i++)
		for (short j = 0; j < M; j++)
		{
			v = getchar_unlocked() - '0';
			getchar_unlocked();
			cnt += v;
			if (N > M)
				must_place[j][i] = v;
			else
				must_place[i][j] = v;
		}
	if (N > M)
		swap(N, M);
	cout << dp(0, 0, 0, 0, 0) - cnt << "\n";
}

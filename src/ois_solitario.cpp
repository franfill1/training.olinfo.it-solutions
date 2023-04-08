#include<bits/stdc++.h>
using namespace std;

int N, M;
vector < vector < vector < vector < vector < int > > > > > memo;

vector < vector < bool > > must_place;

void setbit(int &m, int i, bool val)
{
	assert(i < N);
	if (i < 0)
		return;
	if (val)
		m |= 1<<i;
	else
		m &= ~(1<<i);
}

bool check(int mask1, int mask2, int i)
{
	if (i >= 2)
		if ((mask1 & (1<<(i-2))) && (mask2 & (1<<(i-1))))
			return false;
	if (i < N-2)
		if ((mask1 & (1<<(i+2))) && (mask2 & (1<<(i+1))))
			return false;
	if (((mask1 & (1<<i)) != 0) && ((mask2 & (1<<i)) != 0))
		return false;
	return true;
}

int dp(int x, int y, int mask1, int mask2, int state)
{
	assert(state >= 0 && state < 3);
	if (y == M)
		return 0;
	if (x == N)
	{
		setbit(mask1, x-2, state & 1); //(N-2)
		setbit(mask1, x-1, state & 2); //(N-1)
		return dp(0, y+1, mask2, mask1, 0);	
	}
	if (x == N+1)
	{
		setbit(mask1, x-2, state & 1); //(N-1)
		return dp(0, y+1, mask2, mask1, 0);	
	}
	assert(x < N);
	assert(x-1 < N);
	assert(x-2 < N);
	if (memo[x][y][mask1][mask2][state] != -1)
		return memo[x][y][mask1][mask2][state];
	int ans = 0;
	if (check(mask1, mask2, x))
	{
		if (state & 2) //salto a x+2
		{
			int nstate = 1;
			int nmask1 = mask1;
			setbit(nmask1, x-2, state & 1); //(N-2)
			setbit(nmask1, x-1, state & 2); //(N-1)
			ans = max(dp(x+2, y, nmask1, mask2, nstate)+1, ans);
		}
		else //salto a x+1
		{
			assert(state/2 == 0);
			int nstate = 2; // + state / 2
			int nmask1 = mask1;
			setbit(nmask1, x-2, state & 1); //(N-2)
			ans = max(dp(x+1, y, nmask1, mask2, nstate)+1, ans);
		}
	}

	if (!must_place[x][y]) //salto a x+1
	{	
		int nstate = state/2;	
		int nmask1 = mask1;
		setbit(nmask1, x-2, state & 1); //(N-2)
		ans = max(dp(x+1, y, nmask1, mask2, nstate), ans);
	}
	return memo[x][y][mask1][mask2][state] = ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> N >> M;
	bool swapped = false;
	must_place.resize(min(N, M), vector < bool > (max(N, M), false));
	/*for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
		{
			int v;
			cin >> v;
			if (N > M)
				must_place[j][i] = v;
			else
				must_place[i][j] = v;
		}*/
	if (N > M)
		swap(N, M);
	int masksize = 1<<N;
	memo.resize(N, vector < vector < vector < vector < int > > > > (M, vector < vector < vector < int > > > 
				(masksize, vector < vector < int > > (masksize, vector < int > (3, -1)))));
	cout << dp(0, 0, 0, 0, 0);
}

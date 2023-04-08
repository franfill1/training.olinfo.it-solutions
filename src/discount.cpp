#include<bits/stdc++.h>
using namespace std;
using ld = double;

const int MAXN = 100000;
const int P = 17;
const int ITER = 27;

int n;
int num[MAXN], den[MAXN], nxt[P][MAXN], len[MAXN], state[MAXN];
bool cyc[MAXN];
ld bes[P][MAXN], sum[P][MAXN];

pair < ld , ld > get(int x, int k)
{
	ld b=0, s=0;
	for (int p = 0; p < P; p++)
		if (k & (1<<p))
		{
			b = min(b, s + bes[p][x]);
			s += sum[p][x];
			x = nxt[p][x];
		}
	return {b, s};
}

bool check(ld val)
{
	for (int i = 0; i < n; i++)
		bes[0][i] = 0,  sum[0][i] = - val * den[i] + num[i];
	for (int p = 1; p < P; p++)
		for (int x = 0; x < n; x++)
		{
			int y = nxt[p-1][x];
			sum[p][x] = sum[p-1][x] + sum[p-1][y];
			bes[p][x] = min(bes[p-1][x], sum[p-1][x] + bes[p-1][y]);
		}
	for (int x = 0; x < n; x++)
	{
		int y = nxt[0][x];
		ld v = (1-val) * den[x] + get(y, len[x]-1).first;
		if (cyc[x])
			v = min(v, get(x, len[x]).second);
		if (v < 0)
			return true;
	}
	return false;
}

bool dfs(int x, int d=1)
{
	state[x] = d;
	int y = nxt[0][x];
	bool iscyc = false;
	if (state[y] == 0)
	{
		iscyc = dfs(y, d+1);
		if (iscyc)
			len[x] = len[y];
		else
			len[x] = len[y]+1;
	}
	else if (state[y] > 0)
	{
		iscyc = true, len[x] = state[x] + 1 - state[y];
		state[y] = -2;
	}
	else
		len[x] = len[y]+1;
	cyc[x] = iscyc;
	if (state[x] == -2)
		iscyc = false;
	state[x] = -1;
	return iscyc;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> den[i] >> num[i] >> nxt[0][i];
		
	for (int p = 1; p < P; p++)
		for (int i = 0; i < n; i++)
			nxt[p][i] = nxt[p-1][nxt[p-1][i]];
	
	for (int i = 0; i < n; i++)
		if (state[i] == 0)
			dfs(i);
	
	ld l = 0, r = 1;
	for (int i = 0; i < ITER; i++)
	{
		ld m = (l+r)/2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	cout.setf(ios::fixed);
	cout.precision(7);
	cout << (1-r)*100 << "\n";
}

#include<bits/stdc++.h>
using namespace std;

const int MAXC = 10010;

int N;
int cur[MAXC];
int beg;
int sum = 0;

bool calc(int i, int mi=0)
{
	int res = MAXC - i;
	if (sum + res * 9 - res / 3 < N)
		return false;
	if (sum + res / 3 > N)
		return false;
	if (i == MAXC)
	{
		if (sum == N)
			return true;
		return false;
	}
	for (int c = mi; c < 10; c++)
	{
		if (cur[i-1] == c && cur[i-2] == c)
			continue;
		cur[i] = c;
		sum += c;
		if (calc(i+1))
			return true;
		sum -= c;
	}
	return false;
}
void print()
{
	int i;
	for (i = 0; i < MAXC && cur[i] == 0; i++);
	for (; i < MAXC; i++)
		cout << cur[i];
	cout << "\n";
	return;
}

void solve()
{
	cin >> N;
	string s;
	cin >> s;
	fill(cur, cur + MAXC, 0);
	beg = MAXC - s.size();
	for (int i = 0; i < s.size(); i++)
		cur[beg + i] = s[i] - '0';
	sum = 0;
	if (beg < MAXC)
		sum += cur[beg];
	if (beg + 1 < MAXC)
		sum += cur[beg+1];
	int i;
	for (i = min(beg+2, MAXC); i < MAXC && (cur[i-1] != cur[i] || cur[i-2] != cur[i]); i++)
		sum += cur[i];
	
	if (i == MAXC && calc(i))
	{
		print();
		return;
	}
	if (i == MAXC)
	{
		sum -= cur[i-1];
		i--;
	}
	for (;i >= 0; i--)
	{
		if (calc(i, cur[i] + 1))
		{
			print();
			return;
		}		
		sum -= cur[i-1];

	}
	cout << -1 << "\n";
	return;
}

main()
{
	int t;
	cin >> t;
	while(t--)
		solve();
}


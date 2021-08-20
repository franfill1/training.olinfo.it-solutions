#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

typedef long long int ull;
typedef vector < vector < vector < vector < ull > > > > myMat;

ull sol[120][120][120][120];

ull sol2[120][120];

ull pre[120][120];

const ull M = 1000000007;

ull X;

ull sum(ull left, ull right, ull top, ull bottom)
{
	ull ans = pre[bottom][right];
	if (left > 0)
	{
		ans -= pre[bottom][left-1];
	}
	if (top > 0)
	{
		ans -= pre[top - 1][right];
	}
	if (left > 0 && top > 0)
	{
		ans += pre[top - 1][left - 1];
	}
	return ans;
}


ull dp2(ull height, ull width)
{
	if (sol2[height][width] != 0)
	{
		return sol2[height][width] % M;
	}
	
	ull ans = 1;
    if (height == 1) ans+=2;
    else ans += (2 * dp2(height - 1, width)) % M;
	if (width == 1) ans += 2;
	else ans += (2 * dp2(height, width - 1)) % M;
	ans = ans % M;
	sol2[height][width] = ans;
	return ans;
}


ull dp(ull left, ull right, ull top, ull bottom)
{
	if (sol[left][right][top][bottom] != 0)
	{
		return sol[left][right][top][bottom];
	}
	ull ans = 1;
	
	if (left == right && top == bottom && sum(left, right, top, bottom) >= X)
	{
		ans += 4;
		ans %= M;
	}
	else
	{
		if (left != right)
		{
			if (sum(left, left, top, bottom) >= X)
			{
				ans += dp(left + 1, right, top, bottom);
				ans %= M;
			}
			
			if (sum(right, right, top, bottom) >= X)
			{
				ans += dp(left, right - 1, top, bottom);
				ans %= M;
			}
		}
		else if (sum(left, right, top, bottom) >= X)
		{
			ans += 2;
			ans %= M;
		}
		if (top != bottom)
		{
			if (sum(left, right, top, top) >= X)
			{
				ans += dp(left, right, top + 1, bottom);
				ans %= M;
			}
			
			if (sum(left, right, bottom, bottom) >= X)
			{
				ans += dp(left, right, top, bottom - 1);
				ans %= M;
			}
		}
		else if (sum(left, right, top, bottom) >= X)
		{
			ans += 2;
			ans %= M;
		}
	}
	sol[left][right][top][bottom] = ans;
	return ans;
}


int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	ull N;
	fin >> N >> X;
				
	bool check = true;
	
	for (ull i = 0; i < N; i++)
	{
		for (ull j = 0; j < N; j++)
		{
			ull el;
			fin >> el;
			check = check && (el > 0);
			if (i == 0 && j == 0)
			{
				pre[i][j] = el;
			}
			else if (i == 0)
			{
				pre[i][j] = pre[i][j - 1] + el;
			}
			else if (j == 0)
			{
				pre[i][j] = pre[i - 1][j] + el;
			}
			else
			{
				pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + el;
			}
		}
	}
	
	if (check && X == 0)
	{
	    for (int i = 0; i < N; i++)
	    {
	        for (int j = 0; j < N; j++) sol2[i][j] = 0;
	    }
	    
		fout << dp2(N, N);
	}
	else
	{
		fout << dp(0, N - 1, 0, N - 1);
	}
	
	return 0;
}


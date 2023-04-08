#include<bits/stdc++.h>
#pragma GCC Optimize("Ofast")
#define SIZ 3862162
#define n 131072 
#define n2 262144
using namespace std;

int v[SIZ], l[SIZ], r[SIZ], O[SIZ];
int day[n] = {1};
int d = 0;
int cnt = n2;

void add(int i, int c, int o)
{
	int x=0, y=n;
	int m;
	while(x != i || y != i+1)
	{
		O[cnt] = o;
		v[cnt] = v[o]+c;
		m = (x+y)>>1;	
		if (i < m)
		{
			y = m;
			r[cnt] = r[o];
			o = l[o];
			l[cnt] = cnt+1;
		}
		else
		{
			x = m;
			l[cnt] = l[o];
			o = r[o];
			r[cnt] = cnt+1;
		}
		cnt++;
	}
	v[cnt++] = v[o]+c;
}

int get(int a, int b, int k, int x=0, int y=n)
{
	if (b <= x || y <= a) return 0;
	if (a <= x && y <= b) return v[k];
	int m = (x+y)>>1;
	return get(a, b, l[k], x, m) + get(a, b, r[k], m, y);
}


void init(int _n)
{
	for (int i = 1; i < n2; i++) v[i] = 0;
	for (int i = 1; i < n; i++)
	{
		l[i] = i<<1;
		r[i] = (i<<1)+1;
	}
	add(0, 0, 1);
}

void log(vector < int >& A, vector<int>&R)
{
	for (int& a : A)
	{
		add(a, 1, cnt-18);
	}
	for (int &r : R)
	{
		add(r, -1, cnt-18);
	}
	day[++d] = cnt-18;
}

int answer(int d, int y)
{
	return get(y, n, day[d]);
}


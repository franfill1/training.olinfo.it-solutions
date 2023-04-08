#include<bits/stdc++.h>
#pragma gcc Optimize("O3")
using namespace std;

const int upper = 8962;
const int maxd = 20;
int D[upper];
tuple < int , string , int > S[upper];

int pluss (int x, int y)
{
	return x + y;
}
int minuss (int x, int y)
{
	return x - y;
}
int dott(int x, int y)
{
	return x * y;
}
int slashh(int x, int y)
{
	return x / y;
}
int modd(int x, int y)
{
	return x % y;
}
int lshiftt(int x, int y)
{
	return x << y;
}
int rshiftt(int x, int y)
{
	return x >> y;
}
int bandd(int x , int y)
{
	return x & y;
}
int bxorr(int x, int y)
{
	return x ^ y;
}
int borr(int x, int y)
{
	return x | y; 
}

void calc(int k)
{
	putchar_unlocked('(');
	if (k == 1) 
	{
		putchar_unlocked('1');
	}
	else
	{
		auto &[x, s, y] = S[k];
		calc(x);
		for (char &c : s) putchar_unlocked(c);
		calc(y);
	}
	putchar_unlocked(')');
}

int main()
{
	int M;
	cin >> M;

	vector < int > us;

	// + - * / % << >> & ^ |
	const vector < pair < string , function < int(int , int) > > > op
	{
		{"+", pluss},
		{"-", minuss},
		{"*", dott},
		{"/", slashh},
		{"%", modd},
		{"<<", lshiftt},
		{">>", rshiftt},
		{"&", bandd},
		{"^", bxorr},
		{"|", borr},
	};

	vector < vector < int > > pq(maxd); //LOL not a priority queue

	pq[0].emplace_back(1);
	for (int d = 0; d < maxd; d++)
	{
		for (int &x : pq[d]) us.emplace_back(x);
		for (int &x : pq[d])
		{
			int d = D[x];
			if (x == M)
			{
				calc(x);
				putchar_unlocked('\n');
				return 0;
			}

			for (int &y : us)
			{
				int nd = D[x] + D[y] + 1;
				if (nd >= maxd) continue;
				for (auto &[s, f] : op)
				{
					int n = f(x, y);
					if (n > 1 && n < upper && (D[n] == 0 || D[n] > nd))
					{
						D[n] = nd;
						S[n] = {x, s, y};
						pq[nd].emplace_back(n);
					}
				}
			}
		}
	}
}


#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct sushi
{
	int A, B, C;	
};

bool operator < (sushi x, sushi y)
{
	return x.A < y.A;
}

int N;
vector < int > memo;
vector < sushi > V;

int mangia(int i)
{
	if (i == N)
	{
		return 0;
	}
	else if (memo[i] != -1)
	{
		return memo[i];
	}
	else
	{
		memo[i] = mangia(i+1);
		int x = V[i].A + V[i].C;
		int a = 0, b = N;
		while(a != b - 1)
		{
			int m = (a+b)/2;
			if (V[m].A >= x)
			{
				b = m;
			}
			else
			{
				a = m;
			}
		}
		memo[i] = max(memo[i], V[i].B + mangia(b));
		return memo[i];
	}
}


int main()
{
	fin >> N;
	for (int i = 0; i < N; i++)
	{
		int A, B, C;
		fin >> A >> B >> C;
		V.push_back({A, B, C});
	}
	
	sort(V.begin(), V.end());
	memo.resize(N, -1);
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, mangia(i));
	}
	fout << ans;
}

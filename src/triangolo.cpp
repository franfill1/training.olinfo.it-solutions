#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector < vector < int > > triangolo;
vector < vector < int > > memo;

int SommaMas(int r, int c)
{
	if (memo[r][c] != -1)
	{
		return memo[r][c];
	}
	else if (r == triangolo.size() - 1)
	{
		return triangolo[r][c];
	}
	else //maggiore fra sommmaMas(r + 1, c) e sommaMas(r + 1, c + 1)
	{
		int ans = SommaMas(r + 1, c);
		if (ans < SommaMas(r + 1, c + 1))
		{
			ans = SommaMas(r + 1, c + 1);
		}
		ans += triangolo[r][c];
		memo[r][c] = ans;
		return ans;
	}
}


int main()
{
	int N;
	fin >> N;
	triangolo.resize(N);
	memo.resize(N);
	for (int i = 0; i < N; i++)
	{
		triangolo[i].resize(i+1);
		memo[i].resize(i+1, -1);
		for (int j = 0; j < i + 1; j++)
		{
			fin >> triangolo[i][j];
		}
	}
	
	fout << SommaMas(0, 0);
}

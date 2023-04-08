#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector < int > medaglie;
vector < int > memo;

int gioca(int n, int total)
{
	if (memo[n - 1] != -1)
	{
		return memo[n - 1];
	}
	if (n <= 3)
	{
		return total;
	}
	else
	{
		int ans = 0;
		int sum = 0;
		
		for (int t = 1; t <= 3; t++)
		{
			sum += medaglie[n - t];
			ans = max(ans, total - gioca(n - t, total - sum));
		}
		memo[n - 1] = ans;
		return ans;
	}
}


int main()
{
	int N;
	fin >> N;
	
	vector < int > val {100, 300, 500};
	
	int total = 0;
	medaglie.resize(N);
	memo.resize(N, -1);
	for (int i = 0; i < N; i++)
	{
		int el;
		fin >> el;
		
		medaglie[i] = val[el];
		total += medaglie[i];
	}
	fout << gioca(N, total);
}

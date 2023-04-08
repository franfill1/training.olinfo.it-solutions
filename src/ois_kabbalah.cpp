#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main()
{
	int N, M;
	fin >> N >> M;
	vector < pair < char , int > > ver(M);
	vector < pair < char , int > > diag1(M);
	vector < pair < char , int > > diag2(M);
	
	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		string row;
		fin >> row;
		
		char l = ' ';
		int combo = 0;
		for (int i = 0; i < M; i++)
		{
			if (row[i] != l)
			{
				l = row[i];
				combo = 0;
			}
			combo++;
			ans = max(ans, combo);
		}
		
		for (int i = 0; i < M; i++)
		{
			if (ver[i].first != row[i])
			{
				ver[i].first = row[i];
				ver[i].second = 0;
			}
			ver[i].second++;
			ans = max(ans, ver[i].second);
		}
		
		for (int i = M-1; i > 0; i--)
		{
			diag1[i] = diag1[i-1];
			if (diag1[i].first != row[i])
			{
				diag1[i].first = row[i];
				diag1[i].second = 0;
			}
			diag1[i].second++;
			ans = max(ans, diag1[i].second);
		}
		diag1[0] = make_pair(row[0], 1);
		
		for (int i = 0; i < M-1; i++)
		{
			diag2[i] = diag2[i+1];
			if (diag2[i].first != row[i])
			{
				diag2[i].first = row[i];
				diag2[i].second = 0;
			}
			diag2[i].second++;
			ans = max(ans, diag2[i].second);
		}
		diag2[M-1] = make_pair(row[M-1], 1);
	}
	fout << ans;
	
}

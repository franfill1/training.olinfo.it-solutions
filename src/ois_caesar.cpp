#include <bits/stdc++.h>

using namespace std;

ifstream fin;
ofstream fout;

int main ()
{
	fin.open("input.txt");
	fout.open("output.txt");
	
	
	const int M = 'z' - 'a' + 1;
	
	int N, D;
	fin >> N >> D;
	
	vector < string > vec(N);
	
	for (int i = 0; i < N; i++)
	{
		fin >> vec[i];
		int c = 'z' + 1 - vec[i][0] ;
		for (int j = 0; j < D; j++)
		{
			vec[i][j] = ((vec[i][j] + c - 'a') % (M) + M) % M  + 'a';
		}
	}
	
	sort(vec.begin(), vec.end());
	
	int ans = 0;
	int a = 1;
	
	for (int i = 1; i < N; i++)
	{
		if (vec[i] != vec[i - 1])
		{
			if (a > ans)
			{
				ans = a;
			}
			a = 0;
		}
		a++;
	}
	if (a > ans)
	{
		ans = a;
	}
	
	fout << ans;
	
	return 0;
}


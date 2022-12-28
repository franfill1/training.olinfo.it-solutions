#include <bits/stdc++.h>

using namespace std;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

int dist(bitset < 100 > a, bitset < 100 > b)
{
	return (a^b).count();
}

int main()
{
	int N, M;
	fin >> N >> M;
	
	vector < bitset < 100 > > s(N, 0);
	for (int i = 0; i < N; i++)
	{
		fin >> s[i];
	}
	vector < int > d (N, M);
	d[0] = 0;
	
	vector < bool > ad(N, false);
	ad[0] = true;
	
	int ans = M;
	
	int next = 0;
	for (int i = 0; i < N; i++)
	{
		ad[next] = true;
		ans += d[next];
		
		int add = next;
		next = -1;
		for (int i = 0; i < N; i++)
		{
			d[i] = min(d[i], dist(s[i], s[add]));
			if (!ad[i] && (next == -1 || d[i] < d[next]))
			{
				next = i;
			}
		}
	}
	fout << ans;
}

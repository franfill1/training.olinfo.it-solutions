#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector < vector < int > > g;
	vector < int > p;
	vector < string > S(N);
	vector < int > cnt;
	g.emplace_back(26, -1);
	p.emplace_back(0);
	cnt.emplace_back(0);
	for (auto &s : S)
	{
		cin >> s;
		int x = 0;
		for (auto cc : s)
		{
			int c = cc - 'a';	
			if (g[x][c] == -1)
			{
				cnt[x]++;
				g[x][c] = g.size();
				g.emplace_back(26, -1);
				p.emplace_back(x);
				cnt.emplace_back(0);
			}
			x = g[x][c];
		}
	}
	vector < int > A(N, cnt[0]);
	cnt[0] = 1;
	for (int i = N-2; i >= 0; i--)
	{
		A[i] = A[i+1];	
		int x = 0;
		for (auto cc : S[i+1])
		{
			int c = cc - 'a';
			A[i] += cnt[x]-1;
			cnt[x] = 1;
			x = g[x][c];
		}
		A[i] += cnt[x]-1;
	}
	for (auto a : A) cout << a << "\n";
}

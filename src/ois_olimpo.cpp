#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

typedef pair < int , int > ii;

int main()
{
	unordered_map < char , int > cton {{'P', 1}, {'N', 2}, {'B', 3}};
	int N;
	fin >> N;
	vector < vector < ii > > T(N);
	for (int i = 1; i < N; i++)
	{
		char Q; int A;
		fin >> Q >> A;
		T[A].push_back(make_pair(i, cton[Q]));
	}
	
	vector < int > D(N, -1);
	stack < int > s;
	s.push(0);
	D[0] = 0;
	
	int ans = 0;
	while(!s.empty())
	{
		int n = s.top();
		s.pop();
		ans = max(ans, D[n]);
		for (auto ne : T[n])
		{
			if (D[ne.first] == -1)
			{
				D[ne.first] = D[n] + ne.second;
				s.push(ne.first);
			}
		}
	}
	fout << ans;
}

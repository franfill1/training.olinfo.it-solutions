#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ifstream fin ("input.txt");
ofstream fout ("output.txt");

struct dsu
{
	vector < int > P, S;

	dsu(int n)
	{
		P.resize(n);
		S.resize(n, 1);
		for (int i = 0; i < n; i++) P[i] = i;
	}

	int find(int x)
	{
		return x == P[x] ? x : P[x] = find(P[x]);
	}

	bool merge(int a, int b)
	{
		if ((a = find(a)) != (b = find(b)))
		{
			if (S[a] > S[b]) swap(a, b);
			P[a] = b;
			S[b] += P[a];
			return true;
		}
		return false;
	}
};

int main()
{
	int N, M;
	cin >> N >> M;
	vector<tuple<int, int, int>> v;
	while(M--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		v.emplace_back(c, a, b);
	}

	sort(v.rbegin(), v.rend());
	dsu d(N);

	ll ans = 0;
	
	for (auto [c, a, b] : v)
	{
		if (d.merge(a, b) && --N == 1) 
		{
			cout << c; return 0;
		}
	}
}


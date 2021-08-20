#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll memo[4001];
int Z[8005];
vector < int > g[4000];

void Zalgo(string &a, string &b)
{
	string S = a + '$' + b;
	Z[0] = S.length();
	int l=0, r=0;	
	for (int i = 1; i < S.length(); i++)
	{
		if (i > r || Z[i-l] >= r-i)
		{
			l = i; r = max(r, i);
			while(S[r-l] == S[r]) r++;
			Z[i] = r - l;
		}
		else if (Z[i-l] <= r-i)
		{
			Z[i] = Z[i-l];
		}

		if (Z[i] == a.length())
		{
			int j = i - a.length() - 1;
			g[j].push_back(i-1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	memo[N] = 1;

	string S;
	cin >> S;

	while(M--)
	{
		string a;
		cin >> a;
		Zalgo(a,S);
	}

	for (int i = N-1; i+1; i--)
	{
		for (int j : g[i])
		{
			memo[i] += memo[j];
			memo[i] %= mod;
		}
	}
	cout << memo[0];
}

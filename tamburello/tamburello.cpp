#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Zalgo
{
	vector < int > Z;
	
	Zalgo(string s)
	{
		Z.resize(s.size());
		Z[0] = s.size();
		int l=0, r=0;
		for (int i = 1; i < s.size(); i++)
		{
			if (i + Z[i-l] >= r)
			{
				l = r = i;
				while(r < s.size() && s[r] == s[r-l]) r++;
			}
			Z[i] = min(Z[i-l], r-i);
		}
	}

	int operator [] (int i)
	{
		return Z[i];
	}

};

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int N;
	cin >> N;
	string s;
	char c;
	for (int i = 0; i < N; i++)
	{
		cin >> c;
		s += c;
	}
	Zalgo Z(s);
	for (int i = 1; i < N; i++)
	{
		if (Z[i] == N-i && N % i == 0)
		{
			for (int j = 0; j < i; j++)
			{
				cout << s[j] << " ";
			}
			cout << "\n";
			return 0;
		}
	}
	cout << 2 << "\n";
	return 0;
}

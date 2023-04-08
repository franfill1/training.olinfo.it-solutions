#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll be = 0;
ll N, M;

void calc(int i = 0, ll val=0, int l=0)
{
	be = max(be, val);
	if (i != N)
	{
		for (int c = 3; c <= 9; c+= 3) if (l != c)
		{
			ll nval = (val*10 + c)%M;
			calc(i+1, nval, c);
		}
	}
}

void solve()
{
	cin >> N >> M;
	be = 0;
	calc();
	cout << be << " ";
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int T;
	cin >> T;
	while(T--) solve();
	cout << "\n";
}


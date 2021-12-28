#include<bits/stdc++.h>
using namespace std;

vector < int > H;

bool check(int i)
{
	if (i < 0 || i >= H.size()) return false;
	if (i > 0 && H[i-1] >= H[i]) return false;
	if (i < H.size()-1 && H[i+1] >= H[i]) return false;
	return true;
}
int main ()
{
	int n, p;
	cin >> n >> p;
	H.resize(n);
	for (int &h : H) cin >> h;
	
	vector < int > v;
	for (int i = 0; i < n; i++)
	{
		if (check(i)) v.push_back(i);
	}

	int ans = 0;
	while(p--)
	{
		vector < int > b;
		for (int i : v)
		{
			if (check(i))
			{
				ans++;
				H[i] = 0;
				if (check(i-1)) b.push_back(i-1);
				if (check(i+1)) b.push_back(i+1);
			}
		}
		v = b;
	}
	cout << ans << "\n";
	return 0;
}


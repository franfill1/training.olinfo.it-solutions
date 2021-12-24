#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector < int > V(N);
	for (int &v : V) cin >> v;

	int s;
	for (int &v : V)
	{
		cin >> s;
		v *= s;
	}
	
	int ans = 0, t = 0, l = 0;
	for (int v : V)
	{
		if (v < l) t = 0;
		t += l = v;
		ans = max(ans, t);
	}
	cout << ans << "\n";
}

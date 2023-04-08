#include<bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int K;
		cin >> K;
		vector < bool > vis(10, false);
		int cnt = 0, ans = 0;
		while (cnt < 10)
		{
			ans++;
			int v = K*ans;
			while(v)
			{
				int x = v % 10;
				if (!vis[x])
					vis[x] = 1, cnt++;
				v /= 10;
			}
		}
		cout << ans << "\n";
	}
}

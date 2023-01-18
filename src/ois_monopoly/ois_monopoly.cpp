#include<bits/stdc++.h>
#include <limits>
using namespace std;
using ll = long long;

ll dp[1001][1000][3];
ll T[1000];

int main()
{
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> T[i];
	for (int i = 0; i < N; i++)
		for (int t = 0; t < 3; t++)
			dp[K][i][t] = 0;

	for (int k = K-1; k >= 0; k--)
		for (int t = 2; t >= 0; t--)
			for (int i = 0; i < N; i++)
			{
				dp[k][i][t] = numeric_limits<ll>::min();
				for (int d = 1; d <= 6; d++)
				{
					int j = (i + d*2) % N;
					if (t < 2)
						dp[k][i][t] = max(dp[k][i][t], dp[k][j][t+1] + T[j]);
					else
						dp[k][i][t] = max(dp[k][i][t], dp[k+1][j][0] + T[j]);
				}
				for (int r = 3; r < 12; r++)
				{
					int j = (i + r) % N;
					dp[k][i][t] = max(dp[k][i][t], dp[k+1][j][0] + T[j]);
				}
			}
	cout << dp[0][0][0] << "\n";
}

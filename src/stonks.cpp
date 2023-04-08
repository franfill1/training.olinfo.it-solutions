#include<bits/stdc++.h>
using namespace std;

int B[3001][3001], S[3001][3001];
double dp[3001][3001];

int main()
{
    ios_base::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) for (int j = 0; j < K; j++)
		cin >> B[i][j] >> S[i][j];
	double ans = 1;
	for (int i = 0; i < K; i++) 
		dp[N-1][i] = S[N-1][i];
	for (int i = N-2; i >= 0; i--)
	{
		for (int j = 0; j < K; j++) 
			ans = max(ans, dp[i+1][j]/B[i][j]);
		for (int j = 0; j < K; j++)
			dp[i][j] = max(dp[i+1][j], ans*S[i][j]);
	}
	for (int j = 0; j < K; j++) 
		ans = max(ans, dp[0][j]/B[0][j]);
	cout << setprecision(7) << ans << "\n";
}

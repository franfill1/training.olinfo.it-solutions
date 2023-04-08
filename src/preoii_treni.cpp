#include<algorithm>
int tempo_massimo(int N, int a[], int b[])
{
    int dp[N+1][2];
    dp[0][0] = 0;
    dp[0][1] = std::max(a[0], b[0]);
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = std::max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = std::max(dp[i][0] + a[i], dp[i-1][0] + b[i]);
    }
    return std::max(dp[N-1][0], dp[N-1][1]);
}
